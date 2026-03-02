#ifndef PALABRA_H_INCLUDED
#define PALABRA_H_INCLUDED

#include <stdbool.h>

#define TAM_PAL 31

#define esLetra(c)(((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))
#define aMayuscula(c)((c) >= 'a' && (c) <= 'z' ? (c) - ('a' - 'A') : (c))
#define aMinuscula(c)((c) >= 'A' && (c) <= 'Z' ? (c) + ('a' - 'A') : (c))

typedef struct
{
    char* cursor;
    bool finSec;
}SecPal;

typedef struct
{
    char vPal[TAM_PAL];
}Palabra;

void secPalCrear(SecPal* sec, const char* cad);
bool secPalLeer(SecPal* sec, Palabra* pal);
void secPalEscribir(SecPal* sec, const Palabra* pal);
void secPalEscribirCar(SecPal* sec, char c);
bool secPalFin(const SecPal* sec);
void secPalCerrar(SecPal* sec);
void palabraATitulo(Palabra* pal);


#endif // PALABRA_H_INCLUDED
