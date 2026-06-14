//
// Created by FAV1O on 4/06/2026.
//
#include "funciones.h"

void imprime(int *arreglo,int longitud) {
    for(int i=0;i<longitud;i++) {
        cout<<arreglo[i]<<" ";
    }
    cout<<endl;

}


void buscaSoloVoid(int *arreglo,int inicio, int fin) {

    //CASO BASE
    if (inicio > fin) return;

    int centro = (inicio + fin ) / 2;
    if (inicio == fin) {
        cout<<" Busca solo con Void: "<<arreglo[centro]<<endl;
        return;
    }

    //Cuando 1 2 3 Los del costado diferentes
    if (arreglo[centro-1] != arreglo[centro] and arreglo[centro+1] != arreglo[centro]) {
        cout<<" Busca solo con Void: "<<arreglo[centro]<<endl;
        return;
    }

    if (centro % 2 == 0) { // Cuando el centro es par
        if (arreglo[centro] == arreglo[centro+1]) {
            buscaSoloVoid(arreglo,centro+2,fin);
        }else {
            buscaSoloVoid(arreglo,inicio,centro);
        }
    }else { // cuando el centro es impar
        if (arreglo[centro] == arreglo[centro-1]) {
            buscaSoloVoid(arreglo,centro+1 ,fin);
        }else {
            buscaSoloVoid(arreglo,inicio,centro-1);
        }
    }


}
int buscaSoloEntero(int *arreglo,int inicio, int fin) {
    //CASO BASE
    if (inicio > fin) return -1;

    int centro = (inicio + fin ) / 2;
    if (inicio == fin) {
        return arreglo[centro];
    }

    //Cuando 1 2 3 Los del costado diferentes
    if (arreglo[centro-1] != arreglo[centro] and arreglo[centro+1] != arreglo[centro]) {
        return arreglo[centro];
    }

    if (centro % 2 == 0) { // Cuando el centro es par
        if (arreglo[centro] == arreglo[centro+1]) {
            return buscaSoloEntero(arreglo,centro+2,fin);
        }else {
            return buscaSoloEntero(arreglo,inicio,centro);
        }
    }else { // cuando el centro es impar
        if (arreglo[centro] == arreglo[centro-1]) {
            return buscaSoloEntero(arreglo,centro+1 ,fin);
        }else {
            return buscaSoloEntero(arreglo,inicio,centro-1);
        }
    }
}

int buscaSoloEnTriples(int *arreglo,int inicio, int fin) {
    if (inicio > fin)
        return -1;

    if (inicio == fin)
        return arreglo[inicio];

    int medio = (inicio + fin) / 2;

    if (arreglo[medio-1] != arreglo[medio] and arreglo[medio+1] != arreglo[medio]) {
        return arreglo[medio];
    }

    int iniBloque = medio;

    // Primero revisa medio - 2
    if (arreglo[medio] == arreglo[medio - 2]) {
        iniBloque = medio - 2;
    }
    else if (arreglo[medio] == arreglo[medio - 1]) {
        iniBloque = medio - 1;
    }

    int cantidadIzq = iniBloque;

    if (cantidadIzq % 3 == 0)
        return buscaSoloEnTriples(arreglo, iniBloque + 3, fin);
    else {
        return buscaSoloEnTriples(arreglo, inicio, iniBloque - 1);
    }
}

int cuentaCeros(int *arreglo,int inicio,int fin,int contCeros) {
    if (inicio > fin) {
        return contCeros;
    }

    int centro = (inicio + fin) / 2;

    if (arreglo[centro] == 0) {
        //return cuentaCeros(arreglo,inicio,centro-1,contCeros+fin-centro+1);
        return cuentaCeros(arreglo,centro + 1 ,fin,centro+1);
    }else {
        return cuentaCeros(arreglo,inicio,centro -1 ,contCeros);
        // return cuentaCeros(arreglo,centro+1,fin,contCeros);
    }
}

int cuentaUnos(int *arreglo,int inicio,int fin,int contCeros) {
    if (inicio > fin) {
        return contCeros;
    }

    int centro = (inicio + fin) / 2;

    if (arreglo[centro] == 0) {
        //return cuentaCeros(arreglo,inicio,centro-1,contCeros+fin-centro+1);
        return cuentaCeros(arreglo,centro + 1 ,fin,contCeros);
    }else {
        return cuentaCeros(arreglo,inicio,centro-1 ,contCeros+fin-centro+1);
        // return cuentaCeros(arreglo,centro+1,fin,contCeros);
    }
}

