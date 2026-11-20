#include "../Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha() {
    this->anio = 2000;
    this->mes = 1;
    this->dia = 1;
}

Fecha::Fecha(int anio, int mes, int dia) {
    this->anio = anio;
    this->mes = mes;
    this->dia = dia;
}

bool Fecha::esValida() const {
    if (this->anio < 1900 || this->anio > 2200) return false;
    if (this->mes < 1 || this->mes > 12) return false;
    int diasDelMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int maximo = diasDelMes[this->mes - 1];
    if (this->mes == 2 && ((this->anio % 4 == 0 && this->anio % 100 != 0) || this->anio % 400 == 0)) {
        maximo = 29;
    }
    return this->dia >= 1 && this->dia <= maximo;
}

int Fecha::calcularEdad(const Fecha& actual) const {
    int edad = actual.anio - this->anio;
    if (actual.mes < this->mes || (actual.mes == this->mes && actual.dia < this->dia)) {
        edad--;
    }
    return edad;
}

void Fecha::mostrar() const {
    cout << this->dia << "/" << this->mes << "/" << this->anio;
}

bool Fecha::operator==(const Fecha& otra) const {
    return this->anio == otra.anio && this->mes == otra.mes && this->dia == otra.dia;
}

bool Fecha::operator<(const Fecha& otra) const {
    if (this->anio != otra.anio) return this->anio < otra.anio;
    if (this->mes != otra.mes) return this->mes < otra.mes;
    return this->dia < otra.dia;
}
