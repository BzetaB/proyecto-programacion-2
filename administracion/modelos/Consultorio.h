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
    ~Consultorio();

    Consultorio();

    Consultorio(int codigo, std::string nombre, std::vector<std::string> equipamentos, Sede *sede);

    int codigo1() const;

    void set_codigo(int codigo);

    std::string nombre1() const;

    void set_nombre(std::string nombre);

    std::vector<std::string> get_equipamentos() const;

    void set_equipamentos(std::vector<std::string> equipamentos);

    Sede * get_sede() const;

    void set_sede(Sede *sede);

    bool tieneEquipamiento(const std::string& equipo);
};


#endif //PROYECTOCLINICA_CONSULTORIO_H
