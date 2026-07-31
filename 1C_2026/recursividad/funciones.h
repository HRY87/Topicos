#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


long long factorialRecursivo(unsigned num);
size_t strlenRecursivo(const char* str);
char* strchrRecursivo(const char* str, int c);
char* strrchrRecursivo(const char* str, int c);
void* mapRecursivo(void* vec, size_t tamElem, size_t ce, int action(void*));
int esPalindromoRecursivo(const char* str);
int esPalindromoValidar(const char* inicio, const char* fin);
void* mbsearchRecursivo(const void* clave, const void* vec, size_t ce, size_t tam, int comparar(const void*, const void*));
void ordenarVectorSeleccionRecursivo(void* vec, size_t tamElem, size_t ce, int comparar(const void*, const void*), void intercambiar(void*, void*));
void* buscarMenorRecursivo(void* ini, void* fin, size_t tamElem, int comparar(const void*, const void*));
#endif // FUNCIONES_H_INCLUDED
