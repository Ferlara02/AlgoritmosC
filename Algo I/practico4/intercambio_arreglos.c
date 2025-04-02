#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

void intercambiar(int tam, int a[], int i, int j) {
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

int main() {
    int tam;
    // Pedir el tamaño del arreglo
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &tam);
    int a[tam];

    // Pedir los elementos del arreglo
    printf("Ingrese los elementos del arreglo:\n");
    int k = 0; 
    while (k < tam) {
        printf("Elemento %d: ", k + 1);
        scanf("%d", &a[k]);
        k++;
    }

    int i, j;

    // Pedir las posiciones a intercambiar y validar que estén en el rango
    printf("Ingrese la primera posicion a intercambiar: ");
    scanf("%d", &i);
    printf("Ingrese la segunda posicion a intercambiar: ");
    scanf("%d", &j);

    if (i >= 0 && i < tam && j >= 0 && j < tam) {
        // Llamar a la función para intercambiar
        intercambiar(tam, a, i, j);

        // Imprimir el arreglo modificado
        printf("Arreglo modificado:\n");
        for (int l = 0; l < tam; l++) {
            printf("%d \n", a[l]);
        }
    } else {
        printf("Las posiciones ingresadas están fuera del rango.\n");
    }

    return 0;
}