#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void intercambiarByteAByte(void* a, void* b, size_t tam);

int intercambiarMemoriaDinamica(void* a, void* b, size_t tam);

int main()
{
    int a = 20,
        b = 25;

    printf("Antes: a= %d | b= %d\n", a, b);

    intercambiarByteAByte(&a, &b, sizeof(int));
    //intercambiarMemoriaDinamica(&a, &b, sizeof(int));

    printf("Despues: a= %d | b= %d\n", a, b);

    return 0;
}

/**
Ventajas
-No tengo que preocuparme por reservar memoria
-Copia byte a byte
-No dependo de funciones de bibliotecas
**/

void intercambiarByteAByte(void* a, void* b, size_t tam)
{
    char temp;

    while(tam--)
    {
        temp = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = temp;
        a++;
        b++;
    }
}

/**Aunque esta simplificado, al utilizar funciones mem no se sabe cuanto puede tardar**/
int intercambiarMemoriaDinamica(void* a, void* b, size_t tam)
{
    void* temp = malloc(tam);

    if(!temp)
        return 0;

    memcpy(temp, a, tam);
    memcpy(a, b, tam);
    memcpy(b, temp, tam);

    free(temp);

    return 1;
}
