#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <string>
#include <vector>

class Paciente {
public:
    Paciente(const std::string& nombre, int edad, const std::string& fechaIngreso);
    ~Paciente() = default;

    std::string getId() const;
    std::string getNombre() const;
    int getEdad() const;
    std::string getFechaIngreso() const;
    std::vector<std::string> getHistorialClinico() const;
    std::vector<std::string> getEnfermedadesCronicas() const;

    void setNombre(const std::string& nuevoNombre);
    void setEdad(int nuevaEdad);
    void agregarRegistroClinico(const std::string& registro);
    void agregarEnfermedadCronica(const std::string& enfermedad);

private:
    std::string id;
    std::string nombre;
    int edad;
    std::string fechaIngreso;
    std::vector<std::string> historialClinico;
    std::vector<std::string> enfermedadesCronicas;

    static int nextId;
    static std::string generarId();
};

#endif // PACIENTE_HPP
