//
// Created by thom_ on 12/11/2026.
//

#include "../PersonaBase.h"

PersonaBase::PersonaBase() = default;

PersonaBase::~PersonaBase() = default;

PersonaBase::PersonaBase(std::string identificador_persona, std::string nombre,
    std::string apellido, std::string dni, int añoNacimiento) {
    this->identificadorPersona = identificador_persona;
    this->nombre = nombre;
    this->apellido = apellido;
    this->dni = dni;
    this->añoNacimiento = añoNacimiento;
}

std::string PersonaBase::get_identificador_persona() const {
    return identificadorPersona;
}

std::string PersonaBase::get_nombre() const {
    return nombre;
}

void PersonaBase::set_nombre(std::string nombre) {
    this->nombre = nombre;
}

std::string PersonaBase::get_apellido() const {
    return apellido;
}

void PersonaBase::set_apellido(std::string apellido) {
    this->apellido = apellido;
}

std::string PersonaBase::get_dni() const {
    return dni;
}

int PersonaBase::get_año_nacimiento() const {
    return añoNacimiento;
}

void PersonaBase::set_año_nacimiento(int año_nacimiento) {
    añoNacimiento = año_nacimiento;
}

