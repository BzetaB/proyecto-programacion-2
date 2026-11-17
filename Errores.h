#pragma once
// Excepciones propias del dominio.
#include <exception>
#include <stdexcept>
#include <string>

// Se lanza cuando una operacion viola una regla de negocio.
class ReglaNegocioError : public std::runtime_error {
public:
    explicit ReglaNegocioError(const std::string& mensaje) : std::runtime_error(mensaje) {}
};

// Se lanza cuando la entrada estandar se cierra (fin de archivo).
class EntradaTerminada : public std::exception {
public:
    const char* what() const noexcept override { return "Entrada terminada"; }
};
