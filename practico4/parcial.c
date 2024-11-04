#include <stdio.h>
#include <stdbool.h> 
#include <assert.h>
#include <limits.h>

int sum_end(int tam, int a[], int n) {
    assert(n<=tam);
    int i = tam;
    int res = 0;
    while (i > (tam - n)){
        res = res + a[i-1];
        i--;
    }
    return res;
}

#define N 5
int main(){
    int a[N];
    int i = 0;
    int n;
    while (i < N)
    {
        printf("Ingresa el valor de a.%i\n", i);
        scanf("%d", &a[i]);
        i++;
    }
    printf("Ingrese un numero \n");
    scanf("%d", &n);
    printf("La suma de los ultimos n elementos del arreglo es: %d\n", sum_end(N, a, n));
}