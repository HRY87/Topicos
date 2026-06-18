#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"

#define TAM_CAD_CORTO     31
#define TAM_CAD_LARGO     71

int main()
{
    /**Variables**/
    char cad1[TAM_CAD_CORTO] = "Es cadena vacia?";
//    char cad2[TAM_CAD_CORTO] = "es cadena vacia?";
//    char cad3[TAM_CAD_CORTO] = "este no";
//    char cadVacia1[TAM_CAD_CORTO];
//    char cadVacia2[TAM_CAD_CORTO];

    /**Prueba str_len**/
//    printf("str_len:  %llu\n", str_len(cad1));
//    printf("strlen:   %llu\n", strlen(cad1));

    /**Prueba str_cat**/

//    str_cat(cad1, cad2);
//    strcat(cad3, cad2);
//    printf("str_cat:    -%s-\n", cad1);
//    printf("strcat:     -%s-\n", cad3);

////    printf("str_cat:    -%s-\n", str_cat(cad1, cad3));
////    printf("strcat:     -%s-\n", strcat(cad2, cad3));

    /**Prueba str_cpy**/
//    str_cpy(cadVacia1, cad1);
//    strcpy(cadVacia2, cad1);
//    printf("str_cpy:    -%s-\n", cadVacia1);
//    printf("strcpy:     -%s-\n", cadVacia2);

//    printf("str_cpy:    -%s-\n", str_cpy(cadVacia1, cad1));
//    printf("strcpy:     -%s-\n", strcpy(cadVacia2, cad1));

    /**Prueba str_cmp**/
//    printf("str_cmp:    %d\n", str_cmp(cad1, cad3));
//    printf("strcmp:     %d\n", strcmp(cad1, cad3));

    /**Prueba str_cmpi**/
//    printf("str_cmpi:    %d\n", str_cmpi(cad1, cadVacia1));
//    printf("strcmpi:     %d\n", strcmpi(cad1, cadVacia1));

    /**Prueba strn_cmp**/
//    printf("str_cmp:    %d\n", strn_cmp(cad1, cad2, 4));
//    printf("strcmp:     %d\n", strncmp(cad1, cad2, 4));

    /**Prueba str_chr**/
//    printf("str_chr:    -%s-\n", str_chr(cad1, '!'));
//    printf("strchr:     -%s-\n", strchr(cad1, '!'));

    /**Prueba str_rchr**/
//    printf("str_rchr:    -%s-\n", str_rchr(cad1, 'a'));
//    printf("strrchr:     -%s-\n", strrchr(cad1, 'a'));

    /**Prueba str_str**/
    printf("str_str:    -%s-\n", str_str(cad1, ""));
    printf("strstr:     -%s-\n", strstr(cad1, ""));
    return 0;
}
