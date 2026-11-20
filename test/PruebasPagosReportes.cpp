#include "PruebasPagosReportes.h"

#include <cmath>
#include <iostream>
#include <vector>

#include "../facturacion/CajaClinica.h"
#include "../facturacion/Comprobante.h"
#include "../facturacion/Pago.h"
#include "../facturacion/Reportes.h"
#include "../facturacion/ServicioCobro.h"

namespace {
int pruebasPasadas = 0;
int pruebasFalladas = 0;

void informar(const char* escenario, bool resultado) {
    std::cout << (resultado ? "[PASO] " : "[FALLO] ") << escenario << '\n';
    if (resultado) ++pruebasPasadas;
    else ++pruebasFalladas;
}

bool casiIgual(double a, double b) {
    return std::fabs(a - b) < 0.001;
}

bool probarServicioCobroYPago() {
    ServicioCobro consulta("Consulta general", 120.0);
    Pago pago(40.0, "Yape", "2026-11-20");

    return casiIgual(consulta.precio, 120.0) &&
           consulta.descripcion == "Consulta general" &&
           casiIgual(pago.monto, 40.0) &&
           pago.metodo == "Yape" &&
           pago.fecha == "2026-11-20";
}

bool probarCalculoComprobante() {
    Comprobante comprobante(10, 100, "12345678", "Dra. Perez", "Central", 0.20);
    comprobante += ServicioCobro("Consulta", 100.0);
    comprobante += ServicioCobro("Laboratorio", 50.0);

    bool subtotal = casiIgual(comprobante.getSubtotal(), 150.0);
    bool descuento = casiIgual(comprobante.getTotalNeto(), 120.0);
    bool pendienteInicial = comprobante.getEstado() == "Pendiente" &&
                            casiIgual(comprobante.getSaldoPendiente(), 120.0);

    comprobante += Pago(50.0, "Efectivo", "2026-11-20");
    bool pagoParcial = comprobante.getEstado() == "Pago Parcial" &&
                       casiIgual(comprobante.getTotalPagado(), 50.0) &&
                       casiIgual(comprobante.getSaldoPendiente(), 70.0);

    comprobante += Pago(70.0, "Tarjeta", "2026-11-20");
    bool pagoTotal = comprobante.getEstado() == "Pagado Total" &&
                     casiIgual(comprobante.getSaldoPendiente(), 0.0);

    return subtotal && descuento && pendienteInicial && pagoParcial && pagoTotal;
}

bool probarCajaClinica() {
    CajaClinica caja;
    Comprobante primero(20, 200, "87654321", "Dr. Ruiz", "Norte", 0.0);
    primero += ServicioCobro("Consulta", 80.0);

    bool registrado = caja.registrarComprobante(primero);
    bool duplicadoRechazado = !caja.registrarComprobante(
        Comprobante(21, 200, "87654321", "Dr. Ruiz", "Norte", 0.0));
    bool pagoAceptado = caja.registrarPago(20, Pago(30.0, "Yape", "2026-11-20"));
    bool excesoRechazado = !caja.registrarPago(
        20, Pago(100.0, "Tarjeta", "2026-11-20"));
    bool comprobanteInexistente = !caja.registrarPago(
        999, Pago(10.0, "Efectivo", "2026-11-20"));

    const std::vector<Comprobante>& comprobantes = caja.getComprobantes();
    bool estadoCaja = comprobantes.size() == 1 &&
                      casiIgual(comprobantes[0].getTotalPagado(), 30.0);

    return registrado && duplicadoRechazado && pagoAceptado &&
           excesoRechazado && comprobanteInexistente && estadoCaja;
}

bool probarReportesPorSedeYMedico() {
    std::vector<Comprobante> comprobantes;

    Comprobante norte(30, 300, "11111111", "Dra. Lopez", "Norte", 0.0);
    norte += ServicioCobro("Consulta", 100.0);
    norte += Pago(60.0, "Yape", "2026-11-20");
    comprobantes.push_back(norte);

    Comprobante sur(31, 301, "22222222", "Dr. Vega", "Sur", 0.1);
    sur += ServicioCobro("Especialidad", 200.0);
    sur += Pago(90.0, "Tarjeta", "2026-11-20");
    comprobantes.push_back(sur);

    bool sedeNorte =
        casiIgual(Reportes::recaudadoPorSede(comprobantes, "Norte"), 60.0) &&
        casiIgual(Reportes::pendientePorSede(comprobantes, "Norte"), 40.0);
    bool sedeSur =
        casiIgual(Reportes::recaudadoPorSede(comprobantes, "Sur"), 90.0) &&
        casiIgual(Reportes::pendientePorSede(comprobantes, "Sur"), 90.0);
    bool medicos =
        casiIgual(Reportes::recaudadoPorMedico(comprobantes, "Dra. Lopez"), 60.0) &&
        casiIgual(Reportes::pendientePorMedico(comprobantes, "Dra. Lopez"), 40.0) &&
        casiIgual(Reportes::recaudadoPorMedico(comprobantes, "Dr. Vega"), 90.0) &&
        casiIgual(Reportes::pendientePorMedico(comprobantes, "Dr. Vega"), 90.0);

    return sedeNorte && sedeSur && medicos;
}

bool probarValidacionesPagoComprobante() {
    Comprobante comprobante(40, 400, "33333333", "Dra. Campos", "Central", 0.0);
    comprobante += ServicioCobro("Consulta", 50.0);

    comprobante += Pago(-10.0, "Efectivo", "2026-11-20");
    bool pagoNegativoRechazado = casiIgual(comprobante.getTotalPagado(), 0.0);

    comprobante += Pago(60.0, "Tarjeta", "2026-11-20");
    bool pagoExcesivoRechazado = casiIgual(comprobante.getTotalPagado(), 0.0);

    comprobante += ServicioCobro("Descartar", -20.0);
    bool servicioInvalidoIgnorado = casiIgual(comprobante.getSubtotal(), 50.0);

    return pagoNegativoRechazado && pagoExcesivoRechazado && servicioInvalidoIgnorado;
}
}

void probarPagosReportes() {
    pruebasPasadas = 0;
    pruebasFalladas = 0;

    std::cout << "\n==============================\n";
    std::cout << "  PRUEBAS PAGOS Y REPORTES\n";
    std::cout << "==============================\n";
    informar("1. Creacion de servicios de cobro y pagos", probarServicioCobroYPago());
    informar("2. Subtotal, descuento, saldo y estados del comprobante", probarCalculoComprobante());
    informar("3. Registro de comprobantes y pagos en caja", probarCajaClinica());
    informar("4. Reportes de recaudacion y pendientes por sede y medico", probarReportesPorSedeYMedico());
    informar("5. Validacion de montos y servicios invalidos", probarValidacionesPagoComprobante());

    std::cout << "\nResultado: " << pruebasPasadas << " pasaron, "
              << pruebasFalladas << " fallaron.\n";
}
