#include "pilaEstatica.h"
void crearPila(tPila* pila)
{
    pila->tope = TAM_PILA;
}
int apilar(tPila* pila, const void* dato, unsigned tam)
{
    if(pila->tope < (tam + sizeof(unsigned)))
        return 0;

    pila->tope -= tam;
    memcpy(pila->pila + pila->tope, dato, tam);

    pila->tope -= sizeof(unsigned);
    memcpy(pila->pila + pila->tope, &tam, sizeof(unsigned));

    return 1;
}
int desapilar(tPila* pila, void* dato, unsigned tam)
{
    unsigned tamAux;

    if(pila->tope == TAM_PILA)
        return 0;

    memcpy(&tamAux, pila->pila + pila->tope, sizeof(unsigned));
    pila->tope += sizeof(unsigned);

    memcpy(dato, pila->pila + pila->tope, MIN(tamAux,tam));
    pila->tope += tamAux;

    return 1;
}
int verTope(const tPila* pila, void* buffer, unsigned tamBuffer)
{
    unsigned tamAux;

    if(pila->tope == TAM_PILA)
        return 0;

    memcpy(&tamAux, pila->pila + pila->tope, sizeof(unsigned));
    memcpy(buffer, pila->pila + pila->tope + sizeof(unsigned), MIN(tamAux,tamBuffer));

    return 1;
}
void vaciarPila(tPila* pila)
{
    pila->tope = TAM_PILA;
}
int esPilaVacia(const tPila* pila)
{
    return pila->tope == TAM_PILA;
}
int esPilaLlena(const tPila* pila, unsigned tam)
{
    return pila->tope < tam + sizeof(unsigned);
}
