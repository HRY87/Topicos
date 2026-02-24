#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "vectorDeFloat.h"
#include "menu.h"

#define TAM_MAX     20
int main()
{
    int ce, opc;
    float* min = NULL;
    float vf[TAM_MAX], prom;

    ce = crearMatrizFloat(&vf[0], TAM_MAX);

    if(ce > 0)
    {
        puts("Vector float");
        mostrarMatrizFloat(vf, ce);
    }

    do
    {
        opc = menu(opciones, CANT_OPC);

        switch(opc)
        {
        case '1':
            if(ce)
            {
                min = buscarMinimo(vf, ce);
                printf("El valor minimo del vector es: %.2f\n", *min);
            }
            else
                puts("No hay valores en el vector");
            break;

        case '2':
            if(ce)
            {
                prom = calcularPromedioPosPares(vf, ce);
                printf("El promedio de las posiciones pares es: %.2f\n", prom);
            }
            else
                puts("No hay valores en el vector");
            break;

        case '3':
            mostrarOrdenInverso(vf, ce);
            break;
        }

    }
    while(opc != '4');
    return 0;
}
