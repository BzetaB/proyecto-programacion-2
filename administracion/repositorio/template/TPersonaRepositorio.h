//
// Created by thom_ on 19/11/2026.
//

#ifndef PROYECTOCLINICA_TREPOSITORY_H
#define PROYECTOCLINICA_TREPOSITORY_H
#include <vector>
#include <string>

template <typename T>
class TPersonaRepositorio {
public:
    virtual void agregar(T* elemento) = 0;
    virtual T* buscarPorIdentificador(const std::string& identificador) = 0;
    virtual std::vector<T*> listar() = 0;
    virtual ~TPersonaRepositorio() = default;
};


#endif //PROYECTOCLINICA_TREPOSITORY_H
