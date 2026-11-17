#pragma once
// Responsable legal de un paciente menor de edad. Es COMPUESTO por el Paciente.
#include <string>

class Responsable {
    std::string dni_, nombreCompleto_, parentesco_, telefono_;
public:
    Responsable(const std::string& dni, const std::string& nombreCompleto,
                const std::string& parentesco, const std::string& telefono);
    const std::string& dni() const { return dni_; }
    const std::string& nombreCompleto() const { return nombreCompleto_; }
    const std::string& parentesco() const { return parentesco_; }
    const std::string& telefono() const { return telefono_; }
    std::string resumen() const;
};
