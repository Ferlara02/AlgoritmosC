#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

struct _list {
    elem elem;
    struct _list *next;
};

list empty(){
    list l = NULL;
    return l;
}

list addl(elem e, list l){
    list p;
    p = malloc(sizeof(struct _list));
    p->elem = e;
    p->next = l;
    l = p;

    return l;
}

list destroy(list l){
    list p;
    while(l != NULL) {
        p = l;
        l = l->next;
        free(p);
    }
    return l;
}

bool is_empty(list l){
    return l == NULL;
}

elem head(list l){
    assert(!is_empty(l));
    elem e = l->elem;
    return e;
}

list tail(list l){
    assert(!is_empty(l));
    list p;
    p = l;
    l = l->next;
    free(p);

    return l;
}

list addr(list l, elem e){
    list p, q;
    q = malloc(sizeof(struct _list));
    q->elem = e;
    q->next = NULL;
    if(!is_empty(l)){
        p = l;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = q;
    } else {
        l = q;
    }
    return l;   
}

int length(list l){
    list p = l;
    int n = 0;
    while (p != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}

list concat(list l1, list l2){
    list p;
    list q;
    q = copy_list(l2);
    
    if(!is_empty(l1)) {
        p = l1;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = q;
    } else {
        l1 = q;
    }

    return l1;
}

/*{- PRE: length(l) > n -}*/
elem index(list l, int n){
    assert(length(l) > n);
    list p = l;
    elem e;
    if(n>=1) {
        for (int i = 0; i < n; i++)
        {
            p = p->next;
        }
    }
    e = p->elem;
    return e;
}


list take(list l,  int n){
  int i=0;
  list p=NULL, q=NULL;
  if(!is_empty(l)){
    if(n==0){
      destroy(l);
       l=NULL;
    }
    else{
      p=l;
      while(p->next != NULL && i<(n-1)){
        p=p->next;
        i++;
      }
      q=p->next;
      p->next=NULL;
      while (q != NULL) {
        p = q;
        q = q->next;
        free(p);
      }
    }
  return l;
  }
}

list drop(list l, int n){
    list p;
    int i = 0;
    while (i<n && !is_empty(l))
    {
        p = l;
        l = l->next;
        free(p);
        i++;
    }

    return l;
}

list copy_list(list l){
    list p, q, l2;
    if(l == NULL) {
        l2 = empty();
    } else {
        l2 = malloc(sizeof(struct _list));
        l2->elem = l->elem;
        p = l->next;
        q = l2;
        while(p!=NULL){
            q->next = malloc(sizeof(struct _list));
            q = q->next;
            q->elem = p->elem;
            p = p->next;
        }
        q->next = NULL;
    }

    return l2;
}
