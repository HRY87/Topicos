#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>

#define TODO_OK         0
#define ERR_ARCH        1
#define TAM_LINEA       1024
#define PATH_TXT        "citas.txt"


/**Funcion principal**/
int desofuscarArchivoTxt(const char* path);


/**Funciones auxiliares**/
int mostrarArchivoTxt(const char* path);

#endif // FUNCIONES_H_INCLUDED
