#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if(x>=0) {
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a=-10, res=0;  // No modificar esta

    // --- No se deben declarar variables nuevas ---
    absolute(a, &res);

    //
    // Completar aquí
    //
    assert(res >= 0 && (res == a || res == -a));

    printf("res: %d\n", res);
    return EXIT_SUCCESS;
}

