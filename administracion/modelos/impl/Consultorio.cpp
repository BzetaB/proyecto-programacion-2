//
// Created by thom_ on 19/11/2026.
//

#include "../Consultorio.h"

Consultorio::~Consultorio() = default;

Consultorio::Consultorio() = default;

Consultorio::Consultorio(int codigo, std::string nombre, std::vector<std::string> equipamentos, Sede *sede) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->equipamentos = equipamentos;
    this->sede = sede;
}

int Consultorio::codigo1() const {
    return codigo;
}

void Consultorio::set_codigo(int codigo) {
    this->codigo = codigo;
}

std::string Consultorio::nombre1() const {
    return nombre;
}

void Consultorio::set_nombre(std::string nombre) {
    this->nombre = nombre;
}

std::vector<std::string> Consultorio::get_equipamentos() const {
    return equipamentos;
}

void Consultorio::set_equipamentos(std::vector<std::string> equipamentos) {
    this->equipamentos = equipamentos;
}

Sede * Consultorio::get_sede() const {
    return sede;
}

void Consultorio::set_sede(Sede *sede) {
    this->sede = sede;
}

bool Consultorio::tieneEquipamiento(const std::string& equipo) {
    for (const std::string& equipamiento : equipamentos) {
        if (equipamiento == equipo) {
            return true;
        }
    }
    return false;
}