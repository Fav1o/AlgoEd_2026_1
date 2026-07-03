#include <iostream>
#include <iomanip>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaCola/Cola.h"
using namespace std;

int main() {
    ArbolBinarioBusqueda abecedario;
    construir(abecedario);
    struct ElementoArbolBinarioBusqueda arreglo[] {
        { 25, 'A'},
        { 50, 'B'},
        { 80, 'C'},
        {100, 'D'},
        {120, 'E'},
        {150, 'F'},
        {200, 'G'}
    };
    int n = sizeof(arreglo)/sizeof(arreglo[0]);
    construir(abecedario);
    //para rellenar arboles ABB
    // for (int i = 0; i < n; i++) {
    //     insertar(abecedario, arreglo[i]);
    // }

    llenarArbol(abecedario,arreglo,0,n-1);

    cout<<" Recorrer En Order: " << endl;
    recorrerEnOrden(abecedario);
    cout<<endl;

    // cout << "Recorrer en pre orden: " << endl;
    // recorrerPreOrden(abecedario);
    // cout << endl;
    //
    // cout << "Recorrer en Post orden: " << endl;
    // recorrerPostOrden(abecedario);
    cout << endl<< endl<< endl<< endl;

    cout << endl; //Función que me deja sin arbol
    cout << "Imprimir en orden Iterativo usando una pila y apilando el nodo del arbol: " << endl;
    enOrdenIterativo(abcedario);

    return 0;
}