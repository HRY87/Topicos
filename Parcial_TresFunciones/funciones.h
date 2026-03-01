#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define ES_LETRA(x) (((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z'))
#define TAM_PAL     51

typedef int(*Comparar)(const void* a, const void* b);

/**Ejercicio 1: Ordenar seleccion generico**/
void _ordenarSeleccion(void* base, size_t nmemb, size_t tamanyo, Comparar comparar);
void* buscarMenor(void* base, size_t nmemb, size_t tamanyo, Comparar comparar);
void intercambiarElemento(const void* a, const void* b, size_t bytes);
int compararInt(const void* a, const void* b);
int prueba_ordenarSeleccionGenerico();

/**Ejercicio 2: Contar celulas vivas dado una posicion fila/columna**/
size_t _contarCelulasVivasEnVecindario(int** m, int fil, int col, int posF, int posC);
void** crearMatriz(size_t fil, size_t col, size_t tamElem);
void destruirMatriz(void** m, size_t fil);
void mostrarMatriz(int** m, size_t fil, size_t col);
int inicializarMatriz(int** m, size_t fil, size_t col);
int prueba_juegoDeLaVida(int fil, int col);

/**Ejercicio 3: Hacer a una version de strstr**/
char* msstr(const char* s1, const char* s2);
size_t str_len(const char* s);
int prueba_msstr();
#endif // FUNCIONES_H_INCLUDED
