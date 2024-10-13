#include "lista_circular.h"

void mostrarEntero(void* a, void* b);
int cmpEntero(const void* a, const void* b);

int main()
{
    int num;
    tLista listaCircular;
    crearListaCircular(&listaCircular);
    cargarListaCircularConEnteros(&listaCircular,cmpEntero);
    recorrerListaCircular(&listaCircular,mostrarEntero);

    puts("\nBorrando elementos: ");
    num=1;
    eliminarPrimeraAparicionDeListaCircular(&listaCircular,&num,sizeof(int),cmpEntero);
    recorrerListaCircular(&listaCircular,mostrarEntero);
    puts("");
    num=1;
    eliminarPrimeraAparicionDeListaCircular(&listaCircular,&num,sizeof(int),cmpEntero);
    recorrerListaCircular(&listaCircular,mostrarEntero);




    return 0;
}
void mostrarEntero(void* a, void* b)
{
    printf("%d|",*(int*)a);
}
int cmpEntero(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}
