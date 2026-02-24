#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fecha.h"

static int cantDiasMes[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static const int acumDiasPorMes[2][13]=
{
    {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
    {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}
};

//*Ejercicio 1: Validar fecha*//
int esFechaValida(const tFecha* f)
{
    if(f->anio >= ANIO_BASE)
    {
        if(f->mes >= 1 && f->mes <= 12)
        {
            if(f->dia >= 1 && f->dia <= cantDiasMes[esAnioBisiesto(f->anio)][f->mes])
                return VERDADERO;
        }
    }
    return FALSO;
}

//*Ejercicio 2: Obtener fecha dia siguiente*//
tFecha fechaDiaSiguiente(const tFecha* f)
{
    tFecha fSig;

    fSig.dia = f->dia + 1;
    fSig.mes = f->mes;
    fSig.anio = f->anio;

    if(fSig.dia > cantDiasMes[esAnioBisiesto(fSig.anio)][fSig.mes])
    {
        fSig.dia = 1;
        fSig.mes++;

        if(fSig.mes > 12)
        {
            fSig.mes = 1;
            fSig.anio++;
        }
    }

    return fSig;
}

//*Ejercicio 3: sumar N dias a la fecha*//
tFecha sumarNDiasFecha(const tFecha* f, const unsigned dias)
{
    tFecha fNue;
    int topeDias;

    fNue.dia = f->dia + dias;
    fNue.mes = f->mes;
    fNue.anio = f->anio;

    topeDias = cantDiasMes[esAnioBisiesto(fNue.anio)][fNue.mes];

    while(fNue.dia > topeDias)
    {
        topeDias = cantDiasMes[esAnioBisiesto(fNue.anio)][fNue.mes];
        fNue.dia -= topeDias;
        fNue.mes++;

        if(fNue.mes > 12)
        {
            fNue.mes = 1;
            fNue.anio++;
        }
    }

    return (fNue);
}

//*Ejercicio 4: restar N dias a la fecha*//
tFecha restarNDiasFecha(const tFecha* f, const unsigned dias)
{
    tFecha fNue;

    fNue.dia = f->dia - dias;
    fNue.mes = f->mes;
    fNue.anio = f->anio;

    while(fNue.dia < 1)
    {
        fNue.mes--;
        fNue.dia += cantDiasMes[esAnioBisiesto(fNue.anio)][fNue.mes];

        if(fNue.mes < 1)
        {
            fNue.mes = 13;
            fNue.anio--;
        }
    }

    return (fNue);
}
//*Ejercicio 5: Cantidad de dias entre fechas*//
unsigned difDiasEntreFechas(const tFecha* f1, const tFecha* f2)
{
    int anioBase= (f1->anio <= f2->anio ? f1->anio : f2->anio);
    int distBase1 = f1->anio - anioBase;
    int distBase2= f2->anio - anioBase;

    /*Uso el año menor como base y despues con la formula de bisiesto compenso
    el/los dia/s adicional/es que hay entre las fechas.
    Si el año es igual al anioBase entonces dara cero y se sumara la sumatoria de dias que devuelve diaDelAnio*/
    int diasMenor1 = distBase1*365 + distBase1/4 - distBase1/100
                    + distBase1/400 +(distBase1!=0) + aJuliano(f1);

    int diasMenor2 =  distBase2*365 + distBase2/4 - distBase2/100
                    + distBase2/400 +(distBase2!=0) + aJuliano(f2);

    return (abs(diasMenor1 - diasMenor2));
}

//*Ejercicio 6: Obtener dia de la semana*//
int obtenerDiaDeLaSemana(const tFecha* f)
{
    int distBase = f->anio % 400;

    return (SABADO - 1 + distBase + distBase/4 - distBase/100 + (distBase != 0) + aJuliano(f))% 7;
}


//*Funciones Auxiliares*//
int esAnioBisiesto(const int anio)
{
    return(((anio % 4 == 0 && anio % 100 != 0)
           || anio % 400 == 0) ?
           VERDADERO : FALSO);
}

int aJuliano(const tFecha* f)
{
    return (acumDiasPorMes[ES_ANIO_BISIESTO(f->anio)][f->mes] + f->dia);
}
