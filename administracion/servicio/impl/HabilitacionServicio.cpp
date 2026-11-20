//
// Created by thom_ on 19/11/2026.
//

#include "../HabilitacionServicio.h"

#include "../../modelos/Servicio.h"
#include "../../modelos/Medico.h"
#include "../../modelos/MedicoEspecialidad.h"

bool HabilitacionServicio::medicoHabilitadoParaServicio(Medico* medico, Servicio* servicio) {
    Especialidad* requerida = servicio->getEspecialidadRequerida();

    for (MedicoEspecialidad* relacion : medicoEspecialidadRepository.listar()) {
        if (relacion->get_medico() == medico && relacion->get_especialidad() == requerida) {
            return true;
        }
    }
    return false;
}

void HabilitacionServicio::registrarRelacion(MedicoEspecialidad* relacion) {
    medicoEspecialidadRepository.agregar(relacion);
}

