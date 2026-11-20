//
// Created by thom_ on 19/11/2026.
//

#ifndef PROYECTOCLINICA_REPOSITORIO_H
#define PROYECTOCLINICA_REPOSITORIO_H

#include <vector>

template <typename T>
class Repositorio {
private:
    std::vector<T*> elementos;

public:
    void agregar(T* elemento){
        elementos.push_back(elemento);
    }

    std::vector<T*> listar() {
        return elementos;
    }
};


#endif //PROYECTOCLINICA_REPOSITORIO_H
