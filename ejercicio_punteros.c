// Fecha: 11/05/2026
//Ejercicio clase Punteros

#include <stdio.h>
int suma(int a,int b);
int sumaxref(int *a, int *b);


int main(){

    int a, b;

    printf("Ingrese el valor: \n");
    scanf("%d", &a);

    printf("Ingrese el valor de b: \n");
    scanf("%d", &b);

    int resultado= suma(a,b);

    printf("El resultado de la suma es: %d\n", suma(a,b));
    
    //Aqui estamos imprimiendo los punteros, pero OJO cómo hacemos que lea la variable "sumaref", con &. 
    printf("El resultado de la suma es: %d\n", sumaxref(&a,&b));

}

//Aqui solo es una declaración de funció suma simple
int suma(int a,int b){
    return a+b;

}

//Aqui estamos usando punteros
int sumaxref(int *a,int *b){
    return *a + *b;
    
}


/*Código del profe

#include <stdio.h>
int suma(int a,int b);
int sumaxref(int *a,int *b);

 

int main() {
    int a,b;
    printf("valor de a:");
    scanf("%d", &a);
    printf("valor de b:");
    scanf("%d", &b);
    printf("La respuesta de la suma es: %d\n", suma(a,b));
    printf("La respuesta de la suma es: %d\n", sumaxref(&a,&b));
}
int suma(int a,int b){
        return a+b;
}
int sumaxref(int *a,int *b){
        return *a + *b;
}


*/