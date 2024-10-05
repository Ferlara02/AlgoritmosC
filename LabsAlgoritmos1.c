#include <stdbool.h> /* biblioteca estÃ¡ndar de booleanos*/
#include <stdio.h>


int main(void){
    int n, res, cont;
    res = 1;

    printf("ingrese la variable n\n");
    scanf("%d", &n);
        cont = n; 
    while(cont > 0)
    {
        res = cont * res;
        cont = cont - 1;
    }
    printf("El factorial de %i es %i\n", n, res);
    /*
    y = y + y;
    printf("x: %d, y: %d\n", x, y);
    x = x + y;
    printf("x: %d, y: %d\n", x, y);
    */
    /*printf("ingrese la variable z\n");
    scanf("%d", &z);

    printf("X + Y + 1 = %d \n", x + y + 1);
    printf("z * z + y * 45 - 15 * x = %d \n", z * z + y * 45 - 15 * x);
    printf("y-2 == (x*3+1) % 5 = %d \n", y-2 == (x*3+1) % 5);
    printf("y/2 * x = %d \n", y/2 * x);
    */
   return 0;
}