#ifndef SERVICIO_COBRO_H
#define SERVICIO_COBRO_H

#include <string>

class ServicioCobro {
public:
    std::string descripcion;
    double precio;

    ServicioCobro(std::string desc, double p);
};

#endif