cmake_minimum_required(VERSION 4.0)
project(ArbolesBinariosTeoria)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArbolesBinariosTeoria main.cpp
        BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/ElementoCola.h
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/funcionesPila.cpp)
