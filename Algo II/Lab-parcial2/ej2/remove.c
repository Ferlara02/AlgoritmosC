#include "remove.h"

/**
 * @brief Devuelve en UNA NUEVA lista el resultado de eliminar todas las
 * ocurrencias de `e` en `l`
 *
 */

 
list remove_elem(list l, elem e) {
    //Crea una nueva lista vacía:
    list l2 = empty(); 
    int length_l = length(l); //obtiene el largo de l
    int i = 0;
    elem aux;
    
    //se itera hasta la ultima pos. de l
    while(i < length_l) { 
        //se obtiene el i-esimo elem. de l.
        aux = index(l, i); 
        if(aux != e) {
            //solo si ese elem. != e, se agrega:
            l2 = addr(l2, aux);
        }
        i++;
    }

    return l2;
}
