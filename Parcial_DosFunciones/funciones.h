#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>

#define PATH_TXT    "archivo.txt"
#define TAM_LINEA   1024
#define TAM_PAL     51
#define ES_LETRA(X) (((X) >= 'a' && (X) <= 'z') || ((X) >= 'A' && (X) <= 'Z'))

typedef int(*Comparar)(const void* a, const void* b);

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

int palabraMasLargaYContarPalabras(tPalabra* palLarga, char* linea);
int compararPalabra(const tPalabra* p1, const tPalabra* p2);

void crearSecPal(tSecPal* sec, char* s);
bool leerPalabra(tSecPal* sec, tPalabra* pal);

int str_len(const char* s);
char* str_chr(char* s, int c);
char* str_cpy(char* dest, const char* orig);

int prueba_contarPalabras();

/**Ejercicio 2: Validar matriz campeonato**/
bool esMatrizCampeonatoValidaMio(int** m, int n);
void **matrizCrear(int n, size_t tamElem);
void matrizDestruir(void **m, int n);
void matrizMostrar(int **mat, int n);
void matrizInicializar(int** m, int n);
int cmpEnteros(const void *a, const void *b);
void *busquedaBinaria(const void *v, int ce, size_t tamElem, const void *elem, Comparar cmp);

int prueba_matrizCampeonato(int n);
#endif // FUNCIONES_H_INCLUDED
