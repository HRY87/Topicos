#include <stdio.h>
#include "archivo.h"
#include "agenda.h"
#include "examen.h"
#include "pelicula.h"

int main()
{
//    /**Prueba ejercicio 1**/
//    if(generarArchivoTextoAgenda(RUTA_AGENDA_TXT_FIJO) == TODO_OK)
//        printf("Se creo el archivo %s\n", RUTA_AGENDA_TXT_FIJO);
//
//    puts("");
//
//    /**Prueba ejercicio 2**/
//    if(convertirArchivoTxtABin(RUTA_AGENDA_TXT_FIJO, RUTA_AGENDA_BIN, sizeof(Agenda), trozarAgendaTxtBinFijo) == TODO_OK)
//    {
//        puts("---Agenda.bin---");
//        mostrarArchivoBinario(RUTA_AGENDA_BIN, sizeof(Agenda), mostrarAgendaFijo);
//    }
//
//    puts("");
//
//    /**Prueba ejercicio 3**/
//        if(generarArchivoTextoExamen(RUTA_EXAMEN_TXT_VARIABLE) == TODO_OK)
//            printf("Se creo el archivo %s\n", RUTA_EXAMEN_TXT_VARIABLE);
//
//    puts("");
//
//    /**Prueba ejercicio 4**/
//    if(separarExamenesTexto(RUTA_EXAMEN_TXT_VARIABLE, RUTA_EXAMEN_APROBADOS_TXT, RUTA_EXAMEN_DESAPROBADOS_TXT,
//                            trozarExamenTxtBinVariable, escribirExamenTxtVariable) == TODO_OK)
//    {
//        printf("Se creo el archivo %s\n", RUTA_EXAMEN_APROBADOS_TXT);
//        printf("Se creo el archivo %s\n", RUTA_EXAMEN_DESAPROBADOS_TXT);
//    }
//
//    puts("");

    float puntuacion = 9.0;

    /**Prueba ejercicio 5**/
    if(generarArchivoBinarioPelicula(RUTA_PELICULA_BIN) == TODO_OK)
    {
        puts("----Pelicula.bin----");
        mostrarArchivoBinario(RUTA_PELICULA_BIN, sizeof(Pelicula), mostrarPeliculaVariable);
        puts("");

        if(generarArchivoRankingBinario(RUTA_PELICULA_BIN, RUTA_RANKING_BIN, escribirPeliculaBin, condicionMayorPuntuacion, &puntuacion) == TODO_OK)
        {
            puts("----Ranking.bin----");
            mostrarArchivoBinario(RUTA_RANKING_BIN, sizeof(Pelicula), mostrarPeliculaVariable);
        }

    }
    return 0;
}



