#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "utilidades.h"

#define TAM_ELEM    sizeof(int)
#define CAP_MAX     10

int main()
{
    tVector vec;
    int vLote[] = {1, 32, 654, 1, 1};
    size_t ce = sizeof(vLote) / TAM_ELEM;

    /**Memoria estatica**/
    int memoria[CAP_MAX];

    //int resp = crearVectorDinamico(&vec, TAM_ELEM, CAP_MAX);
    int resp = crearVectorEstatico(&vec, memoria, TAM_ELEM, CAP_MAX);

    if(resp == TODO_OK)
    {
        for(int i = 0; i < ce && (resp == TODO_OK); i++)
        {
            resp = insertarVectorOrd(&vec, &vLote[i], compararInt);
        }

        /**Dato para hacer pruebas**/
        int dato = 1;

        eliminarTodasApariciones(&vec, &dato, compararInt);

        if(resp == TODO_OK)
        {
            mostrarVector(&vec, mostrarInt);
        }

        //destruirVectorDinamico(&vec);
        destruirVectorEstatico(&vec);
    }

    return resp;
}
