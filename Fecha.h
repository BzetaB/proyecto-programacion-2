#pragma once
// Fecha calendario (AAAA-MM-DD) con comparacion por operadores sobrecargados.
#include <iostream>
#include <string>

class Fecha {
    int anio_, mes_, dia_;
public:
    Fecha();                                   // 2000-01-01
    Fecha(int anio, int mes, int dia);         // lanza invalid_argument si es invalida

    static bool esValida(int anio, int mes, int dia);
    static bool parsear(const std::string& texto, Fecha& salida);
    static Fecha hoy();
    static Fecha desdeDias(long dias);         // dias desde 1970-01-01
    static Fecha proximoDiaSemana(const Fecha& desde, int diaSemana); // 0=Lunes

    long diasDesdeEpoca() const;
    int diaSemana() const;                     // 0=Lunes ... 6=Domingo
    int edadA(const Fecha& referencia) const;  // anios cumplidos a la fecha de referencia
    Fecha masDias(int n) const;
    std::string aTexto() const;

    int anio() const { return anio_; }
    int mes() const { return mes_; }
    int dia() const { return dia_; }

    bool operator==(const Fecha& o) const;
    bool operator!=(const Fecha& o) const { return !(*this == o); }
    bool operator<(const Fecha& o) const;
    bool operator<=(const Fecha& o) const { return !(o < *this); }
    bool operator>(const Fecha& o) const { return o < *this; }
    bool operator>=(const Fecha& o) const { return !(*this < o); }
};

std::ostream& operator<<(std::ostream& os, const Fecha& f);
