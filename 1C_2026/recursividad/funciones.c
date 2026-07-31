#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

long long factorialRecursivo(unsigned num)
{
    if(num == 0)
        return 1;

    return(num * factorialRecursivo(num - 1));
}

size_t strlenRecursivo(const char* str)
{
    if(!*str)
        return 0;

    return(1 + strlenRecursivo(str + 1));
}

char* strchrRecursivo(const char* str, int c)
{
    if(*str == c)
        return (char*)str;

    if(!*str)
        return NULL;

    return(strchrRecursivo(str + 1, c));

}

char* strrchrRecursivo(const char* str, int c)
{
    if(!*str)
        return(c == '\0') ? (char*)str : NULL;

    char* resto = (strrchrRecursivo(str + 1, c));

    return(resto ? resto : (*str == c ? (char*)str : NULL));
}

void* mapRecursivo(void* vec, size_t tamElem, size_t ce, int action(void*))
{
    if (ce == 0)
        return NULL;  // caso base: recorrí todo sin fallas

    if (!action(vec))
        return vec;// la acción falló acá, corto y devuelvo el elemento

    return mapRecursivo((char*)vec + tamElem, tamElem, ce - 1, action);
}

int esPalindromoRecursivo(const char* str)
{
    size_t len = strlenRecursivo(str);

    if (len == 0)
        return 1;                // string vacío se considera palíndromo

    return esPalindromoValidar(str, str + len - 1);
}

int esPalindromoValidar(const char* inicio, const char* fin)
{
    if (inicio >= fin)
        return 1;                          // caso base: se cruzaron o coinciden

    if (*inicio != *fin)
        return 0;                          // encontré una diferencia, no es palíndromo

    return esPalindromoValidar(inicio + 1, fin - 1);
}


void* mbsearchRecursivo(const void* clave, const void* vec, size_t ce, size_t tam, int comparar(const void*, const void*))
{
    if (ce == 0)
        return NULL;// caso base: no encontrado

    size_t medio = ce / 2;
    const char* elemMedio = (const char*)vec + medio * tam;
    int cmp = comparar(clave, elemMedio);

    if (cmp == 0)
        return (void*)elemMedio;// encontrado justo en el medio

    if (cmp < 0)
        return mbsearchRecursivo(clave, vec, medio, tam, comparar); // buscar en la mitad izquierda (sin incluir el medio)

    return mbsearchRecursivo(clave, elemMedio + tam, ce - medio - 1, tam, comparar); // buscar en la mitad derecha (sin incluir el medio)
}

void ordenarVectorSeleccionRecursivo(void* vec, size_t tamElem, size_t ce, int comparar(const void*, const void*), void intercambiar(void*, void*))
{
    if(ce <= 1)
        return;//Si queda 0 o 1 elemento, ya debe estar ordenado

    void* ult = vec + (ce - 1) * tamElem;
    void* m = buscarMenorRecursivo(vec, ult, tamElem, comparar);

    intercambiar(m, vec);//m se intercambia con la posicion actual (vec)

    //Paso al siguiente: vec + tamElem ; Bajo la cantidad de elementos a comparar: ce -1
    ordenarVectorSeleccionRecursivo(vec + tamElem, tamElem, ce - 1, comparar, intercambiar);
}

void* buscarMenorRecursivo(void* ini, void* fin, size_t tamElem, int comparar(const void*, const void*))
{
    if(ini == fin)
        return ini; //Queda un solo elemento (ini)

    //Paso al siguiente: vec + tamElem, esto sigue hasta fin
    void* m = buscarMenorRecursivo(ini + tamElem, fin, tamElem, comparar);

    if(comparar(ini, m) < 0)//Si ini sigue siendo el menor que el resto, devuelvo ini
        return ini;

    return m;//Si m es menor que ini, devuelvo m
}
