//
// Created by thom_ on 18/11/2026.
//

#include "../MedicoEspecialidad.h"

MedicoEspecialidad::MedicoEspecialidad() = default;

MedicoEspecialidad::MedicoEspecialidad(int codigo, Medico* medico, Especialidad* especialidad)
    : codigo(codigo), medico(medico), especialidad(especialidad) {
}

MedicoEspecialidad::~MedicoEspecialidad() = default;

int MedicoEspecialidad::get_codigo() const {
    return codigo;
}

void MedicoEspecialidad::set_codigo(int codigo) {
    this->codigo = codigo;
}

Medico* MedicoEspecialidad::get_medico() const {
    return medico;
}

void MedicoEspecialidad::set_medico(Medico* medico) {
    this->medico = medico;
}

Especialidad* MedicoEspecialidad::get_especialidad() const {
    return especialidad;
}

void MedicoEspecialidad::set_especialidad(Especialidad* especialidad) {
    this->especialidad = especialidad;
}
