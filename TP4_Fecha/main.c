#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int main()
{
    tFecha f, fNue;

    puts("Ingrese dos Fechas");
    scanf("%d/%d/%d %d/%d/%d", &f.dia, &f.mes, &f.anio, &fNue.dia, &fNue.mes, &fNue.anio);

    printf("La diferencia es %d\n", difDiasEntreFechas(&f, &fNue));
    printf("Dia de la semana Fecha 1: %d\n", obtenerDiaDeLaSemana(&f));
    printf("Dia de la semana Fecha 2: %d\n", obtenerDiaDeLaSemana(&fNue));
    return 0;
}
