/*
  ! Fecha: jueves 10 de octubre de 2024
  ! Autor: Dali
  ! Practica No.: 24
  ! Objetivo: LSEC -  Lista simplemente enlazada circular o cerrada
*/

//* librerias
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//* tda's
struct agendaSemanal {
  // datos a almacenar
  char dia[20];
  char activida[50];
  char horario[20];
  int duracion;
  // apuntador al siguiente
  agendaSemanal *next;
};

//* variables globales
// apuntador a la LSEC
agendaSemanal *apAgenda = NULL;

// typedef agendaSemanal *apNodo;

//* operaciones
void insertar();  // agregar nuevas actividades en la agenda
void cancelar();  // eliminar alguna acitividad en la agenda
void consultar(); // ver las actividades en la agenda
void buscar();    // buscar alguna actividad en la agenda
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
      insertar();
      break;
    case 2:
      cancelar();
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
//! insertar()
//! ==============================================================
void insertar() {
  // 1) declarar variables
  paleta *apNuevo = NULL;

  // 2) solicitar memoria
  apNuevo = (paleta *)malloc(sizeof(paleta));

  // 3) validar apuntador
  if (apNuevo == NULL) {
    cout << "No hay memoria disponible" << endl;
    return;
  }
  // 4) solicitar datos de la nueva paleta y guardarlos
  cin.ignore();
  cout << endl << "Ingresa los datos de la paleta" << endl;
  cout << "==============================" << endl;
  cout << "Ingrese el sabor (ej. fresa): ";
  cin.getline(apNuevo->sabor, 30, '\n');
  cout << "Ingrese el tamano (ej. mini, chica): ";
  cin.getline(apNuevo->tamaxo, 20, '\n');
  cout << "Ingrese el marca (ej. michoacana): ";
  cin.getline(apNuevo->marca, 30, '\n');
  cout << "Ingrese el precio (ej. 0.75): ";
  cin >> apNuevo->precio;

  // 5) agregar la paleta al stack
  apNuevo->next = apCima;
  apCima = apNuevo;
  cout << "La paleta fue agregada al inicio de la pila" << endl;

  return;
} // insertar()

//! cancelar()
//! ==============================================================
void cancelar(){
  
} // cancelar()


//! consultar()
//! ==============================================================
void consultar(){
  
} // consultar()


//! buscar()
//! ==============================================================
void buscar(){
  
} // buscar()

//! menu()
//! ==============================================================
void menu(void) {
  cout << endl << endl;
  cout << "         Agenda semanal" << endl;
  cout << "====================================" << endl;
  cout << "1. Agregar nueva actividad" << endl;
  cout << "2. Cancelar actividad" << endl;
  cout << "3. Consultar las actividades" << endl;
  cout << "4. Buscar actividad" << endl;
  cout << "0. Salir" << endl;
  cout << "====================================" << endl;

  return;
} // menu()
