#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

//*Devolver valor*//
#define PARTE_ENTERA(X)((int)X)
#define PARTE_DECIMAL(X)(X - (int)X)
#define REDONDEAR(X)(PARTE_DECIMAL(X) >= 0.5 ? PARTE_ENTERA(X) : X)
#define VALOR_ABS(X)(X < 0 ? X*= -1 : X)
#define MAX(X, Y)(X > Y ? X : Y)
#define MIN(X, Y)(X < Y ? X : Y)
//*Verificar condicion*//
#define ES_NUM_PAR(X)(X % 2 == 0)
#define ES_DIGITO(X)(X >= '0' && X<= '9')
#define ES_MAYUSCULA(X)(X >= 'A' && X<= 'Z')
#define ES_MINUSCULA(X)(X >= 'a' && X<= 'z')
#define ES_BLANCO(X)(X == ' ')
#define ES_LETRA(X)(ES_MAYUSCULA(X) || ES_MINUSCULA(X))
#define TO_LOWER(X)(ES_MAYUSCULA(X) ? X += 32 : X)
#define TO_UPPER(X)(ES_MINUSCULA(X) ? X -= 32 : X)
//*Intercambiar memoria*//
#define INTERCAMBIAR_INT(X, Y){\
                            int AUX = *X;\
                                 *X = *Y;\
                                 *Y = AUX;\
                          }
#endif // MACROS_H_INCLUDED
