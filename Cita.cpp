#include "Cita.hpp"
#include <string>

int Cita::nextId = 0;

std::string Cita::generarId() {
    return "CIT" + std::to_string(++nextId);
}

Cita::Cita(const std::string& pacienteId, const std::string& medicoId, const std::string& fecha, int urgencia)
    : id(generarId()), pacienteId(pacienteId), medicoId(medicoId), fecha(fecha), urgencia(urgencia) {
}

std::string Cita::getId() const { return id; }
std::string Cita::getPacienteId() const { return pacienteId; }
std::string Cita::getMedicoId() const { return medicoId; }
std::string Cita::getFecha() const { return fecha; }
int Cita::getUrgencia() const { return urgencia; }

void Cita::setFecha(const std::string& nuevaFecha) { fecha = nuevaFecha; }
void Cita::setUrgencia(int nuevaUrgencia) { urgencia = nuevaUrgencia; }
