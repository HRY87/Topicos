#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

void mostrarVector(void* v, size_t ce, size_t tamElem, Mostrar mostrar)
{
    void* posFinal = v + (ce * tamElem);

    while(v < posFinal)
    {
        mostrar(v);
        v += tamElem;
    }
}

int cmp_int_asc(const void* d1, const void* d2)
{
    return(*(int*)d1 - *(int*)d2);
}

int cmp_int_des(const void* d1, const void* d2)
{
    return(*(int*)d2 - *(int*)d1);
}

int cmp_dni_asc(const void* d1, const void* d2)
{
    tPersona* p1 = (tPersona*)d1;
    tPersona* p2 = (tPersona*)d2;

    return(p1->dni - p2->dni);
}

int cmp_dni_des(const void* d1, const void* d2)
{
    tPersona* p1 = (tPersona*)d1;
    tPersona* p2 = (tPersona*)d2;

    return(p2->dni - p1->dni);
}

int cmp_apellido_nombre_asc(const void* d1, const void* d2)
{
    tPersona* p1 = (tPersona*)d1;
    tPersona* p2 = (tPersona*)d2;

    int comp = strcmpi(p1->apellido, p2->apellido);

    return(comp == 0 ? strcmpi(p1->nombres, p2->nombres): comp);
}

int cmp_apellido_nombre_des(const void* d1, const void* d2)
{
    tPersona* p1 = (tPersona*)d1;
    tPersona* p2 = (tPersona*)d2;

    int comp = strcmpi(p2->apellido, p1->apellido);

    return(comp == 0 ? strcmpi(p2->nombres, p1->nombres): comp);
}
void mostrar_int(const void* d)
{
    int* dato = (int*)d;
    printf("%d\n", *dato);
}

void mostrar_tPersona(const void* d)
{
    tPersona* p = (tPersona*)d;
    printf("%08d %-20s %-30s %4.2f\n", p->dni, p->apellido, p->nombres, p->peso);
}

int buscarXdni(const tPersona* p,tPersona* d, size_t ce, Cmp cmp)
{
    tPersona* pp = (tPersona*)p;
    tPersona* ppFinal = pp + ce;
    int pEncontrado = 0;

    while(pp < ppFinal && !pEncontrado)
    {
        if(!cmp(pp, d))
            pEncontrado = 1;

        pp++;
    }

    return pEncontrado;
}
