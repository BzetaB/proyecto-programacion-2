//
// Created by thom_ on 19/11/2026.
//

#ifndef PROYECTOCLINICA_HABILITACIONSERVICIO_H
#define PROYECTOCLINICA_HABILITACIONSERVICIO_H
#include "../modelos/Medico.h"
#include "../../repositorio/template/Repositorio.h"

class MedicoEspecialidad;

class HabilitacionServicio {
private:
    Repositorio<MedicoEspecialidad> medicoEspecialidadRepository;

public:
    bool medicoHabilitadoParaServicio(Medico* medico, Servicio* servicio);

    void registrarRelacion(MedicoEspecialidad* relacion);

};


#endif //PROYECTOCLINICA_HABILITACIONSERVICIO_H
