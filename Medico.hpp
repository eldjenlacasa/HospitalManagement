#ifndef MEDICO_HPP
#define MEDICO_HPP

#include <string>

class Medico {
public:
    Medico(const std::string& nombre, const std::string& especialidad);
    ~Medico() = default;

    std::string getId() const;
    std::string getNombre() const;
    std::string getEspecialidad() const;
    bool isDisponible() const;

    void setNombre(const std::string& nuevoNombre);
    void setEspecialidad(const std::string& nuevaEspecialidad);
    void setDisponibilidad(bool disponible);

private:
    std::string id;
    std::string nombre;
    std::string especialidad;
    bool disponible;

    static int nextId;
    static std::string generarId();
};

#endif // MEDICO_HPP