int buscaMenor(int *arreglo,int inicio,int fin) {
    if (inicio == fin) return arreglo[inicio];
    int centro = (inicio + fin) / 2;

    if (centro>inicio and arreglo[centro] < arreglo[centro-1]) {
        return arreglo[centro];
    }

    //En un arreglo rotado, siempre hay dos subarreglos ordenados
    if (arreglo[centro] > arreglo[fin]) {
        return buscaMenor(arreglo,centro+1,fin);
    }else {
        return buscaMenor(arreglo,inicio,centro);
    }
}

int sumaMaximaConsecutiva(int *arreglo, int inicio, int fin) {
    if (inicio == fin) return arreglo[inicio];
    int centro = (inicio + fin) / 2;

    int izquierda = sumaMaximaConsecutiva(arreglo,inicio,centro );
    int derecha = sumaMaximaConsecutiva(arreglo,centro+1,fin);
    int sumaCentro = sumaCentroMaximaConsecutiva(arreglo,inicio,centro,fin);
    return max (max(izquierda,derecha),sumaCentro);
}

int sumaCentroMaximaConsecutiva(int *arreglo, int inicio, int centro ,int fin) {
    int suma =0;
    int sumaIzq = INT_MIN;
    int sumaDer = INT_MIN;
    for (int i=centro ; i>=inicio ; i--) {
        suma += arreglo[i];
        if (suma > sumaIzq) {
            sumaIzq = suma;
        }
    }
    suma =0;
    for (int i=centro+1 ; i<=fin ; i++) {
        suma += arreglo[i];
        if (suma > sumaDer) {
            sumaDer = suma;
        }
    }
    return sumaDer + sumaIzq;
}

int buscaMontana(int *arreglo,int inicio, int fin) {
    if (inicio == fin) return arreglo[inicio];

    int centro = (inicio + fin ) / 2;
    if (arreglo[centro] < arreglo[centro+1]) {
        return buscaMontana(arreglo,centro+1,fin);
    }else {
        return buscaMontana(arreglo,inicio,centro);
    }
}
int buscaValle(int *arreglo,int inicio, int fin) {
    if (inicio == fin) return arreglo[inicio];

    int centro = (inicio + fin ) / 2;
    if (arreglo[centro] > arreglo[centro+1]) {
        return buscaValle(arreglo,centro+1,fin);
    }else {
        return buscaValle(arreglo,inicio,centro);
    }
}

int numeroInversiones(int *arreglo,int inicio, int fin) {
    if (inicio >= fin) return 0;
    int centro = (inicio + fin) / 2;
    int ctaIzq = numeroInversiones(arreglo, inicio, centro);
    int ctaDer = numeroInversiones(arreglo, centro + 1, fin);
    int ctaCentro = mergeInversiones(arreglo, inicio, centro, fin);
    return ctaIzq + ctaDer + ctaCentro;
}

int mergeInversiones(int * arreglo, int inicio, int centro, int fin) {
    int size = fin - inicio + 1;
    int temp[size];

    // Copiar a temp
    for (int i = 0; i < size; i++) {
        temp[i] = arreglo[inicio + i];
    }

    int izquierda = 0;
    int derecha = centro - inicio + 1;
    int inversiones = 0;
    for (int indice = 0; indice < size; indice++) {
        if (derecha <= fin - inicio) { // Hay elementos en derecha
            if (izquierda <= centro - inicio) { // Hay elementos en izquierda
                if (temp[izquierda] > temp[derecha]) {
                    // ¡INVERSIÓN! temp[izquierda] > temp[derecha] con izquierda < derecha
                    // Todos los elementos restantes en izquierda también son mayores que temp[derecha]
                    inversiones +=(centro - inicio - izquierda + 1);
                    arreglo[inicio + indice] = temp[derecha++];
                } else {
                    arreglo[inicio + indice] = temp[izquierda++];
                }
            } else {
                // Solo quedan elementos en derecha
                arreglo[inicio + indice] = temp[derecha++];
            }
        } else {
            // Solo quedan elementos en izquierda
            arreglo[inicio + indice] = temp[izquierda++];
        }
    }

    return inversiones;
}