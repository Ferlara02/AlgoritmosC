#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

void pedir_arreglo(int n_max, int a[]) {
    printf("Ingrese los elementos del arreglo:\n");
    int k = 0; 
    while (k < n_max) {
        printf("Elemento %d: ", k + 1);
        scanf("%d", &a[k]);
        k++;
    }
}

void imprimir_arreglo(int n_max, int a[]){
    for (int l = 0; l < n_max; l++) {
            printf("%d \n", a[l]);
    }
}

int main() {
    int n_max;
    printf("Tamaño del arreglo: \n");
    scanf("%d", &n_max);
    int a[n_max];
    pedir_arreglo(n_max, a);
    imprimir_arreglo(n_max, a);
}