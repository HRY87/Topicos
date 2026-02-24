#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "cadena.h"

/**Ejercicio 1.6: Verificar si la cadena es palindromo o no*/
bool esPalindromo(const char* cad)
{
    size_t tam = str_len(cad);
    size_t medio = tam / 2;
    bool esPalindromo = true;

    if(!*cad)
        return false;

    for(int i = 0; i < medio && esPalindromo; i++)
    {
        if(tolower(cad[i]) != tolower(cad[tam - i - 1]))
        {
            esPalindromo = false;
        }
    }

    return esPalindromo;
}

/**Ejercicio 1.7 Devolver valor numerico de una cadena**/

/**Opcion A: Valor de la tabla ascii**/
int valorNumericoCadena_ASCII(const char* cad)
{
    int suma = 0;

    if(!*cad)
        return 0;

    for(int i = 0; cad[i] != '\0'; i++)
    {
        suma += (int)cad[i];
    }

    return suma;
}

/**Opcion B: Asignar valor segun la posicion del vector**/
int valorNumericoCadena(const char* cad)
{
    //El valor es asignado segun la posicion en el vector. 0 es espacio
    static char valorCaracter[27] = " abcdefghijklmnopqrstuvwxyz";
    int suma = 0;
    bool caracterEncontrado = false;

    if(!*cad)
        return 0;

    for(int i = 0; cad[i] != '\0'; i++)
    {
        caracterEncontrado = false;

        for(int j = 0; j < 27 && !caracterEncontrado; j++)
        {
            if(cad[i] == valorCaracter[j])
            {
                suma += j; //+1 para no tener en cuenta el cero
                caracterEncontrado = true;
            }
        }
    }

    return suma;
}

/**Ejercicio 1.8: Contar apariciones de una palabra**/
int contarAparicionesPalabra(const char* texto, const char* palabra)
{
    int contPal = 0;
    size_t tamPal;

    if(!*texto || !*palabra)
        return 0;

    tamPal = strlen(palabra); // Tamanio de la palabra

    if(!tamPal)
        return 0;

    while(*texto)
    {
        if(strncmp(texto, palabra, tamPal) == 0 &&
           (texto[tamPal] == '\0' || isspace((unsigned char)texto[tamPal]) || ispunct((unsigned char)texto[tamPal])))
        {
            contPal++;
            texto += tamPal;
        }else
        {
            texto++;
        }
    }

    return contPal;
}

/**Ejercicio 1.9: Contar apariciones de una palabra**/
char* normalizarCadena(const char* cadNormalizar, char* cadNormalizada)
{
    SecPal sLect, sEscr;

    secPalCrear(&sLect, cadNormalizar);
    secPalCrear(&sEscr, cadNormalizada);

    Palabra pal;

    secPalLeer(&sLect, &pal, true);

    while(!secPalFin(&sLect))
    {
        palabraATitulo(&pal);
        secPalEscribir(&sEscr, &pal);
        secPalEscribirCar(&sEscr, ' ');
        secPalLeer(&sLect, &pal, true);
    }

    secPalFin(&sEscr);

    return cadNormalizada;
}

/**1.10: desofuscar cadena desplazando hacia atras dentro del grupo tantos caracteres como posicion tiene en la palabra**/
char* ofuscarCadena(const char* ofuscado, char* desofuscado, const char* clave)
{
    SecPal sLect, sEscr;

    secPalCrear(&sLect, (char*)ofuscado);
    secPalCrear(&sEscr, (char*)desofuscado);

    Palabra pal;

    secPalLeer(&sLect, &pal,false);

    while(!secPalFin(&sLect))
    {
        desofuscarPalabra(&pal, clave);
        secPalEscribir(&sEscr, &pal);
        secPalEscribirCar(&sEscr, ' ');
        secPalLeer(&sLect, &pal, false);
    }

    sEscr.cursor--;
    secPalCerrar(&sEscr);

    return desofuscado;
}

