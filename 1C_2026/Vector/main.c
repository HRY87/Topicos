#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define TAM_VEC     10

int main()
{
    int vec[] = {3, 12, 454, 12, 234, 12};
    //int vec[] = {1234, 432, 2, 4, 564, 7, -20};

    int ce = sizeof(vec)/sizeof(int);

    //ordenarVectorBurbujeo(vec, ce, compararInt, intercambiarInt);

//    /**Prueba Ejercicio 1.1**/
//    insertarVectorEnPosicionEntero(vec, ce, 100, 0);

//    /**Prueba Ejercicio 1.2**/
//    insertarVectorOrdenadoAsc(vec, ce, 100, compararInt, intercambiarInt);

//    /**Prueba Ejercicio 1.3**/
//    eliminarVectorEnPosicionEntero(vec, &ce, 1);

//    /**Prueba Ejercicio 1.4**/
//    eliminarVectorPrimeraAparicion(vec, &ce, 12);

    /**Prueba Ejercicio 1.5**/
    eliminarVectorTodasApariciones(vec, &ce, 12);


    mostrarVector(vec, ce, mostrarInt);

    return 0;
}
