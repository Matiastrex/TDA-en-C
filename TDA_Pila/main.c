#include "producto.h"
#include "pilaDinamica.h"
void ejercicio_2_6();
//Escriba un programa que al comenzar lea (si lo puede abrir) un archivo de binario <"datos">,
//y lo cargue en una pila con implementación estática de memoria. El archivo debe ser cerrado
//al terminar la carga de la pila. A continuación, y valiéndose de una función de menú, que
//permita cargar más información en la pila, ver la información del tope de la pila, sacar de
//la pila, salir del menú. Al salir del menú, se terminará de cargar el archivo con la información
//que aún quede en la pila. Si el archivo resultara vacío, deberá ser eliminado. Pruebe
//repetidamente el programa, hasta que logre que el archivo quede con información.
void ejercicio_2_7();
//Resuelva el cálculo de la suma de dos números enteros de muchos dígitos (30 o muchos más) haciendo
//uso de dos pilas en las que almacena sólo los dígitos. Tenga en cuenta que debe utilizar una tercera
//pila en la que irá cargando los resultados parciales. Compruebe que obtiene idénticos resultados con
//ambas implementaciones de Pila (estática y dinámica).

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

