//
// Created by thom_ on 20/11/2026.
//

#include "DatosPruebaAdministracion.h"
#include "../modelos/Especialidad.h"
#include "../modelos/Medico.h"
#include "../modelos/Servicio.h"
#include "../modelos/Sede.h"
#include "../modelos/Consultorio.h"
#include "../modelos/Horario.h"
#include "../modelos/MedicoEspecialidad.h"
#include "../modelos/MedicoSede.h"

Especialidad* DatosPruebaAdministracion::crearCardiologia() {
    return new Especialidad(1,"Cardiologia");
}

Medico* DatosPruebaAdministracion::crearMedicoCardiologo() {
    return new Medico(
        "MED001",
        "Juan",
        "Perez",
        "12345678",
        1900,
        "juan@gmail.com",
        "999111222",
        'M',
        10,
        "CMP12345",
        true);
}

Servicio* DatosPruebaAdministracion::crearServicioElectrocardiograma(Especialidad* especialidad) {

    return new Servicio(
        1,
        "Electrocardiograma",
        "Estudio cardiaco",
        30,
        150.0,
        true,
        especialidad,
{"Electrocardiografo"});
}

Sede* DatosPruebaAdministracion::crearSedePrincipal() {

    return new Sede(1, "Sede Central", "Av. Principal 123", true);
}

Consultorio* DatosPruebaAdministracion::crearConsultorioCardiologia(Sede* sede) {

    return new Consultorio(
        1,
        "Consultorio Cardiologia",
{"Camilla","Electrocardiografo","Computadora"},
sede);
}

Sede* DatosPruebaAdministracion::crearSedeSecundaria() {

    return new Sede(
        2,
        "Sede Norte",
        "Av. Los Olivos 456",
        true);
}

Consultorio* DatosPruebaAdministracion::
crearConsultorioBasico(
        Sede* sede) {

    return new Consultorio(
        2,
        "Consultorio Basico",
        {
            "Camilla"
        },
        sede);
}

Horario* DatosPruebaAdministracion::
crearHorarioManana() {

    return new Horario(
        1,
        "LUNES",
        "08:00",
        "12:00",
        "2026-11-20");
}

Horario* DatosPruebaAdministracion::
crearHorarioTarde() {

    return new Horario(
        2,
        "LUNES",
        "14:00",
        "18:00",
        "2026-11-20");
}

MedicoEspecialidad*
DatosPruebaAdministracion::
crearRelacionMedicoCardiologia(Medico* medico, Especialidad* especialidad) {

    return new MedicoEspecialidad(
        1,
        medico,
        especialidad);
}

MedicoSede*
DatosPruebaAdministracion::
crearAsignacionPrincipal(
        Medico* medico,
        Sede* sede,
        Horario* horario) {

    return new MedicoSede(
        1,
        medico,
        sede,
        horario);
}