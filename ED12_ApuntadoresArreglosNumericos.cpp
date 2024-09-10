/*
  ! Fecha: jueves 5 de septiembre de 2024
  ! Autor: Dali
  ! Practica No.: 12
  ! Objetivo: Apuntadores a arreglos numericos
*/

/*
  ? el nombre del arreglo es la direccion de memoria del primer elemento del arreglo
  ? ap = vector;
  ? ap = &vector[0]
  ? esas 2 formas de representarlo es lo mismo
  ? no se puede modificar los nombres de los arreglos ni mover de lugar los valores como si fuera un apuntador
*/

//* librerias
#include <iostream>
using namespace std;

//* prototipos

const int MAX=5;

//* funcion principal
int main(void){
  // declaracion de variables
  double valores[MAX];
  double *ap =  valores;

  // leer datos
  cout << "Este programa ejemplifica la relacion de un apuntador a un arreglo numerico DOBLE" << endl;
  cout << "Ingrese 5 valores reales: " << endl;
  for(int i=0; i<MAX; i++){
    cout << "Numero " << i+1 << ": ";
    cin >> valores[i];
  }

  // mostrar datos
  cout << "Los " << MAX << " numeros reales guardados son" << endl;
  cout << "ap= " << ap << endl;
  for(int i=0; i<MAX; i++){
    cout << "Numero " << i+1 << ": " << valores[i] << endl;
    cout << "Guardado en la memoria en: " << &valores[i] << endl;
  } // for i

  cout << endl << endl;

  cout << "Tamano en bytes de un entero: " << sizeof(double) << endl;
  cout << "Tamano en bytes para el arreglo valores: " << sizeof(valores) << endl;
  cout << "Direccion de memoria donde inicia el arreglo valores[]: " << &valores[0] << endl;
  // mostrar datos con apuntador
  cout << "Direccion de memoria donde inicia el arreglo valores[]: " << ap << endl;
  for(int i=0; i<MAX; i++){
    cout << "Numero " << i+1 << ": " << *(ap+i) << endl;
    cout << "Guardado en la memoria en: " << ap+i << endl;
  }
  cout << "ap= " << ap << endl;

  return 0;
} //* main

//* implementacion de funciones


//* fin de archivo