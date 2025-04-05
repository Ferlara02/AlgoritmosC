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
    int i = 0;
    int j = length -1;
    bool sort1 = true;
    bool sort2 = true;

    while(sort1 && i<j-1) {
        sort1 = sort1 && a[i] < a[i+1];
        i++;
    }
    while(sort2 && i<j-1) {
        sort2 = sort2 && a[j] < a[j-1]; 
        j--;
    }

    return (i==j-1);
}


// bool tiene_cima(int a[], int length) {
//     int i = 0;
//     bool res = false;
//     while(i<length-2 && !res) {
//         res = res || (a[i] < a[i+1] && a[i+1] > a[i+2]);
//         i++;
//     }

//     return res;
// }



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
    int pos = 1;
    bool res = false;
    while(pos < length-1 && !res) {
        res = res || (a[pos-1] < a[pos] && a[pos] > a[pos+1]);
        pos++;
    }

    return pos;
}
