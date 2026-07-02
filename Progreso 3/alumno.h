#ifndef ALUMNO_H
#define ALUMNO_H

#include <stdio.h>

// Estructura Dirección
struct Direccion{
    char callePrincipal[50];
    char calleSecundaria[50];
    int numeroCasa;
};

// Estructura Alumno
typedef struct{
    char nombre[50];
    struct Direccion direccion;
    int edad;
} Alumno;

// Función para mostrar alumnos
void mostrarAlumno(Alumno *a);

#endif