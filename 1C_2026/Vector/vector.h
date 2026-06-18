#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include "utilidades.h"

#define TODO_OK         0
#define ERR_VECTOR      -1

/**Ejercicio 1.1: Insertar elemento dada una posicion**/
int insertarVectorEnPosicionEntero(int* v, int ce, int elem, int pos);

/**Ejercicio 1.2: Insertar elemento en vector ordenado de forma ascendente**/
int insertarVectorOrdenadoAsc(int* v, int ce, int elem, Comparar cmp, Intercambiar intercambio);

/**Ejercicio 1.3: Eliminar elemento dada una posicion**/
int eliminarVectorEnPosicionEntero(int* v, int* ce, int pos);

/**Ejercicio: 1.4: Eliminar primera aparacion**/
int eliminarVectorPrimeraAparicion(int* v, int* ce, int elem);

/**Ejercicio 1.5: Eliminar todas las apariciones**/
int eliminarVectorTodasApariciones(int* v, int* ce, int elem);

/**Funciones auxiliares**/
void mostrarVector(int* v, int ce, Mostrar mostrar);
void ordenarVectorBurbujeo(int* v, int ce, Comparar cmp, Intercambiar intercambio);
#endif // VECTOR_H_INCLUDED
