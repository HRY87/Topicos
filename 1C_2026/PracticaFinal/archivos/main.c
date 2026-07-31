#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    convertirArchivoTextoBinario(RUTA_TXT, RUTA_BIN, sizeof(tProducto));
    mostrarArchivoBinario(RUTA_BIN);
    return 0;
}
