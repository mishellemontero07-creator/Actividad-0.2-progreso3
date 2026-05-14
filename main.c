//Headers 07/05/2026
#include <stdio.h>
#include "sumar.h"
#include "restar.h"
#include "multiplicar.h"
#include "dividir.h"




int main (int argc, char const*argv [])
{
 int a,b;
 printf ("ingrese 1er numero: ");
 scanf("%d", &a);

 printf ("ingrese 2do numero: ");
 scanf("%d", &b);

     printf("El resultado de la suma es: %d\n", sumar(a,b));
    printf("El resultado de la resta es:%d\n", restar(a,b));
    printf("El resultado de la multiplicacion es: %d\n", multiplicar(a,b));
    printf("El resultado de la division es: %d\n", dividir(a,b));

 return 0;

}


