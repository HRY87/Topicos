#ifndef EJERCICIO3_H_INCLUDED
#define EJERCICIO3_H_INCLUDED


#define PATH_ARCH           "datos.txt"
#define TODO_OK             0
#define ERROR_ARCH          1
#define CANT_NUM_MIN        1
#define CANT_NUM_MAX        7
#define CANT_SEP_MIN        1
#define CANT_SEP_MAX        5
#define VALOR_SHORT_MIN     -32768
#define VALOR_SHORT_MAX     32768

#define ES_LINEA_VALIDA(X)(X >= CANT_NUM_MIN && X <= CANT_NUM_MAX)
#define ES_NUMERO_VALIDO(X)(X >= VALOR_SHORT_MIN && X <VALOR_SHORT_MAX)


int crearArchivoTXT(const char* path);

#endif // EJERCICIO3_H_INCLUDED
