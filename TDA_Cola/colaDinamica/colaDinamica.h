#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodo{
    void* info;
    unsigned tamInfo;
    struct sNodo* sig;
}t_nodo;

typedef struct{
    t_nodo* pri;
    t_nodo* ult;
}t_cola;


//PRIMITIVAS
void crearCola(t_cola* cola);
int colaVacia(const t_cola* cola);
int colaLlena(const t_cola* cola, unsigned tam);
int ponerEnCola(t_cola* cola, unsigned tam, const void* info);
int sacarDeCola(t_cola* cola, unsigned tamBuffer, void* buffer);
int verPrimero(const t_cola* cola, unsigned tamBuffer, void* buffer);
void vaciarCola(t_cola* cola);

//AVANZADAS
int cargarArchivoBinarioEnCola(t_cola* cola, const char* path, unsigned tam);
int recorrerYMostrarColaUniforme(t_cola* cola,void accion(const void* a),unsigned tam);

//COMPLEMENTARIAS
void accion(const void* a);


#endif // COLADINAMICA_H_INCLUDED
