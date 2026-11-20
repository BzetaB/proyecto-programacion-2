//
// Created by thom_ on 20/11/2026.
//

#ifndef PROYECTOCLINICA_HISTORIACLINICASERVICIO_H
#define PROYECTOCLINICA_HISTORIACLINICASERVICIO_H
#include <string>

#include "../../repositorio/template/Repositorio.h"


class Paciente;
class Atencion;
class HistoriaClinica;

class HistoriaClinicaServicio {
private:
    Repositorio<HistoriaClinica> historiaRepository;

public:
    bool registrarHistoria(HistoriaClinica* historia);

    HistoriaClinica* buscarPorPaciente(Paciente* paciente);

    std::vector<Atencion*> consultarAtenciones(Paciente* paciente);

    bool registrarAtencion(Paciente* paciente,Atencion* atencion);

    bool registrarAntecedente(Paciente* paciente, const std::string& antecedente);
};


#endif //PROYECTOCLINICA_HISTORIACLINICASERVICIO_H
