#ifndef CAJA_CLINICA_H
#define CAJA_CLINICA_H

#include <vector>
#include "Comprobante.h"

class CajaClinica {
private:
    std::vector<Comprobante> comprobantes;

public:
    bool existeAtencionFacturada(int idAtencion) const;
    bool registrarComprobante(const Comprobante& nuevo);
    bool registrarPago(int idComprobante, const Pago& pago);
    const std::vector<Comprobante>& getComprobantes() const;
    void mostrarComprobantes() const;
};

#endif