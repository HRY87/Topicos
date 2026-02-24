#include <stdio.h>
#include <stdlib.h>
#include "vectorDireccionDeMemoria.h"

int main()
{
    //*Entero*//
//    int vi[5] = {1, 2, 3, 4, 5};
//    int elemi = 1;
//    int* posi;

    //*Flotante*//
//    float vf[5] = {1.3, 2.5, 3.3, 4.2, 5.7};
//    float elemf = 2.5;
//    float* posf;

    //*Caracter*//
    char vc[5] = "HolaT";
    char elemc = 'a';
    char* posc;

    posc = encontrarPosicionDelElemento(vc, &elemc, 5, sizeof(char));

    if(posc)
    {
        printf("%p - %c\n", posc, *posc);
    }else
        puts("No existe el elemento en memoria");

    return 0;
}
