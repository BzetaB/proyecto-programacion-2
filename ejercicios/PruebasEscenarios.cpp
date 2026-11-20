#include "PruebasEscenarios.h"

#include <cmath>
#include <iostream>
#include <vector>

#include "../administracion/modelos/Consultorio.h"
#include "../administracion/modelos/Horario.h"
#include "../administracion/modelos/Medico.h"
#include "../administracion/modelos/MedicoSede.h"
#include "../administracion/modelos/Sede.h"
#include "../administracion/modelos/Servicio.h"
#include "../administracion/servicio/ConsultorioServicio.h"
#include "../administracion/servicio/HorarioServicio.h"
#include "../administracion/servicio/MedicoServicio.h"
#include "../atencion/modelo/Cita.h"
#include "../atencion/servicio/AgendaServicio.h"
#include "../atencion/servicio/CitaServicio.h"
#include "../atencion/servicio/HistoriaClinicaServicio.h"
#include "../facturacion/Comprobante.h"
#include "../facturacion/Pago.h"
#include "../facturacion/Reportes.h"
#include "../facturacion/ServicioCobro.h"
#include "../paciente/modelo/Convenio.h"
#include "../paciente/modelo/HistoriaClinica.h"
#include "../paciente/modelo/Paciente.h"
#include "../paciente/servicio/PacienteServicio.h"
#include "../repositorio/template/Repositorio.h"

