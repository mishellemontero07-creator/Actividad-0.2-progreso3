//Clase semana 8

#include <stdio.h>

int main() 
{
    
    
  int vector[7]= {3,6,9,12,15,18,21};

 int *ptr;
  ptr= &vector[0];
   
   for(int i=0; i< 7; i++)
   {
       printf("%d \n", vector[i]);
        printf("%d \n", *(ptr + i));

   
   }
  
 
    return 0;
}

