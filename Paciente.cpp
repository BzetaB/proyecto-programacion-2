#include "Paciente.h"
#include <iostream>
using namespace std;

// La clase base (Persona) se inicializa despues de los dos puntos.
Paciente::Paciente(int codigo, string dni, string nombres, string apellidos,
                   Fecha fechaNacimiento, string telefono, string sedeRegistro)
    : Persona(dni, nombres, apellidos, fechaNacimiento, telefono) {
    this->codigo = codigo;
    this->sedeRegistro = sedeRegistro;
    this->historia.setNumero(codigo);
    this->responsable = nullptr;
    this->convenio = nullptr;
}

Paciente::~Paciente() {
    delete this->responsable;
}

int Paciente::getCodigo() const { return this->codigo; }
HistoriaClinica& Paciente::getHistoria() { return this->historia; }

bool Paciente::esMenor(const Fecha& actual) const {
    return this->edad(actual) < 18;
}

bool Paciente::asignarResponsable(string dniResp, string nombreResp, string parentesco, string telefonoResp) {
    if (dniResp == this->dni) {
        cout << "ERROR: el paciente no puede ser su propio responsable." << endl;
        return false;
    }
    delete this->responsable;   // si ya habia uno, se reemplaza
    this->responsable = new Responsable(dniResp, nombreResp, parentesco, telefonoResp);
    return true;
}

void Paciente::asignarConvenio(Convenio* convenio) {
    this->convenio = convenio;
}

string Paciente::rol() const {
    return "Paciente";
}

void Paciente::mostrar() const {
    cout << "PAC-" << this->codigo << " | " << this->nombres << " " << this->apellidos
         << " | DNI " << this->dni << " | registrado en " << this->sedeRegistro << endl;
    if (this->convenio != nullptr) {
        cout << "      Convenio: " << this->convenio->getEmpresa() << endl;
    }
    if (this->responsable != nullptr) {
        cout << "      Responsable: ";
        this->responsable->mostrar();
    }
}
