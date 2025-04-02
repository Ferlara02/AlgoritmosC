#include <assert.h>
#include <stdio.h>
#include <stdbool.h> 

int main(void) {
    int x, y, res;
    printf("Ingresa el valor de x\n");
    scanf("%d", &x);
    printf("Ingresa el valor de y\n");
    scanf("%d", &y);
    assert(true);
    if (x>=y){
        res = y;
    } else if (x < y) {
        res = x;
    }
    assert( (res = x) || (res = y));
}