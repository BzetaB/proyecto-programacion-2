#include "RegistroPacientes.h"
#include "Errores.h"
#include <cstdio>

Paciente* RegistroPacientes::buscarPorDni(const std::string& dni) const {
    return pacientes_.buscar([&](const Paciente& p) { return p.dni() == dni; });
}

Paciente* RegistroPacientes::buscarPorCodigo(const std::string& codigo) const {
    return pacientes_.buscar([&](const Paciente& p) { return p.codigo() == codigo; });
}

Paciente* RegistroPacientes::registrar(const std::string& dni, const std::string& nombres,
                                       const std::string& apellidos, const Fecha& nacimiento,
                                       const std::string& telefono, const std::string& sedeRegistro,
                                       std::unique_ptr<Responsable> responsable) {
    if (Paciente* existente = buscarPorDni(dni))
        throw ReglaNegocioError("El DNI " + dni + " ya esta registrado como " + existente->codigo() +
                                " (" + existente->nombreCompleto() + "). La identidad es unica en la red: "
                                "use ese registro en cualquier sede.");
    Paciente* homonimo = pacientes_.buscar([&](const Paciente& p) {
        return p.nombres() == nombres && p.apellidos() == apellidos && p.fechaNacimiento() == nacimiento;
    });
    if (homonimo)
        throw ReglaNegocioError("Posible duplicado: ya existe " + homonimo->codigo() +
                                " con los mismos nombres y fecha de nacimiento.");

    char codigo[16];
    std::snprintf(codigo, sizeof codigo, "PAC-%04d", contador_ + 1);
    auto nuevo = std::make_unique<Paciente>(codigo, dni, nombres, apellidos, nacimiento, telefono,
                                            sedeRegistro);
    if (nuevo->esMenor(Fecha::hoy())) {
        if (!responsable)
            throw ReglaNegocioError("El paciente es menor de edad: debe registrarse un responsable.");
    }
    if (responsable) nuevo->asignarResponsable(std::move(responsable));
    ++contador_;
    return pacientes_.agregar(std::move(nuevo));
}
