#include "arbolBinario.h"
void crearArbol(tArbol* arbol)
{
    *arbol = NULL;
}
void recorrerArbolPreOrden(const tArbol* arbol,void accion(void*a, void*b))
{
    if(!(*arbol))
        return;

    accion((*arbol)->info,NULL);
    recorrerArbolPreOrden(&(*arbol)->izq,accion);
    recorrerArbolPreOrden(&(*arbol)->der,accion);
}
void recorrerArbolInOrden(const tArbol* arbol,void accion(void*a, void*b))
{
    if(!(*arbol))
        return;

    recorrerArbolInOrden(&(*arbol)->izq,accion);
    accion((*arbol)->info,NULL);
    recorrerArbolInOrden(&(*arbol)->der,accion);
}
void recorrerArbolPosOrden(const tArbol* arbol,void accion(void*a, void*b))
{
    if(!(*arbol))
        return;

    recorrerArbolPosOrden(&(*arbol)->izq,accion);
    recorrerArbolPosOrden(&(*arbol)->der,accion);
    accion((*arbol)->info,NULL);
}
int insertarEnOrdenEnArbolRecursivo(tArbol* arbol, void* dato, unsigned tamDato, int cmp(void*a,void*b))
{
    tNodo* nue;
    if(*arbol == NULL)
    {
        nue = malloc(sizeof(tNodo));
        if(nue == NULL)
        {
            return 0;
        }
        nue->info = malloc(tamDato);
        if(nue->info == NULL)
        {
            free(nue);
            return 0;
        }
        memcpy(nue->info,dato,tamDato);
        nue->tamInfo = tamDato;
        nue->izq = NULL;
        nue->der = NULL;
        *arbol = nue;
        return 1;
    }
    if(*arbol)
    {
        if(cmp(dato,(*arbol)->info)>0)
            insertarEnOrdenEnArbolRecursivo(&(*arbol)->der,dato,tamDato,cmp);

        if(cmp(dato,(*arbol)->info)<0)
            insertarEnOrdenEnArbolRecursivo(&(*arbol)->izq,dato,tamDato,cmp);
    }
    return 0;
}
int insertarEnOrdenEnArbolIterativo(tArbol* arbol, void* dato, unsigned tamDato, int cmp(void*a,void*b))
{
    tNodo* nue;
    while(*arbol)
    {
        if(cmp(dato,(*arbol)->info)>0)
            arbol = &(*arbol)->der;
        else if(cmp(dato,(*arbol)->info)<0)
            arbol = &(*arbol)->izq;
        else
            return 0;
    }

    nue = malloc(sizeof(tNodo));
    if(nue == NULL)
        return 0;
    nue->info = malloc(tamDato);
    if(nue->info == NULL)
    {
        free(nue);
        return 0;
    }

    nue->tamInfo = tamDato;
    memcpy(nue->info,dato,tamDato);
    nue->izq = NULL;
    nue->der = NULL;
    *arbol = nue;
    return 1;
}
int cargarArbolConDatosOrdenados(tArbol* arbol, void* fuenteDatos, int leer (void** dato, void* fuenteDatos, unsigned cantReg, void* params), int li, int ls,void* params)
{
    int medio = (li + ls)/2;
    int r;
    if(li>ls)
        return 1;
    *arbol = (tNodo*)malloc(sizeof(tNodo));
    if(!(*arbol) || !((*arbol)->tamInfo = leer(&(*arbol)->info, fuenteDatos, medio, params)))
    {
        free(*arbol);
        return 0;
    }
    (*arbol)->izq = (*arbol)->der = NULL;
    if((r = cargarArbolConDatosOrdenados(&(*arbol)->izq, fuenteDatos, leer, li ,medio-1,params))!=1) // o != TODO BIEN
        return r;
    return cargarArbolConDatosOrdenados(&(*arbol)->der, fuenteDatos, leer, medio+1,ls,params);
}
int cargarArchivoBinarioOrdenadoEnArbol(tArbol* arbol, const char* path, unsigned tamInfo)
{
    int cantReg, r;
    FILE* pf;

    if(*arbol)
        return 0;

    pf = fopen(path,"rb");
    if(pf == NULL)
        return 0;

    fseek(pf,0L,SEEK_END);
    cantReg = ftell(pf)/tamInfo;
    r = cargarArbolConDatosOrdenados(arbol,pf,leerDesdeArchivoBinario,0,cantReg-1,&tamInfo);
    fclose(pf);
    return(r);
}
int leerDesdeArchivoBinario(void** d, void* pf, unsigned pos, void* params)
{
    unsigned tam = *(int*)params;
    *d = malloc(tam);
    if(!*d)
        return 0;
    fseek((FILE*)pf,pos*tam,SEEK_SET);
    return fread(*d, tam, 1, (FILE*)pf);
}

