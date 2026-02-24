#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "funcionGenerica.h"

void intercambiar(void* d1, void* d2, Intercambio tipoIntercambio)
{
    tipoIntercambio(d1, d2);
}

void tipoIntercambio_int(const void* d1, const void* d2)
{
    int aux;

    aux = *(int*)d1;
    *(int*)d1 = *(int*)d2;
    *(int*)d2 = aux;
}
