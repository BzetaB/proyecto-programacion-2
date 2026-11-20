//
// Created by thom_ on 20/11/2026.
//

#include "PacienteServicio.h"

#include <iostream>

#include "../../paciente/modelo/Paciente.h"
#include "../../paciente/modelo/Responsable.h"
#include <string>

Paciente* PacienteServicio::buscarPacientePorIdentificador(const std::string& identificador) {
    return pacienteRepository.buscarPorIdentificador(identificador);
}

Paciente* PacienteServicio::buscarPacientePorDni(const std::string& dni) {
    return pacienteRepository.buscarPorDni(dni);
}

bool PacienteServicio::esMenorEdad(Paciente* paciente) {
    return (2026 - paciente->get_año_nacimiento()) < 18;
}

bool PacienteServicio::existeIdentificador(const std::string& identificador) {
    return pacienteRepository.buscarPorIdentificador(identificador) != nullptr;
}
bool PacienteServicio::existeDni(const std::string& dni) {
    return pacienteRepository.buscarPorDni(dni) != nullptr;
}

bool PacienteServicio::registrarPaciente(Paciente* paciente) {

    if (existeIdentificador(paciente->get_identificador_persona())) {
        std::cout << "Ya existe un paciente con ese identificador."<< std::endl;
        return false;
    }

    if (existeDni(paciente->get_dni())) {
        std::cout << "Ya existe un paciente con ese DNI."<< std::endl;
        return false;
    }

    if (esMenorEdad(paciente) && paciente->get_responsable() == nullptr) {
        std::cout << "Los pacientes menores de edad deben tener responsable."<< std::endl;
        return false;
    }

    Responsable* responsable = paciente->get_responsable();
    if (responsable != nullptr) {
        if ((2026 - responsable->get_año_nacimiento()) < 18) {
            std::cout << "El responsable debe ser mayor de edad." << std::endl;
            return false;
        }

        if (responsable->get_identificador_persona() == paciente->get_identificador_persona()) {
            std::cout << "El responsable no puede tener el mismo identificador que el paciente." << std::endl;
            return false;
        }

        if (responsable->get_dni() == paciente->get_dni()) {
            std::cout << "El responsable no puede tener el mismo DNI que el paciente." << std::endl;
            return false;
        }
    }

    pacienteRepository.agregar(paciente);

    std::cout << "Paciente registrado correctamente."<< std::endl;

    return true;
}

std::vector<Paciente*> PacienteServicio::listarPacientes() {
    return pacienteRepository.listar();
}