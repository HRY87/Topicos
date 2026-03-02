#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"


int main()
{
    Fecha fecha;

    ingresarFecha(&fecha);

//    int dias = ingresarEnteroPositivo();
//    int anio = ingresarEnteroPositivo();
//
//    Fecha fSuma = sumarDiasAFecha(&fecha, dias);
//    Fecha fResta = restarDiasAFecha(&fecha, dias);
//    Fecha fNue = diaDelAnioFecha(dias,anio);
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

