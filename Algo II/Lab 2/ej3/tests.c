#include <stdbool.h>
#include <stdio.h>
#include "cima_log.h"

#define MAX_LENGTH 10
#define N_TESTCASES_CIMA 10

int main() {
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
        { {10}, 1, 0 }                              // único elemento.
    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima_log(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
