/*
  ! Fecha: Lunes 16 de septiembre de 2024
  ! Autor: Dali
  ! Practica No.: 14
  ! Objetivo: Apuntadores y cadenas
*/
/*
  *! Leer y almacenar una cadena de caracteres en arreglo
  *! Implementa la función longitud de cadena usando apuntadores
  *! Implementa la función concatenar dos cadenas usando apuntadores
  *! Implementa la función convertir a minúsculas una cadena usando apuntadores
  ! Implementa la función copiar una cadena en otra usando apuntadores
  ! Implementa la función comparar dos cadenas
*/

//* librerias
#include <iostream>
#include "biblioCad.h" // Busca el archivo en la misma carpeta que el CPP
using namespace std;

//* funcion principal
int main(void){
  // declaracion de variables
  char pelicula[100], personaje[50];

  cout << "Este programa ejemplifica la relacion Apuntadores y cadenas" << endl;

  // leer la cadena
  cout << "Ingresa el titulo de tu pelicula favorita: ";
  cin.getline(pelicula, 100, '\n');
  cout << "Ingresa el nombre del personaje favorito de tu pelicula: ";
  cin.getline(personaje, 50, '\n');
  cout << endl << endl;

  // 1. Funcion para calcular la longitud de una cadena
  cout << pelicula << " tiene " << longCad(pelicula) << " caracteres de longitud" << endl;
  cout << endl << endl;

  // 2. Funcion para concatenar dos cadenas
  cout << "Pelicula: " << pelicula << endl;
  cout << "Personaje: " << personaje << endl;
  conCad(pelicula, personaje);
  cout << "Ahora pelicula contiene: " << pelicula << endl;
  cout << endl << endl;

  // 3. Funcion convertir a minusculas
  cout << "Pelicula antes de conv. a minus.: " << pelicula << endl;
  minusCad(pelicula);
  cout << "Pelicula en minusculas: " << pelicula << endl;
  cout << endl << endl;

  // 4. Funcion copiar una cadena en otra
  cout << "Pelicula: " << pelicula << endl;
  cout << "Personaje: " << personaje << endl;
  copCad(pelicula, personaje);
  cout << "Ahora pelicula contiene: " << pelicula << endl;
  cout << endl << endl;


  return 0;
} //* main


//* fin de archivo