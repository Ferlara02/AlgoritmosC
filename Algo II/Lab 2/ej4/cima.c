#include <stdio.h>
#include <stdbool.h>
#include "cima.h"

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */


bool tiene_cima(int a[], int length) {
    int i = 1;
    
    while(i<length-1 && a[i-1] < a[i]) { 
        i++;
    }

    if(i>1){
        while(i<length && a[i-1]>a[i]) {
            i++;
        }
    }

    
    return i==length;
}


/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */


int cima(int a[], int length) {
    int pos = 0;
    while(pos < length-1 && a[pos] < a[pos+1]) {
        pos++;
    }
    return pos;
}
