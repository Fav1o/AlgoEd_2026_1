
#include <iostream>
#include <iomanip>
using namespace std;

void mergeSort(int *control1,int inicio, int fin) ;
void merge(int *control1,int inicio,int medio,int fin);
void imprimir (int *control1,int size);
void buscaEmpleadoImpar(int *a,int inicio,int fin);
void buscaTrio(int *control1,int inicio,int fin);

int main() {

    //Control de acceso
    int control1[]{1, 6, 3, 4, 5, 6, 3, 7, 5, 4, 3, 1, 7};
    int n1 = sizeof(control1) / sizeof(control1[0]);

    mergeSort(control1,0,n1-1);
    imprimir(control1,n1);
    buscaTrio(control1,0,n1-1);
    buscaEmpleadoImpar(control1,0,n1-1);
    return 0;
}
void buscaTrio(int *control1,int inicio,int fin) {
    if (inicio > fin) return;
    int medio = (inicio+fin) / 2;
    if (control1[medio] == control1[medio-1] and control1[medio+1] == control1[medio]) {
        cout << "El empleado " << control1[medio] << " ingreso y no volvio a salir" << endl;
        return;
    }
    if (medio % 2 == 0) { // cuando el centro es par
        if (control1[medio] != control1[medio-1]) {
            buscaTrio(control1,medio+1,fin);
        }else {
            buscaTrio(control1,inicio,medio);
        }
    }else {
        if (control1[medio] != control1[medio+1]) {
            buscaTrio(control1,medio+1,fin);
        }else {
            buscaTrio(control1,inicio,medio);
        }
    }
}
void buscaEmpleadoImpar(int *a,int inicio,int fin) {
    // if(inicio > fin) return;
    //
    // int medio = (inicio + fin) / 2;
    //
    // int izq = medio;
    // int der = medio;
    //
    // while(izq > inicio && a[izq-1] == a[medio])
    //     izq--;
    //
    // while(der < fin && a[der+1] == a[medio])
    //     der++;
    //
    // int cantidad = der - izq + 1;
    //
    // if(cantidad % 2 != 0){
    //     cout << a[medio] << endl;
    //     return;
    // }
    //
    // if(izq % 2 == 0){
    //     buscaEmpleadoImpar(a, der + 1, fin);
    // }
    // else{
    //     buscaEmpleadoImpar(a, inicio, izq - 1);
    // }
}
void imprimir (int *control1,int size) {
    for (int i=0; i<size; i++) {
        cout << control1[i] << " ";
    }
    cout<<endl;
}


void mergeSort(int *control1,int inicio, int fin) {
    if (inicio == fin ) return;
    int medio = (inicio + fin) / 2;
    mergeSort(control1,inicio,medio);
    mergeSort(control1,medio+1,fin);
    merge(control1,inicio,medio,fin);
}

void merge(int *control1,int inicio,int medio,int fin) {
    int size = fin - inicio + 1;
    int temporal[size];
    for (int i=0; i<size ; i++) {
        temporal[i] = control1[inicio + i];
    }
    int izquierda = 0;
    int derecha = medio - inicio  + 1;

    for (int i=0; i<size ; i++) {
        if (derecha <= fin - inicio) {
            if (izquierda <= medio - inicio) {
                if (temporal[izquierda] > temporal[derecha]) {
                    control1[inicio + i] = temporal[derecha++];
                }else {
                    control1[inicio + i] = temporal[izquierda++];
                }
            }else {
                control1[inicio + i] = temporal[derecha++];
            }
        }else {
            control1[inicio + i] = temporal[izquierda++];
        }
    }
}