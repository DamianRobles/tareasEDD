/*
  ! Fecha: martes 17 de septiembre de 2024
  ! Autor: Dali
  ! Practica No.: 16
  ! Objetivo: Apuntadores a estructuras
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
  // 1. Declaracion de variables
  persona datosPer;
  persona *apPer = &datosPer;

  cout << "Este programa ejemplifica el uso de apuntadores a estructuras" << endl;

  // leer datos
  cout << "Ingrese el nombre: ";
  cin.getline(datosPer.nombre, 30, '\n');
  cout << "Ingrese la edad: ";
  cin >> datosPer.edad;
  cout << "Ingrese el genero: (F - Fem , M - Mas , O - Otro): ";
  cin >> datosPer.genero;
  cout << "Ingrese la estatura: ";
  cin >> datosPer.estatura;

  // mostrara datos usando la variable  
  cout << endl << endl;
  cout << "Datos almacenados en la direccion: " << &datosPer << endl;
  cout << "Nombre  : " << datosPer.nombre << endl;
  cout << "Edad    : " << datosPer.edad << endl;
  cout << "Genero  : " << datosPer.genero << endl;
  cout << "Estatura: " << datosPer.estatura << endl;
  cout << "============================================" << endl;
  
  // mostrara datos usando el apuntador con op. flecha ->
  cout << endl << endl;
  cout << "Datos almacenados en la direccion: " << apPer << endl;
  cout << "Nombre  : " << apPer -> nombre << endl;
  cout << "Edad    : " << apPer -> edad << endl;
  cout << "Genero  : " << apPer -> genero << endl;
  cout << "Estatura: " << apPer -> estatura << endl;
  cout << "============================================" << endl;
  
  // mostrara datos usando el apuntador con la sintaxis (*ap)
  cout << endl << endl;
  cout << "Datos almacenados en la direccion: " << apPer << endl;
  cout << "Nombre  : " << (*apPer).nombre << endl;
  cout << "Edad    : " << (*apPer).edad << endl;
  cout << "Genero  : " << (*apPer).genero << endl;
  cout << "Estatura: " << (*apPer).estatura << endl;
  cout << "============================================" << endl;
  
  return 0;
}