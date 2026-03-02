#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#define ORDEN       4
#define SIN_MEM     1


void** crearMatriz(size_t filas, size_t columnas, size_t tamElem);
void eliminarMatriz(void** matriz, size_t filas);
void cargarMatriz(int** matriz, size_t filas, size_t columnas);
void mostrarMatriz(int** matriz, size_t filas, size_t columnas);
int sumaDiagonalPrincipal(int** matriz, int orden);
int sumaDiagonalSecundaria(int** matriz, int orden);
int sumaTriangularInferiorDP(int** matriz, int orden);
int sumaTriangularSuperiorDP(int** matriz, int orden);
int** productoMatrices(int** mat1, int** mat2, size_t filM1, size_t colM1filM2, size_t colM2);
#endif // MATRIZ_H_INCLUDED
