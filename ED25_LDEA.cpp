/*
  ! Fecha: jueves 17 de octubre de 2024
                 jueves 24 de octubre de 2024
  ! Au}tor: Dali
  ! Practica No.: 25
  ! Objetivo: LDEA - lista doblemente enlazada abierta
*/

//* librerias
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//* tda's
struct tarea {
  // datos
  char descripcion[100];
  char usuario[60];
  char fecha[15];
  // apuntadores
  tarea *next;
  tarea *before;
};

//* variables globales
// apuntador a la LDEA
tarea *apInicio = NULL, *apFinal = NULL;

//* operaciones
void agregarInicio();
void agregarFinal();
void consultarFI();
void consultarIF();
void eliminarPrimero();
void eliminarUltimo();
void buscar();
void filtrar();

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
      agregarInicio();
      break;
    case 2:
      agregarFinal();
      break;
    case 3:
      consultarIF();
      break;
    case 4:
      consultarFI();
      break;
    case 5:
      eliminarPrimero();
      break;
    case 6:
      eliminarUltimo();
      break;
    case 7:
      buscar();
      break;
    case 8:
      filtrar();
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
  // 1) declarar el apuntador
  tarea *nueva;

  // 2) solicitar la memoria
  nueva = (tarea *) malloc(sizeof(tarea));

  // 3) validar el apuntador
  if(nueva == NULL){
    cout << "No hay memoria suficiente para registrar una nueva tarea" << endl;
    return;
  }

  // 4) Solicitar y almacenar los datos
  cout <<  endl << endl;
  cin.ignore();
  cout << endl << "Ingresa los datos de la nueva tarea" << endl;
  cout << "============================" << endl;
  cout << "Descripcion de la tarea: ";
  cin.getline(nueva->descripcion,100,'\n');
  cout << "Usuario que realiza la actualizacion: ";
  cin.getline(nueva->usuario,60,'\n');
  cout << "Fecha de la actualizacion (dd/mm/aaaa): ";
  cin.getline(nueva->descripcion,15,'\n');

  // 5) agregar la tarea al inicio de la LDEA
  // caso A) lista vacia
  if(apInicio == NULL && apFinal == NULL){
    nueva -> next = NULL;
    nueva -> before = NULL;
    apInicio = nueva;
    apFinal = nueva;
    cout << "La tarea fue agregada al inicio del gestor" << endl;
    return;
  } // if lista vacia
  
  // caso B) lista no vacia
  apInicio -> before = nueva;
  nueva -> next = apInicio;
  nueva -> before = NULL;
  apInicio = nueva;
  cout << "La tarea fue agregada al inicio del gestor" << endl;
  
  return;
} // agregarInicio()  


//!? agregarFinal() (TAREA)
//!? ==============================================================
void agregarFinal() {
    // 1) declarar el apuntador
  tarea *nueva;

  // 2) solicitar la memoria
  nueva = (tarea *) malloc(sizeof(tarea));

  // 3) validar el apuntador
  if(nueva == NULL){
    cout << "No hay memoria suficiente para registrar una nueva tarea" << endl;
    return;
  }

  // 4) Solicitar y almacenar los datos
  cout <<  endl << endl;
  cin.ignore();
  cout << endl << "Ingresa los datos de la nueva tarea" << endl;
  cout << "============================" << endl;
  cout << "Descripcion de la tarea: ";
  cin.getline(nueva->descripcion,100,'\n');
  cout << "Usuario que realiza la actualizacion: ";
  cin.getline(nueva->usuario,60,'\n');
  cout << "Fecha de la actualizacion (dd/mm/aaaa): ";
  cin.getline(nueva->descripcion,15,'\n');

  // 5) agregar la tarea al final de la LDEA
  // caso A) lista vacia
  if(apInicio == NULL && apFinal == NULL){
    nueva -> next = NULL;
    nueva -> before = NULL;
    apInicio = nueva;
    apFinal = nueva;
    cout << "La tarea fue agregada al final del gestor" << endl;
    return;
  } // if lista vacia
  
  // caso B) lista no vacia
  apFinal -> next = nueva;
  nueva -> next = NULL;
  nueva -> before = apFinal;
  apFinal = nueva;
  cout << "La tarea fue agregada al final del gestor" << endl;
  
  return;
} // agregarFinal()

