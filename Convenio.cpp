#include "Convenio.h"
#include <stdexcept>

Convenio::Convenio(const std::string& codigo, const std::string& empresa, double descuentoPct)
    : codigo_(codigo), empresa_(empresa), descuentoPct_(descuentoPct) {
    if (codigo.empty() || empresa.empty()) throw std::invalid_argument("Codigo y empresa son obligatorios");
    if (descuentoPct <= 0 || descuentoPct > 100) throw std::invalid_argument("El descuento debe estar en (0, 100]");
}
