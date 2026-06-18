#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>

#define PATH_TXT    "archivo.txt"
#define TAM_PAL     51
#define TAM_LINEA   1024

typedef struct
{
    char pal[TAM_PAL];
    size_t cantRepeticiones;
}tPalabra;

typedef struct
{
    char* pSec;
    bool finSec;
}tSecPal;

/**Ejercicio 1: Hacer contar palabras**/
tPalabra* contarPalabrasMio(const char* pathTxt, tPalabra* pal);

/**Ejercicio 2: Validar matriz campeonato**/
bool esMatrizCampeonatoValidaMio(int** m, int n);
#endif // FUNCIONES_H_INCLUDED
