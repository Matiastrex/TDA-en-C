#include "listaDoble.h"
//INTEGRANTES
//Quispe Milagros 45064110
//Cruz Aro Melina 43444249
//Familia Cruz Karina Soledad 42838266
//Contti Claudio Abel 39487489
//Modestti Tomas Agustin 45073572
//Matías Guliano 41464442

int cmpEntero (const void* a, const void* b);
void mostrarEntero(void* a, void* b);

int main()
{
    tLista listaOrdenada, listaDesordenada;
    int vec[] = {5,7,3,2,10,1,5}, i, num=10;
    crearListaDoble(&listaOrdenada);
    crearListaDoble(&listaDesordenada);

    //PROBANDO ELIMINAR CON LISTA VACIA
    eliminarDeListaDobleDesordenada(&listaDesordenada,&num,sizeof(int),cmpEntero);
    eliminarDeListaDobleOrdenada(&listaOrdenada,&num,sizeof(int),cmpEntero);

    //CARGANDO LA LISTA Y MOSTRANDOLA DESDE AMBOS LADOS
    for(i=0;i<sizeof(vec)/sizeof(int);i++)
    {
        insertarOrdenadoEnListaDoble(&listaDesordenada,&vec[i],sizeof(int),NODUP,cmpEntero);
        insertarOrdenadoEnListaDoble(&listaOrdenada,&vec[i],sizeof(int),NODUP,cmpEntero);
    }
    puts("Lista cargada");
    recorrerListaDobleDesdeInicio(&listaDesordenada,mostrarEntero);
    puts("");
    recorrerListaDobleDesdeFinal(&listaOrdenada,mostrarEntero);

    //PROBANDO ELIMINAR ULTIMO NODO
    eliminarDeListaDobleOrdenada(&listaDesordenada,&num,sizeof(int),cmpEntero);
    eliminarDeListaDobleOrdenada(&listaOrdenada,&num,sizeof(int),cmpEntero);

    puts("\nLista tras eliminar ultimo elemento ");
    recorrerListaDobleDesdeInicio(&listaDesordenada,mostrarEntero);
    printf(" || ");
    recorrerListaDobleDesdeInicio(&listaOrdenada,mostrarEntero);
    puts("");
    recorrerListaDobleDesdeFinal(&listaDesordenada,mostrarEntero);
    printf(" || ");
    recorrerListaDobleDesdeFinal(&listaOrdenada,mostrarEntero);

    //PROBANDO ELIMINAR PRIMER NODO
    num = 1;
    eliminarDeListaDobleDesordenada(&listaDesordenada,&num,sizeof(int),cmpEntero);
    eliminarDeListaDobleDesordenada(&listaOrdenada,&num,sizeof(int),cmpEntero);

    puts("\nLista tras eliminar primer elemento ");
    recorrerListaDobleDesdeInicio(&listaDesordenada,mostrarEntero);
    printf(" || ");
    recorrerListaDobleDesdeInicio(&listaOrdenada,mostrarEntero);
    puts("");
    recorrerListaDobleDesdeFinal(&listaDesordenada,mostrarEntero);
    printf(" || ");
    recorrerListaDobleDesdeFinal(&listaOrdenada,mostrarEntero);

    //PROBANDO ELIMINAR NODO EN EL MEDIO
    num = 5;
    eliminarDeListaDobleDesordenada(&listaDesordenada,&num,sizeof(int),cmpEntero);
    eliminarDeListaDobleDesordenada(&listaOrdenada,&num,sizeof(int),cmpEntero);

    puts("\nLista tras eliminar elemento intermedio");
    recorrerListaDobleDesdeInicio(&listaDesordenada,mostrarEntero);
    printf(" || ");
    recorrerListaDobleDesdeInicio(&listaOrdenada,mostrarEntero);
    puts("");
    recorrerListaDobleDesdeFinal(&listaDesordenada,mostrarEntero);
    printf(" || ");
    recorrerListaDobleDesdeFinal(&listaOrdenada,mostrarEntero);

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
