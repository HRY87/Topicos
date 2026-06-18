#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include "funciones.h"


/**Ejercicio 1: Hacer la version propia  de strcat**/
char* mstcat(char* s1, const char* s2);

/**Ejercicio 2: Sumar los elementos del triangulo debajo de las diagonales**/
int sumaTrianInfEntreDiag(int** m, size_t fil, size_t col);

/**Ejercicio 3: Hacer version propia de bsearch, buscar generico**/
void *mbsearch(const void *clave, const void *base, size_t ce, size_t tamElem, Comparar cmp);
