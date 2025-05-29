#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem a[MAX_LENGTH];
    int start;
    int size;
};

list empty() {
    list l;
    l = malloc(sizeof(struct _list));
    l->start = 0;
    l->size = 0;

    return l;
}
list addl(elem e, list l) {
    l->start =(l->start -1 + MAX_LENGTH) % MAX_LENGTH;
    l->a[l->start] = e;
    l->size++;

    return l;
}

bool is_empty(list l) {
    return l->size == 0;
}
//PRECONDITION: !is_empty(l) 
elem head(list l) {
    assert(!is_empty(l));
    return l->a[l->start];
}

//PRECONDITION: !is_empty(l)
list tail(list l) {
    assert(!is_empty(l));
    l->start = (l->start+1) % MAX_LENGTH;
    l->size--;

    return l;
}

list addr(list l, elem e) {
    l->a[(l->start + l->size) % MAX_LENGTH] = e;
    l->size++;

    return l;
}

int length(list l) {
    return l->size;
}

list concat(list l, list l0) {
    if(l->size + l0->size <= MAX_LENGTH) { //preguntar
        for (int i = 0; i < l0->size; i++) {
            int pos_l0 = (l0->start + i) % MAX_LENGTH;
            int insert_pos = (l->start + l->size) % MAX_LENGTH;
            l->a[insert_pos] = l0->a[pos_l0];
            l->size++;
        }
    }

    return l;
}

//PRECONDITION: n < length(l) 
elem index(list l, int n) {
    assert(n < length(l));
    return l->a[(l->start + n) % MAX_LENGTH];
}

list take(list l, int n) {
    if(n > l->size) {
        n = l->size;
    }
    l->size = n;

    return l;
}

list drop(list l, int n) {
    if (n > l->size) {
        n = l->size;  // no puedo eliminar más de los que hay
    }
    l->size -= n;
    l->start = (l->start + n) % MAX_LENGTH;

    return l;
}

list copy_list(list l) {
    list l2;
    l2 = malloc(sizeof(struct _list));
    l2->size = l->size;
    l2->start = l->start;
    for (int i = 0; i < l->size; i++)
    {
        l2->a[(i + l2->start) % MAX_LENGTH] = l->a[(i+l->start) % MAX_LENGTH];
    }
    
    return l2;
}

void destroy_list(list l) {
    free(l);
    l = NULL;
    return l;
}