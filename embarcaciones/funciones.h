#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TODO_OK                 0
#define ERR_ARCH                1
#define ERR_LINEA_LARGA         2
#define DUPLICADO_O_ACTUALIZADO 3

#define R                       6371 // Radio de la Tierra en kilómetros
#define PI                      3.1415
#define TAM_MAX_LINEA           500

#define MAX_LONG_MATRICULA_EMBARCACION      20
#define MAX_CANT_EMBARCACIONES              20

typedef struct
{
    char matricula[MAX_LONG_MATRICULA_EMBARCACION];
    double latitud;
    double longitud;
    double distanciaKM;
} EmbarcacionRecorrido;


double haversine(double lat1, double lon1, double lat2, double lon2);

#endif // FUNCIONES_H_INCLUDED
