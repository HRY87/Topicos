#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define SEP_TXT     '|'

int convertirArchivoTextoBinario(const char* rutaTxt, const char* rutaBin, size_t tam)
{
    FILE* txt = fopen(rutaTxt, "rt");
    tProducto prod;

    if(!txt)
        return 1;

    FILE* bin = fopen(rutaBin, "wb");

    if(!bin)
    {
        fclose(txt);
        return 1;
    }

    char buffer[200];

    fgets(buffer, 200, txt);

    while(!feof(txt))
    {
        trozarProductoTxt(buffer, &prod);
        fwrite(&prod, sizeof(tProducto), 1, bin);
        printf("-%s-\n", prod.descripcion);
        fgets(buffer, 200, txt);
    }

    fclose(txt);
    fclose(bin);
    return 0;
}

void trozarProductoTxt(const char* linea, tProducto* p)
{
    char* aux = strchr(linea, '\n');

    if(!aux)
        return;

    *aux = '\0';

    aux = strrchr(linea, SEP_TXT);
    sscanf(aux + 1, "%f", &p->precio);
    *aux = '\0';

    aux = strrchr(linea, SEP_TXT);
    sscanf(aux + 1, "%d", &p->cantidad);
    *aux = '\0';

    aux = strrchr(linea, SEP_TXT);
    sscanf(aux + 1, "%d/%d/%d", &p->fechaIngreso.dia, &p->fechaIngreso.mes, &p->fechaIngreso.anio);
    *aux = '\0';

    aux = strrchr(linea, SEP_TXT);
    strcpy(p->descripcion, aux + 1);
    *aux = '\0';

    strcpy(p->codigo, linea);
}


void mostrarArchivoBinario(const char* ruta)
{
    FILE* bin = fopen(ruta, "rb");

    if(!bin)
        return;

    tProducto prod;

    fread(&prod, sizeof(tProducto), 1, bin);

    while(!feof(bin))
    {
        printf("%-10s %-40s %02d/%02d/%04d %4d %6.2f\n",
               prod.codigo,
               prod.descripcion,
               prod.fechaIngreso.dia,
               prod.fechaIngreso.mes,
               prod.fechaIngreso.anio,
               prod.cantidad,
               prod.precio);
        fread(&prod, sizeof(tProducto), 1, bin);
    }

    fclose(bin);
}
