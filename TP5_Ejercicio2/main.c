#include <stdio.h>
#include <stdlib.h>
#include "texto.h"

int main()
{
    char texto[] = "veces...tantas veces, muchas veces, pocas veces, algunas veces, veces sera... infinitesimal";
    int contPal = 0;
    buscarYContarPalabra(texto);

    if((contPal = contarTodasLaaPalabras(texto)))
        printf("Hay %d palabras en el texto\n", contPal);

    printf("La palabra mas larga del texto es de %d letras", longuitudPalabraMasLarga(texto));
    return 0;
}
