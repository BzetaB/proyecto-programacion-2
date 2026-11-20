//
// Created by thom_ on 19/11/2026.
//

#ifndef PROYECTOCLINICA_HORARIOSERVICE_H
#define PROYECTOCLINICA_HORARIOSERVICE_H
#include "../../repositorio/template/Repositorio.h"
#include <vector>

class Horario;
class Medico;
class MedicoSede;
class Sede;

class HorarioServicio {
private:
    Repositorio<MedicoSede> medicoSedeRepositorio;

public:
    bool existeSuperposicion(Medico* medicoSede, Horario* horario);

    bool registrarAsignacion(MedicoSede* medicoSede);

    std::vector<MedicoSede*> listarAsignaciones();

    bool medicoDisponibleEnSede(Medico* medico,
                                Sede* sede,
                                Horario* horario,
                                int duracionMinutos);
};


#endif //PROYECTOCLINICA_HORARIOSERVICE_H
