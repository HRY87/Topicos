#include <stdio.h>
#include <stdlib.h>
#include "datos.h"
int main()
{
    if(!crearArchivo(PATH_ARCH, TAM_ESPACIO))
        puts("El archivo se guardo correctamente");
    return 0;
}
