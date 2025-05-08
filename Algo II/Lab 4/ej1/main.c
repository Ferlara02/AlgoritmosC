/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */

 //int *p; es del tipo puntero a int.
int main(void) {

    int x = 1;

    //&x devuelve la direccion de memoria en la que esta alojada x=1 

    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    int *p; 
    p = &x;
    *p = 9;

    person_t *g; 
    g = &m; 
    g->age = 100;
    g->name_initial = 'F';

    p = &a[1];
    *p = 42;

    /* Completar aquí:
       Al finalizar la ejecución las variables deben tener los siguientes valores
       x = 9
       m = (100, F)
       a[1] = 42

       Las restricciones son:
       - No usar las variables 'x', 'm' y 'a' en la parte izquierda de alguna asignación.
       - Se pueden agregar líneas de código, pero no modificar las que ya existen.
       - Se pueden declarar hasta 2 punteros.
       AYUDA: podes usar GDB para consultares valores de variables y la dirección de memoria donde estan alojadas.
    */

    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}

