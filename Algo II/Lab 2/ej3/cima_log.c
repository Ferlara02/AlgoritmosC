#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
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

//cima con busqueda binaria, implementacion recursiva:

int cima_log_rec(int a[], int lft, int rgt) {
    int pos;
    int mid;
    if(lft>rgt) {
        pos = 0;
    } else {
        mid = (lft+rgt) / 2;
        if(a[mid-1] < a[mid] && a[mid] < a[mid+1]) {
            pos = cima_log_rec(a, mid+1, rgt);
        } else if(a[mid-1] < a[mid] && a[mid]> a[mid+1]) {
            pos = mid;
        } else {
            pos = cima_log_rec(a, lft, mid-1);
        }
    }
    return pos;
}

int cima_log(int a[], int length) {
   int pos = cima_log_rec(a, 0, length-1);
   return pos;
}

