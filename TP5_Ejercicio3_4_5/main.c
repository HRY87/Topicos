#include <stdio.h>
#include <stdlib.h>
#include "ejercicio3.h"

int main()
{
    if(crearArchivoTXT(PATH_ARCH))
        printf("ERROR: No se puede crear el archivo %s\n", PATH_ARCH);
    return 0;
}
