#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM_MAX_ENTRADAS        20
#define TAM_MAX_COD_ENTRADAS    10

typedef struct
{
    char cod[TAM_MAX_COD_ENTRADAS];
    bool usada;
} Entrada;

typedef struct
{
    void *vec;
    int ce;
    size_t tamElem;
    int cap;
} Vector;

typedef void (*Accion)(void *, void *);
void accionMostrarEntrada(void *entrada, void *extra);


// ARCHIVO
void archivoEntradasGenerar(const char *nomArchEntradas);
void archivoEntradasRecorrer(const char *nomArchEntradas, Accion accion, void *datosAccion);


#endif // FUNCIONES_H_INCLUDED
