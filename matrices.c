//Libro: Introducciòn a programaciòn en c
//pàgina 81
//Trabajo en clases Matrices 09/04/2026

#include <stdio.h>

int main() {
    //declaraciòn de matrices 
 int m1[3][3]={{5,6,1}, {1,2,3} ,{7,4,8}};
 int m2 [3][3]={{1,2,3}, {4,5,6} ,{7,8,9}};
 int m3[3][3];
 
 //bucle para sumar
 
 for(int i=0; i<3;i++)
 {
     for (int j=0; i<3; j++)
     {
         m3[i][j]= m1[i][j] + m2[i][j];
     }
 }     
 
 //bucle para imprimir
    for(int i=0; i<3; i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t", m3[i][j]);
        }
     printf("\n");
    }
    return 0; 
}