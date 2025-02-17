#ifndef CITA_HPP
#define CITA_HPP

#include <string>

class Cita {
public:
    Cita(const std::string& pacienteId, const std::string& medicoId, const std::string& fecha, int urgencia);
    ~Cita() = default;

    std::string getId() const;
    std::string getPacienteId() const;
    std::string getMedicoId() const;
    std::string getFecha() const;
    int getUrgencia() const;

    // Permite modificar la cita
    void setFecha(const std::string& nuevaFecha);
    void setUrgencia(int nuevaUrgencia);

private:
    std::string id;
    std::string pacienteId;
    std::string medicoId;
    std::string fecha; // Formato DD/MM/AAAA
    int urgencia;      // Prioridad (1 a 5)

    static int nextId;
    static std::string generarId();
};

#endif // CITA_HPP
