#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include "funciones.h"

/**Ejercicio 1: Hacer la version propia  de strcat**/
#define TAM_CAD     51

char* mstcat(char* s1, const char* s2)
{
    char* pIni = s1;

    if(!s1 || !s2)
        return NULL;

    while(*s1)
    {
        s1++;
    }

    while(*s2)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }

    *s1 = '\0';

    return pIni;
}

int prueba_mstcat()
{
    char s1[TAM_CAD], s2[TAM_CAD];

    puts("Ingrese cadena 1:");
    fgets(s1, TAM_CAD, stdin);
    s1[str_cspn(s1,  "\n")] = '\0';

    puts("Ingrese cadesa 2:");
    fgets(s2, TAM_CAD, stdin);
    s2[str_cspn(s2,  "\n")] = '\0';

    if(!*s1 || !*s2)
        return ERROR;


    printf("Cadena 1: -%s-\n", s1);
    printf("Cadena 2: -%s-\n", s2);


    mstcat(s1, s2);
    printf("mstcart: -%s-\n", s1);

    return TODO_OK;

}


size_t str_cspn(const char* s1, const char* s2)
{
    size_t cont = 0;
    const char* ps2 = NULL;

    if(!s1 || !s2)
        return cont;

    while(*s1)
    {
        ps2 = s2;

        while(*ps2)
        {
            if(*s1 == *ps2)
                return cont;

            ps2++;
        }
        cont++;
        s1++;
    }

    return cont;
}

/**Ejercicio 2: Hacer la version propia  de strcat**/

int sumaTrianInfEntreDiag(int** m, size_t fil, size_t col)
{
    int suma= 0;
    int k = 0;

    int topeMedio = fil / 2 + 1;
    int topeEspejo = fil / 2 - 1;

    if (fil % 2 != 0)
        for (int i = topeMedio; i < fil; i++)
            suma += m[i][topeEspejo + 1];

    for (int i = fil - 1; i >= topeMedio; i--)
    {
        k++;
        for (int j = k; j <= topeEspejo; j++)
        {
            suma += m[i][j];
            suma += m[i][fil - j - 1];
        }
    }

    return suma;
}

int prueba_SumaTriangInfEntreDiag(size_t fil, size_t col, size_t limInf, size_t limSup)
{
    if(fil <= 0 || col <= 0)
        return ERROR;

    int** m = crearMatriz(fil, col);

    if(!m)
        return ERROR;

    inicializarMatriz(m, fil, col, limInf, limSup);

    matrizMostrar(m, fil, col);

    int suma = sumaTrianInfEntreDiag(m, fil, col);

    printf("La suma del triangulo inferior entre diagonales es: %d\n", suma);

    destruirMatriz(m, fil);

    return TODO_OK;
}

int** crearMatriz(size_t fil, size_t col)
{
    int** m = (int**)malloc(fil * sizeof(int*));

    if(!m)
        return NULL;

    for(size_t i = 0; i < fil; i++)
    {
        m[i] = (int*)malloc(col * sizeof(int));

        if(m[i] == NULL)
        {
            destruirMatriz(m, i);
            return NULL;
        }
    }

    return m;
}

void destruirMatriz(int** m, size_t fil)
{
    for(size_t i = 0; i < fil; i++)
    {
        free(m[i]);
    }

    free(m);
}
int inicializarMatriz(int** m, size_t fil, size_t col, int limInf, int limSup)
{

    if(!m)
        return ERROR;

    srand(time(NULL));

    for(size_t i = 0; i < fil; i++)
    {
        for(size_t j = 0; j < col; j++)
        {
            m[i][j] = rand() % (limSup - limInf + 1) + limInf;
        }
    }

    return TODO_OK;
}

void matrizMostrar(int** m, int fil, int col)
{
    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d\t", m[i][j]);

        }

        puts("");
    }
}

/**Ejercicio 3: Hacer version propia de bsearch, buscar generico**/
void *mbsearch(const void *clave, const void *base, size_t ce, size_t tamElem, Comparar cmp)
{
    const void *izq = base;
    const void *der = base + tamElem * (ce - 1);

    const void *med;
    int comp;

    while (izq <= der)
    {
        med = izq + ((der - izq) / (2 * tamElem)) * tamElem;

        comp = cmp(med, clave);

        if (comp == 0)
            return (void *)med;

        else if (comp < 0)
            izq = med + tamElem;

        else
            der = med - tamElem;
    }

    return NULL;
}

int prueba_mbsearch(int v[], int ce, int clave)
{
    if(ce == 0)
        return ERROR;

    int* res = mbsearch(&clave, v, ce, sizeof(int), cmpEnteros);

    if(res)
    {
        printf("Encontrado: %d\n", *res);
    }else
    {
        puts("No encontrado");
    }

    return TODO_OK;
}
int cmpEnteros(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
