#include "../Comprobante.h"
using namespace std;

Comprobante::Comprobante(int idComp, int idAten, string dni,
                         string med, string s, double desc)
    : idComprobante(idComp), idAtencion(idAten), dniPaciente(dni),
      medico(med), sede(s) {
    if (desc < 0.0) desc = 0.0;
    if (desc > 1.0) desc = 1.0;
    descuentoConvenio = desc;
}

int Comprobante::getIdComprobante() const { return idComprobante; }
int Comprobante::getIdAtencion() const { return idAtencion; }
string Comprobante::getDniPaciente() const { return dniPaciente; }
string Comprobante::getMedico() const { return medico; }
string Comprobante::getSede() const { return sede; }

double Comprobante::getSubtotal() const {
    double suma = 0.0;
    for (const auto& s : servicios) {
        suma += s.precio;
    }
    return suma;
}

double Comprobante::getTotalNeto() const {
    return getSubtotal() * (1.0 - descuentoConvenio);
}

double Comprobante::getTotalPagado() const {
    double suma = 0.0;
    for (const auto& p : pagos) {
        suma += p.monto;
    }
    return suma;
}

double Comprobante::getSaldoPendiente() const {
    return getTotalNeto() - getTotalPagado();
}

string Comprobante::getEstado() const {
    if (getTotalPagado() <= 0.0) return "Pendiente";
    if (getSaldoPendiente() > 0.001) return "Pago Parcial";
    return "Pagado Total";
}

Comprobante& Comprobante::operator+=(const ServicioCobro& s) {
    if (s.precio > 0) {
        servicios.push_back(s);
    }
    return *this;
}

Comprobante& Comprobante::operator+=(const Pago& p) {
    if (p.monto <= 0) {
        cout << "Error: El monto del pago debe ser mayor a 0.\n";
        return *this;
    }
    if (p.monto > getSaldoPendiente() + 0.001) {
        cout << "Error: El pago (S/" << p.monto
             << ") supera el saldo pendiente (S/" << getSaldoPendiente() << ").\n";
        return *this;
    }
    pagos.push_back(p);
    return *this;
}

ostream& operator<<(ostream& os, const Comprobante& c) {
    os << "Comprobante #" << c.idComprobante
       << " | Atencion #" << c.idAtencion
       << " | Sede: " << c.sede
       << " | Medico: " << c.medico
       << " | Neto: S/" << c.getTotalNeto()
       << " | Pagado: S/" << c.getTotalPagado()
       << " | Saldo: S/" << c.getSaldoPendiente()
       << " | Estado: " << c.getEstado();
    return os;
}