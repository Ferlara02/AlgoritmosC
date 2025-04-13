#include <stdio.h>

#define ANIOS 3
#define MESES 2
#define DIAS 2
#define CLIMAS 4

#define CANT_ANIOS ANIOS
#define ANIO_INICIAL 1980

typedef enum {
    ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO,
    JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE
} Mes;

typedef enum {
    TEMP, TEMPMAX, TEMPMIN, PRES, HUM, PREC
} Clima;


// Función que calcula la temperatura máxima anual
void temp_max_anio(int med[ANIOS][MESES][DIAS][CLIMAS], int a[ANIOS]) {
    for (int i = 0; i < ANIOS; i++) {
        int max_temp = 0;
        for (int k = 0; k < MESES; k++) {
            for (int m = 0; m < DIAS; m++) {
                if (med[i][k][m][0] > max_temp) {
                    max_temp = med[i][k][m][0];
                }
            }
        }
        a[i] = max_temp;
    }
}

int main() {
    int resultado[ANIOS];

    int mediciones[ANIOS][MESES][DIAS][CLIMAS] = {
        { // Año 0
            { {30, 0, 0, 0}, {32, 0, 0, 0} }, // Mes 0
            { {28, 0, 0, 0}, {35, 0, 0, 0} }  // Mes 1
        },
        { // Año 1
            { {36, 0, 0, 0}, {31, 0, 0, 0} },
            { {29, 0, 0, 0}, {33, 0, 0, 0} }
        },
        { // Año 2
            { {27, 0, 0, 0}, {26, 0, 0, 0} },
            { {25, 0, 0, 0}, {24, 0, 0, 0} }
        }
    };

    temp_max_anio(mediciones, resultado);

    for (int i = 0; i < CANT_ANIOS; i++) {
        printf("Año %d: TempMax = %dC\n", ANIO_INICIAL + i, resultado[i]); // NOTAR %d
    }

    return 0;
}
