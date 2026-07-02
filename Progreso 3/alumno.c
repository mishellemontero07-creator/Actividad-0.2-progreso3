#include <stdio.h>
#include "alumno.h"

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
