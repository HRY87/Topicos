#include <stdio.h>
#include <string.h>
#include "agenda.h"
#include "archivo.h"

int generarArchivoTextoAgenda(const char* rutaTxt)
{
    Agenda vAgenda[TAM_LOTE] =
    {
        {"Juan Perez", 00000001, "juan@gmail.com"},
        {"Maria Lopez", 00000002, "maria@hotmail.com"},
        {"Carlos Gomez", 00000003, "carlos@yahoo.com"},
        {"Ana Martinez", 00000004, "ana@outlook.com"},
        {"Lucia Fernandez", 00000005, "lucia@gmail.com"}
    };

    return crearArchivoTexto(rutaTxt, vAgenda, TAM_LOTE, sizeof(Agenda), escribirAgendaTxtFijo);
}

/**Puntero a funcion**/
int escribirAgendaTxtFijo(void* accion, const void* dato)
{
    FILE* txt = (FILE*)accion;
    const Agenda* a = (const Agenda*)dato;

    if(!txt || !a)
        return ERR_ARCH;

    fprintf(txt, "%-20s%08d%-30s\n", a->contacto, a->telefono, a->mail);

    return TODO_OK;
}

int escribirAgendaTxtVariable(void* accion, const void* dato)
{
    FILE* txt = (FILE*)accion;
    const Agenda* a = (const Agenda*)dato;

    if(!txt || !a)
        return ERR_ARCH;

    fprintf(txt, "|%s|%d|%s\n", a->contacto, a->telefono, a->mail);

    return TODO_OK;
}

int trozarAgendaTxtBinVariable(char* linea, void* reg)
{
    Agenda* a = (Agenda*)reg;

    char* act = strchr(linea, '\n');

    if(!act)
    {
        return ERR_LINEA;
    }

    *act = '\0';
    act = strrchr(linea, '|');
    strcpy(a->mail, act + 1);

    *act = '\0';
    act = strrchr(linea, '|');
    sscanf(act + 1, "%d", &a->telefono);

    *act = '\0';
    strcpy(a->contacto, linea);

    return TODO_OK;
}

int trozarAgendaTxtBinFijo(char* linea, void* reg)
{
    Agenda* a = (Agenda*)reg;

    char* act = strchr(linea, '\n');

    if(!act)
    {
        return ERR_LINEA;
    }

    *act = '\0';
    act -= TAM_MAIL;
    strcpy(a->mail, act);

    *act = '\0';
    act -= TAM_TELEFONO + 1; //POR QUEEEEEEEEEE????
    sscanf(act, "%d", &a->telefono);

    *act = '\0';
    strcpy(a->contacto, linea);

    return TODO_OK;
}

void mostrarAgendaFijo(const void* dato)
{
    Agenda* a = (Agenda*)dato;

    printf("%-*s%08d%-*s\n", TAM_CONTACTO, a->contacto, a->telefono, TAM_MAIL, a->mail);

}

void mostrarAgendaVariable(const void* dato)
{
    Agenda* a = (Agenda*)dato;

    printf("%s|%d|%s\n", a->contacto, a->telefono, a->mail);

}
