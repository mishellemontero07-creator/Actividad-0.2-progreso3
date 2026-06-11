//11/06/2026

//Clase jueves 11, seguimos con estructuras, esta vez lo vamos a ver estructuras con punteros

#include <stdio.h>
#include <string.h>


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
  
    printf("Direccion: %s %d %s ", a1.direccion.callePrincipal,a1.direccion.numeroCasa,a1.direccion.calleSecundaria );

   
    return 0;
}


