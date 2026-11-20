#ifndef CONVENIO_H
#define CONVENIO_H

#include <string>

class Convenio {
private:
    std::string codigo;
    std::string empresa;
    int descuentoPorcentaje = 0;
    bool activo = true;

public:
    Convenio();

    Convenio(
        std::string codigo,
        std::string empresa,
        int descuentoPorcentaje,
        bool activo
    );

    ~Convenio();

    std::string get_codigo() const;
    void set_codigo(std::string codigo);

    std::string get_empresa() const;
    void set_empresa(std::string empresa);

    int get_descuento_porcentaje() const;
    void set_descuento_porcentaje(int descuentoPorcentaje);

    bool is_activo() const;
    void set_activo(bool activo);
};

#endif