#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdbool.h>

void** matrizCrear(int fil, int col, size_t tamElem);
void matrizDestruir(void** m, int fil);
void matrizMostrar(int** m, int fil, int col);
void matrizInicializar(int** m, int fil, int col, int limInf, int limSup);

/**Ejercicio 1.12**/
/**Diagonal principal**/
int matrizSumaEncimaDP(int** m, int fil, int col);
int matrizSumaDebajoDP(int** m, int fil, int col);
int matrizSumaEncimaDPIncluido(int** m, int fil, int col);
int matrizSumaDebajoDPIncuido(int** m, int fil, int col);
/**Diagonal secundaria**/
int matrizSumaEncimaDS(int** m, int fil, int col);
int matrizSumaDebajoDS(int** m, int fil, int col);
int matrizSumaEncimaDSIncluido(int** m, int fil, int col);
int matrizSumaDebajoDSIncluido(int** m, int fil, int col);

/**Ejercicio 1.13*/
int matrizSumaDP(int**m, int fil, int col);
int matrizSumaDS(int**m, int fil, int col);

/**Ejercicio 1.14*/
bool esMatrizIdentidad(int** m, int fil, int col);
void matrizInicializarIdentidad(int** m, int fil, int col, bool esIdentidad);

/**Ejercicio 1.15*/
bool esMatrizSimetrica(int** m, int fil, int col);
void matrizInicializarSimetrica(int** m, int fil, int col, int limInf, int limSup, bool esSimetrica);

/**Ejercicio 1.17*/
void matrizTransponerInSitu(int** m, int fil, int col);

/**Ejercicio 1.18*/
int** matrizTransponer(int** m ,int fil, int col);

/**Ejercicio 1.19*/
int** matrizProducto(int** m1, int** m2, int fil1, int col2, int filcol12);
#endif // MATRIZ_H_INCLUDED
