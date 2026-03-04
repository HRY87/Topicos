#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "utilidades.h"
#include "vector.h"

#define PATH_NEW        "cargoNew.txt"
#define PATH_OLD        "cargoOld.txt"
#define PATH_CARGO      "cargo.txt"
#define PATH_ERROR      "errores.txt"

int crearArchivoTxt(const char* pathTxt, void* datos, size_t tamElem, size_t cantElem, Accion escribirLote);
int llenarVectorConArchivoTxt(const char* pathTxt, tVector* v);

#endif // ARCHIVO_H_INCLUDED
