#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include<stdbool.h>

#define ORDEN_ASCENDENTE    0
#define ORDEN_INVERSO       1

typedef int(*Comparar)(const void* d1, const void* d2);

/**Ejercicio 1: Hacer a una version de strstr**/
char* msstr(const char* s1, const char* s2);
size_t str_len(const char* s);
int prueba_msstr();

/**Ejercicio 2: Hacer transponer matriz cuadrada in situ**/
int transponerMatrizCuadradaInSitu(int** m, size_t n);
int** crearMatrizCuadrada(size_t n);
void destruirMatriz(int** m, size_t fil);
void mostrarMatrizCuadrada(int** m, size_t n);
int prueba_transponerInSitu(size_t n, int limInf, int limSup);

/**Ejercicio 3: Hacer insertar ordenado**/
bool insertarVectorOrdenado(void* v, size_t* ce, size_t cap, void* dato, size_t tam, Comparar comparar, int orden);
int cmpInt(const void* d1, const void* d2);
int prueba_insertarOrdenado();
#endif // FUNCIONES_H_INCLUDED
