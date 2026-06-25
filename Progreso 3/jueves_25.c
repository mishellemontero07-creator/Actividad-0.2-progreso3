//   25/06/2026
// Tema: Manejo de archivos usando comas 


//Continuamos con el ejemplo de la semana 13 (jueves)
//Ahora vamos a usar arreglos + estructuras + punteros (todo básicamente ) + MANEJO DE ARCHIVOS 

#include <stdio.h>
#include <string.h>



struct Direccion{      
    char callePrincipal [50];
    char calleSecundaria[50];
    int numeroCasa;
   

};

//Esta estructura se llama anidamiento de estructuras
typedef struct {   //typedef: me permite utilizar el nombre de ese tipo de dato sin necesidad de usar la palabra struct
    char nombre[50];   
    struct Direccion direccion;
     int edad;
}  Alumno;  

void mostrarAlumno(Alumno *a);  //1. Creamos el prototipo de la funcion
void guardarArchivo(Alumno *a); //Creamos el prototipo del Archivo
void leerCSV();


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

    //mostrarAlumno(clase);  
    guardarArchivo( Alumno, 2 ); 
    //leerArchivo()
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

void guardarArchivo(Alumno *a){



    FILE *archivo = fopen("alumnos.txt", "w");  //cambiamos la extension de txt a csv 
    {

       // fprintf(archivo, "Nombre: %s\n" , a[i].nombre ); 
       // fprintf(archivo, "Edad: %d\n" , a[i].edad );  
        fprintf(archivo, "%s ; %s ; %s ; %d  ; %d\n",   //FORMATO DE MI REGISTRO: usamos el punto y coma 
            a[i].nombre,
            a[i].direccion.callePrincipal,
            a[i].direccion.calleSecundaria,
            a[i].direccion.numeroCasa, 
            a[i].edad);

         //fprintf(archivo, ".......................\n");   
    }
    
    fclose(archivo); 
    printf("datos guardados en alumnos.csv\n");

}


void leerArchivo()
{
    FILE *archivo = fopen("alumnos.csv", "r");


    if (archivo ==NULL)
    {
        printf("No se puede abrir el archivo");
        return;

    }

    char linea [150]; 

    while (fgets (linea, 150, archivo) != NULL) 
    {
    printf("%s", linea);
    } 
    

    fclose(archivo);

}

void leerCSV(){

FILE *archivo= fopen ("alumno.csv", "r");

 if (archivo ==NULL)
    {
        printf("No se puede abrir el archivo");
        return;

    }


    Alumno alumno; //aqui voy a colocar los datos leidos del archivo
    


    while (fscanf(archivo,
        
            "%49[^;] ; %49[^;] ; %49[^;] ; %d ; %d",
            alumno.nombre, 
            alumno.direccion.callePrincipal,
            alumno.direccion.calleSecundaria,
            &alumno.direccion.numeroCasa,
            &alumno.edad
            

        )==5)

        {
            printf("%s", alumno.nombre);
        

        }
          ;  //vamos a empezar a usar patrones de formato

}

