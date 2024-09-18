/*
  ! Fecha: martes 17 de septiembre de 2024
  ! Autor: Dali
  ! Practica No.: 17
  ! Objetivo: Apuntadores a estructuras usando memoria dinamica
*/

// librerias
#include <iostream>
#include <stdlib.h>
using namespace std;

// tda's
struct persona{
  char nombre[30];
  int edad;
  char genero;
  float estatura;
};

int main(void){
  // 1. declarar variables
  persona *apPer = NULL;

  cout << "Este programa ejemplifica el uso de apuntadores a estructuras usando memoria dinamica" << endl;

  // 2. solicitar la memoria
  cout << endl << endl;
  cout << "Numero de bytes necesarios para almacenar los datos de 1 persona: "<< sizeof(persona) << endl;
  apPer = (persona *) malloc(sizeof(persona));
  //apPer = new(persona);
  cout << endl << endl;

  // 3. validar el apuntador
  if(apPer == NULL){
    cout << "Memoria insuficiente para guardar los datos de una persona" << endl;
    return -1;
  } // if
  
  // 4. solicitar los datos
  cout << "Ingrese el nombre: ";
  cin.getline(apPer -> nombre, 30, '\n');
  cout << "Ingrese la edad: ";
  cin >> apPer -> edad;
  cout << "Ingrese el genero: (F - Fem , M - Mas , O - Otro): ";
  cin >> apPer -> genero;
  cout << "Ingrese la estatura: ";
  cin >> apPer -> estatura;

  // 4. mostrar datos usando el apuntador con op. flecha ->
  cout << endl << endl;
  cout << "Datos almacenados en la direccion: " << apPer << endl;
  cout << "Nombre  : " << apPer -> nombre << endl;
  cout << "Edad    : " << apPer -> edad << endl;
  cout << "Genero  : " << apPer -> genero << endl;
  cout << "Estatura: " << apPer -> estatura << endl;
  cout << "============================================" << endl;

  // 5. liberar la memoria
  free(apPer);
  //delete(apPer);
  
  return 0;
}