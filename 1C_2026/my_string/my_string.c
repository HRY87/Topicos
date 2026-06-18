#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"

/**Devuelve la longuitud de la cadena (no cuenta fin de cadena)**/
size_t str_len(const char* s)
{
    size_t tam = 0;

    while(*(s++))
    {
        tam++;
    }

    return tam;
}

/**Concatena los caracteres de s2 en s1**/
char* str_cat(char* s1, const char* s2)
{
    char* ini = s1;

    while(*s1)
    {
        s1++;
    }

    while(*s2)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }

    *s1 = '\0';

    return ini;
}

/**Copia los caracteres de s2 en s1**/
char* str_cpy(char* s1, const char* s2)
{
    char* ini = s1;

    while(*s2)
    {
        *s1 = *s2;
        s1++;
        s2++;
    }

    *s1 = '\0';

    return ini;
}

/**Compara s1 y s2**/
int str_cmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }

    int comp = *s1 - *s2;

    return(comp < 0 ? -1 : (comp > 0 ? 1 : 0));
}

/**Compara s1 y s2 hasta n caracteres ignorando mayusculas**/
int strn_cmp(const char* s1, const char* s2, size_t n)
{
    if(n == 0)
        return 0;

    /**Igual al anterior solo se agrega a que si n llega 0 sale tambien**/
    while(*s1 && --n && (*s1 == *s2))
    {
        s1++;
        s2++;
    }

    int comp = *s1 - *s2;

    return(comp < 0 ? -1 : (comp > 0 ? 1 : 0));
}

/**Compara s1 y s2 ignorando mayusculas y minusculas**/
int str_cmpi(const char* s1, const char* s2)
{
    while(*s1 && (TO_LOWER(*s1) == TO_LOWER(*s2)))
    {
        s1++;
        s2++;
    }

    return(TO_LOWER(*s1) - TO_LOWER(*s2));
}


/**Localia la primera aparicion de c en s**/
char* str_chr(char* s, int c)
{
    while(*s && *s != c)
    {
        s++;
    }

    /**Si son iguales devuelve la posicion de pLec, caso contrario no existe devuelve NULL**/
    return(*s == c ? s : NULL);
}
/**Localiza la ultima aparicion de c en s**/
char* str_rchr(char* s, int c)
{
    char* pLec = s;

    /**Me posiciono al final de la cadena**/
    while(*pLec)
    {
        pLec++;
    }

    /**Termina el bucle si encuentra el caracter o me paso del inicio de la cadena**/
    while(pLec > s && *pLec != c)
    {
        pLec--;
    }

    return (*pLec == c ? pLec : NULL);
}
/**Localiza la primera aparecion de s2 en s1**/
char* str_str(char* s1, const char* s2)
{
    /**Obtengo el tamanio de s2**/
    size_t tam = str_len(s2);

    /**Recorro s1, corta antes si encuentra s2 en s1**/
    /**Esto lo hace por cada caracter de s1 (no se si esto es optimo)**/
    while(*s1 && strncmp(s1, s2, tam))
    {
        s1++;
    }

    /**Si se encontro a s2 en s1 devuelvo la posicion, caso contrario es fin de cadena devuelvo NULL**/
    return (*s1 ? s1 : NULL);
}
