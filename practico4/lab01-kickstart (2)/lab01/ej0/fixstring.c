#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int i;
    i=0;
    while (s[i] != '\0')
    {
        i++;
    }

    return i;
    
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool is_eq = true;

    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
        i++;
    }
    is_eq = s1[i] == s2[i];
    return is_eq;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool res = true;
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    res = s1[i] <= s2[i];
    return res;
}
