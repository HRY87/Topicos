#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define CANT_ELEM_INT  5

int main()
{
    //*Ejercicio 9*//
//    int vInt[CANT_ELEM_INT] = {12, 5, 77, 31, 2};
//
//    puts("---Vector original---");
//    mostrarVector(vInt, CANT_ELEM_INT, sizeof(int), mostrar_int);
//
//    puts("---Vector ordenado forma decendiente---");
//    qsort(vInt, CANT_ELEM_INT, sizeof(int), cmp_int_des);
//    mostrarVector(vInt, CANT_ELEM_INT, sizeof(int), mostrar_int);
//
//    puts("---Vector ordenado forma ascendiente---");
//    qsort(vInt, CANT_ELEM_INT, sizeof(int), cmp_int_asc);
//    mostrarVector(vInt, CANT_ELEM_INT, sizeof(int), mostrar_int);

    tPersona p[CANT_ELEM_INT] =
    {
        {37648213, "Rivadavia", "Laura Sofia", 50.2},
        {38542182, "Saavedra", "Joaquin Jose", 70.8},
        {38482945, "Belgrano", "Martina", 54.6},
        {40582721, "Moreno", "Dario Marcos", 68.9},
        {43928173, "San Martin", "Escalada Josefa", 55.7}
    };

    //*Ejercicio 10 y 11*//
    puts("---Mostrar vector forma ascendente");
    qsort(p, CANT_ELEM_INT, sizeof(tPersona), cmp_dni_asc);
    mostrarVector(p, CANT_ELEM_INT, sizeof(tPersona), mostrar_tPersona);

    puts("---Mostrar vector forma descendiente");
    qsort(p, CANT_ELEM_INT, sizeof(tPersona), cmp_apellido_nombre_des);
    mostrarVector(p, CANT_ELEM_INT, sizeof(tPersona), mostrar_tPersona);

    //*Ejercicio 12 y 13*//
    tPersona d = {40582721, "Moren", "Dario Marcos", 68.9};
    puts("---Busqueda de registro");
    if(buscarXdni(p, &d, CANT_ELEM_INT, cmp_apellido_nombre_asc))
        printf("%08d %-20s %-30s %4.2f\n", d.dni, d.apellido, d.nombres, d.peso);
    return 0;
}
