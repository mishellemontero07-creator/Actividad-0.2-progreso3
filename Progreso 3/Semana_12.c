//08/06/2026
//Tema:Estructuras, primer programa


#include <stdio.h>
#include <string.h>
/*
// EJERCICIO 1: declaramos variables, sencillo
struct alumno{
    char nombre[50];   
    int edad;
    float altura;

} a1={"Juan", 25, 1.78};    //a1 es de tipo alumno 


int main(int argc, char const *argv[])
{
    printf ("Nombre: %s\n", a1.nombre);
      printf ("Edad: %d\n", a1.edad);
       printf ("Altura: %.2f", a1.altura);
    return 0;
}*/


//Ejercicio 2: aqui vamos a usar funciones complementarias para manejo de cadenas
//Primera función complementaria que hay que entender strcpy

struct alumno{
    char nombre[50];   
    int edad;
    float altura;

};  


int main(int argc, char const *argv[])
{
    struct alumno a1,a2,a3, an;  //puedo declarar cualquier numero de variables
    strcpy(a1.nombre,  "Juan");
    a1.edad = 25;
    a1.altura = 1.78;


    printf ("Nombre: %s\n", a1.nombre);
    printf ("Edad: %d\n", a1.edad);
    printf ("Edad: %.2f", a1.altura);
    return 0;
}


