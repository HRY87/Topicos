#ifndef VECTORINT_H_INCLUDED
#define VECTORINT_H_INCLUDED

#define CANT_ELEM_MAX   30
#define VALOR_ELEM_MAX  30

typedef struct
{
    float prom;
    long total;
}tRegistro;

int crearVectorInt(int* vi, size_t cantElemMax);
void mostrarVectorInt(int* vi, size_t ce);
float calcularTotalYPromedioDelVectorInt(int* vi, size_t ce, long* total);
void calcularTotalYPromedioDelVectorInt_2(int* vi, size_t ce, tRegistro* r);
#endif // VECTORINT_H_INCLUDED
