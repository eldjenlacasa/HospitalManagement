#include "Paciente.hpp"
#include <string>

int Paciente::nextId = 0;

std::string Paciente::generarId() {
    return "PAT" + std::to_string(++nextId);
}

Paciente::Paciente(const std::string& nombre, int edad, const std::string& fechaIngreso)
    : id(generarId()), nombre(nombre), edad(edad), fechaIngreso(fechaIngreso) {
}

std::string Paciente::getId() const { return id; }
std::string Paciente::getNombre() const { return nombre; }
int Paciente::getEdad() const { return edad; }
std::string Paciente::getFechaIngreso() const { return fechaIngreso; }
std::vector<std::string> Paciente::getHistorialClinico() const { return historialClinico; }
std::vector<std::string> Paciente::getEnfermedadesCronicas() const { return enfermedadesCronicas; }

void Paciente::setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }
void Paciente::setEdad(int nuevaEdad) { edad = nuevaEdad; }
void Paciente::agregarRegistroClinico(const std::string& registro) { historialClinico.push_back(registro); }
void Paciente::agregarEnfermedadCronica(const std::string& enfermedad) { enfermedadesCronicas.push_back(enfermedad); }
