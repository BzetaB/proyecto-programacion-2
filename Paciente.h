#pragma once
// Paciente: identidad unica en toda la red + historia clinica compartida (composicion).
#include "HistoriaClinica.h"
#include "Persona.h"
#include "Responsable.h"
#include <memory>
#include <string>

class Convenio;   // asociacion opcional (0..1) con un convenio corporativo

class Paciente : public Persona {
    std::string codigo_;          // PAC-0001, unico en la red
    std::string sedeRegistro_;    // sede donde se registro por primera vez
    HistoriaClinica historia_;                 // composicion 1 a 1
    std::unique_ptr<Responsable> responsable_; // composicion 0..1 (obligatorio si es menor)
    const Convenio* convenio_;                 // asociacion 0..1
public:
    Paciente(const std::string& codigo, const std::string& dni, const std::string& nombres,
             const std::string& apellidos, const Fecha& nacimiento, const std::string& telefono,
             const std::string& sedeRegistro);
    ~Paciente() override = default;
    Paciente(const Paciente&) = delete;
    Paciente& operator=(const Paciente&) = delete;

    const std::string& codigo() const { return codigo_; }
    const std::string& sedeRegistro() const { return sedeRegistro_; }
    HistoriaClinica& historia() { return historia_; }
    const HistoriaClinica& historia() const { return historia_; }
    const Responsable* responsable() const { return responsable_.get(); }
    const Convenio* convenio() const { return convenio_; }

    bool esMenor(const Fecha& referencia) const { return edad(referencia) < 18; }
    void asignarResponsable(std::unique_ptr<Responsable> responsable);
    void asignarConvenio(const Convenio* convenio) { convenio_ = convenio; }

    std::string rol() const override { return "Paciente"; }
    std::string resumen() const override;
};
