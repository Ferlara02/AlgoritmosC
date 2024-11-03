#include <stdio.h>
#include <stdbool.h> 
#include <assert.h>

struct div_t {
    int cociente;
    int resto;
};

struct div_t division(int x, int y) {
    struct div_t resultado;
    resultado.cociente = 0;
    resultado.resto = x;

    // Restar repetitivamente y de x hasta que x sea menor que y
    while (resultado.resto >= y) {
        resultado.resto -= y;
        resultado.cociente++;
    }
    
    return resultado;
}

int main(void) {
    int x;
    int y;
    printf("Ingrese el dividendo: \n");
    scanf("%d", &x);
    printf("Ingrese el divisor: \n");
    scanf("%d", &y);
    assert(y>0);
    if (y == 0)
    {
        printf("ERROR: Divisor no puede ser 0\n");
    } else {
        struct div_t resultado = division(x, y);
        assert(resultado.resto >= 0 && resultado.resto < x);
        printf("El resto: %d, y el cociente: %d\n", resultado.resto, resultado.cociente);
    }
    
}
