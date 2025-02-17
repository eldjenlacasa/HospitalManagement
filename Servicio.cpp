#include "Servicio.hpp"
#include <string>

int Servicio::nextId = 0;

std::string Servicio::generarId() {
    return "SER" + std::to_string(++nextId);
}

Servicio::Servicio(const std::string& descripcion, double costo)
    : id(generarId()), descripcion(descripcion), costo(costo) {
}

std::string Servicio::getId() const { return id; }
std::string Servicio::getDescripcion() const { return descripcion; }
double Servicio::getCosto() const { return costo; }
