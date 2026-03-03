#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/**Nota: Hay errores de criterio en los ejemplos del pdf, en el ejemplo para el desempate usan el mayor id de las impresoras,
    pero para la resolucion de este final debemos usar el menor id,
    ademas en los resultados esperados parece que usan ambos criterios generan incosistencia con los resultados
    por ejemplo: T0 se le asigna a id = 5, y T1 se le asigna a id = 1, esto es un error**/

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

        /**Archivos principales despues de actualizar**/
        //mostrarTodosLosArchivos();

        vectorDestruir(&vImp);
        vectorDestruir(&vMat);
    }

    return res;
}
