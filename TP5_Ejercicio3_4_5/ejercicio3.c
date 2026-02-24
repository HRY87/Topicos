#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ejercicio3.h"

int crearArchivoTXT(const char* path)
{
    FILE* txt = fopen(path, "wt");
    char primeraLinea[] = "123456 123456 123456 123456 123456 123456 123456\n";

    if(!txt)
        return ERROR_ARCH;

    fwrite(primeraLinea, 1, strlen(primeraLinea), txt);

    fclose(txt);

    return TODO_OK;
}

int escribirArchivoTxt(const char* path)
{
    FILE* txt = fopen(path, "rt");
    short dato;

    time()
}
