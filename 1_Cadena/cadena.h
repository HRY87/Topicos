#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <stdbool.h>

#define TAM_PAL 31
#define MAX_CAD 51
#define esLetra(c)(((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))
#define TOUPPER(c)((c) >= 'a' && (c) <= 'z' ? (c) - ('a' - 'A') : (c))
#define TOLOWER(c)((c) >= 'A' && (c) <= 'Z' ? (c) + ('a' - 'A') : (c))

typedef struct
{
    char* cursor;
    bool finSec;
}SecPal;

typedef struct
{
    char vPal[TAM_PAL];
}Palabra;

bool esPalindromo(const char* cad);
int valorNumericoCadena_ASCII(const char* cad);
int valorNumericoCadena(const char* cad);
int contarAparicionesPalabra(const char* texto, const char* palabra);
char* normalizarCadena(const char* cadNormalizar, char* cadNormalizada);
char* ofuscarCadena(const char* ofuscado, char* desofuscado, const char* clave);


size_t str_len(const char* cad);
int str_cmpi(const char* s1, const char* s2);
char* str_cpy(char* s1, const char* s2);
void limpiarFrase(const char* entrada, char* salida);

void secPalCrear(SecPal* sec, const char* cad);
bool secPalLeer(SecPal* sec, Palabra* pal, bool normalizarPalabra);
void secPalEscribir(SecPal* sec, const Palabra* pal);
void secPalEscribirCar(SecPal* sec, char c);
bool secPalFin(const SecPal* sec);
void secPalCerrar(SecPal* sec);
void palabraATitulo(Palabra* pal);

int buscarPosicionClave(const char* clave, const char c);
void desofuscarPalabra(Palabra* pal, const char* clave);

int cargarParesMatriz(char matriz[][2][MAX_CAD], size_t max_pares);
int compararCadenas(const char* s1, const char* s2);
#endif // CADENA_H_INCLUDED
