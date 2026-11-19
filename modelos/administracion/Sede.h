//
// Created by thom_ on 16/11/2026.
//

#ifndef PROYECTOCLINICA_SEDE_H
#define PROYECTOCLINICA_SEDE_H

#include <string>
#include <vector>

class Consultorio;

class Sede {
private:
    int codigo = 0;
    std::string nombre;
    std::string direccion;
    bool activo = false;
    std::vector<Consultorio*> consultorios;

public:
    Sede();

    Sede(int codigo, std::string nombre, std::string direccion, bool activo);

    int get_codigo() const;
    void set_codigo(int codigo);

    std::string get_nombre() const;
    void set_nombre(std::string nombre);

    std::string get_direccion() const;
    void set_direccion(std::string direccion);

    bool get_activo() const;
    void set_activo(bool activo);

    const std::vector<Consultorio*>& get_consultorios() const;
    void agregar_consultorio(Consultorio* consultorio);
    void quitar_consultorio(Consultorio* consultorio);
};


#endif //PROYECTOCLINICA_SEDE_H
