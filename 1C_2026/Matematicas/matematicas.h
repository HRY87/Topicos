#ifndef MATEMATICAS_H_INCLUDED
#define MATEMATICAS_H_INCLUDED

#include <stdbool.h>

#define TODO_OK             0
#define ERR_COMBINATORIO    -1
#define ERR_COCIENTE        -1

#define ES_COMBINATORIO_VALIDO(m, n)(m >= n && n >= 0)

#define ES_NUMERO_PERFECTO          1
#define ES_NUMERO_DEFICIENTE        2
#define ES_NUMERO_ABUNDANTE         3

#define ES_DIVISOR(n, d)(n % d == 0)

/**Ejercicio 1**/
long long factorial(const int num);

/**Ejercicio 2**/
long combinatorio(const int m, const int n);

/**Ejercicio 3**/
double exponencial(const int x, const float tol);

/**Ejercicio 4**/
double raizCuadrada(const int num, const float tol);

/**Ejercicio 5**/
bool existeSerieFibonacci(const int num);

/**Ejercicio 6**/
double seno(const int x, const float tol);

/**Ejercicio 7**/
int clasificarNumeroNatural(const int num);
int obtenerSumaDeDivisioresMenores(const int num);

/**Ejercicio 8**/
double productoSumaSucesivas(const int num1, const int num2);

/**Ejercicio 9**/
int calcularCocienteResto(const int a, const int b, double* cociente, int* resto);

/**Ejercicio 10**/
long long sumarPrimerosNumerosNaturales(const int n);

/**Ejercicio 11**/
long long sumarPrimerosNumerosNaturalesPares(const int n);

/**Ejercicio 12**/
long long sumarMenoresNumerosNaturalesPares(const int n);

/**Ejercicio 13**/
bool esNumeroPrimo(const int n);
#endif // MATEMATICAS_H_INCLUDED

