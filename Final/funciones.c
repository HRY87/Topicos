#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "funciones.h"

/**Funciones principales**/
int ejercicio1y2(const char* pathModelo, const char* pathTrabajo, tVector* vImp, tVector* vMat, tConsumo* consumos, size_t nConsumos)
{
    FILE *fMod, *fTrab, *fAsig, *fRech;
    char linea[TAM_LINEA];
    tTrabajo trab;
    tModelo mod;
    tMaterial* mat;
    tImpresora* imp;
    int total = 0, nAsig = 0, nRech = 0;

    fMod = fopen(pathModelo, "rb");
    fTrab = fopen(pathTrabajo, "rt");
    fAsig = fopen(PATH_ASIGNACIONES, "wt");
    fRech = fopen(PATH_RECHAZADOS, "wt");

    if(!fMod || !fTrab || !fAsig || !fRech)
    {
        fclose(fMod);
        fclose(fTrab);
        fclose(fAsig);
        fclose(fRech);

        return ERR_ARCHIVO;
    }

    while(fgets(linea, TAM_LINEA, fTrab))
    {
        if(trabajoTxtVarABin(linea, &trab) != TODO_OK)
            continue;

        total++;

        /**1- Verificar que el modelo existe (sin cargarlo en memoria)**/
        if(!buscarModeloEnArchivo(fMod, trab.idModelo, &mod))
        {
            nRech++;

            if(fRech)
                fprintf(fRech, "%d - MODELO_NO_ENCONTRADO\n", trab.idTrabajo);

            continue;
        }

        /**2- Buscar material con busqueda binaria**/
        mat = (tMaterial*)vectorBuscarBinario(vMat, mod.materialRequerido, compararMateriales);

        /**3- Seleccionar impresora**/
        imp = mat ? seleccionarImpresora(vImp, &mod, mat, trab.cantidad) : NULL;

        if(!imp)
        {
            nRech++;

            if(fRech)
            {
                fprintf(fRech, "%d - %s\n", trab.idTrabajo, motivoRechazo(vImp, &mod, mat, trab.cantidad));
            }

            continue;
        }

        /**4- Actualizar impresora y stock**/
        imp->trabajosAsignados++;
        imp->tiempoAcumulado += mod.tiempoEstimado * trab.cantidad;
        mat->stockDisponible -= mod.gramosNecesarios * trab.cantidad;

        /**Registrar consumo para el ejercicio 3**/
        for(size_t i = 0; i < nConsumos; i++)
        {
            if(strcmp((consumos + i)->tipoMaterial, mod.materialRequerido) == 0)
            {
                (consumos + i)->consumo += mod.gramosNecesarios + trab.cantidad;
                break;
            }
        }

        nAsig++;

        fprintf(fAsig,
                "Trabajo: %d - Modelo: %s - Impresora: %s - Tiempo: %d min\n",
                trab.idTrabajo, mod.nombreModelo,
                imp->nombreImpresora,
                mod.tiempoEstimado * trab.cantidad);
    }

    fclose(fMod);
    fclose(fTrab);
    fclose(fAsig);
    fclose(fRech);

    printf("\nPROCESO DE ASIGNACION COMPLETADO\n");
    printf("Total de trabajos procesados: %d\n", total);
    printf("Trabajos asignados: %d\n",            nAsig);
    printf("Trabajos rechazados: %d\n",            nRech);

    return TODO_OK;
}

