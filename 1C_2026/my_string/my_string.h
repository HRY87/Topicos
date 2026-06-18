#ifndef MY_STRING_H_INCLUDED
#define MY_STRING_H_INCLUDED


#define TO_UPPER(X)((X) >= 'a' && (X) <= 'z'  ? (X) - 32 : (X))
#define TO_LOWER(X)((X) >= 'A' && (X) <= 'Z'  ? (X) + 32 : (X))

/**Devuelve la longuitud de la cadena (no cuenta fin de cadena)**/
size_t str_len(const char* s);

/**Concatena los caracteres de s2 en s1**/
char* str_cat(char* s1, const char* s2);

/**Copia los caracteres de s2 en s1**/
char* str_cpy(char* s1, const char* s2);

/**Compara s1 y s2**/
int str_cmp(const char* s1, const char* s2);

/**Compara s1 y s2 ignorando mayusculas**/
int str_cmpi(const char* s1, const char* s2);

/**Compara s1 y s2 hasta n caracteres**/
int strn_cmp(const char* s1, const char* s2, size_t n);

/**Localia la primera aparicion de c en s**/
char* str_chr(char* s, int c);

/**Localiza la ultima aparicion de c en s**/
char* str_rchr(char* s, int c);

/**Localiza la primera aparecion de s2 en s1**/
char* str_str(char* s1, const char* s2);
#endif // MY_STRING_H_INCLUDED
