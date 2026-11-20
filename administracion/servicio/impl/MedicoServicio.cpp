//
// Created by thom_ on 19/11/2026.
//

#include "../MedicoServicio.h"
#include <iostream>

bool MedicoServicio::registrarMedico(Medico* medico) {
    if (medico == nullptr) {
        std::cout << "Debe proporcionar los datos del medico." << std::endl;
        return false;
    }

    if (Medico::existeIdentificadorRegistrado(medico->get_identificador_persona())) {
        std::cout << "Ya existe una persona con ese identificador." << std::endl;
        return false;
    }

    if (!Medico::registrarIdentificador(medico->get_identificador_persona())) {
        std::cout << "El identificador ya pertenece a otra persona." << std::endl;
        return false;
    }

    medicoRepository.agregar(medico);
    return true;
}

Medico* MedicoServicio::buscarMedicoPorIdentificador(const std::string& identificador) {
    return medicoRepository.buscarPorIdentificador(identificador);
}

std::vector<Medico*> MedicoServicio::listarMedicos() {
    return medicoRepository.listar();
}