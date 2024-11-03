#include <stdio.h>
#include <stdbool.h> 
#include <assert.h>

bool todosPares(int tam, int a[]) {
    int i = 0;
    bool res = true;
    while (i<tam) {
        res = res && (a[i] % 2 == 0);
        i++;
    }

    return res;
}

bool existeMultiplo(int m, int tam, int a[]) {
    int i = 0;
    bool res = false;
    while(i<tam) {
        res = res || (a[i] % m == 0);
        i++;
    }

    return res;
}

#define N 5
int main(void) {
    int i = 0;
    int a[N];
    while (i < N)
    {
        printf("Ingresa el valor de a.%i\n", i);
        scanf("%d", &a[i]);
        i++;
    }
    int x;
    printf("Si desea ejecutar todosPares ingrese 1, si desea ejecutar existeMultiplo ingrese 2 \n");
    scanf("%d", &x);
    if (x != 1 && x != 2) {
        printf("Ingrese una opcion válida!");
    } else if (x == 1) {
        printf("El arreglo tiene todos elementos pares?: %s\n", todosPares(N, a) ? "true" : "false");
    } else if(x == 2) {
        int m;
        printf("Ingrese el valor para m \n");
        scanf("%d", &m);
        printf("Existe en el arreglo un multiplo de %d?: %s\n", m, existeMultiplo(m, N, a) ? "true" : "false");
    }
}