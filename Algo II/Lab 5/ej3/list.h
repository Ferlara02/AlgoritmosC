#ifndef _LIST_H
#define _LIST_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* list as a pointer to structs to guarantee encapsulation */
typedef struct node_of_T *list;
typedef int list_elem;

/* Constructores */
list empty();
/* crea lista vacia*/
list addl(list_elem e, list l);

list destroy(list l);

/* Operations */

bool is_empty(list l);

/*{PRE: not is_empty(l) }*/
list_elem head(list l);

/*{PRE: not is_empty(l) }*/
list tail(list l);

list addr(list l, list_elem e);

int length(list l);

list concat(list l1, list l2);

/*{- PRE: length(l) > n -}*/
list_elem index(list l, int n);

list take(list l, int n);

list drop(list l, int n);

list copy_list(list l);


#endif