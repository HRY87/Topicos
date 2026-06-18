#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**Pueden modificar el main y funciones.c y .h como deseen**/

int main()
{
    int res = TODO_OK;
    printf("ARCHIVO OFUSCADO:\n");
    mostrarArchivoTxt(PATH_TXT);

    printf("\n\nARCHIVO DESOFUSCADO:\n");
    res = desofuscarArchivoTxt(PATH_TXT);

    if(res == TODO_OK)
    {
        mostrarArchivoTxt(PATH_TXT);
    }

    return res;
}
