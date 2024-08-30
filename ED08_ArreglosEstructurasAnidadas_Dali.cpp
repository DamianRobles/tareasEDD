/*
  *Fecha: martes 27 agosto de 2024
  *Autor: Dali
  *Practica No.: 7
  *Objetivo: Arreglos de estructuras anidadas
*/

/*
*Deberás  leer y almacenar los datos para un arreglo de 3 elementos tipo de dato tu estructura anidada (arreglo de estructuras anidadas).
*Implementar una función para leer una variable del tipo de dato de tu propia estructura anidada, la función la devolverá y será asignada a cada elemento de tu arreglo de estructuras declarado en el main( ).
*Implementar una función que deberá recibir e imprimir todos los elementos de tu arreglo de estructuras. Puede recibir todo el arreglo para imprimirlo o bien, puede recibir cada elemento del arreglo, 
*uno por uno e imprimirlos.
*/

/*
*Si creó una función para leer y devolver una variable de la estructura definida con 5 miembros y anidada y lo hace correctamente. (3 puntos)
*Si creó una función para imprimir los elementos de un arreglo de estructuras, que se recibirán como parámetro en la función y lo hace correctamente (3 puntos)
*Si el programa solicita y muestra los datos correctamente usando el Arreglo de Estructuras Anidadas y usando las 2 funciones implementadas (3 puntos)
*Estilo del código fuente correcto: sangrías, comentarios, nombres de variables (1 punto)
*/

//* *librerias
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
const int MAX=1;

//* prototipo de funcion
factura leerFactura(void);
void imprimirFactura(factura, int);

int main(void){
  //* declaracion de variables
  factura factura[MAX];
  
  //* solicitar datos
  for(int i=0; i<MAX; i++){
    factura[i] = leerFactura();
  }

  //* llamar funcion para imprimir las facturas
  for(int i=0; i<MAX; i++){
    imprimirFactura(factura[i], i+1);
  }
  
  return 0;
} //* main

//* definicion de funciones
factura leerFactura(void){
  factura datos;

  cin.ignore();
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

  return datos;
}

//* ==================================================================================
void imprimirFactura(factura factura, int num){
  cout << "------------------- Factura no" << num <<" -------------------" << endl;
  cout << "Nombre de la empresa: " << factura.datosFiscales.nombreEmpresa << endl;
  cout << "Numero de la factura: " << factura.numFactura << endl;
  cout << "Nombre del comprador: " << factura.nomCompleto << endl;
  cout << "RFC del comprador: " << factura.datosFiscales.rfc << endl;
  cout << "Motivo de la factura: " << factura.concepto << endl;
  cout << "Importe total de la factura: $" << factura.datosFiscales.importeTotal << endl;
  cout << "---------------------------------------------------" << endl;
} //* funcion

//* fin de archivo