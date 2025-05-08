#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    data_t *p;
    p = malloc(sizeof(messi));
    strcpy(p->name, "Leo Messi");
    p->age = 36;
    p->height = 169;
    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", 
           sizeof(messi.name), 
           sizeof(messi.age), 
           sizeof(messi.height), 
           sizeof(messi));

    
     
    printf("La dirección de memoria apuntada por messi-height es: %p\n", (void *) &messi.height);
    printf("La dirección de memoria apuntada por messi-age es: %p\n", (void *) &messi.age);
    printf("La dirección de memoria apuntada por messi-name es: %p\n", (void *) &messi.name);
    printf("La dirección de memoria apuntada por messi es: %p\n", (void *) &messi);
    printf("La dirección de memoria apuntada por messi UINT es: %lu\n", (uintptr_t) &messi);

    printf("%s\n", p->name);
    
  
    free(p);
    p = NULL;
    return EXIT_SUCCESS;
}
