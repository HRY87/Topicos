#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

#define CANT_FIL        7
#define CANT_COL        9

/**Esto es para producto de matriz para COL1 = FIL2**/
#define CANT_COL_FIL    4



int main()
{
    /**Prueba para el ejercicio 1.20**/
    int puntos[2][TAM_RESULTADOS] = {
        {0, 1, 2, 3, 4, 6},
        {6, 4, 2, 3, 1, 0}
    };
    int puntosAcumulados[ORDEN];

    int** m = matrizCrear(ORDEN, ORDEN);

    matrizInicializarTorneo(m, ORDEN);

    matrizMostrar(m, ORDEN, ORDEN);

    printf("El resultado es: %d\n", validarMatrizTorneo(m, ORDEN, puntos));

    totalizarPuntosPorEquipos(m, ORDEN, puntosAcumulados);

    for(int i = 0; i < ORDEN; i++)
    {
        printf("[%d]: %d\n", i, puntosAcumulados[i]);
    }
    return 0;
}
