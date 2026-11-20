#pragma once
#include <string>
#include "Fecha.h"
using namespace std;

// Una atencion clinica ya realizada. Se separa de los datos personales del paciente.
class RegistroAtencion {
private:
    string codigoCita;
    Fecha fecha;
    string nombreMedico;
    string nombreSede;
    string servicio;
    string diagnostico;
    string indicaciones;
public:
    RegistroAtencion(string codigoCita, Fecha fecha, string nombreMedico,
                     string nombreSede, string servicio,
                     string diagnostico, string indicaciones);
    string getCodigoCita() const;
    string getDiagnostico() const;
    void mostrar() const;
};