int ejercicio3(tVector* vImp, tConsumo* consumos, size_t nConsumos)
{
    tImpresora* imp;
    tImpresora* mayorUtil = NULL;
    tImpresora* masTrabajos = NULL;
    tImpresora* menosTrabajos = NULL;
    tConsumo* matDemandado = NULL;
    int totalUsadas = 0;
    size_t i;

    for(i = 0; i < vImp->ce; i++)
    {
        imp = (tImpresora*)(vImp->datos + (i * vImp->tamElem));

              if(imp->trabajosAsignados == 0)
                  continue;

        totalUsadas++;

        if (!mayorUtil || imp->tiempoAcumulado > mayorUtil->tiempoAcumulado ||
                (imp->tiempoAcumulado == mayorUtil->tiempoAcumulado &&
                 imp->idImpresora    <  mayorUtil->idImpresora))
        {
            mayorUtil = imp;

        }


        if (!masTrabajos || imp->trabajosAsignados > masTrabajos->trabajosAsignados ||
                (imp->trabajosAsignados == masTrabajos->trabajosAsignados &&
                 imp->idImpresora       <  masTrabajos->idImpresora))
        {
            masTrabajos = imp;
        }

        if (!menosTrabajos ||
                imp->trabajosAsignados < menosTrabajos->trabajosAsignados ||
                (imp->trabajosAsignados == menosTrabajos->trabajosAsignados &&
                 imp->idImpresora       <  menosTrabajos->idImpresora))
        {
            menosTrabajos = imp;
        }
    }

    for(i = 0; i < nConsumos; i++)
    {
        if (!matDemandado || (consumos + i)->consumo > matDemandado->consumo)
            matDemandado = consumos + i;
    }

    printf("\nREPORTE DE UTILIZACION:\n");
    if (mayorUtil)
    {
        printf("Impresora con mayor utilizacion: %s (ID: %d)\n",
               mayorUtil->nombreImpresora, mayorUtil->idImpresora);
        printf("Tiempo total acumulado: %d minutos\n", mayorUtil->tiempoAcumulado);
    }

    if (matDemandado)
    {
        printf("Material mas demandado: %s (%d gramos consumidos)\n",
               matDemandado->tipoMaterial, matDemandado->consumo);
    }

    printf("\nDISTRIBUCION DE TRABAJOS:\n");

    for (i = 0; i < vImp->ce; i++)
    {
        imp = (tImpresora *)((char *)vImp->datos + i * vImp->tamElem);

        if (imp->trabajosAsignados == 0)
            continue;

        printf("Impresora %d (%s): %d trabajo%s - Tiempo acum: %d min\n",
               imp->idImpresora, imp->nombreImpresora,
               imp->trabajosAsignados,
               imp->trabajosAsignados == 1 ? "" : "s",
               imp->tiempoAcumulado);
    }

    printf("Total impresoras utilizadas: %d\n", totalUsadas);

    if (masTrabajos)
    {

        printf("Impresora con mas trabajos: %s (%d trabajo%s)\n",
               masTrabajos->nombreImpresora, masTrabajos->trabajosAsignados,
               masTrabajos->trabajosAsignados == 1 ? "" : "s");
    }
    if (menosTrabajos)
    {

        printf("Impresora con menos trabajos: %s (%d trabajo%s)\n",
               menosTrabajos->nombreImpresora, menosTrabajos->trabajosAsignados,
               menosTrabajos->trabajosAsignados == 1 ? "" : "s");
    }

    return TODO_OK;
}

/**Funciones auxiliares**/

int verificar_compatibilidad_dimensional_ALU(int ancho_modelo, int alto_modelo, int prof_modelo, int ancho_imp, int alto_imp, int prof_imp)
{
    return(ancho_modelo <= ancho_imp && alto_modelo <= alto_imp && prof_modelo <= prof_imp);
}

int compararMaterial(const void* impresora, const char* modelo)
{
    tImpresora* i = (tImpresora*)impresora;
    tModelo* m = (tModelo*)modelo;

    return(strcmp(i->materialCargado, m->materialRequerido));
}

int hayStockDisponible(int stockDisponible, int gramosNecesarios, int cantidad)
{
    return(stockDisponible >= (gramosNecesarios * cantidad));
}


tImpresora* seleccionarImpresora(tVector* vImp, tModelo* mod, tMaterial* mat, int cantidad)
{
    tImpresora* mejor = NULL;
    tImpresora* imp = NULL;

    for(size_t i = 0; i < vImp->ce; i++)
    {
        imp = (tImpresora*)vImp->datos + (i * vImp->tamElem);

        if(!verificar_compatibilidad_dimensional_ALU(mod->ancho, mod->alto, mod->profundidad, imp->anchoMax, imp->altoMax, imp->profundidadMax))
            continue;

        if(strcmp(imp->materialCargado, mod->materialRequerido) != 0)
            continue;

        if(!hayStockDisponible(mat->stockDisponible, mod->gramosNecesarios, cantidad))
            continue;

        //Condicion de mejor impresora y caso de desempate
        if(!mejor || imp->tiempoAcumulado < mejor->tiempoAcumulado ||
                (imp->tiempoAcumulado == mejor->tiempoAcumulado && imp->idImpresora < mejor->idImpresora))
        {
            mejor = imp;
        }
    }

    return mejor;
}

