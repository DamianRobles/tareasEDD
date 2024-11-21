// *********************************************
// Fecha: Sesión 29
// Práctica No.: 37
// Objetivo: Metodo de Ordenamiento Shell Sort
// *********************************************

// Librerias
// *********************************************
#include <iostream>
using namespace std;

// Programa principal
// *********************************************
int main(void){
    // Declaracion de variables
    int n = 10, inc, j, tmp;
    int a[n];
    
    // 1) Entrada de Dato
    cout << "Implementacion del algoritmo Shell Sort" << endl;
    cout << endl;
    for (int i=0; i<n; i++){
        cout << "Agrega el elemento " << i + 1 << " : ";
        cin >> a[i];
    } // for
    
    // 2) Imprimir elementos NO ordenados
    cout << "Arreglo sin ordenar"  << endl;
    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    } // for
    
    // 3) Ordenando el arreglo tama–o n usando mŽtodo Shell
    // ====================================================
    inc = n/2;
    while (inc > 0){
        for (int i=inc; i<n; i++){
            j=i-inc;
            while ( j >= 0 ) {
                if ( a[j] >= a[j+inc]) {
                    tmp = a[j];
                    a[j] = a[j+inc];
                    a[j+inc]=tmp;
                } else
                    j=0;
                j=j-inc;
            } // while
        } // for
        inc = inc / 2;
    } // while
    // =====================================================
    
    // 4) Imprime Elemento ordenados
    cout << endl << "Arreglo ordenado"  << endl;
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    } // for
    
    return(0);
} // main

// ==================== fin de archivo ==================
