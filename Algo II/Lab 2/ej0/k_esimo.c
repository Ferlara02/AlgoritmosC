#include <stdbool.h>
#include "k_esimo.h"
#include <stdio.h>
// FUNCIONES INTERNAS DEL MÓDULO:
int partition(int a[], int izq, int der);
bool goes_before(int x, int y);
void swap(int a[], int i, int j);

/**
 * @brief K-esimo elemento mas chico del arreglo a.
 *
 * Devuelve el elemento del arreglo `a` que quedaría en la celda `a[k]` si el
 * arreglo estuviera ordenado. La función puede modificar el arreglo.
 * Dicho de otra forma, devuelve el k-esimo elemento mas chico del arreglo a.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 * @param k Posicion dentro del arreglo si estuviera ordenado.
 */

int quick_select(int a[], int lft, int rgt, int k) {
    int res;
    int ppiv;
    if(rgt == lft) {
        res = a[lft];
    } else {
        ppiv = partition(a, lft, rgt);
        printf("ppiv: %i\n", a[ppiv]);
        if (ppiv == k) {
            res = a[ppiv];
        } else if (k<ppiv) {
            res = quick_select(a, lft, ppiv-1, k);
        } else {
            res = quick_select(a, ppiv+1, rgt, k);
        }
    } 
    return res;
}

int k_esimo(int a[], int length, int k) {
    int res;
    res = quick_select(a, 0, length-1, k);
    return res;
}



int partition(int a[], int izq, int der) {
    int i, j, ppiv;
    ppiv = izq;
    i = izq + 1;
    j = der;
    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i = i + 1;
        } else if (goes_before(a[ppiv], a[j])) {
            j = j - 1;
        } else {
            swap(a, i, j);
        }
    }

    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

bool goes_before(int x, int y) {
    return x <= y;
}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
