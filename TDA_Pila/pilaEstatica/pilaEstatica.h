#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 256
#define TAM_PILA 50
#define MIN(x,y) ((x)<(y)? (x) : (y))

#define OK 0
#define SIN_MEMORIA -1
#define VACIA -2
#define LLENA -3

typedef struct{
        char pila[TAM];
        unsigned tope;
}tPila;

//PRIMITIVAS
void crearPila(tPila* pila);
int apilar(tPila* pila, const void* dato, unsigned tam);
int desapilar(tPila* pila, void* dato, unsigned tam);
int verTope(const tPila* pila, void* dato, unsigned tam);
void vaciarPila(tPila* pila);
int esPilaVacia(const tPila* pila);
int esPilaLlena(const tPila* pila, unsigned tam);

#endif // PILAESTATICA_H_INCLUDED
