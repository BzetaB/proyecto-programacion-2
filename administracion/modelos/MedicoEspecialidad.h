//
// Created by thom_ on 18/11/2026.
//

#ifndef PROYECTOCLINICA_MEDICOESPECIALIDAD_H
#define PROYECTOCLINICA_MEDICOESPECIALIDAD_H

class Medico;
class Especialidad;

class MedicoEspecialidad {
private:
    int codigo = 0;
    Medico* medico = nullptr;
    Especialidad* especialidad = nullptr;

public:
    MedicoEspecialidad();
    MedicoEspecialidad(int codigo, Medico* medico, Especialidad* especialidad);
    ~MedicoEspecialidad();

    int get_codigo() const;
    void set_codigo(int codigo);

    Medico* get_medico() const;
    void set_medico(Medico* medico);

    Especialidad* get_especialidad() const;
    void set_especialidad(Especialidad* especialidad);
};


#endif //PROYECTOCLINICA_MEDICOESPECIALIDAD_H
