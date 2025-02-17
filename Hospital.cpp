#include "Hospital.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <sstream>
#include <cstdio>

// Constructor
Hospital::Hospital() {}

// Destructor: liberar memoria dinámica
Hospital::~Hospital() {
    for(auto p : pacientes) delete p;
    for(auto m : medicos)   delete m;
    for(auto c : citas)     delete c;
    for(auto s : servicios) delete s;
}

// Función auxiliar para convertir fecha "DD/MM/AAAA" a entero YYYYMMDD
int Hospital::convertirFecha(const std::string &fecha) {
    int d, m, a;
    sscanf(fecha.c_str(), "%d/%d/%d", &d, &m, &a);
    return a * 10000 + m * 100 + d;
}

// --- Gestión de Pacientes ---
void Hospital::agregarPaciente(Paciente* p) {
    pacientes.push_back(p);
}

void Hospital::eliminarPaciente(const std::string &id) {
    auto it = std::remove_if(pacientes.begin(), pacientes.end(),
        [&id](Paciente* p){ return p->getId() == id; });
    if(it != pacientes.end()){
        for(auto itr = it; itr != pacientes.end(); ++itr)
            delete *itr;
        pacientes.erase(it, pacientes.end());
        std::cout << "Paciente eliminado.\n";
    } else {
        std::cout << "Paciente no encontrado.\n";
    }
}

bool Hospital::existePaciente(const std::string &id) const {
    return std::any_of(pacientes.begin(), pacientes.end(),
                       [&id](Paciente* p){ return p->getId() == id; });
}

void Hospital::listarPacientes() const {
    std::cout << "\n-- Lista de Pacientes --\n";
    for(auto p : pacientes)
        std::cout << "ID: " << p->getId() << ", Nombre: " << p->getNombre()
                  << ", Edad: " << p->getEdad() << ", Fecha Ingreso: " << p->getFechaIngreso() << "\n";
}

void Hospital::buscarPaciente(const std::string &criterio, const std::string &valor) const {
    std::cout << "\n-- Resultado de Búsqueda de Paciente --\n";
    for(auto p : pacientes) {
        if((criterio == "1" && p->getId() == valor) ||
           (criterio == "2" && p->getNombre() == valor) ||
           (criterio == "3" && p->getFechaIngreso() == valor))
            std::cout << "Encontrado: " << p->getId() << " - " << p->getNombre() << "\n";
    }
}

