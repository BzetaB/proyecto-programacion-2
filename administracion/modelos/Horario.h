//
// Created by thom_ on 18/11/2026.
//

#ifndef PROYECTOCLINICA_HORARIO_H
#define PROYECTOCLINICA_HORARIO_H

#include <string>

class Horario {
private:
    int codigo = 0;
    std::string diaSemana;
    std::string horaInicio;
    std::string horaFin;
    std::string fecha;

public:
    Horario();

    Horario(int codigo, std::string dia_semana, std::string hora_inicio, std::string hora_fin, std::string fecha);

    int get_codigo() const;
    void set_codigo(int codigo);

    std::string get_dia_semana() const;
    void set_dia_semana(std::string dia_semana);

    std::string get_hora_inicio() const;
    void set_hora_inicio(std::string hora_inicio);

    std::string get_hora_fin() const;
    void set_hora_fin(std::string hora_fin);

    std::string get_fecha() const;
    void set_fecha(std::string fecha);

    bool seSuperpone(Horario* otro);

    bool contiene(Horario* otro);
};


#endif //PROYECTOCLINICA_HORARIO_H
