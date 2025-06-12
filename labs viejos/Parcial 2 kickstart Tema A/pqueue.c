#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "character/character.h"
#include "pqueue.h"

/* ============================================================================
STRUCTS!
============================================================================ */

struct s_pqueue {
  unsigned int size;
  struct s_node *front;
};

struct s_node {
    Character character;
    float iniciative;
    struct s_node *next_c;
};

/* ============================================================================
INVREP
============================================================================ */

static bool invrep(pqueue q) {
  bool valid = (q != NULL);
  return valid;
}

/* ============================================================================
NEW
============================================================================ */

pqueue pqueue_empty(void) {
  pqueue q = malloc(sizeof(struct s_pqueue));
  q->front = NULL;
  q->size = 0;
  return q;
}

/* ============================================================================
ENQUEUE
============================================================================ */

static float calculate_priority(Character character) {
  float res;
  res = character_agility(character);
  char type = character_ctype(character);
  float mod = 1;
  if(type == agile) {
    mod = 1.5;
  } else if(type == tank) {
    mod = 0.8;
  }
  res = res * mod * character_is_alive(character);
  return res;
}

static struct s_node *create_node(Character character) {
    struct s_node *new_node = NULL;
    if (character != NULL) {
        float priority = calculate_priority(character);
        new_node = malloc(sizeof(struct s_node));
        assert(new_node != NULL);
        new_node->character = character_copy(character); // Copia profunda
        new_node->iniciative = priority;
        new_node->next_c = NULL;
    }
    return new_node;
}


pqueue pqueue_enqueue(pqueue q, Character character) {
    assert(invrep(q));
    struct s_node *new_node = create_node(character);
    float priority = new_node->iniciative;

    if (q->front == NULL || priority > q->front->iniciative) {
        // Insertar al frente
        new_node->next_c = q->front;
        q->front = new_node;
    } else {
        struct s_node *current = q->front;
        // Buscar posición de inserción
        while (current->next_c != NULL && current->next_c->iniciative >= priority) {
            current = current->next_c;
        }
        new_node->next_c = current->next_c;
        current->next_c = new_node;
    }

    q->size++;
    return q;
}

/* ============================================================================
IS EMPTY?
============================================================================ */

bool pqueue_is_empty(pqueue q) {
  return q->size == 0;
}

/* ============================================================================
PEEKS
============================================================================ */

Character pqueue_peek(pqueue q) {
  return q->front->character;
}

float pqueue_peek_priority(pqueue q) {
  return q->front->iniciative;
}

/* ============================================================================
SIZE
============================================================================ */

unsigned int pqueue_size(pqueue q) {
  assert(invrep(q));
  unsigned int size = q->size;
  return size;
}

/* ============================================================================
COPY
============================================================================ */

pqueue pqueue_copy(pqueue q) {
    assert(invrep(q));
    pqueue q_copy = malloc(sizeof(struct s_pqueue));
    q_copy->size = q->size;
    q_copy->front = NULL;

    if (q->size > 0) {
        struct s_node *aux = q->front;
        struct s_node *aux2;

        // Crear el primer nodo
        q_copy->front = create_node(aux->character);
        aux2 = q_copy->front;
        aux = aux->next_c;

        // Copiar el resto
        while (aux != NULL) {
            aux2->next_c = create_node(aux->character);
            aux2 = aux2->next_c;
            aux = aux->next_c;
        }
    }

    return q_copy;
}


/* ============================================================================
DESTROY!
============================================================================ */
static struct s_node *destroy_node(struct s_node *node) {
  assert(node != NULL);
  free(node->character);
  node->character = NULL;
  node->iniciative = 0;
  node->next_c = NULL;
  free(node);
  node = NULL;
  assert(node == NULL);
  return node;
}

pqueue pqueue_dequeue(pqueue q) {
  assert(invrep(q));
  struct s_node *aux = q->front;
  if(q->size > 1) {
    q->front = q->front->next_c;
    aux = destroy_node(aux);
    q->size--;
  } else if(q->size == 1 ) {
    q->front = destroy_node(q->front);
    q->size--;
  }
  return q;
}

pqueue pqueue_destroy(pqueue q) {
  struct s_node *aux = q->front; 
  struct s_node *aux2;
  while(aux != NULL) {
      aux2 = aux;
      aux = aux->next_c;
      aux2 = destroy_node(aux2);
  }
  free(q);
  q=NULL;
  assert(q == NULL);
  return q;
}
