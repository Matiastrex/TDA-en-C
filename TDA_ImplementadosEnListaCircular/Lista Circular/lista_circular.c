#include "lista_circular.h"

/////////////////////////////LISTA CIRCULAR////////////////////////////////////////
void crearListaCircular(tLista* p)
{
    *p = NULL;
}
int listaCircularVacia(const tLista* p)
{
    return *p == NULL;
}

int cargarListaCircularConEnteros(tLista* p,int cmp(const void* a, const void* b))
{
    int i,vec[]={5,8,1,3,4,6,7,88,1,4,13};
     for(i=0;i<sizeof(vec)/sizeof(int);i++)
    {
        insertarEnOrdenDeListaCircular(p,&vec[i],sizeof(int),cmp,ASC,DUP);
    }
}
int insertarAlInicioDeListaCircular(tLista* p, void* dato, unsigned bytesDato)
{
    tNodo* act = *p;
    tNodo* nuevo;

    nuevo = malloc(sizeof(tNodo));
    if(nuevo == NULL)
    {
        return 0;
    }
    nuevo->info = malloc(bytesDato);
    if(nuevo->info == NULL)
    {
        free(nuevo);
        return 0;
    }

    memcpy(nuevo->info,dato,bytesDato);
    nuevo->tam = bytesDato;

    if(*p == NULL)
    {
        *p = nuevo;
        nuevo->sig = *p;
    }
    else
    {
        while(act->sig != NULL && act->sig != *p)
        {
            act = act->sig;
        }

        act->sig = nuevo;
        nuevo->sig = *p;
        *p = nuevo;
    }
    return 1;
}
int insertarAlFinalDeListaCircular(tLista* p, void* dato, unsigned bytesDato)
{
    tNodo *nue, *act;

    //CREACION DE NODO
    nue = malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return 0;
    }
    nue->info = malloc(bytesDato);
    if(nue->info == NULL)
    {
        free(nue);
        return 0;
    }

    //COMUN PARA TODOS LOS CASOS
    nue->tam = bytesDato;
    memcpy(nue->info, dato, bytesDato);

    //CASO LISTA VACIA
    if(*p == NULL)
    {
        *p = nue;
        nue->sig = nue;
        return 1;
    }

    //CASO LISTA NO VACIA
    act = *p;
    while(act->sig != *p)
    {
        act = act->sig;
    }
    act->sig = nue;
    nue->sig = *p;
    return 1;
}
int insertarEnPosicionDeListaCircular(tLista* p, void* dato, unsigned bytesDato, unsigned pos)
{
    tNodo *nue, *act;
    int i;

    //CREACION DE NODO
    nue = malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return 0;
    }
    nue->info = malloc(bytesDato);
    if(nue->info == NULL)
    {
        free(nue);
        return 0;
    }
    //COMUN PARA TODOS LOS CASOS
    nue->tam = bytesDato;
    memcpy(nue->info,dato,bytesDato);

    //CASO LISTA VACIA
    if(*p == NULL)
    {
        nue->sig = nue;
        *p = nue;
        return 1;
    }

    if(pos == 1) //CASO PRIMERA POSICION (SERIA INSERTAR AL INICIO)
    {
        act = *p;
        while(act->sig != *p)
        {
            act = act->sig;
        }
        act->sig = nue;
        nue->sig = *p;
        *p = nue;

        return 1;
    }
    else //CASO GENERAL
    {
        i=1;
        act = *p;
        while(act->sig != *p && i < pos-1)
        {
            act = act->sig;
            i++;
        }
        nue->sig = act->sig;
        act->sig = nue;
        return 1;
    }
}
int insertarEnOrdenDeListaCircular(tLista* p, void* dato, unsigned bytesDato, int cmp(const void* a, const void* b),int sentido, int duplicados)
{
    tNodo *nue, *act;

    if(*p == NULL)
    {
        nue = malloc(sizeof(tNodo));
        if(nue == NULL)
        {
            return 0;
        }
        nue->info = malloc(bytesDato);
        if(nue->info == NULL)
        {
            free(nue);
            return 0;
        }
        nue->sig = nue;
        nue->tam = bytesDato;
        memcpy(nue->info, dato,bytesDato);
        *p = nue;
        return 1;
    }

    if(cmp(dato,(*p)->info)*sentido>=0) //CASO INSERCION LUEGO DEL PRIMERO
    {
        act = *p;
        while(act->sig != *p && cmp(dato,act->sig->info)*sentido>0)
        {
            act = act->sig;
        }
        if(cmp(dato,act->sig->info)==0 && duplicados == NODUP)
            return 0;
        else
        {
            nue = malloc(sizeof(tNodo));
            if(nue == NULL)
            {
                return 0;
            }
            nue->info = malloc(bytesDato);
            if(nue->info == NULL)
            {
                free(nue);
                return 0;
            }
            nue->tam = bytesDato;
            memcpy(nue->info, dato,bytesDato);
            nue->sig = act->sig;
            act->sig = nue;
            return 1;
        }
    }
    else //CASO INSERCION ANTES DEL PRIMERO
    {
        act = *p;
        while(act->sig != *p)
        {
            act = act->sig;
        }

        if(cmp(dato,act->sig->info)==0 && duplicados == NODUP)
            return 0;
        else
        {
            nue = malloc(sizeof(tNodo));
            if(nue == NULL)
            {
                return 0;
            }
            nue->info = malloc(bytesDato);
            if(nue->info == NULL)
            {
                free(nue);
                return 0;
            }
            nue->tam = bytesDato;
            memcpy(nue->info, dato,bytesDato);
            act->sig = nue;
            nue->sig = *p;
            *p = nue;
            return 1;
        }
    }
}
int eliminarPrimeroDeListaCircular(tLista* p, void* buffer, unsigned bytesDato)
{
    tNodo* act = *p;

    //CASO LISTA VACIA
    if(*p == NULL)
    {
        return 0;
    }
    //CASO LISTA DE UN ELEMENTO
    if((*p)->sig == *p)
    {
        memcpy(buffer,(*p)->info,MIN((*p)->tam,bytesDato));
        free((*p)->info);
        free(*p);
        *p = NULL;
        return 1;
    }
    //CASO LISTA CON MAS DE UN ELEMENTO
    while(act->sig != *p)
    {
        act = act->sig;
    }
    memcpy(buffer,(*p)->info,MIN((*p)->tam,bytesDato));
    act->sig = act->sig->sig;
    free((*p)->info);
    free(*p);
    *p = act->sig;
    return 1;
}
int eliminarUltimoDeListaCircular(tLista* p, void* buffer, unsigned bytesDato)
{
    tNodo *ant, *act;

    //CASO LISTA VACIA
    if(*p == NULL)
    {
        return 0;
    }
    //CASO LISTA DE UN ELEMENTO
    if((*p)->sig == *p)
    {
        memcpy(buffer,(*p)->info,MIN((*p)->tam,bytesDato));
        free((*p)->info);
        free(*p);
        *p = NULL;
        return 1;
    }
    ant = NULL;
    act = *p;
    while(act->sig != *p)
    {
        ant = act;
        act = act->sig;
    }
    ant->sig = act->sig;
    memcpy(buffer,act->info,MIN(act->tam,bytesDato));
    free(act->info);
    free(act);

    return 1;
}
int eliminarPrimeraAparicionDeListaCircular(tLista* p, void* clave, unsigned bytesDato, int cmp(const void* a, const void* b))
{
    tNodo *ant,*act;

    //CASO LISTA VACIA
    if(*p == NULL)
    {
        return 0;
    }
    //CASO LISTA DE UN ELEMENTO
    if((*p)->sig == *p && cmp((*p)->info,clave) == 0)
    {
        memcpy(clave,(*p)->info,MIN((*p)->tam,bytesDato));
        free((*p)->info);
        free(*p);
        *p = NULL;
        return 1;
    }
    //CASO LISTA CON MAS DE UN ELEMENTO
    ant = NULL;
    act = *p;
    while(act->sig != *p && cmp(act->info,clave) != 0)
    {
        ant = act;
        act = act->sig;
    }
    //CASO LISTA CON MAS DE UN ELEMENTO PERO SE BORRA EL PRIMER ELEMENTO
    if(act == *p && cmp((*p)->info,clave) == 0)
    {
        while(act->sig != *p)
        {
            act = act->sig;
        }
        memcpy(clave,(*p)->info,MIN((*p)->tam,bytesDato));
        act->sig = (*p)->sig;
        free((*p)->info);
        free(*p);
        *p = act->sig;
        return 1;
    }
    if(cmp(act->info,clave)==0)
    {
        memcpy(clave,act->info,MIN(act->tam,bytesDato));
        ant->sig = act->sig;
        free(act->info);
        free(act);
        return 1;
    }
    //CASO LISTA SIN EL ELEMENTO CLAVE
    return 0;
}
int eliminarTodasAparicionesDeListaCircular(tLista* p, void* clave, unsigned bytesDato, int cmp(const void* a, const void* b))
{
    return 1;
}
int eliminarDuplicadosDeListaCircular(tLista* p, void* clave, unsigned bytesDato, int cmp(const void* a, const void* b))
{
    return 1;
}
int vaciarListaCircular(tLista* p)
{
    tNodo *act, *auxElim;

    if(*p == NULL)
    {
        return 1;
    }

    act = (*p)->sig;
    while(act != *p)
    {
        auxElim = act->sig;
        free(act->info);
        free(act);
        act = auxElim;
    }

    free(act->info);
    free(act);
    *p = NULL;

    return 1;
}
void* buscarEnListaCircularDesordenada(const tLista* p, void* clave, unsigned bytesDato, int cmp(const void* a, const void* b))
{

}
void* buscarEnListaCircularOrdenada(const tLista* p, void* clave, unsigned bytesDato, int cmp(const void* a, const void* b))
{

}

