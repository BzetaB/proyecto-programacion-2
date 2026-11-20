#ifndef PROYECTOCLINICA_CITA_H
#define PROYECTOCLINICA_CITA_H

#include <string>

class Horario;
class Sede;
class Consultorio;
class Servicio;
class Medico;
class Paciente;

enum EstadoCita {
    PROGRAMADA,
    CONFIRMADA,
    ATENDIDA,
    CANCELADA,
    INASISTENCIA
};

class Cita {
private:
    std::string codigo;

    Paciente* paciente = nullptr;
    Medico* medico = nullptr;
    Servicio* servicio = nullptr;
    Consultorio* consultorio = nullptr;
    Sede* sede = nullptr;
    Horario* horario = nullptr;

    EstadoCita estado = PROGRAMADA;

public:
    Cita();

    Cita(
        std::string codigo,
        Paciente* paciente,
        Medico* medico,
        Servicio* servicio,
        Consultorio* consultorio,
        Sede* sede,
        Horario* horario,
        EstadoCita estado
    );

    ~Cita();

    std::string get_codigo() const;
    void set_codigo(std::string codigo);

    Paciente* get_paciente() const;
    void set_paciente(Paciente* paciente);

    Medico* get_medico() const;
    void set_medico(Medico* medico);

    Servicio* get_servicio() const;
    void set_servicio(Servicio* servicio);

    Consultorio* get_consultorio() const;
    void set_consultorio(Consultorio* consultorio);

    Sede* get_sede() const;
    void set_sede(Sede* sede);

    Horario* get_horario() const;
    void set_horario(Horario* horario);

    EstadoCita get_estado() const;
    void set_estado(EstadoCita estado);
};

#endif //PROYECTOCLINICA_CITA_H