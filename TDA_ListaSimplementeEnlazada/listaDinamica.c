#include "listaDinamica.h"

void crearLista(t_lista* lista)
{
    *lista = NULL;
}
void vaciarLista(t_lista* lista)
{
    t_nodo* auxElim;
    while(*lista)
    {
        auxElim = *lista;
        *lista = auxElim->sig;
        free(auxElim->info);
        free(auxElim);
    }
}
int agregarAlFinalDeLista(t_lista* lista, void* dato, unsigned tam)
{
    t_nodo* nodo = (t_nodo*)malloc(sizeof(t_nodo));
    if(nodo == NULL)
    {
        return SIN_MEM;
    }
    nodo->info=malloc(tam);
    if(nodo->info == NULL)
    {
        free(nodo);
        return SIN_MEM;
    }

    memcpy(nodo->info,dato,tam);
    nodo->tam = tam;
    nodo->sig = NULL;

    while(*lista)
    {
        lista = &(*lista)->sig;
    }
    *lista = nodo;

    return TODO_OK;
}
void cargarListaConEnteros(t_lista* lista)
{
    int i;
    int vec[]={7,6,5,7,2,3,24,0,11,7,7,7,5,6,7};
    for(i=0;i<sizeof(vec)/sizeof(int);i++)
    {
        agregarAlFinalDeLista(lista,&vec[i],sizeof(int));
    }
}
void recorrerLista(t_lista* lista, void accion(const void*a,const void* b))
{
    while(*lista)
    {
        accion((*lista)->info, NULL);
        lista = &(*lista)->sig;
    }
}

int insertarEnListaOrdenada(t_lista* lista, const void* dato, unsigned tamDato, int duplicado, int cmp(const void* a,const void* b))
{
    t_nodo* nuevo;

    while((*lista) && (cmp((*lista)->info,(void*)dato)<0))
    {
        lista = &(*lista)->sig;
    }

    if(!duplicado && cmp((*lista)->info,(void*)dato)==0) // *lista != NULL && ... ?
    {
        return 0;
    }

    nuevo = (t_nodo*)malloc(sizeof(t_nodo));
    if(nuevo == NULL)
    {
        return 0;
    }

    nuevo->info = malloc(tamDato);
    if(nuevo->info == NULL)
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->info,dato,tamDato);
    nuevo->tam = tamDato;

    nuevo->sig = *lista;
    *lista = nuevo;

    return 1;
}
int eliminarDeListaOrdenadaPorClave(t_lista* lista, void* buffer, unsigned tamDato, int cmp(const void* a,const void* b))
{
    t_nodo* elim;
    while(*lista && (cmp((*lista)->info,buffer)<0))
    {
        lista = &(*lista)->sig;
    }
    if(*lista && (cmp(buffer,(*lista)->info))==0)
    {
        memcpy(buffer,(*lista)->info,MIN(tamDato,(*lista)->tam));

        elim = *lista;
        *lista = elim->sig;
        free(elim->info);
        free(elim);
        return 1;
    }
    return 0;
}
//void eliminarTodosDeListaOrdenadaPorClave(t_lista* lista, void* buffer, unsigned tamDato, int cmp(const void*a,const void*b))
//{
//    t_nodo* pL;
//    t_nodo* auxElim;
//
//    while(*lista)
//    {
//        pL = *lista;
//        lista = &(*lista)->sig;
//
//        while(*lista && cmp((*lista)->info,buffer)==0)
//        {
//            auxElim = *lista;
//            lista = &(*lista)->sig;
//            free(auxElim->info);
//            free(auxElim);
//        }
//
//        pL->sig =*lista;
//        lista = &(*lista)->sig;
//    }
//}


void ordenarListaPorSeleccion(t_lista* lista, int cmp(const void* a,const void* b),int sentido)
{
    t_nodo* minimo = *lista;
    t_nodo* actual = *lista;
    while(actual)
    {
        minimo = buscarMenor((t_nodo*)actual,cmp,sentido);
        if(minimo != actual)
        {
            intercambiarInfoDeNodos(&minimo->info,&actual->info);
        }
        actual = actual->sig;
    }

}
void intercambiarInfoDeNodos(void** a, void** b)
{
    void* aux = *a;
    *a = *b;
    *b = aux;
}
t_nodo* buscarMenor(const t_nodo* nodoInicial,int cmp(const void*, const void*),int sentido)
{
    t_nodo* minimo = (t_nodo*)nodoInicial;
    t_nodo* actual = (t_nodo*)nodoInicial;
    while(actual)
    {
        if(cmp(minimo->info,actual->info)*sentido>0)
        {
            minimo = actual;
        }
        actual = actual->sig;
    }
    return minimo;
}

//t_lista ordenarListaPorMerge(t_lista* lista)
//{
//    t_nodo* medio, mitad1,mitad2;
//    if(*lista == NULL || (*lista)->sig == NULL)
//    {
//        return *lista;
//    }
//    medio = puntoMedio(lista);
//
//    mitad1 = *lista;
//    mitad2 = medio->sig;
//    medio->sig = NULL;
//
//    mitad1 = ordenarListaPorMerge(lista);
//    mitad2 = ordenarListaPorMerge(lista);
//
//    return insertarEnListaOrdenada(
//}
//
//t_nodo* puntoMedio(t_lista* lista)
//{
//    t_nodo* slow = *lista;
//    t_nodo* fast = (*lista)->sig;
//
//    while(fast != NULL && fast->sig != NULL)
//    {
//        slow = slow->sig;
//        fast = fast->sig->sig;
//    }
//
//    return slow;
//}

