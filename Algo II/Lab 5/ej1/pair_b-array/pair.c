#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"
#include <assert.h>

pair_t pair_new(int x, int y){
    pair_t a;
    a.values[0] = x;
    a.values[1] = y;

    return a;

}

int pair_first(pair_t p){
    return p.values[0];
}

int pair_second(pair_t p){
    return p.values[1];
}
pair_t pair_swapped(pair_t p){
    pair_t a;
    a.values[0] = p.values[1];
    a.values[1] = p.values[0];

    return a;
}

pair_t pair_destroy(pair_t p){
    return p;
}