#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <stdbool.h>

#define ANIO_BASE   1601

#define DOMINGO     0
#define LUNES       1
#define MARTES      2
#define MIERCOLES   3
#define JUEVES      4
#define VIERNES     5
#define SABADO      6

typedef struct
{
     int    dia,
            mes,
            anio;
}Fecha;

//Funciones auxiliares
void ingresarFecha(Fecha* f);
bool esFechaValida(const Fecha* f);
bool esAnioBisiesto(int anio);
void mostrarFecha(const Fecha* fecha);
int cantDiasMes(int mes, int anio);
int ingresarEnteroPositivo();

//Funciones
Fecha sumarDiasAFecha(const Fecha* fecha, int dias);
int diferenciaEntreFecha(const Fecha* f1, const Fecha* f2);
int diaDelAnio(const Fecha* fecha);//256 -> dia del programador
Fecha diaDelAnioFecha(int dia, int anio);
int diaDeLaSemana(const Fecha* fecha);
Fecha restarDiasAFecha(const Fecha* f, int dias);
int aJuliano(const Fecha* f);
#endif // FECHA_H_INCLUDED
