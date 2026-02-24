#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "texto.h"

#define TODO_OK     0
#define SIN_TEXTO   1

#define ES_DIGITO(X)(X >= '0' && X <= '9')
#define ES_MAYUSCULA(X)(X >= 'A' && X <= 'Z')
#define ES_MINUSCULA(X)(X >= 'a' && X <= 'z')
#define ES_CARACTER_VALIDO(X)(ES_MAYUSCULA(X) || ES_MINUSCULA(X))

void buscarYContarPalabra(const char* texto)
{
    char pal[25];
    int contPal = 0;

    buscarPrimeraPalabra(texto, pal);

    if((contPal = contarPalabra(texto, pal)))
        printf("Se repite %d veces en el texto\n", contPal);

}

int buscarPrimeraPalabra(const char* texto, char* pal)
{
    char* pLect = (char*)texto;
    int tamPalabra = 0;

    if(!*pLect)
        return 0;

    while(*pLect && !ES_CARACTER_VALIDO(*pLect))
        pLect++;

    while(*pLect && ES_CARACTER_VALIDO(*pLect))
    {
        *pal = *pLect;
        pal++;
        pLect++;
        tamPalabra++;
    }

    *pal = '\0';

    return tamPalabra;
}

int contarPalabra(const char* texto, const char* pal)
{
{
    char* pLec = (char*)texto;
    char* pPal =  NULL;
    int contPal = 0;

    if(!*pLec)
        return 0;

    while(*pLec)
    {
        if(*pLec == *pal)
        {
            pPal = (char*)pal;

            while(*pLec == *pPal)
            {
                pLec++;
                pPal++;
            }

            if(!*pPal)
                contPal++;
        }
        pLec++;
    }

    return contPal;
}
}

int contarTodasLaaPalabras(const char* texto)
{
    char* pLect = (char*)texto;
    int contPalabra = 0;

    if(!*pLect)
        return 0;

    while(*pLect)
    {
        while(*pLect && !ES_CARACTER_VALIDO(*pLect))
            pLect++;

        if(ES_CARACTER_VALIDO(*pLect))
            contPalabra++;

        while(*pLect && ES_CARACTER_VALIDO(*pLect))
            pLect++;

    }

    return contPalabra;
}

int longuitudPalabraMasLarga(const char* texto)
{
    char* pLect = (char*)texto;
    int tamPal = 0, tamMax = 0;

    if(!*pLect)
        return 0;

    while(*pLect)
    {
        while(*pLect && !ES_CARACTER_VALIDO(*pLect))
            pLect++;

        tamPal = 0;

        while(*pLect && ES_CARACTER_VALIDO(*pLect))
        {
            tamPal++;
            pLect++;
        }

        if(tamPal > tamMax)
            tamMax = tamPal;
    }

    return tamMax;
}
