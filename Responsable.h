#pragma once
#include <string>
using namespace std;

// Responsable de un paciente menor de edad.
class Responsable {
private:
    string dni;
    string nombreCompleto;
    string parentesco;
    string telefono;
public:
    Responsable(string dni, string nombreCompleto, string parentesco, string telefono);
    string getDni() const;
    void mostrar() const;
};
