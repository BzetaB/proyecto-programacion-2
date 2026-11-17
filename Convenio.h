#pragma once
// Convenio corporativo: descuento porcentual sobre servicios (no sobre materiales).
#include <string>

class Convenio {
    std::string codigo_, empresa_;
    double descuentoPct_;
public:
    Convenio(const std::string& codigo, const std::string& empresa, double descuentoPct);
    const std::string& codigo() const { return codigo_; }
    const std::string& empresa() const { return empresa_; }
    double descuentoPct() const { return descuentoPct_; }
};
