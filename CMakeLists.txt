cmake_minimum_required(VERSION 4.3)
project(ProyectoClinica)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoClinica main.cpp
        "modelos/base/impl/PersonaBase.cpp"
        modelos/base/PersonaBase.h
        "modelos/paciente/impl/Paciente.cpp"
        modelos/paciente/impl/Persona.cpp
        modelos/paciente/impl/Convenio.cpp
        modelos/paciente/impl/Fecha.cpp
        modelos/paciente/impl/HistoriaClinica.cpp
        modelos/paciente/impl/RegistroAtencion.cpp
        modelos/paciente/impl/RegistroPacientes.cpp
        modelos/paciente/impl/Responsable.cpp
        modelos/paciente/Paciente.h
        "administracion/modelos/impl/Medico.cpp"
        administracion/modelos/Medico.h
        "administracion/modelos/impl/Especialidad.cpp"
        administracion/modelos/Especialidad.h
        "administracion/modelos/impl/Sede.cpp"
        administracion/modelos/Sede.h
        "administracion/modelos/impl/Servicio.cpp"
        administracion/modelos/Servicio.h
        "administracion/modelos/impl/MedicoSede.cpp"
        administracion/modelos/MedicoSede.h
        "administracion/modelos/impl/MedicoEspecialidad.cpp"
        administracion/modelos/MedicoEspecialidad.h
        "administracion/modelos/impl/Horario.cpp"
        administracion/modelos/Horario.h
        administracion/modelos/impl/Consultorio.cpp
        administracion/modelos/Consultorio.h
        modelos/facturacion/ServicioCobro.h
        modelos/facturacion/Pago.h
        modelos/facturacion/CajaClinica.h
        modelos/facturacion/Reportes.h
        modelos/facturacion/Comprobante.h
        modelos/facturacion/impl/ServicioCobro.cpp
        modelos/facturacion/impl/Pago.cpp
        modelos/facturacion/impl/Comprobante.cpp
        modelos/facturacion/impl/CajaClinica.cpp
        modelos/facturacion/impl/Reportes.cpp
        administracion/repositorio/template/TPersonaRepositorio.h
        administracion/repositorio/template/PersonaRepositorio.h
        administracion/servicio/impl/MedicoServicio.cpp
        administracion/servicio/MedicoServicio.h
        administracion/servicio/impl/HabilitacionServicio.cpp
        administracion/servicio/HabilitacionServicio.h
        administracion/repositorio/template/Repositorio.h
        administracion/servicio/impl/HorarioServicio.cpp
        administracion/servicio/HorarioServicio.h
)
