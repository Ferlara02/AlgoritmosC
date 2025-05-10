#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "strfuncs.h"

size_t string_length(const char *str) {
    size_t i;
    i=0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

char *string_filter(const char *str, char c){
    char *res_char;
    size_t length = string_length(str); 
    res_char = malloc(sizeof(char)*(length+1));
    int i = 0;
    int j = 0;
    while(i<=length) {
        if(str[i] != c) {
            res_char[j] = str[i];
            j++;
        }
        i++;
    }

    return  res_char;
}

bool string_is_symmetric(const char *str){
    bool res = true;
    size_t i = 0;
    size_t length = string_length(str);
    size_t j = 0;
    if(length>0){
        j = length-1;
    }
    while (res && i<j) {
        res = res && str[i] == str[j];
        i++;
        j--;
    }

    return res;
}