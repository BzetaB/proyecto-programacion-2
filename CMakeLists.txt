cmake_minimum_required(VERSION 4.3)
project(ProyectoClinica)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoClinica main.cpp
        "modelos/ impl/PersonaBase.cpp"
        modelos/PersonaBase.h
        "modelos/ impl/Paciente.cpp"
        modelos/Paciente.h)
