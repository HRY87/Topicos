#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int** matrizCrear(size_t fil, size_t col)
{
    int** matriz = malloc(fil * sizeof(int*));

    if(!matriz)
    {
        return NULL;
    }

    int** ult = matriz + fil - 1;

    for(int** i = matriz; i <= ult; i++)
    {
        *i = malloc(col * sizeof(int));

        if(!*i)
        {
            matrizDestruir(matriz, i - matriz);
            return NULL;
        }

    }
    return matriz;
}

void matrizDestruir(int** m, int fil)
{
    for(int i = 0; i < fil; i++)
    {
        free(m[i]);
    }

    free(m);
}

/**Recordar que: m[i][j] = *(*(m + i) + j) = *(*(matriz + nFila) + nColumna)**/

void matrizMostrar(int** m, int fil, int col)
{
    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d\t", *(*(m + i) + j));

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
            *(*(m + i) + j) = rand() % (limSup - limInf + 1) + limInf;
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
            suma += *(*(m + i) + j);
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
            suma += *(*(m + i) + j);
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
            suma += *(*(m + i) + j);
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
            suma += *(*(m + i) + j);
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
            suma += *(*(m + i) + j);
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
            suma += *(*(m + i) + j);
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
            suma += *(*(m + i) + j);
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
            suma += *(*(m + i) + j);
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
        suma += *(*(m + i) + i);
    }

    return suma;
}

int matrizSumaDS(int** m, int fil, int col)
{
    int suma = 0;

    for(int i = 0; i < fil; i++)
    {
        suma += *(*(m + i) + (col - i - 1));
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
            if((i == j && (*(*(m + i) + j) != 1)) || (i != j && (*(*(m + i) + j) != 0)))
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
            *(*(m + i) + j) = (esIdentidad ? (i == j ? 1 : 0) : rand() % 2);
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
            //m[i][j] != m[j][i]
            if(*(*(m + i) + j)!= *(*(m + j) + i))
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
            *(*(m + i) + j) = rand() % (limSup - limInf + 1) + limInf;

            *(*(m + j) + i) = (esSimetrica ? *(*(m + i) + j) : rand() % (limSup - limInf + 1) + limInf);
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
            aux = *(*(m + i) + j);
            *(*(m + i) + j) = *(*(m + j) + i);
            *(*(m + j) + i) = aux;
        }
    }
}

/**Ejercicio 1.18: Generar matriz transpuesta**/
int** matrizTransponer(int** m,int fil, int col)
{
    int** mt = (int**)matrizCrear(col, fil);

    if(!mt)
        return NULL;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            //mt[i][j] = m[j][i]
            *(*(mt + j) + i) = *(*(m + i) + j);
        }
    }

    return mt;
}

/**Ejercicio 1.19: Producto de matriz**/
int** matrizProducto(int** m1, int** m2, int fil1, int col2, int col1Fil2)
{
    int** mp = matrizCrear(fil1, col2);

    if(!mp)
    {
        return NULL;
    }

    for(int i = 0; i < fil1; i++)
    {
        for(int j = 0; j < col2; j++)
        {
            *(*(mp + i) + j) = 0;

            for(int k = 0; k < col1Fil2; k++)
            {
                //mp[i][j] += m1[i][k] * m2[k][j];
                *(*(mp + i) + j) += (*(*(m1 + i) + k)) * (*(*(m2 + k) + j));
            }
        }
    }

    return mp;
}

/**Ejercicio 1.20**/
/**Inicializar matriz dinamica**/
void matrizInicializarTorneo(int** m, size_t orden)
{
    int aux[ORDEN][ORDEN] = {
        {0, 4, 1, 2, 4},
        {1, 0, 3, 3, 0},
        {4, 3, 0, 0, 4},
        {2, 3, 6, 0, 6},
        {1, 6, 1, 0, 0},
    };

    for(int i = 0; i < ORDEN ; i++)
    {
        for(int j = 0; j < ORDEN; j++)
        {
            m[i][j] = aux[i][j];
        }
    }

}
/**Validar si es matriz torneo**/
int validarMatrizTorneo(int** m, size_t orden, int puntos[][TAM_RESULTADOS])
{
    int pos;
    if(validarDiagonal(m, orden) != 0)
        return 1;

    for(int i = 0; i < orden; i++)
    {
        for(int j = i + 1; j < orden; j++)
        {
            pos = buscarPos(puntos[0], m[i][j], TAM_RESULTADOS);

            if(pos == -1)
                return 2;

            if(m[j][i] != puntos[1][pos])
                return 2;
        }
    }

    return 0;
}

int buscarPos(int* v, int elem, size_t ce)
{
    for(int i = 0; i < ce; i++)
    {
        if(*(v + i) == elem)
            return i;
    }

    return -1;
}

int validarDiagonal(int** m , size_t orden)
{
    for(int i = 0; i < orden; i++)
    {
        if(m[i][i] != 0)
            return 1;
    }

    return 0;
}
/**Sumar puntos de la temporada por equipo**/
void totalizarPuntosPorEquipos(int** m, size_t orden, int* vPuntos)
{
    int puntos = 0;

    if(!m)
        return;

    for(int i = 0; i < orden; i++)
    {
        puntos = sumarPuntos(m[i], orden);
        *vPuntos = puntos;
        vPuntos++;
    }
}
int sumarPuntos(int* v, size_t orden)
{
    int acum = 0;

    for(int i = 0; i < orden; i++)
    {
        acum += *v;
        v++;
    }

    return acum;
}

/**Rotacion de elementos**/
/**Formula aplicada: [i][j] -> [fil - 1 - i][col - 1 -j]**/

/**
Ejemplo:
    Fila 0 -> 1 2 3
    Fila 1 -> 4 5 6
    Fila 2 -> 7 8 9

    Quiero saber las coordenadas del 6, si lo vemos como un vector:

    1 2 3 4 5 6  -> esta en la posicion 5 (no olvidar que empieza de 0)

    Entonces para obtener las coordenas en la matriz lo puedo calcular asi:

    pos / nColumnas = 5 / 3 = 1 -> Esta en la fila 1
    pos % nColumanas = 5 % 3 = 2 -> Esta en la columna 2

    m[1][2] = 5
**/

void matrizRotar180(int** m, size_t fil, size_t col)
{
    int aux;
    int i1, j1; //Coordenas
    int i2, j2; //Opuestos

    //Recorro la matriz como si fuera un vector, pero solo hasta la mitad del total de sus elementos
    for(int i = 0; i < (fil * col)/2; i++)
    {
        //Obtengo las coordenadas
        i1 = i / col;//Fila
        j1 = i % col;//Columna

        //Roto 180
        i2 = fil - 1 - i1;
        j2 = col - 1 - j1;

//        aux = m[i1][j1];
//        m[i1][j1] = m[i2][j2];
//        m[i2][j2] = aux;

        //intercambio
        aux = *(*(m + i1) + j1);
        *(*(m + i1) + j1) =  *(*(m + i2) + j2);
        *(*(m + i2) + j2) = aux;
    }
}
