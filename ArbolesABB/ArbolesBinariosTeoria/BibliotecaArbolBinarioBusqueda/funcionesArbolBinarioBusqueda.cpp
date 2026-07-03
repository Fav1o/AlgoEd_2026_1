//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include <fstream>
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolBinarioBusqueda.h"

using namespace std;

void insertar(struct ArbolBinarioBusqueda & arbol, const struct ElementoArbolBinarioBusqueda & elemento) {
    insertarRecursivo(arbol.raiz, elemento);
}
void insertarRecursivo(struct NodoArbolBinarioBusqueda *& raiz, const struct ElementoArbolBinarioBusqueda & elemento){
    if(esNodoVacio(raiz))
        plantarNodoArbolBinario(raiz, nullptr, elemento, nullptr);
    else
        if(raiz->elemento.numero > elemento.numero)
            insertarRecursivo(raiz->izquierda, elemento);
        else
            if(raiz->elemento.numero < elemento.numero)
                insertarRecursivo(raiz->derecha, elemento);
            else
                cout << "El elemento " << elemento.numero << "Ya se encuentra en el arbol" << endl;
}

void llenarArbol(struct ArbolBinarioBusqueda &arbol, int *arreglo, int inicio, int fin) {

    llenarArbolRecursivo(arbol.raiz, arreglo, inicio, fin);
}

void llenarArbolRecursivo(struct NodoArbolBinarioBusqueda *&nodo, int *arreglo, int inicio, int fin) {
    //Lo vamos a llenar con la estrategia de divide y vencerÃ¡s
    if (inicio > fin) return;
    int centro = (inicio + fin) / 2;
    plantarNodoArbolBinario(nodo, nullptr, {arreglo[centro]}, nullptr);
    llenarArbolRecursivo(nodo->izquierda, arreglo, inicio, centro-1);
    llenarArbolRecursivo(nodo->derecha, arreglo, centro +1 , fin);

}
int comparaElementos(int elementoA, int elementoB){
    if(elementoA == elementoB) return 0;
    else if(elementoA < elementoB) return -1;
    else if(elementoA > elementoB) return 1;
}

bool buscarRecursivo(struct NodoArbolBinarioBusqueda * nodo, const struct ElementoArbolBinarioBusqueda & elemento){
    if (esNodoVacio(nodo))
        return false;
    if (nodo->elemento.numero == elemento.numero)
        return true;
    if (elemento.numero < nodo->elemento.numero)
        return buscarRecursivo(nodo->izquierda, elemento);
    else
        return buscarRecursivo(nodo->derecha, elemento);
}

bool buscar(const struct ArbolBinarioBusqueda & arbol, const struct ElementoArbolBinarioBusqueda & elemento){
    return buscarRecursivo(arbol.raiz, elemento);
}

struct NodoArbolBinarioBusqueda * minimoArbol(struct NodoArbolBinarioBusqueda * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->izquierda))
        return nodo;
    return minimoArbol(nodo->izquierda);
}

struct NodoArbolBinarioBusqueda * eliminarRecursivo(struct NodoArbolBinarioBusqueda * nodo,
                                  const struct ElementoArbolBinarioBusqueda & elemento){
    if (esNodoVacio(nodo))
        return nodo;
    //buscamos el nodo a eliminar
    if (nodo->elemento.numero > elemento.numero)
        nodo->izquierda = eliminarRecursivo(nodo->izquierda, elemento);
    else
        if (nodo->elemento.numero < elemento.numero)
            nodo->derecha = eliminarRecursivo(nodo->derecha, elemento);
        else
            if (esNodoVacio(nodo->izquierda)) {
                struct NodoArbolBinarioBusqueda * hijo = nodo->derecha;
                delete nodo;
                return hijo;
            }
            else
                if (esNodoVacio(nodo->derecha)) {
                    struct NodoArbolBinarioBusqueda * hijo = nodo->izquierda;
                    delete nodo;
                    return hijo;
                }
                else {
                    /*dos hijos*/
                     struct NodoArbolBinarioBusqueda * minNodo = minimoArbol(nodo->derecha);
                    nodo->elemento = minNodo->elemento;
                    nodo->derecha = eliminarRecursivo(nodo->derecha, minNodo->elemento);
                }
    return nodo;

}

