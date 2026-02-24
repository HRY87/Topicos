#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculadoraComando.h"

int calculadoraComando(const int num_1, const int num_2, const char* tipoOperacion)
{
    int resultado;

    if(strcmp(tipoOperacion, "+") && strcmp(tipoOperacion, "-") && strcmp(tipoOperacion, "*") && strcmp(tipoOperacion, "/"))
        return ERR_TIPO_OPERACION;

    if(!strcmp(tipoOperacion, "/") && !num_2)
        return ERR_MATEMATICO;

    switch(tipoOperacion[0])
    {
        case '+': resultado = num_1 + num_2; break;
        case '-': resultado = num_1 - num_2; break;
        case '*': resultado = num_1 * num_2; break;
        case '/': resultado = num_1 / num_2; break;
    }
    printf("%d %s %d = %d", num_1, tipoOperacion, num_2, resultado);

    return TODO_OK;
}
