/*
  ! Fecha: jueves 19 de septiembre de 2024
  ! Autor: Dali
  ! Practica No.: 21
  ! Objetivo: LSEA - lista simplemente enlazada abierta
*/

//* librerias
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//* tda's
struct videojuego {
  // 1. parte informacion
  char titulo[30];
  char genero[20];
  char clasificacion[20];
  float precio;
  // 2. apuntador al siguiente elemento
  videojuego *next;
};

//* operaciones de LSEA
void agregarInicio();
void consultarLista();
void buscarTitulo();
void menu();

//* variables globales
// apuntador a mi lista
videojuego *apLISTA = NULL;

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
      agregarInicio();
      break;
    case 2:
      consultarLista();
      break;
    case 3:
      buscarTitulo();
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
  // 1) declarar un apuntador
  videojuego *apNuevo = NULL;

  // 2) solicitar memoria dinamica
  apNuevo = (videojuego *)malloc(sizeof(videojuego));

  // 3) validar el apuntador
  if (apNuevo == NULL) {
    cout << "No se tiene memoria suficiente" << endl;
  } // if

  // 4) guardar los datos del nuevo videojuego
  cout << endl << endl;
  cout << "Ingresa los datos del nuevo videojuego" << endl;
  cout << "Titulo: ";
  cin.ignore();
  cin.getline(apNuevo->titulo, 30, '\n');
  cout << "Genero: ";
  cin.getline(apNuevo->genero, 20, '\n');
  cout << "Clasificacion: ";
  cin.getline(apNuevo->clasificacion, 20, '\n');
  cout << "Precio: ";
  cin >> apNuevo->precio;

  // 5) agregar a la LSEA
  // caso A) Lista vacia
  if (apLISTA == NULL) {
    apLISTA = apNuevo;
    apNuevo->next = NULL;
    cout << "Videojuego agregado corrrectamente al inicio de la lista" << endl;
    return;
  } // if

  // caso B) lista no vacia
  apNuevo->next = apLISTA;
  apLISTA = apNuevo;
  cout << "Videojuego agregado correctamente al inicio de la lista" << endl;

  return;
} // agregarInicio()

//! consultarLista()
//! ==============================================================
void consultarLista() {
  // declarar variables
  videojuego *apCopia = apLISTA;

  // validar que este vacia
  if (apCopia == NULL) {
    cout << "La lista esta vacia" << endl;
    return;
  }
  // mostrar los nodos
  cout << "Listado de videojuegos" << endl;
  cout << "La lista inicia en la direccion: " << apLISTA << endl;
  while (apCopia != NULL) {
    cout << endl << endl;
    cout << "Direccion de memoria de este nodo: " << apCopia << endl;
    cout << "Listado de videojuegos" << endl;
    cout << "======================" << endl;
    cout << "Titulo: " << apCopia->titulo << endl;
    cout << "Genero: " << apCopia->genero << endl;
    cout << "Clasificacion: " << apCopia->clasificacion << endl;
    cout << "Precio: " << apCopia->precio;
    cout << "Direccion de memoria del siguiente nodo: " << apCopia->next;
    apCopia =
        apCopia->next; //? aqui se guarda la direccion de memoria del siguiente
  }                    // while

  return;
} // consultarLista()

//! menu()
//! ==============================================================
void buscarTitulo() {
  // declarar variables
  videojuego *apCopia = apLISTA;
  char titBuscar[30];

  // validar que este vacia
  if (apCopia == NULL) {
    cout << "La lista esta vacia" << endl;
    return;
  }

  // solicitar el titulo a buscar
  cout << "Ingresa el titulo a buscar: ";
  cin.ignore();
  cin.getline(titBuscar, 30, '\n');

  // buscar el videojuego
  cout << "Listado de videojuegos" << endl;
  while (apCopia != NULL) {
    if (strcmp(titBuscar, apCopia->titulo) == 0) {
      cout << "Listado de videojuegos" << endl;
      cout << "======================" << endl;
      cout << "Titulo: " << apCopia->titulo << endl;
      cout << "Genero: " << apCopia->genero << endl;
      cout << "Clasificacion: " << apCopia->clasificacion << endl;
      cout << "Precio: " << apCopia->precio;
      return;
    } // if si lo encontro

    apCopia =
        apCopia->next; //? aqui se guarda la direccion de memoria del siguiente
  }                    // while
  cout << "El videojuego con el titulo: " << titBuscar << " no fue localizado"
       << endl;

  return;
} // buscarTitulo()

//! menu()
//! ==============================================================
void menu(void) {
  cout << endl << endl;
  cout << "Listado de mis videojuegos favoritos" << endl;
  cout << "====================================" << endl;
  cout << "1. Agregar un videojuego al inicio de la lista" << endl;
  cout << "2. Consultar mi listado de videojuegos" << endl;
  cout << "3. Buscar un videojuego por su tipo" << endl;
  cout << "0. Salir" << endl;

  return;
} // menu()
