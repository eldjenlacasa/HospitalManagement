# Simulador de Gestión Hospitalaria

Este proyecto es una aplicación de simulación de gestión hospitalaria desarrollada en C++ que cumple con los requisitos de la asignatura "Applied Programming & Design Principles" de Pearson HND. La aplicación permite gestionar información de pacientes, médicos, citas médicas y servicios, aplicando principios SOLID y técnicas de código limpio.

---

## Índice

- [Descripción](#descripción)
- [Funcionalidades](#funcionalidades)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Requisitos](#requisitos)
- [Compilación e Instrucciones de Ejecución](#compilación-e-instrucciones-de-ejecución)
- [Decisiones de Diseño](#decisiones-de-diseño)
- [Pruebas y Validación](#pruebas-y-validación)
- [Contacto](#contacto)

---

## Descripción

El simulador de gestión hospitalaria permite:

- **Gestión de Pacientes:** Alta, baja, modificación, búsqueda (por ID, nombre o fecha de ingreso) y registro de historial clínico y enfermedades crónicas.
- **Gestión de Médicos:** Alta, baja y listado de médicos, con la posibilidad de asignar especialidades y gestionar la disponibilidad.
- **Gestión de Citas Médicas:** Agendar, modificar, cancelar y listar citas. Las citas se pueden ordenar por urgencia y por fecha.
- **Gestión de Servicios:** Alta y listado de servicios hospitalarios.
- **Generación de Reportes:** Reportes de pacientes por rango de fechas, citas pendientes por médico o especialidad, y pacientes con enfermedades crónicas.
- **Manejo de Archivos:** Guardado de datos en archivos y creación de backups para la recuperación de la información.

El código se ha diseñado para ser lo más simple posible, manteniendo una alta legibilidad y modularidad sin sacrificar funcionalidad. Se utilizan contenedores de la STL y algoritmos estándar (como `std::sort` y `std::any_of`) para realizar búsquedas y ordenaciones, lo que facilita la escalabilidad y la integración de grandes volúmenes de datos.

---

## Funcionalidades

- **Pacientes:**
  - Alta y baja de pacientes.
  - Modificación de datos personales.
  - Búsqueda por ID, nombre o fecha de ingreso.
  - Registro de historial clínico y de enfermedades crónicas.

- **Médicos:**
  - Alta y baja de médicos.
  - Asignación y listado por especialidad y disponibilidad.

- **Citas Médicas:**
  - Agendamiento, modificación y cancelación de citas.
  - Ordenación de citas por urgencia y por fecha.
  - Gestión de citas pasadas y futuras.

- **Servicios:**
  - Alta y listado de servicios hospitalarios.

- **Reportes:**
  - Listado de pacientes entre dos fechas.
  - Reporte de citas pendientes por médico o especialidad.
  - Reporte de pacientes con enfermedades crónicas.

- **Manejo de Archivos:**
  - Guardado de datos en un archivo de texto.
  - Funcionalidad de backup de la base de datos.

---

## Estructura del Proyecto

El proyecto está organizado en los siguientes archivos:

- **Cita.hpp / Cita.cpp:** Define la clase `Cita` para gestionar citas médicas.
- **Medico.hpp / Medico.cpp:** Define la clase `Medico` para gestionar la información de los médicos.
- **Paciente.hpp / Paciente.cpp:** Define la clase `Paciente` para gestionar la información de los pacientes, incluyendo historial clínico y enfermedades crónicas.
- **Servicio.hpp / Servicio.cpp:** Define la clase `Servicio` para gestionar los servicios hospitalarios.
- **Hospital.hpp / Hospital.cpp:** Define la clase `Hospital`, que actúa como controlador central para la gestión de pacientes, médicos, citas y servicios, y para la generación de reportes y manejo de archivos.
- **main.cpp:** Contiene la función principal y el menú interactivo de la aplicación.
- **CMakeLists.txt:** Archivo de configuración para compilar el proyecto utilizando CMake.

Adicionalmente, se incluyen archivos de configuración de Git (como `.gitattributes`) y, opcionalmente, `CMakeSettings.json` para ciertos entornos de desarrollo.

---

## Requisitos

El proyecto cumple con los siguientes requisitos:

- Uso de programación orientada a objetos (POO) y principios SOLID.
- Manejo de memoria dinámica para la gestión de registros.
- Implementación de algoritmos de búsqueda y ordenación utilizando la STL.
- Funcionalidades para gestionar grandes volúmenes de datos (utilizando `std::vector`).
- Manejo de archivos para la persistencia de datos y creación de backups.
- Diseño modular que facilita el mantenimiento y la escalabilidad del sistema.

---

## Compilación e Instrucciones de Ejecución

### Requisitos Previos

- Compilador de C++ compatible con C++11 o superior.
- CMake (versión 3.10 o superior).

### Instrucciones

1. **Generar la carpeta de compilación:**
   ```bash
   mkdir build
   cd build