void Hospital::modificarPaciente(const std::string &id, const std::string &nuevoNombre, int nuevaEdad) {
    for(auto p : pacientes) {
        if(p->getId() == id) {
            p->setNombre(nuevoNombre);
            p->setEdad(nuevaEdad);
            std::cout << "Paciente modificado.\n";
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

void Hospital::agregarRegistroClinicoPaciente(const std::string &id, const std::string &registro) {
    for(auto p : pacientes) {
        if(p->getId() == id) {
            p->agregarRegistroClinico(registro);
            std::cout << "Registro clínico agregado.\n";
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

void Hospital::agregarEnfermedadCronicaPaciente(const std::string &id, const std::string &enfermedad) {
    for(auto p : pacientes) {
        if(p->getId() == id) {
            p->agregarEnfermedadCronica(enfermedad);
            std::cout << "Enfermedad crónica agregada.\n";
            return;
        }
    }
    std::cout << "Paciente no encontrado.\n";
}

// --- Gestión de Médicos ---
void Hospital::agregarMedico(Medico* m) {
    medicos.push_back(m);
}

void Hospital::eliminarMedico(const std::string &id) {
    auto it = std::remove_if(medicos.begin(), medicos.end(),
        [&id](Medico* m){ return m->getId() == id; });
    if(it != medicos.end()){
        for(auto itr = it; itr != medicos.end(); ++itr)
            delete *itr;
        medicos.erase(it, medicos.end());
        std::cout << "Médico eliminado.\n";
    } else {
        std::cout << "Médico no encontrado.\n";
    }
}

bool Hospital::existeMedico(const std::string &id) const {
    return std::any_of(medicos.begin(), medicos.end(),
                       [&id](Medico* m){ return m->getId() == id; });
}

void Hospital::listarMedicos() const {
    std::cout << "\n-- Lista de Médicos --\n";
    for(auto m : medicos)
        std::cout << "ID: " << m->getId() << ", Nombre: " << m->getNombre()
                  << ", Especialidad: " << m->getEspecialidad()
                  << ", Disponible: " << (m->isDisponible() ? "Sí" : "No") << "\n";
}

// --- Gestión de Citas ---
void Hospital::agregarCita(Cita* c) {
    citas.push_back(c);
}

void Hospital::modificarCita(const std::string &id, const std::string &nuevaFecha, int nuevaUrgencia) {
    for(auto c : citas) {
        if(c->getId() == id) {
            c->setFecha(nuevaFecha);
            c->setUrgencia(nuevaUrgencia);
            std::cout << "Cita modificada.\n";
            return;
        }
    }
    std::cout << "Cita no encontrada.\n";
}

void Hospital::listarCitas() const {
    std::cout << "\n-- Lista de Citas --\n";
    for(auto c : citas)
        std::cout << "ID Cita: " << c->getId() << ", Paciente ID: " << c->getPacienteId()
                  << ", Médico ID: " << c->getMedicoId() << ", Fecha: " << c->getFecha()
                  << ", Urgencia: " << c->getUrgencia() << "\n";
}

void Hospital::cancelarCita(const std::string &id) {
    auto it = std::remove_if(citas.begin(), citas.end(),
        [&id](Cita* c){ return c->getId() == id; });
    if(it != citas.end()){
        for(auto itr = it; itr != citas.end(); ++itr)
            delete *itr;
        citas.erase(it, citas.end());
        std::cout << "Cita cancelada.\n";
    } else {
        std::cout << "Cita no encontrada.\n";
    }
}

void Hospital::ordenarCitasPorUrgencia() {
    std::sort(citas.begin(), citas.end(), [](Cita* a, Cita* b){
        return a->getUrgencia() > b->getUrgencia();
    });
}

void Hospital::ordenarCitasPorFecha() {
    std::sort(citas.begin(), citas.end(), [](Cita* a, Cita* b){
        return convertirFecha(a->getFecha()) < convertirFecha(b->getFecha());
    });
}

// --- Gestión de Servicios ---
void Hospital::agregarServicio(Servicio* s) {
    servicios.push_back(s);
}

void Hospital::listarServicios() const {
    std::cout << "\n-- Lista de Servicios --\n";
    for(auto s : servicios)
        std::cout << "ID: " << s->getId() << ", Descripción: " << s->getDescripcion()
                  << ", Costo: " << s->getCosto() << "\n";
}

// --- Generación de Reportes ---
void Hospital::reportePacientesPorFecha(const std::string &fechaInicio, const std::string &fechaFin) const {
    int inicio = convertirFecha(fechaInicio);
    int fin = convertirFecha(fechaFin);
    std::cout << "\n-- Reporte de Pacientes entre " << fechaInicio << " y " << fechaFin << " --\n";
    for(auto p : pacientes) {
        int fechaPac = convertirFecha(p->getFechaIngreso());
        if(fechaPac >= inicio && fechaPac <= fin)
            std::cout << "ID: " << p->getId() << ", Nombre: " << p->getNombre() 
                      << ", Fecha Ingreso: " << p->getFechaIngreso() << "\n";
    }
}

void Hospital::reporteCitasPendientesPorMedico(const std::string &idMedico) const {
    std::cout << "\n-- Reporte de Citas Pendientes para Médico ID: " << idMedico << " --\n";
    // Suponiendo que las citas con fecha futura son pendientes; para simplificar se usa una fecha de referencia fija.
    int hoy = convertirFecha("01/01/2025");
    for(auto c : citas) {
        if(c->getMedicoId() == idMedico && convertirFecha(c->getFecha()) >= hoy)
            std::cout << "ID Cita: " << c->getId() << ", Fecha: " << c->getFecha() << "\n";
    }
}

void Hospital::reporteCitasPendientesPorEspecialidad(const std::string &especialidad) const {
    std::cout << "\n-- Reporte de Citas Pendientes para Especialidad: " << especialidad << " --\n";
    int hoy = convertirFecha("01/01/2025");
    for(auto c : citas) {
        auto it = std::find_if(medicos.begin(), medicos.end(), 
            [&c](Medico* m){ return m->getId() == c->getMedicoId(); });
        if(it != medicos.end() && (*it)->getEspecialidad() == especialidad 
           && convertirFecha(c->getFecha()) >= hoy)
            std::cout << "ID Cita: " << c->getId() << ", Médico: " << (*it)->getNombre() 
                      << ", Fecha: " << c->getFecha() << "\n";
    }
}

void Hospital::reportePacientesConEnfermedadesCronicas() const {
    std::cout << "\n-- Reporte de Pacientes con Enfermedades Crónicas --\n";
    for(auto p : pacientes) {
        if(!p->getEnfermedadesCronicas().empty())
            std::cout << "ID: " << p->getId() << ", Nombre: " << p->getNombre() << "\n";
    }
}

// --- Manejo de Archivos ---
void Hospital::guardarDatos() const {
    std::ofstream archivo("hospital_data.txt");
    if(archivo.is_open()){
        archivo << "== Pacientes ==\n";
        for(auto p : pacientes)
            archivo << p->getId() << ";" << p->getNombre() << ";" << p->getEdad() 
                    << ";" << p->getFechaIngreso() << "\n";
        archivo << "\n== Médicos ==\n";
        for(auto m : medicos)
            archivo << m->getId() << ";" << m->getNombre() << ";" << m->getEspecialidad() 
                    << ";" << (m->isDisponible() ? "Sí" : "No") << "\n";
        archivo << "\n== Citas ==\n";
        for(auto c : citas)
            archivo << c->getId() << ";" << c->getPacienteId() << ";" << c->getMedicoId()
                    << ";" << c->getFecha() << ";" << c->getUrgencia() << "\n";
        archivo << "\n== Servicios ==\n";
        for(auto s : servicios)
            archivo << s->getId() << ";" << s->getDescripcion() << ";" << s->getCosto() << "\n";
        archivo.close();
        std::cout << "Datos guardados en hospital_data.txt\n";
    } else {
        std::cout << "Error al abrir el archivo para escribir los datos.\n";
    }
}

void Hospital::backupDatabase() const {
    std::ifstream archivoEntrada("hospital_data.txt");
    if(!archivoEntrada.is_open()){
        std::cout << "Archivo de datos no existe. Guarde los datos primero.\n";
        return;
    }
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::ostringstream oss;
    oss << "backup_" << (1900 + ltm->tm_year) 
        << (1 + ltm->tm_mon) 
        << ltm->tm_mday << ".txt";
    std::string backupFile = oss.str();
    std::ofstream archivoSalida(backupFile);
    if(archivoSalida.is_open()){
        archivoSalida << archivoEntrada.rdbuf();
        archivoSalida.close();
        std::cout << "Backup realizado en " << backupFile << "\n";
    } else {
        std::cout << "Error al crear el backup.\n";
    }
}
