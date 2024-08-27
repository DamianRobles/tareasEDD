/*
  Fecha: martes 27 agosto de 2024
  Autor: Dali
  Practica No.: 7
  Objetivo: Arreglos de estructuras anidadas
*/

// librerias
#include <iostream>
using namespace std;

// TDA
struct domicilio{
  char calle[25];
  int numero;
  char colonia[30];
  int cp;
};
struct nombre{
  char nomPila[30];
  char aPaterno[30];
  char aMaterno[30];
};
struct amigo{
  nombre nomAmigo;
  domicilio domAmigo;
  char numTel[20];
}


// prototipo de funcion


int main(void){
  // declaracion de variables
  amigo amigoNuevo;

  


  return 0;
} // main

// definicion de funciones

// fin de archivo