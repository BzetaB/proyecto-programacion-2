//
// Created by thom_ on 19/11/2026.
//

#include "../Consultorio.h"
#include "../Sede.h"
#include <utility>

Consultorio::Consultorio() = default;

Consultorio::Consultorio(int codigo, std::string nombre,
                         std::vector<std::string> equipamentos, Sede* sede)
    : codigo(codigo),
      nombre(std::move(nombre)),
      equipamentos(std::move(equipamentos)) {
    set_sede(sede);
}

Consultorio::~Consultorio() {
    set_sede(nullptr);
}

int Consultorio::get_codigo() const {
    return codigo;
}

void Consultorio::set_codigo(int codigo) {
    this->codigo = codigo;
}

const std::string& Consultorio::get_nombre() const {
    return nombre;
}

void Consultorio::set_nombre(std::string nombre) {
    this->nombre = std::move(nombre);
}

const std::vector<std::string>& Consultorio::get_equipamentos() const {
    return equipamentos;
}

void Consultorio::set_equipamentos(std::vector<std::string> equipamentos) {
    this->equipamentos = std::move(equipamentos);
}

Sede* Consultorio::get_sede() const {
    return sede;
}

void Consultorio::set_sede(Sede* nuevaSede) {
    if (sede == nuevaSede) {
        return;
    }

    Sede* sedeAnterior = sede;
    sede = nuevaSede;

    if (sedeAnterior != nullptr) {
        sedeAnterior->quitar_consultorio(this);
    }
    if (nuevaSede != nullptr) {
        nuevaSede->agregar_consultorio(this);
    }
}
