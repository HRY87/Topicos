#include <stdio.h>
#include <stdlib.h>
#include "calculadoraComando.h"

int main(int argc, char* argv[])
{
    int num_1 = atoi(argv[1]);
    int num_2 = atoi(argv[2]);
    int info;

    if((info =calculadoraComando(num_1, num_2, argv[3])) == ERR_TIPO_OPERACION)
        puts("El tipo de operacion es incorrrecto");
    else
        if(info == ERR_MATEMATICO)
            puts("No se puede dividir por cero");
    return 0;
}
