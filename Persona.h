#pragma once
// Clase ABSTRACTA base de toda persona natural del sistema (paciente, medico).
#include "Fecha.h"
#include <string>

class Persona {
    std::string dni_, nombres_, apellidos_, telefono_;
    Fecha fechaNacimiento_;
public:
    Persona(const std::string& dni, const std::string& nombres, const std::string& apellidos,
            const Fecha& fechaNacimiento, const std::string& telefono);
    virtual ~Persona() = default;

    const std::string& dni() const { return dni_; }
    const std::string& nombres() const { return nombres_; }
    const std::string& apellidos() const { return apellidos_; }
    const std::string& telefono() const { return telefono_; }
    const Fecha& fechaNacimiento() const { return fechaNacimiento_; }
    std::string nombreCompleto() const { return nombres_ + " " + apellidos_; }
    int edad(const Fecha& referencia) const { return fechaNacimiento_.edadA(referencia); }
    void actualizarTelefono(const std::string& telefono);

    // Metodos virtuales: el comportamiento varia segun el tipo de persona.
    virtual std::string rol() const = 0;
    virtual std::string resumen() const;

    static bool dniValido(const std::string& dni);
    static bool telefonoValido(const std::string& telefono);
};
