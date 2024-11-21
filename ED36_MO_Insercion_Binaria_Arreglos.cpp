// **************************************************
// Fecha: Sesión 29
// Practica No.: 36
// Objetivo: Metodo de Ordenamiento Insercion Binaria
// **************************************************

#include <iostream>
using namespace std;

const int MAX = 10;

// **************************************************
int main(void) {
    int n[MAX];
    
    // 1) Ingresar los elementos del arreglo
    // ==========================
    for (int i=0; i<MAX; i++) {
        cout << "Ingresa numero " << i+1 << ": ";
        cin >> n[i];
    } // for i

    cout << "ARREGLO DESORDENADO" << endl;
    cout << "===================================================" << endl;
    for(int i=0; i<MAX; i++) {
        cout<< n[i] << "\t";
    } // for i
    
    // ORDENAR ARREGLO X MÉTODO INSERCIÓN BINARIA
    // ******************************************
    int i,j,aux,izq,der,m;
    for(i=1; i<MAX; i++) {
        aux = n[i];   // valor a colocar ordenado
        izq=0;
        der=i-1;
        // localizar la posición a insertar
        // usando método de búsqueda binaria
        while(izq <= der) {
            m=( (izq+der)/2 );
            if ( aux < n[m] )
                der=m-1;
            else
                izq=m+1;
        } // while
        // mover todos los elementos a la derecha
        // para liberar la posición donde se insertará
        // el valor en su lugar correspondiente
        j=i-1;
        while( j>=izq ) {
            n[j+1]=n[j];
            j=j-1;
        } // while
        // copia el valor en su lugar correspondiente
        n[izq]=aux;
    } // for
    // ******************************************

    cout << "ARREGLO ORDENADO CON EL METODO DE INSERCION BINARIA" << endl;
    cout << "===================================================" << endl;
    for(int i=0; i<MAX; i++) {
        cout<< n[i] << "\t";
    } // for i
    
    return(0);
} // main
