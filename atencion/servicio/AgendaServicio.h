#ifndef PROYECTOCLINICA_AGENDASERVICIO_H
#define PROYECTOCLINICA_AGENDASERVICIO_H

#include "../../repositorio/template/Repositorio.h"

class Consultorio;
class Servicio;
class Horario;
class Sede;
class Medico;
class ConsultorioServicio;
class HorarioServicio;
class Cita;

class AgendaServicio {
private:
    Repositorio<Cita>* citaRepository;

    HorarioServicio* horarioServicio;
    ConsultorioServicio* consultorioServicio;

public:

    AgendaServicio(
        Repositorio<Cita>* citaRepository,
        HorarioServicio* horarioServicio,
        ConsultorioServicio* consultorioServicio
    );

    bool horarioDisponible(
        Medico* medico,
        Sede* sede,
        Servicio* servicio,
        Horario* horario
    );

    bool consultorioCompatible(
        Consultorio* consultorio,
        Sede* sede,
        Servicio* servicio
    );

    bool existeSuperposicion(Cita* citaPropuesta);
};

#endif