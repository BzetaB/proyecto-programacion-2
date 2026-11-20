#include "../CajaClinica.h"
#include <iostream>
using namespace std;

bool CajaClinica::existeAtencionFacturada(int idAtencion) const {
    for (const auto& c : comprobantes) {
        if (c.getIdAtencion() == idAtencion) {
            return true;
        }
    }
    return false;
}

bool CajaClinica::registrarComprobante(const Comprobante& nuevo) {
    if (existeAtencionFacturada(nuevo.getIdAtencion())) {
        cout << "Error: La atencion #" << nuevo.getIdAtencion()
             << " ya fue facturada anteriormente.\n";
        return false;
    }
    comprobantes.push_back(nuevo);
    return true;
}

bool CajaClinica::registrarPago(int idComprobante, const Pago& pago) {
    for (auto& c : comprobantes) {
        if (c.getIdComprobante() == idComprobante) {
            double pagadoAntes = c.getTotalPagado();
            c += pago;
            return c.getTotalPagado() > pagadoAntes;
        }
    }
    cout << "Error: No se encontro el comprobante #" << idComprobante << ".\n";
    return false;
}

const vector<Comprobante>& CajaClinica::getComprobantes() const {
    return comprobantes;
}

void CajaClinica::mostrarComprobantes() const {
    for (const auto& c : comprobantes) {
        cout << c << "\n";
    }
}