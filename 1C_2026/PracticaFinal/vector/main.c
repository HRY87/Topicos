#include <stdio.h>
#include <stdlib.h>

#define TAM_INT     sizeof(int)
#define TAM_PROD    sizeof(tProducto)
typedef struct
{
    unsigned id;
    int cantidad;
} tProducto;

void mostrarVector(void* vec, size_t tamElem, size_t cantElem, void mostrar(const void*));
void mostrarInt(const void* dato);
void mostrarProducto(const void* dato);
void mapVector(void* vec, size_t tamElem, size_t cantElem, int map(void*));
int mapDuplicarValor(void* dato);
void reducirVector(void* vec, size_t tamElem, size_t* cantElem, int comparar(const void*, const void*), int reduce(void*, const void*));
int reduceAcumularInt(void* acum, const void* dato);
int reduceAcumularProducto(void* acum, const void* dato);
int compararInt(const void* d1, const void* d2);
int compararProducto(const void* d1, const void* d2);
void eliminarElemento(void* vec, size_t tamElem, size_t* cantElem, int pos);
int main()
{
    //int vector[] = {2, 1, 2, 4, 1, 1, 3, 5};
    tProducto vProd[] =
    {
        {1, 10},
        {2, 10},
        {1, 10},
        {2, 10},
        {2, 10},
        {4, 10}
    };
    //size_t ce = sizeof(vector) / TAM_INT;
    size_t ceProd = sizeof(vProd) / TAM_PROD;

    //mostrarVector(vector, TAM_INT, ce, mostrarInt);
    mostrarVector(vProd, TAM_PROD, ceProd, mostrarProducto);
    puts("");

    //mapVector(vector, TAM_INT, ce, mapDuplicarValor);
    //reducirVector(vector, TAM_INT, &ce, compararInt, reduceAcumularInt);
    reducirVector(vProd, TAM_PROD, &ceProd, compararProducto, reduceAcumularProducto);

    mostrarVector(vProd, TAM_PROD, ceProd, mostrarProducto);
    puts("");

    return 0;
}

void mostrarVector(void* vec, size_t tamElem, size_t cantElem, void mostrar(const void*))
{
    for(int i = 0; i < cantElem; i++)
    {
        mostrar(vec);

        vec += tamElem;
    }
}

void mostrarInt(const void* dato)
{
    printf("%d\t", *(int*)dato);
}

void mostrarProducto(const void* dato)
{
    tProducto* prod = (tProducto*)dato;
    printf("|%u %d|\t", prod->id, prod->cantidad);
}

void mapVector(void* vec, size_t tamElem, size_t cantElem, int map(void*))
{
    for(int i = 0; i < cantElem; i++)
    {
        map(vec);

        vec += tamElem;
    }
}

int mapDuplicarValor(void* dato)
{
    if(*(int*)dato % 2 == 0)
        *(int*)dato *= 2;
    else
        *(int*)dato /= 2;

    return 1;
}

void reducirVector(void* vec, size_t tamElem, size_t* cantElem, int comparar(const void*, const void*), int reduce(void*, const void*))
{
    char* pLec = (char*)vec;
    char* pEsc = (char*)vec;
    char* pFin = (char*)vec + ((*cantElem) * tamElem);

    while(pEsc < pFin)
    {
        pLec = pEsc + tamElem;

        while(pLec < pFin)
        {
            if(comparar(pEsc, pLec))
            {
                reduce(pEsc, pLec);
                eliminarElemento(vec, tamElem, cantElem, (int)(pLec - (char*)vec)/ tamElem);
                pFin = vec + ((*cantElem) * tamElem);
            }
            else
            {
                pLec += tamElem;
            }
        }

        pEsc += tamElem;
    }
}

int compararInt(const void* d1, const void* d2)
{
    return(*(int*)d1 - *(int*)d2);
}

int compararProducto(const void* d1, const void* d2)
{
    tProducto* p1 = (tProducto*)d1;
    tProducto* p2 = (tProducto*)d2;

    return(p1->id == p2->id);
}

int reduceAcumularInt(void* acum, const void* dato)
{
    *(int*)acum += *(int*)dato;
    return 1;
}

int reduceAcumularProducto(void* acum, const void* dato)
{
    tProducto* p1 = (tProducto*)acum;
    tProducto* p2 = (tProducto*)dato;

    p1->cantidad += p2->cantidad;

    return 1;
}
void eliminarElemento(void* vec, size_t tamElem, size_t* cantElem, int pos)
{
    char* destino = (char*)vec + ((size_t)pos * tamElem);
    char* origen = destino + tamElem;
    char* fin = (char*)vec + (*cantElem) * tamElem;

    while(origen < fin)
    {
        *destino = *origen;
        destino++;
        origen++;
    }

    (*cantElem)--;
}
