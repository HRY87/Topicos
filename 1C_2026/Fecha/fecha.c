#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

/**Ejercicio 4.1: Determine si una fecha es valida**/
bool esFechaValida(const tFecha* f)
{
    if(f->anio > ANIO_BASE && (f->mes >= 1 && f->mes <= 12) && (f->dia >= 1 && f->dia <= cantDiasMes(f->mes, f->anio)))
        return true;
    else
        return false;
}

bool esAnioBisiesto(int anio)
{
    return(anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0));
}


int cantDiasMes(int mes, int anio)
{
    int vCdm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(mes == 2 && esAnioBisiesto(anio))
        return 29;

    return vCdm[mes];
}

/**Ejercicio 4.2: Obtener fecha del dia siguiente**/
tFecha diaSiguiente(const tFecha* f)
{
    tFecha fSuma = *f;
    fSuma.dia++;
    int cdm;

    while(fSuma.dia > (cdm = cantDiasMes(fSuma.mes, fSuma.anio)))
    {
        fSuma.dia -= cdm;
        fSuma.mes++;

        if(fSuma.mes > 12)
        {
            fSuma.mes = 1;
            fSuma.anio++;
        }
    }

    return fSuma;
}

/**Ejercicio 4.3: Obtener la fecha sumandole N dias**/
tFecha sumarDiasAFecha(const tFecha* f, int dias)
{
    tFecha fSuma = *f;
    fSuma.dia += dias;
    int cdm;

    while(fSuma.dia > (cdm = cantDiasMes(fSuma.mes, fSuma.anio)))
    {
        fSuma.dia -= cdm;
        fSuma.mes++;

        if(fSuma.mes > 12)
        {
            fSuma.mes = 1;
            fSuma.anio++;
        }
    }

    return fSuma;
}

/**Ejercicio 4.4: Obtener fecha restandole N dias**/
tFecha restarDiasAFecha(const tFecha* f, int dias)
{
    tFecha fRes;

    fRes.dia = f->dia - dias;
    fRes.mes = f->mes;
    fRes.anio = f->anio;

    while(fRes.dia < 1)
    {
        fRes.mes--;
        fRes.dia += cantDiasMes(fRes.mes, fRes.anio);

        if(fRes.mes < 1)
        {
            fRes.mes = 13;
            fRes.anio--;
        }
    }

    return (fRes);
}

/**Ejercicio 4.5: Obtener cantidad de dias entre dos fechas**/
int diferenciaEntreFecha(const tFecha* f1, const tFecha* f2)
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

/**Ejercicio 4.6: Obtener un entero que corresponda al dia de la semana**/
int diaDeLaSemana(const tFecha* fecha)
{
    int distBase = fecha->anio - ANIO_BASE;

    return (SABADO + distBase*365 + distBase/4 - distBase/100 + distBase/400 + (distBase != 0) + aJuliano(fecha))% 7;
}


int aJuliano(const tFecha* f)
{
    static const int acumDiasPorMes[2][13]=
    {
        {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
        {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}
    };
    return (acumDiasPorMes[esAnioBisiesto(f->anio)][f->mes] + f->dia);
}

/**Otra versiones del 4.6**/
int diaDelAnio(const tFecha* f)
{
    int nroDia = 0, i;

    for(i = 1; i < f->mes; i++)
        nroDia += cantDiasMes(i, f->anio);

    nroDia += f->dia;

    return nroDia;
}

tFecha diaDelAnioFecha(int dia, int anio)
{
    tFecha f;
    int diaDelMes = 0;
    f.anio = anio;

    for(f.mes = 1; f.mes < 12 && diaDelMes <= dia; f.mes++)
    {
        diaDelMes = cantDiasMes(f.mes, f.anio);
        dia -= diaDelMes;
    }

    f.dia = dia;

    return f;
}

/**Funciones Auxiliares**/
void ingresarFecha(tFecha* fecha)
{
    puts("Ingresar fecha (dd/mm/aaaa):");
    scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);

    while(!esFechaValida(fecha))
    {
        puts("Error: Fecha invalidad. Ingresar de nuevo(dd/mm/aaaa):");
        scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
    }
}

void mostrarFecha(const tFecha* f)
{
    printf("%02d/%02d/%04d\n", f->dia, f->mes, f->anio);
}

int ingresarEnteroPositivo()
{
    int entero;

    puts("Ingrese un entero positivo:");
    do
    {
        scanf("%d", &entero);
    }
    while(entero < 0);

    return entero;
}
