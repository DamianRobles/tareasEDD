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
  *! Implementa la función copiar una cadena en otra usando apuntadores
  *! Implementa la función comparar dos cadenas
  *! Implementa la función imprimir una cadena al revés usando apuntadores
  *-! Implementa la función convertir a mayúsculas una cadena usando apuntadores
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
  cout << "Func. calc. long. cadena" << endl;
  cout << pelicula << " tiene " << longCad(pelicula) << " caracteres de longitud" << endl;
  cout << endl << endl;

  // 2. Funcion para concatenar dos cadenas
  cout << "Func. concat. dos cadenas" << endl;
  cout << "Pelicula: " << pelicula << endl;
  cout << "Personaje: " << personaje << endl;
  conCad(pelicula, personaje);
  cout << "Ahora pelicula contiene: " << pelicula << endl;
  cout << endl << endl;

  // 3. Funcion convertir a minusculas
  cout << "Func. conv. a minus." << endl;
  cout << "Pelicula antes de conv. a minus.: " << pelicula << endl;
  minusCad(pelicula);
  cout << "Pelicula en minusculas: " << pelicula << endl;
  cout << endl << endl;

  // 4. Funcion copiar una cadena en otra
  cout << "Fuc. copiar una cadena a otra" << endl;
  cout << "Pelicula: " << pelicula << endl;
  cout << "Personaje: " << personaje << endl;
  copCad(pelicula, personaje);
  cout << "Ahora pelicula contiene: " << pelicula << endl;
  cout << endl << endl;

  // 5. Funcion comparar dos cadenas
  cout << "Fuc. comparar dos cadenas" << endl;
  cout << "Pelicula: " << pelicula << endl;
  cout << "Personaje: " << personaje << endl;
  if(cmpCad(pelicula, personaje)){
    cout << "Peliculas y personajes son iguales" << endl;
  } else{
    cout << "Peliculas y personajes son diferentes" << endl;
  } // if-else
  cout << endl << endl;


  // 6. Funcion imprimir una cadena al reves (TAREA 1)
  cout << "Fuc. imprimir cadena al reves" << endl;
  cout << "Pelicula: " << pelicula << endl;
  revCad(pelicula);
  cout << "Pelicula al reves: " << pelicula << endl;
  cout << endl << endl;

  // 7. Funcion convertir a mayusculas (TAREA 2)
  cout << "Fuc. conv. a mayus." << endl;
  cout << "Pelicula antes de conv. a mayus.: " << pelicula << endl;
  mayusCad(pelicula);
  cout << "Pelicula en mayusculas: " << pelicula << endl;
  cout << endl << endl;

  return 0;
} //* main


//* fin de archivo