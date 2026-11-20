//
// Created by thom_ on 20/11/2026.
//

#include "../Responsable.h"

Responsable::Responsable() = default;

Responsable::Responsable(
    std::string identificadorPersona,
    std::string nombre,
    std::string apellido,
    std::string dni,
    int añoNacimiento,
    std::string parentesco
) : PersonaBase(
        identificadorPersona,
        nombre,
        apellido,
        dni,
        añoNacimiento
    ) {
    this->parentesco = parentesco;
}

Responsable::~Responsable() = default;

std::string Responsable::obtenerTipo() const {
    return "Responsable";
}