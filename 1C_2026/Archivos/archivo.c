#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"



/**Genericas**/
int crearArchivoTexto(const char* rutaTxt, const void* datos, size_t cantElem, size_t tamElem, Accion escribir)
{
    size_t i;
    const char* act = (const char*)datos;

    FILE* fTxt = fopen(rutaTxt, "wt");

    if(!fTxt)
        return ERR_ARCH;

    for(i = 0; i < cantElem; i++)
    {
        escribir(fTxt, act);
        act += tamElem;
    }

    fclose(fTxt);
    return TODO_OK;
}

int crearArchivoBinario(const char* rutaBin, const void* datos, size_t cantElem, size_t tamElem, Accion escribir)
{
    size_t i;
    const char* act = (const char*)datos;

    FILE* fBin = fopen(rutaBin, "wb");

    if(!fBin)
        return ERR_ARCH;

    for(i = 0; i < cantElem; i++)
    {
        escribir(fBin, act);
        act += tamElem;
    }

    fclose(fBin);
    return TODO_OK;
}

int convertirArchivoBinATxt(const char* rutaBin, const char* rutaTxt, size_t tamElem, BinATxt binATxt)
{
    FILE* fBin = fopen(rutaBin, "rb");

    if(!fBin)
    {
        return ERR_ARCH;
    }

    FILE* fTxt = fopen(rutaTxt, "wt");

    if(!fTxt)
    {
        fclose(fBin);
        return ERR_ARCH;
    }

    void* reg = malloc(tamElem);

    if(!reg)
    {
        fclose(fBin);
        fclose(fTxt);
        return ERR_MEM;
    }

    fread(reg, tamElem, 1, fBin);

    while(!feof(fBin))
    {
        binATxt(reg, fTxt); //Funcion de conversion bin a txt
        fread(reg, tamElem, 1, fBin);
    }

    free(reg);

    fclose(fBin);
    fclose(fTxt);

    return TODO_OK;
}


int convertirArchivoTxtABin(const char* rutaTxt, const char* rutaBin, size_t tamElem, TxtABin txtABin)
{
    int resp = TODO_OK;
    char* linea; //Buffer temporal para guarda la linea de texto

    FILE* fTxt = fopen(rutaTxt, "rt");

    if(!fTxt)
    {
        return ERR_ARCH;
    }

    FILE* fBin = fopen(rutaBin, "wb");

    if(!fBin)
    {
        fclose(fTxt);
        return ERR_ARCH;
    }

    void* reg = malloc(tamElem);

    if(!reg)
    {
        fclose(fBin);
        fclose(fTxt);
        return ERR_MEM;
    }

    linea =  (char*)malloc(TAM_LINEA); //No olvidar reservar memoria

    fgets(linea, TAM_LINEA, fTxt);
    while(!feof(fTxt) && (resp != ERR_LINEA))
    {
        resp = txtABin(linea, reg);

        if(resp == TODO_OK)
        {
            fwrite(reg, tamElem, 1, fBin);
        }

        fgets(linea, TAM_LINEA, fTxt);
    }

    fclose(fBin);
    fclose(fTxt);

    free(reg);
    free(linea);

    return TODO_OK;
}

int mostrarArchivoBinario(const char* rutaBin, size_t tamElem, Mostrar mostrar)
{
    FILE* fBin = fopen(rutaBin, "rb");

    if(!fBin)
    {
        return ERR_ARCH;
    }

    void* reg = malloc(tamElem);

    if(!reg)
    {
        fclose(fBin);
        return ERR_MEM;
    }

    fread(reg, tamElem, 1, fBin);

    while(!feof(fBin))
    {
        mostrar(reg);
        fread(reg, tamElem, 1, fBin);
    }

    free(reg);

    fclose(fBin);

    return TODO_OK;
}
