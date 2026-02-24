#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

#define CANT_FIL        3
#define CANT_COL        3
#define CANT_FIL_COL    4

#define TAM_INT sizeof(int)
int main()
{
    /**Prueba para suma 1.12 y 1.13**/
//    int sumaDPA1, sumaDPA2, sumaDPB1, sumaDPB2;
//    int sumaDSA1, sumaDSA2, sumaDSB1, sumaDSB2;
//    int sumaDP, sumaDS;

//    int** m = (int**)matrizCrear(CANT_FIL, CANT_COL, TAM_INT);
//    matrizInicializar(m, CANT_FIL, CANT_COL, 1, 20);
//    matrizMostrar(m, CANT_FIL, CANT_COL);

//    sumaDPA1 = matrizSumaEncimaDP(m, CANT_FIL, CANT_COL);
//    sumaDPA2 = matrizSumaEncimaDPIncluido(m, CANT_FIL, CANT_COL);
//    sumaDPB1 = matrizSumaDebajoDP(m, CANT_FIL, CANT_COL);
//    sumaDPB2 = matrizSumaDebajoDPIncuido(m, CANT_FIL, CANT_COL);
//
//    printf("Suma encima de DP: %d\n", sumaDPA1);
//    printf("Suma encima de DP incluido: %d\n", sumaDPA2);
//    printf("Suma debajo de DP : %d\n", sumaDPB1);
//    printf("Suma debajo de DP incluido: %d\n", sumaDPB2);

//    sumaDSA1 = matrizSumaEncimaDS(m, CANT_FIL, CANT_COL);
//    sumaDSA2 = matrizSumaEncimaDSIncluido(m, CANT_FIL, CANT_COL);
//    sumaDSB1 = matrizSumaDebajoDS(m, CANT_FIL, CANT_COL);
//    sumaDSB2 = matrizSumaDebajoDSIncluido(m, CANT_FIL, CANT_COL);
//
//    printf("Suma encima de DS: %d\n", sumaDSA1);
//    printf("Suma encima de DS incluido: %d\n", sumaDSA2);
//    printf("Suma debajo de DS: %d\n", sumaDSB1);
//    printf("Suma debajo de DS incluido: %d\n", sumaDSB2);
//
//    sumaDP = matrizSumaDP(m, CANT_FIL, CANT_COL);
//    sumaDS = matrizSumaDS(m, CANT_FIL, CANT_COL);
//
//    printf("Suma diagonal principal: %d\n", sumaDP);
//    printf("Suma diagonal secundaria: %d\n", sumaDS);

//    matrizDestruir((void**)m, CANT_FIL);

    /**Prueba para matriz identidad**/
//    int** identidad = (int**)matrizCrear(CANT_FIL, CANT_COL, TAM_INT);
//    matrizInicializarIdentidad(identidad, CANT_FIL, CANT_COL, false);
//    matrizMostrar((int**)identidad, CANT_FIL, CANT_COL);
//
//    if(esMatrizIdentidad((int**)identidad, CANT_FIL, CANT_COL))
//    {
//        puts("Es matriz identidad");
//    }else
//    {
//        puts("No es matriz identidad");
//    }
//
//    matrizDestruir((void**)identidad, CANT_FIL);

    /**Prueba para matriz simetrica**/
//    int** simetria = (int**)matrizCrear(CANT_FIL, CANT_COL, TAM_INT);
//    matrizInicializarSimetrica(simetria, CANT_FIL, CANT_COL,0, 100, false);
//    matrizMostrar((int**)simetria, CANT_FIL, CANT_COL);
//
//    if(esMatrizSimetrica((int**)simetria, CANT_FIL, CANT_COL))
//    {
//        puts("Es matriz simetrica");
//    }else
//    {
//        puts("No es matriz simetrica");
//    }
//
//    matrizDestruir((void**)simetria, CANT_FIL);

    /**Prueba para transponer matriz**/
//    int** mt = NULL;
//    int** transponer = (int**)matrizCrear(CANT_FIL, CANT_COL, TAM_INT);
//    matrizInicializar(transponer, CANT_FIL, CANT_COL, 0, 100);
//
//    puts("---Matriz original---");
//    matrizMostrar((int**)transponer, CANT_FIL, CANT_COL);
//
//    mt = matrizTransponer(transponer, CANT_FIL, CANT_COL);
//
//    if(mt)
//    {
//        puts("---Matriz transpuesta---");
//        matrizMostrar((int**)mt, CANT_FIL, CANT_COL);
//
//        matrizDestruir((void**)mt, CANT_COL);
//    }else
//    {
//        puts("ERROR: No se pudo crear la matriz");
//    }
//
//    matrizDestruir((void**)transponer, CANT_FIL);

    /**Prueba para matriz producto*/
    int** m1 = (int**)matrizCrear(CANT_FIL, CANT_FIL_COL, TAM_INT);
    matrizInicializar(m1, CANT_FIL, CANT_FIL_COL, 1, 2);

    puts("---Matriz 1---");
    matrizMostrar(m1, CANT_FIL, CANT_FIL_COL);

    int** m2 = (int**)matrizCrear(CANT_FIL_COL, CANT_COL, TAM_INT);
    matrizInicializar(m2, CANT_FIL, CANT_COL, 1, 2);

    puts("---Matriz 2---");
    matrizMostrar(m2, CANT_FIL_COL, CANT_COL);

    int** mp = matrizProducto(m1, m2, CANT_FIL, CANT_COL, CANT_FIL_COL);

    if(mp)
    {
        puts("---Producto de matriz---");
        matrizMostrar(mp, CANT_FIL, CANT_COL);
        matrizDestruir((void**)mp, CANT_FIL);
    }
    matrizDestruir((void**)m1, CANT_FIL);
    matrizDestruir((void**)m2, CANT_FIL_COL);


    return 0;
}
