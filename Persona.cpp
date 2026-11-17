#include "Persona.h"
#include <cctype>
#include <stdexcept>

bool Persona::dniValido(const std::string& dni) {
    if (dni.size() != 8) return false;
    for (char c : dni) if (!std::isdigit(static_cast<unsigned char>(c))) return false;
    return true;
}

bool Persona::telefonoValido(const std::string& t) {
    if (t.size() < 7 || t.size() > 13) return false;
    for (std::size_t i = 0; i < t.size(); ++i) {
        char c = t[i];
        if (!(std::isdigit(static_cast<unsigned char>(c)) || (i == 0 && c == '+'))) return false;
    }
    return true;
}

Persona::Persona(const std::string& dni, const std::string& nombres, const std::string& apellidos,
                 const Fecha& fechaNacimiento, const std::string& telefono)
    : dni_(dni), nombres_(nombres), apellidos_(apellidos), telefono_(telefono),
      fechaNacimiento_(fechaNacimiento) {
    if (!dniValido(dni)) throw std::invalid_argument("El DNI debe tener exactamente 8 digitos");
    if (nombres.empty() || apellidos.empty())
        throw std::invalid_argument("Nombres y apellidos son obligatorios");
    if (!telefonoValido(telefono))
        throw std::invalid_argument("Telefono invalido (7 a 13 digitos, '+' opcional al inicio)");
    if (fechaNacimiento > Fecha::hoy())
        throw std::invalid_argument("La fecha de nacimiento no puede ser futura");
}

void Persona::actualizarTelefono(const std::string& telefono) {
    if (!telefonoValido(telefono)) throw std::invalid_argument("Telefono invalido");
    telefono_ = telefono;
}

std::string Persona::resumen() const {
    return rol() + ": " + nombreCompleto() + " (DNI " + dni_ + ")";
}
