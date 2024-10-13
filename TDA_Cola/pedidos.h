#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED
#include "funcionesFecha.h"
#include "string.h"

#define LONG_COD 7
#define LONG_PATH 50
#define PATH_PEDIDOS "Pedidos.dat"
#define PATH_PEDIDOS_MIN "PedidosMinoristas.dat"
#define PATH_PEDIDOS_MAY "PedidosMayoristas.dat"
#define PATH_TABLA_MAYORISTA "TablaMayorista.dat"
typedef struct
{
    TFecha fecha;
    unsigned hora;
    char cod[LONG_COD];
    char sector;
    unsigned cant;
}TPedido;
typedef struct
{
    char cod[LONG_COD];
    unsigned cant;
}TMayorista;

int generarArchivoBinarioDePedidos(const char* path);
int generarArchivoBinarioDeTablaMayorista(const char* path);
void mostrarPedido(const void* pedido);
int compararTablaMayoristaXCod(const void* pedidoA, const void* pedidoB);
void mostrarMayorista(const void* mayorista);

#endif // PEDIDOS_H_INCLUDED
