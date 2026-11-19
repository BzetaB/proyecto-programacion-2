//
// Created by thom_ on 16/11/2026.
//

#include "../Medico.h"
#include "../MedicoEspecialidad.h"
#include "../Servicio.h"

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

void Medico::agregarEspecialidad(MedicoEspecialidad* especialidad) {
    if (especialidad != nullptr) {
        especialidades.push_back(especialidad);
    }
}

bool Medico::poseeEspecialidad(Especialidad* especialidad) const {
    if (especialidad == nullptr) {
        return false;
    }

    for (MedicoEspecialidad* relacion : especialidades) {
        if (relacion != nullptr && relacion->correspondeA(this, especialidad)) {
            return true;
        }
    }

    return false;
}

bool Medico::puedeRealizarServicio(Servicio* servicio) const {
    if (servicio == nullptr || !activo || !servicio->get_activo()) {
        return false;
    }

    return poseeEspecialidad(servicio->getEspecialidadRequerida());
}
