//
// Created by thom_ on 16/11/2026.
//

#include "../Sede.h"
#include "../Consultorio.h"
#include <algorithm>
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

void Sede::agregar_consultorio(Consultorio* consultorio) {
    if (consultorio == nullptr || std::find(
        consultorios.begin(), consultorios.end(), consultorio) != consultorios.end()) {
        std::cout << "El consultorio ya está asociado a esta sede o es nulo." << std::endl;
        return;
    }

    consultorios.push_back(consultorio);
    consultorio->set_sede(this);
}

void Sede::quitar_consultorio(Consultorio* consultorio) {
    if (consultorio == nullptr) {
        return;
    }

    consultorios.erase(
        std::remove(consultorios.begin(), consultorios.end(), consultorio),
        consultorios.end());

    if (consultorio->get_sede() == this) {
        consultorio->set_sede(nullptr);
    }
}
