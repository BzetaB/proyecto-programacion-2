#pragma once

class Fecha {
private:
    int anio;
    int mes;
    int dia;
public:
    Fecha();
    Fecha(int anio, int mes, int dia);
    bool esValida() const;
    int calcularEdad(const Fecha& actual) const;
    void mostrar() const;
    bool operator==(const Fecha& otra) const;
    bool operator<(const Fecha& otra) const;
};
