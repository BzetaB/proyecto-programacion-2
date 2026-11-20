//
// Created by thom_ on 12/11/2026.
//

#ifndef PROYECTOCLINICA_PERSONABASE_H
#define PROYECTOCLINICA_PERSONABASE_H

#include <string>

class PersonaBase {
protected:
    std::string identificadorPersona;
    std::string nombre;
    std::string apellido;
    std::string dni;
    std::string fechaNacimiento;
    std::string correoElectronico;
    std::string celular;
    char sexo = 'M';

public:
    PersonaBase();

    virtual ~PersonaBase();

    PersonaBase(std::string identificador_persona, std::string nombre, std::string apellido, std::string dni,
        std::string fecha_nacimiento, std::string correo_electronico, std::string celular, char sexo);

    std::string get_identificador_persona() const;

    void set_identificador_persona(std::string identificador_persona);

    std::string get_nombre() const;

    void set_nombre(std::string nombre);

    std::string get_apellido() const;

    void set_apellido(std::string apellido);

    std::string get_dni() const;

    void set_dni(std::string dni);

    std::string get_fecha_nacimiento() const;

    void set_fecha_nacimiento(std::string fecha_nacimiento);

    std::string get_correo_electronico() const;

    void set_correo_electronico(std::string correo_electronico);

    std::string get_celular() const;

    void set_celular(std::string celular);

    char get_sexo() const;

    void set_sexo(char sexo);

    // Metodo virtual
    virtual std::string obtenerTipo() const = 0;
};


#endif //PROYECTOCLINICA_PERSONABASE_H
