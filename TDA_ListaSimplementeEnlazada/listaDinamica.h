#ifndef LISTADINAMICA_H_INCLUDED
#define LISTADINAMICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TODO_OK 0
#define SIN_MEM 1
#define MIN(x,y) ((x)<=(y)? (x) : (y))
#define ASC 1
#define DESC -1

typedef struct s_nodo
{
    unsigned tam;
    void* info;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista(t_lista* lista);
void vaciarLista(t_lista* lista);
void cargarListaConEnteros(t_lista* lista);

int agregarAlFinalDeLista(t_lista* lista, void* dato, unsigned tam);
int insertarEnListaOrdenada(t_lista* lista, const void* dato, unsigned tamDato, int duplicado, int cmp(const void* a,const void* b));

void recorrerLista(t_lista* lista, void accion(const void*a,const void*b));

int eliminarDeListaOrdenadaPorClave(t_lista* lista, void* buffer, unsigned tamDato, int cmp(const void* a,const void* b));
//void eliminarTodosDeListaOrdenadaPorClave(t_lista* lista, void* buffer, unsigned tamDato, int cmp(const void*a,const void*b));

void ordenarListaPorSeleccion(t_lista* lista, int cmp(const void* a,const void* b),int sentido);
t_nodo* buscarMenor(const t_nodo* nodoInicial, int cmp(const void*, const void*),int sentido);
void intercambiarInfoDeNodos(void** a, void** b);

//t_lista ordenarListaPorMerge(t_lista* lista);
//t_nodo* puntoMedio(t_lista* lista);


void accion(void*a, void*b);

#endif // LISTADINAMICA_H_INCLUDED
