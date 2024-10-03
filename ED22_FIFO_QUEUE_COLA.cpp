/*
  ! Fecha: jueves 3 de octubre de 2024
  ! Autor: Dali
  ! Practica No.: 22
  ! Objetivo: FIFO - First In First Out - QUEUE - Cola
*/

//* librerias
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//* tda's
struct taquilla{
  // datos
  char nombre[40];
  char asientos[20];
  float totalPagar;
  char fecha[30];
  char evento[30];
  // apuntadoral siguiente en la lista
  taquilla *next;
};

//* variables globales
// apuntadores a mi QUEUE
taquilla *apPRIMERO = NULL, *apULTIMO = NULL;

//* operaciones
void agregar();
void eliminar();
void mostrar();
void verificar();
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
      mostrar();
      break;
    case 3:
      eliminar();
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
void agregar(){
  
  return;
}
//! eliminar()
//! ==============================================================
void eliminar(){

  return;
}
//! mostrar()
//! ==============================================================
void mostrar(){

  return;
}
//! verificar()
//! ==============================================================
void verificar(){

  return;
}

//! menu()
//! ==============================================================
void menu(void) {
cout << endl << endl;
cout << "Fila para comprar boletos en taquilla Santander" << endl;
cout << "====================================" << endl;
cout << "1. Agregar un cliente al final de la fila" << endl;
cout << "2. Consultar clientes formados en la fila" << endl;
cout << "3. Atender al primer cliente en la fila" << endl;
cout << "0. Salir" << endl;
cout << "====================================" << endl;

return;
} // menu() 
