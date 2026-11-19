#ifndef REPORTES_H
#define REPORTES_H

#include <iostream>
#include <string>
#include <vector>
#include "Comprobante.h"

class Reportes {
public:
    template <typename T, typename Criterio>
    static double sumarRecaudado(const std::vector<T>& lista, Criterio cumpleFiltro) {
        double total = 0.0;
        for (const auto& item : lista) {
            if (cumpleFiltro(item)) {
                total += item.getTotalPagado();
            }
        }
        return total;
    }

    template <typename T, typename Criterio>
    static double sumarPendiente(const std::vector<T>& lista, Criterio cumpleFiltro) {
        double total = 0.0;
        for (const auto& item : lista) {
            if (cumpleFiltro(item)) {
                total += item.getSaldoPendiente();
            }
        }
        return total;
    }

    static void mostrarReportePorSede(const std::vector<Comprobante>& lista, const std::string& sede) {
        auto filtroSede = [&](const Comprobante& c) { return c.getSede() == sede; };
        std::cout << "--- Reporte Sede: " << sede << " ---\n"
                  << "Recaudado: S/" << sumarRecaudado(lista, filtroSede) << "\n"
                  << "Pendiente por cobrar: S/" << sumarPendiente(lista, filtroSede) << "\n";
    }

    static void mostrarReportePorMedico(const std::vector<Comprobante>& lista, const std::string& medico) {
        auto filtroMedico = [&](const Comprobante& c) { return c.getMedico() == medico; };
        std::cout << "--- Reporte Medico: " << medico << " ---\n"
                  << "Recaudado: S/" << sumarRecaudado(lista, filtroMedico) << "\n"
                  << "Pendiente por cobrar: S/" << sumarPendiente(lista, filtroMedico) << "\n";
    }
};

#endif