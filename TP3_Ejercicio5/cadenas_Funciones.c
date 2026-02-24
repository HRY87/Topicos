#include <stdio.h>
#include <stdlib.h>
#include "cadenas.h"

void pruebaDeCadenas(const char* cad)
{
    tAlumno alu;
    char mensaje[201];

    sscanf(cad, "%ld %s %lf", &alu.dni, alu.ayn, & alu.prom);

    printf("%08ld | %-51s | %.2lf\n", alu.dni, alu.ayn, alu.prom);

    sprintf(mensaje, "Registro del alumno: %08ld | %-51s | %.2lf\n", alu.dni, alu.ayn, alu.prom);
    puts(mensaje);
}
