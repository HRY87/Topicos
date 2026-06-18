#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

#define TAM_DURACION    3
#define TAM_PUNTUACION  2
#define TAM_GENERO      20
#define TAM_TITULO      40

#define RUTA_PELICULA_BIN             "resultados/pelicula.bin"
#define RUTA_PELICULA_TXT_FIJO        "resultados/peliculaFijo.txt"
#define RUTA_PELICULA_TXT_VARIABLE    "resultados/peliculaVariable.txt"

#define RUTA_RANKING_BIN               "resultados/ranking.bin"
typedef struct
{
    char titulo[TAM_TITULO];
    char genero[TAM_GENERO];
    unsigned duracion;
    float puntuacion;
}Pelicula;

int generarArchivoTextoPelicula(const char* rutaTxt);
int generarArchivoBinarioPelicula(const char* rutaBin);

int generarArchivoRankingBinario(const char* rutaPelicula, const char* rutaRanking, Accion escribir, Condicion condicion, void* valorCondicion);

/**Puntero a funcion**/
int escribirAPeliculaTxtFijo(void* accion, const void* dato);
int escribirPeliculaTxtVariable(void* accion, const void* dato);

int escribirPeliculaBin(void* accion, const void* dato);

void mostrarPeliculaFijo(const void* dato);
void mostrarPeliculaVariable(const void* dato);

int condicionMayorPuntuacion(const void* valorCondicion, const void* dato);
#endif // PELICULA_H_INCLUDED
