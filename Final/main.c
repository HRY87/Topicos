#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    tVector vImp, vMat;
    tConsumo consumos[CANT_MATERIAL];
    tMaterial* mat;
    size_t i;
    int res = TODO_OK;

    res = archivoCrearLotes();

    if(!res)
    {
        if(vectorCrear(&vImp, sizeof(tImpresora)) ||
                vectorCrear(&vMat, sizeof(tMaterial)))
        {
            return SIN_MEMORIA;
        }

        if(vectorInicializarConArchivoBin(PATH_IMPRESORA, &vImp, sizeof(tImpresora), compararImpresoras) ||
                vectorInicializarConArchivoBin(PATH_MATERIALES, &vMat, sizeof(tMaterial), compararMateriales))
        {
            vectorDestruir(&vImp);
            vectorDestruir(&vMat);
            return ERR_ARCHIVO;
        }

        /**Inicializamos consumos con los tipos de materiales disponibles**/
        for(i = 0; i < vMat.ce; i++)
        {
            mat = (tMaterial*)(vMat.datos + (i * vMat.tamElem));

            strcpy((consumos + i)->tipoMaterial, mat->tipoMaterial);
            (consumos + i)->consumo = 0;
        }

        if(!(res = ejercicio1y2(PATH_MODELOS, PATH_TRABAJOS, &vImp, &vMat, consumos, vMat.ce)))
        {
            if(!(res = ejercicio3(&vImp, consumos, vMat.ce)))
            {
                archivoGuardarVector(PATH_IMPRESORA, &vImp);
                archivoGuardarVector(PATH_MATERIALES, &vMat);
            }
        }

        vectorDestruir(&vImp);
        vectorDestruir(&vMat);
    }

    return res;
}
