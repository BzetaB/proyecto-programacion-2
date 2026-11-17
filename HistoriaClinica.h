#pragma once
// Historia clinica unica y compartida entre sedes. Es COMPUESTA por el Paciente.
#include "RegistroAtencion.h"
#include <string>
#include <vector>

class HistoriaClinica {
    std::string numero_;
    std::vector<std::string> antecedentes_;
    std::vector<RegistroAtencion> atenciones_;   // composicion: no existen sin la historia
public:
    explicit HistoriaClinica(const std::string& numero) : numero_(numero) {}
    const std::string& numero() const { return numero_; }

    void agregarAntecedente(const std::string& antecedente);
    // Rechaza diagnosticos vacios y atenciones duplicadas de una misma cita.
    void registrarAtencion(const RegistroAtencion& atencion);
    bool tieneAtencionDeCita(const std::string& codigoCita) const;

    const std::vector<std::string>& antecedentes() const { return antecedentes_; }
    const std::vector<RegistroAtencion>& atenciones() const { return atenciones_; }
    int totalAtenciones() const { return static_cast<int>(atenciones_.size()); }
    int atencionesEnSede(const std::string& codigoSede) const;
    std::string aTexto() const;
};
