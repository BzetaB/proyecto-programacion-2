#include <iostream>
#include <limits>

#include "paciente/modelo/Paciente.h"
#include "paciente/modelo/Responsable.h"
#include "paciente/servicio/PacienteServicio.h"
#include "paciente/servicio/ResponsableServicio.h"
#include "paciente/modelo/HistoriaClinica.h"
#include "administracion/modelos/Medico.h"
#include "administracion/servicio/MedicoServicio.h"
#include "atencion/modelo/Cita.h"
#include "atencion/modelo/Atencion.h"
#include "atencion/servicio/AgendaServicio.h"
#include "atencion/servicio/CitaServicio.h"
#include "atencion/servicio/HistoriaClinicaServicio.h"
#include "administracion/servicio/HorarioServicio.h"
#include "administracion/servicio/ConsultorioServicio.h"
#include "repositorio/template/Repositorio.h"
#include "administracion/modelos/Sede.h"
#include "administracion/modelos/Horario.h"
#include "administracion/modelos/MedicoSede.h"
#include "ejercicios/PruebasEscenarios.h"

void registrarPaciente(PacienteServicio& servicio, ResponsableServicio& responsableServicio,
                       HistoriaClinicaServicio& historiaServicio) {
    std::string identificador;
    std::string nombre;
    std::string apellido;
    std::string dni;
    int anioNacimiento;

    std::cout << "\n--- Registrar paciente ---\n";
    std::cout << "Identificador: ";
    std::cin >> identificador;
    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Apellido: ";
    std::cin >> apellido;
    std::cout << "DNI: ";
    std::cin >> dni;
    std::cout << "Anio de nacimiento: ";
    std::cin >> anioNacimiento;

    Paciente* paciente = new Paciente(
        identificador,
        nombre,
        apellido,
        dni,
        anioNacimiento, nullptr, nullptr
    );

    Responsable* responsable = nullptr;
    if (servicio.esMenorEdad(paciente)) {
        std::string identificadorResponsable;
        std::string nombreResponsable;
        std::string apellidoResponsable;
        std::string dniResponsable;
        int anioResponsable;
        std::string parentesco;

        std::cout << "\nEl paciente es menor de edad. Datos del responsable:\n";
        std::cout << "Identificador: ";
        std::cin >> identificadorResponsable;
        std::cout << "Nombre: ";
        std::cin >> nombreResponsable;
        std::cout << "Apellido: ";
        std::cin >> apellidoResponsable;
        std::cout << "DNI: ";
        std::cin >> dniResponsable;
        std::cout << "Anio de nacimiento: ";
        std::cin >> anioResponsable;
        std::cout << "Parentesco: ";
        std::cin >> parentesco;

        responsable = new Responsable(
            identificadorResponsable,
            nombreResponsable,
            apellidoResponsable,
            dniResponsable,
            anioResponsable,
            parentesco
        );

        if (!responsableServicio.validarResponsable(responsable, paciente)) {
            delete responsable;
            responsable = nullptr;
        } else {
            paciente->set_responsable(responsable);
        }
    }

    if (!servicio.registrarPaciente(paciente)) {
        delete paciente;
        delete responsable;
    } else {
        if (responsable != nullptr) {
            responsableServicio.registrarResponsable(responsable, paciente);
        }
        HistoriaClinica* historia = new HistoriaClinica(
            "HC-" + paciente->get_dni(),
            paciente
        );
        historiaServicio.registrarHistoria(historia);
    }
}

void mostrarPacientes(PacienteServicio& servicio) {
    std::vector<Paciente*> pacientes = servicio.listarPacientes();

    std::cout << "\n--- Pacientes registrados ---\n";
    if (pacientes.empty()) {
        std::cout << "No hay pacientes registrados.\n";
        return;
    }

    for (Paciente* paciente : pacientes) {
        std::cout << paciente->get_identificador_persona()
                  << " | " << paciente->get_nombre()
                  << " " << paciente->get_apellido()
                  << " | DNI: " << paciente->get_dni() << '\n';
    }
}

