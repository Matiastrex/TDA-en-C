#include "listaDoble.h"
int cmpEntero (const void* a, const void* b);
void mostrarEntero(void* a, void* b);
int main()
{
    tLista lista;
    int vec[] = {5,7,3,2,10,1,5}, i, num=10;
    crearListaDoble(&lista);
    for(i=0;i<sizeof(vec)/sizeof(int);i++)
    {
        insertarOrdenadoEnListaDoble(&lista,&vec[i],sizeof(int),NODUP,cmpEntero);
    }
    puts("Lista cargada");
    recorrerListaDobleDesdeInicio(&lista,mostrarEntero);
    puts("");
    recorrerListaDobleDesdeFinal(&lista,mostrarEntero);

    eliminarDeListaDobleOrdenada(&lista,&num,sizeof(int),cmpEntero);
    puts("\nLista tras eliminar un elemento ");
    recorrerListaDobleDesdeInicio(&lista,mostrarEntero);
    puts("");
    recorrerListaDobleDesdeFinal(&lista,mostrarEntero);

    num = 1;
    eliminarDeListaDobleDesordenada(&lista,&num,sizeof(int),cmpEntero);
    puts("\nLista tras eliminar un elemento ");
    recorrerListaDobleDesdeInicio(&lista,mostrarEntero);
    puts("");
    recorrerListaDobleDesdeFinal(&lista,mostrarEntero);

    return 0;
}
int cmpEntero (const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}
void mostrarEntero(void* a, void* b)
{
    printf("%d|",*(int*)a);
}
