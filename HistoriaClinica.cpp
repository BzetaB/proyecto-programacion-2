#include "HistoriaClinica.h"
#include "Errores.h"
#include <sstream>

void HistoriaClinica::agregarAntecedente(const std::string& a) {
    if (a.empty()) throw ReglaNegocioError("El antecedente no puede estar vacio.");
    antecedentes_.push_back(a);
}

bool HistoriaClinica::tieneAtencionDeCita(const std::string& codigoCita) const {
    for (const auto& a : atenciones_) if (a.codigoCita() == codigoCita) return true;
    return false;
}

void HistoriaClinica::registrarAtencion(const RegistroAtencion& atencion) {
    if (atencion.diagnostico().empty())
        throw ReglaNegocioError("Toda atencion clinica requiere un diagnostico.");
    if (tieneAtencionDeCita(atencion.codigoCita()))
        throw ReglaNegocioError("La cita " + atencion.codigoCita() + " ya genero una atencion clinica.");
    atenciones_.push_back(atencion);
}

int HistoriaClinica::atencionesEnSede(const std::string& codigoSede) const {
    int n = 0;
    for (const auto& a : atenciones_) if (a.codigoSede() == codigoSede) ++n;
    return n;
}

std::string HistoriaClinica::aTexto() const {
    std::ostringstream os;
    os << "Historia clinica No. " << numero_ << "\n  Antecedentes:";
    if (antecedentes_.empty()) os << " (ninguno registrado)";
    os << "\n";
    for (const auto& a : antecedentes_) os << "   - " << a << "\n";
    os << "  Atenciones (" << atenciones_.size() << "):";
    if (atenciones_.empty()) os << " (ninguna)";
    os << "\n";
    for (const auto& a : atenciones_) {
        os << "   * " << a.fecha() << " | " << a.nombreSede() << " | " << a.servicio()
           << " | Dr(a). " << a.nombreMedico() << " [cita " << a.codigoCita() << "]\n"
           << "       Diagnostico: " << a.diagnostico() << "\n"
           << "       Indicaciones: " << (a.indicaciones().empty() ? "(sin indicaciones)" : a.indicaciones())
           << "\n";
    }
    return os.str();
}
