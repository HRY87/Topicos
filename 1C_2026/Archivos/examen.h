#ifndef EXAMEN_H_INCLUDED
#define EXAMEN_H_INCLUDED

#define TAM_NOTA        2
#define TAM_DNI         8
#define TAM_NOMBRE      25

#define RUTA_EXAMEN_BIN             "resultados/examen1.bin"
#define RUTA_EXAMEN_TXT_FIJO        "resultados/examen1Fijo.txt"
#define RUTA_EXAMEN_TXT_VARIABLE    "resultados/examen1Variable.txt"

#define RUTA_EXAMEN_APROBADOS_TXT       "resultados/aprobados.txt"
#define RUTA_EXAMEN_DESAPROBADOS_TXT    "resultados/desaprobados.txt"

#define ESTADO_APROBADO             'A'
#define ESTADO_FINAL                'F'
#define ESTADO_DESAPROBADO          'R'

typedef struct
{
    int dni;
    char nombre[TAM_NOMBRE];
    char estado;
    unsigned nota;
}Examen;

int generarArchivoTextoExamen(const char* rutaTxt);
int separarExamenesTexto(const char* rutaExamen, const char* rutaAprobado, const char* rutaDesaprobado, TxtABin trozar, Accion escribir);

/**Puntero a funcion**/
int escribirExamenTxtFijo(void* accion, const void* dato);
int escribirExamenTxtVariable(void* accion, const void* dato);

int trozarExamenTxtBinVariable(char* linea, void* reg);
int trozarExamenTxtBinFijo(char* linea, void* reg);

void mostrarExamenFijo(const void* dato);
void mostrarExamenVariable(const void* dato);
#endif // EXAMEN_H_INCLUDED
