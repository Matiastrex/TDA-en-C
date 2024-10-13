#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <stdio.h>
#include <string.h>

#define LONG_COD 7
#define LONG_DESC 15
#define LONG_PROV 15

#define OPERACION_PRODUCTO_OK 0
#define ERROR_ARCHIVO_PRODUCTO 1
#define SIN_MEMORIA_PRODUCTO 2

typedef struct{
    int d;
    int m;
    int a;
}tFecha;

typedef struct{
    char cod[LONG_COD];
    char desc[LONG_DESC];
    char prov[LONG_PROV];
    tFecha compra;
    tFecha vencimiento;
    unsigned cant;
    float precioCompra;
    float precioVenta;
}tProducto;

int compararProductoPorCantidad(const void* prod1, const void* prod2);
int compararProductoPorCodigo(const void* prod1, const void* prod2);
void mostrarProducto(const void* producto);
void ingresarProducto(tProducto* prod);
int generarArchivoBinarioDeProductos();
int leerArchivoBinarioDeProductos(const char* path);
//void generarArchivoTextoVariable();
//void generarArchivoTextoFijo();
#endif // PRODUCTO_H_INCLUDED
