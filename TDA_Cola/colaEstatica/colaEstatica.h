#ifndef COLAESTATICA_H_INCLUDED
#define COLAESTATICA_H_INCLUDED

#define TAM_COLA 256

#define SIN_MEMORIA -1

#define MIN(x,y) ((x)<(y))? (x) : (y)
typedef struct{
    char cola[TAM_COLA];
    unsigned pri;
    unsigned ult;
    unsigned tamDisp;
}tCola;

//PRIMITIVAS
void crearCola(tCola* cola);
int colaVacia(const tCola* cola);
int colaLlena(const tCola* cola, unsigned tam);
int ponerEnCola(tCola* cola, unsigned tam, const void* info);
int sacarDeCola(tCola* cola, unsigned tamBuffer, void* buffer);
int verPrimero(const tCola* cola, unsigned tamBuffer, void* buffer);
void vaciarCola(tCola* cola);

#endif // COLAESTATICA_H_INCLUDED
