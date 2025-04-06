#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TIENE_CIMA 11
#define N_TESTCASES_CIMA 12

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();

    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    struct testcase tests[N_TESTCASES_TIENE_CIMA] = {
        { {8}, 1, true },                           // único elemento
        { {1, 2, 3, 2, 1}, 5, true },               // cima en el medio
        { {1, 2, 3, 4, 5}, 5, true },              // estrictamente creciente
        { {5, 4, 3, 2, 1}, 5, true },              // estrictamente decreciente
        { {1, 3, 2}, 3, true },                     // cima corta
        { {1, 3, 5, 7, 6, 4, 2}, 7, true },         // cima más al medio
        { {1, 2, 3, 3, 2, 1}, 6, false },           // no estrictamente creciente
        { {1, 2, 4, 4, 3, 1}, 6, false },           // cima plana
        { {2, 3, 4, 3, 5}, 5, false },              // baja y vuelve a subir
        { {1, 5, 9, 7, 6, 2}, 6, true },            // cima normal
        {{5, 4, 3, 7, 4, 3, 2}, 7, false}           // 
    };
    bool result;

    printf("TESTING tiene_cima\n");

    for (int i=0; i < N_TESTCASES_TIENE_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = tiene_cima(tests[i].a, tests[i].length);

        if (result != tests[i].result) {
            printf("FAILED\n");
        } else {
            printf("OK\n");
        }
    }
}

void test_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        { {8}, 1, 0 },                              // único elemento
        { {1, 2, 3, 2, 1}, 5, 2 },                  // cima en 2
        { {1, 3, 2}, 3, 1 },                        // cima en 1
        { {1, 5, 9, 7, 6, 2}, 6, 2 },               // cima en 2
        { {1, 2, 5, 4, 1}, 5, 2 },                  // cima en 2
        { {2, 4, 6, 9, 7, 4, 3}, 7, 3 },            // cima en 3
        { {3, 6, 10, 8, 7, 5, 1}, 7, 2 },           // cima en 2
        { {1, 3, 7, 6, 4, 2, 0}, 7, 2 },            // cima en 2
        { {4, 5, 6, 9, 8, 4}, 6, 3 },               // cima en 3
        { {10}, 1, 0 },                             // unico elemento
        {{1, 2, 3, 4, 5, 6}, 6, 5},                 // cima al final
        {{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 10, 0}    // cima al principio
            
    };

    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }
}