/**Ejercicio 1.11: Comparar cadenas, termina cuando son iguales**/
int cargarParesMatriz(char matriz[][2][MAX_CAD], size_t max_pares)
{
    int i = 0, comp = -1;
    char cad1[MAX_CAD];
    char cad2[MAX_CAD];

    while(i < max_pares && comp != 0)
    {
        puts("Ingrese cadena 1:");
        fgets(cad1, MAX_CAD, stdin);

        puts("Ingrese cadena 2:");
        fgets(cad2, MAX_CAD, stdin);

        /*Eliminar salto de linea*/
        cad1[strcspn(cad1, "\n")] = '\0';
        cad2[strcspn(cad2, "\n")] = '\0';

        comp = compararCadenas(cad1, cad2);

        if(comp < 0)
        {
            str_cpy(matriz[i][0],cad1);
            str_cpy(matriz[i][1],cad2);
        }

        if(comp > 0)
        {
            str_cpy(matriz[i][0],cad1);
            str_cpy(matriz[i][1],cad2);
        }

        i++;
    }

    return i; //Cantidad de pares cargados
}
int compararCadenas(const char* s1, const char* s2)
{
    size_t tam1 = str_len(s1);
    size_t tam2 = str_len(s2);

    if(tam1 < tam2)
        return -1;

    if(tam1 > tam2)
        return 1;

    return str_cmpi(s1, s2);
}

void desofuscarPalabra(Palabra* pal, const char* clave)
{
    int pos = 0;
    int cont = 1;
    int tam = strlen(clave);

    char* pPal = pal->vPal;

    while(*pPal)
    {
        pos = buscarPosicionClave(clave, *pPal);

        if(pos != -1)
            *pPal = *(clave + (pos + cont) % tam);

        cont++;
        pPal++;
    }
}

int buscarPosicionClave(const char* clave, const char c)
{
    int pos = 0;

    while(*clave)
    {
        if(*clave == c)
            return pos;

        pos++;
        clave++;
    }

    return -1;
}

void secPalCrear(SecPal* sec, const char* cad)
{
    sec->cursor = (char*)cad;
    sec->finSec = false;
}

bool secPalLeer(SecPal* sec, Palabra* pal, bool normalizarPalabra)
{
    while(*sec->cursor && !esLetra(*sec->cursor))
    {
        sec->cursor++;
    }

    if(!*sec->cursor)
    {
        sec->finSec = true;
        return false;
    }

    char*pPal = pal->vPal;

    while(*sec->cursor && esLetra(*sec->cursor))
    {
        *pPal = normalizarPalabra ? TOLOWER(*sec->cursor) : *sec->cursor;
        pPal++;
        sec->cursor++;
    }

    *pPal = '\0';

    return true;
}
void secPalEscribir(SecPal* sec, const Palabra* pal)
{
    char* pPal = (char*)pal->vPal;

    while(*pPal)
    {
        *sec->cursor = *pPal;
        sec->cursor++;
        pPal++;
    }
}

void secPalEscribirCar(SecPal* sec, char c)
{
    *sec->cursor = c;
    sec->cursor++;
}

bool secPalFin(const SecPal* sec)
{
    return sec->finSec;
}

void secPalCerrar(SecPal* sec)
{
    *sec->cursor = '\0';
}

void palabraATitulo(Palabra* pal)
{
    char* pPal = pal->vPal;

    *pPal = TOUPPER(*pPal);
}

/**Funciones auxiliares**/
size_t str_len(const char* cad)
{
    size_t tam = 0;

    while(*cad)
    {
        tam++;
        cad++;
    }

    return tam;
}

int str_cmpi(const char* s1, const char* s2)
{
    int dif;
    while(*s1 && *s2)
    {
        dif = (TOLOWER(*s1) - TOLOWER(*s2));

        if(dif != 0)
            return dif;

        s1++;
        s2++;
    }

    return (*s1 ? 1 : (*s2 ? -1 : 0));
}

char* str_cpy(char* s1, const char* s2)
{
    char* pIni = s1;

    while(*s1)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }

    *s1 = '\0';

    return pIni;
}

void limpiarFrase(const char* entrada, char* salida)
{
    int j = 0;

    if(!*entrada)
        return;

    for(int i = 0; entrada[i] != '\0'; i++)
    {
        //Solo letras y numeros
        if(isalnum(entrada[i]))
        {
            salida[j++] = tolower(entrada[i]);
        }

    }

    salida[j] = '\0'; //Fin de cadena
}


