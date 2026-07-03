#include <iostream>
#include <iomanip>
using namespace std;
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"



int main() {
    ArbolBinarioBusqueda arbol;
    construir(arbol);

    /*Insertar uno a uno los nodos de un ABB*/
    insertar(arbol, {100});
    insertar(arbol, {50});
    insertar(arbol, {150});
    insertar(arbol, {125});
    insertar(arbol, {175});
    insertar(arbol, {200});
    insertar(arbol, {25});
    insertar(arbol, {75});


    cout << "Recorrer en Pre Orden: " << endl;
    //    100 50 25 75 150 125 175 200
    recorrerPreOrden(arbol); cout<<endl;

    cout << "Recorrer en Orden: " << endl;
    //    25   50   75  100  125  150  175  200
    recorrerEnOrden(arbol); cout<<endl;

    cout << "Recorrer en Post Orden: " << endl;
    //    25   50   75  100  125  150  175  200
    recorrerPostOrden(arbol); cout<<endl;
    cout<<endl<<endl<<endl;


    struct ArbolBinarioBusqueda arbolABB;
    construir(arbolABB);

    int arreglo[]{25, 50, 75, 100, 125, 150, 175, 200};
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int inicio = 0, fin = n;
    llenarArbol(arbolABB, arreglo, inicio, fin-1);

    cout << "Recorrer en Orden: " << endl;
    //    25   50   75  100  125  150  175  200
    recorrerEnOrden(arbolABB); cout<<endl;



    /*Función de busqueda*/
    cout<<"Se encuentra 125 en arbol: "<<buscar(arbolABB, {200})<<endl;


    eliminar(arbolABB, {175});
    eliminar(arbolABB, {25});
    eliminar(arbolABB, {150});
    eliminar(arbolABB, {100});

    cout << "Recorrer en Orden despues del borrado: " << endl;
    // //     50   75  125  200
    recorrerEnOrden(arbolABB); cout<<endl;



    cout <<endl << endl << "Otro casos con Iterativas colas y pilas"<<endl;

    struct ArbolBinarioBusqueda arbolabb;
    construir(arbolabb);

    ElementoArbolBinarioBusqueda arreglo1[]{
        {25,'A'},
        {30,'B'},
        {37,'C'},
        {10,'D'},
        {100,'E'},
        {13,'G'},
        {25,'H'},
        {33,'I'},
        {8,'J'},
        {150,'K'},
        {140,'K'},
    };
    int n1= sizeof(arreglo1) / sizeof(arreglo1[0]);

    // insertar por metodo de divide y venceras
    for (int i=0 ; i<n1 ; i++) {
        insertar(arbolabb,arreglo1[i]);
    }
    // llenarABB(arbolabb,arreglo1,0,n1-1);

    //recorrer por iterativas
    recorrerPreOrden(arbolabb);
    cout<<endl;
    recorrerPreOrdenIterativo(arbolabb);
    cout<<endl<<endl<<endl;
    recorrerEnOrden(arbolabb);
    cout<<endl;
    recorrerEnOrdenIterativo(arbolabb);
    return 0;
}