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
// apuntador a la pila o stack
paleta *apCima = NULL;

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
void colocarPaleta(){
  // 1) declarar variables
  paleta *apNuevo = NULL;
  
  // 2) solicitar memoria
  apNuevo = (paleta *) malloc(sizeof(paleta));

  // 3) validar apuntador
  if (apNuevo == NULL){
    cout << "No hay memoria disponible" << endl;
    return;
  }
  // 4) solicitar datos de la nueva paleta y guardarlos
  cin.ignore();
  cout << endl << "Ingresa los datos de la paleta" << endl;
  cout << "==============================" << endl;
  cout << "Ingrese el sabor (ej. fresa): ";
  cin.getline(apNuevo -> sabor, 30, '\n');
  cout << "Ingrese el tamano (ej. mini, chica): ";
  cin.getline(apNuevo -> tamaxo, 20, '\n');
  cout << "Ingrese el marca (ej. michoacana): ";
  cin.getline(apNuevo -> marca, 30, '\n');
  cout << "Ingrese el precio (ej. 0.75): ";
  cin >> apNuevo -> precio;

  // 5) agregar la paleta al stack
  apNuevo -> next = apCima;
  apCima = apNuevo;
  cout << "La paleta fue agregada al inicio de la pila" << endl;
    
  return;
} // colocarPaleta()

//! mostrarPaletas()
//! ==============================================================
void mostrarPaletas(){
  // 1) declaracion de variables
  paleta *apCopia = apCima;

  // 2) validar si la pila esta vacia
  if (apCopia == NULL){
    cout << "No hay paletas en la pila" << endl;
    return;
  }

  // 3) mostrar las paletas
  while(apCopia != NULL){
    cout << endl << "Paletas en la pila" << endl;
    cout << "==============================" << endl;
    cout << "Sabor: " << apCopia -> sabor << endl;
    cout << "Tamano: " << apCopia -> tamaxo << endl;
    cout << "Marca: " << apCopia -> marca << endl;
    cout << "Precio: $" << apCopia -> precio << endl;
    apCopia = apCopia -> next;
  }
  
  return;
} // mostrarPaletas()

//! comerPaleta()
//! ==============================================================
void comerPaleta() { 
  // 1) declaracion de variables
  paleta *apBorrar = apCima;
  int respuesta;

  // 2) validar si la pila esta vacia
  if (apBorrar == NULL){
    cout << "No hay paletas en la pila" << endl;
    return;
  }

  // 3) comer paleta
  cout << endl << "Paleta a comer" << endl;
  cout << "==============================" << endl;
  cout << "Sabor: " << apBorrar -> sabor << endl;
  cout << "Tamano: " << apBorrar -> tamaxo << endl;
  cout << "Marca: " << apBorrar -> marca << endl;
  cout << "Precio: $" << apBorrar -> precio << endl;
  cout << "Quieres comerte la paleta? (1-Si 2-No) ";
  cin >> respuesta;
  if(respuesta == 1){
    apCima = apBorrar -> next;
    free(apBorrar);
    cout << "La paleta fue comida" << endl;
    return;
  }
  else{
    cout << "No te comiste la paleta" << endl;
    return;
  }
} // comerPaleta()

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
