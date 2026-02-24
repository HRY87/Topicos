#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

typedef struct
{
    int dni;
    char ayp[51];
    float peso;
}tAlumno;

int crearArchivo(const char* path);
int modificarArchivo(const char* path);
int mostrarArchivo(const char* path);
#endif // ARCHIVO_H_INCLUDED
