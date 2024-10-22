/*
  ! Fecha: jueves 17 de octubre de 2024
  ! Au}tor: Dali
  ! Practica No.: 26
  ! Objetivo: LDEC - lista doblemente enlazada cerada
*/

//* librerias
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//* tda's
struct cancion {
  // datos
  char titulo[50];
  char artista[59];
  char duracion[6];
  char genero[30];
  // apuntadores
  cancion *next;
  cancion* before;
};

//* variables globales
// apuntador a la LDEA
cancion *apPlayList = NULL;

//* operaciones
void agregar();
void agregar();
void consultar();
void buscar();

//* Funciones
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
      agregar();
      break;
    case 2:
      agregar();
      break;
    case 3:
      consultar();
      break;
    case 4:
      buscar();
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
//! agregarInicio()
//! ==============================================================
void agregarInicio() {
  
}

//! menu()
//! ==============================================================
void menu(void) {
  cout << endl << endl;
  cout << "         Gestor de canciones" << endl;
  cout << "====================================" << endl;
  cout << "1. Agregar al inicio de la lista (Clase)" << endl;
  cout << "2. Agregar al final de la lista (Tarea)" << endl;
  cout << "3. Consultar la lista de inicio a fin (Tarea)" << endl;
  cout << "4. Consultar la lista de fin a inicio (Clase)" << endl;
  cout << "0. Salir" << endl;
  cout << "====================================" << endl;

  return;
} // menu()
