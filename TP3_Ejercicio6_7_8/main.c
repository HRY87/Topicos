#include <stdio.h>
#include <stdlib.h>
#include "macros.h"

int main()
{
//    //*Ejercicio 6*//
//    float num_f = 23.5;
//    int num_neg = -3;
//    char letra = 'c';
//    char mayu = 'A';
//    char minu = 'a';
//
//    //*Pruebas de macros*//
//    printf("Prueba de redondear: %f\n", REDONDEAR(num_f));
//    printf("Prueba de valor absoluto: %d\n", VALOR_ABS(num_neg));
//    printf("Prueba de parte entera: %d\n", PARTE_ENTERA(num_f));
//    printf("Prueba de parte decimal: %f\n", PARTE_DECIMAL(num_f));
//    printf("%c | %c\n", TO_LOWER(mayu), TO_UPPER(minu));
//
//    if(ES_LETRA(letra))
//        puts("Es letra");
//
//    if(ES_DIGITO('1'))
//        puts("Es digito");
//
//    if(ES_MAYUSCULA(TO_UPPER(letra)))
//        puts("Es mayuscula");
//
//    if(ES_MINUSCULA(TO_LOWER(letra)))
//        puts("Es minuscula");
//
//    if(ES_BLANCO(' '))
//        puts("Es blanco");

    //*Ejercicio 7*//
    int num_1 = 12;
    int num_2 = 2;
    printf("El mayor es: %d\n", MAX(num_1, num_2));
    printf("El menor es: %d\n", MIN(num_1, num_2));

    //*Ejercicio 8*//
    INTERCAMBIAR_INT(&num_1, &num_2);
    printf("Numero 1: %d | Numero 2:%d", num_1, num_2);
    return 0;
}
