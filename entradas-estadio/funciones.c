#include "funciones.h"

/**Nota:
    El proyecto viene sin lote de prueba.
    Dejo uno para que puedan centrarse en la resolucion.
    Pueden modificarlo como gusten o entiendan el enunciado
**/
void accionMostrarEntrada(void *entrada, void *extra)
{
    Entrada *ent = (Entrada *)entrada;

    printf("%s  %s\n", ent->cod, ent->usada == false ? "false" : "true");
}

// ARCHIVO
void archivoEntradasGenerar(const char *nomArchEntradas)
{
    FILE *arch = fopen(nomArchEntradas, "wb");
    if (!arch)
        return;

    Entrada vecEntradas[TAM_MAX_ENTRADAS] = {
        {"E00001", false},
        {"A00001", false},
        {"A00004", false},
        {"B00002", false},
        {"C00004", false},
        {"D00004", false},
        {"B00003", false},
        {"C00001", false},
        {"B00004", false},
        {"C00002", false},
        {"A00003", false},
        {"C00003", false},
        {"D00002", false},
        {"D00001", false},
        {"D00003", false},
        {"E00003", false},
        {"E00002", false},
        {"B00001", false},
        {"A00002", false},
        {"E00004", false},
    };

    fwrite(vecEntradas, sizeof(Entrada), TAM_MAX_ENTRADAS, arch);

    fclose(arch);
}

void archivoEntradasRecorrer(const char *nomArchEntradas, Accion accion, void *datosAccion)
{
    Entrada ent;
    FILE *arch = fopen(nomArchEntradas, "r+b");

    if (!arch)
        return;

    while (fread(&ent, sizeof(Entrada), 1, arch))
    {
        accion(&ent, datosAccion);
    }

    fclose(arch);
}

