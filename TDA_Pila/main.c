#include "producto.h"
#include "pilaDinamica.h"
void ejercicio_2_6();
//Escriba un programa que al comenzar lea (si lo puede abrir) un archivo de binario <"datos">,
//y lo cargue en una pila con implementaci�n est�tica de memoria. El archivo debe ser cerrado
//al terminar la carga de la pila. A continuaci�n, y vali�ndose de una funci�n de men�, que
//permita cargar m�s informaci�n en la pila, ver la informaci�n del tope de la pila, sacar de
//la pila, salir del men�. Al salir del men�, se terminar� de cargar el archivo con la informaci�n
//que a�n quede en la pila. Si el archivo resultara vac�o, deber� ser eliminado. Pruebe
//repetidamente el programa, hasta que logre que el archivo quede con informaci�n.
void ejercicio_2_7();
//Resuelva el c�lculo de la suma de dos n�meros enteros de muchos d�gitos (30 o muchos m�s) haciendo
//uso de dos pilas en las que almacena s�lo los d�gitos. Tenga en cuenta que debe utilizar una tercera
//pila en la que ir� cargando los resultados parciales. Compruebe que obtiene id�nticos resultados con
//ambas implementaciones de Pila (est�tica y din�mica).

int main()
{
    ejercicio_2_6();
    //ejercicio_2_7();

    return 0;
}

void ejercicio_2_6()
{
    printf("ARCHIVO DE PRODUCTOS ORIGINAL\n");
    generarArchivoBinarioDeProductos("productos.dat");
    leerArchivoBinarioDeProductos("productos.dat");

    printf("ARCHIVO DE PRODUCTOS ORDENADO\n");
    ordenarArchivoConPila("productos.dat",compararProductoPorCodigo,sizeof(tProducto),1);
    leerArchivoBinarioDeProductos("productos.dat");
}
void ejercicio_2_7()
{
    t_pila p1,p2,pFinal;
    int numero1[] = {1,0,9};
    int numero2[] = {4,0,2,9};
    crearPila(&p1);
    crearPila(&p2);
    crearPila(&pFinal);
    cargarNumero(&p1,numero1,sizeof(numero1)/sizeof(int));
    cargarNumero(&p2,numero2,sizeof(numero2)/sizeof(int));
    printf("El numero final es: ");
    sumarNumeros(&p1,&p2,&pFinal);
    leerNumeroEnPila(&pFinal);
}

