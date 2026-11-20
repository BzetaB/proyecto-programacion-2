#pragma once
#include <string>
using namespace std;

// Convenio corporativo (clase compartida con el modulo de facturacion).
class Convenio {
private:
    string codigo;
    string empresa;
    double descuentoPorcentaje;
public:
    Convenio(string codigo, string empresa, double descuentoPorcentaje);
    string getEmpresa() const;
};
