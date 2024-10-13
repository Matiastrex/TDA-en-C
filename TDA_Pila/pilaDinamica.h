#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_nodo
{
    unsigned tam;
    void*  info;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_pila;

//PRIMITIVAS
void crearPila(t_pila* pila);
int apilar(t_pila* pila, const void* dato, unsigned tam);
int desapilar(t_pila* pila, void* dato, unsigned tam);
int verTope(const t_pila* pila, void* dato, unsigned tam);
void vaciarPila(t_pila* pila);
int esPilaVacia(const t_pila* pila);
int esPilaLlena(const t_pila* pila, unsigned tam);

//DERIVADAS
int ordenarArchivoConPila(const char* path, int cmp(const void* a,const void* b), unsigned bytesRegistro, int dir); //dir 1 ordenamiento asc, dir -1 ordenamiento desc
void cargarNumero(t_pila* pila, int* numero, unsigned cantDigitos);
void sumarNumeros(t_pila* p1, t_pila* p2, t_pila* pFinal);
void leerNumeroEnPila(t_pila* pila);


#endif // PILADINAMICA_H_INCLUDED
