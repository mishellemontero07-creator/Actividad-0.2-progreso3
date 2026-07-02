#include <stdio.h>
#include <string.h>

#include "archivo.h"

void guardarArchivo(Alumno *a, int n)
{
    FILE *archivo = fopen("alumnos.csv", "w");

    if (archivo == NULL)
    {
        printf("No se pudo crear el archivo.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(archivo,
                "%s;%s;%s;%d;%d\n",
                a[i].nombre,
                a[i].direccion.callePrincipal,
                a[i].direccion.calleSecundaria,
                a[i].direccion.numeroCasa,
                a[i].edad);
    }

    fclose(archivo);
    printf("Datos guardados en alumnos.csv\n");
}

void leerCSV()
{
    FILE *archivo = fopen("alumnos.csv", "r");

    if (archivo == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return;
    }

    Alumno alumno;

    while (fscanf(archivo,
                  " %49[^;];%49[^;];%49[^;];%d;%d",
                  alumno.nombre,
                  alumno.direccion.callePrincipal,
                  alumno.direccion.calleSecundaria,
                  &alumno.direccion.numeroCasa,
                  &alumno.edad) == 5)
    {
        printf("\nNombre: %s\n", alumno.nombre);
        printf("Edad: %d\n", alumno.edad);
        printf("Direccion: %s %d %s\n",
               alumno.direccion.callePrincipal,
               alumno.direccion.numeroCasa,
               alumno.direccion.calleSecundaria);
    }

    fclose(archivo);
}

void buscarAlumno(char *cadenaBuscada)
{
    FILE *archivo = fopen("alumnos.csv", "r");

    if (archivo == NULL)
    {
        printf("No se puede abrir el archivo\n");
        return;
    }

    Alumno alumno;

    while (fscanf(archivo,
                  " %49[^;];%49[^;];%49[^;];%d;%d",
                  alumno.nombre,
                  alumno.direccion.callePrincipal,
                  alumno.direccion.calleSecundaria,
                  &alumno.direccion.numeroCasa,
                  &alumno.edad) == 5)
    {
        if (strcmp(alumno.nombre, cadenaBuscada) == 0)
        {
            printf("\nNombre: %s\n", alumno.nombre);
            printf("Edad: %d\n", alumno.edad);
            printf("Direccion: %s %d %s\n",
                   alumno.direccion.callePrincipal,
                   alumno.direccion.numeroCasa,
                   alumno.direccion.calleSecundaria);
        }
    }

    fclose(archivo);
}