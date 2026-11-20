//
// Created by thom_ on 16/11/2026.
//

#ifndef PROYECTOCLINICA_SEDE_H
#define PROYECTOCLINICA_SEDE_H

#include <string>
#include <vector>

class Consultorio;
class Horario;

class Sede {
private:
    int codigo = 0;
    std::string nombre;
    std::string direccion;
    bool activo = false;
    std::vector<Horario*> horarios;

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

    std::vector<Horario*> get_horarios() const;

    void agregarHorario(Horario* horario);

    bool estaDisponible(Horario* horario) const;

};


#endif //PROYECTOCLINICA_SEDE_H
