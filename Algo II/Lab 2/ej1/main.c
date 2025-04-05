#include <stdio.h>
#include <stdlib.h>
#include "cima.h"

int main(void) {
    int a[] = {1, 2, 3, 2, 1, 0};
    int length = 6;
    int result;

    result = tiene_cima(a, length);


    if(result) {
        printf("Tiene cima?: si");
    } else {
        printf("Tiene cima?: no");
    }   


    return EXIT_SUCCESS;
}
