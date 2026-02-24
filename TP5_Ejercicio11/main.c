#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"

#define PATH_ARCH   "datos.dat"

int main()
{
    if(crearArchivo(PATH_ARCH))
        puts("No se puede abrir el archivo");

    puts("---Archivo original---");
    if(mostrarArchivo(PATH_ARCH))
        puts("No se pudo abrir el archivo");
    if(modificarArchivo(PATH_ARCH))
        puts("No se puede abrir el archivo");

    puts("---Archivo modificado---");
    if(mostrarArchivo(PATH_ARCH))
        puts("No se pudo abrir el archivo");
    return 0;
}
