#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include "utilidades.h"

typedef struct
{
    void* vec;
    size_t tamElem;
    size_t cantElem;
    size_t tope;
}tVector;

int crearVector(tVector* v, size_t tamElem, size_t cantElem);
int insertarVectorOrd(tVector* v, void* dato, size_t tamElem, Comparar compararLegajo);
void vaciarVector(tVector* v);
void mostrarVector(tVector* v, Mostrar mostrarCargo);

#endif // VECTOR_H_INCLUDED
