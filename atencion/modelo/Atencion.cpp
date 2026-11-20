#include "Atencion.h"

Atencion::Atencion() = default;

Atencion::Atencion(
    int codigo,
    Cita* cita,
    std::string diagnostico,
    std::string tratamiento,
    std::string observaciones
) {
    this->codigo = codigo;
    this->cita = cita;
    this->diagnostico = diagnostico;
    this->tratamiento = tratamiento;
    this->observaciones = observaciones;
}

Atencion::~Atencion() = default;

int Atencion::get_codigo() const {
    return codigo;
}

void Atencion::set_codigo(int codigo) {
    this->codigo = codigo;
}

Cita* Atencion::get_cita() const {
    return cita;
}

void Atencion::set_cita(Cita* cita) {
    this->cita = cita;
}

std::string Atencion::get_diagnostico() const {
    return diagnostico;
}

void Atencion::set_diagnostico(std::string diagnostico) {
    this->diagnostico = diagnostico;
}

std::string Atencion::get_tratamiento() const {
    return tratamiento;
}

void Atencion::set_tratamiento(std::string tratamiento) {
    this->tratamiento = tratamiento;
}

std::string Atencion::get_observaciones() const {
    return observaciones;
}

void Atencion::set_observaciones(std::string observaciones) {
    this->observaciones = observaciones;
}