void menuPacientes(PacienteServicio& servicio, ResponsableServicio& responsableServicio,
                   HistoriaClinicaServicio& historiaServicio) {
    int opcion;

    do {
        std::cout << "\n==============================\n";
        std::cout << "      GESTION DE PACIENTES\n";
        std::cout << "==============================\n";
        std::cout << "1. Registrar paciente\n";
        std::cout << "2. Listar pacientes\n";
        std::cout << "0. Volver\n";
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (opcion) {
            case 1:
                registrarPaciente(servicio, responsableServicio, historiaServicio);
                break;
            case 2:
                mostrarPacientes(servicio);
                break;
            case 0:
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

void registrarMedico(MedicoServicio& servicio) {
    std::string identificador;
    std::string nombre;
    std::string apellido;
    std::string dni;
    std::string colegiatura;
    int anioNacimiento;
    int aniosExperiencia;
    bool activo;
    char activoInput;

    std::cout << "\n--- Registrar medico ---\n";
    std::cout << "Identificador: ";
    std::cin >> identificador;
    if (servicio.buscarMedicoPorIdentificador(identificador) != nullptr) {
        std::cout << "Ya existe un medico con ese identificador.\n";
        return;
    }
    std::cout << "Nombre: ";
    std::cin >> nombre;
    std::cout << "Apellido: ";
    std::cin >> apellido;
    std::cout << "DNI: ";
    std::cin >> dni;
    std::cout << "Anio de nacimiento: ";
    std::cin >> anioNacimiento;
    std::cout << "Anios de experiencia: ";
    std::cin >> aniosExperiencia;
    std::cout << "Colegiatura: ";
    std::cin >> colegiatura;
    std::cout << "Activo (S/N): ";
    std::cin >> activoInput;
    activo = (activoInput == 'S' || activoInput == 's');

    Medico* medico = new Medico(
        identificador, nombre, apellido, dni, anioNacimiento,
        aniosExperiencia, colegiatura, activo
    );
    bool registrado = servicio.registrarMedico(medico);
    if (registrado) {
        std::cout << "Medico registrado correctamente.\n";
    } else {
        delete medico;
    }
}

void mostrarMedicos(MedicoServicio& servicio) {
    std::vector<Medico*> medicos = servicio.listarMedicos();
    std::cout << "\n--- Medicos registrados ---\n";
    if (medicos.empty()) {
        std::cout << "No hay medicos registrados.\n";
        return;
    }
    for (Medico* medico : medicos) {
        std::cout << medico->get_identificador_persona()
                  << " | " << medico->get_nombre() << " " << medico->get_apellido()
                  << " | DNI: " << medico->get_dni()
                  << " | CMP: " << medico->get_colegiatura()
                  << " | Experiencia: " << medico->get_anios_experiencia() << " anios"
                  << " | " << (medico->get_activo() ? "Activo" : "Inactivo") << '\n';
    }
}

void buscarMedico(MedicoServicio& servicio) {
    std::string identificador;
    std::cout << "Identificador del medico: ";
    std::cin >> identificador;
    Medico* medico = servicio.buscarMedicoPorIdentificador(identificador);
    if (medico == nullptr) {
        std::cout << "Medico no encontrado.\n";
        return;
    }
    std::cout << medico->get_identificador_persona()
              << " | " << medico->get_nombre() << " " << medico->get_apellido()
              << " | DNI: " << medico->get_dni()
              << " | CMP: " << medico->get_colegiatura()
              << " | " << (medico->get_activo() ? "Activo" : "Inactivo") << '\n';
}

bool horaValida(const std::string& hora) {
    if (hora.size() != 5 || hora[2] != ':') return false;
    for (int i : {0, 1, 3, 4}) {
        if (hora[i] < '0' || hora[i] > '9') return false;
    }
    int horas = (hora[0] - '0') * 10 + hora[1] - '0';
    int minutos = (hora[3] - '0') * 10 + hora[4] - '0';
    return horas <= 23 && minutos <= 59;
}

int horaEnMinutos(const std::string& hora) {
    return (hora[0] - '0') * 600 + (hora[1] - '0') * 60 +
           (hora[3] - '0') * 10 + hora[4] - '0';
}

void registrarSede(std::vector<Sede*>& sedes) {
    int codigo;
    std::string nombre;
    std::string direccion;
    char activaInput;

    std::cout << "\n--- Registrar sede ---\n";
    std::cout << "Codigo: ";
    std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Direccion: ";
    std::getline(std::cin, direccion);
    std::cout << "Activa (S/N): ";
    std::cin >> activaInput;

    Sede* sede = new Sede(codigo, nombre, direccion,
                          activaInput == 'S' || activaInput == 's');
    sedes.push_back(sede);
    std::cout << "Sede registrada correctamente.\n";
}

void listarSedes(const std::vector<Sede*>& sedes) {
    std::cout << "\n--- Sedes registradas ---\n";
    if (sedes.empty()) {
        std::cout << "No hay sedes registradas.\n";
        return;
    }
    for (Sede* sede : sedes) {
        std::cout << sede->get_codigo() << " | " << sede->get_nombre()
                  << " | " << sede->get_direccion()
                  << " | " << (sede->get_activo() ? "Activa" : "Inactiva") << '\n';
    }
}

void asignarHorarioMedico(MedicoServicio& medicoServicio,
                          HorarioServicio& horarioServicio,
                          std::vector<Sede*>& sedes) {
    std::string identificador;
    std::string fecha;
    std::string dia;
    std::string horaInicio;
    std::string horaFin;
    int codigoSede;
    int codigoHorario;

    std::cout << "\n--- Asignar horario a medico ---\n";
    std::cout << "Identificador del medico: ";
    std::cin >> identificador;
    Medico* medico = medicoServicio.buscarMedicoPorIdentificador(identificador);
    if (medico == nullptr) {
        std::cout << "Medico no encontrado.\n";
        return;
    }
    if (!medico->get_activo()) {
        std::cout << "El medico no esta activo.\n";
        return;
    }

    listarSedes(sedes);
    if (sedes.empty()) {
        return;
    }
    std::cout << "Codigo de sede: ";
    std::cin >> codigoSede;
    Sede* sede = nullptr;
    for (Sede* candidata : sedes) {
        if (candidata->get_codigo() == codigoSede) {
            sede = candidata;
            break;
        }
    }
    if (sede == nullptr) {
        std::cout << "Sede no encontrada.\n";
        return;
    }
    if (!sede->get_activo()) {
        std::cout << "La sede no esta activa.\n";
        return;
    }

    std::cout << "Codigo de horario: ";
    std::cin >> codigoHorario;
    std::cout << "Dia de la semana: ";
    std::cin >> dia;
    std::cout << "Fecha (AAAA-MM-DD): ";
    std::cin >> fecha;
    std::cout << "Hora inicio (HH:MM): ";
    std::cin >> horaInicio;
    std::cout << "Hora fin (HH:MM): ";
    std::cin >> horaFin;

    if (!horaValida(horaInicio) || !horaValida(horaFin)) {
        std::cout << "Formato de hora invalido. Use HH:MM.\n";
        return;
    }
    if (horaEnMinutos(horaInicio) >= horaEnMinutos(horaFin)) {
        std::cout << "La hora inicio debe ser menor que la hora fin.\n";
        return;
    }

    Horario* horario = new Horario(codigoHorario, dia, horaInicio, horaFin, fecha);
    MedicoSede* asignacion = new MedicoSede(
        codigoHorario, medico, sede, horario
    );

    if (horarioServicio.registrarAsignacion(asignacion)) {
        sede->agregarHorario(horario);
        std::cout << "Horario asignado correctamente.\n";
    } else {
        delete asignacion;
        delete horario;
    }
}

void listarHorariosMedicos(HorarioServicio& horarioServicio) {
    std::vector<MedicoSede*> asignaciones = horarioServicio.listarAsignaciones();
    std::cout << "\n--- Horarios asignados ---\n";
    if (asignaciones.empty()) {
        std::cout << "No hay horarios asignados.\n";
        return;
    }
    for (MedicoSede* asignacion : asignaciones) {
        if (asignacion == nullptr) continue;
        Horario* horario = asignacion->get_horario();
        Medico* medico = asignacion->get_medico();
        Sede* sede = asignacion->get_sede();
        std::cout << asignacion->get_codigo()
                  << " | Medico: " << (medico ? medico->get_nombre() + " " + medico->get_apellido() : "Desconocido")
                  << " | Sede: " << (sede ? sede->get_nombre() : "Desconocida")
                  << " | " << horario->get_dia_semana()
                  << " " << horario->get_fecha()
                  << " " << horario->get_hora_inicio()
                  << "-" << horario->get_hora_fin() << '\n';
    }
}

void menuAdministracion(MedicoServicio& medicoServicio, HorarioServicio& horarioServicio,
                        std::vector<Sede*>& sedes) {
    int opcion;
    do {
        std::cout << "\n==============================\n";
        std::cout << "      ADMINISTRACION\n";
        std::cout << "==============================\n";
        std::cout << "1. Registrar medico\n";
        std::cout << "2. Listar medicos\n";
        std::cout << "3. Buscar medico\n";
        std::cout << "4. Registrar sede\n";
        std::cout << "5. Asignar horario a medico\n";
        std::cout << "6. Listar horarios asignados\n";
        std::cout << "0. Volver\n";
        std::cout << "Seleccione una opcion: ";
        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (opcion) {
            case 1: registrarMedico(medicoServicio); break;
            case 2: mostrarMedicos(medicoServicio); break;
            case 3: buscarMedico(medicoServicio); break;
            case 4: registrarSede(sedes); break;
            case 5: asignarHorarioMedico(medicoServicio, horarioServicio, sedes); break;
            case 6: listarHorariosMedicos(horarioServicio); break;
            case 0: break;
            default: std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

const char* estadoCita(EstadoCita estado) {
    switch (estado) {
        case PROGRAMADA: return "PROGRAMADA";
        case CONFIRMADA: return "CONFIRMADA";
        case ATENDIDA: return "ATENDIDA";
        case CANCELADA: return "CANCELADA";
        case INASISTENCIA: return "INASISTENCIA";
    }
    return "DESCONOCIDO";
}

void listarCitas(CitaServicio& citaServicio) {
    std::vector<Cita*> citas = citaServicio.listarCitas();
    std::cout << "\n--- Citas registradas ---\n";
    if (citas.empty()) {
        std::cout << "No hay citas registradas.\n";
        return;
    }
    for (Cita* cita : citas) {
        Paciente* paciente = cita->get_paciente();
        Medico* medico = cita->get_medico();
        std::cout << cita->get_codigo()
                  << " | Paciente: " << (paciente ? paciente->get_nombre() + " " + paciente->get_apellido() : "Sin asignar")
                  << " | Medico: " << (medico ? medico->get_nombre() + " " + medico->get_apellido() : "Sin asignar")
                  << " | " << estadoCita(cita->get_estado()) << '\n';
    }
}

void confirmarCita(CitaServicio& citaServicio) {
    std::string codigo;
    std::cout << "Codigo de cita: ";
    std::cin >> codigo;
    Cita* cita = citaServicio.buscarPorCodigo(codigo);
    if (cita == nullptr) {
        std::cout << "Cita no encontrada.\n";
        return;
    }
    if (citaServicio.confirmarCita(cita)) {
        std::cout << "Cita confirmada correctamente.\n";
    }
}

void atenderPaciente(CitaServicio& citaServicio) {
    std::string codigo;
    std::string diagnostico;
    std::string tratamiento;
    std::string observaciones;

    std::cout << "Codigo de cita confirmada: ";
    std::cin >> codigo;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    Cita* cita = citaServicio.buscarPorCodigo(codigo);
    if (cita == nullptr) {
        std::cout << "Cita no encontrada.\n";
        return;
    }
    std::cout << "Diagnostico: ";
    std::getline(std::cin, diagnostico);
    std::cout << "Tratamiento: ";
    std::getline(std::cin, tratamiento);
    std::cout << "Observaciones: ";
    std::getline(std::cin, observaciones);
    citaServicio.atenderCita(cita, diagnostico, tratamiento, observaciones);
}

void consultarHistoria(PacienteServicio& pacienteServicio, HistoriaClinicaServicio& historiaServicio) {
    std::string dni;
    std::cout << "DNI del paciente: ";
    std::cin >> dni;
    Paciente* paciente = pacienteServicio.buscarPacientePorDni(dni);
    if (paciente == nullptr) {
        std::cout << "Paciente no encontrado.\n";
        return;
    }
    std::vector<Atencion*> atenciones = historiaServicio.consultarAtenciones(paciente);
    std::cout << "\n--- Historia clinica de " << paciente->get_nombre()
              << " " << paciente->get_apellido() << " ---\n";
    if (atenciones.empty()) {
        std::cout << "No existen atenciones registradas.\n";
        return;
    }
    for (Atencion* atencion : atenciones) {
        std::cout << "Atencion #" << atencion->get_codigo()
                  << " | Diagnostico: " << atencion->get_diagnostico()
                  << " | Tratamiento: " << atencion->get_tratamiento()
                  << " | Observaciones: " << atencion->get_observaciones() << '\n';
    }
}

void menuAtenciones(PacienteServicio& pacienteServicio, CitaServicio& citaServicio,
                    HistoriaClinicaServicio& historiaServicio) {
    int opcion;
    do {
        std::cout << "\n==============================\n";
        std::cout << "      ATENCION DE PACIENTES\n";
        std::cout << "==============================\n";
        std::cout << "1. Listar citas\n";
        std::cout << "2. Confirmar cita\n";
        std::cout << "3. Atender paciente\n";
        std::cout << "4. Consultar historia clinica\n";
        std::cout << "0. Volver\n";
        std::cout << "Seleccione una opcion: ";
        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (opcion) {
            case 1: listarCitas(citaServicio); break;
            case 2: confirmarCita(citaServicio); break;
            case 3: atenderPaciente(citaServicio); break;
            case 4: consultarHistoria(pacienteServicio, historiaServicio); break;
            case 0: break;
            default: std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);
}

int main() {
    PacienteServicio pacienteServicio;
    ResponsableServicio responsableServicio;
    HistoriaClinicaServicio historiaServicio;
    MedicoServicio medicoServicio;
    Repositorio<Cita> citaRepository;
    HorarioServicio horarioServicio;
    ConsultorioServicio consultorioServicio;
    std::vector<Sede*> sedes;
    AgendaServicio agendaServicio(&citaRepository, &horarioServicio, &consultorioServicio);
    CitaServicio citaServicio(&citaRepository, &agendaServicio, &historiaServicio);
    int opcion;

    do {
        std::cout << "\n==============================\n";
        std::cout << "      SISTEMA DE CLINICA\n";
        std::cout << "==============================\n";
        std::cout << "1. Gestion de administracion\n";
        std::cout << "2. Gestion de pacientes\n";
        std::cout << "3. Gestion de citas\n";
        std::cout << "4. Gestion de atenciones\n";
        std::cout << "5. Facturacion\n";
        std::cout << "6. Probar test\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            opcion = -1;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (opcion) {
            case 1:
                menuAdministracion(medicoServicio, horarioServicio, sedes);
                break;
            case 2:
                menuPacientes(pacienteServicio, responsableServicio, historiaServicio);
                break;
            case 3:
                std::cout << "Modulo de citas pendiente.\n";
                break;
            case 4:
                menuAtenciones(pacienteServicio, citaServicio, historiaServicio);
                break;
            case 5:
                std::cout << "Modulo de facturacion pendiente.\n";
                break;
            case 6:
                probarEscenariosComprobacion();
                break;
            case 0:
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
