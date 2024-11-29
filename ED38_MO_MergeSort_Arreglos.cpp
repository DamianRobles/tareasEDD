// ********************************************
// Fecha: Sesi�n 30
// Practica No.: 38
// Objetivo: Metodo de Ordenamiento MergeSort
// ********************************************

// Librerias
// ********************************************
#include <iostream>
#include <stdlib.h>
using namespace std;

// Prototipos de funciones
// ********************************************
void mergesort(int *v, int i, int f);
void merge(int *v, int i, int m, int f);

// Programa principal
// ********************************************
int main(void) {
    //Declaracion de variables
    int n=10;
    int v[n];
    
    cout << "Este programa ordena los elementos de un arreglo de numeros enteros." << endl;
    
    // 1) Arreglo con los nœmeros
    cout << "Escribe los numeros del arreglo." << endl;
    for(int i=0; i<n; i++) {
        cout << "Numero " << i+1 << " --> ";
        cin >> v[i];
    }//for
    
    // 2) Imprime arreglo desordenado
    cout << "Arreglo original: " <<endl;
    for(int i=0; i<n; i++)
        cout << v[i] << "\t";
    cout << endl;
    
    // 3) Ordenar el arreglo mŽtodo MergeSort
    mergesort(v, 0, n-1);
    
    // 4) Imprime arreglo ordenado
    cout << "Arreglo ordenado con Merge Sort: " <<endl;
    for(int i=0; i<n; i++)
        cout << v[i] << "\t";
    cout << endl;
    
    return(0);
} // main

// *************************************
void mergesort(int *v, int i, int f) {
    // Separa los datos en sublistas recursivamente
 	if (i != f) {
        int m = (i+f)/2;
        mergesort(v, i, m);
        mergesort(v, m+1, f);
        merge(v, i, m, f);
    } //if
    
} // mergesort

// *************************************
void merge(int *v, int i, int m, int f) {
    int *aux = new int[m-i+1];
    
    // Une las sublistas en una sola
    for (int j=i; j<=m; j++)
        aux[j-i] = v[j];
    
    int c1=0, c2=m+1;
    
    for ( int j=i; j<=f; j++ ) {
        if (aux[c1] < v[c2]) {
            v[j] = aux[c1++];
            if(c1==m-i+1)
                for(int k=c2; k<=f; k++)
                    v[++j] = v[k];
        } else {
            v[j] = v[c2++];
            if(c2==f+1)
                for(int k=c1; k<=m-i; k++)
                    v[++j] = aux[k];
        } // if-else
    } // for
    
} // merge

//Fin del archivo
