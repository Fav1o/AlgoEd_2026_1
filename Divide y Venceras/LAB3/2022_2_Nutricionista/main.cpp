#include <iostream>
#include <iomanip>
using namespace std;

void mergeSort(int *arreglo,int inicio, int fin);
void merge(int *arreglo,int inicio,int medio, int fin);
void imprimir(int *arreglo,int size);
int buscaMenor(int *arreglo,int inicio,int fin);

void buscarConsecutivos(int *arreglo, int inicio, int fin, int menor,
                        int &maxCant, int &diaIni, int &diaFin);

int main() {

    int arreglo[] = {98,95, 92, 89, 91, 92, 89, 89, 92, 93, 94, 92, 91, 90, 88, 88, 88, 89, 90, 91, 88, 88, 90, 90, 92, 89, 90, 88, 90, 91};
    int longitud = sizeof(arreglo)/sizeof(arreglo[0]);
    int copia[longitud];

    for (int i = 0; i < longitud; i++) {
        copia[i] = arreglo[i];
    }

    mergeSort(copia, 0, longitud - 1);
    //Inciso B -- Determinar el menor peso que logro en sus evaluaciones
    //Primero Hacer un Merge Sort
    //Luego Hacer un buscaMenor
    imprimir(copia,longitud);
    int menor = buscaMenor(arreglo,0,longitud-1);
    cout<<"El menor peso que logro fue de :"<<menor<<endl;

    //Inciso C -- Determinar la cantidad de días consecutivos que logro su menor peso y el rango de días
    int maxCant = 0;
    int diaIni = -1;
    int diaFin = -1;

    buscarConsecutivos(arreglo, 0, longitud - 1, menor,
                       maxCant, diaIni, diaFin);

    cout << "La cantidad de dias consecutivos fue: " << maxCant << endl;
    cout << "El rango de dias fue del "
         << diaIni + 1 << " al " << diaFin + 1 << endl;
    return 0;
}

void buscarConsecutivos(int *arreglo, int inicio, int fin, int menor,
                        int &maxCant, int &diaIni, int &diaFin) {
    if (inicio>fin) return;



}

int buscaMenor(int *arreglo,int inicio,int fin) {
    if (inicio > fin ) return -1;

    if (inicio == fin) {
        return arreglo[inicio];
    }
    int medio = (inicio+fin)/2;

    if (arreglo[medio] <= arreglo[fin]) {
        return buscaMenor(arreglo,inicio,medio);
    }else {
        return buscaMenor(arreglo,medio+1,fin);
    }
}
void imprimir(int *arreglo,int size) {
    for (int i=0 ; i<size; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

void mergeSort(int *arreglo,int inicio, int fin) {
    if (inicio == fin) return ;
    int medio = (inicio+fin)/2;

    mergeSort(arreglo,inicio,medio);

    mergeSort(arreglo,medio+1,fin);

    merge(arreglo,inicio,medio,fin);

}

void merge(int *arreglo,int inicio,int medio, int fin) {
    int size = fin - inicio + 1;
    int temp[size];
    for (int i = 0; i < size; i++) {
        temp[i]  = arreglo[inicio + i];
    }


    int izquierda = 0;
    int derecha = medio - inicio + 1;

    for (int indice = 0; indice < size; indice++) {
        if (derecha <= fin - inicio) {
            if (izquierda <= medio - inicio) {
                if (temp[izquierda] > temp[derecha]) {
                    arreglo[inicio + indice] = temp[derecha++];
                }else {
                    arreglo[inicio + indice] = temp[izquierda++];
                }
            }else {
                arreglo[inicio + indice] = temp[derecha++];
            }
        }else {
            arreglo[inicio + indice] = temp[izquierda++];
        }
    }
}