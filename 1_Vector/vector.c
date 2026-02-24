#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "vector.h"

int insertarVectorEnPosicionEntero(int* v, int ce, int elem, int pos)
{
    if(ce == 0 || pos >= ce)
        return ERR_VECTOR;

    for(int i = ce - 1; i >= pos; i--)
    {
        v[i + 1] = v[i];
    }

    v[pos] = elem;

    return TODO_OK;
}

int insertarVectorOrdenadoAsc(int* v, int ce, int elem, Comparar cmp, Intercambiar intercambio)
{
    int pos = ce - 1, i;
    int posEncontrada = false;

    if(ce == 0)
        return ERR_VECTOR;

    ordenarVectorBurbujeo(v, ce, cmp, intercambio);

    for(i = 0; i < ce && !posEncontrada; i++)
    {
        if(elem < v[i])
        {
            pos = i;
            posEncontrada = true;
        }
    }

    for(i = ce - 1; i >= pos && posEncontrada; i--)
    {
        v[i + 1] = v[i];
    }

    v[pos] = elem;

    return TODO_OK;
}

int eliminarVectorEnPosicionEntero(int* v, int* ce, int pos)
{
    if(*ce == 0 || pos >= *ce)
        return ERR_VECTOR;

    for(int i = pos; i < *ce - 1; i++)
    {
        v[i] = v[i + 1];
    }

    (*ce)--;

    return TODO_OK;
}

int eliminarVectorPrimeraAparicion(int* v, int* ce, int elem)
{
    int pos = -1;
    bool elemEncontrado = false;

    if(*ce == 0)
        return ERR_VECTOR;

    for(int i = 0; i < *ce && !elemEncontrado; i++)
    {
        if(v[i] == elem)
        {
            pos = i;
            elemEncontrado = true;
        }
    }

    if(elemEncontrado && pos >= 0)
    {
        eliminarVectorEnPosicionEntero(v, ce, pos);
    }


    return elemEncontrado ? TODO_OK : ERR_VECTOR;
}

int eliminarVectorTodasApariciones(int* v, int* ce, int elem)
{
    if(*ce == 0)
        return ERR_VECTOR;

    for(int i = 0; i < *ce; i++)
    {
        if(v[i] == elem)
        {
            eliminarVectorEnPosicionEntero(v, ce, i);
        }
    }

    return TODO_OK;
}


int crearVectorEntero(int* v, int ce, int tamMax, int limiteInferior, int limiteSuperior)
{
    if(ce > tamMax)
        return ERR_VECTOR;

    srand(time(NULL));

    for(int i = 0; i < ce; i++)
    {
        v[i] = limiteInferior + rand() % (limiteSuperior - limiteInferior + 1);
    }

    return TODO_OK;
}

void mostrarVector(int* v, int ce, Mostrar mostrar)
{
    for(int i = 0; i < ce; i++)
    {
        printf("[%d]:", i);
        mostrar(&v[i]);
    }
}

void ordenarVectorBurbujeo(int* v, int ce, Comparar cmp, Intercambiar intercambio)
{
    for(int i = 0; i < ce; i++)
    {
        for(int j = i + 1; j < ce; j++)
        {
            if(v[i] > v[j])
            {
                intercambio(&v[j], &v[i]);
            }
        }
    }
}
