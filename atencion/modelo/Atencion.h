#ifndef PROYECTOCLINICA_ATENCION_H
#define PROYECTOCLINICA_ATENCION_H

#include <string>

class Cita;

class Atencion {
private:
    int codigo = 0;
    Cita* cita = nullptr;
    std::string diagnostico;
    std::string tratamiento;
    std::string observaciones;

public:
    Atencion();

    Atencion(
        int codigo,
        Cita* cita,
        std::string diagnostico,
        std::string tratamiento,
        std::string observaciones
    );

    ~Atencion();

    int get_codigo() const;
    void set_codigo(int codigo);

    Cita* get_cita() const;
    void set_cita(Cita* cita);

    std::string get_diagnostico() const;
    void set_diagnostico(std::string diagnostico);

    std::string get_tratamiento() const;
    void set_tratamiento(std::string tratamiento);

    std::string get_observaciones() const;
    void set_observaciones(std::string observaciones);
};

#endif //PROYECTOCLINICA_ATENCION_H