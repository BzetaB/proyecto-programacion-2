//
// Created by thom_ on 12/11/2026.
//

#include "../Paciente.h"

Paciente::~Paciente() = default;

Paciente::Paciente() = default;

Paciente::Paciente(bool es_menor_de_edad, std::string grupo_sanguineo, std::string contacto_emergencia_nombre,
    std::string contacto_emergencia_telefono): esMenorDeEdad(es_menor_de_edad),
                                               grupoSanguineo(grupo_sanguineo),
                                               contactoEmergenciaNombre(contacto_emergencia_nombre),
                                               contactoEmergenciaTelefono(contacto_emergencia_telefono) {
}

Paciente::Paciente(std::string identificador_persona, std::string nombre, std::string apellido, std::string dni,
    std::string fecha_nacimiento, std::string correo_electronico, std::string celular, char sexo, bool es_menor_de_edad,
    std::string grupo_sanguineo, std::string contacto_emergencia_nombre, std::string contacto_emergencia_telefono): PersonaBase(
        identificador_persona, nombre, apellido, dni, fecha_nacimiento, correo_electronico, celular, sexo),
    esMenorDeEdad(es_menor_de_edad),
    grupoSanguineo(grupo_sanguineo),
    contactoEmergenciaNombre(contacto_emergencia_nombre),
    contactoEmergenciaTelefono(contacto_emergencia_telefono) {
}


bool Paciente::is_es_menor_de_edad() const {
    return esMenorDeEdad;
}

void Paciente::set_es_menor_de_edad(bool es_menor_de_edad) {
    esMenorDeEdad = es_menor_de_edad;
}

std::string Paciente::get_grupo_sanguineo() const {
    return grupoSanguineo;
}

void Paciente::set_grupo_sanguineo(std::string grupo_sanguineo) {
    grupoSanguineo = grupo_sanguineo;
}

std::string Paciente::get_contacto_emergencia_nombre() const {
    return contactoEmergenciaNombre;
}

void Paciente::set_contacto_emergencia_nombre(std::string contacto_emergencia_nombre) {
    contactoEmergenciaNombre = contacto_emergencia_nombre;
}

std::string Paciente::get_contacto_emergencia_telefono() const {
    return contactoEmergenciaTelefono;
}

void Paciente::set_contacto_emergencia_telefono(std::string contacto_emergencia_telefono) {
    contactoEmergenciaTelefono = contacto_emergencia_telefono;
}
