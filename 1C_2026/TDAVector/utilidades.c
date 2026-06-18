#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"

void mostrarEmpleado(const void* d)
{
    tEmpleado* e = (tEmpleado*)d;

    printf("%02d|%-80s|%6.2f\n", e->legajo, e->ayn, e->sueldo);
}

int comparar_legajo(const void* d1, const void* d2)
{
    tEmpleado* e1 = (tEmpleado*)d1;
    tEmpleado* e2 = (tEmpleado*)d2;

    return(e1->legajo - e2->legajo);
}

int comparar_sueldo(const void* d1, const void* d2)
{
    tEmpleado* e1 = (tEmpleado*)d1;
    tEmpleado* e2 = (tEmpleado*)d2;

    return((e1->sueldo == e2->sueldo ? 0 : (e1->sueldo > e2->sueldo ? 1 : -1)));
}

void mostrarInt(const void* d)
{
    printf("%d", *(const int*)d);
}

int compararInt(const void* d1, const void* d2)
{
    return(*(const int*)d1 - *(const int*)d2);
}
