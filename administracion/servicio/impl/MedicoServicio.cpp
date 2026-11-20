//
// Created by thom_ on 19/11/2026.
//

#include "../MedicoServicio.h"

void MedicoServicio::registrarMedico(Medico* medico) {
    medicoRepository.agregar(medico);
}

Medico* MedicoServicio::buscarMedicoPorIdentificador(const std::string& identificador) {
    return medicoRepository.buscarPorIdentificador(identificador);
}

std::vector<Medico*> MedicoServicio::listarMedicos() {
    return medicoRepository.listar();
}