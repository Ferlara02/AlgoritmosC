#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

int suma_hasta(int n) {
    int res;
    res = n;
    while (n>0) {
        res = res + (n-1);
        n = n - 1;
    }
    return res;
}

int main(void) {
    int x;
    printf("Ingresa el valor de x\n");
    scanf("%d", &x);
    if(x<0) {
        printf("ERROR: Ingresaste un valor negativo\n");
    } else if (x>=0) {
        printf("La suma de los primeros n naturales es:%i\n", suma_hasta(x));
    }
}