void ordenarListaCircularPorSeleccion(tLista* lista, int cmp(const void* a,const void* b),int sentido)
{

}
tNodo* buscarMenorEnListaCircular(const tNodo* nodoInicial,int cmp(const void*, const void*),int sentido)
{

}
void intercambiarInfoDeNodos(void** a, void** b)
{

}
int recorrerListaCircular(tLista* p, void accion(void* a, void* b))
{
    tNodo* act = *p;
    if(*p == NULL)
    {
        return 0;
    }

    do{
        accion(act->info,NULL);
        act = act->sig;
    }while(act != *p);

    return 1;
}
//void filtrarListaCircular(tLista* p, ...);
//void reducirListaCircular(tLista*p, ...);
///////////////////////////////////////COLA CIRCULAR/////////////////////////////////////////////////
void crearColaCircular(tLista *p)
{
    *p = NULL;
}
int ponerEnColaCircular(tLista *p,void*info,unsigned tam)
{
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
    {
        return 0;
    }
    nue->info =malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    if (*p == NULL)
    {
        nue->sig = nue;
    }
    else
    {
        nue->sig = (*p)->sig;
        (*p)->sig = nue;
    }
    memcpy(nue->info,info,tam);
    *p = nue;
    nue->tam = tam;
    return 1;
}
int sacarDeColaCircular(tLista *p,void*buffer,unsigned tam)
{
    tNodo*aux;
    if ((*p) == NULL || (*p)->sig == NULL)
    {
        return 0;
    }

    aux = (*p)->sig;
    memcpy(buffer,aux->info,MIN(tam,aux->tam));

    if(*p == aux)
    {
        *p = NULL;
    }
    else
    {
        (*p)->sig = aux->sig;
    }

    free(aux->info);
    free(aux);

        return 1;
}
int verPrimeroEnColaCircular(const tLista* p,void* buffer,unsigned tam)
{
    if((*p)->sig == NULL)
    {
        return 0;
    }
    memcpy(buffer,(*p)->sig->info,MIN(tam,(*p)->sig->tam));

    return 1;
}
int esColaCircularVacia(const tLista* p)
{
    return *p == NULL;
}
int esColaCircularLlena(const tLista* p, unsigned tam)
{
    tNodo* aux = (tNodo*)malloc(sizeof(tNodo));
    if(aux == NULL)
    {
        return 1;
    }

    aux->info = malloc(sizeof(tam));
    if(aux->info == NULL)
    {
        return 1;
    }

    free(aux->info);
    free(aux);
    return 0;
}
void vaciarColaCircular(tLista* p)
{
    tNodo* auxElim;
    while(*p)
    {
        auxElim = (*p)->sig;

        if(*p == auxElim)
        {
            *p = NULL;
        }
        else
        {
            (*p)->sig = auxElim->sig;
        }

        free(auxElim->info);
        free(auxElim);
    }
}

