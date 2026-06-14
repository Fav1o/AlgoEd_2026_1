
#include "Bibliotecas/funciones.h"


int main() {

    // Encontrar el elmento que aparece una vez en varios pares
    //1,1,3,3,4,5,5,7,7,8,8
    //3,3,4,4,1,6,6,5,5 --> centro es el unico
    //1,2,2 -- cuando centro es impar
    //2,2,1

    int arreglo[] = {3,3,4,4,6,6,1,5,5};
    int longitud = sizeof(arreglo)/sizeof(arreglo[0]);
    imprime(arreglo,longitud);
    buscaSoloVoid(arreglo,0,longitud-1);
    int solo = buscaSoloEntero(arreglo,0,longitud-1);
    cout<<"Busca Solo con entero "<<solo<<endl;

    int arreglo2[] = {1,1,1,3,3,3,4,4,4,6,6,6,10};
    int longitud2 = sizeof(arreglo2)/sizeof(arreglo2[0]);
    imprime(arreglo2,longitud2);
    cout<<"Busca Solo con entero "<< buscaSoloEnTriples(arreglo2,0,longitud2-1) <<endl;


    //2. Cuenta Ceros o Cuentas 1's
    int arreglo3[] = {0,0,0,0,0,1,1,1};
    int longitud3 = sizeof(arreglo3)/sizeof(arreglo3[0]);
    imprime(arreglo3,longitud3);
    cout<<"Cantidad de 0's "<<cuentaCeros(arreglo3,0,longitud3-1,0)<<endl;
    cout<<"Cantidad de 1's "<<cuentaUnos(arreglo3,0,longitud3-1,0)<<endl;


    //3. Un arreglo rotado en algún punto desconocido. Encontra el elemento mínimo del arreglo
    int arreglo4[] = {10,9,7,6,5,1};
    int longitud4 =  sizeof(arreglo4)/sizeof(arreglo4[0]);
    imprime(arreglo4,longitud4);
    cout<<"El menor elemento rotado es :"<<buscaMenor(arreglo4,0,longitud4-1)<<endl;

    //4. Arreglo de número positivos y negativos, encontrar la suma de números contiguos que tengan la sum máx
    int arreglo5[] = {-2,-5,6,-2,-3,1,5,-6};
    int longitud5 =  sizeof(arreglo5)/sizeof(arreglo5[0]);
    imprime(arreglo5,longitud5);
    cout << "Salida maxima: " << sumaMaximaConsecutiva(arreglo5, 0, longitud5-1) << endl;

    //5. Primero crece y luego decrece. Encontrar el máximo valor en el arreglo
    //8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1 // crece - decrece
    //
    int arreglo6[]{30,21,19,18,10,11,12,13}; //funciona por que se forma una montaÃ±a
    int longitud6 = sizeof (arreglo6) / sizeof (arreglo6[0]);
    imprime(arreglo6,longitud6);
    cout << "EL PUNTO MAS ALTO DE LA MONTANNA: " << buscaMontana(arreglo6, 0, longitud6-1) << endl;
    cout << "EL PUNTO MAS BAJO DE LA VALLE : "<< buscaValle(arreglo6, 0, longitud6-1)<<endl;


    //6. Inversiones Una inversión es un par de elementos A[i] y A[j] tal que i < j y A[i] > A[j].
    int arreglo7[] = {1, 2, 3, 4, 5}; //no hay inversiones
    int arreglo8[] = {5, 4, 3, 2, 1}; // todas las parejas son inversiones
    int arreglo9[] = {2, 4, 1, 3, 5}; // tenemos 3 inversiones (2,1),(4,1),(4,3); dónde i<j y A[i] > A[j]
    int longitud7 = sizeof (arreglo7) / sizeof (arreglo7[0]);
    cout << "Inversiones 1: " << numeroInversiones(arreglo7, 0, longitud7 - 1) << endl;
    int longitud8 = sizeof (arreglo8) / sizeof (arreglo8[0]);
    cout << "Inversiones 2: " << numeroInversiones(arreglo7, 0, longitud8 - 1) << endl;
    int longitud9 = sizeof (arreglo9) / sizeof (arreglo9[0]);
    cout << "Inversiones 3: " << numeroInversiones(arreglo9, 0, longitud9 - 1) << endl;
    imprime(arreglo9,longitud9);




    return 0;
}