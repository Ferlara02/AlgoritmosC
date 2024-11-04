#include <stdio.h>
#include <stdbool.h> 
#include <assert.h>
#include <limits.h>

int minimo_pares(int tam, int a[]) {
    int min_par = INT_MAX;  // Inicializamos con el máximo valor de int para comparar
    int i = 0;
    while(i<tam) {
        if (a[i] % 2 == 0) {  // Verificamos si el elemento es par
            if (a[i] < min_par) {
                min_par = a[i];
            }
        }
        i++;
    }
    return min_par;
}

int minimo_impares(int tam, int a[]) {
    int min_impar = INT_MAX;  // Inicializamos con el máximo valor de int para comparar
    int i = 0;
    while(i<tam) {
        if (a[i] % 2 != 0) {  // Verificamos si el elemento es par
            if (a[i] < min_impar) {
                min_impar = a[i];
            }
        }
        i++;
    }
    return min_impar;
}

#define N 5
int main(){
    int a[N];
    int i = 0;
    while (i < N)
    {
        printf("Ingresa el valor de a.%i\n", i);
        scanf("%d", &a[i]);
        i++;
    }
    printf("El elemento par mas chico del arreglo es: %d\n", minimo_pares(N, a));
    printf("El elemento impar mas chico es: %d\n", minimo_impares(N, a));
    printf("El elemento minimo de todo el arreglo es: %d\n", minimo_impares(N, a) < minimo_pares(N, a) ? minimo_impares(N, a) : minimo_pares(N, a));
}