//
// Created by thom_ on 20/11/2026.
//

#include "ResponsableServicio.h"

#include <iostream>

#include "../modelo/Paciente.h"
#include "../modelo/Responsable.h"

Responsable* ResponsableServicio::buscarResponsablePorIdentificador(const std::string& identificador) {
    return responsableRepository.buscarPorIdentificador(identificador);
}

Responsable* ResponsableServicio::buscarResponsablePorDni(const std::string& dni) {
    return responsableRepository.buscarPorDni(dni);
}

bool ResponsableServicio::esMayorEdad(Responsable* responsable) {
    return responsable != nullptr && (2026 - responsable->get_año_nacimiento()) >= 18;
}

bool ResponsableServicio::existeIdentificador(const std::string& identificador) {
    return responsableRepository.buscarPorIdentificador(identificador) != nullptr;
}

bool ResponsableServicio::existeDni(const std::string& dni) {
    return responsableRepository.buscarPorDni(dni) != nullptr;
}

bool ResponsableServicio::registrarResponsable(Responsable* responsable) {
    if (responsable == nullptr) {
        std::cout << "Debe proporcionar los datos del responsable." << std::endl;
        return false;
    }

    if (!esMayorEdad(responsable)) {
        std::cout << "El responsable debe ser mayor de edad." << std::endl;
        return false;
    }

    if (existeIdentificador(responsable->get_identificador_persona())) {
        std::cout << "Ya existe un responsable con ese identificador." << std::endl;
        return false;
    }

    if (existeDni(responsable->get_dni())) {
        std::cout << "Ya existe un responsable con ese DNI." << std::endl;
        return false;
    }

    responsableRepository.agregar(responsable);
    std::cout << "Responsable registrado correctamente." << std::endl;
    return true;
}

bool ResponsableServicio::validarResponsable(Responsable* responsable, Paciente* paciente) {
    if (responsable == nullptr) {
        std::cout << "Debe proporcionar los datos del responsable." << std::endl;
        return false;
    }

    if (!esMayorEdad(responsable)) {
        std::cout << "El responsable debe ser mayor de edad." << std::endl;
        return false;
    }

    if (paciente != nullptr && responsable != nullptr) {
        if (responsable->get_identificador_persona() == paciente->get_identificador_persona()) {
            std::cout << "El responsable no puede tener el mismo identificador que el paciente." << std::endl;
            return false;
        }

        if (responsable->get_dni() == paciente->get_dni()) {
            std::cout << "El responsable no puede tener el mismo DNI que el paciente." << std::endl;
            return false;
        }
    }

    return true;
}

bool ResponsableServicio::registrarResponsable(Responsable* responsable, Paciente* paciente) {
    if (!validarResponsable(responsable, paciente)) {
        return false;
    }

    return registrarResponsable(responsable);
}

std::vector<Responsable*> ResponsableServicio::listarResponsables() {
    return responsableRepository.listar();
}
