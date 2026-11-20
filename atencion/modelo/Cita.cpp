#include "Cita.h"

Cita::Cita() = default;

Cita::Cita(
    std::string codigo,
    Paciente* paciente,
    Medico* medico,
    Servicio* servicio,
    Consultorio* consultorio,
    Sede* sede,
    Horario* horario,
    EstadoCita estado
) {
    this->codigo = codigo;
    this->paciente = paciente;
    this->medico = medico;
    this->servicio = servicio;
    this->consultorio = consultorio;
    this->sede = sede;
    this->horario = horario;
    this->estado = estado;
}

Cita::~Cita() = default;

std::string Cita::get_codigo() const {
    return codigo;
}

void Cita::set_codigo(std::string codigo) {
    this->codigo = codigo;
}

Paciente* Cita::get_paciente() const {
    return paciente;
}

void Cita::set_paciente(Paciente* paciente) {
    this->paciente = paciente;
}

Medico* Cita::get_medico() const {
    return medico;
}

void Cita::set_medico(Medico* medico) {
    this->medico = medico;
}

Servicio* Cita::get_servicio() const {
    return servicio;
}

void Cita::set_servicio(Servicio* servicio) {
    this->servicio = servicio;
}

Consultorio* Cita::get_consultorio() const {
    return consultorio;
}

void Cita::set_consultorio(Consultorio* consultorio) {
    this->consultorio = consultorio;
}

Sede* Cita::get_sede() const {
    return sede;
}

void Cita::set_sede(Sede* sede) {
    this->sede = sede;
}

Horario* Cita::get_horario() const {
    return horario;
}

void Cita::set_horario(Horario* horario) {
    this->horario = horario;
}

EstadoCita Cita::get_estado() const {
    return estado;
}

void Cita::set_estado(EstadoCita estado) {
    this->estado = estado;
}