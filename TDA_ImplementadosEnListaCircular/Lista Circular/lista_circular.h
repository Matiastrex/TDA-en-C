#ifndef LISTA_CIRCULAR_H_INCLUDED
#define LISTA_CIRCULAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(a,b) ((a) <= (b) ? (a) : (b))
#define ASC 1
#define DESC -1
#define DUP 1
#define NODUP 0
typedef struct sNodo
{
    void* info;
    unsigned tam;
    struct sNodo *sig;
}tNodo;

typedef tNodo *tLista;

//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////LISTA CIRCULAR///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void crearListaCircular(tLista* p);
int listaCircularVacia(const tLista* p);
int cargarListaCircularConEnteros(tLista* p,int cmp(const void* a, const void* b));
int insertarAlInicioDeListaCircular(tLista* p, void* dato, unsigned bytesDato);
int insertarAlFinalDeListaCircular(tLista* p, void* dato, unsigned bytesDato);
int insertarEnPosicionDeListaCircular(tLista* p, void* dato, unsigned bytesDato, unsigned pos); //Desde 1 a n
int insertarEnOrdenDeListaCircular(tLista* p, void* dato, unsigned bytesDato, int cmp(const void* a, const void* b),int sentido, int duplicados);//ASC 1, DESC -1, DUP 1, NODUP 0
int eliminarPrimeroDeListaCircular(tLista* p, void* buffer, unsigned bytesDato);
int eliminarUltimoDeListaCircular(tLista* p, void* buffer, unsigned bytesDato);
int eliminarPrimeraAparicionDeListaCircular(tLista* p, void* clave, unsigned bytesDato, int cmp(const void* a, const void* b));
//int eliminarTodasAparicionesDeListaCircular(tLista* p, void* clave, unsigned bytesDato, int cmp(const void* a, const void* b));
//int eliminarDuplicadosDeListaCircular(tLista* p, void* clave, unsigned bytesDato, int cmp(const void* a, const void* b));
int vaciarListaCircular(tLista* p);

//void* buscarEnListaCircularDesordenada(const tLista* p, void* clave, unsigned bytesDato, int cmp(const void* a, const void* b));
//void* buscarEnListaCircularOrdenada(const tLista* p, void* clave, unsigned bytesDato, int cmp(const void* a, const void* b));

//void ordenarListaCircularPorSeleccion(tLista* lista, int cmp(const void* a,const void* b),int sentido);
//tNodo* buscarMenorEnListaCircular(const tNodo* nodoInicial,int cmp(const void*, const void*),int sentido);
//void intercambiarInfoDeNodos(void** a, void** b);

int recorrerListaCircular(tLista* p, void accion(void* a, void* b));
//void filtrarListaCircular(tLista* p, ...);
//void reducirListaCircular(tLista*p, ...);

//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////COLA CIRCULAR////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void crearColaCircular(tLista* p);
int ponerEnColaCircular(tLista* p,void* info,unsigned tam);
int sacarDeColaCircular(tLista* p,void* buffer,unsigned tam);
int verPrimeroEnColaCircular(const tLista* p,void* buffer,unsigned tam);
int esColaCircularVacia(const tLista* p);
int esColaCircularLlena(const tLista* p, unsigned tam);
void vaciarColaCircular(tLista* p);
//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////PILA CIRCULAR////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void crearPilaCircular(tLista* p);
int ponerEnPilaCircular(tLista* p,void* info,unsigned tam);
int sacarDePilaCircular(tLista* p,void* buffer,unsigned tam);
int verTopeDePilaCircular(const tLista* p,void* buffer,unsigned tam);
int esPilaCircularVacia(const tLista* p);
int esPilaCircularLlena(const tLista* p, unsigned tam);
void vaciarPilaCircular(tLista* p);


#endif // LISTA_CIRCULAR_H_INCLUDED
