#pragma once
// Registro de una atencion clinica realizada. Es INMUTABLE: una vez creado no se modifica.
// Se separa de los datos personales del paciente (clase Persona/Paciente).
#include "Fecha.h"
#include <string>

class RegistroAtencion {
    std::string codigoCita_, cmpMedico_, nombreMedico_, codigoSede_, nombreSede_, servicio_,
        diagnostico_, indicaciones_;
    Fecha fecha_;
public:
    RegistroAtencion(const std::string& codigoCita, const Fecha& fecha, const std::string& cmpMedico,
                     const std::string& nombreMedico, const std::string& codigoSede,
                     const std::string& nombreSede, const std::string& servicio,
                     const std::string& diagnostico, const std::string& indicaciones)
        : codigoCita_(codigoCita), cmpMedico_(cmpMedico), nombreMedico_(nombreMedico),
          codigoSede_(codigoSede), nombreSede_(nombreSede), servicio_(servicio),
          diagnostico_(diagnostico), indicaciones_(indicaciones), fecha_(fecha) {}

    const std::string& codigoCita() const { return codigoCita_; }
    const std::string& cmpMedico() const { return cmpMedico_; }
    const std::string& nombreMedico() const { return nombreMedico_; }
    const std::string& codigoSede() const { return codigoSede_; }
    const std::string& nombreSede() const { return nombreSede_; }
    const std::string& servicio() const { return servicio_; }
    const std::string& diagnostico() const { return diagnostico_; }
    const std::string& indicaciones() const { return indicaciones_; }
    const Fecha& fecha() const { return fecha_; }
};
