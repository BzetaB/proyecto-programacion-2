#include "../Responsable.h"
#include <iostream>
using namespace std;

Responsable::Responsable(string dni, string nombreCompleto, string parentesco, string telefono) {
    this->dni = dni;
    this->nombreCompleto = nombreCompleto;
    this->parentesco = parentesco;
    this->telefono = telefono;
}

string Responsable::getDni() const { return this->dni; }

void Responsable::mostrar() const {
    cout << this->nombreCompleto << " (" << this->parentesco << ", DNI " << this->dni
         << ", tel. " << this->telefono << ")" << endl;
}
