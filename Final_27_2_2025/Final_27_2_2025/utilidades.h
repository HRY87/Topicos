#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#define TODO_OK     0
#define ERR_ARCH    1
#define SIN_MEM     2

#define TAM_COD     4

typedef int(*Comparar)(const void* d1, const void* d2);
typedef void(*Mostrar)(const void* d);
typedef void(*Actualizar)(void* actualizado, const void* actualizador);
typedef void(*Accion)(void* d, const void* accion);

typedef struct
{
    int legajo;
    char suc[TAM_COD];
    char codCargo[TAM_COD];
}tCargo;

typedef struct
{
    FILE* pf;
    size_t cantElem;
    size_t tamElem;
}tInfo;

void mostrarCargo(const void* d);

int compararLegajo(const void* d1, const void* d2);
int compararNroLegajo(const void* d1, const void* d2);

void accionEscribirLoteCargoTxt(void* d, const void* accion);
void accionEscribirCargoTxt(void* d, const void* accion);

#endif // UTILIDADES_H_INCLUDED
