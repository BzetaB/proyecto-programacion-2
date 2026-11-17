#include "Paciente.h"
#include "Convenio.h"
#include "Errores.h"

Paciente::Paciente(const std::string& codigo, const std::string& dni, const std::string& nombres,
                   const std::string& apellidos, const Fecha& nacimiento,
                   const std::string& telefono, const std::string& sedeRegistro)
    : Persona(dni, nombres, apellidos, nacimiento, telefono), codigo_(codigo),
      sedeRegistro_(sedeRegistro), historia_("HC-" + codigo.substr(codigo.find('-') + 1)),
      responsable_(nullptr), convenio_(nullptr) {}

void Paciente::asignarResponsable(std::unique_ptr<Responsable> responsable) {
    if (!responsable) throw ReglaNegocioError("Responsable no valido.");
    if (responsable->dni() == dni())
        throw ReglaNegocioError("El paciente no puede ser su propio responsable.");
    responsable_ = std::move(responsable);
}

std::string Paciente::resumen() const {
    std::string s = codigo_ + " | " + nombreCompleto() + " | DNI " + dni() + " | " +
                    std::to_string(edad(Fecha::hoy())) + " anios | registrado en " + sedeRegistro_;
    if (convenio_) s += " | convenio: " + convenio_->empresa();
    if (responsable_) s += "\n      Responsable: " + responsable_->resumen();
    return s;
}
