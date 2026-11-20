//
// Created by thom_ on 19/11/2026.
//

#include "../HorarioServicio.h"
#include "../../modelos/Horario.h"
#include "../../modelos/MedicoSede.h"
#include "../../modelos/Sede.h"
#include <iostream>

static int convertirHoraAsignacion(const std::string& hora) {
    if (hora.size() < 5 || hora[2] != ':') {
        return -1;
    }
    if (hora[0] < '0' || hora[0] > '9' ||
        hora[1] < '0' || hora[1] > '9' ||
        hora[3] < '0' || hora[3] > '9' ||
        hora[4] < '0' || hora[4] > '9') {
        return -1;
    }
    int horas = (hora[0] - '0') * 10 + (hora[1] - '0');
    int minutos = (hora[3] - '0') * 10 + (hora[4] - '0');
    if (horas > 23 || minutos > 59) {
        return -1;
    }
    return horas * 60 + minutos;
}

bool HorarioServicio::existeSuperposicion(Medico* medico, Horario* horario) {
    if (medico == nullptr || horario == nullptr) {
        return false;
    }

    for (MedicoSede* relacion : medicoSedeRepositorio.listar()) {
        if (relacion == nullptr || relacion->get_medico() != medico) {
            continue;
        }

        Horario* horarioExistente = relacion->get_horario();
        if (horarioExistente != nullptr && horarioExistente->seSuperpone(horario)) {
            return true;
        }
    }

    return false;
}

bool HorarioServicio::existeAsignacionDuplicada(Medico* medico, Sede* sede, Horario* horario) {
    if (medico == nullptr || sede == nullptr || horario == nullptr) {
        return false;
    }

    for (MedicoSede* relacion : medicoSedeRepositorio.listar()) {
        if (relacion == nullptr ||
            relacion->get_medico() != medico ||
            relacion->get_sede() != sede) {
            continue;
        }

        Horario* existente = relacion->get_horario();
        if (existente != nullptr &&
            existente->get_fecha() == horario->get_fecha() &&
            existente->get_hora_inicio() == horario->get_hora_inicio() &&
            existente->get_hora_fin() == horario->get_hora_fin()) {
            return true;
        }
    }
    return false;
}


bool HorarioServicio::registrarAsignacion(MedicoSede* medicoSede) {
    if (medicoSede == nullptr ||
        medicoSede->get_medico() == nullptr ||
        medicoSede->get_sede() == nullptr ||
        medicoSede->get_horario() == nullptr) {
        return false;
    }

    if (existeAsignacionDuplicada(
            medicoSede->get_medico(),
            medicoSede->get_sede(),
            medicoSede->get_horario())) {
        std::cout << "La asignacion ya existe para ese medico, sede y horario." << std::endl;
        return false;
    }

    if (existeSuperposicion(medicoSede->get_medico(), medicoSede->get_horario())) {
        std::cout << "El horario se superpone con una asignacion existente." << std::endl;
        return false;
    }

    medicoSedeRepositorio.agregar(medicoSede);

    return true;
}

std::vector<MedicoSede*> HorarioServicio::listarAsignaciones() {
    return medicoSedeRepositorio.listar();
}

bool HorarioServicio::medicoDisponibleEnSede(Medico* medico,
                                             Sede* sede,
                                             Horario* horario,
                                             int duracionMinutos) {
    if (medico == nullptr || sede == nullptr || horario == nullptr || duracionMinutos <= 0) {
        return false;
    }

    int inicio = convertirHoraAsignacion(horario->get_hora_inicio());
    int fin = inicio + duracionMinutos;
    if (inicio < 0) {
        return false;
    }

    for (MedicoSede* relacion : medicoSedeRepositorio.listar()) {
        if (relacion->get_medico() == medico &&
            relacion->get_sede() == sede) {
            Horario* asignacion = relacion->get_horario();
            if (asignacion != nullptr &&
                asignacion->get_fecha() == horario->get_fecha()) {
                int inicioAsignacion = convertirHoraAsignacion(asignacion->get_hora_inicio());
                int finAsignacion = convertirHoraAsignacion(asignacion->get_hora_fin());
                if (inicioAsignacion >= 0 && finAsignacion > inicioAsignacion &&
                    inicio >= inicioAsignacion && fin <= finAsignacion) {
                    return true;
                }
            }
        }
    }
    return false;
}
