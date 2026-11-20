#include <iostream>
#include <limits>

#include "paciente/modelo/Paciente.h"
#include "paciente/modelo/Responsable.h"
#include "paciente/servicio/PacienteServicio.h"
#include "paciente/servicio/ResponsableServicio.h"

void registrarPaciente(PacienteServicio& servicio, ResponsableServicio& responsableServicio) {
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
    } else if (responsable != nullptr) {
        responsableServicio.registrarResponsable(responsable, paciente);
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

void menuPacientes(PacienteServicio& servicio, ResponsableServicio& responsableServicio) {
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
                registrarPaciente(servicio, responsableServicio);
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

int main() {
    PacienteServicio pacienteServicio;
    ResponsableServicio responsableServicio;
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
                std::cout << "Modulo de administracion pendiente.\n";
                break;
            case 2:
                menuPacientes(pacienteServicio, responsableServicio);
                break;
            case 3:
                std::cout << "Modulo de citas pendiente.\n";
                break;
            case 4:
                std::cout << "Modulo de atenciones pendiente.\n";
                break;
            case 5:
                std::cout << "Modulo de facturacion pendiente.\n";
                break;
            case 0:
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
