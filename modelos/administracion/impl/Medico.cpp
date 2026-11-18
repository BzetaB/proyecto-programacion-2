//
// Created by thom_ on 16/11/2026.
//

#include "../Medico.h"

Medico::Medico() = default;

Medico::Medico(std::string identificador_persona, std::string nombre, std::string apellido, std::string dni,
               std::string fecha_nacimiento, std::string correo_electronico, std::string celular, char sexo,
               int anios_experiencia, std::string colegiatura, bool activo)
    : PersonaBase(std::string(identificador_persona), std::string(nombre), std::string(apellido), std::string(dni),
                  std::string(fecha_nacimiento), std::string(correo_electronico), std::string(celular), sexo),
      aniosExperiencia(anios_experiencia),
      colegiatura(std::string(colegiatura)),
      activo(activo) {
}

int Medico::get_anios_experiencia() const {
    return aniosExperiencia;
}

void Medico::set_anios_experiencia(int anios_experiencia) {
    aniosExperiencia = anios_experiencia;
}

std::string Medico::get_colegiatura() const {
    return colegiatura;
}

void Medico::set_colegiatura(std::string colegiatura) {
    this->colegiatura = std::string(colegiatura);
}

bool Medico::get_activo() const {
    return activo;
}

void Medico::set_activo(bool activo) {
    this->activo = activo;
}
