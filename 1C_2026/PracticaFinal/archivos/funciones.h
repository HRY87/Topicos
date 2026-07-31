#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define TAM_CODIGO          11
#define TAM_DESCRIPCION     41
#define TAM_CANTIDAD        4
#define TAM_PRECIO          6

#define RUTA_BIN            "productos.dat"
#define RUTA_TXT            "productos.txt"

typedef struct
{
    int dia,
        mes,
        anio;
}tFecha;

typedef struct
{
    char codigo[TAM_CODIGO];
    char descripcion[TAM_DESCRIPCION];
    tFecha fechaIngreso;
    int cantidad;
    float precio;
}tProducto;

int convertirArchivoTextoBinario(const char* rutaTxt, const char* rutaBin, size_t tam);
void trozarProductoTxt(const char* linea, tProducto* p);
void mostrarArchivoBinario(const char* ruta);
#endif // FUNCIONES_H_INCLUDED