const char* motivoRechazo(tVector* vImp, tModelo* mod, tMaterial* mat, int cantidad)
{
    tImpresora* imp;

    for(size_t i = 0; i < vImp->ce; i++)
    {
        imp = (tImpresora*)(vImp->datos + (i * vImp->tamElem));

        if (verificar_compatibilidad_dimensional_ALU(
                    mod->ancho, mod->alto, mod->profundidad,
                    imp->anchoMax, imp->altoMax, imp->profundidadMax))
        {
            /* Al menos una impresora pasa dimensiones -> fallo material/stock */
            (void)mat;
            (void)cantidad;
            return "MATERIAL_INSUFICIENTE";
        }
    }

    return "DIMENSIONES_EXCEDIDADAS";
}
/**Archivos**/
int ArchivoCrear(const char* path, void* datos, size_t ce, size_t tamElem, bool esBinario, Accion accion)
{
    FILE* pf = fopen(path, esBinario ? "wb" : "wt");

    if(!pf)
        return ERR_ARCHIVO;

    if(esBinario)
    {
        fwrite(datos, tamElem, ce, pf);
    }
    else
    {
        for(size_t i = 0; i < ce; i++)
        {
            accion(datos + (i * tamElem), pf);
        }
    }

    fclose(pf);
    return TODO_OK;
}

int archivoMostrarBin(const char* path, size_t tamElem, Accion accion)
{
    FILE* pf = fopen(path, "rb");

    if(!pf)
        return ERR_ARCHIVO;

    void* buffer = malloc(tamElem);

    if(!buffer)
    {
        fclose(pf);
        return SIN_MEMORIA;
    }

    while(fread(buffer, tamElem, 1, pf))
    {
        accion(buffer, NULL);
    }

    free(buffer);
    fclose(pf);

    return TODO_OK;
}

int archivoMostrarTxt(const char* path, Accion accion)
{
    FILE* pf = fopen(path, "rt");

    if(!pf)
        return ERR_ARCHIVO;

    char linea[TAM_LINEA];

    while(fgets(linea, sizeof(linea), pf))
    {
        accion(linea, NULL);
    }

    fclose(pf);

    return TODO_OK;
}

int archivoCrearLotes()
{
    tImpresora vImpresora[CANT_IMPRESORA] =
    {
        {1, "Prusa MK3", 250, 210, 210, "PLA", 0,0},
        {2, "Ender 3 Pro", 220, 250, 220, "PLA", 0,0},
        {3, "CR-10 V3", 300, 400, 300, "ABS", 0,0},
        {4, "Artillery X1", 300, 300, 300, "PETG", 0,0},
        {5, "Anycubic Mega", 210, 205, 210, "PLA", 0,0}
    };

    tModelo vModelo[CANT_MODELO] =
    {
        {101, "Soporte Tablet", 150, 80, 100, "PLA", 45, 120},
        {102, "Organizador Cables", 200, 50, 80, "PLA", 65, 180},
        {103, "Carcasa Electronica", 180, 120, 90, "ABS", 120, 240},
        {104, "Maceta Decorativa", 140, 150, 140, "PLA", 80, 200},
        {105, "Engranaje Mecanico", 100, 60, 100, "PETG", 55, 150},
        {106, "Pieza Industrial", 280, 350, 280, "ABS", 450, 600}
    };

    tMaterial vMaterial[CANT_MATERIAL] =
    {
        {"PLA", 5000, 0.05},
        {"ABS", 3000, 0.06},
        {"PETG", 2000, 0.07}
    };

    tTrabajo vTrabajo[CANT_TRABAJO] =
    {
        {1, 101, 2, "ALTA"},
        {2, 102, 1, "MEDIA"},
        {3, 103, 3, "ALTA"},
        {4, 104, 2, "BAJA"},
        {5, 105, 1, "ALTA"},
        {6, 106, 1, "MEDIA"},
        {7, 101, 5, "BAJA"},
        {8, 107, 1, "ALTA"},
        {9, 103, 1, "BAJA"},
        {10, 102, 3, "MEDIA"}
    };

    if(!ArchivoCrear(PATH_IMPRESORA, vImpresora, CANT_IMPRESORA, sizeof(tImpresora), true, accionEscribirRegistroBin))
    {
        archivoMostrarBin(PATH_IMPRESORA, sizeof(tImpresora), accionMostrarImpresora);
    }

    if(!ArchivoCrear(PATH_MODELOS, vModelo, CANT_MODELO, sizeof(tModelo), true, accionEscribirRegistroBin))
    {
        puts("");
        archivoMostrarBin(PATH_MODELOS, sizeof(tModelo), accionMostrarModelos);
    }

    if(!ArchivoCrear(PATH_MATERIALES, vMaterial, CANT_MATERIAL, sizeof(tMaterial), true, accionEscribirRegistroBin))
    {
        puts("");
        archivoMostrarBin(PATH_MATERIALES, sizeof(tMaterial), accionMostrarMaterial);
    }

    if(!ArchivoCrear(PATH_TRABAJOS, vTrabajo, CANT_TRABAJO, sizeof(tTrabajo), false, accionEscribirRegistoTxt))
    {
        puts("\nTODO OK");
    }

    return TODO_OK;
}

