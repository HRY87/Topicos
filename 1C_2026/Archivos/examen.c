#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "archivo.h"
#include "examen.h"

int generarArchivoTextoExamen(const char* rutaTxt)
{
    Examen vExamen[TAM_LOTE] =
    {
        {40111222, "Juan Perez", 'A', 8},
        {38999111, "Maria Lopez", 'R', 3},
        {41222333, "Carlos Gomez", 'A', 10},
        {37777444, "Ana Martinez", 'F', 6},
        {42555666, "Lucia Fernandez", 'A', 7}
    };

    return crearArchivoTexto(rutaTxt, vExamen, TAM_LOTE, sizeof(Examen), escribirExamenTxtVariable);
}

int separarExamenesTexto(const char* rutaExamen, const char* rutaAprobado, const char* rutaDesaprobado, TxtABin trozar, Accion escribir)
{
    Examen ex;
    char* linea;
    unsigned cantAprobados = 0, cantDesaprobados = 0, cantTotal = 0;

    FILE* fExamen = fopen(rutaExamen, "rt");

    if(!fExamen)
    {
        return ERR_ARCH;
    }

    FILE* fAprobado = fopen(rutaAprobado, "wt");

    if(!fAprobado)
    {
        fclose(fExamen);
        return ERR_ARCH;
    }

    FILE* fDesaprobado = fopen(rutaDesaprobado, "wt");

    if(!fDesaprobado)
    {
        fclose(fExamen);
        fclose(fAprobado);
        return ERR_ARCH;
    }

    linea = malloc(TAM_LINEA);

    if(!linea)
    {
        fclose(fExamen);
        fclose(fAprobado);
        fclose(fDesaprobado);
        return ERR_MEM;
    }

    while(fgets(linea, TAM_LINEA, fExamen))
    {
        trozar(linea, &ex);

        if(ex.estado == ESTADO_DESAPROBADO)
        {
            escribir(fDesaprobado, &ex);
            cantDesaprobados++;
        }
        else
        {
            escribir(fAprobado, &ex);
            cantAprobados++;
        }

        cantTotal++;
    }

    free(linea);

    fclose(fExamen);
    fclose(fAprobado);
    fclose(fDesaprobado);

    puts("\n---Resumen---");
    printf("Cantidad total de alumnos: %u\n", cantTotal);
    printf("Cantidad de alumnos aprobados: %u\n", cantAprobados);
    printf("Cantidad de alumnos desaprobados: %u\n", cantDesaprobados);

    return TODO_OK;
}

/**Puntero a funcion**/
int escribirExamenTxtFijo(void* accion, const void* dato)
{
    FILE* txt = (FILE*)accion;
    const Examen* e = (const Examen*)dato;

    if(!txt || !e)
        return ERR_ARCH;

    fprintf(txt, "%08d%-*s%c%02d\n", e->dni, TAM_NOMBRE, e->nombre, e->estado, e->nota);

    return TODO_OK;
}

int escribirExamenTxtVariable(void* accion, const void* dato)
{
    FILE* txt = (FILE*)accion;
    const Examen* e = (const Examen*)dato;

    if(!txt || !e)
        return ERR_ARCH;

    fprintf(txt, "%d|%s|%c|%d\n", e->dni, e->nombre, e->estado, e->nota);

    return TODO_OK;
}

int trozarExamenTxtBinVariable(char* linea, void* reg)
{
    Examen* e = (Examen*)reg;

    char* act = strchr(linea, '\n');

    if(!act)
    {
        return ERR_LINEA;
    }

    *act = '\0';
    act = strrchr(linea, '|');
    sscanf(act + 1, "%d", &e->nota);

    *act = '\0';
    act = strrchr(linea, '|');
    e->estado = *(act + 1);

    *act = '\0';
    act = strrchr(linea, '|');
    strcpy(e->nombre, act + 1);

    *act = '\0';
    sscanf(linea, "%d", &e->dni);

    return TODO_OK;
}

int trozarExamenTxtBinFijo(char* linea, void* reg)
{
    Examen* e = (Examen*)reg;

    char* act = strchr(linea, '\n');

    if(!act)
    {
        return ERR_LINEA;
    }

    *act = '\0';
    act -= TAM_NOTA;
    sscanf(act, "%d", &e->nota);

    *act = '\0';
    act--;
    e->estado = *act;

    *act = '\0';
    act -= TAM_NOMBRE;
    strcpy(e->nombre, act);

    *act = '\0';
    sscanf(linea, "%d", &e->dni);

    return TODO_OK;
}

void mostrarExamenFijo(const void* dato)
{
    Examen* e = (Examen*)dato;

    printf("%08d%-*s%c%02d\n", e->dni, TAM_NOMBRE, e->nombre, e->estado, e->nota);

}

void mostrarExamenVariable(const void* dato)
{
    Examen* e = (Examen*)dato;

    printf("%d|%s|%c|%d\n", e->dni, e->nombre, e->estado, e->nota);

}

