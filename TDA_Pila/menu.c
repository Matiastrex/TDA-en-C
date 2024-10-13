#include "menu.h"
#include "pilaDinamica.c"
int menu(const char* path, void funcion(const void* a), unsigned bytesRegistro)
{
    t_pila pila;
    void* buffer;
    FILE* pf = fopen(path,"rb");
    if(!pf)
    {
        return ERROR_ARCHIVO;
    }
    buffer = malloc(bytesRegistro);
    if(!buffer)
    {
        fclose(pf);
        return SIN_MEMORIA;
    }

    crearPila(&pila);

    fread(buffer,bytesRegistro,1,pf);
    while(!feof(pf))
    {
        apilar(&pila,buffer,bytesRegistro);
        verTope(&pila,buffer,bytesRegistro);//DEBUG
        mostrarProducto(buffer);//DEBUG

        fread(buffer,bytesRegistro,1,pf);
    }
    fclose(pf);
    return OPERACION_OK;
}
