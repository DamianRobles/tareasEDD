/*
  ! Fecha: lunes 2 de septiembre de 2024
  ! Autor: Dali
  ! Practica No.: 8
  ! Objetivo: Arreglos de estructuras anidadas con uso de funciones
*/

//* librerias
#include <iostream>
using namespace std;

//* TDA
struct factura{
  struct sat{
    char rfc[14];
    char nombreEmpresa[99];
    int importeTotal;
  };
  char nomCompleto[99];
  int numFactura;
  char concepto[99];
  sat datosFiscales;  
};

//* constantes
const int MAX=3;

//* prototipo de funcion
factura leerFactura(int);
void imprimirFactura(factura, int);

//* funcion principal
int main(void){
  // declaracion de variables
  factura factura[MAX];
  
  // llamar funcion para solicitar datos
  for(int i=0; i<MAX; i++){
    factura[i] = leerFactura(i+1);
    // se limpia el buffer despues de cada lectura para evitar errores al leer el siguiente
    cin.ignore();
  }

  // llamar funcion para imprimir las facturas
  for(int i=0; i<MAX; i++){
    imprimirFactura(factura[i], i+1);
  }
  
  return 0;
} //* main

//* ==================================================================================

//* definicion de funciones
//* funcion leerFactura
factura leerFactura(int num){
  // declaracion de variables
  factura datos;

  // solicitar los datos de cada elemento del arreglo
  cout << "\nIngrese los datos de la factura no." << num << endl;
  cout << "Ingrese el nombre de la empresa: ";
  cin.getline(datos.datosFiscales.nombreEmpresa, 99);
  
  cout << "Ingrese el numero de la factura: ";
  cin >> datos.numFactura;
  
  cout << "Ingrese el nombre completo del comprador: ";
  cin.ignore();
  cin.getline(datos.nomCompleto, 99);
  
  cout << "Ingrese el RFC del comprador: ";
  cin.getline(datos.datosFiscales.rfc, 14);
  
  cout << "Ingrese el motivo de la factura: ";
  cin.getline(datos.concepto, 99);
  
  cout << "Ingrese el importe total de la factura: $";
  cin >> datos.datosFiscales.importeTotal;

  // se regresa a main() los campos rellenados de la variable estructura
  return datos;
} //* funcion leerFactura

// ==================================================================================

//* funcion imprimirFactura
void imprimirFactura(factura factura, int num){
  // se imprime cada elemento del arreglo de estructuras en formato de boucher
  cout << "------------------- Factura no" << num <<" -------------------" << endl;
  cout << "Nombre de la empresa: " << factura.datosFiscales.nombreEmpresa << endl;
  cout << "Numero de la factura: " << factura.numFactura << endl;
  cout << "Nombre del comprador: " << factura.nomCompleto << endl;
  cout << "RFC del comprador: " << factura.datosFiscales.rfc << endl;
  cout << "Motivo de la factura: " << factura.concepto << endl;
  cout << "Importe total de la factura: $" << factura.datosFiscales.importeTotal << endl;
  cout << "---------------------------------------------------" << endl;
} //* funcion imprimirFactura

//* fin de archivo