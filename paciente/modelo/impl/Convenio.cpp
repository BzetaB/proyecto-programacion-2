#include "../Convenio.h"

Convenio::Convenio() = default;

Convenio::Convenio(
    std::string codigo,
    std::string empresa,
    int descuentoPorcentaje,
    bool activo
) {
    this->codigo = codigo;
    this->empresa = empresa;
    this->descuentoPorcentaje = descuentoPorcentaje;
    this->activo = activo;
}

Convenio::~Convenio() = default;

std::string Convenio::get_codigo() const {
    return codigo;
}

void Convenio::set_codigo(std::string codigo) {
    this->codigo = codigo;
}

std::string Convenio::get_empresa() const {
    return empresa;
}

void Convenio::set_empresa(std::string empresa) {
    this->empresa = empresa;
}

int Convenio::get_descuento_porcentaje() const {
    return descuentoPorcentaje;
}

void Convenio::set_descuento_porcentaje(int descuentoPorcentaje) {
    this->descuentoPorcentaje = descuentoPorcentaje;
}

bool Convenio::is_activo() const {
    return activo;
}

void Convenio::set_activo(bool activo) {
    this->activo = activo;
}