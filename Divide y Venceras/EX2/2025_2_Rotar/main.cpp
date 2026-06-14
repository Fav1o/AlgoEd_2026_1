#include <iostream>
#include <iomanip>
using namespace std;
int encontrarMenor(int arreglo[][2],int inicio,int fin,int &menor) {
    if (inicio > fin) return -1;
    if (inicio==fin) {
        return inicio;
    }
    int centro = (inicio + fin) / 2;
    if (arreglo[centro][0] < menor) {
        menor = arreglo[centro][0];
    }

    if (arreglo[centro][0] > arreglo[fin][0]) {
        return encontrarMenor(arreglo,centro+1,fin,menor);
    }else {
        return encontrarMenor(arreglo,inicio,centro,menor);
    }
}
int sumaCentroMaximaConsecutiva(int *riesgos,int inicio,int centro,int fin) {
    int sumaIzq = INT_MIN;
    int sumaDer = INT_MIN;
    int suma = 0;
    for (int i=centro ; i>=inicio; i--) {
        suma += riesgos[i];
        if (suma > sumaIzq) {
            sumaIzq = suma;
        }
    }
    suma = 0;
    for (int i=centro+1 ; i<=fin; i++) {
        suma += riesgos[i];
        if (suma > sumaDer) {
            sumaDer = suma;
        }
    }
    return sumaIzq + sumaDer;
}
int max(int a, int b) {
    return a > b ? a : b;
}

int sumaMaximaConsecutiva(int *riesgos,int inicio,int fin) {
    if (inicio == fin) return riesgos[inicio];
    int centro = (inicio + fin) / 2;
    int izquierda = sumaMaximaConsecutiva(riesgos,inicio,centro);
    int derecha = sumaMaximaConsecutiva(riesgos,centro+1,fin);
    int sumaCentro = sumaCentroMaximaConsecutiva(riesgos,inicio,centro,fin);

    return max(max(izquierda,derecha),sumaCentro);

}

int main() {
    cout<<endl<<endl<<" --------------------------------- Caso de prueba 1 ---------------------------------"<<endl;
    int arreglo1[8][2] = {
        {50, 4},
        {60, -1},
        {70, 3},
        {80, -2},
        {10, -4},
        {20, 5},
        {30, 1},
        {40, -2}
    };
    int filas1 = sizeof(arreglo1) / sizeof(arreglo1[0]);
    int menor1 = 9999;
    int posMenor1 = encontrarMenor(arreglo1,0,filas1-1,menor1);
    cout<<"Posicion inicial original : "<<posMenor1<<" cuyo valor es : "<<menor1<<endl;

    int riesgos[filas1]{};
    for (int i = 0; i < filas1; i++) {
        int posReal = (posMenor1 + i) % filas1;

        riesgos[i] = arreglo1[posReal][1];
        // cout << arreglo1[posReal][0] << " " << arreglo1[posReal][1] << endl;
    }

    int sumMax = sumaMaximaConsecutiva(riesgos,0,filas1-1);
    cout<<"Maxima acumulacion de riesgo en un intervalo continuo : "<<sumMax<<endl;

    cout<<endl<<endl<<" --------------------------------- Caso de prueba 2 ---------------------------------"<<endl;
    int arreglo2[9][2] = {
        {80, -4},
        {90, -2},
        {10, 1},
        {20, -3},
        {30, 6},
        {40, -8}, {50, 5}, {60, 2}, {70, -1}};
    int filas2 = sizeof(arreglo2) / sizeof(arreglo2[0]);
    int menor2 = 9999;
    int posMenor2 = encontrarMenor(arreglo2,0,filas2-1,menor2);
    cout<<"Posicion inicial original : "<<posMenor2<<" cuyo valor es : "<<menor2<<endl;

    int riesgos2[filas2];
    int k = 0;

    for (int i = posMenor2; i < filas2; i++)
        riesgos2[k++] = arreglo2[i][1];

    for (int i = 0; i < posMenor2; i++)
        riesgos2[k++] = arreglo2[i][1];

    int sumMax2 = sumaMaximaConsecutiva(riesgos2,0,filas2-1);
    cout<<"Maxima acumulacion de riesgo en un intervalo continuo : "<<sumMax2<<endl;
    return 0;
}