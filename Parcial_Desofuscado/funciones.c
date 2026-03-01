#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define PATH_TEMP   "tmp.txt"

/**Funcion principal**/
int desofuscarArchivoTxt(const char* path)
{
    char linea[TAM_LINEA];
    FILE* txt = fopen(path, "rt");

    if(!txt)
        return ERR_ARCH;

    FILE* tmp = fopen(PATH_TEMP, "wt");

    if(!tmp)
    {
        fclose(txt);
        return ERR_ARCH;
    }

    while(fgets(linea, TAM_LINEA, txt))
    {
        desofuscar(linea);
        fprintf(tmp, "%s\n", linea);
    }

    fclose(txt);
    fclose(tmp);

    remove(path);
    rename(PATH_TEMP, path);

    return TODO_OK;
}
/**funciones desofuscar**/
char* desofuscar(char* s)
{
    tSecPal sLect;
    crearSecPal(&sLect, s);

    char linea[TAM_LINEA];
    tSecPal sEscr;
    crearSecPal(&sEscr, linea);

    tPalabra pal;

    while(leerPalabra(&sLect, &pal))
    {
        cambiarLetrasPalabra(&pal);
        darVueltaPalabra(&pal);
        escribirPalabra(&sEscr, &pal);
        escribirCaracter(&sEscr, ' ');
    }

    moverPunteroSecPal(&sEscr, -1);
    escribirCaracter(&sEscr, '\0');

    str_cpy(s, linea);

    return s;
}

void cambiarLetrasPalabra(tPalabra* pal)
{
    char clave[] = "fedcba";
    size_t tamClave = str_len(clave);

    char* act = pal->pal;
    char* posi;

    while(*act)
    {
        posi = buscarElemento(clave, tamClave, sizeof(char), act, cmpCaracter);

        if(posi != NULL)
        {
            *act = *(clave + ((tamClave - 1) - ((posi - clave) / sizeof(char))));
        }

        act++;
    }
}

void darVueltaPalabra(tPalabra* pal)
{
    size_t tam = str_len(pal->pal);

    char* pri= pal->pal;
    char* ult = pal->pal + (tam - 1);
    char aux;

    while(pri < ult)
    {
        aux = *pri;
        *pri = *ult;
        *ult = aux;

        ult--;
        pri++;
    }
}
/**Funciones auxiliares**/
int mostrarArchivoTxt(const char* path)
{
    FILE* txt = fopen(path, "rt");

    if(!txt)
        return ERR_ARCH;

    char linea[TAM_LINEA];

    while(fgets(linea, TAM_LINEA, txt))
    {
       printf("%s", linea);
    }

    fclose(txt);

    return TODO_OK;
}

int cmpCaracter(const void* c1, const void *c2)
{
    return(*(char*)c1 - *(char*)c2);
}

void* buscarElemento(void* vec, int ce, size_t tamElem, void* elem, Comparar comparar)
{
    void* act = vec;
    void* ult = vec + tamElem * (ce - 1);

    while(act <= ult)
    {
        if(comparar(act, elem) == 0)
        {
            return act;
        }
        act++;
    }

    return NULL;
}
/**Seccion palabara Palabra**/

void crearSecPal(tSecPal* sec, char* s)
{
    sec->pSec = s;
    sec->finSecPal = false;
}

void finalSecPal(tSecPal* sec)
{
    sec->finSecPal = true;
}

void escribirPalabra(tSecPal* sec, const tPalabra* pal)
{
    const char* act = pal->pal;

    while(*act)
    {
        *sec->pSec = *act;
        sec->pSec++;
        act++;
    }
}

void escribirCaracter(tSecPal* sec, const char c)
{
    *sec->pSec = c;
    sec->pSec++;
}

void moverPunteroSecPal(tSecPal* sec, int n)
{
    sec->pSec += n;
}

bool leerPalabra(tSecPal* sec, tPalabra* pal)
{
    while(*sec->pSec && !ES_LETRAS(*sec->pSec))
        sec->pSec++;

    if(!*sec->pSec)
    {
        finalSecPal(sec);
        return false;
    }

    char* act = pal->pal;

    while(*sec->pSec && ES_LETRAS(*sec->pSec))
    {
        *act = *sec->pSec;
        act++;
        sec->pSec++;
    }

    *act = '\0';

    return true;
}
/**Funciones de string.h**/
size_t str_len(const char* s)
{
    size_t cont = 0;

    while(*s)
    {
        cont++;
        s++;
    }

    return cont++;
}

char* str_cpy(char* s1, const char* s2)
{
    char* p1 = s1;

    while(*s2)
    {
        *p1 = *s2;
        p1++;
        s2++;
    }

    *p1 = '\0';

    return s1;
}
