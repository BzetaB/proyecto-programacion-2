#include "Responsable.h"
#include "Persona.h"
#include <stdexcept>

Responsable::Responsable(const std::string& dni, const std::string& nombreCompleto,
                         const std::string& parentesco, const std::string& telefono)
    : dni_(dni), nombreCompleto_(nombreCompleto), parentesco_(parentesco), telefono_(telefono) {
    if (!Persona::dniValido(dni)) throw std::invalid_argument("DNI del responsable invalido");
    if (nombreCompleto.empty() || parentesco.empty())
        throw std::invalid_argument("Nombre y parentesco del responsable son obligatorios");
    if (!Persona::telefonoValido(telefono))
        throw std::invalid_argument("Telefono del responsable invalido");
}

std::string Responsable::resumen() const {
    return nombreCompleto_ + " (" + parentesco_ + ", DNI " + dni_ + ", tel. " + telefono_ + ")";
}
