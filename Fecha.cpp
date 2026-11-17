#include "Fecha.h"
#include <cstdio>
#include <ctime>
#include <stdexcept>

namespace {
// Algoritmos de calendario civil (dias desde 1970-01-01).
long diasDesdeCivil(int y, int m, int d) {
    y -= (m <= 2) ? 1 : 0;
    const long era = (y >= 0 ? y : y - 399) / 400;
    const long yoe = y - era * 400;
    const long doy = (153L * (m + (m > 2 ? -3 : 9)) + 2) / 5 + d - 1;
    const long doe = yoe * 365 + yoe / 4 - yoe / 100 + doy;
    return era * 146097 + doe - 719468;
}

void civilDesdeDias(long z, int& y, int& m, int& d) {
    z += 719468;
    const long era = (z >= 0 ? z : z - 146096) / 146097;
    const long doe = z - era * 146097;
    const long yoe = (doe - doe / 1460 + doe / 36524 - doe / 146096) / 365;
    const long doy = doe - (365 * yoe + yoe / 4 - yoe / 100);
    const long mp = (5 * doy + 2) / 153;
    d = static_cast<int>(doy - (153 * mp + 2) / 5 + 1);
    m = static_cast<int>(mp < 10 ? mp + 3 : mp - 9);
    y = static_cast<int>(yoe + era * 400 + (m <= 2 ? 1 : 0));
}

int diasEnMes(int anio, int mes) {
    static const int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool bisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
    return (mes == 2 && bisiesto) ? 29 : dias[mes - 1];
}
} // namespace

Fecha::Fecha() : anio_(2000), mes_(1), dia_(1) {}

Fecha::Fecha(int anio, int mes, int dia) : anio_(anio), mes_(mes), dia_(dia) {
    if (!esValida(anio, mes, dia)) throw std::invalid_argument("Fecha invalida");
}

bool Fecha::esValida(int anio, int mes, int dia) {
    if (anio < 1900 || anio > 2200 || mes < 1 || mes > 12 || dia < 1) return false;
    return dia <= diasEnMes(anio, mes);
}

bool Fecha::parsear(const std::string& texto, Fecha& salida) {
    int a = 0, m = 0, d = 0, n = 0;
    if (std::sscanf(texto.c_str(), "%d-%d-%d%n", &a, &m, &d, &n) != 3) return false;
    if (static_cast<std::size_t>(n) != texto.size()) return false;
    if (!esValida(a, m, d)) return false;
    salida = Fecha(a, m, d);
    return true;
}

Fecha Fecha::hoy() {
    std::time_t t = std::time(nullptr);
    std::tm* lt = std::localtime(&t);
    return Fecha(lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday);
}

Fecha Fecha::desdeDias(long dias) {
    int y, m, d;
    civilDesdeDias(dias, y, m, d);
    return Fecha(y, m, d);
}

Fecha Fecha::proximoDiaSemana(const Fecha& desde, int diaSemana) {
    int delta = (diaSemana - desde.diaSemana() + 7) % 7;
    if (delta == 0) delta = 7;
    return desde.masDias(delta);
}

long Fecha::diasDesdeEpoca() const { return diasDesdeCivil(anio_, mes_, dia_); }

int Fecha::diaSemana() const {
    long d = diasDesdeEpoca();
    return static_cast<int>(((d % 7) + 7 + 3) % 7); // 1970-01-01 fue jueves (3)
}

int Fecha::edadA(const Fecha& r) const {
    int edad = r.anio_ - anio_;
    if (r.mes_ < mes_ || (r.mes_ == mes_ && r.dia_ < dia_)) --edad;
    return edad;
}

Fecha Fecha::masDias(int n) const { return desdeDias(diasDesdeEpoca() + n); }

std::string Fecha::aTexto() const {
    char buf[16];
    std::snprintf(buf, sizeof buf, "%04d-%02d-%02d", anio_, mes_, dia_);
    return buf;
}

bool Fecha::operator==(const Fecha& o) const {
    return anio_ == o.anio_ && mes_ == o.mes_ && dia_ == o.dia_;
}

bool Fecha::operator<(const Fecha& o) const {
    if (anio_ != o.anio_) return anio_ < o.anio_;
    if (mes_ != o.mes_) return mes_ < o.mes_;
    return dia_ < o.dia_;
}

std::ostream& operator<<(std::ostream& os, const Fecha& f) { return os << f.aTexto(); }
