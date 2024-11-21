// **********************************************
// Fecha: Sesion 28
// Practica No.: 34
// Objetivo: Metodo de Ordenamiento por Seleccion
// **********************************************

#include <iostream>
using namespace std;

const int TOTAL = 10;

// **********************************************
int main ( void ) {
    // Declarar variables
    int arreglo[TOTAL], posicion, valor, temporal;
    
    // =======================
    // 1) Leer arreglo
    // =======================
    for (int i=0 ; i<TOTAL; i++) {
        cout << "Elemento " << i+1 << " : ";
        cin >> arreglo[i];
    } // for i
    cout << endl;
    
    // =======================
    // 2) Imprimir arreglo DESORDENADO
    // =======================
    cout << "ARREGLO  DESORDENADO." << endl;
    for (int i=0 ; i<TOTAL; i++) {
        cout << arreglo[i] << "\t";
    } // for i
    cout << endl << endl;
    
    // =======================
    // 3) Ordenar el arreglo x ALGORITMO SELECCION
    // =======================
    cout << "ORDENANDO EL ARREGLO..." << endl << endl;
    
    for (int i=0; i<TOTAL; i++) {
        valor=arreglo[i];
        posicion=i;
        
        // Seleccionar el menor
        for (int j=i+1; j<TOTAL; j++ ) {
            if ( arreglo[j] < valor ) {
                valor = arreglo[j];     // Guardar valor
                posicion=j;             // Guardar posición del índice
            } // if
        } // for j
        
        // intercambiar
        temporal = arreglo[i];
        arreglo[i] = valor;
        arreglo[posicion] = temporal;
    } // for i
    
    // =======================
    // 4) Imprimir arreglo ORDENADO
    // =======================
    cout << "ARREGLO  ORDENADO." << endl;
    for (int i=0 ; i<TOTAL; i++) {
        cout << arreglo[i] << "\t";
    } // for i
    cout << endl;
    
    return(0);
}  // main
