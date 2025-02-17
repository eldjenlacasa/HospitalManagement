cmake_minimum_required(VERSION 3.10)
project(HospitalManagement)

set(CMAKE_CXX_STANDARD 11)

add_executable(HospitalManagement
    main.cpp
    Hospital.cpp
    Paciente.cpp
    Medico.cpp
    Cita.cpp
    Servicio.cpp
)