int trabajoTxtVarABin(char* linea, tTrabajo* reg)
{

    char* act = strchr(linea, '\n');

    if(!act)
    {
        return ERR_LINEA_LARGA;
    }

    *act = '\0';
    act = strrchr(linea, ';');
    strcpy(reg->prioridad, act + 1);

    *act = '\0';
    act = strrchr(linea, ';');
    sscanf(act + 1, "%d", &reg->cantidad);

    *act = '\0';
    act = strrchr(linea, ';');
    sscanf(act + 1, "%d", &reg->idModelo);

    *act = '\0';
    sscanf(linea, "%d", &reg->idTrabajo);

    return TODO_OK;
}

/**No se puede cargar el archivo en memoria, lectura desde el archivo, es mas lento pero cumple**/
bool buscarModeloEnArchivo(FILE* fMod, int idBuscado, tModelo* modelo)
{
    tModelo m;

    rewind(fMod);

    while(fread(&m, sizeof(tModelo), 1, fMod))
    {
        if(m.idModelo == idBuscado)
        {
            *modelo = m;
            return true;
        }
    }

    return false;
}

int archivoGuardarVector(const char* path, tVector* vec)
{
    FILE* bin = fopen(path, "wb");

    if(!bin)
        return ERR_ARCHIVO;

    for(size_t i = 0; i < vec->ce; i++)
    {
        fwrite(vec->datos + (i* vec->tamElem), vec->tamElem, 1, bin);
    }

    fclose(bin);
    return TODO_OK;
}
/**Puntero a funcion**/
int compararImpresoras(const void* a, const void* b)
{
    tImpresora* ia = (tImpresora*)a;
    tImpresora* ib = (tImpresora*)b;

    return(ia->idImpresora - ib->idImpresora);
}

int compararModelos(const void* a, const void* b)
{
    tModelo* ma = (tModelo*)a;
    tModelo* mb = (tModelo*)b;

    return(ma->idModelo - mb->idModelo);
}

int compararTrabajos(const void* a, const void* b)
{
    tTrabajo* ta = (tTrabajo*)a;
    tTrabajo* tb = (tTrabajo*)b;

    return(ta->idTrabajo - tb->idTrabajo);
}

int compararMateriales(const void* a, const void* b)
{
    tMaterial* ma = (tMaterial*)a;
    tMaterial* mb = (tMaterial*)b;

    return(strcmpi(ma->tipoMaterial, mb->tipoMaterial));
}

void accionEscribirRegistroBin(void* datos, void* accion)
{
    tVector* v = (tVector*)datos;
    FILE* pf = (FILE*)accion;

    fwrite(v->datos, v->tamElem, v->ce, pf);
}

void accionEscribirRegistoTxt(void* datos, void* accion)
{
    tTrabajo* v = (tTrabajo*)datos;
    FILE* pf = (FILE*)accion;

    fprintf(pf, "%d;%d;%d;%s\n",
            v->idTrabajo, v->idModelo, v->cantidad, v->prioridad);
}

