//
// Created by thom_ on 16/11/2026.
//

#include "../Especialidad.h"

Especialidad::Especialidad() = default;

Especialidad::Especialidad(int codigo, std::string nombre)
    : codigo(codigo),
      nombre(nombre) {
}

int Especialidad::get_codigo() const {
    return codigo;
}

void Especialidad::set_codigo(int codigo) {
    this->codigo = codigo;
}

std::string Especialidad::get_nombre() const {
    return nombre;
}

void Especialidad::set_nombre(std::string nombre) {
    this->nombre = nombre;
}
