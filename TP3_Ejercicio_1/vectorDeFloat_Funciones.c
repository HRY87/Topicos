#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include "vectorDeFloat.h"

int crearMatrizFloat(float* vf, size_t cantElemMax)
{
    float* posFinal = vf + cantElemMax;
    char opc;
    int cantElem = 0;
    do
    {
        puts("Desea agregar un elemento?");
        fflush(stdin);
        scanf("%c", &opc);
        opc = tolower(opc);
        if(opc == 's')
        {
            puts("Ingrese elemento:");
            scanf("%f", vf);
            vf++;
            cantElem++;
        }

        system("cls");
    }while(vf < posFinal && opc == 's');

    return cantElem;
}

void mostrarMatrizFloat(float* vf, size_t cantElem)
{
    float* posFinal = vf + cantElem;
    int i = 0;

    while(vf < posFinal)
    {
        printf("[%d]: %.2f\n", i, *vf);
        vf++;
        i++;
    }

}
float* buscarMinimo(float* vf, size_t cantElem)
{
    float* min = vf;
    float* posFinal = vf + cantElem;

    while(vf < posFinal)
    {
        if(*vf < *min)
            min = vf;
        vf++;
    }

    return min;
}

float calcularPromedioPosPares(float* vf, size_t cantElem)
{
    float* posFinal = vf + cantElem;
    int cantDeNumerosPares = 0;
    float total = 0;

    vf++;
    while(vf < posFinal)
    {
        total += *vf;
        cantDeNumerosPares++;
        vf += 2;
    }

    return (cantElem < 1 ? 0 : total / cantDeNumerosPares);
}

void mostrarOrdenInverso(float* vf, size_t cantElem)
{
    float* posFinal;
    int ce = cantElem;
    for(posFinal = vf + cantElem - 1; posFinal >= vf; posFinal--)
        printf("[%d]: %.2f\n", --ce, *posFinal);
}
