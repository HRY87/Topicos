#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TAM_LINEA   1024

#define ES_MAYUSCULA(X)((X) >= 'A' && (X) <= 'Z')
#define ES_MINUSCULA(X)((X) >= 'a' && (X) <= 'z')
#define A_MINUSCULA(X)(ES_MAYUSCULA(X) ? (X) + ('a' - 'A') : (X))
#define ES_LETRA(X)(ES_MAYUSCULA(X) || ES_MINUSCULA(X))

#define RUTA_TXT_TEXTO    "texto.txt"
#define RUTA_TXT_PRUEBA    "prueba.txt"

typedef struct
{
    char* ini;
    char* fin;
} tSecPal;

typedef struct
{
    char palLarga[41];
    size_t cant_repeticiones;
} tPalabra;

size_t contarPalabrasArchivo(const char* rutaArchivo, tPalabra* pal);
size_t buscarPalabra(const char* linea, tSecPal* secPal);
char* copiarPalabra(tPalabra* pal, tSecPal* secPal);
int str_cmpi(const char* s1, const char* s2);
void inicializarPalabra(tPalabra* pal);
size_t str_len(const char* s);
int compararLargoCadena(const char* s1, const char* s2);
char* str_cpy(char* dest, const char* orig);
int main()
{
    tPalabra palLarga;
    printf("Cantidad de palabras: %llu\n", contarPalabrasArchivo(RUTA_TXT_TEXTO, &palLarga));

    printf("Palabra larga: %s | Repeticiones: %llu\n", palLarga.palLarga, palLarga.cant_repeticiones);
    return 0;
}

size_t contarPalabrasArchivo(const char* rutaArchivo, tPalabra* pal)
{
    char* linea = NULL;
    tSecPal secPal;
    tPalabra palActual;
    size_t desplazamiento = 0;
    FILE* txt = fopen(rutaArchivo, "rt");
    size_t cantPalabras = 0;
    char* pLinea;
    int comp;

    if(!txt)
        return 0;

    linea = malloc(TAM_LINEA);

    if(!linea)
    {
        fclose(txt);
        return 0;
    }

    inicializarPalabra(pal);

    fgets(linea, TAM_LINEA, txt);

    while(!feof(txt))
    {
        pLinea = linea;
        while(*pLinea && *pLinea != '\n')
        {
            desplazamiento = buscarPalabra(pLinea, &secPal);

            if(desplazamiento > 0)
            {
                copiarPalabra(&palActual, &secPal);
                palActual.cant_repeticiones = 1;
                comp = compararLargoCadena(palActual.palLarga, pal->palLarga);

                if(comp > 0)
                {
                    copiarPalabra(pal, &secPal);
                    pal->cant_repeticiones = 1;
                }

                if(comp == 0)
                    pal->cant_repeticiones++;

                cantPalabras++;
            }

            pLinea = secPal.fin;
        }
        fgets(linea, TAM_LINEA, txt);
    }

    fclose(txt);
    free(linea);
    return cantPalabras;
}

size_t buscarPalabra(const char* linea, tSecPal* secPal)
{
    size_t tamPalabra = 0;

    if(!*linea)
        return tamPalabra;

    while(*linea && !ES_LETRA(*linea))
    {
        linea++;
    }

    secPal->ini = (char*)linea;

    while(*linea && ES_LETRA(*linea))
    {
        tamPalabra++;
        linea++;
    }

    secPal->fin = (char*)linea;

    return tamPalabra;
}

char* copiarPalabra(tPalabra* pal, tSecPal* secPal)
{
    char* ini = pal->palLarga;
    char* pPal = pal->palLarga;
    char* pSec = secPal->ini;

    while(pSec < secPal->fin)
    {
        *pPal = *pSec;
        pPal++;
        pSec++;
    }

    *pPal = '\0';

    return ini;
}

int str_cmpi(const char* s1, const char* s2)
{
    while(*s1 && *s2 && A_MINUSCULA(*s1) == A_MINUSCULA(*s2))
    {
        s1++;
        s2++;
    }

    return(*s1 || *s2? *(char*)s1 - *(char*)s2 : 0);
}

size_t str_len(const char* s)
{
    size_t tam = 0;

    while(*s)
    {
       s++;
       tam++;
    }

    return tam;
}

char* str_cpy(char* dest, const char* orig)
{
    char* ini = dest;

    while(*orig)
    {
        *dest = *orig;
        dest++;
        orig++;
    }

    return ini;
}
int compararLargoCadena(const char* s1, const char* s2)
{
    if(str_cmpi(s1, s2) == 0)
        return 0;

    return((int)str_len(s1) - str_len(s2));
}
void inicializarPalabra(tPalabra* pal)
{
    str_cpy(pal->palLarga, "");
    pal->cant_repeticiones = 0;
}
