#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "alumno.h"

// Guardar datos en archivo CSV
void guardarArchivo(Alumno *a, int n);

// Leer archivo CSV
void leerCSV();

// Buscar alumno por nombre
void buscarAlumno(char *cadenaBuscada);

#endif