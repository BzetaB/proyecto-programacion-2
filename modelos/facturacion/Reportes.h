#ifndef REPORTES_H
#define REPORTES_H

#include <string>
#include <vector>
#include "Comprobante.h"

class Reportes {
public:
    // Cálculos por sede
    static double recaudadoPorSede(const std::vector<Comprobante>& lista, const std::string& sede);
    static double pendientePorSede(const std::vector<Comprobante>& lista, const std::string& sede);
    static void mostrarReportePorSede(const std::vector<Comprobante>& lista, const std::string& sede);

    // Cálculos por médico
    static double recaudadoPorMedico(const std::vector<Comprobante>& lista, const std::string& medico);
    static double pendientePorMedico(const std::vector<Comprobante>& lista, const std::string& medico);
    static void mostrarReportePorMedico(const std::vector<Comprobante>& lista, const std::string& medico);
};

#endif