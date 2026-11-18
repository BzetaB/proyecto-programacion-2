cmake_minimum_required(VERSION 4.3)
project(ProyectoClinica)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoClinica main.cpp
        "modelos/base/impl/PersonaBase.cpp"
        modelos/base/PersonaBase.h
        "modelos/paciente/impl/Paciente.cpp"
        modelos/paciente/Paciente.h
        "modelos/administracion/impl/Medico.cpp"
        modelos/administracion/Medico.h
        "modelos/administracion/impl/Especialidad.cpp"
        modelos/administracion/Especialidad.h
        "modelos/administracion/impl/Sede.cpp"
        modelos/administracion/Sede.h
        "modelos/administracion/impl/Servicio.cpp"
        modelos/administracion/Servicio.h
        "modelos/administracion/impl/MedicoSede.cpp"
        modelos/administracion/MedicoSede.h
        "modelos/administracion/impl/MedicoEspecialidad.cpp"
        modelos/administracion/MedicoEspecialidad.h
        "modelos/administracion/impl/MedicoHorario.cpp"
        modelos/administracion/MedicoHorario.h
        "modelos/administracion/impl/Horario.cpp"
        modelos/administracion/Horario.h
)