namespace {
int pruebasPasadas = 0;
int pruebasFalladas = 0;

void informar(const char* escenario, bool resultado) {
    std::cout << (resultado ? "[PASO] " : "[FALLO] ") << escenario << '\n';
    if (resultado) ++pruebasPasadas;
    else ++pruebasFalladas;
}

bool casiIgual(double a, double b) {
    return std::fabs(a - b) < 0.001;
}

bool probarPacienteAtendidoOtraSede() {
    PacienteServicio pacienteServicio;
    HistoriaClinicaServicio historiaServicio;
    MedicoServicio medicos;
    Repositorio<Cita> citas;
    HorarioServicio horarios;
    ConsultorioServicio consultorios;
    AgendaServicio agenda(&citas, &horarios, &consultorios);
    CitaServicio citaServicio(&citas, &agenda, &historiaServicio);

    Paciente paciente("TEST-PAC-1", "Ana", "Prueba", "TEST-DNI-1", 1995, nullptr, nullptr);
    bool registrado = pacienteServicio.registrarPaciente(&paciente);
    Paciente duplicado("TEST-PAC-DUP", "Ana", "Duplicada", "TEST-DNI-1", 1995, nullptr, nullptr);
    bool rechazadoDuplicado = !pacienteServicio.registrarPaciente(&duplicado);

    Sede sedeCentral(101, "Central", "Av. Central", true);
    Sede sedeNorte(102, "Norte", "Av. Norte", true);
    Medico medico("TEST-MED-1", "Luis", "Medico", "TEST-MED-DNI-1", 1985, 10, "CMP1", true);
    Servicio servicio(201, "Consulta", "Prueba", 30, 100.0, true, nullptr, {});
    Consultorio consultorio(301, "Consultorio Norte", {}, &sedeNorte);
    consultorios.registrarConsultorio(&consultorio);
    Horario jornada(401, "Viernes", "09:00", "18:00", "2026-12-04");
    sedeNorte.agregarHorario(&jornada);
    horarios.registrarAsignacion(new MedicoSede(501, &medico, &sedeNorte, &jornada));

    HistoriaClinica historia("HC-TEST-1", &paciente);
    historiaServicio.registrarHistoria(&historia);
    Horario horarioCita(402, "Viernes", "10:00", "10:30", "2026-12-04");
    Cita cita("TEST-CITA-1", &paciente, &medico, &servicio, &consultorio, &sedeNorte, &horarioCita, PROGRAMADA);
    bool programada = citaServicio.programarCita(&cita);
    bool confirmada = citaServicio.confirmarCita(&cita);
    bool atendida = citaServicio.atenderCita(&cita, "Diagnostico prueba", "Tratamiento prueba", "Sin observaciones");

    bool identidadUnica =
        registrado &&
        rechazadoDuplicado &&
        pacienteServicio.buscarPacientePorDni("TEST-DNI-1") == &paciente &&
        pacienteServicio.listarPacientes().size() == 1;

    return identidadUnica && programada && confirmada && atendida && cita.get_sede() == &sedeNorte;
}

bool probarCitasDuracionCruces() {
    Repositorio<Cita> citas;
    HorarioServicio horarios;
    ConsultorioServicio consultorios;
    AgendaServicio agenda(&citas, &horarios, &consultorios);
    HistoriaClinicaServicio historias;
    CitaServicio citaServicio(&citas, &agenda, &historias);

    Sede sede(102, "Norte", "Av. Norte", true);
    Medico medico("TEST-MED-2", "Carlos", "Duracion", "TEST-MED-DNI-2", 1980, 12, "CMP2", true);
    Consultorio consultorio(302, "Consultorio 302", {}, &sede);
    consultorios.registrarConsultorio(&consultorio);
    Horario jornada(403, "Viernes", "09:00", "18:00", "2026-12-04");
    sede.agregarHorario(&jornada);
    horarios.registrarAsignacion(new MedicoSede(502, &medico, &sede, &jornada));

    Paciente paciente("TEST-PAC-2", "Bea", "Duracion", "TEST-DNI-2", 1992, nullptr, nullptr);
    Servicio corta(202, "Corta", "30 minutos", 30, 80.0, true, nullptr, {});
    Servicio larga(203, "Larga", "45 minutos", 45, 120.0, true, nullptr, {});

    Horario h1(404, "Viernes", "09:00", "09:30", "2026-12-04");
    Cita cita1("TEST-CITA-2", &paciente, &medico, &corta, &consultorio, &sede, &h1, PROGRAMADA);
    bool primeraAceptada = citaServicio.programarCita(&cita1);

    Horario h2(405, "Viernes", "09:15", "10:00", "2026-12-04");
    Cita cita2("TEST-CITA-3", &paciente, &medico, &larga, &consultorio, &sede, &h2, PROGRAMADA);
    bool cruceMedicoRechazado = !citaServicio.programarCita(&cita2);

    Horario h3(406, "Viernes", "10:00", "10:45", "2026-12-04");
    Cita cita3("TEST-CITA-4", &paciente, &medico, &larga, &consultorio, &sede, &h3, PROGRAMADA);
    bool segundaDuracionAceptada = citaServicio.programarCita(&cita3);

    return primeraAceptada && cruceMedicoRechazado && segundaDuracionAceptada;
}

bool probarReprogramacionRestricciones() {
    Repositorio<Cita> citas;
    HorarioServicio horarios;
    ConsultorioServicio consultorios;
    AgendaServicio agenda(&citas, &horarios, &consultorios);
    HistoriaClinicaServicio historias;
    CitaServicio citaServicio(&citas, &agenda, &historias);

    Sede sede(103, "Este", "Av. Este", true);
    Medico medico("TEST-MED-3", "Diana", "Reprograma", "TEST-MED-DNI-3", 1978, 15, "CMP3", true);
    Servicio servicio(204, "Control", "Control", 30, 90.0, true, nullptr, {});
    Consultorio consultorio(303, "Consultorio 303", {}, &sede);
    Paciente paciente("TEST-PAC-3", "Edu", "Reprograma", "TEST-DNI-3", 1990, nullptr, nullptr);

    Horario h1(407, "Viernes", "11:00", "11:30", "2026-12-04");
    Cita cita("TEST-CITA-5", &paciente, &medico, &servicio, &consultorio, &sede, &h1, PROGRAMADA);
    Horario libre(408, "Viernes", "12:00", "12:30", "2026-12-04");
    bool programadaLuegoReprogramada = citaServicio.reprogramarCita(&cita, &libre);

    cita.set_estado(ATENDIDA);
    Horario intentoAtendida(409, "Viernes", "13:00", "13:30", "2026-12-04");
    bool atendidaNoReprogramable = !citaServicio.reprogramarCita(&cita, &intentoAtendida);

    cita.set_estado(CANCELADA);
    Horario intentoCancelada(410, "Viernes", "14:00", "14:30", "2026-12-04");
    bool canceladaNoReprogramable = !citaServicio.reprogramarCita(&cita, &intentoCancelada);

    return programadaLuegoReprogramada &&
           cita.get_horario() == &libre &&
           atendidaNoReprogramable &&
           canceladaNoReprogramable;
}

bool probarAtencionHistoriaComprobante() {
    Repositorio<Cita> citas;
    HorarioServicio horarios;
    ConsultorioServicio consultorios;
    AgendaServicio agenda(&citas, &horarios, &consultorios);
    HistoriaClinicaServicio historias;
    CitaServicio citaServicio(&citas, &agenda, &historias);

    Paciente paciente("TEST-PAC-4", "Fabio", "Atencion", "TEST-DNI-4", 1991, nullptr, nullptr);
    HistoriaClinica historia("HC-TEST-4", &paciente);
    historias.registrarHistoria(&historia);
    Sede sede(104, "Sur", "Av. Sur", true);
    Medico medico("TEST-MED-4", "Gina", "Atencion", "TEST-MED-DNI-4", 1982, 11, "CMP4", true);
    Servicio servicio(205, "Especialidad", "Atencion", 30, 150.0, true, nullptr, {});
    Consultorio consultorio(304, "Consultorio 304", {}, &sede);
    Horario horario(411, "Viernes", "15:00", "15:30", "2026-12-04");

    Cita cita("TEST-CITA-6", &paciente, &medico, &servicio, &consultorio, &sede, &horario, CONFIRMADA);
    bool atendida = citaServicio.atenderCita(&cita, "Migraña", "Analgesia", "Control en 7 dias");
    bool actualizada = historias.consultarAtenciones(&paciente).size() == 1;

    Comprobante comprobante(1, 1, paciente.get_dni(), "Gina Atencion", "Sur", 0.0);
    comprobante += ServicioCobro("Especialidad", 150.0);
    bool generado = comprobante.getIdComprobante() == 1 &&
                    casiIgual(comprobante.getTotalNeto(), 150.0);

    return atendida && actualizada && generado && cita.get_estado() == ATENDIDA;
}

bool probarPagosParcialesReportes() {
    Comprobante comprobante(2, 2, "TEST-DNI-5", "Doctor Prueba", "Central", 0.0);
    comprobante += ServicioCobro("Consulta", 100.0);
    comprobante += Pago(30.0, "Yape", "2026-12-04");

    bool saldo = casiIgual(comprobante.getSaldoPendiente(), 70.0);
    bool estado = comprobante.getEstado() == "Pago Parcial";

    std::vector<Comprobante> comprobantes;
    comprobantes.push_back(comprobante);
    bool reportes =
        casiIgual(Reportes::recaudadoPorSede(comprobantes, "Central"), 30.0) &&
        casiIgual(Reportes::pendientePorSede(comprobantes, "Central"), 70.0) &&
        casiIgual(Reportes::recaudadoPorMedico(comprobantes, "Doctor Prueba"), 30.0) &&
        casiIgual(Reportes::pendientePorMedico(comprobantes, "Doctor Prueba"), 70.0);

    return saldo && estado && reportes;
}

bool probarConvenioPaquete() {
    Convenio convenio("CONV-TEST", "Empresa Salud", 20, true);
    double subtotal = 200.0;
    double descuento = subtotal * convenio.get_descuento_porcentaje() / 100.0;
    double totalNeto = subtotal - descuento;

    Comprobante comprobante(3, 3, "TEST-DNI-6", "Doctor Convenio", "Central",
                            convenio.get_descuento_porcentaje() / 100.0);
    comprobante += ServicioCobro("Consulta", 120.0);
    comprobante += ServicioCobro("Paquete laboratorio", 80.0);

    bool calculo =
        casiIgual(comprobante.getSubtotal(), subtotal) &&
        casiIgual(descuento, 40.0) &&
        casiIgual(comprobante.getTotalNeto(), totalNeto) &&
        casiIgual(comprobante.getTotalNeto(), 160.0);

    if (calculo) {
        std::cout << "  Calculo aplicado: S/" << subtotal
                  << " - " << convenio.get_descuento_porcentaje()
                  << "% (S/" << descuento << ") = S/" << totalNeto << '\n';
    }
    return calculo;
}
}

void probarEscenariosComprobacion() {
    pruebasPasadas = 0;
    pruebasFalladas = 0;

    std::cout << "\n==============================\n";
    std::cout << "       PRUEBAS TEST\n";
    std::cout << "==============================\n";
    informar("1. Paciente registrado y atendido en sede distinta sin duplicar identidad",
             probarPacienteAtendidoOtraSede());
    informar("2. Citas de duracion variable y rechazo de cruces",
             probarCitasDuracionCruces());
    informar("3. Reprogramacion y restricciones de estado/disponibilidad",
             probarReprogramacionRestricciones());
    informar("4. Atencion, historia clinica y comprobante",
             probarAtencionHistoriaComprobante());
    informar("5. Pagos parciales, saldo e ingresos en reportes",
             probarPagosParcialesReportes());
    informar("6. Aplicacion y calculo de convenio",
             probarConvenioPaquete());

    std::cout << "\nResultado: " << pruebasPasadas << " pasaron, "
              << pruebasFalladas << " fallaron.\n";
}
