//
// Created by thom_ on 12/11/2026.
//

#ifndef PROYECTOCLINICA_PACIENTE_H
#define PROYECTOCLINICA_PACIENTE_H
#include "PersonaBase.h"

#include <string>

class Paciente : public PersonaBase {
private:
    bool esMenorDeEdad = false;
    std::string grupoSanguineo;
    std::string contactoEmergenciaNombre;
    std::string contactoEmergenciaTelefono;

public:
    ~Paciente() override;

    Paciente();

    Paciente(bool es_menor_de_edad, std::string grupo_sanguineo, std::string contacto_emergencia_nombre,
        std::string contacto_emergencia_telefono);

    Paciente(std::string identificador_persona, std::string nombre, std::string apellido, std::string dni,
             std::string fecha_nacimiento, std::string correo_electronico, std::string celular, char sexo,
             bool es_menor_de_edad, std::string grupo_sanguineo, std::string contacto_emergencia_nombre,
             std::string contacto_emergencia_telefono);

    bool is_es_menor_de_edad() const;

    void set_es_menor_de_edad(bool es_menor_de_edad);

    std::string get_grupo_sanguineo() const;

    void set_grupo_sanguineo(std::string grupo_sanguineo);

    std::string get_contacto_emergencia_nombre() const;

    void set_contacto_emergencia_nombre(std::string contacto_emergencia_nombre);

    std::string get_contacto_emergencia_telefono() const;

    void set_contacto_emergencia_telefono(std::string contacto_emergencia_telefono);
};


#endif //PROYECTOCLINICA_PACIENTE_H
