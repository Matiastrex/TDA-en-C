#include "pilaDinamica.h"

#define MIN(X,Y) ((X)<=(Y)? (X) : (Y))
#define OPERACION_OK 0
#define SIN_MEMORIA 1
#define PILA_VACIA 2
#define PILA_NO_VACIA 3
#define PILA_LLENA 4

#define ERROR_ARCHIVO 5

void crearPila(t_pila* pila)
{
        *pila = NULL;
}
int apilar(t_pila* pila, const void* dato, unsigned tam)
{
        t_nodo* nue = (t_nodo*)malloc(sizeof(t_nodo));
        if(nue!=NULL)
        {
                nue->info=malloc(tam);
                if(nue->info==NULL)
                {
                        free(nue);
                        return 0;
                }
        }
        nue->tam = tam;
        memcpy(nue->info,dato,tam);
        nue->sig = *pila;
        *pila = nue;
        return 1;
}
int desapilar(t_pila* pila, void* dato, unsigned tam)
{
        t_nodo* elim = *pila;
        if(*pila==NULL)
        {
                return 0;
        }
        *pila = elim->sig;
        memcpy(dato,elim->info,MIN(tam,elim->tam));
        free(elim->info);
        free(elim);
        return 1;
}
int verTope(const t_pila* pila, void* dato, unsigned tam)
{
        if(*pila == NULL)
        {
                return 0;
        }
        memcpy(dato,(*pila)->info,MIN(tam,(*pila)->tam));
        return 1;
}
void vaciarPila(t_pila* pila)
{
    while(*pila)
    {
        t_nodo* aux = *pila;
        *pila = aux->sig;
        free(aux->info);
        free(aux);
    }
}
int esPilaVacia(const t_pila* pila)
{
    if(*pila == NULL)
        return 1;
    else
        return 0;
}
int esPilaLlena(const t_pila* pila, unsigned tam)
{
        t_nodo* aux = (t_nodo*)malloc(sizeof(t_nodo));
        if(aux==NULL)
        {
                return 1;
        }
        aux->info=malloc(tam);
        free(aux->info);
        free(aux);
        return (aux==NULL||aux->info==NULL);
}
int ordenarArchivoConPila(const char* path, int cmp(const void* a,const void* b), unsigned bytesRegistro, int dir)
{
    t_pila pila1;
    t_pila pila2;

    void *buffer1, *buffer2, *bufferActual;
    FILE* pf;

    pf = fopen(path,"r+b");
    if(pf == NULL)
    {
        return 0;
    }

    buffer1 = malloc(bytesRegistro);
    if(buffer1 == NULL)
    {
        fclose(pf);
        return 0;
    }

    buffer2 = malloc(bytesRegistro);
    if(buffer2 == NULL)
    {
        fclose(pf);
        free(buffer1);
        return 0;
    }

    bufferActual = malloc(bytesRegistro);
    if(bufferActual == NULL)
    {
        fclose(pf);
        free(buffer1);
        free(buffer2);
        return 0;
    }

    crearPila(&pila1);
    crearPila(&pila2);

    fread(bufferActual,bytesRegistro,1,pf);
    memcpy(buffer1,bufferActual,bytesRegistro);
    while(!feof(pf))
    {

        if((esPilaVacia(&pila1) || cmp(buffer1,bufferActual) > 0))
        {
            apilar(&pila1,bufferActual,bytesRegistro);
            memcpy(buffer1,bufferActual,bytesRegistro);
        }
        else
        {
            if(esPilaVacia(&pila2) || cmp(buffer2,bufferActual) > 0)
            {
                apilar(&pila2,bufferActual,bytesRegistro);
                memcpy(buffer2,bufferActual,bytesRegistro);
            }
            while(!esPilaVacia(&pila1) && cmp(buffer1,bufferActual) < 0)
            {
                desapilar(&pila1,buffer1,bytesRegistro);
                apilar(&pila2,buffer1,bytesRegistro);
            }
        }
        verTope(&pila2,buffer2,bytesRegistro);
        verTope(&pila1,buffer1,bytesRegistro);
        fread(bufferActual,bytesRegistro,1,pf);
    }

    rewind(pf);

    if(dir == 1)
    {
        while(!esPilaVacia(&pila2))
        {
            desapilar(&pila2,bufferActual,bytesRegistro);
            fwrite(bufferActual,bytesRegistro,1,pf);
        }
        while(!esPilaVacia(&pila1))
        {
            desapilar(&pila1,bufferActual,bytesRegistro);
            fwrite(bufferActual,bytesRegistro,1,pf);
        }
    }
    else
    {
        while(!esPilaVacia(&pila1))
        {
            desapilar(&pila1,bufferActual,bytesRegistro);
            fwrite(bufferActual,bytesRegistro,1,pf);
        }
        while(!esPilaVacia(&pila2))
        {
            desapilar(&pila2,bufferActual,bytesRegistro);
            fwrite(bufferActual,bytesRegistro,1,pf);
        }
    }

    free(buffer1);
    free(buffer2);
    free(bufferActual);
    vaciarPila(&pila1);
    vaciarPila(&pila2);
    fclose(pf);
    return 1;
}
void cargarNumero(t_pila* pila, int* numero, unsigned cantDigitos)
{
    int i = 0;
    while(i<cantDigitos)
    {
        apilar(pila,numero,sizeof(int));
        numero++;
        i++;
    }
}
void sumarNumeros(t_pila* p1, t_pila* p2, t_pila* pFinal)
{
    int buffer1;
    int buffer2;
    int aux = 0;
    int resultado = 0;

    while(esPilaVacia(p1) != PILA_VACIA && esPilaVacia(p2) != PILA_VACIA)
    {
        desapilar(p1,&buffer1,sizeof(int));
        desapilar(p2,&buffer2,sizeof(int));
        resultado = buffer1 + buffer2 + aux;
        aux = 0;

        if(resultado>9)
        {
            resultado = resultado - 10;
            aux++;
        }
        apilar(pFinal,&resultado,sizeof(int));
    }
    while(esPilaVacia(p1) != PILA_VACIA)
    {
        desapilar(p1,&buffer1,sizeof(int));
        apilar(pFinal,&buffer1,sizeof(int));
    }
    while(esPilaVacia(p2) != PILA_VACIA)
    {
        desapilar(p2,&buffer2,sizeof(int));
        apilar(pFinal,&buffer2,sizeof(int));
    }
}
void leerNumeroEnPila(t_pila* pila)
{
    int numero;
    while(esPilaVacia(pila) != PILA_VACIA)
    {
        desapilar(pila,&numero,sizeof(int));
        printf("%d",numero);
    }
}

