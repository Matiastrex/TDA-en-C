#ifndef FUNCIONESTFecha_H_INCLUDED
#define FUNCIONESTFecha_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{   int d;
    int m;
    int a;
}TFecha;

void ingresarTFecha(TFecha* f);
bool esTFechaValida(const TFecha* TFecha);
int cantDiasMes(int m, int a);
bool esBisiesto(int anio);
TFecha sumarDiasATFecha(const TFecha* f, int dias);
TFecha restarDiasATFecha(const TFecha* f, int dias);
TFecha restarAniosATFecha(const TFecha* f, int anios);
int compararTFecha(const TFecha* f1, const TFecha* f2);
void mostrarTFecha( TFecha* f);

#endif // FUNCIONESTFecha_H_INCLUDED
