// *******************************************
// Fecha: Sesi�n 30
// Practica No.: 39
// Objetivo: Metodo de ordenamiento QuickSort
// *******************************************

// Librerias
#include <iostream>
#include <cmath>
using namespace std;

// Prototipos de funciones
// *******************************************
void Quicksort(int *arr, int izq, int der);

// Constantes
const int MAX=10;

// Programa principal
// *******************************************
int main(void) {
	// Declaración de Variables
    int numeros[MAX];
    
    // Leer arreglo
    for(int i=0; i<MAX; i++) {
		cout << "Numero " << i+1 << " -> ";
        cin >> numeros[i];
    } // for i
    
    // Imprimir arreglo desordenado
    cout << "Arreglo desordenado" << endl;
    for(int i=0; i<MAX; i++)
        cout << numeros[i] << '\t';
    cout << endl;
    
    // Ordenar arreglo método Quicksort
    cout << "Ordenando arreglo algoritmo QuickSort..." << endl;
    Quicksort(numeros, 0, 9);
    
    // Imprimir arreglo ordenado
    cout << "Arreglo ordenado" << endl;
    for(int i=0; i<MAX; i++)
        cout << numeros[i] << '\t';
    cout << endl;
    
	return 0;
} // main

//********************************************
void Quicksort(int *arr, int izq, int der) {
    int i = izq, j = der, tmp; //temp es para guardar el valor que se cambia
    int p = arr[(izq + der) / 2]; //la mitad de la cadena , arr es para el valor de la posicion
    
    while (i <= j)
    {
        while (arr[i] < p) i++; //condicionales anidadas para comparar con el pivote
        while (arr[j] > p) j--; //deben cumplir
        if (i <= j)
        {
            tmp = arr[i]; //se guarda el valor en i para no perder la referencia
            arr[i] = arr[j]; //se asigna el valor de i a j
            arr[j] = tmp; //y el valor inicial de i que esta en temp se asigna a j
            i++; j--; //mover las posiciones
        } // if
    } // while
    
    if (izq < j)
        Quicksort(arr, izq, j);
    
    if (i < der)
        Quicksort(arr, i, der);
    
} // Quicksort

// ************** fin de archivo
