#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"

#define CANT_ALU        5

int crearArchivo(const char* path)
{
    tAlumno alu[CANT_ALU] = {
        {12345678, "Basile, Carlos",    69.6},
        {23456789, "Riquelme, Roman",   79.4},
        {45678901, "Palermo, Martin",   63.2},
        {45423135, "Sambrano, Sofia",   79.1},
        {12323145, "Rojo, Dario",       89.8}
    };

    FILE* pf = fopen(path, "wb");

    if(!pf)
        return 1;

    fwrite(alu, sizeof(tAlumno), CANT_ALU, pf);

    fclose(pf);

    return 0;
}
int modificarArchivo(const char* path)
{
    FILE* fAux = fopen("auxiliar.dat", "wb");
    FILE* pf = fopen(path, "rb");
    tAlumno alu;

    if(!fAux && !pf)
        return 1;

    fread(&alu, sizeof(tAlumno), 1, pf);
    while(!feof(pf))
    {
        if(alu.peso > 70.5)
            alu.peso -= 10.5;

        fwrite(&alu, sizeof(tAlumno), 1, fAux);
        fread(&alu, sizeof(tAlumno), 1, pf);
    }


    fclose(pf);
    fclose(fAux);

    unlink(path);
    rename("auxiliar.dat", path);

    return 0;
}

int mostrarArchivo(const char* path)
{
    FILE* pf = fopen(path, "rb");
    tAlumno alu;

    if(!pf)
        return 1;

    fread(&alu, sizeof(tAlumno), 1, pf);
    while(!feof(pf))
    {
        printf("%d | %s | %.2f\n", alu.dni, alu.ayp, alu.peso);
        fread(&alu, sizeof(tAlumno), 1, pf);
    }

    fclose(pf);

    return 0;
}
