#pragma once
// Gestor central de pacientes: garantiza identidad unica en toda la red.
#include "Paciente.h"
#include "Repositorio.h"
#include <memory>
#include <string>

class RegistroPacientes {
    Repositorio<Paciente> pacientes_;
    int contador_ = 0;
public:
    // Rechaza duplicados (por DNI o por nombre+fecha de nacimiento) y menores sin responsable.
    Paciente* registrar(const std::string& dni, const std::string& nombres,
                        const std::string& apellidos, const Fecha& nacimiento,
                        const std::string& telefono, const std::string& sedeRegistro,
                        std::unique_ptr<Responsable> responsable = nullptr);
    Paciente* buscarPorDni(const std::string& dni) const;
    Paciente* buscarPorCodigo(const std::string& codigo) const;
    const Repositorio<Paciente>& todos() const { return pacientes_; }
    int total() const { return static_cast<int>(pacientes_.tamano()); }
};
