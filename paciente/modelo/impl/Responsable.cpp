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
    std::string correoElectronico,
    std::string celular,
    char sexo,
    std::string parentesco
) : PersonaBase(
        identificadorPersona,
        nombre,
        apellido,
        dni,
        añoNacimiento,
        correoElectronico,
        celular,
        sexo
    ) {
    this->parentesco = parentesco;
}

Responsable::~Responsable() = default;

std::string Responsable::obtenerTipo() const {
    return "Responsable";
}