//
// Created by thom_ on 20/11/2026.
//

#include "HistoriaClinicaServicio.h"
#include <iostream>

#include "../modelo/Cita.h"
#include "../../paciente/modelo/HistoriaClinica.h"

bool HistoriaClinicaServicio::registrarHistoria(
        HistoriaClinica* historia) {

    if (buscarPorPaciente(historia->get_paciente()) != nullptr) {
        std::cout<< "El paciente ya tiene historia clínica."<< std::endl;
        return false;
    }

    historiaRepository.agregar(historia);

    return true;
}

std::vector<Atencion*> HistoriaClinicaServicio::consultarAtenciones(Paciente* paciente) {

    HistoriaClinica* historia = buscarPorPaciente(paciente);

    if (historia == nullptr) {
        return {};
    }

    return historia->get_atenciones();
}

bool HistoriaClinicaServicio::registrarAtencion(Paciente* paciente,Atencion* atencion) {

    HistoriaClinica* historia = buscarPorPaciente(paciente);

    if (historia == nullptr) {
        std::cout<< "El paciente no tiene historia clínica."<< std::endl;
        return false;
    }

    if (atencion == nullptr) {
        std::cout<< "La atención es inválida."<< std::endl;
        return false;
    }

    if (atencion->get_cita() == nullptr) {
        std::cout<< "La atención no tiene cita asociada." << std::endl;
        return false;
    }

    if (atencion->get_cita()->get_estado() != ATENDIDA) {
        std::cout<< "Solo se puede registrar una atención "
        << "para una cita atendida."<< std::endl;
        return false;
    }

    historia->agregarAtencion(atencion);

    std::cout<< "Atención registrada correctamente."<< std::endl;

    return true;
}

bool HistoriaClinicaServicio::registrarAntecedente(Paciente* paciente, const std::string& antecedente) {

    HistoriaClinica* historia = buscarPorPaciente(paciente);
    if (historia == nullptr) {
        return false;
    }
    historia->agregarAntecedente(antecedente);
    return true;
}


HistoriaClinica* HistoriaClinicaServicio::buscarPorPaciente(Paciente* paciente) {
    for (HistoriaClinica* historia : historiaRepository.listar()) {
        if (historia->get_paciente() == paciente) {
            return historia;
        }
    }
    return nullptr;
}