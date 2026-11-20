#ifndef COMPROBANTE_H
#define COMPROBANTE_H

#include <iostream>
#include <string>
#include <vector>
#include "ServicioCobro.h"
#include "Pago.h"

class Comprobante {
private:
    int idComprobante;
    int idAtencion;
    std::string dniPaciente;
    std::string medico;
    std::string sede;
    double descuentoConvenio;
    std::vector<ServicioCobro> servicios;
    std::vector<Pago> pagos;

public:
    Comprobante(int idComp, int idAten, std::string dni,
                std::string med, std::string s, double desc);

    int getIdComprobante() const;
    int getIdAtencion() const;
    std::string getDniPaciente() const;
    std::string getMedico() const;
    std::string getSede() const;

    double getSubtotal() const;
    double getTotalNeto() const;
    double getTotalPagado() const;
    double getSaldoPendiente() const;
    std::string getEstado() const;

    Comprobante& operator+=(const ServicioCobro& s);
    Comprobante& operator+=(const Pago& p);
    friend std::ostream& operator<<(std::ostream& os, const Comprobante& c);
};

#endif