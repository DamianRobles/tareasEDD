/*
  ! Fecha: Lunes 16 de septiembre de 2024
  ! Autor: Dali
  ! Practica No.: 14
  ! Objetivo: Apuntadores y cadenas
/*
  ? Leer y almacenar una cadena de caracteres en arreglo
  ? Implementa la función longitud de cadena usando apuntadores
  ? Implementa la función concatenar dos cadenas usando apuntadores
  ? Implementa la función convertir a minúsculas una cadena usando apuntadores
  ? Implementa la función copiar una cadena en otra usando apuntadores
  ? Implementa la función comparar dos cadenas
*/

//* librerias
#include <iostream>
#include "biblioCad.h"
using namespace std;

//* funcion principal
int main(void){
  // declaracion de variables
  char pelicula[50];

  cout << "Este programa ejemplifica la relacion Apuntadores y cadenas" << endl;

  // leer la cadena
  cout << "Ingresa el titulo de tu pelicula favorita: ";
  cin.getline(pelicula, 50, '\n');

  // 1. Funcion para calcular la longitud de una cadena
  cout << pelicula << " tiene " << longCad(pelicula) << " caracteres de longitud" << endl;

  return 0;
} //* main


//* fin de archivo