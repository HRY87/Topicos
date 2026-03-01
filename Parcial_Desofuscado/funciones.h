#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>

#define TODO_OK         0
#define ERR_ARCH        1
#define TAM_PAL         31
#define TAM_LINEA       1024
#define PATH_TXT        "citas.txt"
#define ES_LETRAS(X)    (((X) >= 'a' && (X) <= 'z') || ((X) >= 'A' && (X) <= 'Z'))

typedef int(*Comparar)(const void* d1, const void* d2);

typedef struct
{
    char* pSec;
    bool finSecPal;
}tSecPal;

typedef struct
{
    char pal[TAM_PAL];
}tPalabra;

/**Funcion principal**/
int desofuscarArchivoTxt(const char* path);

/**desofuscar**/
char* desofuscar(char* s);
void cambiarLetrasPalabra(tPalabra* pal);
void darVueltaPalabra(tPalabra* pal);

/**Funciones auxiliares**/
int mostrarArchivoTxt(const char* path);
int cmpCaracter(const void* c1, const void *c2);
void* buscarElemento(void* vec, int ce, size_t tamElem, void* elem, Comparar comparar);

/**Seccion palabra y palabra**/
void crearSecPal(tSecPal* sec, char* s);
void finalSecPal(tSecPal* sec);
void escribirPalabra(tSecPal* sec, const tPalabra* pal);
void escribirCaracter(tSecPal* sec, const char c);
void moverPunteroSecPal(tSecPal* sec, int n);
bool leerPalabra(tSecPal* sec, tPalabra* pal);
/**Funciones de string.h**/
size_t str_len(const char* s);
char* str_cpy(char* s1, const char* s2);
#endif // FUNCIONES_H_INCLUDED
