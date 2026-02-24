#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "cadena.h"

#define MAX_PARES   50

int main()
{
    char matriz[MAX_PARES][2][MAX_CAD];

    int cant = cargarParesMatriz(matriz, MAX_PARES);

    printf("Se cargaron %d pares\n", cant);

    return 0;
}
