#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cadena.h"

int main()
{
//    char cad[14];
//    char cad2[31] = "Hola que tal ?,";
//
//    strcpy(cad, cad2);
//
//    printf("Cad: %s\n", cad);
//
//    strcat(cad2, "Todo bien.");
//    printf("Cad2 concatenada: %s\n", cad2);
//
//    printf("Cad: %s\n", cad);
//
//    char* q = strchr(cad2, 'q');
//
//    printf("Desde la q: %s\n", q);
//
//    char* signoPreg = strchr(cad2, '?');
//
//    *signoPreg = '\0';
//
//    printf("Desde la q: %s\n", q);

    char cadNormalizar[] = "#%%$&%//esTa/&eS/(#&uNA%()()(cAdenA%&PaRa&%%nORMalIzAr%#";
    char cadNormalizada[71];

    normalizar(cadNormalizar, cadNormalizada);

    printf("Cadena normalizada: %s\n", cadNormalizada);

    return 0;
}
