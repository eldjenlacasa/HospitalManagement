#ifndef SERVICIO_HPP
#define SERVICIO_HPP

#include <string>

class Servicio {
public:
    Servicio(const std::string& descripcion, double costo);
    ~Servicio() = default;

    std::string getId() const;
    std::string getDescripcion() const;
    double getCosto() const;

private:
    std::string id;
    std::string descripcion;
    double costo;

    static int nextId;
    static std::string generarId();
};

#endif // SERVICIO_HPP
