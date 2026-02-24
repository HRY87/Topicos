#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

char menu(char texto_opc[][TAM_TEXTO], size_t nro_opc)
{
    int i;
    char opc;

    for(i = 0; i < nro_opc; i++)
        printf("%d- %s\n", i + 1, texto_opc + i);

    puts("Ingrese la opcion que desee realizar:");

    do
    {
        fflush(stdin);
        scanf("%c", &opc);
    }
    while(opc < '1'  && opc > '4');

    return opc;
}
