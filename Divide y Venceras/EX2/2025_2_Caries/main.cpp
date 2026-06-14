#include <iostream>
#include <iomanip>
using namespace std;

int detectaCaries(int *arreglo,int inicio ,int fin,int umbral) {

    if (inicio > fin) {
        return -1;
    }

    if (arreglo[inicio] < umbral) {
        return inicio;
    }

    int centro =(inicio+fin) / 2;

    if (arreglo[centro] > umbral) {
        return detectaCaries(arreglo,centro+1,fin,umbral);
    }else {
        return detectaCaries(arreglo,inicio,centro,umbral);
    }

}
int main() {
    int arreglo1[] = {98,95,93,90,72,60,55,50};
    int longitud1 = sizeof(arreglo1)/sizeof(arreglo1[0]);

    int umbral = 80;

    int detecto  = detectaCaries(arreglo1,0,longitud1-1,umbral);
    if (detecto != -1) {
        cout<<"Densidad Registrada : "<<arreglo1[detecto]<<" en la posicion : "<<detecto<<endl;
    }else {
        cout<<"No se detecto caries clínica "<<endl;
    }

    int arreglo2[] = {98,95,93,90,72,60,55,50};
    int longitud2 = sizeof(arreglo2)/sizeof(arreglo2[0]);

   umbral = 40;

    int detecto2  = detectaCaries(arreglo2,0,longitud2-1,umbral);
    if (detecto2 != -1) {
        cout<<"Densidad Registrada : "<<arreglo2[detecto2]<<" en la posicion : "<<detecto2<<endl;
    }else {
        cout<<"No se detecto caries clinica "<<endl;
    }


    int arreglo3[] = {70,65,55,52,50,48,40,30};
    int longitud3 = sizeof(arreglo3)/sizeof(arreglo3[0]);

    umbral =33;
    int detecto3  = detectaCaries(arreglo3,0,longitud3-1,umbral);
    if (detecto3 != -1) {
        cout<<"Densidad Registrada : "<<arreglo3[detecto3]<<" en la posicion : "<<detecto3<<endl;
    }else {
        cout<<"No se detecto caries clinica "<<endl;
    }


    return 0;
}
