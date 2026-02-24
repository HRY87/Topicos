#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct
{
    int dni;
    int legajo;
    float promedio;
    int edad;
    char genero;
}tAlumno;

typedef void *tMostrar(const void* dato);
#endif // ALUMNO_H_INCLUDED
