#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include "funciones.h"

/**Ejercicio 1: Hacer contar palabras**/
tPalabra* contarPalabrasMio(const char* pathTxt, tPalabra* pal)
{
    FILE* txt = fopen(pathTxt, "rt");

    if(!txt)
        return NULL;

    char linea[TAM_LINEA];
    pal->cantRepeticiones = 0;
    int cantPalabras = 0;

    while(fgets(linea, TAM_LINEA, txt))
    {
        cantPalabras += palabraMasLargaYContarPalabras(pal, linea);
    }

    printf("Cantidad de palabras en el archivo %s: %d\n", pathTxt, cantPalabras);

    fclose(txt);

    return pal;
}

int palabraMasLargaYContarPalabras(tPalabra* palLarga, char* linea)
{
    int cantPalabras = 0;
    char* act = str_chr(linea, '\n');

    if(!act)
        return 0;

    *act = '\0';

    tSecPal sLect;
    crearSecPal(&sLect, linea);

    tPalabra pal;

    while(leerPalabra(&sLect, &pal))
    {
        if(compararPalabra(&pal, palLarga) > 0)
        {
            str_cpy(palLarga->pal, pal.pal);
            palLarga->cantRepeticiones = 1;
        }else if(compararPalabra(&pal, palLarga) == 0)
        {
            palLarga->cantRepeticiones++;
        }

        cantPalabras++;
    }

    return cantPalabras;
}

int compararPalabra(const tPalabra* p1, const tPalabra* p2)
{
    return(str_len(p1->pal) - str_len(p2->pal));
}

void crearSecPal(tSecPal* sec, char* s)
{
    sec->pSec = s;
    sec->finSec = false;
}

bool leerPalabra(tSecPal* sec, tPalabra* pal)
{
    while(*sec->pSec && !ES_LETRA(*sec->pSec))
        sec->pSec++;

    if(*sec->pSec == '\0')
    {
        sec->finSec = true;
        return false;
    }

    char* pPal = pal->pal;

    while(*sec->pSec && ES_LETRA(*sec->pSec))
    {
        *pPal = *sec->pSec;
        pPal++;
        sec->pSec++;
    }

    *pPal = '\0';

    return true;
}

int str_len(const char* s)
{
    int cont = 0;

    while(*s)
    {
        cont++;
        s++;
    }

    return cont;
}

char* str_chr(char* s, int c)
{
    char* ultAparacion = NULL;

    while(*s)
    {
        if(*s == c)
            ultAparacion = s;

        s++;
    }

    return ultAparacion;
}

char* str_cpy(char* dest, const char* orig)
{
    char* pDest = dest;

    while(*orig)
    {
        *pDest = *orig;
        pDest++;
        orig++;
    }

    *pDest = '\0';

    return dest;
}

int prueba_contarPalabras()
{
    tPalabra pal;

    contarPalabrasMio(PATH_TXT, &pal);

    printf("La palabra mas larga: %s\nCantidad de apariciones: %llu\n", pal.pal, pal.cantRepeticiones);

    return 0;
}

/**Ejercicio 2: Validar matriz campeonato**/
bool esMatrizCampeonatoValidaMio(int** m, int n)
{
    int puntos[6] = {0, 1, 2, 3, 4, 6};
    int resEsperado;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                int* posi = (int*)busquedaBinaria(puntos, 6, sizeof(int), &m[i][j], cmpEnteros);

                if(!posi)
                    return false;

                resEsperado = (*posi == 2 || *posi == 3) ? *posi :
                    puntos[(6 - 1) - (posi - puntos)];

                if(m[j][i] != resEsperado)
                    return false;
            }
        }
    }
    return true;
}
void **matrizCrear(int n, size_t tamElem)
{
    void **m = malloc(n * sizeof(void *));
    if (!m)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        m[i] = malloc(n * tamElem);

        if (!m[i])
        {
            matrizDestruir(m, i);
            return NULL;
        }
    }
    return m;
}

void matrizDestruir(void **m, int n)
{
    for (int i = 0; i < n; i++)
        free(m[i]);

    free(m);
}

void matrizMostrar(int **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void matrizInicializar(int** m, int n)
{
    int resultados[6][2] = {
        {6,0},
        {0,6},
        {4,1},
        {1,4},
        {3,3},
        {2,2}
    };

    int pos = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i == j)
            {
                m[i][j] = 0;
            }
            else
            {
                pos = rand() % 6;

                m[i][j] = resultados[pos][0];
                m[j][i] = resultados[pos][1];
            }
        }
    }
}

int cmpEnteros(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void *busquedaBinaria(const void *v, int ce, size_t tamElem, const void *elem, Comparar cmp)
{
    const void *izq = v;
    const void *der = v + tamElem * (ce - 1);
    const void *mid;

    while (izq <= der)
    {
        mid = izq + ((der - izq) / (2 * tamElem)) * tamElem;

        if (cmp(mid, elem) == 0)
            return (void *)mid;

        else if (cmp(mid, elem) < 0)
            izq = mid + tamElem;

        else
            der = mid - tamElem;
    }

    return NULL;
}

int prueba_matrizCampeonato(int n)
{
    int** m = (int**)matrizCrear(n, sizeof(int));

    if(!m)
        return -1;

    matrizInicializar(m, n);

    matrizMostrar(m, n);

    if(esMatrizCampeonatoValidaMio(m, n))
    {
        puts("Es una matriz valida");
    }else
    {
        puts("No es una matriz valida");
    }
    matrizDestruir((void**)m, n);

    return 0;
}
