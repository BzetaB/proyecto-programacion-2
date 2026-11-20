//
// Created by thom_ on 20/11/2026.
//

#ifndef PROYECTOCLINICA_DATOSPRUEBAADMINISTRACION_H
#define PROYECTOCLINICA_DATOSPRUEBAADMINISTRACION_H
#include <vector>


class MedicoSede;
class MedicoEspecialidad;
class Horario;
class Especialidad;
class Medico;
class Servicio;
class Sede;
class Consultorio;

class DatosPruebaAdministracion {
public:
    static Especialidad* crearCardiologia();

    static Medico* crearMedicoCardiologo();

    static Servicio* crearServicioElectrocardiograma(Especialidad* especialidad);

    static Sede* crearSedePrincipal();

    static Consultorio* crearConsultorioCardiologia(Sede* sede);

    static Sede* crearSedeSecundaria();

    static Consultorio* crearConsultorioBasico(Sede* sede);

    static Horario* crearHorarioManana();

    static Horario* crearHorarioTarde();

    static MedicoEspecialidad* crearRelacionMedicoCardiologia(Medico* medico, Especialidad* especialidad);

    static MedicoSede* crearAsignacionPrincipal(Medico* medico, Sede* sede, Horario* horario);
};


#endif //PROYECTOCLINICA_DATOSPRUEBAADMINISTRACION_H
