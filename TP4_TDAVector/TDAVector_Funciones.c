#include <stdio.h>
#include <stdlib.h>
#include "TDAVector.h"

void crearVector(tVector* v)
{
    *v = NULL;
}

int vectorLLeno(const tVector* v, unsigned cantBytes)
{

}
int vectorVacio(const tVector* v);
int insertarEnVectorOrd(tVector* v, const void* dato, unsigned cantBytes);
int eliminarDelVector(tVector* v, void* dato, unsigned cantBytes);
void vaciarVector(tVector* v);
