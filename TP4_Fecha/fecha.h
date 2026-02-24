#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#define FALSO       0
#define VERDADERO   1

#define ANIO_BASE   1601

#define DOMINGO     0
#define LUNES       1
#define MARTES      2
#define MIERCOLES   3
#define JUEVES      4
#define VIERNES     5
#define SABADO      6

#define ES_ANIO_BISIESTO(X)((X % 4 == 0 && X % 100 != 0) || (X % 400 == 0))

typedef struct
{
    int dia;
    int mes;
    int anio;
}tFecha;

//*Ejercicio 1: Validar fecha*//
int esFechaValida(const tFecha* f);

//*Ejercicio 2: Obtener fecha dia siguiente*//
tFecha fechaDiaSiguiente(const tFecha* f);

//*Ejercicio 3: sumar N dias a la fecha*//
tFecha sumarNDiasFecha(const tFecha* f, const unsigned dias);

//*Ejercicio 4: restar N dias a la fecha*//
tFecha restarNDiasFecha(const tFecha* f, const unsigned dias);

//*Ejercicio 5: Cantidad de dias entre fechas*//
unsigned difDiasEntreFechas(const tFecha* f1, const tFecha* f2);

//*Ejercicio 6: Obtener dia de la semana*//
int obtenerDiaDeLaSemana(const tFecha* f);

//*Funciones Auxiliares*//
int esAnioBisiesto(const int anio);
int aJuliano(const tFecha* f);
#endif // FECHA_H_INCLUDED
