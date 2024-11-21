// **********************************************
// Fecha: Sesión 29
// Practica No.: 35
// Objetivo: Metodo de ordenamiento x Insercion Directa
// **********************************************

#include<iostream>
using namespace std;

const int MAX = 10;

// **********************************************
int main (void) {
    // Declaracion de variables
    int numeros[MAX], temp, i;
    
    // 1) Leer numeros
    // ==========================
    for(int i=0; i<MAX; i++) {
        cout << "Ingresa numero " << i+1 << " --> ";
        cin >> numeros[i];
    } // for i
    cout << endl;
    
    // 2) Imprimir arreglo desordenado
    // ==========================
    cout << "ARREGLO DESORDENADO" << endl;
    for (int i=0; i<MAX; i++ ) {
        cout << numeros[i] << "\t" ;
    } // for i
    cout << endl << endl;
    
    // 3) Ordenar arreglo usando método de Inserción Directa
    cout << "Ordenando el arreglo con Método Insercion Directa..." << endl;
    // *******************************************
    for (int k=1; k<MAX; k++) {
        // a) Copiar el elemento que se va a insertar en su posición correcta
        temp = numeros[k];
        // b) Mover todos los elementos menores que el elemento a insertar en su posición
        for (i=k-1; i >= 0 && temp < numeros[i]; i--) {
            numeros[i+1]=numeros[i];
        } // for i
        // c) insertar el elemento en la posición que le corresponde
        numeros[i+1]=temp;
    } // for k
    cout << endl;
    // *******************************************
    
    // 4) Imprimir arreglo ordenado
    // ==========================
    cout << "ARREGLO ORDENADO" << endl;
    for(i=0; i<MAX; i++) {
        cout << numeros[i] << "\t";
    } // for i
    cout << endl;
    
    return(0);
} // main
