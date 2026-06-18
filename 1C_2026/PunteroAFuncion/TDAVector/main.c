#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "utilidades.h"
#include <memory.h>

#define TAM_ELEM    sizeof(int)
#define CAP_MAX     10

tVector* map(tVector* v, int action(void*));

int filter(void* v, size_t ce, size_t tam, int ffilter(const void*));
int filterPocoEficiente(void* v, size_t ce, size_t tam, int ffilter(const void*));
int filterMayor10(const void * d);
int filterDistinto2(const void* d);

void mostrarVectorSinTDA(void* v, size_t ce, size_t tam, Mostrar mostrar);

void reduce(void * v, size_t ce, size_t tam, int* dato, int freduce(void* d, const void* v));
int reduceAcumulador(void* d, const void* v);

void ssort(void* vec, size_t ce, size_t tam, Comparar cmp);
void* buscarMenor(void* ini, void* fin, size_t tamElem, Comparar cmp);
void* mbsearch(const void* clave, const void* vec, size_t ce, size_t tam, Comparar cmp);
void intercambiar(void* d1, void* d2, size_t tam);

int main()
{
    int vLote[5] = {88, 3, 7, 2, 5};
    size_t ce = sizeof(vLote) / TAM_ELEM;
    int clave = 120;
    int* pos = NULL;

    ssort(vLote, 5, sizeof(int), compararInt);

    for(size_t i = 0; i < ce; i++)
    {
        mostrarInt(&vLote[i]);
    }

    pos = mbsearch(&clave, vLote, ce, sizeof(int), compararInt);

    if(pos != NULL)
    {
        printf("Existe el dato:");
        mostrarInt(pos);
    }

    return 0;
}

tVector* map(tVector* v, int action(void*))
{
    void* aux = v->vec;

    for(int i = 0; i < v->ce; i++)
    {
        action(aux);
        aux += v->tamElem;
    }

    return v;
}

int filter(void* v, size_t ce, size_t tam, int ffilter(const void*))
{
    void* pLec = v;
    void* pEsc = v;
    void* fin = v + ((ce - 1) * tam);

    while(pLec < fin)
    {
        if(ffilter(pLec))
        {
            intercambiar(pLec, pEsc, tam);
            pEsc += tam;
            pLec += tam;
            ce--;
        }
        else
        {
            pLec += tam;
        }
    }

    return ce;
}

int filterPocoEficiente(void* v, size_t ce, size_t tam, int ffilter(const void*))
{
    void* elim = NULL;
    void* fin = v + (ce * tam);
    for(int i = 0; i < ce; i++)
    {
        if(ffilter(v))
        {
            v += tam;
        }
        else
        {
            elim = v;
            while(elim < fin - tam)
            {
                memcpy(elim, elim + tam, tam);
                elim += tam;
            }
            ce--;
        }
    }

    return ce;
}

int filterMayor10(const void * d)
{
    return(*(int*)d > 10);
}

int filterDistinto2(const void* d)
{
    return(*(int*)d != 2);
}
void mostrarVectorSinTDA(void* v, size_t ce, size_t tam, Mostrar mostrar)
{
    void* act = v;
    void* fin = v + ((ce - 1) * tam);

    while(act < fin)
    {
        mostrar(act);
        act += tam;
    }
}



/**Revisar**/
void reduce(void * v, size_t ce, size_t tam, int* dato, int freduce(void* d, const void* v))
{
    printf("%d", *dato);
}


int reduceAcumulador(void* d, const void* v)
{
    *(int*)d += *(int*)v;

    return 1;
}

void ssort(void* vec, size_t ce, size_t tam, Comparar cmp)
{
    char* ult = (char*)vec + (ce - 1) * tam;
    char* menor;

    for(char* pLec = (char*)vec; pLec < ult; pLec += tam)
    {
        menor = buscarMenor(pLec, ult, tam, cmp);
        intercambiar(menor, pLec, tam);
    }
}


void* buscarMenor(void* ini, void* fin, size_t tamElem, Comparar cmp)
{
    char* menor = (char*)ini;

    for(char* pLec = (char*)ini + tamElem; pLec <= (char*)fin; pLec += tamElem)
    {
        if(cmp(pLec, menor) < 0)
        {
            menor = pLec;
        }
    }

    return menor;
}

void* mbsearch(const void* clave, const void* vec, size_t ce, size_t tam, Comparar cmp)
{
    char* ini = (char*)vec;
    char* fin = ini + (ce - 1) * tam;

    while(ini <= fin)
    {
        char* pm = ini +(((fin - ini) / tam) / 2) * tam;

        int comp = cmp(clave, pm);

        if(comp == 0)
            return pm;

        if(comp < 0)
            fin = pm - tam;
        else
            ini = pm + tam;
    }

    return NULL;
}

void intercambiar(void* d1, void* d2, size_t tam)
{
    void* aux = malloc(tam);

    memcpy(aux, d1, tam);
    memcpy(d1, d2, tam);
    memcpy(d2, aux, tam);

    free(aux);
}
