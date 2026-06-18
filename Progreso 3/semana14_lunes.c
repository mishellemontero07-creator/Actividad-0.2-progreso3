//18/06/2026
//Semana 14: MANEJO DE ARCHIVOS

//Continuamos con el ejemplo de la semana 13 (jueves)
//Ahora vamos a usar arreglos + estructuras + punteros (todo básicamente ) + MANEJO DE ARCHIVOS 

#include <stdio.h>
#include <string.h>



struct Direccion{      
    char callePrincipal [50];
    int numeroCasa;
    char calleSecundaria[50];

};

//Esta estructura se llama anidamiento de estructuras
typedef struct {   //typedef: me permite utilizar el nombre de ese tipo de dato sin necesidad de usar la palabra struct
    char nombre[50];   
    struct Direccion direccion;
     int edad;
}  Alumno;  

void mostrarAlumno(Alumno *a);  //1. Creamos el prototipo de la funcion
void guardarArchivo(Alumno *a); //Creamos el prototipo del Archivo

int main(int argc, char const *argv[])
{
    //si yo tengo varias alumnos, al hacer Alumno a1; solo estoy declarando para un único alumno, pero si quiero más??, usamos arreglo 

    //p1->clase
    Alumno clase[2];  //vector  de tamaño 2 de tipo Alumno de nombre clase
    strcpy(clase[0].nombre,"JUAN");
    strcpy(clase[0].direccion.callePrincipal ,  "San Carlos");
    strcpy(clase[0].direccion.calleSecundaria ,  "Huachi");
    clase[0].direccion.numeroCasa = 123;
    clase[0].edad = 20;
    
    //strcpy(p.1 nombre,"Juan")

    strcpy(clase[1].nombre,"Maria");
    strcpy(clase[1].direccion.callePrincipal ,  "Av Galo Plaza");
    strcpy(clase[1].direccion.calleSecundaria ,  "Naciones Unidas");
    clase[1].direccion.numeroCasa = 563;
    clase[1].edad = 26; 

    mostrarAlumno(clase);  
    guardarArchivo(Alumno); 
    return 0;
}


//2. Creamos el cuerpo de la función
void mostrarAlumno(Alumno *a){
for ( int i = 0; i < 2; i++)
{
  printf ("Nombre: %s\n", a[i].nombre);
  printf ("Edad: %d\n", a[i].edad);
    printf("Direccion: %s ", a[i].direccion.callePrincipal);
    printf("%d",  a[i].direccion.numeroCasa);
    printf("%s\n\n",  a[i].direccion.calleSecundaria);  
}

void guardarArchivo(Alumno *a);
    FILE *archivo = fopen("alumnos.txt", "w");  //primer paso, usamos la palabra reservada FILE 
    for(int i=0;  i < 2; i++)
    {

        fprintf(archivo, "Nombre: %s\n" , a[i].nombre );//a[i].nombre es el valor 
        
        fprintf(archivo, "Edad: %d\n" , a[i].edad );  
        fprintf("Direccion:  %s %d %s", a[i].direccion.callePrincipal, a[i].direccion.numeroCasa, a[i].direccion.calleSecundaria );

    
    }
    
    fclose(archivo); 
}