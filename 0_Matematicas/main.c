#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"

#define NUMOP_MIN                        1
#define NUMOP_MAX                        13

#define  EXEC_FACTORIAL                1
#define  EXEC_COMBINATORIO             2
#define  EXEC_EXPONENCIAL              3
#define  EXEC_RAIZ_CUADRADA            4
#define  EXEC_FIBONACCI                5
#define  EXEC_SENO                     6
#define  EXEC_CLASIFICACION            7
#define  EXEC_PRODUCTO                 8
#define  EXEC_COCIENTE                 9
#define  EXEC_SUMAR_PRIMEROS_NUM      10
#define  EXEC_SUMAR_PRIMEROS_PARES    11
#define  EXEC_SUMAR_MENORES_PARES     12
#define  EXEC_ES_PRIMO                13

void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int numOp;
    do
    {
        puts("-----Menu-----");
        puts("1 - Calcular factorial.");
        puts("2 - Calcular combinatorio.");
        puts("3 - Calcular exponencial.");
        puts("4 - Calcular raiz Cuadrada.");
        puts("5 - Verificar existencia en serie de Fibonacci.");
        puts("6 - Calcular seno.");
        puts("7 - Clasificar numero natural.");
        puts("8 - Calcular producto con sumatorias sucesivas");
        puts("9 - Calcular cociente y resto.");
        puts("10 - Calcular la suma de los primeros N numeros naturales.");
        puts("11 - Calcular la suma de los primeros N numeros naturales pares.");
        puts("12 - Calcular la suma de los numeros naturales pares menores a N.");
        puts("13 - Validar si es numero primo.");
        puts("0 - Salir");
        puts("Ingrese el numero de operacion:");

        fflush(stdin);
        scanf("%d", &numOp);

        system("cls");

        switch(numOp)
        {
        case EXEC_FACTORIAL:
            ejecutarCalcularFactorial();
            break;
        case EXEC_COMBINATORIO:
            ejecutarCalcularCombinatorio();
            break;
        case EXEC_EXPONENCIAL:
            ejecutarCalcularExponencial();
            break;
        case EXEC_RAIZ_CUADRADA:
            ejecutarCalcularRaizCuadrada();
            break;
        case EXEC_FIBONACCI:
            ejecutarVerificarNumeroEnFibonacci();
            break;
        case EXEC_SENO:
            ejecutarCalcularSeno();
            break;
        case EXEC_CLASIFICACION:
            ejecutarClasificarNumeroNatural();
            break;
        case EXEC_PRODUCTO:
            ejecutarProductoSumaSucesivas();
            break;
        case EXEC_COCIENTE:
            ejecutarCalcularCocienteResto();
            break;
        case EXEC_SUMAR_PRIMEROS_NUM:
            ejecutarsumarPrimerosNumerosNaturales();
            break;
        case EXEC_SUMAR_PRIMEROS_PARES:
            ejecutarsumarPrimerosNumerosNaturalesPares();
            break;
        case EXEC_SUMAR_MENORES_PARES:
            ejecutarsumarMenoresNumerosNaturalesPares();
            break;
        case EXEC_ES_PRIMO:
            ejecutarEsNumeroPrimo();
        break;
        default:
            puts("---Saliendo del menu---");
        }

    }
    while(numOp >= NUMOP_MIN && numOp <= NUMOP_MAX);
}
