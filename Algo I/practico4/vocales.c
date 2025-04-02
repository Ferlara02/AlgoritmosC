#include <stdio.h>
#include <stdbool.h> 

bool es_vocal(char letra) {
    int i = 0;
    int vocales[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    bool result = false;
    while (i<10 && !result){
        result = letra == vocales[i];
        i++;
    }
    return result;
}

char pedir_vocal() {
    char vocal;
    printf("escribe la letra\n");
    scanf("%c",&vocal);
    return vocal;
}

int main(void) {
    char letra;
    letra = pedir_vocal();
    if (es_vocal(letra)) {
        printf("La letra SI es una vocal\n");
    } else {
        printf("La letra NO es una vocal\n");
    }
    return 0;
}