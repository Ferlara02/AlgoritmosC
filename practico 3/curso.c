#include <stdio.h>
#define PI 3.14159
#define CUBO(a) a*a*a
int main() 
/*{
    char C = 'a'; 
    int edad;
    printf("Ingrese tu edad \n");
    scanf("%d", &edad);
    if(edad >=18)
    {
        printf("Eres mayor de edad \n");
    }else if (edad == 17){
        printf("Eres casi mayor! \n");
    } else {
        printf("Eres menor! \n");
    }
    return 0;  
}*/

/*
{
    int contador;
    for(contador = 1; contador <= 10; contador++)
    {
        printf("%i\n", contador);
    }
    return 0;
}
*/
{
    int contador = 1;
    while(contador <= 10) 
    {
        printf("%i\n", contador);
        contador++;
    }
    return 0;
}