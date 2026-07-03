//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef PILA_NODOPILA_H
#define PILA_NODOPILA_H
#include "ElementoPila.h"
#include "../BibliotecaArbolBinarioBusqueda/NodoArbolBinarioBusqueda.h"
struct NodoPila {
    // struct ElementoPila elemento; /*Dato que cambia por double, char, struct */
    struct NodoArbolBinarioBusqueda * elemento;
    struct NodoPila * siguiente; /*puntero a una variable de tipo struct Nodo*/
};
#endif //PILA_NODOPILA_H