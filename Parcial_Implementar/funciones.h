#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define TODO_OK     0
#define SIN_MEM     1
#define ERROR       2

typedef int (*Comparar)(const void *, const void *);

/**Ejercicio 1: Hacer la version propia  de strcat**/
char* mstcat(char* s1, const char* s2);
size_t str_cspn(const char* s1, const char* s2);
int prueba_mstcat();

/**Ejercicio 2: Sumar los elementos del triangulo debajo de las diagonales**/
int inicializarMatriz(int** m, size_t fil, size_t col, int limInf, int limSup);
int prueba_SumaTriangInfEntreDiag(size_t fil, size_t col, size_t limInf, size_t limSup);
int** crearMatriz(size_t fil, size_t col);
void destruirMatriz(int** m, size_t fil);
int sumaTrianInfEntreDiag(int** m, size_t fil, size_t col);
void matrizMostrar(int** m, int fil, int col);

/**Ejercicio 3: Hacer version propia de bsearch, buscar generico**/
void *mbsearch(const void *clave, const void *base, size_t ce, size_t tamElem, Comparar cmp);
int prueba_mbsearch(int v[], int ce, int clave);
int cmpEnteros(const void *a, const void *b);
#endif // FUNCIONES_H_INCLUDED
