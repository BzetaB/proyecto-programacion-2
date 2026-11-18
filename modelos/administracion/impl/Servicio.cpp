//
// Created by thom_ on 16/11/2026.
//

#include "../Servicio.h"

Servicio::Servicio() = default;

Servicio::Servicio(int codigo, std::string nombre, std::string descripcion, int duracion_minutos, double tarifa_base,
                   bool activo)
    : codigo(codigo),
      nombre(nombre),
      descripcion(descripcion),
      duracionMinutos(duracion_minutos),
      tarifaBase(tarifa_base),
      activo(activo) {
}

int Servicio::get_codigo() const {
    return codigo;
}

void Servicio::set_codigo(int codigo) {
    this->codigo = codigo;
}

std::string Servicio::get_nombre() const {
    return nombre;
}

void Servicio::set_nombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Servicio::get_descripcion() const {
    return descripcion;
}

void Servicio::set_descripcion(std::string descripcion) {
    this->descripcion = descripcion;
}

int Servicio::get_duracion_minutos() const {
    return duracionMinutos;
}

void Servicio::set_duracion_minutos(int duracion_minutos) {
    duracionMinutos = duracion_minutos;
}

double Servicio::get_tarifa_base() const {
    return tarifaBase;
}

void Servicio::set_tarifa_base(double tarifa_base) {
    tarifaBase = tarifa_base;
}

bool Servicio::get_activo() const {
    return activo;
}

void Servicio::set_activo(bool activo) {
    this->activo = activo;
}
