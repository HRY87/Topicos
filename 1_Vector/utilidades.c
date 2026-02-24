#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"

int compararInt(const void* d1, const void* d2)
{
    int* e1 = (int*)d1;
    int* e2 = (int*)d2;

    return(*e1 - *e2);
}

void intercambiarInt(void* d1, void* d2)
{
    int aux;
    int* e1 = (int*)d1;
    int* e2 = (int*)d2;

    aux = *e1;
    *e1 = *e2;
    *e2 = aux;
}

void mostrarInt(const void* d)
{
    printf("%d\n", *(int*)d);
}

