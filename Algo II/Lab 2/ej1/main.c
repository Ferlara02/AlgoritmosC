#include <stdio.h>
#include <stdlib.h>
#include "cima.h"

int main(void) {
    int a[] = {-2, 8, 9, 510, 10000, 1};
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
