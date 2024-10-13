#include "listaDoble.h"
void crearListaDoble (tLista* lista)
{
    *lista = NULL;
}
int listaDobleVacia (const tLista* lista)
{
    return *lista == NULL;
}
int listaDobleLlena (const tLista* lista, unsigned tamDato)
{
    tNodo* nue = malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return 1;
    }
    nue->info = malloc(tamDato);
    if(nue->info == NULL)
    {
        free(nue);
        return 1;
    }
    free(nue->info);
    return 0;
}
int insertarOrdenadoEnListaDoble (tLista* lista, void* dato, unsigned bytesRegistro, int duplicados, int cmp(const void* a, const void* b))
{
    tNodo *auxAnt, *auxSig, *nue;
    tNodo *act = *lista;
    if(act == NULL)
    {
        auxAnt = NULL;
        auxSig = NULL;
    }
    else
    {
        while(act->ant!=NULL && cmp(dato,act->info)<0)
            act = act->ant;
        while(act->sig!=NULL && cmp(dato,act->info)>0)
            act = act->sig;
        if(cmp(dato,act->info)>0)
        {
            auxSig = act->sig;
            auxAnt = act;
        }
        else
        {
            auxAnt = act->ant;
            auxSig = act;
        }
        if(cmp(dato,act->info)==0 && duplicados == NODUP)
            return 0;
    }
    nue = malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return 0;
    }
    nue->info = malloc(bytesRegistro);
    if(nue->info == NULL)
    {
        free(nue);
        return 0;
    }
    nue->ant = auxAnt;
    nue->sig = auxSig;
    nue->tamDato = bytesRegistro;
    memcpy(nue->info,dato,bytesRegistro);
    if(auxAnt != NULL)
    {
        auxAnt->sig = nue;
    }
    if(auxSig != NULL)
    {
        auxSig->ant = nue;
    }
    *lista = nue;
    return 1;
}
int eliminarDeListaDobleOrdenada(tLista* lista, void* clave, unsigned bytesRegistro,int cmp(const void* a, const void* b))
{
    tNodo *act = *lista;
    tNodo *auxAnt, *auxSig;
    if(act == NULL)
    {
        return 0;
    }

    while(act->ant != NULL && cmp(clave,act->info)<0)
    {
        act = act->ant;
    }
    while(act->sig != NULL && cmp(clave,act->info)>0)
    {
        act = act->sig;
    }

    if(cmp(act->info,clave)==0)
    {
        auxAnt = act->ant;
        auxSig = act->sig;

        if(auxAnt != NULL)
            auxAnt->sig = auxSig;

        if(auxSig != NULL)
        {
            auxSig->ant = auxAnt;
            *lista = auxSig;
        }
        else
        {
            *lista = auxAnt;
        }

        memcpy(clave,act->info,MIN(bytesRegistro,act->tamDato));
        free(act->info);
        free(act);

        return 1;
    }
    return 0;
}
int eliminarDeListaDobleDesordenada(tLista* lista, void* clave, unsigned bytesRegistro,int cmp(const void* a, const void* b))
{
    tNodo *act = *lista, *ini = *lista;
    tNodo  *auxAnt, *auxSig;
    if(act == NULL)
    {
        return 0;
    }
    //RECORRE LA LISTA HACIA EL FINAL
    while(act->sig != NULL && cmp(act->info,clave)!=0)
    {
        act = act->sig;
    }
    if(cmp(act->info,clave)==0)
    {
        auxAnt = act->ant;
        auxSig = act->sig;

        if(auxAnt != NULL)
        {
            auxAnt->sig = auxSig;
        }
        if(auxSig != NULL)
        {
            auxSig->ant = auxAnt;
            *lista = auxSig;
        }
        else
        {
            *lista = auxAnt;
        }
        memcpy(clave,act->info,MIN(bytesRegistro,act->tamDato));
        free(act->info);
        free(act);

        return 1;
    }
    act = ini;
     //RECORRE LA LISTA HACIA EL INICIO
    while(act->ant != NULL && cmp(act->info,clave)!=0)
    {
        act = act->ant;
    }
    if(cmp(act->info,clave)==0)
    {
        auxAnt = act->ant;
        auxSig = act->sig;

        if(auxAnt != NULL)
        {
            auxAnt->sig = auxSig;
        }
        if(auxSig != NULL)
        {
            auxSig->ant = auxAnt;
            *lista = auxSig;
        }
        else
        {
            *lista = auxAnt;
        }
        memcpy(clave,act->info,MIN(bytesRegistro,act->tamDato));
        free(act->info);
        free(act);
        return 1;
    }
    return 0;
}
void recorrerListaDobleDesdeInicio(tLista* lista, void accion(void* a, void* b))
{
    tNodo* act = *lista;
    while(act->ant != NULL)
    {
        act = act->ant;
    }
    while(act != NULL)
    {
        accion(act->info,NULL);
        act = act->sig;
    }
}
void recorrerListaDobleDesdeFinal(tLista* lista, void accion(void* a, void* b))
{
    tNodo* act = *lista;
    while(act->sig != NULL)
    {
        act = act->sig;
    }
    while(act != NULL)
    {
        accion(act->info,NULL);
        act = act->ant;
    }
}


