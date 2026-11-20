//
// Created by thom_ on 20/11/2026.
//

#include "../ConsultorioServicio.h"
#include <string>

#include "../../modelos/Consultorio.h"
#include "../../modelos/Servicio.h"

bool ConsultorioServicio::existeConsultorioCompatible(Servicio *servicio) {
    return obtenerConsultorioCompatible(servicio) != nullptr;
}

Consultorio* ConsultorioServicio::obtenerConsultorioCompatible(Servicio* servicio) {

    for (Consultorio* consultorio : consultorioRepository.listar()) {
        bool compatible = true;

        for (const std::string& requerido : servicio->get_equipamentos_requeridos()) {
            if (!consultorio->tieneEquipamiento(requerido)) {
                compatible = false;
                break;
            }
        }

        if (compatible) {
            return consultorio;
        }
    }

    return nullptr;
}

void ConsultorioServicio::registrarConsultorio(Consultorio* consultorio) {
    consultorioRepository.agregar(consultorio);
}