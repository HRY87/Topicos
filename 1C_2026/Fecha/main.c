#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"


int main()
{
    tFecha fecha;

    ingresarFecha(&fecha);

//    int dias = ingresarEnteroPositivo();
//    int anio = ingresarEnteroPositivo();

//    tFecha fSuma = sumarDiasAFecha(&fecha, dias);
//    tFecha fResta = restarDiasAFecha(&fecha, dias);
//    tFecha fNue = diaDelAnioFecha(dias,anio);
//    int difFecha = diferenciaEntreFecha(&fSuma, &fResta);
//    int diaAnio = diaDelAnio(&fecha);
    int diaSemana = diaDeLaSemana(&fecha);

//    mostrarFecha(&fSuma);
//    mostrarFecha(&fResta);
//    mostrarFecha(&fNue);

//    printf("Diferencia entre fecha: %d\nDia de la semana: %d\nDia del anio: %d\n", difFecha, diaSemana, diaAnio);
    printf("Dia de la semana: %d\n",diaSemana);

    return 0;
}
