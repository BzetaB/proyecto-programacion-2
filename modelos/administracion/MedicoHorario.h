//
// Created by thom_ on 18/11/2026.
//

#ifndef PROYECTOCLINICA_MEDICOHORARIO_H
#define PROYECTOCLINICA_MEDICOHORARIO_H

class Medico;
class Horario;

class MedicoHorario {
private:
    int codigo = 0;
    Medico* medico = nullptr;
    Horario* horario = nullptr;

public:
    MedicoHorario();
    MedicoHorario(int codigo, Medico* medico, Horario* horario);
    ~MedicoHorario();

    int get_codigo() const;
    void set_codigo(int codigo);

    Medico* get_medico() const;
    void set_medico(Medico* medico);

    Horario* get_horario() const;
    void set_horario(Horario* horario);
};


#endif //PROYECTOCLINICA_MEDICOHORARIO_H
