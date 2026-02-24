#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

#include <stddef.h>

#define TODO_OK         0
#define ERR_ARCH        1
#define TAM_ESPACIO     7
#define RANGO_INF       -32768
#define RANGO_SUP       32767
#define PATH_ARCH       "datos.txt"
int crearArchivo(const char* path, size_t tamEspacio);
int cargarFila(short int* v, size_t tamEspacio);
#endif // DATOS_H_INCLUDED
