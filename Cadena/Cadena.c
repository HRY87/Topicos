#include <stdio.h>
#include "Cadena.h"
#include "Palabra.h"

char* normalizar(const char* cadNormalizar, char* cadNormalizada)
{
    SecPal secLect, secEscr;

    secPalCrear(&secLect, cadNormalizar);
    secPalCrear(&secEscr, cadNormalizada);

    Palabra pal;

    secPalLeer(&secLect, &pal);

    while(!secPalFin(&secLect))
    {
        palabraATitulo(&pal);
        secPalEscribir(&secEscr, &pal);
        secPalEscribirCar(&secEscr, ' ');
        secPalLeer(&secLect, &pal);
    }

    secPalCerrar(&secEscr);

    return cadNormalizada;
}
