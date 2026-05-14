//Clase 16/04  Ejercicios con vectores y funciones


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definiciòn de la funciòn llenarvector
 void llenarvector(int vector[], int n)
 {
    
      for (int i= 0; i <n; i++) 
    {
        vector[i]= rand() %101;
    }
     
 }
 
 //declaraciòn de la funciòn imprimirvector
 void imprimirvector(int vector[], int n)
 {
     for (int i= 0; i <n; i++)
     {
         printf("%d ", vector[i]);
       
     }
 }

int main() 
{
    //definir un vector tipo entero de tamaño (n)
    int n;
    printf("Ingrese el tamaño del vector: ");
    scanf("%d",&n);

    int vector[n];   
    llenarvector(vector,n); //llamado a la funciòn llenarvector
    imprimirvector (vector, n); //llamado a la funciòn imprimir vector
    

    return 0;
}

  