//
// Created by thom_ on 20/11/2026.
//

#ifndef PROYECTOCLINICA_RESPONSABLE_H
#define PROYECTOCLINICA_RESPONSABLE_H
#include "../../base/PersonaBase.h"


class Responsable : public PersonaBase{
private:
    std::string parentesco;
public:
    Responsable();

    Responsable(
        std::string identificadorPersona,
        std::string nombre,
        std::string apellido,
        std::string dni,
        int añoNacimiento,
        std::string parentesco
    );

    ~Responsable() override;

    std::string obtenerTipo() const override;
};

#endif //PROYECTOCLINICA_RESPONSABLE_H
