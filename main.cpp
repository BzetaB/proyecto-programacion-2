#include <iostream>

#include "administracion/modelos/Medico.h"
#include "administracion/modelos/Especialidad.h"
#include "administracion/modelos/Horario.h"
#include "administracion/modelos/Servicio.h"
#include "administracion/modelos/MedicoEspecialidad.h"
#include "administracion/modelos/MedicoSede.h"
#include "administracion/modelos/Sede.h"
#include "administracion/servicio/HabilitacionServicio.h"
#include "administracion/servicio/HorarioServicio.h"

int main() {

    // Especialidades
    Especialidad* cardiologia = new Especialidad(1, "Cardiologia");

    Especialidad* traumatologia = new Especialidad(2, "Traumatologia");

    // Servicio que requiere Cardiologia
    Servicio* electrocardiograma = new Servicio(
    1,
    "Electrocardiograma",
    "Analisis cardiaco",
    30,
    150.0,
    true,
    cardiologia
    );

    // Medico habilitado
    Medico* medicoCardiologo = new Medico(
    "MED001",
    "Juan",
    "Perez",
    "12345678",
    "1990-01-01",
    "juan@correo.com",
    "999999999",
    'M',
    10,
    "COL001",
    true
    );

    // Medico NO habilitado
    Medico* medicoTraumatologo =new Medico(
    "MED002",
    "Carlos",
    "Lopez",
    "87654321",
    "1988-02-10",
    "carlos@correo.com",
    "988888888",
    'M',
    8,
    "COL002",
    true
    );

    // Relaciones medico-especialidad
    MedicoEspecialidad* relacion1 =
        new MedicoEspecialidad(
            1,
            medicoCardiologo,
            cardiologia
        );

    MedicoEspecialidad* relacion2 =
        new MedicoEspecialidad(
            2,
            medicoTraumatologo,
            traumatologia
        );

    // Servicio de validacion
    HabilitacionServicio habilitacionServicio;

    habilitacionServicio.registrarRelacion(relacion1);
    habilitacionServicio.registrarRelacion(relacion2);

    // Caso 1
    bool resultado1 =
        habilitacionServicio.medicoHabilitadoParaServicio(
            medicoCardiologo,
            electrocardiograma
        );

    std::cout
        << "Caso 1 - Medico cardiologo: "
        << (resultado1 ? "TEST PASA" : "FALLA")
        << std::endl;

    // Caso 2
    bool resultado2 =
        habilitacionServicio.medicoHabilitadoParaServicio(
            medicoTraumatologo,
            electrocardiograma
        );

    std::cout
        << "Caso 2 - Medico traumatologo: "
        << (!resultado2 ? "TEST PASA" : "FALLA")
        << std::endl;


    Especialidad* medicinaGeneral =
    new Especialidad(3, "Medicina General");

    Medico* medicoMultiple =
        new Medico(
            "MED003",
            "Roberto",
            "Martinez",
            "11223344",
            "1985-06-15",
            "roberto@correo.com",
            "977777777",
            'M',
            12,
            "COL003",
            true
        );

    MedicoEspecialidad* relacion3 =
        new MedicoEspecialidad(
            3,
            medicoMultiple,
            medicinaGeneral
        );

    MedicoEspecialidad* relacion4 =
        new MedicoEspecialidad(
            4,
            medicoMultiple,
            cardiologia
        );

    habilitacionServicio.registrarRelacion(relacion3);
    habilitacionServicio.registrarRelacion(relacion4);

    bool resultado3 =
        habilitacionServicio.medicoHabilitadoParaServicio(
            medicoMultiple,
            electrocardiograma
        );

    std::cout
        << "Caso 3 - Medico con multiples especialidades: "
        << (resultado3 ? "TEST PASA" : "FALLA")
        << std::endl;



    // -----------------------------------
    // PRUEBAS DE SUPERPOSICION HORARIA
    // -----------------------------------

    Sede* sedeMiraflores =
        new Sede(
            1,
            "Sede Miraflores",
            "Av. Larco 123",
            true
        );

    Sede* sedeSanIsidro =
        new Sede(
            2,
            "Sede San Isidro",
            "Av. Javier Prado 456",
            true
        );

    Horario* horario1 =
        new Horario(
            1,
            "Lunes",
            "08:00",
            "12:00",
            "2026-11-20"
        );

    Horario* horario2 =
        new Horario(
            2,
            "Lunes",
            "13:00",
            "17:00",
            "2026-11-20"
        );

    Horario* horario3 =
        new Horario(
            3,
            "Lunes",
            "10:00",
            "14:00",
            "2026-11-20"
        );

    // Asignación existente
    MedicoSede* asignacion1 =
        new MedicoSede(
            1,
            medicoCardiologo,
            sedeMiraflores,
            horario1
        );

    MedicoSede* asignacion2 =
        new MedicoSede(
            2,
            medicoCardiologo,
            sedeSanIsidro,
            horario3
        );

    HorarioServicio horarioService;

    horarioService.registrarAsignacion(asignacion1);
    horarioService.registrarAsignacion(asignacion2);

    // -----------------------------------
    // Caso 1
    // Horario SIN conflicto
    // -----------------------------------

    bool resultadoHorario1 =
        horarioService.existeSuperposicion(
            medicoCardiologo,
            horario3
        );

    std::cout
        << "Caso Horario 1 (sin superposicion): "
        << (!resultadoHorario1 ? "PASA" : "FALLA");


    for (MedicoSede* m : horarioService.listarAsignaciones()) {

        std::cout
            << m->get_medico()->get_nombre()
            << " - "
            << m->get_sede()->get_nombre()
            << std::endl;
         }

    return 0;
}
