#include <stdio.h>
#include <limits.h>

#define N 4  // Número de filas
#define M 4  // Número de columnas

void minimo_f(int a[N][M], int b[N]) {
    for (int i = 0; i < N; i++) {
        int min = INT_MAX;
        for (int k = 0; k < M; k++) {
            if (a[i][k] < min) {
                min = a[i][k];
            }
        }
        b[i] = min;
    }
}

int main() {
    int a[N][M] = {
        {5, 3, 8, 1},
        {7, 2, 9, 4},
        {6, 0, 3, 5},
        {210, 232, 2, -4}
    };
    int b[N];

    minimo_f(a, b);

    printf("Elementos mínimos de cada fila:\n");
    for (int i = 0; i < N; i++) {
        printf("Fila %d: %d\n", i + 1, b[i]);
    }

    return 0;
}
