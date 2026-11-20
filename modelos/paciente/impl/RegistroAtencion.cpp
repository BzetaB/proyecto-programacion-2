#include "../RegistroAtencion.h"
#include <iostream>
using namespace std;

RegistroAtencion::RegistroAtencion(string codigoCita, Fecha fecha, string nombreMedico,
                                   string nombreSede, string servicio,
                                   string diagnostico, string indicaciones) {
    this->codigoCita = codigoCita;
    this->fecha = fecha;
    this->nombreMedico = nombreMedico;
    this->nombreSede = nombreSede;
    this->servicio = servicio;
    this->diagnostico = diagnostico;
    this->indicaciones = indicaciones;
}

string RegistroAtencion::getCodigoCita() const { return this->codigoCita; }
string RegistroAtencion::getDiagnostico() const { return this->diagnostico; }

void RegistroAtencion::mostrar() const {
    cout << "  * ";
    this->fecha.mostrar();
    cout << " | " << this->nombreSede << " | " << this->servicio
         << " | Dr(a). " << this->nombreMedico << " [cita " << this->codigoCita << "]" << endl;
    cout << "      Diagnostico: " << this->diagnostico << endl;
    cout << "      Indicaciones: " << this->indicaciones << endl;
}
