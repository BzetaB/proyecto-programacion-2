//
// Created by thom_ on 20/11/2026.
//

#include "../HistoriaClinica.h"

HistoriaClinica::HistoriaClinica() = default;

HistoriaClinica::HistoriaClinica(
    std::string codigo,
    Paciente* paciente
) {
    this->codigo = codigo;
    this->paciente = paciente;
}

HistoriaClinica::~HistoriaClinica() = default;

std::string HistoriaClinica::get_codigo() const {
    return codigo;
}

void HistoriaClinica::set_codigo(std::string codigo) {
    this->codigo = codigo;
}

Paciente* HistoriaClinica::get_paciente() const {
    return paciente;
}

void HistoriaClinica::set_paciente(Paciente* paciente) {
    this->paciente = paciente;
}

std::vector<std::string> HistoriaClinica::get_antecedentes() const {
    return antecedentes;
}

void HistoriaClinica::set_antecedentes(
    std::vector<std::string> antecedentes
) {
    this->antecedentes = antecedentes;
}

std::vector<Atencion*> HistoriaClinica::get_atenciones() const {
    return atenciones;
}

void HistoriaClinica::set_atenciones(
    std::vector<Atencion*> atenciones
) {
    this->atenciones = atenciones;
}

void HistoriaClinica::agregarAntecedente(
    std::string antecedente
) {
    antecedentes.push_back(antecedente);
}

void HistoriaClinica::agregarAtencion(
    Atencion* atencion
) {
    atenciones.push_back(atencion);
}