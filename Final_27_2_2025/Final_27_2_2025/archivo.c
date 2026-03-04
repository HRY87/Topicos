#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivo.h"

void parsearCargoVariable(char* cad, tCargo* c);

int crearArchivoTxt(const char* pathTxt, void* datos, size_t tamElem, size_t cantElem, Accion escribirLote)
{
    FILE* txt = fopen(pathTxt, "wt");

    if(!txt)
        return ERR_ARCH;

    tInfo info;

    info.pf = txt;
    info.cantElem = cantElem;
    info.tamElem = tamElem;

    fprintf(txt, "LEGAJO|SUC|CODCARGO\n");//Encabezado, primera linea

    escribirLote(datos, &info);

    fclose(txt);

    return TODO_OK;
}


int llenarVectorConArchivoTxt(const char* pathTxt, tVector* v)
{
    FILE* txt = fopen(pathTxt, "rt");

    if(!txt)
        return ERR_ARCH;

    char buffer[21];
    tCargo c;

    fgets(buffer, 21, txt);
    while(fgets(buffer, 21, txt))
    {
        parsearCargoVariable(buffer, &c);
        insertarVectorOrd(v, &c, sizeof(tCargo), compararLegajo);
    }

    fclose(txt);
    return TODO_OK;
}

void parsearCargoVariable(char* cad, tCargo* c)
{
    char* pCad = strchr(cad, '\n');
    *pCad = '\0';

    pCad = strrchr(cad, '|');
    strcpy(c->codCargo, pCad + 1);
    *pCad = '\0';

    pCad = strrchr(cad, '|');
    strcpy(c->suc, pCad + 1);
    *pCad = '\0';

    sscanf(cad, "%d", &c->legajo);
}
