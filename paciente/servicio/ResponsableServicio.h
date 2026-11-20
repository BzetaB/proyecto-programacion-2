//
// Created by thom_ on 20/11/2026.
//

#ifndef PROYECTOCLINICA_RESPONSABLESERVICIO_H
#define PROYECTOCLINICA_RESPONSABLESERVICIO_H

#include <string>

#include "../../repositorio/template/PersonaRepositorio.h"

class Paciente;
class Responsable;

class ResponsableServicio {
private:
    PersonaRepositorio<Responsable> responsableRepository;

    bool existeIdentificador(const std::string& identificador);
    bool existeDni(const std::string& dni);

public:
    bool esMayorEdad(Responsable* responsable);
    bool validarResponsable(Responsable* responsable, Paciente* paciente);
    bool registrarResponsable(Responsable* responsable);
    bool registrarResponsable(Responsable* responsable, Paciente* paciente);
    Responsable* buscarResponsablePorIdentificador(const std::string& identificador);
    Responsable* buscarResponsablePorDni(const std::string& dni);
    std::vector<Responsable*> listarResponsables();
};

#endif // PROYECTOCLINICA_RESPONSABLESERVICIO_H
