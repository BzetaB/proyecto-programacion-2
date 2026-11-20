//
// Created by thom_ on 19/11/2026.
//

#include "../HorarioServicio.h"
#include "../../modelos/Horario.h"
#include "../../modelos/MedicoSede.h"

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