void eliminar(struct ArbolBinarioBusqueda & arbol, const struct ElementoArbolBinarioBusqueda & elemento){
    arbol.raiz = eliminarRecursivo(arbol.raiz, elemento);
}

/*FUNCIONES DE ARBOL BINARIO
 *QUE TAMBIEN USA UN
 *ARBOL BINARIO DE BUSQUEDA*/

void construir(struct ArbolBinarioBusqueda &arbol) {
    arbol.raiz = nullptr;
}

bool esArbolVacio(const struct ArbolBinarioBusqueda &nodo) {
    return nodo.raiz == nullptr;
}

bool esNodoVacio(const struct NodoArbolBinarioBusqueda *nodo) {
    return nodo == nullptr;
}

void plantarArbolBinario(struct ArbolBinarioBusqueda &arbol, const struct ArbolBinarioBusqueda &izquierda,
               const struct ElementoArbolBinarioBusqueda &elemento, const struct ArbolBinarioBusqueda &derecha) {

    plantarNodoArbolBinario(arbol.raiz, izquierda.raiz, elemento, derecha.raiz);
}

void plantarNodoArbolBinario(struct NodoArbolBinarioBusqueda *&nodo, struct NodoArbolBinarioBusqueda *izquierda,
    const struct ElementoArbolBinarioBusqueda &elemento, struct NodoArbolBinarioBusqueda *derecha) {
    struct NodoArbolBinarioBusqueda *nuevo = new struct NodoArbolBinarioBusqueda;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nodo = nuevo;
}

void imprimirNodo(struct NodoArbolBinarioBusqueda *raiz) {
    cout << setw(5) << raiz->elemento.numero;
}

void recorrerPreOrden(const struct ArbolBinarioBusqueda &arbol) {
    recorrerPreOrdenRecursivo(arbol.raiz);
}

void recorrerPreOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (not esNodoVacio(nodo)) {
        imprimirNodo(nodo);
        recorrerPreOrdenRecursivo(nodo->izquierda);
        recorrerPreOrdenRecursivo(nodo->derecha);
    }
}

void recorrerEnOrden(const struct ArbolBinarioBusqueda &arbol) {
    recorrerEnOrdenRecursivo(arbol.raiz);
}

/*Va mostrar el Ã¡rbol en orden */
void recorrerEnOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerEnOrdenRecursivo(nodo->izquierda);
        imprimirNodo(nodo);
        recorrerEnOrdenRecursivo(nodo->derecha);
    }
}

void recorrerPostOrden(const struct ArbolBinarioBusqueda &arbol) {
    recorrerPostOrdenRecursivo(arbol.raiz);
}

void recorrerPostOrdenRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (not esNodoVacio(nodo)) {
        recorrerPostOrdenRecursivo(nodo->izquierda);
        recorrerPostOrdenRecursivo(nodo->derecha);
        imprimirNodo(nodo);
    }
}

int numeroHojas(const struct ArbolBinarioBusqueda &arbol) {
    return numeroHojasRecursivo(arbol.raiz);
}

int numeroHojasRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else if (esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return numeroHojasRecursivo(nodo->izquierda) + numeroHojasRecursivo(nodo->derecha);
}


int numeroNodos(const struct ArbolBinarioBusqueda &arbol) {
    return numeroNodosRecursivo(arbol.raiz);
}

int numeroNodosRecursivo(struct NodoArbolBinarioBusqueda *nodo) {
    if (esNodoVacio(nodo))
        return 0;
    else
        return 1 + numeroNodosRecursivo(nodo->izquierda) + numeroNodosRecursivo(nodo->derecha);
}

