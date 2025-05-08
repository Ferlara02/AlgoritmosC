#include <stdio.h>
#include <stdlib.h>

void main() {
    int x = 3; 
    // int *p;

    // p = &x;
    // *p = 25;

    int *p;
    p = malloc(sizeof(int));
    *p = 6;
    printf("*p: %d\n", *p);
//---------------------------/

//--------------------------------

    int y = 10;
    y = *(&x); 
    printf("EL valor de y es %d\n", y);


}

//  INDEXACION; 

/* 
    p[n] permite moverse n lugares (de manera lineal) desde la memoria p, por lo que p[0] = p

*/

