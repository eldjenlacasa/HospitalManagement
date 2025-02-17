#include "Medico.hpp"
#include <string>

int Medico::nextId = 0;

std::string Medico::generarId() {
    return "MED" + std::to_string(++nextId);
}

Medico::Medico(const std::string& nombre, const std::string& especialidad)
    : id(generarId()), nombre(nombre), especialidad(especialidad), disponible(true) {
}

std::string Medico::getId() const { return id; }
std::string Medico::getNombre() const { return nombre; }
std::string Medico::getEspecialidad() const { return especialidad; }
bool Medico::isDisponible() const { return disponible; }

void Medico::setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }
void Medico::setEspecialidad(const std::string& nuevaEspecialidad) { especialidad = nuevaEspecialidad; }
void Medico::setDisponibilidad(bool disp) { disponible = disp; }
