/*
  *Fecha: martes 27 agosto de 2024
  *Autor: Dali
  *Practica No.: 7
  *Objetivo: Arreglos de estructuras anidadas
*/

/*
*Deberás utilizar la estructura "MiFactura" usada en la Actividad #3  (5 elementos mínimo) práctica ED05_MiFactura_Nombre_del_Alumno.cpp
*
*Uno de sus elementos deberá ser un campo tipo de dato de otra estructura creada por medio de struct (estructura anidada). 
*
*Deberás  leer y almacenar los datos para un arreglo de 3 elementos tipo de dato tu estructura anidada (arreglo de estructuras anidadas).
*
*Implementar una función para leer una variable del tipo de dato de tu propia estructura anidada, la función la devolverá y será asignada a cada elemento de tu arreglo de estructuras declarado en el main( ).
*
*Implementar una función que deberá recibir e imprimir todos los elementos de tu arreglo de estructuras. Puede recibir todo el arreglo para imprimirlo o bien, puede recibir cada elemento del arreglo, uno por uno e imprimirlos.
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
      cout << "Ingresa los datos de tu nuevo amigo " << i+1 << endl;
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
  cout << "Datos de tu nuevo amigo " << num << endl;
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