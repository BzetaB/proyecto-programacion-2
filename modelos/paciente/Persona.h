#pragma once
#include <string>
#include "Fecha.h"
using namespace std;

// Clase ABSTRACTA: no se puede crear una Persona sola, solo una clase derivada (Paciente).
class Persona {
protected:
    string dni;
    string nombres;
    string apellidos;
    string telefono;
    Fecha fechaNacimiento;
public:
    Persona(string dni, string nombres, string apellidos,
            Fecha fechaNacimiento, string telefono);
    virtual ~Persona() {}

    string getDni() const;
    string getNombres() const;
    string getApellidos() const;
    string getTelefono() const;
    Fecha getFechaNacimiento() const;
    int edad(const Fecha& actual) const;

    virtual string rol() const = 0;   // virtual puro
    virtual void mostrar() const;
};
