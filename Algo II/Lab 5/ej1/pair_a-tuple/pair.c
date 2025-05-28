#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"
#include <assert.h>

pair_t pair_new(int x, int y) {
    pair_t pair;
    pair.fst = x;
    pair.snd = y;

    return pair;
}

int pair_first(pair_t p){
    return p.fst;
}


int pair_second(pair_t p){
    return p.snd;
}

pair_t pair_swapped(pair_t p){
    pair_t q;
    q.fst = p.snd;
    q.snd = p.fst;


    assert(pair_first(q) == pair_second(p) && pair_second(q) == pair_first(p));
    return p;


}

pair_t pair_destroy(pair_t p){
    return p;
}