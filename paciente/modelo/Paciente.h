//
// Created by thom_ on 20/11/2026.
//

#ifndef PROYECTOCLINICA_PACIENTE_H
#define PROYECTOCLINICA_PACIENTE_H
#include "../../base/PersonaBase.h"


class Convenio;
class Responsable;

class Paciente : public PersonaBase{
private:
    Responsable* responsable = nullptr;
    Convenio* convenio = nullptr;
public:
    Paciente();

    Paciente(
        std::string identificadorPersona,
        std::string nombre,
        std::string apellido,
        std::string dni,
        int añoNacimiento,
        Responsable* responsable,
        Convenio* convenio
    );

    ~Paciente() override;

    Responsable* get_responsable() const;
    void set_responsable(Responsable* responsable);

    Convenio* get_convenio() const;
    void set_convenio(Convenio* convenio);

    std::string obtenerTipo() const override;
};

#endif //PROYECTOCLINICA_PACIENTE_H
