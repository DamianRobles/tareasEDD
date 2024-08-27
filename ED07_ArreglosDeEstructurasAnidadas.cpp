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
};


// prototipo de funcion

// constantes
const int MAX=3;

int main(void){
  // declaracion de variables
  amigo amigoNuevo[MAX];

  cout << "Este programa ejemplifica eluso de arreglos de estructuras anidadas" << endl;

  // leer datos
  for(int i=0; i<MAX; i++){
    cout << "Ingresa los datos de tu nuevo amigo:" << endl;
    cout << "Nombre de pila (ej. Juan): ";
    cin.getline(amigoNuevo[i].nomAmigo.nomPila, 30, '\n');
    cout << "Apellido paterno: ";
    cin.getline(amigoNuevo[i].nomAmigo.aPaterno, 30, '\n');
    cout << "Apellido materno: ";
    cin.getline(amigoNuevo[i].nomAmigo.aMaterno, 30, '\n');

    cout << "Domicilio: ";
    cin.getline(amigoNuevo[i].domAmigo.calle, 25, '\n');
    cout << "Colonia: ";
    cin.getline(amigoNuevo[i].domAmigo.colonia, 25, '\n');
    cout << "Numero: ";
    cin >> amigoNuevo[i].domAmigo.numero;
    cout << "Codigo Postal: ";
    cin >> amigoNuevo[i].domAmigo.cp;
    
    cin.ignore();
    cout << "Numero telefonico: ";
    cin.getline(amigoNuevo[i].numTel, 20, '\n');
  } //for i
  


  return 0;
} // main

// definicion de funciones

// fin de archivo