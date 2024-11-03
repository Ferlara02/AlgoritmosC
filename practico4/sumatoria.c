#include <stdio.h>
#include <stdbool.h> 
#define N 5
int sumatoria(int tam, int a[]) {
    int n = 0;
    int res = 0;

    while (n<tam) {
        res = res + a[n];
        n = n+1;
    }

    return res; 
}


int main(void) {
    /*printf("Ingrese tamaño del arreglo: \n");
    scanf("%d", &N);*/
    int a[N];
    int i = 0;
    
    while (i < N)
    {
        printf("Ingresa el valor de a.%i\n", i);
        scanf("%d", &a[i]);
        i++;
    }

    printf("La suma de todos los elementos es de: %i\n",  sumatoria(N, a));
    return 0;
}
