//
// Created by thom_ on 20/11/2026.
//

#ifndef PROYECTOCLINICA_CITASERVICIO_H
#define PROYECTOCLINICA_CITASERVICIO_H
#include <vector>
#include <string>

#include "../../repositorio/template/Repositorio.h"

class Cita;
class Horario;
class AgendaServicio;
class HistoriaClinicaServicio;

class CitaServicio {
private:
    Repositorio<Cita>* citaRepository;

    AgendaServicio* agendaServicio;
    HistoriaClinicaServicio* historiaClinicaServicio;

    int siguienteCodigoAtencion = 1;

public:

    CitaServicio(
        Repositorio<Cita>* citaRepository,
        AgendaServicio* agendaServicio,
        HistoriaClinicaServicio* historiaClinicaServicio
    );

    bool programarCita(
        Cita* cita
    );

    bool confirmarCita(
        Cita* cita
    );

    bool reprogramarCita(
        Cita* cita,
        Horario* nuevoHorario
    );

    bool cancelarCita(
        Cita* cita
    );

    bool registrarInasistencia(
        Cita* cita
    );

    bool atenderCita(
        Cita* cita,
        std::string diagnostico,
        std::string tratamiento,
        std::string observaciones
    );

    std::vector<Cita*> listarCitas();

    Cita* buscarPorCodigo(
        const std::string& codigo
    );
};


#endif //PROYECTOCLINICA_CITASERVICIO_H
