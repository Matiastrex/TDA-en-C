#include "colaEstatica.h"
//PRIMITIVAS
void crearCola(tCola* cola)
{
    cola->pri = TAM_COLA - 50;
    cola->ult = TAM_COLA - 50;
    cola->tamDisp = TAM_COLA;
}
int colaVacia(const tCola* cola)
{
    return cola->tamDisp == TAM_COLA;
}
int colaLlena(const tCola* cola, unsigned tam)
{
    return cola->tamDisp < tam + sizeof(unsigned);
}
int ponerEnCola(tCola* cola, unsigned tam, const void* info)
{
    unsigned ini, fin;

    if(cola->tamDisp < tam + sizeof(unsigned))
        return SIN_MEMORIA;
    cola->tamDisp -= sizeof(unsigned) + tam;

    ini = MIN(sizeof(unsigned),TAM_COLA-cola->ult);
    if(ini != 0)
        memcpy(cola->cola + cola->ult, &tam,ini);

    fin = sizeof(unsigned) - ini;
    if(fin != 0)
        memcpy(cola->cola, ((char*)&tam) + ini, fin);

    cola->ult = fin? fin : cola->ult + ini;
    ini =

}
int sacarDeCola(tCola* cola, unsigned tamBuffer, void* buffer);
int verPrimero(const tCola* cola, unsigned tamBuffer, void* buffer);
void vaciarCola(tCola* cola);
