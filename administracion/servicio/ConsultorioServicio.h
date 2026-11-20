//
// Created by thom_ on 20/11/2026.
//

#ifndef PROYECTOCLINICA_CONSULTORIOSERVICIO_H
#define PROYECTOCLINICA_CONSULTORIOSERVICIO_H
#include "../repositorio/template/Repositorio.h"


class Servicio;
class Consultorio;

class ConsultorioServicio {
private:
    Repositorio<Consultorio> consultorioRepository;

public:
    bool existeConsultorioCompatible(Servicio* servicio);

    Consultorio* obtenerConsultorioCompatible(Servicio* servicio);

    void registrarConsultorio(Consultorio* consultorio);
};


#endif //PROYECTOCLINICA_CONSULTORIOSERVICIO_H
