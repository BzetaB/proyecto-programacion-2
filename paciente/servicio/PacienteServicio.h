//
// Created by thom_ on 20/11/2026.
//

#ifndef PROYECTOCLINICA_PACIENTESERVICIO_H
#define PROYECTOCLINICA_PACIENTESERVICIO_H
#include <string>

#include "../../repositorio/template/PersonaRepositorio.h"

class Paciente;

class PacienteServicio {
private:
    PersonaRepositorio<Paciente> pacienteRepository;
    bool existeIdentificador(const std::string& identificador);

    bool existeDni(const std::string& dni);

public:
    bool esMenorEdad(Paciente* paciente);
    bool registrarPaciente(Paciente* paciente);
    Paciente* buscarPacientePorIdentificador(const std::string& identificador);
    std::vector<Paciente*> listarPacientes();
    Paciente* buscarPacientePorDni(const std::string& dni);
};


#endif //PROYECTOCLINICA_PACIENTESERVICIO_H
