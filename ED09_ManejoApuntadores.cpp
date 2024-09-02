/*
  Fecha: jueves 29 agosto de 2024
  Autor: Dali
  Practica No.: 9
  Objetivo: manipulacion de apuntadores
*/

// librerias
#include <iostream>
using namespace std;

int main(void){
  // declaracion de variables
  int ruta = 636;
  int *apRuta = NULL; // se declara apuntador y se inicializa en NULL
  double salario = 12543.76, *apSalario = &salario;

  // imprimir
  cout << "Ruta (var): " << ruta << endl;
  cout << "Direccion de ruta (var): " << &ruta << endl;
  cout << "Numero de bytes (var): " << sizeof(ruta) << endl;
  cout << "=======================================" << endl;
  apRuta = &ruta; // apRuta "apunta" a ruta
  cout << "Ruta (apt): " << *apRuta << endl;
  cout << "Direccion de ruta (apt): " << apRuta << endl;
  cout << "Direccion del apuntador apRuta (apt): " << &apRuta << endl;

  cout << "=======================================" << endl;
  // salario y apSalario
  cout << "Bytes para salario: " << sizeof(salario) << endl;
  cout << "Direccion de salario (var): " << &salario << endl;
  cout << "Direccion de salario (apt): " << apSalario << endl;
  cout << "Salario (var): " << salario << endl;
  cout << "Salario (apt): " << *apSalario << endl;
  
  return 0;
} // main

// implementacion de funciones


// fin de archivo