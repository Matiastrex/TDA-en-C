#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_nodo
{
    unsigned tam;
    void*  info;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* tPila;

//PRIMITIVAS
void crearPila(tPila* pila);
int apilar(tPila* pila, const void* dato, unsigned tam);
int desapilar(tPila* pila, void* dato, unsigned tam);
int verTope(const tPila* pila, void* dato, unsigned tam);
void vaciarPila(tPila* pila);
int esPilaVacia(const tPila* pila);
int esPilaLlena(const tPila* pila, unsigned tam);

//DERIVADAS
int ordenarArchivoConPila(const char* path, int cmp(const void* a,const void* b), unsigned bytesRegistro, int dir); //dir 1 ordenamiento asc, dir -1 ordenamiento desc
void cargarNumero(tPila* pila, int* numero, unsigned cantDigitos);
void sumarNumeros(tPila* p1, tPila* p2, tPila* pFinal);
void leerNumeroEnPila(tPila* pila);

#endif // PILA_H_INCLUDED
