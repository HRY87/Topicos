#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

typedef int(*Comparar)(const void* d1, const void* d2);
typedef void(*Intercambiar)(void* d1, void* d2);
typedef void(*Mostrar)(const void* d);

int compararInt(const void* d1, const void* d2);
void intercambiarInt(void* d1, void* d2);
void mostrarInt(const void* d);

#endif // UTILIDADES_H_INCLUDED
