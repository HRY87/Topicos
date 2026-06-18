#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"
// #include "funciones.c"

#define RUTA_ENTRADA    "entradasVendidas.bin"
int main()
{
    archivoEntradasGenerar(RUTA_ENTRADA);
    printf("Archivo de prueba:\n");
    archivoEntradasRecorrer(RUTA_ENTRADA, accionMostrarEntrada, NULL);

    return 0;
}
