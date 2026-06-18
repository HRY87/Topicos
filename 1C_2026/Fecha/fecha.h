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
}tFecha;


/**Ejercicio 4.1: Determine si una fecha es valida**/
bool esFechaValida(const tFecha* f);
bool esAnioBisiesto(int anio);
int cantDiasMes(int mes, int anio);

/**Ejercicio 4.2: Obtener fecha del dia siguiente**/
tFecha diaSiguiente(const tFecha* f);

/**Ejercicio 4.3: Obtener la fecha sumandole N dias**/
tFecha sumarDiasAFecha(const tFecha* f, int dias);

/**Ejercicio 4.4: Obtener fecha restandole N dias**/
tFecha restarDiasAFecha(const tFecha* f, int dias);

/**Ejercicio 4.5: Obtener cantidad de dias entre dos fechas**/
int diferenciaEntreFecha(const tFecha* f1, const tFecha* f2);

/**Ejercicio 4.6: Obtener un entero que corresponda al dia de la semana**/
int diaDeLaSemana(const tFecha* f);
int aJuliano(const tFecha* f);

/**Otra versiones del 4.6 centrado en obtener dia**/
int diaDelAnio(const tFecha* f);
tFecha diaDelAnioFecha(int dia, int anio);

/**Funciones Auxiliares**/
void ingresarFecha(tFecha* f);
void mostrarFecha(const tFecha* f);
int ingresarEnteroPositivo();

#endif // FECHA_H_INCLUDED
