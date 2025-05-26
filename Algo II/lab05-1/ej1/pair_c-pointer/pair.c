#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"
#include <assert.h>



pair_t pair_new(int x, int y){
    pair_t a;
    a = malloc(sizeof(struct s_pair_t));
    a->fst = x;
    a->snd = y;

    assert(a != NULL && a->fst == x && a->snd == y);
    return a;

}

int pair_first(pair_t p){
    assert(p != NULL);
    return p->fst;
}

int pair_second(pair_t p){
    assert(p != NULL);
    return p->snd;
}

pair_t pair_swapped(pair_t p){
    assert(p != NULL);
    pair_t a;
    a = malloc(sizeof(pair_t));
    a->fst = p->snd;
    a->snd = p->fst;
    assert(pair_first(a) == pair_second(p) && pair_second(a) == pair_first(p));
    return a;
}

pair_t pair_destroy(pair_t p){
    free(p);
    p = NULL;
    return p;
}