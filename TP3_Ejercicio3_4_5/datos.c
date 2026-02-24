#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "windows.h"
#include "datos.h"

int crearArchivo(const char* path, size_t tamEspacio)
{
    FILE* pf = fopen(path, "wt");
    short int v[7] = {0};
    char opc;
    int i, ce;

    if(!pf)
        return ERR_ARCH;

    fprintf(pf, "123456 123456 123456 123456 123456 123456 123456\n");

    do
    {
        ce = cargarFila(v, tamEspacio);

        for(i = 0; i < ce; i++)
            fprintf(pf, "%-6d ", v[i]);
        fprintf(pf, "\n");
        puts("Desea terminar y guardar el archivo ?");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }while(tolower(opc) == 'n');

    fclose(pf);
    return TODO_OK;
}

int cargarFila(short int* v, size_t tamEspacio)
{
    int cantPorFila = 0;
    char opc;
    do
    {
        puts("Agregar numero:");
        scanf("%d", v);

        v++;
        cantPorFila++;

        puts("Desea agregar otro?");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }while(tolower(opc) == 's' && cantPorFila < TAM_ESPACIO );

    return cantPorFila;
}
