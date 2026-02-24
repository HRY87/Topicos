#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include "utilidades.h"

#define TODO_OK         0
#define ERR_VECTOR      -1

int insertarVectorEnPosicionEntero(int* v, int ce, int elem, int pos);
int insertarVectorOrdenadoAsc(int* v, int ce, int elem, Comparar cmp, Intercambiar intercambio);
int eliminarVectorEnPosicionEntero(int* v, int* ce, int pos);
int eliminarVectorPrimeraAparicion(int* v, int* ce, int elem);
int eliminarVectorTodasApariciones(int* v, int* ce, int elem);

int crearVectorEntero(int* v, int ce, int tamMax, int limiteInferior, int limiteSuperior);
void mostrarVector(int* v, int ce, Mostrar mostrar);
void ordenarVectorBurbujeo(int* v, int ce, Comparar cmp, Intercambiar intercambio);
#endif // VECTOR_H_INCLUDED
