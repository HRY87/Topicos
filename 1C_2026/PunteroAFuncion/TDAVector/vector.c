#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "vector.h"

/**Dinamico**/
int crearVectorDinamico(tVector* v, size_t tamElem, size_t capacidad)
{
    v->vec = malloc(tamElem * capacidad);

    if(!v->vec)
        return SIN_MEM;

    v->ce = 0;
    v->tamElem = tamElem;
    v->tope = capacidad;

    return TODO_OK;
}

void destruirVectorDinamico(tVector* v)
{
    free(v->vec);

    v->ce = 0;
    v->tamElem = 0;
    v->tope = 0;
}

/**Estatico**/
int crearVectorEstatico(tVector* v, void* memoria, size_t tamElem, size_t capacidad)
{
    if(!memoria)
        return SIN_MEM;

    v->vec = memoria;
    v->ce = 0;
    v->tamElem = tamElem;
    v->tope = capacidad;

    return TODO_OK;
}

void destruirVectorEstatico(tVector* v)
{
    v->ce = 0;
}

int vectorLleno(const tVector* v)
{
    return(v->ce == v->tope);
}

int vectorVacio(const tVector* v)
{
    return(v->ce == 0);
}

int insertarVectorOrd(tVector* v, void* dato, Comparar cmp)
{
    char* act = (char*)v->vec;
    char* fin = (char*)v->vec + (v->ce * v->tamElem);

    if(v->ce == v->tope)
        return VEC_LLENO;

    while(act < fin && cmp(dato, act) > 0)
    {
        act += v->tamElem;
    }


    while(fin > act)
    {
        memcpy(fin, fin - v->tamElem, v->tamElem);
        fin -= v->tamElem;
    }

    memcpy(act, dato, v->tamElem);

    v->ce++;

    return TODO_OK;
}

int insertarVectorFinal(tVector* v, void* dato)
{
    char* fin = (char*)v->vec + (v->ce * v->tamElem);

    if(v->ce == v->tope)
        return VEC_LLENO;

    memcpy(fin, dato, v->tamElem);

    v->ce++;

    return TODO_OK;
}

int eliminarElementoVector(tVector* v, void* dato, Comparar cmp)
{
    char* fin =(char*)v->vec + (v->ce * v->tamElem);
    char* act =(char*)v->vec;

    if(v->ce == 0)
        return VEC_VACIO;

    while(act < fin && cmp(dato, act) != 0)
    {
        act += v->tamElem;
    }

    if(act == fin)
        return NO_EXISTE;

    while(act < fin - v->tamElem)
    {
        memcpy(act, act + v->tamElem, v->tamElem);
        act += v->tamElem;
    }

    v->ce--;

    return TODO_OK;
}

/**Auxiliares**/
void mostrarVector(tVector* v, Mostrar mostrar)
{
    char* act = (char*)v->vec;
    for(int i = 0 ; i < v->ce; i++)
    {
        mostrar(act);
        act += v->tamElem;
    }

    puts("");
}

/**Ejercicio 1.21**/
int insertarVectorEnPosicion(tVector* v, void* dato, size_t pos)
{
    char* ini = (char*)v->vec;
    char* act;

    if(v->ce == v->tope || pos >= v->ce)
        return VEC_LLENO;

    act = ini + (pos * v->tamElem);

    char* fin = ini + (v->ce * v->tamElem);

    while(fin > act)
    {
        memcpy(fin, fin - v->tamElem, v->tamElem);
        fin -= v->tamElem;
    }

    memcpy(act, dato, v->tamElem);

    v->ce++;

    return TODO_OK;
}

int eliminarVectorEnPosicion(tVector* v, size_t pos)
{
    char* ini = (char*)v->vec;

    if(v->ce == 0 || pos >= v->ce)
        return VEC_VACIO;

    char* act = ini + (pos * v->tamElem);
    char* fin = ini + (v->ce * v->tamElem);

    while(act < fin - v->tamElem)
    {
        memcpy(act, act + v->tamElem, v->tamElem);
        act += v->tamElem;
    }

    v->ce--;

    return TODO_OK;
}

int eliminarPrimeraAparicion(tVector* v, void* dato, Comparar cmp)
{
    char* act = (char*)v->vec;
    char* fin = act + (v->ce * v->tamElem);

    size_t pos = 0;

    if(v->ce == 0)
        return VEC_VACIO;

    while(act < fin)
    {
        if(cmp(dato, act) == 0)
        {
            return eliminarVectorEnPosicion(v, pos);
        }

        act += v->tamElem;
        pos++;
    }

    return NO_EXISTE;
}

int eliminarTodasApariciones(tVector* v, void* dato, Comparar cmp)
{
    char* act = (char*)v->vec;
    char* fin = act + (v->ce * v->tamElem);

    if(v->ce == 0)
        return VEC_VACIO;

    while(act < fin)
    {
        if(cmp(dato, act) == 0)
        {
            char* sig = act + v->tamElem;

            while(sig < fin)
            {
                memcpy(sig - v->tamElem,
                       sig,
                       v->tamElem);

                sig += v->tamElem;
            }

            v->ce--;
            fin -= v->tamElem;

            /* NO avanzar */
        }
        else
        {
            act += v->tamElem;
        }
    }

    return TODO_OK;
}
