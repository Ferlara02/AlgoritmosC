#include <stdio.h>
#include <stdbool.h> 
int main(void) {
    int x, y, aux;
    printf("Ingresa el valor de x\n");
    scanf("%d", &x);
    printf("Ingresa el valor de y\n");
    scanf("%d", &y);
    aux = x;
    x = x + 1;
    y = aux + y;

    return 0;
}

int lab2b(void) {
    int x, y, z, xaux, yaux;
    printf("Ingresa el valor de x\n");
    scanf("%d", &x);
    printf("Ingresa el valor de y\n");
    scanf("%d", &y);
    printf("Ingresa el valor de z\n");
    scanf("%d", &z);
    xaux = x;
    yaux = y;
    x = y;
    y = y + xaux + z;
    z = yaux + xaux;

    return 0;
}