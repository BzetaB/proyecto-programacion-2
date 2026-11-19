#ifndef PAGO_H
#define PAGO_H

#include <string>

class Pago {
public:
    double monto;
    std::string metodo; // Ej: "Efectivo", "Tarjeta", "Yape"
    std::string fecha;

    Pago(double m, std::string met, std::string f);
};

#endif