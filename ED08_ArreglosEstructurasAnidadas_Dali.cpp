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

// librerias
#include <iostream>
using namespace std;

// TDA
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

// prototipo de funcion
void imprimirFactura(factura);

int main(void){
  // declaracion de variables
  factura fact1 = {
    // datos factura
    "Beatriz Pinzon Solano", 25, "Prestamo TERRAMODA",
    // datos fiscales (estructura anidada sat)
    {"PISB740321EM5", "ECOMODA", 50000000}
  };
  factura fact2, fact3;
  
  // solicitar datos
  cout << "Ingrese el nombre de la empresa: ";
  cin.getline(fact2.datosFiscales.nombreEmpresa, 99);
  
  cout << "Ingrese el numero de la factura: ";
  cin >> fact2.numFactura;
  
  cout << "Ingrese el nombre completo del comprador: ";
  cin.ignore();
  cin.getline(fact2.nomCompleto, 99);
  
  cout << "Ingrese el RFC del comprador: ";
  cin.getline(fact2.datosFiscales.rfc, 14);
  
  cout << "Ingrese el motivo de la factura: ";
  cin.getline(fact2.concepto, 99);
  
  cout << "Ingrese el importe total de la factura: $";
  cin >> fact2.datosFiscales.importeTotal;


  // llamar funcion para imprimir las facturas
  cout << endl;
  imprimirFactura(fact1);
  cout << endl;
  imprimirFactura(fact2);
  cout << endl;
  // se copian los valores de la factura 1 a la factura 3
  fact3 = fact2;
  imprimirFactura(fact3);
  
  return 0;
} // main

// definicion de funciones
void imprimirFactura(factura factura){
  cout << "--------------------- Factura ---------------------" << endl;
  cout << "Nombre de la empresa: " << factura.datosFiscales.nombreEmpresa << endl;
  cout << "Numero de la factura: " << factura.numFactura << endl;
  cout << "Nombre del comprador: " << factura.nomCompleto << endl;
  cout << "RFC del comprador: " << factura.datosFiscales.rfc << endl;
  cout << "Motivo de la factura: " << factura.concepto << endl;
  cout << "Importe total de la factura: $" << factura.datosFiscales.importeTotal << endl;
  cout << "---------------------------------------------------" << endl;
} // funcion

// fin de archivo