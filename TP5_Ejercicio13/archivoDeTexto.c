#include <stdio.h>
#include <stdlib.h>
#include "archivoDeTexto.h"


int crearArchivoTXT(const char* path, const char* ordenCampos)
{
    FILE* txt = fopen(path, "wt");

    if(!txt)
        return ERR_ARCH;


}
