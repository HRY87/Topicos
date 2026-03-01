#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int res = 0;

    //res = prueba_mstcat();

    //res = prueba_SumaTriangInfEntreDiag(6, 6, 1, 3);

    int v[] = {1, 3, 4, 5, 6, 7, 10}; //Debe estar ordenado

    int ce = sizeof(v) / sizeof(v[0]);

    res = prueba_mbsearch(v, ce, 1);

    return res;
}
