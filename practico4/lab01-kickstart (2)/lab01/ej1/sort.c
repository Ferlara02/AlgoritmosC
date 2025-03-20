#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) {
   unsigned int j;
   j = i;
   while(j>0 && goes_before(a[j], a[j-1])){
    for (int c = 0; i < length; i++)
    {
        printf("%d", a[c]);
    }
    swap(a, j-1, j);
    j = j-1;
   }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
    }
}
