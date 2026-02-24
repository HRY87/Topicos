#ifndef TDAVECTOR_H_INCLUDED
#define TDAVECTOR_H_INCLUDED

typedef struct s_nodo
{
    void* info;
    unsigned tamElem;
    struct s_nodo* sig;
}tNodo;

typedef tNodo* tVector;

void crearVector(tVector* v);
int vectorLLeno(const tVector* v, unsigned cantBytes);
int vectorVacio(const tVector* v);
int insertarEnVectorOrd(tVector* v, const void* dato, unsigned cantBytes);
int eliminarDelVector(tVector* v, void* dato, unsigned cantBytes);
void vaciarVector(tVector* v);

#endif // TDAVECTOR_H_INCLUDED
