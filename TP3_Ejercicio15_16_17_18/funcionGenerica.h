#ifndef FUNCIONGENERICA_H_INCLUDED
#define FUNCIONGENERICA_H_INCLUDED

typedef void(*Intercambio)(const void*, const void*);

void intercambiar(void* d1, void* d2, Intercambio tipoIntercambio);

void tipoIntercambio_int(const void* d1, const void* d2);
#endif // FUNCIONGENERICA_H_INCLUDED
