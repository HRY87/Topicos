#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include "utilidades.h"

#define TODO_OK     0
#define SIN_MEM     1
#define DUPLICADO   2
#define VEC_LLENO   3
#define VEC_VACIO   4
#define NO_EXISTE   5

typedef struct
{
    void* vec; //Memoria donde estan los elementos
    size_t ce; //Cantidad de elementos
    size_t tamElem; //Tamanio de cada elemento
    size_t tope; //Capacidad maxima
}tVector;

/**Dinamico**/
int crearVectorDinamico(tVector* v, size_t tamElem, size_t capacidad);
void destruirVectorDinamico(tVector* v);

/**Estatico**/
int crearVectorEstatico(tVector* v, void* memoria, size_t tamElem, size_t capacidad);
void destruirVectorEstatico(tVector* v);


int vectorLleno(const tVector* v);
int vectorVacio(const tVector* v);
int insertarVectorOrd(tVector* v, void* dato, Comparar cmp);
int eliminarElementoVector(tVector* v, void* dato, Comparar cmp);

/**Auxiliares**/
void mostrarVector(tVector* v, Mostrar mostrar);

/**Ejercicio 1.21**/
int insertarVectorEnPosicion(tVector* v, void* dato, size_t pos);
int eliminarVectorEnPosicion(tVector* v, size_t pos);
int eliminarPrimeraAparicion(tVector* v, void* dato, Comparar cmp);
int eliminarTodasApariciones(tVector* v, void* dato, Comparar cmp);
#endif // VECTOR_H_INCLUDED
