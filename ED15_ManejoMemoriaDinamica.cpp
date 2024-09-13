/*
  ! Fecha: jueves 12 de septiembre de 2024
  ! Autor: Dali
  ! Practica No.: 15
  ! Objetivo: Manejo de memoria dinamica
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){
  // 1. Declaracion de variables
  int *apEntero = NULL;
  float *apFlotante = NULL;

  // 2. solicitar memoria dinamica
  cout << "Bytes para un entero: " << sizeof(int) << endl;
  apEntero = (int *) malloc(sizeof(int));
  cout << "Bytes para un flotante: " << sizeof(float) << endl;
  apFlotante = (float *) malloc(sizeof(float));

  // 3. validar el apuntador
  if(apEntero == NULL){
    cout << "No hay memoria suficiente para un int" << endl;
  } // if
  if(apFlotante == NULL){
    cout << "No hay memoria suficiente para un float" << endl;
  } // if

  // 4. si hubo memoria
  cout << "Ingresa un numero entero: ";
  cin >> *apEntero;
  cout << "El valor ingresado fue: " << *apEntero << endl;
  cout << "Esta almacenado en la direccion: " << apEntero << endl;

  cout << "Ingresa un numero flotante: ";
  cin >> *apFlotante;
  cout << "El valor ingresado fue: " << *apFlotante << endl;
  cout << "Esta almacenado en la direccion: " << apFlotante << endl;

  // 5. liberar memoria
  free(apEntero);
  free(apFlotante);

  return 0;
}