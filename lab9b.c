#include <stdio.h>
#include <stdbool.h> 

int main(void) {
    int A[4];
    int i, c;
    printf("Ingresa el valor de i\n");
    scanf("%d", &i);
    printf("Ingresa el valor de c\n");
    scanf("%d", &c);
    i = 0;
    c = 0;
    printf("Ingresa el valor de A.0\n");
    scanf("%d", &A[0]);
    printf("Ingresa el valor de A.1\n");
    scanf("%d", &A[1]);
    printf("Ingresa el valor de A.2\n");
    scanf("%d", &A[2]);
    printf("Ingresa el valor de A.3\n");
    scanf("%d", &A[3]);
    while (i<4)
    {
        if (A[i]>0)
        {
            c = c + 1;
        } else {
            ;
        }
        i = i+1;
    }
    return 0;
}
