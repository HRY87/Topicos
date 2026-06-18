#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

typedef int(*Comparar)(const void* d1, const void* d2);
typedef void(*Mostrar)(const void* d);

typedef struct
{
    int legajo;
    char ayn[81];
    float sueldo;
}tEmpleado;

void mostrarEmpleado(const void* d);
int comparar_legajo(const void* d1, const void* d2);
int comparar_sueldo(const void* d1, const void* d2);


void mostrarInt(const void* d);
int compararInt(const void* d1, const void* d2);

#endif // UTILIDADES_H_INCLUDED
