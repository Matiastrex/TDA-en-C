#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "pilaDinamica.h"
#include "producto.h"
int menu(const char* path, void funcion(const void* a), unsigned bytesRegistro);

#endif // MENU_H_INCLUDED
