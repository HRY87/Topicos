#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "matematicas.h"
#include "utilidades.h"

int ingresarNumeroEntero(const char* mensaje)
{
    int num;

    printf("%s\n", mensaje);

    do
    {
        scanf("%d", &num);

    }
    while(num < 0);

    return num;
}

float ingresarTolerancia(const char* mensaje)
{
    float num;

    printf("%s\n", mensaje);

    do
    {
        scanf("%f", &num);

    }
    while(num < 0);

    return num;
}

void ejecutarCalcularFactorial()
{
    int num;
    long res;
    char opc;
    do
    {
        num = ingresarNumeroEntero("Ingrese un numero entero (n > 0):");
        res = factorial(num);
        printf("El factorial de %d es %ld\n", num, res);

        getchar();

        puts("Desea calcular otro? (s/n)");
        fflush((stdin));
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');
}


void ejecutarCalcularCombinatorio()
{
    int m, n;
    long res;
    char opc;
    do
    {
        m = ingresarNumeroEntero("Ingrese valor para m:");
        n = ingresarNumeroEntero("Ingrese valor para n:");

        res = combinatorio(m, n);

        if(res == ERR_COMBINATORIO)
            puts("ERRO: No cumple la condicion (m >= n && n >= 0) revisar");
        else
            printf("El combinatorio entre (%d / %d) es: %ld\n", m, n, res);

        getchar();

        puts("Desea calcular otro?(s/n):");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');
}


void ejecutarCalcularExponencial()
{
    int x;
    float tol;
    double res;
    char opc;
    do
    {
        x = ingresarNumeroEntero("Ingrese valor para X:");
        tol = ingresarTolerancia("Ingrese valor para TOL:");

        res = exponencial(x, tol);

        printf("El exponencial de %d con toleracia %.5f es: %.8lf\n", x, tol, res);

        getchar();

        puts("Desea calcular otro?(s/n):");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');
}


void ejecutarCalcularRaizCuadrada()
{
    int num;
    float tol;
    double res;
    char opc;
    do
    {
        num = ingresarNumeroEntero("Ingrese valor para num:");
        tol = ingresarTolerancia("Ingrese valor para TOL:");

        res = raizCuadrada(num, tol);

        printf("La raiz cuadrada de %d con toleracia %.5f es: %.8lf\n", num, tol, res);

        getchar();

        puts("Desea calcular otro?(s/n):");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');
}

void ejecutarVerificarNumeroEnFibonacci()
{
    int num;
    char opc;
    do
    {
        puts("Ingrese un numero:");
        scanf("%d", &num);

        if(existeSerieFibonacci(num))
            printf("El numero %d existe en la serie de Fibonacci\n", num);
        else
            printf("El numero %d no existe en la serie de Fibonacci\n", num);

        getchar();

        puts("Desea calcular otro? (s/n)");
        fflush((stdin));
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');
}

void ejecutarCalcularSeno()
{
    int x;
    float tol;
    double res;
    char opc;
    do
    {
        x = ingresarNumeroEntero("Ingrese valor para X:");
        tol = ingresarTolerancia("Ingrese valor para TOL:");

        res = seno(x, tol);

        printf("El seno de %d con toleracia %.5f es: %.8lf\n", x, tol, res);

        getchar();

        puts("Desea calcular otro?(s/n):");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');
}

void ejecutarClasificarNumeroNatural()
{
    int num, res;
    char opc;
    do
    {
        num = ingresarNumeroEntero("Ingrese un numero natural:");

        res = clasificarNumeroNatural(num);

        switch(res)
        {
        case ES_NUMERO_PERFECTO:
            printf("El numero natural %d es perfecto\n", num);
            break;
        case ES_NUMERO_DEFICIENTE:
            printf("El numero natural %d es deficiente\n", num);
            break;
        case ES_NUMERO_ABUNDANTE:
            printf("El numero natural %d es abundante\n", num);
            break;
        default:
            puts("ERROR: El numero ingresado no se puede clasificar");
        }

        getchar();

        puts("Desea calcular otro?(s/n):");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');
}

void ejecutarProductoSumaSucesivas()
{
    int num1, num2;
    double res;
    char opc;

    do
    {
        num1 = ingresarNumeroEntero("Ingrese valor para num1:");
        num2 = ingresarNumeroEntero("Ingrese valor para num2:");

        res = productoSumaSucesivas(num1, num2);

        printf("El producto entre %d y %d es %.2lf\n", num1, num2, res);

        getchar();

        puts("Desea calcular otro?(s/n):");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');

}

void ejecutarCalcularCocienteResto()
{
    int a, b;
    double cociente;
    int resto;
    char opc;

    do
    {
        a = ingresarNumeroEntero("Ingrese valor para a:");
        b = ingresarNumeroEntero("Ingrese valor para b:");

        if(!calcularCocienteResto(a, b, &cociente, &resto))
        {
           printf("El cociente entre %d y %d es %.2f y su resto es %d\n", a, b, cociente, resto);
        }else
        {
            puts("ERROR: b debe ser distinto de 0");
        }

        getchar();

        puts("Desea calcular otro?(s/n):");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');

}

void ejecutarEsNumeroPrimo()
{
    int num;
    char opc;
    do
    {
        num = ingresarNumeroEntero("Ingrese un numero natural:");

        if(esNumeroPrimo(num))
        {
            printf("%d es numero primo\n", num);
        }else
        {
             printf("%d no es numero primo\n", num);
        }

        getchar();

        puts("Desea calcular otro?(s/n):");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');
}

void ejecutarsumarPrimerosNumerosNaturales()
{
    int num;
    long long sum;
    char opc;
    do
    {
        num = ingresarNumeroEntero("Ingrese el valor de N:");

        sum = sumarPrimerosNumerosNaturales(num);

        printf("La suma de los primeros %d numeros naturales es %lld\n", num, sum);

        getchar();

        puts("Desea calcular otro?(s/n):");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');
}

void ejecutarsumarPrimerosNumerosNaturalesPares()
{
    int num;
    long long sum;
    char opc;
    do
    {
        num = ingresarNumeroEntero("Ingrese el valor de N:");

        sum = sumarPrimerosNumerosNaturalesPares(num);

        printf("La suma de los primeros %d numeros naturales pares es %lld\n", num, sum);

        getchar();

        puts("Desea calcular otro?(s/n):");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');
}

void ejecutarsumarMenoresNumerosNaturalesPares()
{
    int num;
    long long sum;
    char opc;
    do
    {
        num = ingresarNumeroEntero("Ingrese el valor de N:");

        sum = sumarMenoresNumerosNaturalesPares(num);

        printf("La suma de los numeros naturales menores a %d es %lld\n", num, sum);

        getchar();

        puts("Desea calcular otro?(s/n):");
        fflush(stdin);
        scanf("%c", &opc);

        system("cls");

    }
    while(tolower(opc) == 's');
}
