#ifndef VECTORDEFLOAT_H_INCLUDED
#define VECTORDEFLOAT_H_INCLUDED

#include <stddef.h>

int crearMatrizFloat(float* vf, size_t cantElemMax);
void mostrarMatrizFloat(float* vf, size_t cantElem);

float* buscarMinimo(float* vf, size_t cantElem);
float calcularPromedioPosPares(float* vf, size_t cantElem);
void mostrarOrdenInverso(float* vf, size_t cantElem);
#endif // VECTORDEFLOAT_H_INCLUDED