int cargarDesdeDatosOrdenadosArbolBinario(tArbol* arbol, void* fuenteDatos, unsigned cantReg, int leer (void** dato, void*,unsigned,void* params),void* params)
{
    if(*arbol || !fuenteDatos)
        return 0;
    return cargarArbolConDatosOrdenados(arbol, fuenteDatos, leer, 0, cantReg-1, params);
}

int contarNodosDeArbol(const tArbol* arbol)
{
    if(*arbol == NULL)
        return 0;

   return contarNodosDeArbol(&(*arbol)->izq) + contarNodosDeArbol(&(*arbol)->der) + 1;
}
int eliminarHojas(tArbol* arbol)
{
    if(*arbol)
    {
        if((*arbol)->izq == NULL && (*arbol)->der == NULL)
        {
            free((*arbol)->info);
            free((*arbol));
            (*arbol)=NULL;
            return 1;
        }
        return eliminarHojas(&(*arbol)->izq) + eliminarHojas(&(*arbol)->der);
    }
    return 0;
}
void eliminarArbol(tArbol* arbol)
{ /// tiene que ser en posorden
    if(!(*arbol)) /// me fijo si hay árbol
        return;
    if((*arbol)->izq) /// primero izq
        eliminarArbol(&((*arbol)->izq));
    if((*arbol)->der) /// desp der
        eliminarArbol(&((*arbol)->der));
    free((*arbol)->info); /// la info
    free(*arbol);
    *arbol = NULL;
}
int eliminarNodoDeArbolBinario(tArbol* arbol)
{
    tNodo *elim, **remp;
    if(!*arbol)
        return 0; ///ARBOL VACIO
    free((*arbol)->info);
    if(!(*arbol)->izq && !(*arbol)->der)
    {
        free(*arbol);
        *arbol = NULL;
        return 1; ///OK
    }
    if(alturaArbolBinario(&(*arbol)->izq) > alturaArbolBinario(&(*arbol)->der))
        remp = mayorNodoArbolBinario(&(*arbol)->izq);
    else
        remp = menorNodoArbolBinario(&(*arbol)->der);

    elim = *remp;
    (*arbol)->info = elim->info;
    (*arbol)->tamInfo = elim->tamInfo;

    if(elim->izq)
        *remp = elim->izq;
    else
        *remp = elim->der;

    free(elim);
    return 1; ///OK
}
int eliminarElementoDeArbolBinario(tArbol* arbol, void* dato, unsigned tam, int cmp (const void*, const void*))
{
    if(!(arbol = buscarNodoArbolBinario(arbol,dato,cmp)))
        return 0;
    memcpy(dato,(*arbol)->info,MINIMO(tam,(*arbol)->tamInfo));
    return eliminarNodoDeArbolBinario(arbol);
}
int buscarElementoEnArbolBinario(const tArbol* arbol, void* dato, unsigned tam, int cmp (const void*,const void*))
{
    if(!(arbol = buscarNodoArbolBinario(arbol,dato,cmp)))
        return 0;
    memcpy(dato,(*arbol)->info,MINIMO(tam,(*arbol)->tamInfo));
    return 1;
}
tArbol* buscarNodoArbolBinario(const tArbol* arbol, const void* dato, int cmp (const void*,const void*))
{
    while(*arbol)
    {
        if(cmp(dato,(*arbol)->info)<0)
            arbol =&(*arbol)->izq;
        else
            arbol =&(*arbol)->der;
    }
    if(!*arbol)
        return NULL;
    return (tArbol*)arbol;
}
tArbol* mayorNodoArbolBinario(const tArbol* arbol)
{
    if(!*arbol)
        return NULL;
    if(!(*arbol)->der)
       return (tArbol*)arbol;
    return mayorNodoArbolBinario(&(*arbol)->der);
}
tArbol* menorNodoArbolBinario(const tArbol* arbol)
{
    if(!*arbol)
        return NULL;
    if(!(*arbol)->izq)
       return (tArbol*)arbol;
    return mayorNodoArbolBinario(&(*arbol)->izq);
}
unsigned alturaArbolBinario(const tArbol* arbol)
{
    int hi,hd;
    if(!*arbol)
        return 0;
    hi = alturaArbolBinario(&(*arbol)->izq);
    hd = alturaArbolBinario(&(*arbol)->der);

    return (hi>hd ? hi : hd) + 1;
}
int cargarArbolConEnteros(tArbol* arbol,int cmp(void*a,void*b))
{
    int i,vec[]={50,125,100,75};
    for(i=0;i<sizeof(vec)/sizeof(int);i++)
    {
        insertarEnOrdenEnArbolRecursivo(arbol,&vec[i],sizeof(int),cmp);
    }
    return 1;
}
