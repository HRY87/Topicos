#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matematicas.h"

long long factorial(const int num)
{
    long res = 1;

    if(num == 0)
        return res;

    for(int n = num; n > 0; n--)
    {
        res *= n;
    }

    return res;
}

long combinatorio(const int m, const int n)
{
    if(!ES_COMBINATORIO_VALIDO(m, n))
        return ERR_COMBINATORIO;

    return (factorial(m) / (factorial(n) * factorial(m - n)));
}

double exponencial(const int x, const float tol)
{
    double res = 1;
    double term = (double)x;
    unsigned nTerm = 2;

    while(term >= tol)
    {
        term = (double)pow(x, nTerm) / factorial(nTerm);
        res += term;
        nTerm++;
    }

    return res;
}

double raizCuadrada(const int num, const float tol)
{
    double term1 = 1, term2 = 0.5 * (term1 + (num/term1));

    while(abs(term1 - term2) >= tol)
    {
        term1 = term2;
        term2 = 0.5 * (term1 + (num/term1));
    }

    return term2;
}

bool existeSerieFibonacci(const int num)
{
    int term, ant1 = 1, ant2 = 1;
    bool existeNumero = false;

    term = ant1;

    while(term <= num && !existeNumero)
    {
        if(term == num)
        {
            existeNumero = true;
        }

        term = ant1 + ant2;
        ant2 = ant1;
        ant1 = term;
    }

    return existeNumero;
}

double seno(const int x, const float tol)
{
    double res = x;
    double term = x;
    int cambioSigno = -1;

    for(unsigned nTerm = 3; fabs(term) > tol; nTerm += 2)
    {
        term = cambioSigno * pow(x, nTerm) / factorial(nTerm);
        res += term;
        cambioSigno *= -1;
    }

    return res;
}

int clasificarNumeroNatural(const int num)
{
    int sum = obtenerSumaDeDivisioresMenores(num);

    return(sum == num ? ES_NUMERO_PERFECTO :
           (sum < num ? ES_NUMERO_DEFICIENTE : ES_NUMERO_ABUNDANTE));
}

int obtenerSumaDeDivisioresMenores(const int num)
{
    int sum = 0;

    for(int i = 1; i < num; i++)
    {
        if(ES_DIVISOR(num, i))
        {
            sum += i;
        }
    }

    return sum;
}

double productoSumaSucesivas(const int num1, const int num2)
{
    double res = 0;

    for(int i = 0; i < num1; i++)
    {
        res += num2;
    }

    return res;
}

int calcularCocienteResto(const int a, const int b, double* cociente, int* resto)
{
    if(b == 0)
        return ERR_COCIENTE;

    *cociente = a/b;
    *resto = a%b;

    return TODO_OK;
}

long long sumarPrimerosNumerosNaturales(const int n)
{
    long long sum = 0;

    for(int i = 1; i < n; i++)
    {
        sum += i;
    }

    return sum;
}

long long sumarPrimerosNumerosNaturalesPares(const int n)
{
    long long sum = 0;
    int contPares = 0;

    for(int i = 2; contPares < n; i += 2)
    {
        sum += i;
        contPares++;
    }

    return sum;
}

long long sumarMenoresNumerosNaturalesPares(const int n)
{
    long sum = 0;

    for(int i = 2; i < n; i += 2)
    {
        sum += i;
    }

    return sum;
}

bool esNumeroPrimo(const int n)
{
    if(n == 2) //2 es el unico primo par
        return true;

    if(n <= 0 || n % 2 == 0) //0, 1, negativos y pares mayores a 2 no son primos
        return false;

    //Verificamos hasta la raiz cuadrada de n
    int limite = (int)sqrt(n);

    //Saltamos los numeros pares
    for(int i = 3; i <= limite; i+=2)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}
