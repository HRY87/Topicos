#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define TAM_VEC     50

int main()
{
    int vec[TAM_VEC];
    int ce = TAM_VEC;
    if(!eliminarVectorTodasApariciones(vec, &ce, 53))
    {
        mostrarVector(vec, ce, mostrarInt);
    }
    return 0;
}
