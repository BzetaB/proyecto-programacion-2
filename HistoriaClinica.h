#pragma once
#include <string>
#include <vector>
#include "RegistroAtencion.h"
using namespace std;

// Historia clinica unica del paciente (compartida entre sedes).
class HistoriaClinica {
private:
    int numero;
    vector<string> antecedentes;
    vector<RegistroAtencion> atenciones;
public:
    HistoriaClinica();
    void setNumero(int numero);
    bool agregarAntecedente(string antecedente);
    bool registrarAtencion(RegistroAtencion atencion);
    bool tieneAtencionDeCita(string codigoCita) const;
    void mostrar() const;
};
