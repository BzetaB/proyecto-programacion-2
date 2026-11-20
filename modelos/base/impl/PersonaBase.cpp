//
// Created by thom_ on 12/11/2026.
//

#include "../PersonaBase.h"

PersonaBase::PersonaBase() = default;

PersonaBase::~PersonaBase() = default;

PersonaBase::PersonaBase(std::string identificador_persona, std::string nombre,
    std::string apellido, std::string dni,std::string fecha_nacimiento,
    std::string correo_electronico, std::string celular, char sexo) {
    this->identificadorPersona = identificador_persona;
    this->nombre = nombre;
    this->apellido = apellido;
    this->dni = dni;
    this->fechaNacimiento = fecha_nacimiento;
    this->correoElectronico = correo_electronico;
    this->celular = celular;
    this->sexo = sexo;
}

std::string PersonaBase::get_identificador_persona() const {
    return identificadorPersona;
}

void PersonaBase::set_identificador_persona(std::string identificador_persona) {
    identificadorPersona = identificador_persona;
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

void PersonaBase::set_dni(std::string dni) {
    this->dni = dni;
}

std::string PersonaBase::get_fecha_nacimiento() const {
    return fechaNacimiento;
}

void PersonaBase::set_fecha_nacimiento(std::string fecha_nacimiento) {
    fechaNacimiento = fecha_nacimiento;
}

std::string PersonaBase::get_correo_electronico() const {
    return correoElectronico;
}

void PersonaBase::set_correo_electronico(std::string correo_electronico) {
    correoElectronico = correo_electronico;
}

std::string PersonaBase::get_celular() const {
    return celular;
}

void PersonaBase::set_celular(std::string celular) {
    this->celular = celular;
}

char PersonaBase::get_sexo() const {
    return sexo;
}

void PersonaBase::set_sexo(char sexo) {
    this->sexo = sexo;
}

