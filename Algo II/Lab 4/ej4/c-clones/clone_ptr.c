#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ansicolors.h"

#define MAX_LENGTH 1820

char *string_clone(const char *str, size_t length) {
    //length toma valor 1812 (gdb)

    /*string_clone CORREGIDO: */
    char *output=malloc(length+1); //+1 para el '\0'
    for (size_t i=0; i<length;i++) {
        output[i] = str[i];
    }

    output[length] = '\0'; //esto es equivalente a *(output + length) = '\0', es decir, estoy modificando el valor ALOJADO en output+length
    return output;
}
/*El problema de string_clone es que al puntero output nunca se le reserva memoria, 
apunta a una variable local (clon) que sólo vive en la funcion string_clone. 
Es un puntero que solo vive en memoria estática, lo cual es contradictorio*/

int main(void) {
    char *original="";


    char *copy=NULL;

    //copy = string_clone(original, sizeof(original)/sizeof(*original)); --> linea sin corregir
    copy = string_clone(original, sizeof(*original)); //linea corregida
    printf("Original:\n" ANSI_CYAN
            " %s\n", original);
    copy[0] = 'A';
    copy[1] = ' ';
    copy[2] = 'l';
    copy[3] = 'o';
    copy[4] = 'n';
    copy[5] = 'g';
    printf("Copia   :\n" ANSI_CYAN
           " %s\n", copy);

    free(copy); //liberacion para evitar memory leaks
    copy = NULL;       
    return EXIT_SUCCESS;
}
//Esto no funciona porque ahora original es un puntero
//Entonces cuando calculamos el length para pasarle como parámetro a string_clone,
//sizeof(original) = sizeof de un puntero, que es de 8bytes 
//y luego sizeof(*original) = sizeof del valor alojado, que es un char (1)
//Por lo tanto, length = 8, y como *original es vacío, luego en string_clone con el for se accede a valores de str[i] que no existen.