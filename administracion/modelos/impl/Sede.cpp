//
// Created by thom_ on 16/11/2026.
//

#include "../Sede.h"
#include "../Consultorio.h"
#include <iostream>

Sede::Sede() = default;

Sede::Sede(int codigo, std::string nombre, std::string direccion, bool activo)
    : codigo(codigo),
      nombre(nombre),
      direccion(direccion),
      activo(activo) {
}

int Sede::get_codigo() const {
    return codigo;
}

void Sede::set_codigo(int codigo) {
    this->codigo = codigo;
}

std::string Sede::get_nombre() const {
    return nombre;
}

void Sede::set_nombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Sede::get_direccion() const {
    return direccion;
}

void Sede::set_direccion(std::string direccion) {
    this->direccion = direccion;
}

bool Sede::get_activo() const {
    return activo;
}

void Sede::set_activo(bool activo) {
    this->activo = activo;
}

const std::vector<Consultorio*>& Sede::get_consultorios() const {
    return consultorios;
}

