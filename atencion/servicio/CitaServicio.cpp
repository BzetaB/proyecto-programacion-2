//
// Created by thom_ on 20/11/2026.
//

#include "CitaServicio.h"

#include <iostream>

#include "../modelo/Cita.h"
#include "../modelo/Atencion.h"
#include "../servicio/AgendaServicio.h"
#include "../servicio/HistoriaClinicaServicio.h"

CitaServicio::CitaServicio(
        AgendaServicio* agendaServicio,
        HistoriaClinicaServicio* historiaClinicaServicio) {

    this->agendaServicio = agendaServicio;
    this->historiaClinicaServicio = historiaClinicaServicio;
}

bool CitaServicio::programarCita(
        Cita* cita) {

    if (cita == nullptr) {

        std::cout
            << "La cita es invalida."
            << std::endl;

        return false;
    }

    if (!agendaServicio->horarioDisponible(
            cita->get_medico(),
            cita->get_sede(),
            cita->get_servicio(),
            cita->get_horario())) {

        std::cout
            << "Horario no disponible."
            << std::endl;

        return false;
    }

    if (!agendaServicio->consultorioCompatible(
            cita->get_consultorio(),
            cita->get_sede(),
            cita->get_servicio())) {

        std::cout
            << "Consultorio incompatible."
            << std::endl;

        return false;
    }

    if (agendaServicio->existeSuperposicion(cita)) {

        std::cout
            << "Existe superposicion de horarios."
            << std::endl;

        return false;
    }

    citaRepository.agregar(cita);

    std::cout
        << "Cita programada correctamente."
        << std::endl;

    return true;
}

bool CitaServicio::confirmarCita(
        Cita* cita) {

    if (cita == nullptr) {
        return false;
    }

    if (cita->get_estado() != PROGRAMADA) {

        std::cout
            << "Solo se puede confirmar una cita programada."
            << std::endl;

        return false;
    }

    cita->set_estado(CONFIRMADA);

    return true;
}

bool CitaServicio::reprogramarCita(
        Cita* cita,
        Horario* nuevoHorario) {

    if (
        cita == nullptr ||
        nuevoHorario == nullptr
    ) {
        return false;
    }

    if (
        cita->get_estado() == ATENDIDA ||
        cita->get_estado() == CANCELADA
    ) {

        std::cout
            << "La cita no puede reprogramarse."
            << std::endl;

        return false;
    }

    Horario* horarioAnterior =
        cita->get_horario();

    cita->set_horario(nuevoHorario);

    if (agendaServicio->existeSuperposicion(cita)) {

        cita->set_horario(horarioAnterior);

        std::cout
            << "Existe superposicion."
            << std::endl;

        return false;
    }

    return true;
}

bool CitaServicio::cancelarCita(
        Cita* cita) {

    if (cita == nullptr) {
        return false;
    }

    if (cita->get_estado() == ATENDIDA) {

        std::cout
            << "No se puede cancelar una cita atendida."
            << std::endl;

        return false;
    }

    cita->set_estado(CANCELADA);

    return true;
}

bool CitaServicio::registrarInasistencia(
        Cita* cita) {

    if (cita == nullptr) {
        return false;
    }

    if (
        cita->get_estado() != PROGRAMADA &&
        cita->get_estado() != CONFIRMADA
    ) {

        std::cout
            << "Estado invalido para registrar inasistencia."
            << std::endl;

        return false;
    }

    cita->set_estado(INASISTENCIA);

    return true;
}

bool CitaServicio::atenderCita(
        Cita* cita,
        std::string diagnostico,
        std::string tratamiento,
        std::string observaciones) {

    if (cita == nullptr) {
        return false;
    }

    if (cita->get_estado() != CONFIRMADA) {

        std::cout
            << "Solo las citas confirmadas pueden ser atendidas."
            << std::endl;

        return false;
    }

    cita->set_estado(ATENDIDA);

    Atencion* atencion =
        new Atencion(
            siguienteCodigoAtencion++,
            cita,
            diagnostico,
            tratamiento,
            observaciones
        );

    return historiaClinicaServicio
        ->registrarAtencion(
            cita->get_paciente(),
            atencion
        );
}

std::vector<Cita*> CitaServicio::listarCitas() {

    return citaRepository.listar();
}

Cita* CitaServicio::buscarPorCodigo(
        const std::string& codigo) {

    for (Cita* cita : citaRepository.listar()) {

        if (
            cita != nullptr &&
            cita->get_codigo() == codigo
        ) {
            return cita;
        }
    }

    return nullptr;
}