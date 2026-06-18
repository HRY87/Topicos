#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <stdbool.h>

#define NO_EXISTE       -1
#define ES_MENOR        -1
#define ES_MAYOR         1
#define TAM_PAL         31
#define MAX_CAD         51

#define ES_MAYUS(X)((X) >= 'A' && (X) <= 'Z')
#define ES_MINUS(X)((X) >= 'a' && (X) <= 'z')
#define IS_ALPHA(X)(ES_MAYUS(X) || ES_MINUS(X))
#define TO_UPPER(c)(ES_MINUS(c) ? (c) - ('a' - 'A') : (c))
#define TO_LOWER(c)(ES_MAYUS(c) ? (c) + ('a' - 'A') : (c))

typedef struct
{
    char* cursor;
    bool finSec;
}SecPal;

typedef struct
{
    char vPal[TAM_PAL];
}Palabra;

/**Ejercicio 1.6: Determina si una cadena es palindromo**/
bool esPalindromo(const char* cad);

/**Ejercicio 1.7: Devolver valor numerico de una cadena**/
/**Opcion A: Valor de la tabla ascii**/
int valorNumericoCadena_ASCII(const char* cad);
/**Opcion B: Asignar valor segun la posicion del vector**/
int valorNumericoCadena(const char* cad);

/**Ejercicio 1.8: Contar apariciones de una palabra**/
int contarAparicionesPalabra(const char* texto, const char* palabra);
void limpiarFrase(const char* entrada, char* salida);

/**Ejercicio 1.9: Normalizar cadena**/
char* normalizarCadena(const char* cadNormalizar, char* cadNormalizada);
void secPalCrear(SecPal* sec, const char* cad);
bool secPalLeer(SecPal* sec, Palabra* pal, bool normalizarPalabra);
void secPalEscribir(SecPal* sec, const Palabra* pal);
void secPalEscribirCar(SecPal* sec, char c);
bool secPalFin(const SecPal* sec);
void secPalCerrar(SecPal* sec);
void palabraATitulo(Palabra* pal);

/**1.10: desofuscar cadena desplazando hacia atras dentro del grupo tantos caracteres como posicion tiene en la palabra**/
char* ofuscarCadena(const char* ofuscado, char* desofuscado, const char* clave);
int buscarPosicionClave(const char* clave, const char c);
void desofuscarPalabra(Palabra* pal, const char* clave);

/**Ejercicio 1.11: Comparar cadenas ingresada por teclado, termina cuando son iguales**/
int cargarParesMatriz(char matriz[][2][MAX_CAD], size_t max_pares);
int compararCadenas(const char* s1, const char* s2);

/**Funciones propias de string.h**/
size_t str_len(const char* cad);
int str_cmpi(const char* s1, const char* s2);
char* str_cpy(char* s1, const char* s2);

#endif // CADENA_H_INCLUDED
