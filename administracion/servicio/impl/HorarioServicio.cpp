//
// Created by thom_ on 19/11/2026.
//

#include "../HorarioServicio.h"
#include "../../modelos/Horario.h"
#include "../../modelos/MedicoSede.h"
#include "../../modelos/Sede.h"

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
    for (MedicoSede* relacion : medicoSedeRepositorio.listar()) {
        if (relacion->get_medico() != medico) {
            continue;
        }

        Horario* horarioExistente = relacion->get_horario();

        if (horarioExistente-> get_fecha() != horario->get_fecha()) {
            continue;
        }

        if (horario->get_hora_inicio() < horarioExistente->get_hora_fin() &&
            horario->get_hora_fin() > horarioExistente->get_hora_inicio() ) {
            return true;
        }
    }

    return false;
}


bool HorarioServicio::registrarAsignacion(MedicoSede* medicoSede) {
    if (existeSuperposicion(medicoSede->get_medico(), medicoSede->get_horario())) {
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
