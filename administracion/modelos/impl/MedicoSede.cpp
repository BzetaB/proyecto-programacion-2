//
// Created by thom_ on 18/11/2026.
//

#include "../MedicoSede.h"

MedicoSede::MedicoSede() = default;

MedicoSede::MedicoSede(int codigo, Medico* medico, Sede* sede, Horario* horario)
    : codigo(codigo), medico(medico), sede(sede), horario(horario) {
}

MedicoSede::~MedicoSede() = default;

int MedicoSede::get_codigo() const {
    return codigo;
}

void MedicoSede::set_codigo(int codigo) {
    this->codigo = codigo;
}

Medico* MedicoSede::get_medico() const {
    return medico;
}

void MedicoSede::set_medico(Medico* medico) {
    this->medico = medico;
}

Sede* MedicoSede::get_sede() const {
    return sede;
}

void MedicoSede::set_sede(Sede* sede) {
    this->sede = sede;
}

Horario* MedicoSede::get_horario() const {
    return horario;
}

void MedicoSede::set_horario(Horario* horario) {
    this->horario = horario;
}
