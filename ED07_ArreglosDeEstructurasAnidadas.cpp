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


// constantes
const int MAX=3;

// prototipo de funcion
void imprimir(amigo, int);
amigo leer(void);

int main(void){
  // declaracion de variables
  amigo amigoNuevo[MAX];

  cout << "Este programa ejemplifica eluso de arreglos de estructuras anidadas" << endl;

  // leer datos
  for(int i=0; i<MAX; i++){
    amigoNuevo[i] = leer();
  } //for i
  
  // imprimir datos
  for(int i=0; i<MAX; i++){
    imprimir(amigoNuevo[i], i+1);
  } // for i

  return 0;
} // main

// implementacion de funciones
//=========================================================
amigo leer(void){
  amigo amigoN;

  // leer datos
  cout << "Ingresa los datos de tu nuevo amigo:" << endl;
  cout << "Nombre de pila (ej. Juan): ";
  cin.getline(amigoN.nomAmigo.nomPila, 30, '\n');
  cout << "Apellido paterno: ";
  cin.getline(amigoN.nomAmigo.aPaterno, 30, '\n');
  cout << "Apellido materno: ";
  cin.getline(amigoN.nomAmigo.aMaterno, 30, '\n');

  cout << "Domicilio: ";
  cin.getline(amigoN.domAmigo.calle, 25, '\n');
  cout << "Colonia: ";
  cin.getline(amigoN.domAmigo.colonia, 25, '\n');
  cout << "Numero: ";
  cin >> amigoN.domAmigo.numero;
  cout << "Codigo Postal: ";
  cin >> amigoN.domAmigo.cp;
  
  cin.ignore();
  cout << "Numero telefonico: ";
  cin.getline(amigoN.numTel, 20, '\n');

  return amigoN;
} // leer

//=========================================================
void imprimir(amigo datos, int num){
  cout << "====================================================" << endl;
  cout << "Datos de tu nuevo amigo numero " << num << endl;
  cout << "Nombre de pila      : " << datos.nomAmigo.nomPila << endl;
  cout << "Apellido paterno    : " << datos.nomAmigo.aPaterno << endl;
  cout << "Apellido materno    : " << datos.nomAmigo.aMaterno << endl;
  cout << "Domicilio (calle)   : " << datos.domAmigo.calle << endl;
  cout << "Domicilio (colonia) : " << datos.domAmigo.colonia << endl;
  cout << "Numero              : " << datos.domAmigo.numero << endl;
  cout << "Codigo Postal       : " << datos.domAmigo.cp << endl;
  cout << "Numero telefonico   : " << datos.numTel << endl;
  cout << "====================================================" << endl;
  
  return;
} // imprimir

// fin de archivo