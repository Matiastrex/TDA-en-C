#include "listaDinamica.h"

int cmpEntero (const void* a,const void* b);
void mostrarEntero(const void*a,const void* b);

int main()
{
    t_lista lista;
    crearLista(&lista);
    int clave = 7;

    cargarListaConEnteros(&lista);
//    eliminarTodosDeListaOrdenadaPorClave(&lista,&clave,sizeof(int),cmpEntero);
    recorrerLista(&lista,mostrarEntero);
    vaciarLista(&lista);

    return 0;
}
int cmpEntero (const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}
void mostrarEntero(const void*a,const void*b)
{
    printf("%d\n",*(int*)a);
}
