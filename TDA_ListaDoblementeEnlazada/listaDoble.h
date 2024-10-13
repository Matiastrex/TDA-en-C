#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DUP 1
#define NODUP 0
#define MIN(x,y) (((x)<(y))? (x) : (y))
typedef struct sNodo
{
    struct sNodo* ant;
    unsigned tamDato;
    void* info;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;

void crearListaDoble(tLista* lista);
int listaDobleVacia(const tLista* lista);
int listaDobleLlena(const tLista* lista, unsigned tamDato);
int insertarOrdenadoEnListaDoble(tLista* lista, void* dato, unsigned bytesRegistro,int duplicados, int cmp(const void* a, const void* b));
int eliminarDeListaDobleOrdenada(tLista* lista, void* clave, unsigned bytesRegistro,int cmp(const void* a, const void* b));
int eliminarDeListaDobleDesordenada(tLista* lista, void* clave, unsigned bytesRegistro,int cmp(const void* a, const void* b));
void recorrerListaDobleDesdeInicio(tLista* lista, void accion(void* a, void* b));
void recorrerListaDobleDesdeFinal(tLista* lista, void accion(void* a, void* b));
int verActual(const tLista* lista, void* buffer, unsigned bytesRegistro);


#endif // LISTADOBLE_H_INCLUDED
