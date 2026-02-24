#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    int dni;
    char apellido[20];
    char nombres[30];
    float peso;
}tPersona;

//*Puntero a funcion*//
typedef int(*Cmp)(const void*, const void*);
typedef void(*Mostrar)(const void*);

//*Funciones mostrar*//
void mostrarVector(void* v, size_t ce, size_t tamElem, Mostrar mostrar);
void mostrar_int(const void* d);
void mostrar_tPersona(const void* d);
//*Funciones comparar*//
int cmp_int_asc(const void* d1, const void* d2);
int cmp_int_des(const void* d1, const void* d2);
int cmp_dni_asc(const void* d1, const void* d2);
int cmp_dni_des(const void* d1, const void* d2);
int cmp_apellido_nombre_asc(const void* d1, const void* d2);
int cmp_apellido_nombre_des(const void* d1, const void* d2);
//*Funciones de Buscar*//
int buscarXdni(const tPersona* p, tPersona* d, size_t ce, Cmp cmp);
#endif // PERSONA_H_INCLUDED