//!? consultarIF() (TAREA))
//!? ==============================================================
void consultarIF(){
  // declarar variable
  tarea *apCopia = apInicio;
  
  // validar si esta vacia
  if(apCopia == NULL){
    cout << "El gestor esta vacio" << endl;
    return;
  }
  
  // mostrar las tareas
  cout << endl << "Tareas guardadas en el gestor del inicio al final" << endl;
  while(apCopia != NULL){
    // mostrar tarea
    cout << endl << "============================" << endl;
    cout << "Descripcion de la tarea: " << apCopia->descripcion << endl;
    cout << "Usuario que realiza la actualizacion: " << apCopia->usuario << endl;
    cout << "Fecha de la actualizacion (dd/mm/aaaa): " << apCopia->descripcion << endl;
    cout << "Tarea anterior" << apCopia -> before << endl;
    cout << "Siguiente tarea" << apCopia -> next;
    
    // ir a la tarea siguiente
    apCopia = apCopia -> next;
  } //while
  
  return;
} // consultarIF()

//! consultarFI() 
//! ==============================================================
void consultarFI(){
  // declarar variable
  tarea *apCopia = apFinal;
  
  // validar si esta vacia
  if(apCopia == NULL){
    cout << "El gestor esta vacio" << endl;
    return;
  }
  
  // mostrar las tareas
  cout << endl << "Tareas guardadas en el gestor del final al inicio" << endl;
  while(apCopia != NULL){
    // mostrar tarea
    cout << endl << "============================" << endl;
    cout << "Descripcion de la tarea: " << apCopia->descripcion << endl;
    cout << "Usuario que realiza la actualizacion: " << apCopia->usuario << endl;
    cout << "Fecha de la actualizacion (dd/mm/aaaa): " << apCopia->descripcion << endl;
    cout << "Tarea anterior" << apCopia -> before << endl;
    cout << "Siguiente tarea" << apCopia -> next;
    
    // ir a la tarea anterior
    apCopia = apCopia -> before;
  }
  
  return;
} // consultarFI()

//!? eliminarPrimero() (TAREA))
//!? ==============================================================
void eliminarPrimero(){
  // declaracion de variables
  tarea *apBorrar = apInicio;
  int respuesta;
  
  // validar si esta vacia
  if(apBorrar == NULL){
    cout << "El gestor esta vacio" << endl;
    return;
  }
  
  // mostrar el primer  nodo
  cout << endl << "         Tarea a ser eliminada" << endl;
  cout << "============================" << endl;
  cout << "Descripcion de la tarea: " << apBorrar->descripcion << endl;
  cout << "Usuario que realiza la actualizacion: " << apBorrar->usuario << endl;
  cout << "Fecha de la actualizacion (dd/mm/aaaa): " << apBorrar->descripcion << endl;
  cout << "Estas seguro de eliminarlo? (1- Si 2- No): ";
  cin >> respuesta;
  if(respuesta == 1){
    if(apBorrar -> next == NULL){
      // 1 nodo
      apInicio = apFinal = NULL;
      free(apBorrar);
    } // if si hay 1 nodo 
    else{
      // 2 o mas nodos
      apBorrar->next->before = NULL;
      apInicio = apBorrar->next;
      free(apBorrar);      
    }// else si hay 2 o mas nodos
    
    cout << "La ultima tarea fue eliminada"<< endl;
    return;
  }
  else{
    cout << "No se elimino ninguna tarea" << endl;
  } // if else
    
  return;
} //eliminarPrimero()

//! eliminarUltimo()
//! ==============================================================
void eliminarUltimo(){
  // declaracion de variables
  tarea *apBorrar = apFinal;
  int respuesta;
  
  // validar si esta vacia
  if(apBorrar == NULL){
    cout << "El gestor esta vacio" << endl;
    return;
  }
  
  // mostrar el ultimo nodo
  cout << endl << "         Tarea a ser eliminada" << endl;
  cout << "============================" << endl;
  cout << "Descripcion de la tarea: " << apBorrar->descripcion << endl;
  cout << "Usuario que realiza la actualizacion: " << apBorrar->usuario << endl;
  cout << "Fecha de la actualizacion (dd/mm/aaaa): " << apBorrar->descripcion << endl;
  cout << "Estas seguro de eliminarlo? (1- Si 2- No): ";
  cin >> respuesta;
  if(respuesta == 1){
    if(apBorrar -> before == NULL){
      // 1 nodo
      apInicio = apFinal = NULL;
      free(apBorrar);
    } // if si hay 1 nodo 
    else{
      // 2 o mas nodos
      apBorrar->before->next = NULL;
      apFinal = apBorrar->before;
      free(apBorrar);      
    }// else si hay 2 o mas nodos
    
    cout << "La ultima tarea fue eliminada"<< endl;
    return;
  }
  else{
    cout << "No se elimino ninguna tarea" << endl;
  } // if else
    
  return;
} // eliminarUltimo()

