#include <stdio.h>
#include <stdbool.h> 
int main(void) {
    int x, y, z;
    printf("Ingresa el valor de x\n");
    scanf("%d", &x);
    printf("Ingresa el valor de y\n");
    scanf("%d", &y);
    printf("Ingresa el valor de z\n");
    scanf("%d", &z);
    z = x;
    x = y;
    y = z;

    return 0;
}