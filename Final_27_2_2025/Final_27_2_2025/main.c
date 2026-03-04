#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"
#include "vector.h"

#define TAM_NEW     5
#define TAM_OLD     5

int fusionarYGenerarArchivoTxt(const char* pathNew, const char* pathOld, const char* pathCargo, const char* pathErrores,
                               Comparar compararLeg, Comparar compararNro, Accion escribir);

int generarArchivoTxtConVectores(const char* pathCargo, const char* pathErrores, tVector* vNew, tVector* vOld,
                                 Comparar compararLeg, Comparar compararNro, Accion escribir);
int main()
{
    int resp = fusionarYGenerarArchivoTxt(PATH_NEW, PATH_OLD, PATH_CARGO, PATH_ERROR, compararLegajo, compararNroLegajo, accionEscribirCargoTxt);

    return resp;
}

int fusionarYGenerarArchivoTxt(const char* pathNew, const char* pathOld, const char* pathCargo, const char* pathErrores, Comparar compararLeg, Comparar compararNro, Accion escribir)
{
    /*LOTE DE PRUEBA*/
    tCargo vNew[TAM_NEW] =
    {
        {1001, "001", "A01"},//se repite, se guarda 1
        {1002, "002", "B02"},//error
        {1003, "003", "C03"},//se guarda
        {1005, "005", "D04"},//Se repite, se guarda 1
        {1006, "006", "E05"}//se guarda
    };

    tCargo vOld[TAM_OLD] =
    {
        {1001, "001", "A01"},//Se repite, se guarda 1
        {1002, "002", "X99"},//error
        {1004, "004", "C03"},//se guarda
        {1005, "005", "D04"},//Se repite, se guarda 1
        {1007, "007", "F06"}//se guarda
    };

    tVector cNew, cOld; //Vectores para los registros New y Old

    if(!crearArchivoTxt(PATH_NEW, &vNew, sizeof(tCargo), TAM_NEW, accionEscribirLoteCargoTxt) &&
            !crearArchivoTxt(PATH_OLD, &vOld, sizeof(tCargo), TAM_OLD, accionEscribirLoteCargoTxt))
    {
        if(!crearVector(&cNew, sizeof(tCargo), 4) && !crearVector(&cOld, sizeof(tCargo), 4))
        {
            if(!llenarVectorConArchivoTxt(PATH_NEW, &cNew) && !llenarVectorConArchivoTxt(PATH_OLD, &cOld))
            {
                puts("---REGISTRO DE CARGO NEW---");
                mostrarVector(&cNew, mostrarCargo);
                puts("\n---REGISTROS DE CARGO OLD---");
                mostrarVector(&cOld, mostrarCargo);


                if(!generarArchivoTxtConVectores(PATH_CARGO, PATH_ERROR, &cNew, &cOld, compararLeg, compararNro, escribir))
                {
                    puts("TODO OK");
                }

            }
            vaciarVector(&cNew);
            vaciarVector(&cOld);

        }
    }

    return TODO_OK;
}

int generarArchivoTxtConVectores(const char* pathCargo, const char* pathErrores, tVector* vNew, tVector* vOld, Comparar compararLeg, Comparar compararNro, Accion escribir)
{
    int comp = 0;

    FILE* car = fopen(pathCargo, "wt");
    FILE* err = fopen(pathErrores, "wt");

    if(!car || !err)
        return ERR_ARCH;

    void* pNew = vNew->vec;
    void* pOld = vOld->vec;

    void* ultNew = vNew->vec + (vNew->cantElem - 1)* vNew->tamElem;
    void* ultOld = vOld->vec + (vOld->cantElem - 1)* vOld->tamElem;

    while(pNew <= ultNew && pOld <= ultOld)
    {
        comp = compararLeg(pNew, pOld);

        if(comp == 0) //Si hay dos con un mismo legajo se guerdan en errores.txt
        {
            //Se debe comparar por separado por ser una condicion especial si hay legajos iguales

            if(compararNro(pNew, pOld) == 0)//Si ambos tiene el mismo nroCargo solo escribo uno en cargo.txt
            {
                escribir(pNew, car);
            }
            else //Si tiene nroCargo distintos guardo los 2 en errores.txt
            {
                escribir(pNew, err);
                escribir(pOld, err);
            }

            //En ambos casos, paso al siguiente elemento del vector
            pNew += vNew->tamElem;
            pOld += vOld->tamElem;
        }

        if(comp < 0)
        {
            escribir(pNew, car);
            pNew += vNew->tamElem;
        }

        if(comp > 0)
        {
            escribir(pOld, car);
            pOld += vOld->tamElem;
        }
    }

    while(pNew <= ultNew)
    {
        escribir(pNew, car);
        pNew += vNew->tamElem;
    }

    while(pOld <= ultOld)
    {
        escribir(pOld, car);
        pOld += vOld->tamElem;
    }

    fclose(car);
    fclose(err);

    return TODO_OK;
}
