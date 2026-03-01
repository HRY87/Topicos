#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int res = TODO_OK;
    printf("ARCHIVO OFUSCADO:\n");
    mostrarArchivoTxt("citas.txt");

    printf("\n\nARCHIVO DESOFUSCADO:\n");
    res = desofuscarArchivoTxt("citas.txt");

    if(res == TODO_OK)
    {
        mostrarArchivoTxt("citas.txt");
    }

    return res;
}
