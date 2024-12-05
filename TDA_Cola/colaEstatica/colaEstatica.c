#include "colaEstatica.h"
//PRIMITIVAS
void crearCola(tCola* cola)
{
    cola->pri = TAM_COLA - 50;
    cola->ult = TAM_COLA - 50;
    cola->tamDisp = TAM_COLA;
}
int colaVacia(const tCola* cola);
int colaLlena(const tCola* cola, unsigned tam);
int ponerEnCola(tCola* cola, unsigned tam, const void* info);
int sacarDeCola(tCola* cola, unsigned tamBuffer, void* buffer);
int verPrimero(const tCola* cola, unsigned tamBuffer, void* buffer);
void vaciarCola(tCola* cola);
