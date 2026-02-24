#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conversion.h"

void pruebasDeConversion(const char* cad_i, const char* cad_f)
{
    char* pFin;

    printf("Conversion a float:     %f\n", atof(cad_f));
    printf("Conversion a int:       %d\n", atoi(cad_i));
    printf("Conversion a long:      %ld\n", atol(cad_i));

    printf("Conversion a double:    %lf\n", strtod(cad_f, &pFin));
    printf("Conversion a long:      %ld\n", strtol(cad_i, &pFin, 10));
    printf("Conversion a u.long:    %ld\n", strtoul(cad_i, &pFin, 10));
}
