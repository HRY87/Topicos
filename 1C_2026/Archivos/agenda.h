#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#define TAM_CONTACTO    20
#define TAM_TELEFONO    8
#define TAM_MAIL        30

#define RUTA_AGENDA_BIN             "resultados/agenda.bin"
#define RUTA_AGENDA_TXT_FIJO        "resultados/agendaFijo.txt"
#define RUTA_AGENDA_TXT_VARIABLE    "resultados/agendaVariable.txt"


typedef struct
{
    char contacto[TAM_CONTACTO];
    int telefono;
    char mail[TAM_MAIL];
}Agenda;


int generarArchivoTextoAgenda(const char* rutaTxt);

/**Puntero a funcion**/
int escribirAgendaTxtFijo(void* accion, const void* dato);
int escribirExamenTxtVariable(void* accion, const void* dato);

int trozarAgendaTxtBinVariable(char* linea, void* reg);
int trozarAgendaTxtBinFijo(char* linea, void* reg);

void mostrarAgendaFijo(const void* dato);
void mostrarAgendaVariable(const void* dato);
#endif // AGENDA_H_INCLUDED
