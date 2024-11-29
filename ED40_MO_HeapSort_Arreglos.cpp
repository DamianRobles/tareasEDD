// ********************************************
// Fecha: Sesi�n 30
// Practica No.: 40
// Objetivo: Metodo de Ordenamiento HeapSort
// ********************************************

// Librerias
// =================
#include <iostream>
using namespace std;

// Prototipos de funciones
// ========================
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void imprimeArray(int arr[], int n);

// Programa principal
// ========================
int main(void) {
    int r;
    
    cout << "**************************************************************" << endl;
    cout << "Programa que ordena numeros del menor al mayor usando HeapSort" << endl;
    cout << "**************************************************************" << endl;
    cout << "Cuantos numeros desea ordenar: ";
    cin >> r;
    cout << "Escriba los numeros separados por un <enter>" << endl;
    
    // 1) Lee los nœmeros del arreglo
    int arr[r];
    for(int i=0 ; i < r ; i++) {
        cout << "Ingresa numero " << i+1 << ": ";
        cin >> arr[i];
    } // for
    
    // 2) Ordena los nœmeros del arreglo
    int n = (int) sizeof(arr) / sizeof(arr[0]);
    // La obtencion del tama–o del array,
    // en este caso se tomara en cuenta por los bytes que utilizara
    heapSort(arr, n);
    cout << endl << endl;
    
    // 3) Imprime los nœmeros del arreglo ordenados
    cout << "Numeros ordenados \n";
    imprimeArray(arr, n);
    
    return(0);
} // main

// =========================================
void heapSort(int arr[], int n) {
    // Construyen el monticulo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // Se extrae un elemento del monticulo uno por uno.
    for (int i=n-1; i>=0; i--) {
        // Mueve la Raiz al final
        swap(arr[0], arr[i]);
        
        // LLama la funcion en el monton disminuido
        heapify(arr, i, 0);
    } // for
} // heapsort

// =========================================
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // izquierdo = 2*i + 1
    int r = 2*i + 2;  // derecho = 2*i + 2
    
    // Si el hijo es mayor que el nodo raiz
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    // Si el hijo derecho es mas grande que el mas grande hasta ahora
    if (r < n && arr[r] > arr[largest])
        largest = r;
    
    // Si el mayor no es la raiz
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    } // if
    
} // Heapify

// =========================================
void imprimeArray(int arr[], int n) {
    cout << "============================" << endl;
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
} // imprimeArray

//  ***************** fin de archivo
