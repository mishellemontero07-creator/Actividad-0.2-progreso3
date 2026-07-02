#include <stdio.h>
#include <string.h>

#include "alumno.h"
#include "archivo.h"

int main()
{
    Alumno clase[2];

    strcpy(clase[0].nombre, "JUAN");
    strcpy(clase[0].direccion.callePrincipal, "San Carlos");
    strcpy(clase[0].direccion.calleSecundaria, "Huachi");
    clase[0].direccion.numeroCasa = 123;
    clase[0].edad = 20;

    strcpy(clase[1].nombre, "Maria");
    strcpy(clase[1].direccion.callePrincipal, "Av Galo Plaza");
    strcpy(clase[1].direccion.calleSecundaria, "Naciones Unidas");
    clase[1].direccion.numeroCasa = 563;
    clase[1].edad = 26;

    mostrarAlumno(clase);

    char nombreBuscado[50];
    printf("Ingrese el nombre a buscar: ");
    fgets(nombreBuscado, 50, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = '\0';

    buscarAlumno(nombreBuscado);

    return 0;
}

void mostrarAlumno(Alumno *a)
{
    for (int i = 0; i < 2; i++)
    {
        printf("Nombre: %s\n", a[i].nombre);
        printf("Edad: %d\n", a[i].edad);
        printf("Direccion: %s %d %s\n\n",
               a[i].direccion.callePrincipal,
               a[i].direccion.numeroCasa,
               a[i].direccion.calleSecundaria);
    }
}

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

        if(strcmp(alumno.nombre,cadenaBuscada )==0 )
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



