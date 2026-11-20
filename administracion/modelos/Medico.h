//
// Created by thom_ on 16/11/2026.
//

#ifndef PROYECTOCLINICA_MEDICO_H
#define PROYECTOCLINICA_MEDICO_H

#include "../../base/PersonaBase.h"
#include <string>
#include <vector>

class Especialidad;
class MedicoEspecialidad;
class Servicio;

class Medico : public PersonaBase {
private:
    int aniosExperiencia = 0;
    std::string colegiatura;
    bool activo = false;
    std::vector<MedicoEspecialidad*> especialidades;

public:
    Medico();

    Medico(std::string identificador_persona, std::string nombre, std::string apellido, std::string dni,
           int añoNacimiento, std::string correo_electronico, std::string celular, char sexo,
           int anios_experiencia, std::string colegiatura, bool activo);

    int get_anios_experiencia() const;
    void set_anios_experiencia(int anios_experiencia);

    std::string get_colegiatura() const;
    void set_colegiatura(std::string colegiatura);

    bool get_activo() const;
    void set_activo(bool activo);

    std::string obtenerTipo() const override;
};


#endif //PROYECTOCLINICA_MEDICO_H
