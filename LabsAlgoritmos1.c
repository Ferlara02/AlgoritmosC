#include <stdbool.h> /* biblioteca estÃ¡ndar de booleanos*/
#include <stdio.h>


int main(void){
    int x, y,z; 
    printf("ingrese la variable x\n");
    scanf("%d", &x);
    printf("ingrese la variable y\n");
    scanf("%d", &y);
    printf("ingrese la variable z\n");
    scanf("%d", &z);

    printf("X + Y + 1 = %d \n", x + y + 1);
    printf("z * z + y * 45 - 15 * x = %d \n", z * z + y * 45 - 15 * x);
    printf("y-2 == (x*3+1) % 5 = %d \n", y-2 == (x*3+1) % 5);
    printf("y/2 * x = %d \n", y/2 * x);
   return 0;
}