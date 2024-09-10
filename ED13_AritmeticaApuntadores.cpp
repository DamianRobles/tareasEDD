/*
  ! Fecha: jueves 5 de septiembre de 2024
  ! Autor: Dali
  ! Practica No.: 13
  ! Objetivo: Aritmetica de apuntadores
*/

//* librerias
#include <iostream>
using namespace std;

//* prototipos

const int MAX=5;

//* funcion principal
int main(void){
  // declaracion de variables
  int valores[MAX];
  int *ap =  valores;

  // leer datos
  cout << "Este programa ejemplifica la aritmetica de apuntadores" << endl;
  cout << "Ingrese 5 valores enteros: " << endl;
  for(int i=0; i<MAX; i++){
    cout << "Numero " << i+1 << ": ";
    cin >> valores[i];
  }

  cout << "=======================================================" << endl;
  // mostrar datos con el arreglo
  cout << "Los " << MAX << " numeros enteros guardados son" << endl;
  cout << "ap= " << ap << endl;
  for(int i=0; i<MAX; i++){
    cout << "Numero " << i+1 << ": " << valores[i] << endl;
    cout << "Guardado en la memoria en: " << &valores[i] << endl;
  } // for i

  cout << "=======================================================" << endl;
  // mostrar datos con apuntador
  cout << "Los " << MAX << " numeros enteros guardados son" << endl;
  for(int i=0; i<MAX; i++){
    cout << "Numero " << i+1 << ": " << *ap << endl;
    cout << "Guardado en la memoria en: " << ap << endl;
    ap++; // esto desplaza el apuntador
  } // for i
  cout << "Al final quede apuntando a " << ap << " que contiene " << *ap << endl;
  ap = ap-3;
  cout << "Direcion ap " << ap << endl;
  cout << "Contenido ap " << *ap << endl;
  
  return 0;
} //* main

//* implementacion de funciones


//* fin de archivo