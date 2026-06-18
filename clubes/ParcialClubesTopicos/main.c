/***************************************************************************************
******************************* Complete sus datos *************************************
****************************************************************************************
* Apellido, Nombres:
*
* DNI:
*
****************************************************************************************/

#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdbool.h>
#include "../SolucionClubesTopicos/UtilitariasClubes.h"
#include "../SolucionClubesTopicos/SolucionClubes.h"

#define ARG_ARCH_CLUB_A 1
#define ARG_ARCH_CLUB_B 2
#define ARG_ARCH_CLUB_FUS 3


int fusionarArchivos_ALU(const char *nombreSociosClubA, const char *nombreSociosClubBTxt, const char *nombreSociosFus);

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "spanish"); // Cambiar locale - Suficiente para m�quinas Linux
	SetConsoleCP(1252);			  // Cambiar STDIN -  Para m�quinas Windows
	SetConsoleOutputCP(1252);	  // Cambiar STDOUT - Para m�quinas Windows

	generarArchivoSociosClubA(argv[ARG_ARCH_CLUB_A]);
	generarArchivoSociosClubBTxtDesord(argv[ARG_ARCH_CLUB_B]);

	mostrarArchSociosA(argv[ARG_ARCH_CLUB_A]);
	mostrarArchSociosBTxt(argv[ARG_ARCH_CLUB_B]);

	/**
		Esta funci�n debe fusionar los archivos de los socios del club A y los del club B en un nuevo archivo.
		La estructura del archivo fusionado es la del archivo de socios del club A.
		El c�digo de socio en el archivo fusionado debe incluir el club de donde proviene. Existen socios que se encuentran en
		los 2 clubes. Ej: socio 1 del club A, el c�digo resultante es 1-A. El c�digo del socio 2, que est� en los 2 clubes
		queda 2-AB.
		La antig�edad se toma la mayor.
	*/
	/// Para que ejecute su c�digo, debe descomentar fusionarArchivos_ALU y comentar fusionarArchivos.
	//fusionarArchivos_ALU(argv[ARG_ARCH_CLUB_A], argv[ARG_ARCH_CLUB_B], argv[ARG_ARCH_CLUB_FUS]);
	fusionarArchivos(argv[ARG_ARCH_CLUB_A], argv[ARG_ARCH_CLUB_B], argv[ARG_ARCH_CLUB_FUS]);

	puts("Archivo Fusionado");
	mostrarArchSociosA(argv[ARG_ARCH_CLUB_FUS]);

	return TODO_OK;
}

int fusionarArchivos_ALU(const char *nombreSociosClubA, const char *nombreSociosClubBTxt, const char *nombreSociosFus)
{
    ///implementar solucion aqui
	return TODO_OK;
}

