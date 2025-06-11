#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include <assert.h>

#include "pokerdeck.h"

struct s_pokerdck {
    int size_deck; //cantidad de cartas

    struct s_node *first;
};

struct s_node {
    cardnum_t num;
    cardsuit_t suit;
    struct s_node *nextcard;
};

typedef struct s_node * node_t;

// Auxiliar dump functions
static void dump_suit(cardsuit_t suit) {
    printf("%s", suit==spades   ? "♠️  ":
                 suit==hearts   ? "♥️  ":
                 suit==diamonds ? "♦️  ":
                 suit==clubs    ? "♣️  ": "???");
}

static void dump_num(cardnum_t num) {
    if (1 < num && num < 11) {
        printf("%-2d", num);
    } else {
        printf("%-2s", num==1 ? "A":
                       num==11 ? "J":
                       num==12 ? "Q":
                       num==13 ? "K": "???");

    }
}

// Representation invariant
static bool invrep(pokerdeck deck) {
    bool valid=false;
    if (deck == NULL) valid = false;

    if (deck->first == NULL) {
        valid = deck->size_deck == 0;
    }

    // verif si la cantidad de nodos coincide con deck->size
    int count = 0;
    node_t current = deck->first;

    while (current != NULL) {
        count++;
        current = current->nextcard;
    }
    valid = count == deck->size_deck;


    return valid;
}

// Creates a single node in dynamic memory with a given card
static node_t create_node(cardnum_t num, cardsuit_t suit) {
    node_t newnode = malloc(sizeof(struct s_node));
    newnode->num = num;
    newnode->suit = suit;
    newnode->nextcard=NULL;
    assert(newnode!=NULL);
    return newnode;
}

// Destroy a single node
static node_t destroy_node(node_t node) {
    free(node);
    node = NULL;
    assert(node==NULL);
    return node;
}

// Public functions of the Abstract Data Type
pokerdeck pokerdeck_empty(void) {
    pokerdeck deck = malloc(sizeof(struct s_pokerdck));
    deck->size_deck = 0;
    deck->first = NULL;


    return deck;
}

bool pokerdeck_is_empty(pokerdeck deck) {
    return deck->size_deck == 0;
}

pokerdeck pokerdeck_add(pokerdeck deck, cardnum_t num, cardsuit_t suit) {
    node_t node = create_node(num, suit);
    node_t aux = deck->first;
    if(deck->size_deck == 0) {
        deck->first = node;
    } else {
        while(aux->nextcard != NULL) {
            aux = aux->nextcard;
        }
        aux->nextcard = node;
    }
    deck->size_deck++;
    return deck;
}

pokerdeck pokerdeck_push(pokerdeck deck,  cardnum_t num, cardsuit_t suit) {
    assert(invrep(deck));
    node_t newnode = create_node(num, suit);
    newnode->nextcard = deck->first;
    deck->first = newnode;
    deck->size_deck++;
    assert(invrep(deck) && !pokerdeck_is_empty(deck));
    return deck;
}

pokerdeck pokerdeck_pop(pokerdeck deck, cardnum_t *popped_num, cardsuit_t *popped_suit) {
    assert(deck != NULL);
    assert(deck->first != NULL); // No deberías hacer pop sobre una lista vacía

    node_t temp = deck->first;

    if (popped_num != NULL) *popped_num = temp->num;
    if (popped_suit != NULL) *popped_suit = temp->suit;

    deck->first = temp->nextcard;
    temp = destroy_node(temp);

    deck->size_deck--;
    return deck;
}

unsigned int pokerdeck_length(pokerdeck deck) {
    return deck->size_deck;
}

pokerdeck pokerdeck_remove(pokerdeck deck, cardnum_t num, cardsuit_t suit) {
    assert(invrep(deck));
    node_t aux = deck->first;
    node_t aux2;
    if(deck->size_deck > 0){
        //verifico la primera carta del mazo
        if(aux->suit == suit && aux->num == num) {
            deck->first = aux->nextcard;
            aux = destroy_node(aux);
            deck->size_deck--;
        }
        //verifico las demás (si es que el mazo es de mas de 1 carta)
        while((aux != NULL && aux->nextcard != NULL) && (aux->nextcard->suit != suit && aux->nextcard->num != num)) {
            aux = aux->nextcard;
        }
        if(aux != NULL && aux->nextcard != NULL) {
            aux2 = aux->nextcard;
            aux->nextcard = aux->nextcard->nextcard;
            aux2 = destroy_node(aux2);
            deck->size_deck--;
        }
        
    }

    return deck;
}

unsigned int pokerdeck_count(pokerdeck deck, cardsuit_t suit) {
    unsigned int res = 0;
    node_t aux = deck->first;
    while(aux != NULL) {
        if(aux->suit == suit) res++;
        aux = aux->nextcard;
    }

    return res;
}

struct card * pokerdeck_to_array(pokerdeck deck) {
    assert(deck != NULL);
    assert(invrep(deck));  

    // 1. Reservar memoria para el arreglo dinámico
    struct card *array = malloc(deck->size_deck * sizeof(struct card));
    assert(array != NULL);  // Siempre conviene chequear

    // 2. Recorrer la lista y llenar el arreglo
    node_t current = deck->first;
    int i = 0;
    while (current != NULL && i < deck->size_deck) {
        array[i].num = current->num;
        array[i].suit = current->suit;
        current = current->nextcard;
        i++;
    }

    // 3. Retornar el arreglo dinámico
    return array;
}


void card_dump(cardnum_t num, cardsuit_t suit) {
    printf("|");
    dump_num(num);
    printf(" ");
    dump_suit(suit);
    printf("|");
}

void pokerdeck_dump(pokerdeck deck) {
    assert(invrep(deck));
    node_t node = deck->first;
    while (node != NULL) {
        card_dump(node->num, node->suit);
        printf(" ");
        node = node->nextcard;
    }
    printf("\n");
}

pokerdeck pokerdeck_destroy(pokerdeck deck) {
    node_t aux = deck->first;
    node_t aux2;
    while(aux != NULL) {
        aux2 = aux;
        aux = aux->nextcard;
        aux2 = destroy_node(aux2);
    }
    free(deck);
    deck=NULL;
    return deck;
}