//! buscar()
//! ==============================================================
void buscar(){
    // declarar variable
  tarea *apCopia = apInicio;
  char tareaBuscar[100];
  
  // validar si esta vacia
  if(apCopia == NULL){
    cout << "El gestor esta vacio" << endl;
    return;
  }
  
  cout << "Ingrese la descripcion de la tarea a buscar: ";
  cin.ignore();
  cin.getline(tareaBuscar, 100, '\n');
  
  
  // mostrar las tareas
  cout << endl << "Busqueda de tareas guardadas en el gestor" << endl;
  while(apCopia != NULL){
    // mostrar tarea
    if(strcmp(tareaBuscar, apCopia->descripcion)==0){
      cout << endl << "Tarea encontrada" << endl;
      cout << endl << "============================" << endl;
      cout << "Descripcion de la tarea: " << apCopia->descripcion << endl;
      cout << "Usuario que realiza la actualizacion: " << apCopia->usuario << endl;
      cout << "Fecha de la actualizacion (dd/mm/aaaa): " << apCopia->descripcion << endl;
      return;
    }
    // ir a la tarea siguiente
    apCopia = apCopia -> next;
  } //while
  
  cout << "La tarea " << tareaBuscar << " no fue encontrada" << endl;
  
  return;
} // buscar()


//! filtrar()
//! ==============================================================
void filtrar(){
  // declarar variable
  tarea *apCopia = apInicio;
  char usuarioBuscar[100];
  bool encontrado = false;
  
  // validar si esta vacia
  if(apCopia == NULL){
    cout << "El gestor esta vacio" << endl;
    return;
  }
  
  cout << "Ingrese el nombre de usuario: ";
  cin.ignore();
  cin.getline(usuarioBuscar, 60, '\n');
  
  
  // mostrar las tareas
  cout << endl << " Filtrado de tareas guardadas en el gestor" << endl;
  while(apCopia != NULL){
    // mostrar tarea
    cout << endl << "Tareas realizadas por: " << apCopia->usuario << endl;
    if(strcmp(usuarioBuscar, apCopia->usuario)==0){
      cout << endl << "============================" << endl;
      cout << "Descripcion de la tarea: " << apCopia->descripcion << endl;
      cout << "Usuario que realiza la actualizacion: " << apCopia->usuario << endl;
      cout << "Fecha de la actualizacion (dd/mm/aaaa): " << apCopia->descripcion << endl << endl;
      encontrado = true;
    }
    // ir a la tarea siguiente
    apCopia = apCopia -> next;
  } //while
  
  if(!encontrado){
    cout << "No existen tareas realizadas por el usuario " << usuarioBuscar << endl;
    return;
  }
  
  return;
} // filtrar()


//! menu()
//! ==============================================================
void menu(void) {
  cout << endl << endl;
  cout << "         Gestor de tareas" << endl;
  cout << "====================================" << endl;
  cout << "1. Agregar al inicio de la lista (Clase)" << endl;
  cout << "2. Agregar al final de la lista (Tarea)" << endl;
  cout << "3. Consultar la lista de inicio a fin (Tarea)" << endl;
  cout << "4. Consultar la lista de fin a inicio (Clase)" << endl;
  cout << "5. Eliminar el primer elemento de la lista (Tarea)" << endl;
  cout << "6. Eliminar el último elemento de la lista (Clase)" << endl;
  cout << "7. Buscar un elemento en la lista" << endl;
  cout << "8. Filtrar la lista" << endl;
  cout << "0. Salir" << endl;
  cout << "====================================" << endl;

  return;
} // menu()
