#include "pedidos.h"
int generarArchivoBinarioDePedidos(const char* path)
{
    TPedido pedidos[]={{{2,5,2024},15,"8",'A',4},
                       {{2,5,2024},19,"8",'A',10},
                       {{3,5,2024},12,"8",'B',40},
                       {{4,5,2024},10,"8",'C',6},
                       {{1,6,2024},15,"9",'A',2},
                       {{1,6,2024},19,"9",'B',5},
                       {{3,6,2024},12,"9",'C',30},
                       {{4,6,2024},12,"10",'A',8},
                       {{5,6,2024},12,"10",'B',12},
                       {{5,6,2024},12,"10",'C',4}};

    FILE* pf = fopen(path,"wb");
    if(pf == NULL)
    {
        return 0;
    }
    fwrite(pedidos,sizeof(TPedido),sizeof(pedidos)/sizeof(TPedido),pf);
    fclose(pf);
    return 1;
}
int generarArchivoBinarioDeTablaMayorista(const char* path)
{
    TMayorista criterios[]={{"3",50},{"8",100},{"9",10}};
    FILE* pf = fopen(path,"wb");
    if(pf == NULL)
    {
        return 0;
    }
    fwrite(criterios,sizeof(TMayorista),sizeof(criterios)/sizeof(TMayorista),pf);
    fclose(pf);
    return 1;
}
void mostrarPedido(const void* pedido)
{
    printf("%d/%d/%d|%d|%s|%c|%d\n",((TPedido*)pedido)->fecha.d,((TPedido*)pedido)->fecha.m,((TPedido*)pedido)->fecha.a,
                                   ((TPedido*)pedido)->hora,((TPedido*)pedido)->cod,((TPedido*)pedido)->sector,((TPedido*)pedido)->cant);
}
int compararTablaMayoristaXCod(const void* pedidoA, const void* pedidoB)
{
    return strcmp(((TMayorista*)pedidoA)->cod,((TMayorista*)pedidoB)->cod);
}
void mostrarMayorista(const void* mayorista)
{
    printf("%s|%d\n",((TMayorista*)mayorista)->cod,((TMayorista*)mayorista)->cant);
}
