#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "memoria.h"

#define TAM_INT     sizeof(int)
#define TAM_EST     sizeof(tEstudiante)

int IngresarEnteros()
{
    int ce;
    puts("Ingrese la cantidad de elementos:");
    scanf("%d", &ce);

    int* vElem = reservarMemoria(ce, TAM_INT);

    if(!vElem)
        return -1;

    inicializarEnteros(vElem, ce);
    mostrarEnteros(vElem, ce);

    free(vElem);

    return 0;
}

void* reservarMemoria(size_t cantElem, size_t tamElem)
{
    void* vElem = malloc(cantElem * tamElem);

    if(!vElem)
        return NULL;

    return vElem;
}

bool inicializarEnteros(int* vElem, size_t ce)
{

    if(!vElem)
        return false;


    for(int i = 0; i < ce; i++)
    {
        printf("Ingrese el elemento %d: ", i);
        scanf("%d", &vElem[i]);

    }

    return true;
}

void mostrarEnteros(int* vElem, size_t ce)
{
    for(int i = 0; i < ce; i++)
    {
        printf("[%d]: %d\n", i, vElem[i]);
    }
}

int IngresarEstudiante()
{
    int ce;
    puts("Ingrese la cantidad de elementos:");
    scanf("%d", &ce);

    tEstudiante* vElem = reservarMemoria(ce, TAM_EST);

    if(!vElem)
        return -1;

    inicializarEstudiante(vElem, ce);
    mostrarEstudiante(vElem, ce);

    free(vElem);

    return 0;
}

bool inicializarEstudiante(tEstudiante* vElem, size_t ce)
{
    if(!vElem)
        return false;

    for(int i = 0; i < ce; i++)
    {
        printf("Ingrese los valores del estudiante %d:\n", i);
        puts("Apellido:");
        scanf("%s", vElem[i].apellido);

        puts("Sexo (F/M):");
        scanf(" %c", &vElem[i].sexo);

        puts("Edad:");
        scanf("%d", &vElem[i].edad);

        puts("Ingrese el promedio:");
        scanf("%f", &vElem[i].promedio);
    }

    return true;
}

void mostrarEstudiante(tEstudiante* est, size_t ce)
{
    for(int i = 0; i < ce; i++)
    {
        printf("[%d]: %-30s|%c|%02d|%.2f\n", i, est[i].apellido, est[i].sexo, est[i].edad, est[i].promedio);
    }
}

/**Ejercicio 2.4: Crear copiaCadena y copiaCosas**/
int IngresarCadena()
{
    char buffer[101];

    puts("Ingrese una cadena:");
    fgets(buffer, sizeof(buffer), stdin);//gets obsoleto en 25.03

    buffer[strcspn(buffer, "\n")] = '\0'; //Reemplazar \n por el \0

    char* copia = copiaCadena(buffer);

    if(!copia)
        return -1;

    printf("Original: -%s-\n", buffer);
    printf("Copia: -%s-\n", copia);

    free(copia);

    return 0;
}

char* copiaCadena(const char* origen)
{
    if(!origen)
        return NULL;

    size_t tam = strlen(origen);

    char* copia = (char*)malloc(tam + 1);

    if(!copia)
        return NULL;

    strcpy(copia, origen);

    return copia;
}

int ingresarCosa()
{
    //char buffer[101];
    int dato;

    puts("Ingrese algo:");
    scanf("%d", &dato);

//    fgets(buffer, sizeof(buffer), stdin);//gets obsoleto en 25.03
//    buffer[strcspn(buffer, "\n")] = '\0'; //Reemplazar \n por el \0
//    size_t tam = strlen(buffer) + 1;

    void* copia = (int*)copiarCosas(&dato, sizeof(int));

    if(!copia)
        return -1;

//    printf("Original: -%s-\n", buffer);
//    printf("Copia: -%s-\n", (char*)copia);

    printf("-%d-\n", dato);

    mostrarInt(copia);

    free(copia);

    return 0;
}

void* copiarCosas(void* elemento, unsigned tam)
{
    if(!elemento || tam == 0)
        return NULL;

    void* copia = malloc(tam);

    if(!copia)
        return NULL;

    memcpy(copia, elemento, tam);

    return copia;
}

void mostrarInt(const void* d)
{
    int* p = (int*)d;

    printf("-%d-\n", *p);
}

/**Ejercicio 2.25; Hacer memmove
Logica:
Copia n bytes desde origen hacia destino

Condiciones:
Funciona aunque las zonas se superpongan
Si dest < src Copiamos normal (izq a der)
Si dest > src Copiamos invertido (der a izq) para no pisar datos
**/

void* mem_move(void* dest, const void* src, size_t n)
{
    if(!dest || !src)
        return NULL;

    //Copia byte a byte
    unsigned char* d = (unsigned char*)dest;
    const unsigned char* s = (const unsigned char*)src;

    if(d == s || n == 0)
        return dest;

    if(d < s)
    {
        //Copia hacia delante
        for(size_t i = 0; i < n; i++)
        {
            d[i] = s[i];
        }
    }else
    {
        //Copia hacia atras
        for(size_t i = n; i > 0; i--)
        {
            d[i - 1] = s[i - 1];
        }
    }

    return dest;
}

int probarMemmove()
{
    char buffer[] = "abcdef";

    if(mem_move(buffer + 2, buffer, 4) == NULL)
        return -1;


    printf("%s\n", buffer); //resultado esperado: ababcd

    return 0;
}
