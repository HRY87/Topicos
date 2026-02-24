#include <stdio.h>
#include <stdlib.h>
#include "vectorInt.h"

int main()
{
    int v[CANT_ELEM_MAX];
    int ce;
    float prom;
    long total;
    tRegistro r;

    ce = crearVectorInt(v, CANT_ELEM_MAX);

    if(ce > 0)
    {
        mostrarVectorInt(v, ce);

        prom = calcularTotalYPromedioDelVectorInt(v, ce, &total);
        calcularTotalYPromedioDelVectorInt_2(v, ce, &r);

        printf("El promedio es %.2f y el total de los elementos %ld\n", prom, total);
        printf("El promedio es %.2f y el total de los elementos %ld\n", r.prom, r.total);

    }else
    puts("No hay elementos en el vector");

    return 0;
}
