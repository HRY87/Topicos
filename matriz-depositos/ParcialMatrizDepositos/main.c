/***************************************************************************************
******************************* Complete sus datos *************************************
****************************************************************************************
* Apellido, Nombres:
*
* DNI:
*
****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Matriz/Matriz.h"
#include "../Vector/Vector.h"
#include "../SolucionMatrizDepositos/SolucionMatrizDepositos.h"

#define ARG_STOCKS      1
#define ARG_MOVIMIENTOS 2


int actualizarDepositos_ALU(const char *nombreStocks, const char *nombreMovimientos);

int main(int argc, char *argv[])
{
	generarStocks(argv[ARG_STOCKS]);
	generarMovimientos(argv[ARG_MOVIMIENTOS]);

	puts("Stocks antes de actualizar:");
	mostrarStocks(argv[ARG_STOCKS]);

	/*********************************************************************************************************************/
	//actualizarDepositos_ALU(argv[ARG_STOCKS], argv[ARG_MOVIMIENTOS]);
	/************* Descomente la funci�n de arriba y comente la de abajo para ejecutar su c�digo. ************************/
	 actualizarDepositos(argv[ARG_STOCKS], argv[ARG_MOVIMIENTOS]);
	/*********************************************************************************************************************/

	puts("\n\nStocks despues de actualizar:");
	mostrarStocks(argv[ARG_STOCKS]);

	return 0;
}

int actualizarDepositos_ALU(const char *nombreStocks, const char *nombreMovimientos)
{
    ///Implementar resolucion aqui
	return TODO_OK;
}

