/*
  ! Fecha: martes 3 de septiembre de 2024
  ! Autor: Dali
  ! Practica No.: 10
  ! Objetivo: paso de parametros a funciones
*/

//* librerias
#include <iostream>
using namespace std;

//* prototipos
void modificador(int);
void modificadorD(int &);
void modificadorAp(int *);

int main(void){
  // declaracion de variables
  int numero;

  cout << "Este programa ejemplicica las 3 formas de pasar parametros" 
      << " a funciones: copia o valor, direccion o referencia, apuntador" << endl;

  // solicitar el valor de numero
  cout << "Ingresa un numero entero: ";
  cin >> numero;

  // 1) Paso de parametros por valor o copia
  cout << "1) Paso por valor o copia" << endl;
  cout << "numero= " << numero << " ANTES de ir a la funcion" << endl;
  modificador(numero);
  cout << "numero= " << numero << " DESPUES de ir a la funcion" << endl;
  
  // 2) Paso de parametros por direccion o referencia
  cout << endl << "2) Paso por referencia o direccion" << endl;
  cout << "numero= " << numero << " ANTES de ir a la funcion" << endl;
  modificadorD(numero);
  cout << "numero= " << numero << " DESPUES de ir a la funcion" << endl;

  // 3) Paso de parametros por apuntador
  numero = 2005;
  cout << endl << "3) Paso por apuntador" << endl;
  cout << "numero= " << numero << " ANTES de ir a la funcion" << endl;
  modificadorAp(&numero);
  cout << "numero= " << numero << " DESPUES de ir a la funcion" << endl;
  
  return 0;
} //* main

//* implementacion de funciones
void modificador(int num){
  num = 999;
  return;
} //* modificador
// ==================================================================
void modificadorD(int &num){
  num = 666;
  return;
} //* modificadorD
// ==================================================================
void modificadorAp(int *apNum){
  *apNum = 12321;
  return;
} //* modificadorAp

//* fin de archivo