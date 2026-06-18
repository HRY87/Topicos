#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#define TODO_OK         0
#define ERR_ARCH        1
#define ERR_LINEA       2
#define ERR_MEM         3

#define TAM_LOTE               5
#define TAM_LOTE_GRANDE        30

#define TAM_LINEA       201

typedef int (*Accion)(void* accion, const void* dato);
typedef void (*Mostrar)(const void* dato);
typedef int (*Condicion)(const void* valorCodicion, const void* dato);

/**Puntero a funcion para conversion generico**/
//Se puede hacer mas generico, como por ejemplo usar Accion pero tenga en cuenta que puede volverse confuso, Ademas de que se vuelve un lio de casteo
typedef void (*BinATxt)(const void* dato, FILE* archTxt);
typedef int (*TxtABin)(char* linea, void* dato);

int crearArchivoTexto(const char* rutaTxt, const void* datos, size_t cantElem, size_t tamElem, Accion escribir);
int crearArchivoBinario(const char* rutaBin, const void* datos, size_t cantElem, size_t tamElem, Accion escribir);

int convertirArchivoBinATxt(const char* rutaBin, const char* rutaTxt, size_t tamElem, BinATxt binATxt);
int convertirArchivoTxtABin(const char* rutaTxt, const char* rutaBin, size_t tamElem, TxtABin txtABin);

int mostrarArchivoBinario(const char* rutaBin, size_t tamElem, Mostrar mostrar);

#endif // ARCHIVO_H_INCLUDED