void accionMostrarImpresora(void* dato, void* accion)
{
    tImpresora* i = (tImpresora*)dato;

    printf("%d\t%-31s\t%d\t%d\t%d\t%-4s\t%d\t%d\n", i->idImpresora, i->nombreImpresora, i->altoMax, i->anchoMax, i->profundidadMax,
           i->materialCargado, i->trabajosAsignados, i->tiempoAcumulado);
}

void accionMostrarModelos(void* dato, void* accion)
{
    tModelo* m = (tModelo*)dato;

    printf("%d\t%-31s\t%d\t%d\t%d\t%-4s\t%d\t%d\n", m->idModelo, m->nombreModelo, m->alto, m->ancho, m->profundidad,
           m->materialRequerido, m->gramosNecesarios, m->tiempoEstimado);
}

void accionMostrarTrabajo(void* dato, void* accion)
{
    tTrabajo* t = (tTrabajo*)dato;

    printf("%d;%d;%d;%s\n", t->idTrabajo, t->idModelo, t->cantidad, t->prioridad);
}

void accionMostrarMaterial(void* dato, void* accion)
{
    tMaterial* m = (tMaterial*)dato;

    printf("%-4s\t%d\t%.2f\n", m->tipoMaterial, m->stockDisponible, m->costoGGramo);
}


/**Funciones para TDA vector**/
int vectorCrear(tVector* vec, size_t tamElem)
{
    vec->ce = 0;
    vec->tope =  TOPE_MAX;
    vec->tamElem = tamElem;

    vec->datos = malloc(vec->tope * vec->tamElem);

    if(!vec->datos)
        return SIN_MEMORIA;


    return TODO_OK;
}

void vectorDestruir(tVector* vec)
{
    free(vec->datos);

    vec->datos = NULL;
    vec->ce = 0;
    vec->tamElem = 0;
    vec->tope = 0;
}

int vectorInsertarOrdenado(tVector* vec, void* dato, size_t tamElem, Comparar comparar)
{
    if(vec->ce == vec->tope)
    {
        if(!vectorRedimenzionar(vec, vec->tope * 2))
        {
            return SIN_MEMORIA;
        }
    }

    void* posIns = vec->datos;
    void* ult = vec->datos + (vec->ce - 1) * vec->tamElem;

    while(posIns <= ult && comparar(posIns, dato) < 0)
        posIns += vec->tamElem;


    for(void* i = ult; i >= posIns; i -= vec->tamElem)
    {
        memcpy(i + vec->tamElem, i, vec->tamElem);
    }

    memcpy(posIns, dato, tamElem);

    vec->ce++;

    return TODO_OK;
}

int vectorRedimenzionar(tVector* vec, size_t nuevoTope)
{
    void* nue = realloc(vec->datos, nuevoTope * vec->tamElem);

    if(!nue)
        return SIN_MEMORIA;

    vec->datos = nue;
    vec->tope = nuevoTope;

    return TODO_OK;
}

void vectorRecorrer(tVector* vec, Accion accion)
{
    for(size_t i = 0; i < vec->ce; i++)
    {
        accion(vec->datos + (i * vec->tamElem), NULL);
    }
}

int vectorInicializarConArchivoBin(const char* path, tVector* v, size_t tamElem, Comparar comparar)
{
    FILE* bin = fopen(path, "rb");

    if(!bin)
        return ERR_ARCHIVO;

    void* reg = malloc(tamElem);

    while(fread(reg, tamElem, 1, bin))
    {
        vectorInsertarOrdenado(v, reg, tamElem, comparar);
    }

    fclose(bin);
    free(reg);

    return TODO_OK;
}
void *vectorBuscarBinario(tVector *vec, const void *clave, Comparar comparar)
{
    size_t izq = 0;
    size_t der = vec->ce;
    size_t mid;
    int    comp;

    while (izq < der)
    {
        mid = izq + (der - izq) / 2;
        comp = comparar((char *)vec->datos + mid * vec->tamElem, clave);
        if(comp == 0)
        {
            return (char *)vec->datos + mid * vec->tamElem;
        }
        else
        {
            comp <  0 ? (izq = mid + 1) : (der = mid);
        }
    }
    return NULL;
}
