//
// Created by thom_ on 19/11/2026.
//

#ifndef PROYECTOCLINICA_REPOSITORY_H
#define PROYECTOCLINICA_REPOSITORY_H
#include "TPersonaRepositorio.h"
#include <vector>
#include <string>

template <typename T>
class PersonaRepositorio : public TPersonaRepositorio<T> {
private:
    std::vector<T*> elementos;

public:
    void agregar(T* elemento) override {
        elementos.push_back(elemento);
    }

    std::vector<T*> listar() override {
        return elementos;
    }

    T* buscarPorIdentificador(const std::string& identificador) override {
        for (T* elemento : elementos) {
            if (elemento->get_identificador_persona()== identificador) {
                return elemento;
            }
        }
        return nullptr;
    }
};


#endif //PROYECTOCLINICA_REPOSITORY_H
