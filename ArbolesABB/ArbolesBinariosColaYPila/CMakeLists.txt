cmake_minimum_required(VERSION 4.0)
project(ArbolesBinariosColaYPila)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArbolesBinariosColaYPila main.cpp
        BibliotecaPila/Pila.h
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaCola/Cola.h
        BibliotecaCola/funcionesCola.h
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/ElementoCola.h
        BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp)
