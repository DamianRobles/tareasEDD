/*
  ! Fecha: jueves 3 de octubre de 2024
           martes 8 de ocubre de 2024
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
struct taquilla {
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
void agregar() {
  // 1) declarar un apuntador
  taquilla *apNuevo = NULL;

  // 2) solicitar memoria
  apNuevo = (taquilla *)malloc(sizeof(taquilla));

  // 3) validar el apuntador
  if (apNuevo == NULL) {
    cout << "No hay memoria disponible" << endl;
    return;
  } // if

  // 4) solicitar datos
  cin.ignore();
  cout << endl << "Ingresa los datos de la nueva compra" << endl;
  cout << "=====================================" << endl;
  cout << "Ingresa el nombre: ";
  cin.getline(apNuevo->nombre, 40, '\n');
  cout << "Ingresa el evento: ";
  cin.getline(apNuevo->evento, 30, '\n');
  cout << "Ingresa la fecha (08/10/2024): ";
  cin.getline(apNuevo->fecha, 30, '\n');
  cout << "Ingresa los asientos (B2 - B3 - B4):";
  cin.getline(apNuevo->asientos, 20, '\n');
  cout << "Ingresa el total a pagar: ";
  cin >> apNuevo->totalPagar;
  cin.ignore();

  // 5) agregarlo a la fifo
  // A) si la queue esta vacia
  if (apPRIMERO == NULL) {
    apPRIMERO = apNuevo;
    apULTIMO = apNuevo;
    apULTIMO->next = NULL;
    cout << "Los datos fueron agregados al final correctamente" << endl;
  } // if vacio

  // B) si la queue no esta vacia
  apULTIMO->next = apNuevo; // el ultimo nodo apunta a apNuevo
  apNuevo->next = NULL;     // el nuevo nodo apunta a NULL
  apULTIMO = apNuevo;       // el ultimo nodo es el nuevo

  return;
} // agregar()

//! mostrar()
//! ==============================================================
void mostrar() {
  taquilla *apCopia = apPRIMERO;

  // validar que no este vacia
  if (apCopia == NULL) {
    cout << "No hay datos en la lista" << endl;
    return;
  }

  // si no esta vacia
  cout << endl << "Datos de los clientes en la fila" << endl;
  while (apCopia != NULL) {
    cout << "=====================================" << endl;
    cout << "Ingresa el nombre       : " << apCopia->nombre << endl;
    cout << "Ingresa el evento       : " << apCopia->evento << endl;
    cout << "Ingresa la fecha        : " << apCopia->fecha << endl;
    cout << "Ingresa los asientos    : " << apCopia->asientos << endl;
    cout << "Ingresa el total a pagar: " << apCopia->totalPagar << endl;
    apCopia = apCopia->next;
  } // while

  return;
} // mostrar()

//! eliminar()
//! ==============================================================
void eliminar() {
  // declaracino de variables
  taquilla *apBorrar = apPRIMERO;
  int respuesta;

  // A) vacia
  if (apBorrar == NULL) {
    cout << "No hay clientes formados" << endl;
    return;
  }

  // si la queue no esta vacia
  cout << "=====================================" << endl;
  cout << "Ingresa el nombre       : " << apBorrar->nombre << endl;
  cout << "Ingresa el evento       : " << apBorrar->evento << endl;
  cout << "Ingresa la fecha        : " << apBorrar->fecha << endl;
  cout << "Ingresa los asientos    : " << apBorrar->asientos << endl;
  cout << "Ingresa el total a pagar: " << apBorrar->totalPagar << endl;
  cout << "=====================================" << endl;
  cout << "El cliente ya fue atendido? (1-Si 2-No)" << endl;
  cin >> respuesta;

  // B) un unico cliente formado
  if (apBorrar->next == NULL) {
    if (respuesta == 1) {
      free(apBorrar);
      apPRIMERO = apULTIMO = NULL;
      cout << "El cliente ya fue atendido y ya no hay mas en fila" << endl;
    } else {
      cout << "Aun no se atiende al primer cliente" << endl;
    }
    return;
  } // if 1 solo cliente

  // C) mas de un cliente
  if (respuesta == 1) {
    apPRIMERO = apPRIMERO->next; // se mueve el ap al 2do cliente
    free(apBorrar);
    cout << "El cliente ya fue atendido" << endl;
  } else {
    cout << "Aun no se atiende al primer cliente" << endl;
  }

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
