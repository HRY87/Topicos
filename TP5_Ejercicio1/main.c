#include <stdio.h>
#include <stdlib.h>

#define TODO_OK 0
#define ERR_OR  1

int abrirArchivo();

int main()
{
    if(abrirArchivo() == ERR_OR)
        puts("No se puede abrir el archivo");
    else
        puts("El archivo se abrio correctamente");
    return 0;
}

int abrirArchivo()
{
    FILE* pf;
    pf = fopen("TP5_Ejercicio1.bin", "rb");

    if(!pf)
        return ERR_OR;

    return TODO_OK;
}
