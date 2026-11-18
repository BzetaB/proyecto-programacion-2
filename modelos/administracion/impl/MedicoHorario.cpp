//
// Created by thom_ on 18/11/2026.
//

#include "../MedicoHorario.h"

MedicoHorario::MedicoHorario() = default;

MedicoHorario::MedicoHorario(int codigo, Medico* medico, Horario* horario)
    : codigo(codigo), medico(medico), horario(horario) {
}

MedicoHorario::~MedicoHorario() = default;

int MedicoHorario::get_codigo() const {
    return codigo;
}

void MedicoHorario::set_codigo(int codigo) {
    this->codigo = codigo;
}

Medico* MedicoHorario::get_medico() const {
    return medico;
}

void MedicoHorario::set_medico(Medico* medico) {
    this->medico = medico;
}

Horario* MedicoHorario::get_horario() const {
    return horario;
}

void MedicoHorario::set_horario(Horario* horario) {
    this->horario = horario;
}
