#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP

#include <string>
#include <vector>
#include "Paciente.hpp"
#include "Medico.hpp"
#include "Cita.hpp"
#include "Servicio.hpp"

class Hospital {
public:
    Hospital();
    ~Hospital();

    // Gesti�n de pacientes
    void agregarPaciente(Paciente* p);
    void eliminarPaciente(const std::string& id);
    bool existePaciente(const std::string& id) const;
    void listarPacientes() const;
    void buscarPaciente(const std::string& criterio, const std::string& valor) const;
    void modificarPaciente(const std::string& id, const std::string& nuevoNombre, int nuevaEdad);

    // Funciones para agregar informaci�n cl�nica a pacientes
    void agregarRegistroClinicoPaciente(const std::string& id, const std::string& registro);
    void agregarEnfermedadCronicaPaciente(const std::string& id, const std::string& enfermedad);

    // Gesti�n de m�dicos
    void agregarMedico(Medico* m);
    void eliminarMedico(const std::string& id);
    bool existeMedico(const std::string& id) const;
    void listarMedicos() const;

    // Gesti�n de citas
    void agregarCita(Cita* c);
    void modificarCita(const std::string& id, const std::string& nuevaFecha, int nuevaUrgencia);
    void listarCitas() const;
    void cancelarCita(const std::string& id);
    void ordenarCitasPorUrgencia();
    void ordenarCitasPorFecha();

    // Gesti�n de servicios
    void agregarServicio(Servicio* s);
    void listarServicios() const;

    // Generaci�n de reportes
    void reportePacientesPorFecha(const std::string& fechaInicio, const std::string& fechaFin) const;
    void reporteCitasPendientesPorMedico(const std::string& idMedico) const;
    void reporteCitasPendientesPorEspecialidad(const std::string& especialidad) const;
    void reportePacientesConEnfermedadesCronicas() const;

    // Manejo de archivos y backup
    void guardarDatos() const;
    void backupDatabase() const;

private:
    std::vector<Paciente*> pacientes;
    std::vector<Medico*> medicos;
    std::vector<Cita*> citas;
    std::vector<Servicio*> servicios;

    // Funci�n auxiliar: convierte fecha "DD/MM/AAAA" a entero YYYYMMDD
    static int convertirFecha(const std::string& fecha);
};

#endif // HOSPITAL_HPP
