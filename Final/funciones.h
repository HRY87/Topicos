#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdbool.h>

/**Etiquetas**/
#define TODO_OK                 0
#define ERR_ARCHIVO             -1
#define SIN_MEMORIA             -2
#define ERR_LINEA_LARGA         -3
/**Tamanio de cadenas**/
#define TAM_MATERIAL            6
#define TAM_PRIORIDAD           10
#define TAM_NOMBRE_IMPRESORA    31
#define TAM_NOMBRE_MODELO       41
#define TAM_LINEA               1024

/**Archivos**/
#define PATH_IMPRESORA          "impresora.dat"
#define PATH_MODELOS            "modelos.dat"
#define PATH_TRABAJOS           "trabajos.csv"
#define PATH_MATERIALES         "materiales.dat"
#define PATH_ASIGNACIONES       "asignaciones.txt"
#define PATH_RECHAZADOS         "rechazados.txt"
/**TDA Vector**/
#define TOPE_MAX                2
#define CANT_IMPRESORA          5
#define CANT_MODELO             6
#define CANT_MATERIAL           3
#define CANT_TRABAJO            10
/**TDA para impresoras.dat**/
typedef struct
{
    int idImpresora;
    char nombreImpresora[TAM_NOMBRE_IMPRESORA];
    int anchoMax; //mm
    int altoMax; //mm
    int profundidadMax; //mm
    char materialCargado[TAM_MATERIAL]; //PLA/ABS/PETG
    int trabajosAsignados; //Cantidad de trabajo asignados
    int tiempoAcumulado; //Minutos totales de impresion
}tImpresora;

/**TDA para modelos.dat**/
typedef struct
{
    int idModelo;
    char nombreModelo[TAM_NOMBRE_MODELO];
    int ancho; //mm
    int alto; //mm
    int profundidad; //mm
    char materialRequerido[TAM_MATERIAL]; //PLA/ABS/PETG
    int gramosNecesarios; //Cantidad de material en gramos
    int tiempoEstimado; //Minutos totales de impresion
}tModelo;

/**TDA para trabajos.csv**/
typedef struct
{
    int idTrabajo;
    int idModelo;
    int cantidad; //Cantidad de copias solicitadas
    char prioridad[TAM_PRIORIDAD];
}tTrabajo;

/**TDA para materiales.dat**/
typedef struct
{
    char tipoMaterial[TAM_MATERIAL];
    int stockDisponible;
    float costoGGramo; //Costo por gramo del material
}tMaterial;

/**Lleva la cuenta del consumo de cada material**/
typedef struct
{
    char tipoMaterial[TAM_MATERIAL];
    int consumo;
}tConsumo;

typedef struct
{
    void* datos;
    size_t ce;
    size_t tamElem;
    size_t tope;
}tVector;

typedef int(*Comparar)(const void* a, const void* b);
int compararImpresoras(const void* a, const void* b);
int compararModelos(const void* a, const void* b);
int compararTrabajos(const void* a, const void* b);
int compararMateriales(const void* a, const void* b);

typedef void(*Accion)(void* datos, void* datosAccion);
void accionEscribirRegistroBin(void* datos, void* accion);
void accionEscribirRegistoTxt(void* datos, void* accion);

void accionMostrarImpresora(void* dato, void* accion);
void accionMostrarModelos(void* dato, void* accion);
void accionMostrarTrabajo(void* dato, void* accion);
void accionMostrarMaterial(void* dato, void* accion);

void accionMostrarLineaTrabajo(void* dato, void* extra);

/**Funciones principales**/
int ejercicio1y2(const char* pathModelo, const char* pathTrabajo, tVector* vImp, tVector* vMat, tConsumo* consumos, size_t nConsumos);
int ejercicio3(tVector* vImp, tConsumo* consumos, size_t nConsumos);

/**Funciones auxiliares**/
int verificar_compatibilidad_dimensional_ALU(int ancho_modelo, int alto_modelo, int prof_modelo, int ancho_imp, int alto_imp, int prof_imp);
int compararMaterial(const void* impresora, const char* modelo);
int hayStockDisponible(int stockDisponible, int gramosNecesarios, int cantidad);
tImpresora* seleccionarImpresora(tVector* vImp, tModelo* mod, tMaterial* mat, int cantidad);
const char* motivoRechazo(tVector* vImp, tModelo* mod, tMaterial* mat, int cantidad);

/**Archivo**/
int ArchivoCrear(const char* path, void* datos, size_t ce, size_t tamElem, bool esBinario, Accion accion);
int archivoMostrarBin(const char* path, size_t tamElem, Accion accion);
int archivoMostrarTxt(const char* path, Accion accion);
int archivoCrearLotes();
int trabajoTxtVarABin(char* linea, tTrabajo* reg);
bool buscarModeloEnArchivo(FILE* fMod, int idBuscado, tModelo* modelo);
int archivoGuardarVector(const char* path, tVector* vec);
void mostrarTodosLosArchivos();

/**Funciones para TDA vector**/
int vectorCrear(tVector* vec, size_t tamElem);
void vectorDestruir(tVector* vec);
int vectorInsertarOrdenado(tVector* vec, void* dato, size_t tamElem, Comparar comparar);
int vectorRedimenzionar(tVector* vec, size_t nuevoTope);
void vectorRecorrer(tVector* vec, Accion accion);
int vectorInicializarConArchivoBin(const char* path, tVector* v, size_t tamElem, Comparar comparar);
void *vectorBuscarBinario(tVector *vec, const void *clave, Comparar comparar);
#endif // FUNCIONES_H_INCLUDED
