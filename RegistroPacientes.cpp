#include "RegistroPacientes.h"
#include <iostream>
using namespace std;

RegistroPacientes::RegistroPacientes() {
    this->contador = 0;
}

RegistroPacientes::~RegistroPacientes() {
    for (int i = 0; i < this->pacientes.size(); i++) {
        delete this->pacientes[i];
    }
    this->pacientes.clear();
}

bool RegistroPacientes::dniValido(string dni) const {
    if (dni.size() != 8) return false;
    for (int i = 0; i < dni.size(); i++) {
        if (dni[i] < '0' || dni[i] > '9') return false;
    }
    return true;
}

bool RegistroPacientes::telefonoValido(string telefono) const {
    if (telefono.size() < 7 || telefono.size() > 13) return false;
    for (int i = 0; i < telefono.size(); i++) {
        if (telefono[i] < '0' || telefono[i] > '9') return false;
    }
    return true;
}

Paciente* RegistroPacientes::buscarPorDni(string dni) const {
    for (int i = 0; i < this->pacientes.size(); i++) {
        if (this->pacientes[i]->getDni() == dni) return this->pacientes[i];
    }
    return nullptr;
}

Paciente* RegistroPacientes::registrar(string dni, string nombres, string apellidos,
                                       Fecha fechaNacimiento, string telefono, string sedeRegistro,
                                       Fecha hoy,
                                       string dniResp, string nombreResp,
                                       string parentesco, string telefonoResp) {
    // Validaciones: si algo falla se muestra el mensaje y no se registra 
    if (!this->dniValido(dni)) {
        cout << "ERROR: el DNI debe tener exactamente 8 digitos." << endl;
        return nullptr;
    }
    if (nombres == "" || apellidos == "") {
        cout << "ERROR: nombres y apellidos son obligatorios." << endl;
        return nullptr;
    }
    if (!this->telefonoValido(telefono)) {
        cout << "ERROR: telefono invalido (solo digitos, de 7 a 13)." << endl;
        return nullptr;
    }
    if (!fechaNacimiento.esValida() || hoy < fechaNacimiento) {
        cout << "ERROR: fecha de nacimiento invalida o futura." << endl;
        return nullptr;
    }

    // Evitar duplicados (aunque el paciente cambie de sede) 
    Paciente* existente = this->buscarPorDni(dni);
    if (existente != nullptr) {
        cout << "ERROR: el DNI " << dni << " ya esta registrado como PAC-" << existente->getCodigo()
             << ". La identidad es unica en la red: use ese registro en cualquier sede." << endl;
        return nullptr;
    }
    for (int i = 0; i < this->pacientes.size(); i++) {
        if (this->pacientes[i]->getNombres() == nombres && this->pacientes[i]->getApellidos() == apellidos &&
            this->pacientes[i]->getFechaNacimiento() == fechaNacimiento) {
            cout << "ERROR: posible duplicado, ya existe PAC-" << this->pacientes[i]->getCodigo()
                 << " con los mismos nombres y fecha de nacimiento." << endl;
            return nullptr;
        }
    }

    bool esMenor = fechaNacimiento.calcularEdad(hoy) < 18;
    if (esMenor) {
        if (dniResp == "") {
            cout << "ERROR: el paciente es menor de edad, debe registrarse un responsable." << endl;
            return nullptr;
        }
        if (!this->dniValido(dniResp) || nombreResp == "" || parentesco == "" || !this->telefonoValido(telefonoResp)) {
            cout << "ERROR: los datos del responsable son invalidos." << endl;
            return nullptr;
        }
        if (dniResp == dni) {
            cout << "ERROR: el paciente no puede ser su propio responsable." << endl;
            return nullptr;
        }
    }

    // se crea el paciente 
    this->contador++;
    Paciente* nuevo = new Paciente(this->contador, dni, nombres, apellidos, fechaNacimiento, telefono, sedeRegistro);
    if (esMenor) {
        nuevo->asignarResponsable(dniResp, nombreResp, parentesco, telefonoResp);
    }
    this->pacientes.push_back(nuevo);
    return nuevo;
}

int RegistroPacientes::total() const {
    return this->pacientes.size();
}

void RegistroPacientes::mostrarTodos() const {
    if (this->pacientes.size() == 0) cout << "(sin pacientes)" << endl;
    for (int i = 0; i < this->pacientes.size(); i++) {
        this->pacientes[i]->mostrar();
    }
}
