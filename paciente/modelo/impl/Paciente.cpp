//
// Created by thom_ on 20/11/2026.
//

#include "../Paciente.h"

Paciente::Paciente() = default;

Paciente::Paciente(
    std::string identificadorPersona,
    std::string nombre,
    std::string apellido,
    std::string dni,
    int añoNacimiento,
    std::string correoElectronico,
    std::string celular,
    char sexo,
    Responsable* responsable,
    Convenio* convenio
) : PersonaBase(
        identificadorPersona,
        nombre,
        apellido,
        dni,
        añoNacimiento,
        correoElectronico,
        celular,
        sexo
    ) {

    this->responsable = responsable;
    this->convenio = convenio;
}

Paciente::~Paciente() = default;

Responsable* Paciente::get_responsable() const {
    return responsable;
}

void Paciente::set_responsable(Responsable* responsable) {
    this->responsable = responsable;
}

Convenio* Paciente::get_convenio() const {
    return convenio;
}

void Paciente::set_convenio(Convenio* convenio) {
    this->convenio = convenio;
}

std::string Paciente::obtenerTipo() const {
    return "Paciente";
}