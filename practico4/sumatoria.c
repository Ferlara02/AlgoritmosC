#include <stdio.h>
#include <stdbool.h> 

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
    int tam;
    printf("Ingrese tamaño del arreglo: \n");
    scanf("%d", &tam);
    int a[tam];
    int i = 0;
    
    while (i < tam)
    {
        printf("Ingresa el valor de a.%i\n", i);
        scanf("%d", &a[i]);
        i++;
    }

    printf("La suma de todos los elementos es de: %i\n",  sumatoria(tam, a));
    return 0;
}
