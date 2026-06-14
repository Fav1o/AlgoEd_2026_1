//
// Created by FAV1O on 4/06/2026.
//

#ifndef EJERCICIOSSEPARATA_FUNCIONES_H
#define EJERCICIOSSEPARATA_FUNCIONES_H
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

void imprime(int *arreglo,int longitud);

void buscaSoloVoid(int *arreglo,int inicio, int fin);
int buscaSoloEntero(int *arreglo,int inicio, int fin);
int buscaSoloEnTriples(int *arreglo,int inicio, int fin);
int cuentaCeros(int *arreglo,int inicio,int fin,int contCeros);
int cuentaUnos(int *arreglo,int inicio,int fin,int contCeros);
int buscaMenor(int *arreglo,int inicio,int fin);

int sumaMaximaConsecutiva(int *arreglo, int inicio, int fin);
int sumaCentroMaximaConsecutiva(int *arreglo, int inicio, int centro ,int fin) ;
int buscaMontana(int *arreglo,int inicio, int fin);
int buscaValle(int *arreglo,int inicio, int fin);
int numeroInversiones(int *arreglo,int inicio, int fin) ;
int mergeInversiones(int * arreglo, int inicio, int centro, int fin);
#endif //EJERCICIOSSEPARATA_FUNCIONES_H