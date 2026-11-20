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
    int añoNacimiento;

public:
    PersonaBase();

    virtual ~PersonaBase();

    PersonaBase(std::string identificador_persona, std::string nombre, std::string apellido, std::string dni,
        int añoNacimiento);

    std::string get_identificador_persona() const;

    std::string get_nombre() const;

    void set_nombre(std::string nombre);

    std::string get_apellido() const;

    void set_apellido(std::string apellido);

    std::string get_dni() const;

    int get_año_nacimiento() const;

    void set_año_nacimiento(int año_nacimiento);

    static bool existeIdentificadorRegistrado(const std::string& identificador);
    static bool registrarIdentificador(const std::string& identificador);

    // Metodo virtual
    virtual std::string obtenerTipo() const = 0;
};


#endif //PROYECTOCLINICA_PERSONABASE_H