///////////////////////////////////////PILA CIRCULAR/////////////////////////////////////////////////
void crearPilaCircular(tLista *p)
{
    *p = NULL;
}
int ponerEnPilaCircular(tLista *p,void*info,unsigned tam)
{
    tNodo *nue = (tNodo*) malloc(sizeof(tNodo));
    if(!nue)
    {
        return 0;
    }
    nue->info =malloc(tam);
    if(!nue->info)
    {
        free(nue);
        return 0;
    }

    if (*p == NULL)
    {
        nue->sig = nue;
        *p = nue;
    }
    else
    {
        nue->sig = (*p)->sig;
        (*p)->sig = nue;
    }
    memcpy(nue->info,info,tam);
    nue->tam = tam;
    return 1;
}
int sacarDePilaCircular(tLista *p,void*buffer,unsigned tam)
{
    tNodo *aux;
    if (*p == NULL)
    {
        return 0;
    }

    aux = (*p)->sig;
    memcpy(buffer,aux->info,MIN(tam,aux->tam));

    if(*p == aux)
    {
        *p = NULL;
    }
    else
    {
        (*p)->sig = aux->sig;
    }

    free(aux->info);
    free(aux);

    return 1;
}
int verTopeDePilaCircular(const tLista* p,void* buffer,unsigned tam)
{
    if(*p == NULL)
    {
        return 0;
    }
    memcpy(buffer,(*p)->sig->info,MIN(tam,(*p)->sig->tam));
    return 1;
}
int esPilaCircularVacia(const tLista* p)
{
    return *p == NULL;
}
int esPilaCircularLlena(const tLista* p, unsigned tam)
{
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return 1;
    }
    nue->info = malloc(tam);
    if(nue->info == NULL)
    {
        free(nue);
        return 1;
    }
    free(nue->info);
    free(nue);
    return 0;
}
void vaciarPilaCircular(tLista* p)
{
    tNodo* auxElim;
    while(*p)
    {
        auxElim = (*p)->sig;

        if(*p == auxElim)
            *p = NULL;
        else
            (*p)->sig = auxElim->sig;

        free(auxElim->info);
        free(auxElim);
    }
}
