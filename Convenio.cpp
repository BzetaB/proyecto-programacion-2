#include "Convenio.h"
using namespace std;

Convenio::Convenio(string codigo, string empresa, double descuentoPorcentaje) {
    this->codigo = codigo;
    this->empresa = empresa;
    this->descuentoPorcentaje = descuentoPorcentaje;
}

string Convenio::getEmpresa() const { return this->empresa; }
