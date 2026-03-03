# Final - Tópicos de Programación 3635
## Granja de Impresoras 3D

---

## Índice
1. [Descripción del problema](#descripción-del-problema)
2. [Restricciones clave](#restricciones-clave)
3. [Estructuras de datos](#estructuras-de-datos)
4. [Arquitectura del proyecto](#arquitectura-del-proyecto)
5. [TDA Vector dinámico](#tda-vector-dinámico)
6. [Manejo de archivos](#manejo-de-archivos)
7. [Algoritmo de asignación](#algoritmo-de-asignación)
8. [Ejercicios](#ejercicios)
9. [Bugs encontrados y corregidos](#bugs-encontrados-y-corregidos)
10. [Decisiones de diseño](#decisiones-de-diseño)
11. [Compilación y ejecución](#compilación-y-ejecución)

---

## Descripción del problema

El sistema gestiona una granja de impresoras 3D que procesa trabajos de impresión para múltiples clientes. Dado un catálogo de modelos 3D, un inventario de materiales y una cola de trabajos, el sistema debe:

- Asignar cada trabajo a la impresora más adecuada
- Registrar trabajos rechazados con su motivo
- Generar un reporte de utilización al finalizar

---

## Restricciones clave

Estas restricciones del enunciado determinan toda la arquitectura:

| Archivo | Restricción | Consecuencia |
|---|---|---|
| `impresoras.dat` | Se puede cargar completo | Se carga en `tVector` en memoria |
| `materiales.dat` | Se puede cargar completo | Se carga en `tVector` en memoria |
| `modelos.dat` | **NO** se puede cargar completo | Se busca en el archivo por cada trabajo |
| `trabajos.csv` | Solo se puede leer **una vez** | Ejercicios 1 y 2 se procesan juntos en un único recorrido |

---

## Estructuras de datos

```c
typedef struct {
    int  idImpresora;
    char nombreImpresora[31];
    int  anchoMax, altoMax, profundidadMax;
    char materialCargado[6];
    int  trabajosAsignados, tiempoAcumulado;
} tImpresora;

typedef struct {
    int  idModelo;
    char nombreModelo[41];
    int  ancho, alto, profundidad;
    char materialRequerido[6];
    int  gramosNecesarios, tiempoEstimado;
} tModelo;

typedef struct {
    int  idTrabajo, idModelo, cantidad;
    char prioridad[10];
} tTrabajo;

typedef struct {
    char  tipoMaterial[6];
    int   stockDisponible;
    float costoGGramo;
} tMaterial;

/* Extra: para registrar consumo por material durante la sesión */
typedef struct {
    char tipoMaterial[6];
    int  consumo;
} tConsumo;
```

---

## Arquitectura del proyecto

```
Final/
├── main.c          → Punto de entrada, orquesta todo el flujo
├── funciones.h     → Declaraciones, defines, typedefs
└── funciones.c     → Implementación de todas las funciones
```

### Flujo general del `main`

```
archivoCrearLotes()
        ↓
vectorCrear() × 2
        ↓
vectorInicializarConArchivoBin() → carga impresoras y materiales ordenados
        ↓
Inicializar array consumos[]
        ↓
ejercicio1y2()  ←── lectura única de trabajos.csv
        ↓
ejercicio3()
        ↓
archivoGuardarVector() × 2  ← persiste cambios en .dat
        ↓
mostrarTodosLosArchivos()
        ↓
vectorDestruir() × 2
```

---

## TDA Vector dinámico

El vector genérico usa `void*` para almacenar cualquier tipo de dato.

```c
typedef struct {
    void*  datos;
    size_t ce;       /* cantidad de elementos actuales */
    size_t tamElem;  /* tamaño de cada elemento */
    size_t tope;     /* capacidad reservada */
} tVector;
```

### Operaciones principales

| Función | Descripción |
|---|---|
| `vectorCrear` | Reserva memoria inicial |
| `vectorDestruir` | Libera memoria |
| `vectorInsertarOrdenado` | Inserta manteniendo orden según comparador |
| `vectorRedimenzionar` | Duplica capacidad cuando está lleno |
| `vectorBuscarBinario` | Búsqueda O(log n) sobre vector ordenado |
| `vectorRecorrer` | Aplica una acción a cada elemento |
| `vectorInicializarConArchivoBin` | Carga archivo binario en el vector ordenado |

### Bug crítico en `vectorInsertarOrdenado`

El bug más importante del proyecto estaba aquí:

```c
/* ❌ BUGGY: cuando ce==0, (ce-1) con size_t da SIZE_MAX (underflow) */
void* ult = vec->datos + (vec->ce - 1) * vec->tamElem;

/* ✅ CORRECTO: guardar el cálculo de posición solo si hay elementos */
posIns = (char*)vec->datos;
if (vec->ce > 0)
{
    ult = (char*)vec->datos + (vec->ce - 1) * vec->tamElem;
    while (posIns <= ult && comparar(posIns, dato) < 0)
        posIns = (char*)posIns + vec->tamElem;
    for (k = ult; k >= posIns; k = (char*)k - vec->tamElem)
        memcpy((char*)k + vec->tamElem, k, vec->tamElem);
}
memcpy(posIns, dato, tamElem);
vec->ce++;
```

`size_t` es un entero **sin signo**. Cuando `ce == 0`, la operación `ce - 1` no da `-1` sino `SIZE_MAX` (~4 billones en 64 bits). El while entonces recorre memoria arbitraria corrompiendo todo el vector desde el primer `insert`.

**Por qué no se notaba en Debug:** el compilador sin optimizaciones y malloc en direcciones bajas hacía que el acceso fuera de rango "cayera" en memoria válida por casualidad. Con `-O2` en Release el crash era inmediato.

---

## Manejo de archivos

### Patrón puntero a función

Se usa `typedef void(*Accion)(void*, void*)` para pasar comportamiento a las funciones genéricas:

```c
/* Función genérica */
int archivoMostrarBin(const char* path, size_t tamElem, Accion accion);

/* Uso concreto */
archivoMostrarBin(PATH_IMPRESORA, sizeof(tImpresora), accionMostrarImpresora);
```

### Funciones de archivo

| Función | Descripción |
|---|---|
| `ArchivoCrear` | Crea binario o texto según flag `esBinario` |
| `archivoMostrarBin` | Lee registro a registro con buffer mínimo |
| `archivoMostrarTxt` | Lee línea a línea aplicando acción |
| `archivoGuardarVector` | Persiste el vector completo en binario |
| `buscarModeloEnArchivo` | Busca un modelo por ID sin cargar el archivo |

### Por qué `modelos.dat` no se carga en memoria

El enunciado lo prohíbe explícitamente. La solución es `buscarModeloEnArchivo` que hace `rewind()` y recorre el archivo por cada trabajo:

```c
bool buscarModeloEnArchivo(FILE* fMod, int idBuscado, tModelo* modelo)
{
    tModelo m;
    rewind(fMod);
    while (fread(&m, sizeof(tModelo), 1, fMod))
    {
        if (m.idModelo == idBuscado)
        {
            *modelo = m;
            return true;
        }
    }
    return false;
}
```

Es más lento que tenerlo en memoria, pero cumple la restricción.

### Parseo del CSV con `strrchr`

Se trabaja desde el final de la línea hacia el inicio, evitando recorridos extra:

```c
int trabajoTxtVarABin(char* linea, tTrabajo* reg)
{
    char* act = strchr(linea, '\n');   /* buscar fin de línea */
    if (!act) return ERR_LINEA_LARGA;
    *act = '\0';

    act = strrchr(linea, ';');         /* último campo: prioridad */
    strcpy(reg->prioridad, act + 1);
    *act = '\0';

    act = strrchr(linea, ';');         /* cantidad */
    sscanf(act + 1, "%d", &reg->cantidad);
    *act = '\0';

    act = strrchr(linea, ';');         /* idModelo */
    sscanf(act + 1, "%d", &reg->idModelo);
    *act = '\0';

    sscanf(linea, "%d", &reg->idTrabajo); /* idTrabajo: lo que queda */
    return TODO_OK;
}
```

---

## Algoritmo de asignación

Para cada trabajo se verifican tres condiciones en orden:

### 1. El modelo existe
```c
if (!buscarModeloEnArchivo(fMod, trab.idModelo, &mod))
    → rechazar con MODELO_NO_ENCONTRADO
```

### 2. Buscar material compatible
```c
mat = vectorBuscarBinario(vMat, mod.materialRequerido, compararMateriales);
```
El vector de materiales está ordenado alfabéticamente (ABS, PETG, PLA), lo que permite búsqueda binaria O(log n).

### 3. Seleccionar la mejor impresora
```c
tImpresora* seleccionarImpresora(tVector* vImp, tModelo* mod, tMaterial* mat, int cantidad)
```

Recorre todas las impresoras verificando:
- **Dimensiones:** `modelo <= impresora` en los tres ejes
- **Material:** `materialCargado == materialRequerido`
- **Stock:** `stockDisponible >= gramosNecesarios * cantidad`

**Criterio de selección:** menor `tiempoAcumulado`. Desempate por menor `idImpresora`.

### 4. Actualizar estado
```c
imp->trabajosAsignados++;
imp->tiempoAcumulado += mod.tiempoEstimado * trab.cantidad;
mat->stockDisponible -= mod.gramosNecesarios * trab.cantidad;
consumos[i].consumo  += mod.gramosNecesarios * trab.cantidad;
```

### Motivo de rechazo
```c
const char* motivoRechazo(tVector* vImp, tModelo* mod, tMaterial* mat, int cantidad)
```
Recorre impresoras: si alguna pasa la prueba dimensional → `MATERIAL_INSUFICIENTE`. Si ninguna la pasa → `DIMENSIONES_EXCEDIDAS`.

---

## Ejercicios

### Ejercicio 1 — `asignaciones.txt`
Trabajos asignados exitosamente:
```
Trabajo: 1 - Modelo: Soporte Tablet - Impresora: Prusa MK3 - Tiempo: 240 min
```

### Ejercicio 2 — `rechazados.txt`
Trabajos rechazados con motivo:
```
8 - MODELO_NO_ENCONTRADO
```

> **Nota:** Ejercicios 1 y 2 se procesan en la **misma función** `ejercicio1y2()` en un único recorrido de `trabajos.csv`, respetando la restricción de lectura única.

### Ejercicio 3 — Reporte de utilización
Muestra en pantalla:
- Impresora con mayor tiempo acumulado
- Material más consumido (usando array `tConsumo[]`)
- Distribución completa de trabajos por impresora
- Impresora con más y menos trabajos (desempate por menor ID)

---

## Bugs encontrados y corregidos

### Bug 1 — Underflow en `vectorInsertarOrdenado` (CRÍTICO)
**Síntoma:** Solo asignaba trabajos PLA, ABS y PETG siempre rechazados.
**Causa:** `size_t` sin signo con `ce=0` daba `SIZE_MAX` al restar 1.
**Fix:** Envolver el desplazamiento en `if (vec->ce > 0)`.

### Bug 2 — Cast incorrecto en aritmética de punteros (CRÍTICO)
**Síntoma:** Solo leía correctamente el elemento en índice 0.
**Causa:** El cast a `tImpresora*` ocurría antes de la suma, multiplicando el offset dos veces.
```c
/* ❌ */ imp = (tImpresora*)vImp->datos + (i * vImp->tamElem);
/* ✅ */ imp = (tImpresora*)((char*)vImp->datos + (i * vImp->tamElem));
```

## Decisiones de diseño

### ¿Por qué `ejercicio1y2` están juntos?
`trabajos.csv` solo puede leerse una vez. Ambos archivos de salida (`asignaciones.txt` y `rechazados.txt`) se generan en el mismo recorrido.

### ¿Por qué los vectores se cargan ordenados?
Para poder usar `vectorBuscarBinario` (O(log n)) en lugar de búsqueda lineal (O(n)). Los materiales se ordenan por `tipoMaterial` y las impresoras por `idImpresora`.

### ¿Por qué `tConsumo[]` separado de `tMaterial`?
El stock en `tMaterial` se va descontando durante el proceso. Al final no se puede saber cuánto se consumió a partir del stock restante sin conocer el inicial. `tConsumo` acumula el consumo durante la sesión, independientemente del stock.

### ¿Por qué no se carga `modelos.dat` en memoria?
El enunciado lo prohíbe explícitamente: *"El archivo modelos.dat es considerable y no puede cargarse completamente en memoria."*

### Aritmética de punteros vs funciones de biblioteca
El enunciado exige usar aritmética de punteros para vectores y cadenas. Se permite `string.h` para `strcmp`, `strcpy`, `sscanf`, `strchr`, `strrchr`.

---

## Compilación y ejecución

### En Code::Blocks
1. Abrir `Final.cbp`
2. Build → Build (F9) en modo **Release**
3. Ejecutar desde la carpeta del proyecto (donde están los `.dat`)

### En línea de comandos
```bash
gcc -Wall -Wextra -ansi -pedantic main.c funciones.c -o Final
./Final
```

### Archivos generados al ejecutar
```
asignaciones.txt        → trabajos asignados exitosamente
rechazados.txt          → trabajos rechazados con motivo
impresora.dat           → actualizado con trabajos y tiempos acumulados
materiales.dat          → actualizado con stock descontado
```
