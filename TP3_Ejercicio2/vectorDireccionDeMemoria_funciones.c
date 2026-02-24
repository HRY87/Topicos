#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vectorDireccionDeMemoria.h"

void* encontrarPosicionDelElemento(void* v, const void* dato, size_t cantElem, size_t tamElem)
{
    void* posFinal = v + (cantElem * tamElem);
    int posEncontrada = FALSO;
    void* pos = NULL;

    while(v < posFinal && !posEncontrada)
    {
        if(!memcmp(v, dato, tamElem))
        {
            posEncontrada = VERDADERO;
            pos = v;
        }
        v += tamElem;
    }

    return pos;
}
