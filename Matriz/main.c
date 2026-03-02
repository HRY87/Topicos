#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{
//    int** matriz = (int**)crearMatriz(ORDEN, ORDEN, sizeof(int));
//
//    if(!matriz)
//    {
//        return SIN_MEM;
//    }
//
//    cargarMatriz(matriz, ORDEN, ORDEN);
//
//    mostrarMatriz(matriz, ORDEN, ORDEN);
//
//    int sumDP = sumaDiagonalPrincipal(matriz, ORDEN);
//
//    printf("Suma DP: %d\n", sumDP);
//
//    eliminarMatriz((void**)matriz, ORDEN);

    int** mat1 = (int**)crearMatriz(2, 4, sizeof(int));
    int** mat2 = (int**)crearMatriz(4, 3, sizeof(int));


    cargarMatriz(mat1, 2, 4);
    cargarMatriz(mat2, 4, 3);

    int** mp = productoMatrices(mat1, mat2, 2, 4, 3);

    mostrarMatriz(mp, 2, 3);

    eliminarMatriz((void**)mat1, 2);
    eliminarMatriz((void**)mat2, 4);
    eliminarMatriz((void**)mp, 2);

    return 0;
}
