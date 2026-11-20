//
// Created by thom_ on 16/11/2026.
//

#ifndef PROYECTOCLINICA_ESPECIALIDAD_H
#define PROYECTOCLINICA_ESPECIALIDAD_H

#include <string>

class Especialidad {
private:
    int codigo = 0;
    std::string nombre;

public:
    Especialidad();

    Especialidad(int codigo, std::string nombre);

    int get_codigo() const;
    void set_codigo(int codigo);

    std::string get_nombre() const;
    void set_nombre(std::string nombre);
};


#endif //PROYECTOCLINICA_ESPECIALIDAD_H
