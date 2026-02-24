#include <stdio.h>
#include <stdlib.h>
#include "funcionGenerica.h"

int main()
{
    int num_1 = 12;
    int num_2 = 2;

    intercambiar(&num_1, &num_2, tipoIntercambio_int);

    printf("Num_1: %d | Num_2: %d\n", num_1, num_2);
    return 0;
}
