//
// Created by thom_ on 20/11/2026.
//

#ifndef PROYECTOCLINICA_HISTORIACLINICA_H
#define PROYECTOCLINICA_HISTORIACLINICA_H
#include <vector>
#include <string>

#include "../../atencion/modelo/Atencion.h"
class Paciente;

class HistoriaClinica {
private:
    std::string codigo;
    Paciente* paciente = nullptr;
    std::vector<std::string> antecedentes;
    std::vector<Atencion* > atenciones;
public:
    HistoriaClinica();

    HistoriaClinica(
        std::string codigo,
        Paciente* paciente
    );

    ~HistoriaClinica();

    std::string get_codigo() const;
    void set_codigo(std::string codigo);

    Paciente* get_paciente() const;
    void set_paciente(Paciente* paciente);

    std::vector<std::string> get_antecedentes() const;
    void set_antecedentes(std::vector<std::string> antecedentes);

    std::vector<Atencion*> get_atenciones() const;
    void set_atenciones(std::vector<Atencion*> atenciones);

    void agregarAntecedente(std::string antecedente);

    void agregarAtencion(Atencion* atencion);
};


#endif //PROYECTOCLINICA_HISTORIACLINICA_H
