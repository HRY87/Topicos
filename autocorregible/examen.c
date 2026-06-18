#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "examen.h"


void* _bbinaria(const void *clave, const void *vec, size_t ce, size_t tam, int cmp(const void *, const void *));
int _contarPalabras(const char* nomArc, char* palMasLarga, int* cantVeces);
int _sumTrianDerEntreDiag(int mat[][MAX_COL], int filas);
int _sumTrianInfEntreDiag(int mat[][MAX_COL], int filas);
