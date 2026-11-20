//
// Created by thom_ on 19/11/2026.
//

#ifndef PROYECTOCLINICA_MEDICOSERVICIO_H
#define PROYECTOCLINICA_MEDICOSERVICIO_H
#include "../modelos/Medico.h"
#include "../../repositorio/template/PersonaRepositorio.h"


class MedicoServicio {
private:
    PersonaRepositorio<Medico> medicoRepository;
public:
    bool registrarMedico(Medico* medico);

    Medico* buscarMedicoPorIdentificador(const std::string& identificador);

    std::vector<Medico*> listarMedicos();
};


#endif //PROYECTOCLINICA_MEDICOSERVICIO_H
