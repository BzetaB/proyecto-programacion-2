//
// Created by thom_ on 18/11/2026.
//

#ifndef PROYECTOCLINICA_MEDICOSEDE_H
#define PROYECTOCLINICA_MEDICOSEDE_H

class Medico;
class Sede;
class Horario;

class MedicoSede {
private:
    int codigo = 0;
    Medico* medico = nullptr;
    Sede* sede = nullptr;
    Horario* horario = nullptr;

public:
    MedicoSede();
    MedicoSede(int codigo, Medico* medico, Sede* sede, Horario* horario);

    ~MedicoSede();

    int get_codigo() const;
    void set_codigo(int codigo);

    Medico* get_medico() const;
    void set_medico(Medico* medico);

    Sede* get_sede() const;
    void set_sede(Sede* sede);

    Horario* get_horario() const;

    void set_horario(Horario* horario);
};


#endif //PROYECTOCLINICA_MEDICOSEDE_H
