#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

#define SEP_TXT '|'   /* separador de columnas en el archivo */

#define RUTA_MATRIZ     "matriz.txt"

void** crearMatriz(size_t fil, size_t col, size_t tam);
void eliminarMatriz(void** m, size_t fil);
void inicializarMatriz(int**m, size_t fil, size_t col);
void mostrarMatriz(int** m, size_t fil, size_t col);
void rotarMatriz(int** m, size_t fil, size_t col);
static char* miStrchr(const char* s, char c);
static void miStrncpy(char* dest, const char* src, size_t n);
static size_t contarColumnas(const char* linea);
static size_t contarFilas(FILE* txt);
int obtenerDimensionesMatriz(FILE* txt, const char* primeraLinea, size_t* fil, size_t* col);
void** crearMatrizArchivo(const char* rutaTxt, size_t tam, size_t *fil, size_t* col);
void trozarLineaMatrizFloat(const char* linea, float* fila, size_t col);
void mostrarMatrizFloat(float** m, size_t fil, size_t col);
void rotarEstrella(float** m, size_t fil, size_t col);
int main()
{
    size_t fil = 0;
    size_t col = 0;

    float** matriz = (float**)crearMatrizArchivo(RUTA_MATRIZ, sizeof(float), &fil, &col);

    puts("---Matriz original---");
    mostrarMatrizFloat(matriz, fil, col);

    puts("---Matriz rotada---");
    rotarEstrella(matriz, fil, col);
    mostrarMatrizFloat(matriz, fil, col);

    eliminarMatriz((void**)matriz, fil);

    return 0;
}


void** crearMatriz(size_t fil, size_t col, size_t tam)
{
    void** m = malloc(fil * sizeof(void*));

    if(!m)
        return NULL;

    void** ult = m + fil;

    for(void**i = m; i < ult; i++)
    {
        *i = malloc(col * tam);

        if(!*i)
        {
            eliminarMatriz(m, i - m);
            return NULL;
        }
    }

    return m;
}


void eliminarMatriz(void** m, size_t fil)
{
    void** ult = m + fil;

    for(void** i = m; i < ult; i++)
    {
        free(*i);
    }

    free(m);
}

void inicializarMatriz(int**m, size_t fil, size_t col)
{

    int num = 1;

    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            m[i][j] = num;
            num++;
        }
    }
}


void mostrarMatriz(int** m, size_t fil, size_t col)
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

void mostrarMatrizFloat(float** m, size_t fil, size_t col)
{
    for(int i = 0; i < fil; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%.2f\t", m[i][j]);
        }

        puts("");
    }
}
void rotarMatriz(int** m, size_t fil, size_t col)
{
    int i1, i2, j1, j2, aux;

    for(int i = 0; i < (fil * col)/ 2; i++)
    {
        i1 = i/col;
        j1= i % col;

        i2 = fil -1 - i1;
        j2 = col -1 - j1;

         aux = m[i1][j1];
         m[i1][j1] = m[i2][j2];
         m[i2][j2] = aux;
    }
}



/* --- Reemplazo de strchr --- */
static char* miStrchr(const char* s, char c)
{
    while(*s)
    {
        if(*s == c)
            return (char*)s;
        s++;
    }
    return (c == '\0') ? (char*)s : NULL;
}

/* --- Reemplazo de strncpy --- */
static void miStrncpy(char* dest, const char* src, size_t n)
{
    size_t i = 0;
    while(i < n - 1 && src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

/* --- Cuenta columnas de la primera línea --- */
static size_t contarColumnas(const char* linea)
{
    size_t cols = 0;
    int enCampo = 0;
    const char* p = linea;

    while(*p && *p != '\r' && *p != '\n')
    {
        if(*p == SEP_TXT)
        {
            enCampo = 0;
        }
        else if(!enCampo)
        {
            cols++;
            enCampo = 1;
        }
        p++;
    }
    return cols;
}

/* --- Cuenta filas con contenido real --- */
static size_t contarFilas(FILE* txt)
{
    char linea[201];
    size_t filas = 0;

    while(fgets(linea, sizeof(linea), txt))
    {
        const char* p = linea;
        while(*p == ' ' || *p == '\t')
            p++;
        if(*p != '\n' && *p != '\r' && *p != '\0')
            filas++;
    }
    return filas;
}

int obtenerDimensionesMatriz(FILE* txt, const char* primeraLinea, size_t* fil, size_t* col)
{
    if(!*primeraLinea)
        return 0;

    *col = contarColumnas(primeraLinea);
    if(*col == 0)
        return 0;

    rewind(txt);
    *fil = contarFilas(txt);
    if(*fil == 0)
        return 0;

    rewind(txt);
    return 1;
}

/* --- Trozar línea usando miStrchr en vez de strchr --- */
void trozarLineaMatrizFloat(const char* linea, float* fila, size_t col)
{
    size_t c = 0;
    char buffer[201];
    miStrncpy(buffer, linea, sizeof(buffer));   /* copia local para poder cortar con '\0' */

    char* fin = miStrchr(buffer, '\n');
    if(fin) *fin = '\0';
    fin = miStrchr(buffer, '\r');
    if(fin) *fin = '\0';

    char* ini = buffer;
    int hayMasColumnas = 1;

    while(c < col && hayMasColumnas)
    {
        char* sep = miStrchr(ini, SEP_TXT);
        if(sep)
            *sep = '\0';

        sscanf(ini, "%f", &fila[c]);
        c++;

        if(sep)
            ini = sep + 1;
        else
            hayMasColumnas = 0;
    }
}

void** crearMatrizArchivo(const char* rutaTxt, size_t tam, size_t *fil, size_t* col)
{
    char linea[201];
    FILE* txt = fopen(rutaTxt, "rt");
    if(!txt)
        return NULL;

    if(!fgets(linea, sizeof(linea), txt))
    {
        fclose(txt);
        return NULL;
    }

    if(!obtenerDimensionesMatriz(txt, linea, fil, col))
    {
        fclose(txt);
        return NULL;
    }

    void** matriz = crearMatriz(*fil, *col, tam);
    if(!matriz)
    {
        fclose(txt);
        return NULL;
    }

    size_t f = 0;
    while(f < *fil && fgets(linea, sizeof(linea), txt))
    {
        const char* p = linea;
        while(*p == ' ' || *p == '\t')
            p++;
        if(*p == '\n' || *p == '\r' || *p == '\0')
            continue;   /* salteamos líneas vacías */

        trozarLineaMatrizFloat(linea, (float*)matriz[f], *col);
        f++;
    }

    fclose(txt);
    return matriz;
}

void rotarEstrella(float** m, size_t fil, size_t col)
{
    int i1,i2,j1,j2;
    float aux;

    for(int i = 0; i < (fil * col)/2; i++)
    {
        i1 = i/col;
        j1 = i%col;

        i2 = fil - 1 - i1;
        j2 = col - 1 - j1;

        aux = m[i1][j1];
        m[i1][j1] = m[i2][j2];
        m[i2][j2] = aux;
    }
}
