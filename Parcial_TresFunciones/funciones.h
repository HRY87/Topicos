#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef int(*Comparar)(const void* a, const void* b);

/**Ejercicio 1: Ordenar seleccion generico**/
void _ordenarSeleccion(void* base, size_t nmemb, size_t tamanyo, Comparar comparar);

/**Ejercicio 2: Contar celulas vivas dado una posicion fila/columna**/
size_t _contarCelulasVivasEnVecindario(int** m, int fil, int col, int posF, int posC);

/**Ejercicio 3: Hacer a una version de strstr**/
char* msstr(const char* s1, const char* s2);

#endif // FUNCIONES_H_INCLUDED
