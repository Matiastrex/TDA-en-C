#include "producto.h"
#include "pedidos.h"
#include "colaDinamica.h"
int cmp (const void* a,const void* b);
void* busquedaDesordenada(const void* ptr, unsigned cantElem, unsigned tamElem, void* elem, int cmp (const void* a,const void* b));
int separarPedidosEnMayoristaMinorista(const char* original, const char* destino1, const char* destino2);
void separador();

int main()
{
    t_cola cola;
    crearCola(&cola);


    generarArchivoBinarioDePedidos(PATH_PEDIDOS);
    cargarArchivoBinarioEnCola(&cola,PATH_PEDIDOS,sizeof(TPedido));
    recorrerYMostrarColaUniforme(&cola,mostrarPedido,sizeof(TPedido));

    separador();

    separarPedidosEnMayoristaMinorista(PATH_PEDIDOS,PATH_PEDIDOS_MIN,PATH_PEDIDOS_MAY);

    cargarArchivoBinarioEnCola(&cola,PATH_PEDIDOS_MAY,sizeof(TPedido));
    recorrerYMostrarColaUniforme(&cola,mostrarPedido,sizeof(TPedido));

    separador();

    cargarArchivoBinarioEnCola(&cola,PATH_PEDIDOS_MIN,sizeof(TPedido));
    recorrerYMostrarColaUniforme(&cola,mostrarPedido,sizeof(TPedido));

    return 0;
}

int separarPedidosEnMayoristaMinorista(const char* original, const char* destino1, const char* destino2)
{
    t_cola cola;
    unsigned acumPedidos;
    FILE *pfOriginal, *pfMinorista, *pfMayorista, *pfObjetivo;
    TPedido pedidoActual, pedidoAnterior;
    TMayorista tablaMayorista[]={{"3",50},{"8",100},{"9",10}};
    TMayorista* pos;

    pfOriginal = fopen(PATH_PEDIDOS,"rb");
    if(pfOriginal == NULL)
    {
        return 0;
    }

    pfMinorista = fopen(destino1,"wb");
    if(pfMinorista == NULL)
    {
        fclose(pfOriginal);
        return 0;
    }

    pfMayorista = fopen(destino2,"wb");
    if(pfMayorista == NULL)
    {
        fclose(pfOriginal);
        fclose(pfMinorista);
        return 0;
    }

    crearCola(&cola);
    fread(&pedidoActual,sizeof(TPedido),1,pfOriginal);
    while(!feof(pfOriginal))
    {
        acumPedidos = 0;
        strcpy(pedidoAnterior.cod,pedidoActual.cod);

        while(!feof(pfOriginal) && strcmp(pedidoActual.cod,pedidoAnterior.cod) == 0)
        {
            ponerEnCola(&cola,sizeof(TPedido),&pedidoActual);
            acumPedidos += pedidoActual.cant;
            fread(&pedidoActual,sizeof(TPedido),1,pfOriginal);
        }

        pos = busquedaDesordenada(tablaMayorista,sizeof(tablaMayorista)/sizeof(TMayorista),sizeof(TMayorista),&pedidoAnterior.cod,compararTablaMayoristaXCod);

        if(pos != NULL && pos->cant <= acumPedidos)
            pfObjetivo = pfMayorista;
        else
            pfObjetivo = pfMinorista;

        while(!colaVacia(&cola))
        {
            sacarDeCola(&cola,sizeof(TPedido),&pedidoAnterior);
            fwrite(&pedidoAnterior,sizeof(TPedido),1,pfObjetivo);
        }
    }
    fclose(pfOriginal);
    fclose(pfMinorista);
    fclose(pfMayorista);

    return 1;
}
void* busquedaDesordenada(const void* ptr, unsigned cantElem, unsigned tamElem, void* elem, int cmp (const void* a,const void* b))
{
    void* i = (void*)ptr;
    void* ult = (void*)(ptr+(cantElem-1)*tamElem);

    while(i<=ult && cmp(elem,i)!=0)
        i+=tamElem;
    if(i==ult+tamElem)
        return NULL;
    else
        return i;
}
void separador()
{
    puts("--------------------------------------------------------------------");
}


