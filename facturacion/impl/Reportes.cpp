#include "../Reportes.h"
#include <iostream>
using namespace std;

double Reportes::recaudadoPorSede(const vector<Comprobante>& lista, const string& sede) {
    double total = 0.0;
    for (const auto& c : lista) {
        if (c.getSede() == sede) {
            total += c.getTotalPagado();
        }
    }
    return total;
}

double Reportes::pendientePorSede(const vector<Comprobante>& lista, const string& sede) {
    double total = 0.0;
    for (const auto& c : lista) {
        if (c.getSede() == sede) {
            total += c.getSaldoPendiente();
        }
    }
    return total;
}

void Reportes::mostrarReportePorSede(const vector<Comprobante>& lista, const string& sede) {
    cout << "--- Reporte Sede: " << sede << " ---\n"
         << "Recaudado: S/" << recaudadoPorSede(lista, sede) << "\n"
         << "Pendiente por cobrar: S/" << pendientePorSede(lista, sede) << "\n";
}

double Reportes::recaudadoPorMedico(const vector<Comprobante>& lista, const string& medico) {
    double total = 0.0;
    for (const auto& c : lista) {
        if (c.getMedico() == medico) {
            total += c.getTotalPagado();
        }
    }
    return total;
}

double Reportes::pendientePorMedico(const vector<Comprobante>& lista, const string& medico) {
    double total = 0.0;
    for (const auto& c : lista) {
        if (c.getMedico() == medico) {
            total += c.getSaldoPendiente();
        }
    }
    return total;
}

void Reportes::mostrarReportePorMedico(const vector<Comprobante>& lista, const string& medico) {
    cout << "--- Reporte Medico: " << medico << " ---\n"
         << "Recaudado: S/" << recaudadoPorMedico(lista, medico) << "\n"
         << "Pendiente por cobrar: S/" << pendientePorMedico(lista, medico) << "\n";
}