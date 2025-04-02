#include <stdio.h>
#include <stdbool.h> 
#include <assert.h>

struct comp_t {
    int menores;
    int iguales;
    int mayores;
};

struct comp_t cuantos(int tam, int a[], int elem) {
    struct comp_t resultado;
    resultado.menores = 0;
    resultado.iguales = 0;
    resultado.mayores = 0;
    
    int i = 0;
    while(i < tam) {
        if (a[i] < elem) {
            resultado.menores++;
            i++;
        } else if (a[i] == elem) {
            resultado.iguales++;
            i++;
        } else if (a[i] > elem) {
            resultado.mayores++;
            i++;
        } 
    }

    return resultado;
}

#define N 5
int main(void) {
    int i = 0;
    int a[N];
    int elem;
    while (i < N)
    {
        printf("Ingresa el valor de a.%i\n", i);
        scanf("%d", &a[i]);
        i++;
    }
    printf("Ingrese el numero a comparar\n");
    scanf("%d", &elem);
    struct comp_t resultado = cuantos(N, a, elem);
    printf("Elementos menores: %d, elementos mayores: %d, elementos iguales: %d\n", resultado.menores, resultado.mayores, resultado.iguales);
}