#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "vector.h"

/**Ejercicio 1.1: Insertar elemento dada una posicion**/
int insertarVectorEnPosicionEntero(int* v, int ce, int elem, int pos)
{
    if(ce == 0 || pos == ce)
        return ERR_VECTOR;

    int* act = v + ce - 1;

    while(act >= (v + pos))
    {
        //v[i + 1] = v[i];
        *(act + 1) = *act;
        act--;
    }

    *(v + pos) = elem;

    return TODO_OK;
}

/**Ejercicio 1.2: Insertar elemento en vector ordenado de forma ascendente**/
int insertarVectorOrdenadoAsc(int* v, int ce, int elem, Comparar cmp, Intercambiar intercambio)
{
    if(ce == 0)
        return ERR_VECTOR;

    ordenarVectorBurbujeo(v, ce, cmp, intercambio);

    int* act = v;

    while(act < (v + ce) && *(act) < elem)
    {
        act++;
    }

    int* ult = v + ce - 1;

    while(ult >= act)
    {
        *(ult + 1) = *ult;
        ult--;
    }

    *act = elem;

    return TODO_OK;
}

/**Ejercicio 1.3: Eliminar elemento dada una posicion**/
int eliminarVectorEnPosicionEntero(int* v, int* ce, int pos)
{
    if(*ce == 0 || pos < 0|| pos >= *ce)
        return ERR_VECTOR;

    int* act = v + pos;
    int* ult = v + *ce - 1;

    while(act < ult)
    {
        *act = *(act + 1);
        act++;
    }

    (*ce)--;

    return TODO_OK;
}

/**Ejercicio: 1.4: Eliminar primera aparacion**/
int eliminarVectorPrimeraAparicion(int* v, int* ce, int elem)
{
    int* act = v;
    int* ult = v + *ce;
    int pos;

    if(*ce <= 0)
        return ERR_VECTOR;

    while(act < ult)
    {
        if(*act == elem)
        {
            pos = act - v; //La diferencia sera la pos en el vector
            return eliminarVectorEnPosicionEntero(v, ce, pos);
        }

        act++;
    }

    return ERR_VECTOR;
}

/**Ejercicio 1.5: Eliminar todas las apariciones**/
int eliminarVectorTodasApariciones(int* v, int* ce, int elem)
{
    if(*ce == 0)
        return ERR_VECTOR;

    int* act = v;

    while(act < v + *ce)
    {
        if(*act == elem)
        {
            eliminarVectorEnPosicionEntero(v, ce, act - v);
            //No se debe avanzar, por que el vector cambio
        }else
        {
            act++;
        }
    }

    return TODO_OK;
}

/**Funciones auxiliares**/
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
    int* pi = v;
    int* pj = NULL;
    int* pFin = v + ce;

    while(pi < pFin)
    {
        pj = pi + 1; //pj sera el siguiente de pi

        while(pj < pFin)
        {
            if(cmp(pj, pi) < 0)
            {
                intercambio(pj, pi);
            }

            pj++;
        }
        pi++;
    }
}
