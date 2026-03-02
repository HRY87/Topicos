#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matriz.h"

void** crearMatriz(size_t filas, size_t columnas, size_t tamElem)
{
    void** matriz = malloc(filas * sizeof(void*));

    if(!matriz)
    {
        return NULL;
    }

    void** ult = matriz + filas - 1;

    for(void** i = matriz; i <= ult; i++)
    {
        *i = malloc(columnas * tamElem);

        if(!*i)
        {
            eliminarMatriz(matriz, i - matriz);
            return NULL;
        }

    }
    return matriz;
}

void eliminarMatriz(void** matriz, size_t filas)
{
    void** ult = matriz + filas - 1;

    for(void** i = matriz; i <= ult; i++)
    {
        free(*i);
    }

    free(matriz);
}

void cargarMatriz(int** matriz, size_t filas, size_t columnas)
{
    int elem = 1;

    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            matriz[i][j] = elem++;
        }
    }
}

void mostrarMatriz(int** matriz, size_t filas, size_t columnas)
{
    for(int i = 0; i < filas; i++)
    {
        for(int j = 0; j < columnas; j++)
        {
            printf("%d\t", matriz[i][j]);
        }

        putchar('\n');
    }
}

int sumaDiagonalPrincipal(int** matriz, int orden)
{
    int acum = 0;

    for(int i = 0; i < orden; i++)
    {
        acum += matriz[i][i];
    }

    return acum;
}

int sumaDiagonalSecundaria(int** matriz, int orden)
{
    int acum = 0;

    for(int i = 0, j = orden - 1; i < orden; i++, j--)
    {
        acum += matriz[i][j];
    }

    return acum;
}

int sumaTriangularInferiorDP(int** matriz, int orden)
{
    int acum = 0;

    for(int i = 0; i < orden; i++)
    {
        for(int j = 0; j < i; j++)
        {
            acum += matriz[i][j];
        }
    }

    return acum;
}

int sumaTriangularSuperiorDP(int** matriz, int orden)
{
    int acum = 0;

    for(int i = 0, limj = orden - 2; i <= orden - 2; i++, limj--)
    {
        for(int j = 0; j <= limj; j++)
        {
            acum += matriz[i][j];
        }
    }

    return acum;
}

int** productoMatrices(int** mat1, int** mat2, size_t filM1, size_t colM1filM2, size_t colM2)
{
    int** mp = (int**)crearMatriz(filM1, colM2, sizeof(int));

    if(!mp)
    {
        return NULL;
    }

    for(int i = 0; i < filM1; i++)
    {
        for(int j = 0; j < colM2; j++)
        {
            mp[i][j] = 0;

            for(int k = 0; k < colM1filM2; k++)
            {
                mp[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return mp;
}
