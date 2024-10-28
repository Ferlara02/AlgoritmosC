#include <stdio.h>
#include <stdbool.h> 


typedef struct {
    int cociente;
    int resto;
} div_t;

div_t division(int x, int y){
    div_t mod;
    
    mod.resto = 0;
    mod.cociente = 1;

    int r = mod.resto;
    int q = mod.cociente;
    int i = 0;
    while (i<3) {
        i++;
                
    }

    return mod;
    
}

int main(void) {
    int x;
    int y;
    printf("Ingrese el dividendo: \n");
    scanf("%d", &x);
    printf("Ingrese el divisor: \n");
    scanf("%d", &y);

    if (y == 0)
    {
        printf("ERROR: Divisor no puede ser 0\n");
    } else {
        div_t mod = division(x, y);
        int resto = mod.resto;
        int cociente = mod.cociente; 
        printf("El resto y el cociente son; %d %d\n", resto, cociente);
    }
    
}
