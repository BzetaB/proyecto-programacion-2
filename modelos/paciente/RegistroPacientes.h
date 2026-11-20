#pragma once
#include <string>
#include <vector>
#include "Paciente.h"
using namespace std;

// Guarda todos los pacientes de la red y evita registros duplicados.
class RegistroPacientes {
private:
    vector<Paciente*> pacientes;
    int contador;
    bool dniValido(string dni) const;
    bool telefonoValido(string telefono) const;
public:
    RegistroPacientes();
    ~RegistroPacientes();

    // Devuelve el paciente registrado, o nullptr si alguna validacion falla (muestra el error con cout).
    // Para menores de edad hay que enviar los datos del responsable.
    Paciente* registrar(string dni, string nombres, string apellidos,
                        Fecha fechaNacimiento, string telefono, string sedeRegistro,
                        Fecha hoy,
                        string dniResp = "", string nombreResp = "",
                        string parentesco = "", string telefonoResp = "");
    Paciente* buscarPorDni(string dni) const;
    int total() const;
    void mostrarTodos() const;
};
