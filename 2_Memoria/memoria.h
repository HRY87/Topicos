#ifndef MEMORIA_H_INCLUDED
#define MEMORIA_H_INCLUDED

#include <stdbool.h>

typedef struct
{
    char apellido[31];
    char sexo;
    int edad;
    float promedio;
}tEstudiante;

/**Ejercicio 2.1 y 2.2**/
int IngresarEnteros();
void* reservarMemoria(size_t cantElem, size_t tamElem);
bool inicializarEnteros(int* vElem, size_t ce);
void mostrarEnteros(int* vElem, size_t ce);

/**Ejercicio 2.3**/
int IngresarEstudiante();
bool inicializarEstudiante(tEstudiante* vElem, size_t ce);
void mostrarEstudiante(tEstudiante* est, size_t ce);

/**Ejercicio 2.4**/
int IngresarCadena();
char* copiaCadena(const char* origen);

int ingresarCosa();
void* copiarCosas(void* elemento, unsigned tam);
void mostrarInt(const void* d);

/**Ejercicio 2.5**/
int probarMemmove();
void* mem_move(void* dest, const void* src, size_t n);
#endif // MEMORIA_H_INCLUDED
