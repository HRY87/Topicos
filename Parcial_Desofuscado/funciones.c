#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


/**Funcion principal**/
int desofuscarArchivoTxt(const char* path)
{
    return TODO_OK;
}
/**Funciones auxiliares**/
int mostrarArchivoTxt(const char* path)
{
    FILE* txt = fopen(path, "rt");

    if(!txt)
        return ERR_ARCH;

    char linea[TAM_LINEA];

    while(fgets(linea, TAM_LINEA, txt))
    {
       printf("%s", linea);
    }

    fclose(txt);

    return TODO_OK;
}
