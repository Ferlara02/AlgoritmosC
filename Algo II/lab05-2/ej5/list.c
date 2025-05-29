#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem elems[MAX_LENGTH];
    int size;
};


list empty() {
    list l;
    l = malloc(sizeof(struct _list));
    l->size = 0;

    return l;
}

list addl(elem e, list l) {
    int size_list;
    l->size++;
    size_list = l->size;
    for (int i = size_list-1; i > 0; i--)
    {
        l->elems[i+1] = l->elems[i];
    }

    l->elems[0] = e;
    

    return l;
}

bool is_empty(list l){
    return l->size==0;
}

elem head(list l){
    assert(!is_empty(l));
    return l->elems[0];
}

list tail(list l) {
    for (int i = 0; i < l->size-1; i++)
    {
        l->elems[i] = l->elems[i+1];
    }
    
    l->size--;

    return l;
}

list addr(list l, elem e) {
    l->size++; 
    l->elems[l->size] = e;
    
    return l;
}

int length(list l) {

    return l->size;
}


/*{PRE: l->size + l0->size <= MAX_SIZE}*/
list concat(list l, list l0) {
    int new_size = l->size + l0->size;
    for (int i = l->size+1; i < new_size; i++)
    {
        l->elems[i] = l0->elems[i-l->size];
    }
    l->size += l0->size;
    return l;
}

elem index(list l, int n) {
    assert(n<l->size);
    elem e = l->elems[n];
    return e; 
}

list take(list l, int n) {
    if(n>l->size){
        n = l->size;
    }
    l->size = n;
    return l;
}

list drop(list l, int n) {
    int i, k;
    k = n+1;
    i = 0;
    while (k <= l->size){
        l->elems[i] = l->elems[k];
        k = k+1;
        i = i+1;
    }
    l->size = l->size - n;
}

list copy_list(list l) {
    list l2;
    l2 = empty();
    l2->size = l->size;
    for (int i = 0; i < l->size; i++)
    {
        l2->elems[i] = l->elems[i];
    }
    

    return l2;
}

void destroy_list(list l) {
    free(l);
}