#pragma once
#include <string>
#include "Persona.h"
#include "HistoriaClinica.h"
#include "Responsable.h"
#include "Convenio.h"
using namespace std;

class Paciente : public Persona {
private:
    int codigo;                   // se muestra como PAC-codigo
    string sedeRegistro;
    HistoriaClinica historia;     // COMPOSICION: la historia es parte del paciente
    Responsable* responsable;     // COMPOSICION: se crea con new y el paciente lo elimina
    Convenio* convenio;           // ASOCIACION: el convenio existe aparte (no se elimina aqui)
public:
    Paciente(int codigo, string dni, string nombres, string apellidos,
             Fecha fechaNacimiento, string telefono, string sedeRegistro);
    ~Paciente();

    int getCodigo() const;
    HistoriaClinica& getHistoria();
    bool esMenor(const Fecha& actual) const;
    bool asignarResponsable(string dniResp, string nombreResp, string parentesco, string telefonoResp);
    void asignarConvenio(Convenio* convenio);

    string rol() const override;
    void mostrar() const override;
};
