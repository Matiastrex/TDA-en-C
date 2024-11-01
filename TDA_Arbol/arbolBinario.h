#ifndef ARBOLBINARIO_H_INCLUDED
#define ARBOLBINARIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(x,y) ((x)<(y)?(x):(y))
/** ***************************************************************************************************************************************
 **                                     ARBOLES
 ** + Por cantidad de nodos, pueden clasificarse en dos tipos:
 **      |-> N-Arios: Cada nodo del árbol puede tener de 0 a N hijos
 **      |-> Binarios: Cada nodo del árbol puede tener de 0 a 2 hijos (Las funciones trabajan este tipo de árboles
 ** + Propiedades:
 **      |-> Nivel: Cantidad de saltos que se tienen que dar para llegar a un nodo específico
 **      |-> Altura: Cantidad de niveles
 ** + Tipos de recorridos al arbol (I = SubArbol izquierdo, R = Raiz, D = SubArbol derecho):
 **      |-> Recorrido en orden: I R D
 **      |-> Recorrido en preorden (Polaca): R I D
 **      |-> Recorrido en posorden (Polaca inversa): I D R
 ** + Arbol completo:
 **      |-> Tienen exactamente la cantidad de nodos correspondiente con su altura. Son los más eficientes en las búsquedas.
 **      |-> Cantidad de nodos = 2^altura-1
 ** + Arbol balanceado:
 **      |-> Es aquel que tiene aproximadamente la misma cantidad de nodos en el subarbol izquierdo y el subarbol derecho.
 ** + Arbol balanceado AVL (Adelson-Velskii-Landis):
 **      |-> Puesto que obtener un árbol balanceado a partir de uno que no lo está es muy complejo en cómputo, hay un algoritmo que permite
 **          obtener uno más fácil de obtener que preserva parcialmente la eficiencia en las búsquedas.
 **      |-> La condicion de dicho arbol es que la diferencia de altura entre el subarbol izquierdo  y el subarbol derecho nunca puede ser
 **          mayor a 1.
 ** ***************************************************************************************************************************************/
typedef struct sNodo{
    struct sNodo* izq;
    unsigned tamInfo;
    void* info;
    struct sNodo* der;
}tNodo;
typedef tNodo* tArbol;

void crearArbol(tArbol* arbol);
void recorrerArbolPreOrden(const tArbol* arbol,void accion(void*a, void*b));
void recorrerArbolInOrden(const tArbol* arbol,void accion(void*a, void*b));
void recorrerArbolPosOrden(const tArbol* arbol,void accion(void*a, void*b));
int insertarEnOrdenEnArbolRecursivo(tArbol* arbol, void* dato, unsigned tamDato, int cmp(void*a,void*b));
int insertarEnOrdenEnArbolIterativo(tArbol* arbol, void* dato, unsigned tamDato, int cmp(void*a,void*b));

int cargarArbolConDatosOrdenados(tArbol* arbol, void* fuenteDatos, int leer (void** dato, void* fuenteDatos, unsigned cantReg, void* params), int li, int ls,void* params);
int cargarArchivoBinarioOrdenadoEnArbol(tArbol* arbol, const char* path, unsigned tamInfo);
int leerDesdeArchivoBinario(void** d, void* pf, unsigned pos, void* params);
int cargarDesdeDatosOrdenadosArbolBinario(tArbol* arbol, void* ds, unsigned cantReg, int leer (void** dato, void*,unsigned,void* params),void* params);

int eliminarNodoDeArbolBinario(tArbol* arbol);
int eliminarElementoDeArbolBinario(tArbol* arbol, void* dato, unsigned tam, int cmp (const void*, const void*));
int buscarElementoEnArbolBinario(const tArbol* arbol, void* dato, unsigned tam, int cmp (const void*,const void*));
tArbol* buscarNodoArbolBinario(const tArbol* arbol, const void* dato, int cmp (const void*,const void*));
tArbol* mayorNodoArbolBinario(const tArbol* arbol);
tArbol* menorNodoArbolBinario(const tArbol* arbol);
unsigned alturaArbolBinario(const tArbol* arbol);

int contarNodosDeArbol(const tArbol* arbol);
int eliminarHojas(tArbol* arbol);
void eliminarArbol(tArbol* arbol);

int cargarArbolConEnteros(tArbol* arbol,int cmp(void*a,void*b));

#endif // ARBOLBINARIO_H_INCLUDED
