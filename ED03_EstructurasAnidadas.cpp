// Fecha: jueves 22 agosto de 2024
// Autor: Dali
// Practica No.: 3
// Objetivo: Estructuras anidadas

// Librerias
#include <iostream>
using namespace std;

// TDA
struct nombre{
  // elementos
  char nPila[50];
  char aPaterno[25];
  char aMaterno[25];
};
struct persona{
  // elementos
  int edad;
  bool vivo;
  int id;
  char gen;
  nombre nomCompleto;
};


int main(void){
  // declaracion de variables
  persona persona1;

  cout << "Este programa ejemplifica el uso de estructuras anidadas" << endl;

  // leer los datos de la persona 1
  cout << "Ingrese tus datos: ";
  cout << "Nombre de pila (ej. Juan): ";
  cin.getline(persona1.nomCompleto.nPila, 50, '\n');
  cout << "Apellido paterno: ";
  cin.getline(persona1.nomCompleto.aPaterno, 25, '\n');
  cout << "Apellido materno: ";
  cin.getline(persona1.nomCompleto.aMaterno, 25, '\n');
  cout << "Numero de identificacion: ";
  cin >> persona1.id;
  cout << "Edad: ";
  cin >> persona1.edad;
  cout << "Genero: (F-Femenino, M-Masculino, O-Otro): ";
  cin >> persona1.gen;
  cout << "Estado de vida: (1-Vivo, 0-Muerto): ";
  cin >> persona1.vivo;
  
  // mostrar los datos de la persona 1
  cout << "\n\nLos datos de la persona 1 son: ";
  cout << "\nNombre completo: ";
  cout << persona1.nomCompleto.nPila << " " << persona1.nomCompleto.aPaterno << " " << persona1.nomCompleto.aMaterno;
  cout << "\nNumero de identificacion: ";
  cout << persona1.id;
  cout << "\nEdad: ";
  cout << persona1.edad;
  cout << "\nGenero: (F-Femenino, M-Masculino, O-Otro): ";
  cout << persona1.gen;
  cout << "\nEsta vivo? (1-Si, 0-No): ";
  cout << persona1.vivo;
  
  return 0;
} // main

// fin de archivo