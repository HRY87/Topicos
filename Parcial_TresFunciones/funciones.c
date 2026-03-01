#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "funciones.h"
/**Ejercicio 1: Ordenar seleccion generico**/
void _ordenarSeleccion(void* base, size_t nmemb, size_t tamanyo, Comparar comparar)
{
    void* ult = base + tamanyo * (nmemb - 1);
    void* posMenor = NULL;

    while(base < ult)
    {
        posMenor = buscarMenor(base, nmemb, tamanyo, comparar);

        if(posMenor != base)
        {
            intercambiarElemento(base, posMenor, tamanyo);
        }

        base += tamanyo;
        nmemb--; //Reducimos la longuitud de busqueda
    }
}

void* buscarMenor(void* base, size_t nmemb, size_t tamanyo, Comparar comparar)
{
    void* ult = base + tamanyo * (nmemb - 1);
    void* pos = base;

    while(base < ult)
    {
        base += tamanyo;
        if(comparar(base, pos) < 0)
        {
            pos = base;
        }
    }

    return pos;
}

void intercambiarElemento(const void* a, const void* b, size_t bytes)
{
    char* pa = (char*)a;
    char* pb = (char*)b;
    char aux;

    while(bytes)
    {
        aux = *pa;
        *pa= *pb;
        *pb = aux;

        pa++;
        pb++;
        bytes--;
    }
}

int compararInt(const void* a, const void* b)
{
    return(*(int*)a - *(int*)b);
}

int prueba_ordenarSeleccionGenerico()
{
    int v1[] = {23, 53, 1, 634, 7};

    int ce1 = sizeof(v1) / sizeof(int);

    _ordenarSeleccion(v1, ce1, sizeof(int), compararInt);

    for(int i = 0; i < ce1; i++)
    {
        printf(" -%d-", v1[i]);
    }

    return 0;
}

/**Ejercicio 2: Contar celulas vivas dado una posicion fila/columna**/
size_t _contarCelulasVivasEnVecindario(int** m, int fil, int col, int posF, int posC)
{
    size_t cont = 0;
    int nueFil = posF, nueCol = posC;

    if(!m)
        return cont;

    for(int i  = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if(i == 0 && j == 0)
                continue;

            nueFil = posF + i;
            nueCol = posC + j;

            if((nueFil >= 0 && nueFil < fil) && (nueCol >= 0 && nueCol < col))
            {
                if(m[nueFil][nueCol] == 1)
                {
                    cont++;
                }
            }
        }
    }

    return cont;

}
void** crearMatriz(size_t fil, size_t col, size_t tamElem)
{
    void** m = (void**)malloc(fil * sizeof(void*));

    if(!m)
        return NULL;

    for(size_t i = 0; i < col; i++)
    {
        m[i] = malloc(col* tamElem);

        if(!m[i])
        {
            destruirMatriz(m, fil);
            return NULL;
        }
    }

    return m;
}

void destruirMatriz(void** m, size_t fil)
{
    for(size_t i = 0; i < fil; i++)
    {
        free(m[i]);
    }

    free(m);
}

void mostrarMatriz(int** m, size_t fil, size_t col)
{
    for(size_t i = 0; i < fil; i++)
    {
        for(size_t j = 0; j < col; j++)
        {
            printf("%d ", m[i][j]);
        }

        puts("");
    }
}

int inicializarMatriz(int** m, size_t fil, size_t col)
{
    srand(time(NULL));

    if(!m)
        return -1;

    for(size_t i = 0; i < fil; i++)
    {
        for(size_t j = 0; j < col; j++)
        {
            m[i][j] = rand() % 2;
        }
    }

    return 0;
}

int prueba_juegoDeLaVida(int fil, int col)
{
    int** m = (int**)crearMatriz(fil, col, sizeof(int));
    int posF, posC;
    size_t contVidas = 0;
    char opc = 'n';

    if(!m)
        return -1;

    inicializarMatriz(m, fil, col);
    mostrarMatriz(m, fil, col);
    printf("Matriz %dx%d\n", fil, col);

    do
    {



        puts("Ingrese posicion(fila/columna):");
        scanf("%d/%d", &posF, &posC);

        contVidas = _contarCelulasVivasEnVecindario(m, fil, col, posF, posC);

        printf("En la posicion [%d,%d]: Hay %llu celulas vivas\n",posF, posC, contVidas);

        puts("Desea buscar otra posicion (s/n):");
        fflush(stdin);
        scanf(" %c", &opc);

    }
    while(tolower(opc) == 's');

    destruirMatriz((void**)m, fil);

    return 0;
}

/**Ejercicio 3: Hacer a una version de strstr**/
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
    char* c1 = "como nada el que nadando anda";
    char* c2 = "anda";

    char* p = msstr(c1, c2);
    char* f = strstr(c1, c2);

    printf("Cadena 1: -%s-\n", c1);
    printf("Cadena 2: -%s-\n", c2);
    printf("Puntero: -%s-\n", p);
    printf("Funcion: -%s-\n", f);

    return 0;
}
