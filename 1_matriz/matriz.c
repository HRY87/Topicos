#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"matriz.h"

void** matrizCrear(int fil, int col, size_t tamElem)
{
    void** m = malloc(fil* sizeof(void*));

    if(!m)
        return NULL;

    for(int i = 0; i < fil; i++)
    {
        m[i] = malloc(col * tamElem);

        if(m[i] == NULL)
        {
            matrizDestruir(m, i);
            return NULL;
        }
    }

    return m;
}

void matrizDestruir(void** m, int fil)
{
    for(int i = 0; i < fil; i++)
    {
        free(m[i]);
    }

    free(m);
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

void matrizInicializar(int** m, int fil, int col, int limInf, int limSup)
{
    srand(time(NULL));

    if(!m)
        return;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            m[i][j] = rand() % (limSup - limInf + 1) + limInf;
        }
    }
}
/**Ejercicio 1.12: Sumatoria encima y debajo de las diagonales**/
int matrizSumaEncimaDP(int** m, int fil, int col)
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = i + 1; j < col; j++)
        {
            suma += m[i][j];
        }
    }

    return suma;
}

int matrizSumaDebajoDP(int** m, int fil, int col)
{
    int suma = 0;

    for(int i = 1; i < fil; i++)
    {
        for(int j = 0; j < i; j++)
        {
            suma += m[i][j];
        }
    }

    return suma;
}
int matrizSumaEncimaDPIncluido(int** m, int fil, int col)
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = i; j < col; j++)
        {
            suma += m[i][j];
        }
    }

    return suma;
}

int matrizSumaDebajoDPIncuido(int** m, int fil, int col)
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            suma += m[i][j];
        }
    }

    return suma;
}
int matrizSumaEncimaDS(int** m, int fil, int col)
{
    int suma = 0;

    for(int i = 0; i < fil - 1; i++)
    {
        for(int j = 0; j < col - i - 1; j++)
        {
            suma += m[i][j];
        }
    }

    return suma;
}

int matrizSumaDebajoDS(int** m, int fil, int col)
{
    int suma = 0;

    for(int i = 1; i < fil; i++)
    {
        for(int j = col - i; j < col; j++)
        {
            suma += m[i][j];
        }
    }

    return suma;
}

int matrizSumaEncimaDSIncluido(int** m, int fil, int col)
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col - i; j++)
        {
            suma += m[i][j];
        }
    }

    return suma;
}

int matrizSumaDebajoDSIncluido(int** m, int fil, int col)
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        for(int j = col - i - 1; j < col; j++)
        {
            suma += m[i][j];
        }
    }

    return suma;
}

/**Ejercicio 1.13: Sumatoria en diagonal**/
int matrizSumaDP(int** m, int fil, int col)
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        suma += m[i][i];
    }

    return suma;
}

int matrizSumaDS(int** m, int fil, int col)
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        suma += m[i][col - i- 1];
    }

    return suma;
}

/**Ejercicio 1.15: Validar matriz identididad**/
bool esMatrizIdentidad(int** m, int fil, int col)
{

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(m[i][i] == 0 || (i != j && m[i][j] != 0))
            {
                return false;
            }

        }
    }

    return true;
}

void matrizInicializarIdentidad(int** m, int fil, int col, bool esIdentidad)
{
    if(!m)
        return;

    srand(time(NULL));

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            m[i][j] = (esIdentidad ? (i == j ? 1 : 0) : rand() % 2);
        }
    }
}
/**Ejercicio 1.16: Validar matriz simetrica**/
bool esMatrizSimetrica(int** m, int fil, int col)
{
    for(int i = 1; i < fil; i++)
    {
        for(int j = i + 1; j < col; j++)
        {
            if(m[i][j] != m[j][i])
            {
                return false;
            }
        }
    }

    return true;
}

void matrizInicializarSimetrica(int** m, int fil, int col, int limInf, int limSup, bool esSimetrica)
{
    if(!m)
        return;

    srand(time(NULL));

    for(int i = 0; i < fil; i++)
    {
        for(int j = i; j < col; j++)
        {
            m[i][j] = rand() % (limSup - limInf + 1) + limInf;

            m[j][i] = (esSimetrica ? m[i][j] : rand() % (limSup - limInf + 1) + limInf);
        }
    }
}

/**Ejercicio 1.17: Transponer in situ**/
void matrizTransponerInSitu(int** m, int fil, int col)
{
    int aux;

    for(int i = 0; i < fil; i++)
    {
        for(int j = i + 1; j < col; j++)
        {
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
}

/**Ejercicio 1.18: Generar matriz transpuesta**/
int** matrizTransponer(int** m ,int fil, int col)
{
    int** mt = (int**)matrizCrear(col, fil, sizeof(int));

    if(!mt)
        return NULL;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            mt[j][i] = m[i][j];
        }
    }

    return mt;
}

/**Ejercicio 1.19: Generar matriz producto**/
int** matrizProducto(int** m1, int** m2, int fil1, int col2, int filcol12)
{
    int** mp = (int**)matrizCrear(fil1, col2, sizeof(int));
    int suma = 0;

    if(!mp)
        return NULL;

    matrizInicializar(mp, fil1, col2, 0, 0);

    for(int i = 0; i < fil1; i++)
    {
        for(int j = 0; j < col2; j++)
        {
            suma = 0;

            for(int k = 0; k < filcol12; k++)
            {
                suma += m1[i][k] * m2[k][j];
            }

            mp[i][j] = suma;
        }
    }

    return mp;
}
