#include <iostream>
#include <string>
#include <clocale>
#include "Hospital.hpp"
#include "Paciente.hpp"
#include "Medico.hpp"
#include "Cita.hpp"
#include "Servicio.hpp"
#include <windows.h>

using namespace std;

void submenuPacientes(Hospital& hospital) {
    int opcion;
    do {
        cout << "\n-- Menú de Gestión de Pacientes --\n"
            << "1. Agregar Paciente\n"
            << "2. Listar Pacientes\n"
            << "3. Buscar Paciente (por ID, Nombre o Fecha de Ingreso)\n"
            << "4. Modificar Paciente\n"
            << "5. Eliminar Paciente\n"
            << "6. Agregar Registro Clínico / Enfermedad Crónica\n"
            << "0. Volver al Menú Principal\n"
            << "Seleccione una opción: ";
        cin >> opcion; cin.ignore();
        switch (opcion) {
        case 1: {
            string nombre, fechaIngreso;
            int edad;
            cout << "Ingrese nombre del paciente: ";
            getline(cin, nombre);
            cout << "Ingrese edad: ";
            cin >> edad; cin.ignore();
            cout << "Ingrese fecha de ingreso (DD/MM/AAAA): ";
            getline(cin, fechaIngreso);
            Paciente* nuevoPaciente = new Paciente(nombre, edad, fechaIngreso);
            hospital.agregarPaciente(nuevoPaciente);
            cout << "Paciente agregado! ID: " << nuevoPaciente->getId() << "\n";
            break;
        }
        case 2:
            hospital.listarPacientes();
            break;
        case 3: {
            string criterio, valor;
            cout << "Buscar paciente por (1) ID, (2) Nombre, (3) Fecha de Ingreso: ";
            getline(cin, criterio);
            cout << "Ingrese valor de búsqueda: ";
            getline(cin, valor);
            hospital.buscarPaciente(criterio, valor);
            break;
        }
        case 4: {
            string id, nuevoNombre;
            int nuevaEdad;
            cout << "Ingrese ID del paciente a modificar: ";
            getline(cin, id);
            cout << "Ingrese nuevo nombre: ";
            getline(cin, nuevoNombre);
            cout << "Ingrese nueva edad: ";
            cin >> nuevaEdad; cin.ignore();
            hospital.modificarPaciente(id, nuevoNombre, nuevaEdad);
            break;
        }
        case 5: {
            string id;
            cout << "Ingrese ID del paciente a eliminar: ";
            getline(cin, id);
            hospital.eliminarPaciente(id);
            break;
        }
        case 6: {
            string id, tipo, info;
            cout << "Ingrese ID del paciente: ";
            getline(cin, id);
            cout << "¿Desea agregar (1) Registro Clínico o (2) Enfermedad Crónica? ";
            getline(cin, tipo);
            cout << "Ingrese la información: ";
            getline(cin, info);
            if (tipo == "1")
                hospital.agregarRegistroClinicoPaciente(id, info);
            else if (tipo == "2")
                hospital.agregarEnfermedadCronicaPaciente(id, info);
            else
                cout << "Tipo no reconocido.\n";
            break;
        }
        case 0:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

void submenuMedicos(Hospital& hospital) {
    int opcion;
    do {
        cout << "\n-- Menú de Gestión de Médicos --\n"
            << "1. Agregar Médico\n"
            << "2. Listar Médicos\n"
            << "3. Eliminar Médico\n"
            << "0. Volver al Menú Principal\n"
            << "Seleccione una opción: ";
        cin >> opcion; cin.ignore();
        switch (opcion) {
        case 1: {
            string nombre, especialidad;
            cout << "Ingrese nombre del médico: ";
            getline(cin, nombre);
            cout << "Ingrese especialidad: ";
            getline(cin, especialidad);
            Medico* nuevoMedico = new Medico(nombre, especialidad);
            hospital.agregarMedico(nuevoMedico);
            cout << "Médico agregado! ID: " << nuevoMedico->getId() << "\n";
            break;
        }
        case 2:
            hospital.listarMedicos();
            break;
        case 3: {
            string id;
            cout << "Ingrese ID del médico a eliminar: ";
            getline(cin, id);
            hospital.eliminarMedico(id);
            break;
        }
        case 0:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

void submenuCitas(Hospital& hospital) {
    int opcion;
    do {
        cout << "\n-- Menú de Gestión de Citas --\n"
            << "1. Agendar Cita\n"
            << "2. Listar Citas (ordenadas por urgencia)\n"
            << "3. Listar Citas (ordenadas por fecha)\n"
            << "4. Modificar Cita\n"
            << "5. Cancelar Cita\n"
            << "0. Volver al Menú Principal\n"
            << "Seleccione una opción: ";
        cin >> opcion; cin.ignore();
        switch (opcion) {
        case 1: {
            string idPaciente, idMedico, fecha;
            int urgencia;
            cout << "Ingrese ID del paciente: ";
            getline(cin, idPaciente);
            cout << "Ingrese ID del médico: ";
            getline(cin, idMedico);
            cout << "Ingrese fecha de la cita (DD/MM/AAAA): ";
            getline(cin, fecha);
            cout << "Ingrese nivel de urgencia (1 al 5): ";
            cin >> urgencia; cin.ignore();
            if (!hospital.existePaciente(idPaciente)) {
                cout << "Paciente no encontrado.\n";
                break;
            }
            if (!hospital.existeMedico(idMedico)) {
                cout << "Médico no encontrado.\n";
                break;
            }
            Cita* nuevaCita = new Cita(idPaciente, idMedico, fecha, urgencia);
            hospital.agregarCita(nuevaCita);
            cout << "Cita agendada! ID: " << nuevaCita->getId() << "\n";
            break;
        }
        case 2:
            hospital.ordenarCitasPorUrgencia();
            hospital.listarCitas();
            break;
        case 3:
            hospital.ordenarCitasPorFecha();
            hospital.listarCitas();
            break;
        case 4: {
            string id, nuevaFecha;
            int nuevaUrgencia;
            cout << "Ingrese ID de la cita a modificar: ";
            getline(cin, id);
            cout << "Ingrese nueva fecha (DD/MM/AAAA): ";
            getline(cin, nuevaFecha);
            cout << "Ingrese nueva urgencia: ";
            cin >> nuevaUrgencia; cin.ignore();
            hospital.modificarCita(id, nuevaFecha, nuevaUrgencia);
            break;
        }
        case 5: {
            string id;
            cout << "Ingrese ID de la cita a cancelar: ";
            getline(cin, id);
            hospital.cancelarCita(id);
            break;
        }
        case 0:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

void submenuServicios(Hospital& hospital) {
    int opcion;
    do {
        cout << "\n-- Menú de Gestión de Servicios --\n"
            << "1. Agregar Servicio\n"
            << "2. Listar Servicios\n"
            << "0. Volver al Menú Principal\n"
            << "Seleccione una opción: ";
        cin >> opcion; cin.ignore();
        switch (opcion) {
        case 1: {
            string descripcion;
            double costo;
            cout << "Ingrese descripción del servicio: ";
            getline(cin, descripcion);
            cout << "Ingrese costo del servicio: ";
            cin >> costo; cin.ignore();
            Servicio* nuevoServicio = new Servicio(descripcion, costo);
            hospital.agregarServicio(nuevoServicio);
            cout << "Servicio agregado! ID: " << nuevoServicio->getId() << "\n";
            break;
        }
        case 2:
            hospital.listarServicios();
            break;
        case 0:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

void submenuArchivos(Hospital& hospital) {
    int opcion;
    do {
        cout << "\n-- Menú de Manejo de Archivos --\n"
            << "1. Guardar Datos en Archivo\n"
            << "2. Realizar Backup de la Base de Datos\n"
            << "0. Volver al Menú Principal\n"
            << "Seleccione una opción: ";
        cin >> opcion; cin.ignore();
        switch (opcion) {
        case 1:
            hospital.guardarDatos();
            break;
        case 2:
            hospital.backupDatabase();
            break;
        case 0:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

void submenuReportes(Hospital& hospital) {
    int opcion;
    do {
        cout << "\n-- Menú de Reportes --\n"
            << "1. Reporte de Pacientes por Fecha de Ingreso\n"
            << "2. Reporte de Citas Pendientes por Médico\n"
            << "3. Reporte de Citas Pendientes por Especialidad\n"
            << "4. Reporte de Pacientes con Enfermedades Crónicas\n"
            << "0. Volver al Menú Principal\n"
            << "Seleccione una opción: ";
        cin >> opcion; cin.ignore();
        switch (opcion) {
        case 1: {
            string inicio, fin;
            cout << "Ingrese fecha de inicio (DD/MM/AAAA): ";
            getline(cin, inicio);
            cout << "Ingrese fecha de fin (DD/MM/AAAA): ";
            getline(cin, fin);
            hospital.reportePacientesPorFecha(inicio, fin);
            break;
        }
        case 2: {
            string idMedico;
            cout << "Ingrese ID del médico: ";
            getline(cin, idMedico);
            hospital.reporteCitasPendientesPorMedico(idMedico);
            break;
        }
        case 3: {
            string especialidad;
            cout << "Ingrese especialidad: ";
            getline(cin, especialidad);
            hospital.reporteCitasPendientesPorEspecialidad(especialidad);
            break;
        }
        case 4:
            hospital.reportePacientesConEnfermedadesCronicas();
            break;
        case 0:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "");

    Hospital hospital;
    int opcion;
    do {
        cout << "\n==== Menú Principal ====\n"
            << "1. Gestión de Pacientes\n"
            << "2. Gestión de Médicos\n"
            << "3. Gestión de Citas\n"
            << "4. Gestión de Servicios\n"
            << "5. Manejo de Archivos\n"
            << "6. Reportes\n"
            << "0. Salir\n"
            << "Seleccione una opción: ";
        cin >> opcion; cin.ignore();
        switch (opcion) {
        case 1: submenuPacientes(hospital); break;
        case 2: submenuMedicos(hospital); break;
        case 3: submenuCitas(hospital); break;
        case 4: submenuServicios(hospital); break;
        case 5: submenuArchivos(hospital); break;
        case 6: submenuReportes(hospital); break;
        case 0: cout << "Saliendo del sistema...\n"; break;
        default: cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
    return 0;
}
