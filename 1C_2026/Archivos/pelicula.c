#include <stdio.h>
#include "archivo.h"
#include "pelicula.h"

int generarArchivoTextoPelicula(const char* rutaTxt)
{

    Pelicula vPelicula[TAM_LOTE] =
    {
        {"Inception", "Ciencia Ficcion", 148, 8.8},
        {"Titanic", "Drama", 195, 7.9},
        {"The Dark Knight", "Accion", 152, 9.0},
        {"Toy Story", "Animacion", 81, 8.3},
        {"Interstellar", "Ciencia Ficcion", 169, 8.7}
    };

    return crearArchivoTexto(rutaTxt, vPelicula, TAM_LOTE, sizeof(Pelicula), escribirPeliculaTxtVariable);
}

int generarArchivoBinarioPelicula(const char* rutaBin)
{

Pelicula vPelicula[TAM_LOTE_GRANDE] =
{
    {"Inception", "Ciencia Ficcion", 148, 8.8},
    {"Titanic", "Drama", 195, 7.9},
    {"The Dark Knight", "Accion", 152, 9.0},
    {"Toy Story", "Animacion", 81, 8.3},
    {"Interstellar", "Ciencia Ficcion", 169, 8.7},
    {"Gladiator", "Accion", 155, 8.5},
    {"The Godfather", "Drama", 175, 9.2},
    {"Finding Nemo", "Animacion", 100, 8.1},
    {"Avengers Endgame", "Accion", 181, 8.4},
    {"Shrek", "Comedia", 90, 7.9},
    {"The Matrix", "Ciencia Ficcion", 136, 8.7},
    {"Frozen", "Animacion", 102, 7.4},
    {"Joker", "Drama", 122, 8.5},
    {"Deadpool", "Comedia", 108, 8.0},
    {"The Lion King", "Animacion", 88, 8.5},
    {"Pulp Fiction", "Drama", 154, 8.9},
    {"Iron Man", "Accion", 126, 7.9},
    {"Cars", "Animacion", 117, 7.2},
    {"Doctor Strange", "Ciencia Ficcion", 115, 7.5},
    {"The Avengers", "Accion", 143, 8.0},
    {"Up", "Animacion", 96, 8.2},
    {"Fight Club", "Drama", 139, 8.8},
    {"Black Panther", "Accion", 134, 7.3},
    {"Soul", "Animacion", 100, 8.0},
    {"Avatar", "Ciencia Ficcion", 162, 7.8},
    {"The Batman", "Accion", 176, 7.9},
    {"Coco", "Animacion", 105, 8.4},
    {"Parasite", "Drama", 132, 8.6},
    {"Guardians of the Galaxy", "Ciencia Ficcion", 121, 8.0},
    {"Monsters Inc", "Animacion", 92, 8.1}
};

    return crearArchivoTexto(rutaBin, vPelicula, TAM_LOTE_GRANDE, sizeof(Pelicula), escribirPeliculaBin);
}

int generarArchivoRankingBinario(const char* rutaPelicula, const char* rutaRanking, Accion escribir, Condicion condicion, void* valorCondicion)
{
    Pelicula p;

    FILE* fPelicula = fopen(rutaPelicula, "rb");

    if(!fPelicula)
    {
        return ERR_ARCH;
    }

    FILE* fRanking = fopen(rutaRanking, "wb");

    if(!fRanking)
    {
        fclose(fPelicula);
        return ERR_ARCH;
    }

    fread(&p, sizeof(Pelicula), 1, fPelicula);

    while(!feof(fPelicula))
    {
        if(condicion(valorCondicion, &p))
            escribir(fRanking, &p);

        fread(&p, sizeof(Pelicula), 1, fPelicula);
    }

    fclose(fPelicula);
    fclose(fRanking);

    return TODO_OK;
}

/**Puntero a funcion**/
int escribirAPeliculaTxtFijo(void* accion, const void* dato)
{
    FILE* txt = (FILE*)accion;
    const Pelicula* p = (const Pelicula*)dato;

    if(!txt || !p)
        return ERR_ARCH;

    fprintf(txt, "%-*s%-*s%03u%5.2f\n", TAM_TITULO, p->titulo, TAM_GENERO, p->genero, p->duracion, p->puntuacion);

    return TODO_OK;
}

int escribirPeliculaTxtVariable(void* accion, const void* dato)
{
    FILE* txt = (FILE*)accion;
    const Pelicula* p = (const Pelicula*)dato;

    if(!txt || !p)
        return ERR_ARCH;

    fprintf(txt, "%s|%s|%u|%f\n", p->titulo, p->genero, p->duracion, p->puntuacion);

    return TODO_OK;
}

int escribirPeliculaBin(void* accion, const void* dato)
{
    FILE* bin = (FILE*)accion;
    const Pelicula* p = (const Pelicula*)dato;

    if(!bin || !p)
        return ERR_ARCH;

    fwrite(p, sizeof(Pelicula), 1, bin);

    return TODO_OK;
}

int escribirPeliculaConPuntuacionMayorA(void* accion, const void* dato)
{
    FILE* bin = (FILE*)accion;
    const Pelicula* p = (const Pelicula*)dato;

    if(!bin || !p)
        return ERR_ARCH;

    fwrite(p, sizeof(Pelicula), 1, bin);

    return TODO_OK;
}

void mostrarPeliculaFijo(const void* dato)
{
    Pelicula* p = (Pelicula*)dato;

    printf("%-*s%-*s%03u%5.2f\n", TAM_TITULO, p->titulo, TAM_GENERO, p->genero, p->duracion, p->puntuacion);

}

void mostrarPeliculaVariable(const void* dato)
{
    Pelicula* p = (Pelicula*)dato;

    printf("%s|%s|%u|%f\n", p->titulo, p->genero, p->duracion, p->puntuacion);

}

int condicionMayorPuntuacion(const void* valorCondicion, const void* dato)
{
    Pelicula* p = (Pelicula*)dato;

    return(p->puntuacion > *(float*)valorCondicion);
}
