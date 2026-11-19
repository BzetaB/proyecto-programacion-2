//
// Created by thom_ on 19/11/2026.
//

#ifndef PROYECTOCLINICA_CONSULTORIO_H
#define PROYECTOCLINICA_CONSULTORIO_H

#include <string>
#include <vector>

class Sede;

class Consultorio {
private:
    int codigo = 0;
    std::string nombre;
    std::vector<std::string> equipamentos;
    Sede* sede = nullptr;

public:
    Consultorio();
    Consultorio(int codigo, std::string nombre,
                std::vector<std::string> equipamentos, Sede* sede);
    ~Consultorio();

    int get_codigo() const;
    void set_codigo(int codigo);

    const std::string& get_nombre() const;
    void set_nombre(std::string nombre);

    const std::vector<std::string>& get_equipamentos() const;
    void set_equipamentos(std::vector<std::string> equipamentos);

    Sede* get_sede() const;
    void set_sede(Sede* sede);
};


#endif //PROYECTOCLINICA_CONSULTORIO_H
