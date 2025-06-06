#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strfuncs.h"

#define MAX_LENGTH 50

#define SIZEOF_ARRAY(s) (sizeof(s) / sizeof(*s))

int main(void) {
    char user_input[MAX_LENGTH];
    char ignore_chars[] = {' ', '?', '!', ',', '-', '.'};
    char *filtered=NULL;

    printf("Ingrese un texto (no más de %d símbolos) para verificar palíndromo: ", MAX_LENGTH);

    fgets(user_input, MAX_LENGTH, stdin);

    size_t length = string_length(user_input);

    if (length > 0 && user_input[length - 1] == '\n') {
        user_input[length - 1] = '\0';  // Elimina el '\n'
    }

    char *tmp = string_filter(user_input, ignore_chars[0]); //almaceno el primer filtered
    for (unsigned int i = 1; i < SIZEOF_ARRAY(ignore_chars); i++) {
        char *tmp2 = string_filter(tmp, ignore_chars[i]);
        free(tmp); //si no se hacia este free por cada nuevo filtered, habia N memorys leaks
        tmp = tmp2;
    }
    filtered = tmp;

    printf("El texto:\n\n"
            "\"%s\" \n\n"
            "%s un palíndromo.\n\n", user_input, string_is_symmetric(filtered) ? "Es": "NO es");

        
    free(filtered);
    filtered = NULL;
    
    return EXIT_SUCCESS;
}

