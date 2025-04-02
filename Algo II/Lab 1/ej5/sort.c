#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    unsigned int i = izq + 1, j = der, ppiv = izq;

    while (i <= j) {
        // Mueve i hacia la derecha mientras a[i] sea menor que el pivote
        if (goes_before(a[i], a[ppiv])) {
            i++;
        }
        // Mueve j hacia la izquierda mientras a[j] sea mayor que el pivote
        else if (goes_before(a[ppiv], a[j])) {
            j = j-1;
        }
        // Si los elementos a[i] y a[j] están fuera de lugar, los intercambiamos
        else {
            swap(a, i, j);
        }
    }

    // Colocamos el pivote en su posición correcta
    swap(a, ppiv, j);
    ppiv = j;
    return ppiv; // Retornamos la posición del pivote
}
    

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der, unsigned int length) {
    unsigned int ppiv;
    array_dump(a, length);
    if(der > izq ) {
        array_dump(a, length);
        ppiv = partition(a, izq, der);
        array_dump(a, length);
        quick_sort_rec(a, izq, ppiv > 0? ppiv - 1 : 0, length);
        quick_sort_rec(a, ppiv+1, der, length);
    }
}



void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, length);
}


