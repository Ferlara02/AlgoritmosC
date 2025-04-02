#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    unsigned int k = 0;
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;

    while (k < length) {
        res.is_upperbound = res.is_upperbound && value >= arr[k];
        res.is_lowerbound = res.is_lowerbound && value <= arr[k];
        res.exists = res.exists || value == arr[k];

        if (value == arr[k]) {
            res.where = k;
        }
        k++;
    }
    return res;
}

int main(void) {
    int a[ARRAY_SIZE]; 
    int k = 0;
    while (k < ARRAY_SIZE) {
        printf("Ingresa el valor de a.%i\n", k);
        scanf("%d", &a[k]);
        k++;
    }
    int value;
    printf("Ingrese un valor");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    printf("cota superior %d\n", result.is_upperbound); // Imprime 1
    printf("cota inferior %d\n", result.is_lowerbound); // Imprime 0
    printf("existe? %u\n", result.exists);
    if (result.exists) {
        printf("¿que posicion? %u\n", result.where);   
    }        
    return EXIT_SUCCESS;
}

