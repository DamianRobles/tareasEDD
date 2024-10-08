/*
  ! Fecha: martes 8 de octubre de 2024
           jueves 10 de octubre de 2024
  ! Autor: Dali
  ! Practica No.: 23
  ! Objetivo: LIFO - Last In First Out - Stack - Pila
*/

//* librerias
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//* tda's
struct paleta {
  // datos a almacenar
  char sabor[30];
  float precio;
  char marca[30];
  char tamaxo[20];
  // apuntador al siguiente
  paleta *next;
};

//* variables globales

//* operaciones
void colocarPaleta();
void comerPaleta();
void mostrarPaletas();
void menu();

//* funcion principal
int main(void) {
  // declaracion de variables
  int opcion;

  do {
    menu();
    cout << "Ingresa tu opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 1:
      colocarPaleta();
      break;
    case 2:
      mostrarPaletas();
      break;
    case 3:
      comerPaleta();
      break;
    case 0:
      cout << "Seleccionaste salir" << endl;
      break;
    default:
      cout << "Opcion no valida" << endl;
      break;
    } // switch
  } while (opcion);

  return 0;
}

//* implementacion de operaciones - funciones
//! colocarPaleta()
//! ==============================================================
void colocarPaleta() {} // colocarPaleta()

//! mostrarPaletas()
//! ==============================================================
void mostrarPaletas() {} // mostrarPaletas()

//! comerPaleta()
//! ==============================================================
void comerPaleta() { return; } // comerPaleta()

//! menu()
//! ==============================================================
void menu(void) {
  cout << endl << endl;
  cout << "Pila de paletas de sabores" << endl;
  cout << "====================================" << endl;
  cout << "1. Colocar una paleta al inicio de la pila" << endl;
  cout << "2. Mostrar paletas que hay apiladas" << endl;
  cout << "3. Comer la primer paleta de la pila" << endl;
  cout << "0. Salir" << endl;
  cout << "====================================" << endl;

  return;
} // menu()
