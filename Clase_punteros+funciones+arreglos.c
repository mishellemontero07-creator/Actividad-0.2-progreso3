//    18/05/2026
// En este ejercicio vamos a usar punteros + arreglos + funciones


#include <stdio.h>

float calcular(float *vector);


int main() 
{
 
    float notas[5]= {8 ,  7,  7.5, 3.0,  6.1};
    printf("el promedio es:%.2f", calcular(notas) );
    return 0;
}


float calcular(float *vector){
       float promedio = 0;
       
     for(int i=0; i< 5; i++)
   {
       printf("%.1f\n ", vector[i]);
       promedio=promedio+vector[i];
     
   }
    promedio = promedio/5;
    return promedio;
}


