//
// Created by thom_ on 16/11/2026.
//

#ifndef PROYECTOCLINICA_SERVICIOS_H
#define PROYECTOCLINICA_SERVICIOS_H

#include <string>

class Servicio {
private:
    int codigo = 0;
    std::string nombre;
    std::string descripcion;
    int duracionMinutos = 0;
    double tarifaBase = 0.0;
    bool activo = false;

public:
    Servicio();

    Servicio(int codigo, std::string nombre, std::string descripcion, int duracion_minutos, double tarifa_base,
             bool activo);

    int get_codigo() const;
    void set_codigo(int codigo);

    std::string get_nombre() const;
    void set_nombre(std::string nombre);

    std::string get_descripcion() const;
    void set_descripcion(std::string descripcion);

    int get_duracion_minutos() const;
    void set_duracion_minutos(int duracion_minutos);

    double get_tarifa_base() const;
    void set_tarifa_base(double tarifa_base);

    bool get_activo() const;
    void set_activo(bool activo);
};


#endif //PROYECTOCLINICA_SERVICIOS_H
