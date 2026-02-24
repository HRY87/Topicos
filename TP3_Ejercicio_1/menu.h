#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdio.h>

#define TAM_TEXTO   200
#define CANT_OPC    4

#define TODO_OK     0
#define ERR_OR      -1

static char opciones[CANT_OPC][TAM_TEXTO] = {
{"Buscar el minimo elemento."},
{"Calcular el promedio de los valores de las posiciones pares."},
{"Mostrarlo en orden inverso."},
{"Salir"}
};

char menu(char texto_opc[][TAM_TEXTO], size_t nro_opc);

#endif // MENU_H_INCLUDED