int altura(const struct ArbolBinarioBusqueda & arbol){
       return alturaRecursivo(arbol.raiz);
}

int alturaRecursivo(struct NodoArbolBinarioBusqueda * nodo){
    if(esNodoVacio(nodo))
        return 0;
    else if(esNodoVacio(nodo->izquierda) and esNodoVacio(nodo->derecha))
        return 1;
    else
        return 1 + maximo(alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int maximo(int a, int b){
    return a >= b ? a : b;
}

bool esEquilibrado(const struct ArbolBinarioBusqueda & arbol){
    return esEquilibradoRecursivo(arbol.raiz);
}

bool esEquilibradoRecursivo(struct NodoArbolBinarioBusqueda * nodo){
    if(esNodoVacio(nodo))
        return true;
    else{
        int alturaHijoIzquierdo = alturaRecursivo(nodo->izquierda);
        int alturaHijoDerecho = alturaRecursivo(nodo->derecha);
        int diferencia = abs(alturaHijoIzquierdo - alturaHijoDerecho);
        return diferencia <=1 and esEquilibradoRecursivo(nodo->izquierda) and
                esEquilibradoRecursivo(nodo->derecha);
    }
}

void destruirArbolBinario(struct ArbolBinarioBusqueda & arbol){
    destruirRecursivo(arbol.raiz);
    arbol.raiz = nullptr;
}

void destruirRecursivo(struct NodoArbolBinarioBusqueda * nodo){
    if(not (esNodoVacio(nodo))){
        destruirRecursivo(nodo->izquierda);
        destruirRecursivo(nodo->derecha);
        delete nodo;
    }
}


//nuevas funciones
void llenarABB(ArbolBinarioBusqueda &arbol,ElementoArbolBinarioBusqueda *arreglo,int inicio,int fin) {
    llenarABBRecursivo(arbol.raiz,arreglo,inicio,fin);
}

void llenarABBRecursivo(NodoArbolBinarioBusqueda *&nodo,ElementoArbolBinarioBusqueda *arreglo,int inicio,int fin) {
    if (inicio > fin) {
        return;
    }
    int medio = (inicio+fin)/2;
    plantarNodoArbolBinario(nodo,nullptr,arreglo[medio],nullptr);
    llenarABBRecursivo(nodo->izquierda,arreglo,inicio,medio-1);
    llenarABBRecursivo(nodo->derecha,arreglo,medio+1,fin);
}

void recorrerPreOrdenIterativo(const struct ArbolBinarioBusqueda &arbol) {
    struct Pila pila; // Se usará pila para acceder a los nodos
    construir(pila);
    if (not esArbolVacio(arbol)) {
        apilar(pila,arbol.raiz);
        while (not esPilaVacia(pila)) {
            struct NodoArbolBinarioBusqueda *nodo = desapilar(pila);
            imprimirNodo(nodo);
            if (not esNodoVacio(nodo->derecha)) {
                apilar(pila,nodo->derecha);
            }
            if (not esNodoVacio(nodo->izquierda)) {
                apilar(pila,nodo->izquierda);
            }
        }
    }
    destruir(pila);
}

void recorrerEnOrdenIterativo(const struct ArbolBinarioBusqueda &arbol) {
    struct Pila pila;
    construir(pila);
    int fin=0;
    struct NodoArbolBinarioBusqueda *nodo = arbol.raiz;
    do {
        while (not esNodoVacio(nodo)) {
            apilar(pila,nodo);
            nodo = nodo->izquierda;
        }
        if (esPilaVacia(pila)) {
            fin = 1;
        }else {
            nodo = desapilar(pila);
            imprimirNodo(nodo);
            nodo = nodo->derecha;
        }

    }while (fin == 0);
    destruir(pila);
}