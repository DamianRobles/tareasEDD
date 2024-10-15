/*
  ! Fecha: jueves 10 de octubre de 2024
           martes 15 de octubre de 2024
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
  char actividad[50];
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
  agendaSemanal *apNuevo = NULL;

  // 2) solicitar memoria
  apNuevo = (agendaSemanal *)malloc(sizeof(agendaSemanal));

  // 3) validar apuntador
  if (apNuevo == NULL) {
    cout << "No hay memoria disponible" << endl;
    return;
  }
  // 4) solicitar datos de la nueva paleta y guardarlos
  cin.ignore();
  cout << endl << "Ingresa la nueva actividad" << endl;
  cout << "==============================" << endl;
  cout << "Ingrese la actividad (ej. trotar): ";
  cin.getline(apNuevo->actividad, 50, '\n');
  cout << "Ingrese el dia (ej. 20/enero/2025): ";
  cin.getline(apNuevo->dia, 20, '\n');
  cout << "Ingrese el horario (ej. 19:00): ";
  cin.getline(apNuevo->horario, 20, '\n');
  cout << "Ingrese la duracion en minutos (ej. 30): ";
  cin >> apNuevo->duracion;
  cin.ignore();

  // 5) agregar el nodo a la LSEC
  // caso A) lista vacia
  if(apAgenda == NULL){
    apAgenda = apNuevo;
    apAgenda -> next = apNuevo;
    cout << "Actividad agregada a la agenda" << endl;
    return;
  } // if lista vacia
  // caso B) lista con 1 nodo
  apNuevo -> next = apAgenda -> next;
  apAgenda -> next = apNuevo;
  cout << "Actividad agregada a la agenda" << endl;  

  return;
} // insertar()

//! cancelar()
//! ==============================================================
void cancelar(){
  // declaracion de variables
  agendaSemanal *apBorrar = apAgenda;
  int respuesta;

  // validar si la lista esta vacia
  // caso A) lista vacia
  if(apBorrar == NULL){
    cout << "La lista esta vacia" << endl;
    return;
  }

  // caso B) lista con 1 nodo
  if(apAgenda -> next == apAgenda){
    cout << endl << "La siguiente es la unica actividad en la agenda" << endl;
    cout << "========================" << endl << endl;
    cout << "Actividad: " << apBorrar -> actividad << endl;
    cout << "Dia: " << apBorrar -> dia << endl;
    cout << "Horario: " << apBorrar -> horario << endl;
    cout << "Duracion: "<< apBorrar -> duracion << endl;
    cout << "========================" << endl << endl;
    cout << "Deseas cancelarla? (1-Si 2-No)" << endl;
    cin >> respuesta;
    if(respuesta == 1){
      apAgenda = NULL;
      free(apBorrar);
      cout << "La actividad fue cancelada" << endl;
      return;
    }
    else{
      cout << "La actividad no fue cancelada" << endl;
      return;
    }
  } // iif lista con 1 actividad

  
  // caso C) lista con 2 o mas nodos
  do{
    cout << "========================" << endl << endl;
    cout << "Actividad: " << apBorrar -> actividad << endl;
    cout << "Dia: " << apBorrar -> dia << endl;
    cout << "Horario: " << apBorrar -> horario << endl;
    cout << "Duracion: "<< apBorrar -> duracion << endl;
    cout << "========================" << endl << endl;
    cout << "Deseas cancelarla? (1-Si 2-No)" << endl;
    cin >> respuesta;
    if(respuesta == 1){
      // mover apAgenda un nodo antes del que se borrara
      while(apAgenda -> next != apBorrar){
        apAgenda = apAgenda -> next;
      }
      apAgenda -> next = apBorrar -> next;
      free(apBorrar);
      cout << "La actividad fue cancelada" << endl;
      return;
    } // if si si la cancela
    
    apBorrar = apBorrar -> next;
  } while(apBorrar != apAgenda); 

  cout << "Ninguna actividad fue cancelada" << endl;
  return;
} // cancelar()


//! consultar()
//! ==============================================================
void consultar(){
  // declarar variable
  agendaSemanal *apCopia = apAgenda;

  // validar apuntador
  if(apCopia == NULL){
    cout << "La lista esta vacia" << endl;
    return;
  }

  // si hay por lo menos 1 actividad
  cout << endl << " Actividades a realizar" << endl;
  cout << "========================" << endl;
  do{
    cout << "Actividad: " << apCopia -> actividad << endl;
    cout << "Dia: " << apCopia -> dia << endl;
    cout << "Horario: " << apCopia -> horario << endl;
    cout << "Duracion: "<< apCopia -> duracion << endl;
    cout << "========================" << endl << endl;
    apCopia = apCopia -> next;
  } while(apCopia != apAgenda);
  return;
} // consultar()


//! buscar()
//! ==============================================================
void buscar(){
  // declarar variable
  agendaSemanal *apCopia = apAgenda;
  char buscar[50];
  bool encontrada = false;

  // validar apuntador
  if(apCopia == NULL){
    cout << "La lista esta vacia" << endl;
    return;
  }

  cout << "Actividad a buscar: ";
  cin.ignore();
  cin.getline(buscar,50,'\n');
  do{
    if(strcmp(buscar,apCopia -> actividad) == 0){
      cout << "  Actividad encontrada" << endl;
      cout << "========================" << endl << endl;
      cout << "Actividad: " << apCopia -> actividad << endl;
      cout << "Dia: " << apCopia -> dia << endl;
      cout << "Horario: " << apCopia -> horario << endl;
      cout << "Duracion: "<< apCopia -> duracion << endl;
      cout << "========================" << endl << endl;
      encontrada = true;
    }
    apCopia = apCopia -> next;
  } while(apCopia != apAgenda);
  if(!encontrada){
    cout << "Actividad " << buscar << " no fue encontrada" << endl;
  }
  return;
} // buscar()

//! menu()
//! ==============================================================
void menu(void) {
  cout << endl << endl;
  cout << "         Agenda semanal" << endl;
  cout << "====================================" << endl;
  cout << "1. Agregar actividad" << endl;
  cout << "2. Cancelar actividad" << endl;
  cout << "3. Consultar las actividades" << endl;
  cout << "4. Buscar actividad" << endl;
  cout << "0. Salir" << endl;
  cout << "====================================" << endl;

  return;
} // menu()
