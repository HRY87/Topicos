#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <stdbool.h>

/**Para el ejercicio 1.20**/
#define ORDEN           5
#define TAM_RESULTADOS  6

int** matrizCrear(size_t filas, size_t columnas);
void matrizDestruir(int** m, int fil);
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
int** matrizProducto(int** m1, int** m2, int fil1, int col2, int col1Fil2);

/**Ejercicio 1.20**/
/**Inicializar matriz dinamica**/
void matrizInicializarTorneo(int** m, size_t orden);

/**Validar si es matriz torneo**/
int validarMatrizTorneo(int** m, size_t orden, int puntos[][TAM_RESULTADOS]);
int buscarPos(int* v, int elem, size_t ce);
int validarDiagonal(int** m , size_t orden);

/**Sumar puntos de la temporada por equipo**/
void totalizarPuntosPorEquipos(int** m, size_t orden, int* vPuntos);
int sumarPuntos(int* v, size_t orden);

/**Rotacion de elementos**/
void matrizRotar180(int** m, size_t fil, size_t col);
#endif // MATRIZ_H_INCLUDED
