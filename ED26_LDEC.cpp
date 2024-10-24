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
  // 1) declarar el apuntador
  cancion *nueva;

  // 2) solicitar la memoria
  nueva = (cancion *) malloc(sizeof(cancion));

  // 3) validar el apuntador
  if(nueva == NULL){
    cout << "No hay memoria suficiente para registrar una nueva tarea" << endl;
    return;
  }

  // 4) Solicitar y almacenar los datos
  cout <<  endl << endl;
  cin.ignore();
  cout << endl << "Ingresa los datos de la nueva cancion" << endl;
  cout << "============================" << endl;
  cout << "Titulo: ";
  cin.getline(nueva->titulo,50,'\n');
  cout << "Artista: ";
  cin.getline(nueva->artista,50,'\n');
  cout << "Duracion (mm:ss): ";
  cin.getline(nueva->duracion,6,'\n');
  cout << "Genero: ";
  cin.getline(nueva->genero,30,'\n');

  // 5) agregar la tarea al inicio de la LDEA
  // caso A) lista vacia
  if(apPlayList == NULL){
    apPlayList = nueva;
    apPlayList -> next = apPlayList;
    apPlayList -> before = apPlayList;
    cout << "La cancion fue agregada a la playlist" << endl;
    return;
  } // if lista vacia
  
  // caso B) lista no vacia
  nueva-> next = apPlayList->next;
  nueva->before = apPlayList;
  nueva->next->before = nueva;
  apPlayList->next = nueva;
  cout << "La cancion fue agregada a la playlist" << endl;
  return;
} // agregar()  

//! consultar()
//! ==============================================================
void consultar() {
  // declarar variable
  cancion *apCopia = apPlayList;
  
  // validar si esta vacia
  if(apCopia == NULL){
    cout << "La playlist esta vacia" << endl;
    return;
  }
  
  // mostrar las canciones
  cout << endl << "Cancionces guardadas en la playlist" << endl;
  do{
    // mostrar  cancion
    cout << endl << "============================" << endl;
    cout << "Titulo: " << apCopia->titulo << endl;
    cout << "Artista: " << apCopia->artista << endl;
    cout << "Duracion: " << apCopia->duracion << endl;
    cout << "Genero: " << apCopia->genero << endl;
    
    // ir a la cancion siguiente
    apCopia = apCopia -> next;
  } while(apPlayList != apCopia);
  
  return;
} // consultar

//! eliminar()
//! ==============================================================
void eliminar() {
    // declarar variable
  cancion *apCopia = apPlayList;
  int respuesta;
  
  // caso A) lista vacia
  if(apCopia == NULL){
    cout << "La playlist esta vacia" << endl;
    return;
  }
  
  // mostrar las canciones
  cout << endl << "Cancionces guardadas en la playlist" << endl;
  do{
    // mostrar  cancion
    cout << endl << "============================" << endl;
    cout << "Titulo: " << apCopia->titulo << endl;
    cout << "Artista: " << apCopia->artista << endl;
    cout << "Duracion: " << apCopia->duracion << endl;
    cout << "Genero: " << apCopia->genero << endl;
    cout << endl << "Deseas eliminar la cancion? (1-Si 2-No): ";
    cin >> respuesta;
    if(respuesta == 1){
      // caso B) lista con 1 nodo
      if(apCopia->next == apCopia){
        apPlayList == NULL;
        free(apCopia);
        cout << "La cancion fue eliminada" << endl;
        return;
      }
      // caso C) lista con 2 o mas nodos
      if(apCopia == apPlayList){
        apPlayList = apPlayList->next;
      } // if si se quiere borrar la cancion en apPlayList
      apCopia->before->next = apCopia->next;
      apCopia->next->before = apCopia->before;
      free(apCopia);
      cout << "La cancion fue eliminada" << endl;
      return;
    }
    
    // ir a la cancion siguiente
    apCopia = apCopia -> next;
  } while(apPlayList != apCopia);
  
  cout << "No eliminaste ninguna cancion" << endl;
  return;
} // eliminar

//! buscar()
//! ==============================================================
void buscar() {
  // declarar variable
  cancion *apCopia = apPlayList;
  char titBuscar[50];
  
  // validar si esta vacia
  if(apCopia == NULL){
    cout << "La playlist esta vacia" << endl;
    return;
  }
  
  // solicitar el titulo de la cancion a buscar
  cin.ignore();
  cout << "Ingresa el titulo de la cancion a buscar:";
  cin.getline(titBuscar, 50, '\n');
  
  // mostrar las canciones
  cout << endl << "Buscando cancion con titulo: " << titBuscar << endl;
  do{
    if(strcmp(titBuscar, apCopia->titulo) == 0){
      // mostrar  cancion
      cout << "Cancion encontrada" << endl;
      cout << endl << "============================" << endl;
      cout << "Titulo: " << apCopia->titulo << endl;
      cout << "Artista: " << apCopia->artista << endl;
      cout << "Duracion: " << apCopia->duracion << endl;
      cout << "Genero: " << apCopia->genero << endl;
      return;
    }
    // ir a la cancion siguiente
    apCopia = apCopia -> next;
  } while(apPlayList != apCopia);
  
  cout << "Cancion no encontrada" << endl;
  
  return;
} // buscar

//! menu()
//! ==============================================================
void menu(void) {
  cout << endl << endl;
  cout << "Playlist" << endl;
  cout << "====================================" << endl;
  cout << "1. Agregar cancion a la lista" << endl;
  cout << "2. Consultar canciones en la lista (Tarea)" << endl;
  cout << "3. Eliminar cancion de la lista" << endl;
  cout << "4. Buscar canciones de la lista (Clase)" << endl;
  cout << "0. Salir" << endl;
  cout << "====================================" << endl;

  return;
} // menu()
