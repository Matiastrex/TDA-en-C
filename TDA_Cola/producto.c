#include "producto.h"
int compararProductoPorCantidad(const void* prod1, const void* prod2)
{
    return ((tProducto*)prod1)->cant-((tProducto*)prod2)->cant;
}
int compararProductoPorCodigo(const void* prod1, const void* prod2)
{
    return strcmp(((tProducto*)prod1)->cod,((tProducto*)prod2)->cod);
}

void mostrarProducto(const void* producto)
{
    tProducto* prod = (tProducto*)producto;
    printf("%s|%-*s|%-*s|%02d/%02d/%4d|%02d/%02d/%4d|%03d|%03.2f|%06.2f\n",prod->cod,LONG_DESC,prod->desc,LONG_PROV,prod->prov,
    prod->compra.d,prod->compra.m,prod->compra.a,prod->vencimiento.d,prod->vencimiento.m,
    prod->vencimiento.a,prod->cant,prod->precioCompra,prod->precioVenta);
}
void ingresarProducto(tProducto* prod)
{
    gets(prod->cod);
    fflush(stdin);

    gets(prod->desc);
    fflush(stdin);

    gets(prod->prov);

    scanf("%d/%d/%d",&prod->compra.d,&prod->compra.m,&prod->compra.a);

    scanf("%d/%d/%d",&prod->vencimiento.d,&prod->vencimiento.m,&prod->vencimiento.a);

    scanf("%d",&prod->cant);

    scanf("%f",&prod->precioCompra);

    scanf("%f",&prod->precioVenta);
}
int generarArchivoBinarioDeProductos(const char* path)
{
     tProducto productos[15] = {
        {"P003", "Yerba Mate", "Provee SA", {1, 9, 2023}, {1, 9, 2025}, 100, 350.50, 500.00},
        {"P002", "Arroz Integ", "Arroces Sur", {15, 8, 2023}, {15, 8, 2024}, 200, 100.00, 150.00},
        {"P001", "Aceite Oliv", "Olivar SA", {10, 7, 2023}, {10, 7, 2024}, 50, 700.00, 900.00},
        {"P004", "Harina Trig", "Molinos Uni", {25, 6, 2023}, {25, 6, 2024}, 300, 90.00, 120.00},
        {"P008", "Azucar Bla", "Azucarera N", {30, 5, 2023}, {30, 5, 2024}, 400, 80.00, 110.00},
        {"P010", "Sal Fina", "Minerales S", {12, 8, 2023}, {12, 8, 2025}, 250, 50.00, 70.00},
        {"P007", "Fideos Spa", "Pasta Prima", {5, 7, 2023}, {5, 7, 2024}, 150, 60.00, 90.00},
        {"P005", "Leche Ente", "Lacteos SA", {22, 6, 2023}, {22, 10, 2023}, 500, 80.00, 120.00},
        {"P009", "Queso Rall", "Queserias", {18, 7, 2023}, {18, 1, 2024}, 100, 150.00, 200.00},
        {"P006", "Galletas Du", "Confiteria", {12, 9, 2023}, {12, 3, 2024}, 300, 50.00, 75.00},
        {"P011", "Jugo Naran", "Bebidas Nat", {5, 9, 2023}, {5, 12, 2023}, 200, 100.00, 150.00},
        {"P012", "Cafe Molid", "Cafeteros", {1, 8, 2023}, {1, 2, 2024}, 120, 250.00, 350.00},
        {"P015", "Te Verde", "Herbales SA", {15, 8, 2023}, {15, 8, 2025}, 100, 200.00, 280.00},
        {"P014", "Chocolates", "Dulces SA", {20, 9, 2023}, {20, 3, 2024}, 400, 500.00, 700.00},
        {"P013", "Mermelada D", "Frutales SR", {2, 7, 2023}, {2, 7, 2024}, 180, 120.00, 180.00}
    };

    FILE* pf = fopen(path,"wb");
    if(pf == NULL)
    {
        return ERROR_ARCHIVO_PRODUCTO;
    }

    fwrite(productos, sizeof(tProducto),sizeof(productos)/sizeof(tProducto),pf);
    fclose(pf);
    return OPERACION_PRODUCTO_OK;
}
int leerArchivoBinarioDeProductos(const char* path)
{
    tProducto prod;
    FILE* pf = fopen(path,"rb");
    if(pf == NULL)
    {
        return ERROR_ARCHIVO_PRODUCTO;
    }

    fread(&prod,sizeof(tProducto),1,pf);
    while(!feof(pf))
    {
        mostrarProducto(&prod);
        fread(&prod,sizeof(tProducto),1,pf);
    }
    fclose(pf);
    return OPERACION_PRODUCTO_OK;
}
void generarArchivoTextoVariable()
{

}
void generarArchivoTextoFijo()
{

}
