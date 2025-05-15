#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
    int i;
    List list;
    Node *a_node;
    list = malloc(sizeof(Node));
    a_node = list;
    i = 2;
    while(i>0){
        a_node->data = i*10;
        a_node->next = malloc(sizeof(Node));
        a_node = a_node->next;
        i--;
    } 
    a_node->data = 0;
    a_node->next = NULL;
    a_node = NULL;
    return list;
}

/**
 * @brief Elimina el primer elemento de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
List tail_example(List xs) {
    List a_node = xs;
    xs = xs->next; 
    free(a_node);
    a_node = NULL;

    return xs;
}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    printf("Lista antes del tail: ");

    show_list(my_list);

    my_list = tail_example(my_list);

    printf("Lista después del tail: ");

    show_list(my_list);

    return 0;
}
