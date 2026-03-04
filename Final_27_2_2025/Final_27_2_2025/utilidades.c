#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"

void mostrarCargo(const void* d)
{
    tCargo* c = (tCargo*)d;
    printf("%d|%s|%s\n", c->legajo, c->suc, c->codCargo);
}

int compararLegajo(const void* d1, const void* d2)
{
    tCargo* c1 = (tCargo*)d1;
    tCargo* c2 = (tCargo*)d2;

    return c1->legajo - c2->legajo;
}

int compararNroLegajo(const void* d1, const void* d2)
{
    tCargo* c1 = (tCargo*)d1;
    tCargo* c2 = (tCargo*)d2;

    return strcmpi(c1->codCargo, c2->codCargo);
}

void accionEscribirLoteCargoTxt(void* d, const void* accion)
{
    tCargo* c = (tCargo*)d;
    tInfo* info = (tInfo*)accion;

    for(size_t i = 0; i < info->cantElem; i++, c++)
    {
        fprintf(info->pf, "%d|%s|%s\n", c->legajo, c->suc, c->codCargo);
    }
}

void accionEscribirCargoTxt(void* d, const void* accion)
{
    tCargo* c = (tCargo*)d;
    FILE* pf = (FILE*)accion;

    fprintf(pf, "%d|%s|%s\n", c->legajo, c->suc, c->codCargo);
}
