/***************************************************************************************
******************************* Complete sus datos *************************************
****************************************************************************************
* Apellido, Nombres:
*
* DNI:
*
****************************************************************************************/

#include <locale.h>
#include <windows.h>
#include <stdio.h>
#include "../SolucionParcialArmadoPCTopicos/TiposArmadoPC.h"
#include "../SolucionParcialArmadoPCTopicos/SolucionParcialArmadoPC.h"

#define ARG_PATH_COMP       1
#define ARG_PATH_ARM_REP    2

int actualizarComponentes_ALU(const char *pathComponentes, const char *pathArmadoYRep);

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "spanish"); // Cambiar locale - Suficiente para m�quinas Linux
    SetConsoleCP(1252);           // Cambiar STDIN -  Para m�quinas Windows
    SetConsoleOutputCP(1252);     // Cambiar STDOUT - Para m�quinas Windows

    generarArchivoStockComponentes(argv[ARG_PATH_COMP]);

    generarArchivoArmadosYReparaciones(argv[ARG_PATH_ARM_REP]);

    puts("Componentes antes de actualizar:\n");
    mostrarArchivoComponentes(argv[ARG_PATH_COMP]);
    puts("");

    puts("Armados/Reparaciones:");
    mostrarArchivoArmadoYRep(argv[ARG_PATH_ARM_REP]);
    puts("");

    ///*********************************************************************************************************
     int resp = actualizarComponentes(argv[ARG_PATH_COMP], argv[ARG_PATH_ARM_REP]);
    ///******** Descomente la l�nea de abajo y comente la de arriba para probar su c�digo **********************
    //int resp = actualizarComponentes_ALU(argv[ARG_PATH_COMP], argv[ARG_PATH_ARM_REP]);
    ///*********************************************************************************************************

    if (resp != TODO_OK)
    {
        puts("Error actualizando los componentes.");
        return resp;
    }

    puts("\nComponentes despues de actualizar:\n");
    mostrarArchivoComponentes(argv[ARG_PATH_COMP]);

    //	getchar();

    return 0;
}

int actualizarComponentes_ALU(const char *pathComponentes, const char *pathArmadoYRep)
{
    return TODO_OK;
}
