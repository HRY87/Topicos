#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "vectorInt.h"

int crearVectorInt(int* vi, size_t cantElemMax)
{
    int i, ce;
    srand(time(NULL));

    do
    {
        printf("Ingrese la cantidad de elementos(MAX: %d):\n", (int)cantElemMax);
        scanf("%d", &ce);
        system("cls");
    }while(ce > cantElemMax);

    for(i = 0; i < ce; i++)
        *(vi + i) = rand() % VALOR_ELEM_MAX;

    return ce;
}

void mostrarVectorInt(int* vi, size_t ce)
{
    int i;
    for(i = 0; i < ce; i++)
        printf("[%d]: %d\n", i, *(vi + i));
}
float calcularTotalYPromedioDelVectorInt(int* vi, size_t ce, long* total)
{
    int i;

    for(i = 0; i < ce; i++)
        *total += *(vi + i);

    return (ce == 0 ? 0 : (float)*total / ce);
}

void calcularTotalYPromedioDelVectorInt_2(int* vi, size_t ce, tRegistro* r)
{
    int i;

    r->total = 0;
    r->prom = 0;

    for(i = 0; i < ce; i++)
        r->total += *(vi + i);

    r->prom = r->total / ce;
}
