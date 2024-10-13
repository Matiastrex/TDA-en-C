#include "funcionesFecha.h"

void ingresarTFecha(TFecha* f)
{
    puts("Ingresar una TFecha(D/M/A):");
    scanf("%d/%d/%d",&f->d,&f->m,&f->a);
    while(!esTFechaValida(f))
    {
        puts("TFecha invalida. Ingrese nuevamente");
        scanf("%d/%d/%d",&f->d,&f->m,&f->a);
    }
}

bool esTFechaValida(const TFecha* TFecha)
{
    if(TFecha->a>=1601)
        if(TFecha->m>=1 && TFecha->m<=12)
            if(TFecha->d>=1 && TFecha->d<=cantDiasMes(TFecha->m,TFecha->a))
                return true;
    return false;
}

int cantDiasMes(int m, int a)
{
    int dm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2 && esBisiesto(a))
        return 29;
    return dm[m];
}

bool esBisiesto(int anio)
{
    return anio%4==0 && (anio%100!=0 || anio%400==0);
}

TFecha sumarDiasATFecha(const TFecha* f, int dias)
{
    int cd;
    TFecha fs = *f;
    fs.d+=dias;
    while(fs.d>(cd=cantDiasMes(fs.m,fs.a)))
    {
        fs.d-=cd;
        fs.m++;
        if(fs.m>12)
        {
            fs.m=1;
            fs.a++;
        }
    }
    return fs;
}

void mostrarTFecha( TFecha* f)
{
    puts("\n La TFecha resultante es: ");
    printf("%d/%d/%d",f->d,f->m,f->a);
}

TFecha restarDiasATFecha(const TFecha* f, int dias)
{
    int cd;
    TFecha fr = *f;
    fr.d-=dias;
    if(fr.m<2)
        cd=cantDiasMes(12,fr.a-1);
    else
        cd=cantDiasMes(fr.m-1,fr.a);
    while(fr.d<1)
    {
        fr.m--;
        fr.d+=cd;
        if(fr.m<1)
        {
            fr.a--;
            fr.m=12;
        }
        if(fr.m<2)
        cd=cantDiasMes(12,fr.a-1);
        else
        cd=cantDiasMes(fr.m-1,fr.a);
    }
    return fr;
}
TFecha restarAniosATFecha(const TFecha* f, int anios)
{
    int diasAnio;
    TFecha fr = *f;
    while(anios>0)
    {
        diasAnio=esBisiesto(fr.a)? 366 : 365;
        fr=restarDiasATFecha(&fr,diasAnio);
        anios--;
    }
    return fr;
}
int compararTFecha(const TFecha* f1,const TFecha* f2)
{
    if(f1->a>f2->a)
        return 1;
    if(f1->a<f2->a)
        return -1;
    if(f1->m>f2->m)
        return 1;
    if(f1->m<f2->m)
        return -1;
    if(f1->d>f2->d)
        return 1;
    if(f1->d<f2->d)
        return -1;
    return 0;
}
