//
// Created by thom_ on 18/11/2026.
//

#include "../Horario.h"

Horario::Horario() = default;

Horario::Horario(int codigo, std::string dia_semana, std::string hora_inicio, std::string hora_fin, std::string fecha)
    : codigo(codigo),
      diaSemana(dia_semana),
      horaInicio(hora_inicio),
      horaFin(hora_fin),
      fecha(fecha) {
}

int Horario::get_codigo() const {
    return codigo;
}

void Horario::set_codigo(int codigo) {
    this->codigo = codigo;
}

std::string Horario::get_dia_semana() const {
    return diaSemana;
}

void Horario::set_dia_semana(std::string dia_semana) {
    diaSemana = dia_semana;
}

std::string Horario::get_hora_inicio() const {
    return horaInicio;
}

void Horario::set_hora_inicio(std::string hora_inicio) {
    horaInicio = hora_inicio;
}

std::string Horario::get_hora_fin() const {
    return horaFin;
}

void Horario::set_hora_fin(std::string hora_fin) {
    horaFin = hora_fin;
}

std::string Horario::get_fecha() const {
    return fecha;
}

void Horario::set_fecha(std::string fecha) {
    this->fecha = fecha;
}
