//11/06/2026

//Clase jueves 11, seguimos con estructuras, esta vez lo vamos a ver estructuras con punteros y funciones. 


#include <stdio.h>
#include <string.h>

void mostrarAlumno();  //1. Creamos el prototipo de la funcion

struct Direccion{
    char callePrincipal [50];
    int numeroCasa;
    char calleSecundaria[50];

};


typedef struct {   //typedef: me permite utilizar el nombre de ese tipo de dato sin necesidad de usar la palabra struct
    char nombre[50];   
    struct Direccion direccion;
     int edad;
}  Alumno;  


int main(int argc, char const *argv[])
{
    Alumno a1;  // ya no necesito poner aqui la palabra "struct", solo hago ese pequeño cambio
    
    strcpy(a1.direccion.callePrincipal ,  "San Carlos");
    a1.direccion.numeroCasa = 123;
    strcpy(a1.direccion.calleSecundaria ,  "Huachi");
    mostrarAlumno(&a1);  //3. Llamamos a la funcion en el main 
    return 0;
}


//2. Creamos el cuerpo de la función
void mostrarAlumno(Alumno *a){
printf ("Nombre: %s\n", a->nombre);
printf("Direccion: %s ", a->direccion.callePrincipal);
printf("%d", a->direccion.numeroCasa);
printf("%s", a->direccion.calleSecundaria);

}