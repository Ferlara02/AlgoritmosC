#include <stdio.h>
#include <stdlib.h>
#include "cima.h"

int main(void) {
    int a[] = {1, 2, 3, 4, -123};
    int length = 5;
    int result;

    result = tiene_cima(a, length);


    if(result) {
        printf("Tiene cima?: si");
    } else {
        printf("Tiene cima?: no");
    }   


    return EXIT_SUCCESS;
}
