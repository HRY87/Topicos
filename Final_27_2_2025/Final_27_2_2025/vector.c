#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "vector.h"

int redimensionarVector(tVector* v, size_t nueTope);

int crearVector(tVector* v, size_t tamElem, size_t cantElem)
{
    v->vec = malloc(tamElem * cantElem);

    if(!v->vec)
        return SIN_MEM;

    v->tope = cantElem;
    v->tamElem = tamElem;
    v->cantElem = 0;

    return TODO_OK;
}

int insertarVectorOrd(tVector* v, void* dato, size_t tamElem, Comparar compararLegajo)
{
    if(v->cantElem == v->tope)
    {
        if(redimensionarVector(v, v->tope * 2))
        {
            return SIN_MEM;
        }
    }

    void* posIns = v->vec;
    void* posUlt = v->vec + (v->cantElem - 1) * v->tamElem;

    while(posIns <= posUlt && compararLegajo(posIns, dato) < 0)
    {
        posIns += tamElem;
    }

    for(void* i = posUlt; i >= posIns; i -= tamElem)
    {
        memcpy(i + tamElem, i, tamElem);
    }

    memcpy(posIns, dato, tamElem);
    v->cantElem++;

    return TODO_OK;
}

int redimensionarVector(tVector* v, size_t nueTope)
{
    void* nue = realloc(v->vec, v->tamElem * nueTope);

    if(!nue)
        return SIN_MEM;

    v->vec = nue;
    v->tope = nueTope;

    return TODO_OK;
}

void vaciarVector(tVector* v)
{
    free(v->vec);

    v->tope = 0;
    v->tamElem = 0;
    v->cantElem = 0;
}
void mostrarVector(tVector* v, Mostrar mostrarCargo)
{
    for(void* i = v->vec; i <= v->vec + (v->cantElem - 1)* v->tamElem; i+= v->tamElem)
    {
        mostrarCargo(i);
    }
}
