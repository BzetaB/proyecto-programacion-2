//
// Created by thom_ on 20/11/2026.
//

#include "AgendaServicio.h"

#include "../../administracion/modelos/Consultorio.h"
#include "../../administracion/modelos/Horario.h"
#include "../../administracion/modelos/Servicio.h"
#include "../../administracion/servicio/ConsultorioServicio.h"
#include "../../administracion/servicio/HorarioServicio.h"
#include "../../atencion/modelo/Cita.h"
#include "../../administracion/modelos/Sede.h"

AgendaServicio::AgendaServicio(
        Repositorio<Cita>* citaRepository,
        HorarioServicio* horarioServicio,
        ConsultorioServicio* consultorioServicio) {

    this->citaRepository = citaRepository;
    this->horarioServicio = horarioServicio;
    this->consultorioServicio = consultorioServicio;
}

bool AgendaServicio::horarioDisponible(
        Medico* medico,
        Sede* sede,
        Servicio* servicio,
        Horario* horario) {

    if (
       medico == nullptr ||
       sede == nullptr ||
       servicio == nullptr ||
       horario == nullptr ||
       horarioServicio == nullptr
   ) {
        return false;
   }

    if (!sede->estaDisponible(horario)) {
        return false;
    }

    return horarioServicio->medicoDisponibleEnSede(
        medico,
        sede,
        horario,
        servicio->get_duracion_minutos()
    );
}


bool AgendaServicio::consultorioCompatible(
        Consultorio* consultorio,
        Sede* sede,
        Servicio* servicio) {

    if (
        consultorio == nullptr ||
        sede == nullptr ||
        servicio == nullptr ||
        consultorioServicio == nullptr
    ) {
        return false;
    }

    if (
        consultorio->get_sede() != sede
    ) {
        return false;
    }

    return this->consultorioServicio->obtenerConsultorioCompatible(
            servicio,
            sede
        ) == consultorio;
}

bool AgendaServicio::existeSuperposicion(
        Cita* citaPropuesta) {

    for (Cita* cita : citaRepository->listar()) {

        if (cita == nullptr ||
            cita == citaPropuesta) {
            continue;
            }

        if (
            cita->get_horario()
                ->seSuperpone(
                    citaPropuesta->get_horario()
                )
        ) {

            if (
                cita->get_medico()
                ==
                citaPropuesta->get_medico()
            ) {
                return true;
            }

            if (
                cita->get_consultorio()
                ==
                citaPropuesta->get_consultorio()
            ) {
                return true;
            }
        }
         }

    return false;
}
