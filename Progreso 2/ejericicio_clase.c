#include <stdio.h>
 
int main() {
    int n, i;
    int A[50];

 
    // Leer el número de elementos
    printf("Ingrese el numero de elementos: ");
    scanf("%d", &n);
    
    if(n<0){
     printf("el numero ingresado no es positivo!! ");
     return 0;
    }
 
    // Leer los elementos del vector
    for(i = 0; i < n; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &A[i]);
    }
 
    
    for(i = 0; i < n; i++) {
        printf("%d\n", A[i]);
    }
 
    return 0;
}
