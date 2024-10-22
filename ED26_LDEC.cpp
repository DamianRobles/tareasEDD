/*
  ! Fecha: martes 22 de octubre de 2024
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
void eliminar();
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
      consultar();
      break;
    case 3:
      eliminar();
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
//! agregar()
//! ==============================================================
void agregar() {
} // agregar

//! menu()
//! ==============================================================
void menu(void) {
  cout << endl << endl;
  cout << "                           Playlist" << endl;
  cout << "====================================" << endl;
  cout << "1. Agregar cancion a la lista" << endl;
  cout << "2. Consultar canciones en la lista (Tarea)" << endl;
  cout << "3. Eliminar cancion de la lista" << endl;
  cout << "4. Buscar canciones de la lista (Clase)" << endl;
  cout << "0. Salir" << endl;
  cout << "====================================" << endl;

  return;
} // menu()
