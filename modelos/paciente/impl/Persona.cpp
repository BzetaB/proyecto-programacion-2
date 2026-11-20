#include "../Persona.h"
#include <iostream>
using namespace std;

Persona::Persona(string dni, string nombres, string apellidos, Fecha fechaNacimiento, string telefono) {
    this->dni = dni;
    this->nombres = nombres;
    this->apellidos = apellidos;
    this->fechaNacimiento = fechaNacimiento;
    this->telefono = telefono;
}

string Persona::getDni() const { return this->dni; }
string Persona::getNombres() const { return this->nombres; }
string Persona::getApellidos() const { return this->apellidos; }
string Persona::getTelefono() const { return this->telefono; }
Fecha Persona::getFechaNacimiento() const { return this->fechaNacimiento; }

int Persona::edad(const Fecha& actual) const {
    return this->fechaNacimiento.calcularEdad(actual);
}

void Persona::mostrar() const {
    cout << this->rol() << ": " << this->nombres << " " << this->apellidos
         << " (DNI " << this->dni << ")" << endl;
}
