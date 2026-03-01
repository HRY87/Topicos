#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <time.h>
#include "funciones.h"

#define ES_LETRA(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z'))
#define TAM_PAL     51

/**Ejercicio 1: Hacer a una version de strstr**/
char* msstr(const char* s1, const char* s2)
{
    size_t tam1 = str_len(s1);
    size_t tam2 = str_len(s2);

    if (tam1 < tam2)
        return NULL;
    if (!*s2)
        return (char*)s1;

    char* buffer = (char*)malloc(TAM_PAL);
    if (!buffer)
        return NULL;

    while (*s1)
    {
        // Saltar lo que no es letra
        while (*s1 && !ES_LETRA(*s1))
            s1++;

        if (!*s1) break;

        // Guardar dónde empieza la palabra en s1
        const char* inicio_palabra = s1;

        // Extraer la palabra en buffer usando índice, no moviendo el puntero base
        char* pal = buffer;
        while (*s1 && ES_LETRA(*s1))
        {
            *pal = *s1;
            s1++;
            pal++;
        }
        *pal = '\0';

        if (strcmpi(buffer, s2) == 0)
        {
            free(buffer);
            return (char*)inicio_palabra; // Retorna donde empieza la coincidencia
        }
    }

    free(buffer);
    return NULL;
}

size_t str_len(const char* s)
{
    size_t tam = 0;

    while(*s)
    {
        tam++;
        s++;
    }

    return tam;
}

int prueba_msstr()
{
    char* c1 = "como nada el tipo que anda en el agua";
    char* c2 = "tipo";

    char* p = msstr(c1, c2);
    char* f = strstr(c1, c2);

    printf("Cadena 1: -%s-\n", c1);
    printf("Cadena 2: -%s-\n", c2);
    printf("Puntero: -%s-\n", p);
    printf("Funcion: -%s-\n", f);

    return 0;
}

/**Ejercicio 2: Hacer transponer matriz cuadrada in situ**/
int transponerMatrizCuadradaInSitu(int** m, size_t n)
{
    int aux;

    for(size_t i = 1; i < n; i++)
    {
        for(size_t j = 0; j < i; j++)
        {
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
    return 0;
}

int** crearMatrizCuadrada(size_t n)
{
    int** m = (int**)malloc(n * sizeof(int*));

    if(!m)
        return NULL;

    for(size_t i = 0; i < n; i++)
    {
        m[i] = (int*)malloc(n * sizeof(int));

        if(!m[i])
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

int inicializarMatrizCuadrada(int** m, size_t n, int limInf, int limSup)
{
    srand(time(NULL));

    if(!m)
        return -1;

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            m[i][j] = rand()% (limSup - limInf + 1) + limInf;
        }
    }
    return 0;
}

void mostrarMatrizCuadrada(int** m, size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
           printf("%d ", m[i][j]);
        }
        puts("");
    }
}

int prueba_transponerInSitu(size_t n, int limInf, int limSup)
{

    int** m = crearMatrizCuadrada(n);

    if(!m)
        return -1;

    inicializarMatrizCuadrada(m, n, limInf, limSup);

    puts("---Matriz original---");
    mostrarMatrizCuadrada(m, n);

    puts("---Matriz transpuesta---");
    transponerMatrizCuadradaInSitu(m, n);
    mostrarMatrizCuadrada(m, n);

    destruirMatriz(m, n);

    return 0;
}

/**Ejercicio 3: Hacer insertar ordenado**/
bool insertarVectorOrdenado(void* v, size_t* ce, size_t cap, void* dato, size_t tam, Comparar comparar, int orden)
{
    bool asc = orden == ORDEN_ASCENDENTE ? true : false;
    int comp;

    void* act = v;
    void* ult = v + (tam * (*ce - 1));

    if(cap == *ce)
    {
        if(asc)
        {
            comp = comparar(ult, dato);

            if(asc == (comp > 0))
            {
                memcpy(ult, dato, tam);
                return false; //Se pierden datos
            }else
            {
                if(comp < 0)
                {
                    return false; //No se insertar
                }else
                {
                    ult -= tam;
                }
            }

        }
    }

    while(act <= ult)
    {
        comp = comparar(act, dato);

        if(asc ? comp > 0: comp < 0)
            break;

        act += tam;
    }

    for(void* i = ult; i >= act; i -= tam)
    {
        memcpy(i + tam, i, tam);
    }

    memcpy(act, dato, tam);

    cap == (*ce) ? *ce : (*ce)++;

    return true;
}

int cmpInt(const void* d1, const void* d2)
{
    return(*(int*)d1 - *(int*)d2);
}

int prueba_insertarOrdenado()
{
    int vec[10] = {0, 2, 3, 1, 5, 4, 7, 8, 9, 10};
    int vec2[5];
    size_t cap2 = 5;
    size_t ce2 = 0;

    for (int i = 0; i < 10; i++)
    {
        insertarVectorOrdenado(vec2, &ce2, cap2, &vec[i], sizeof(int), cmpInt, ORDEN_ASCENDENTE);
    }

    printf("\n\n");
    for (int i = 0; i < ce2; i++)
        printf("%d ", vec2[i]);

    return 0;
}
