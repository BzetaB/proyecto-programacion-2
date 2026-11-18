#include "HistoriaClinica.h"
#include <iostream>
using namespace std;

HistoriaClinica::HistoriaClinica() {
    this->numero = 0;
}

void HistoriaClinica::setNumero(int numero) {
    this->numero = numero;
}

bool HistoriaClinica::agregarAntecedente(string antecedente) {
    if (antecedente == "") {
        cout << "ERROR: el antecedente no puede estar vacio." << endl;
        return false;
    }
    this->antecedentes.push_back(antecedente);
    return true;
}

bool HistoriaClinica::tieneAtencionDeCita(string codigoCita) const {
    for (int i = 0; i < this->atenciones.size(); i++) {
        if (this->atenciones[i].getCodigoCita() == codigoCita) return true;
    }
    return false;
}

bool HistoriaClinica::registrarAtencion(RegistroAtencion atencion) {
    if (atencion.getDiagnostico() == "") {
        cout << "ERROR: toda atencion clinica requiere un diagnostico." << endl;
        return false;
    }
    if (this->tieneAtencionDeCita(atencion.getCodigoCita())) {
        cout << "ERROR: la cita " << atencion.getCodigoCita() << " ya genero una atencion clinica." << endl;
        return false;
    }
    this->atenciones.push_back(atencion);
    return true;
}

void HistoriaClinica::mostrar() const {
    cout << "Historia clinica No. HC-" << this->numero << endl;
    cout << "  Antecedentes:";
    if (this->antecedentes.size() == 0) cout << " (ninguno registrado)";
    cout << endl;
    for (int i = 0; i < this->antecedentes.size(); i++) {
        cout << "   - " << this->antecedentes[i] << endl;
    }
    cout << "  Atenciones (" << this->atenciones.size() << "):";
    if (this->atenciones.size() == 0) cout << " (ninguna)";
    cout << endl;
    for (int i = 0; i < this->atenciones.size(); i++) {
        this->atenciones[i].mostrar();
    }
}
