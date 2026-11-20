//
// Created by thom_ on 20/11/2026.
//

#ifndef PROYECTOCLINICA_CONSULTORIOSERVICIO_H
#define PROYECTOCLINICA_CONSULTORIOSERVICIO_H
#include "../../repositorio/template/Repositorio.h"


class Servicio;
class Consultorio;
class Sede;

class ConsultorioServicio {
private:
    Repositorio<Consultorio> consultorioRepository;

public:
    bool existeConsultorioCompatible(Servicio* servicio);

    Consultorio* obtenerConsultorioCompatible(Servicio* servicio);

    void registrarConsultorio(Consultorio* consultorio);

    bool existeConsultorioCompatible(Servicio* servicio, Sede* sede);

    Consultorio* obtenerConsultorioCompatible(Servicio* servicio, Sede* sede);
};


#endif //PROYECTOCLINICA_CONSULTORIOSERVICIO_H
