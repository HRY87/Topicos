#ifndef ARCHIVODETEXTO_H_INCLUDED
#define ARCHIVODETEXTO_H_INCLUDED

#include "alumno.h"

#define PATH_TXT    "alumnos.txt"
#define TODO_OK     0
#define ERR_ARCH    1

int crearArchivoTXT(const char* path, const char* ordenCampos);

#endif // ARCHIVODETEXTO_H_INCLUDED
