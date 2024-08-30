// Fecha: jueves 15 agosto de 2024
// Autor: Dali
// Practica No.: 1
// Objetivo: Repaso de FP

// Librerias
#include <iostream>
using namespace std;

// Constantes
const int MAX = 6;
const int PAIS = 4;
const int TIPO = 3;


// Prototipo o definicion de funciones
bool fnTurno(bool); // Prototipo

void fnMuestra(int cal[], int tam){
  cout << "Calificaciones: ";
  for(int i=0; i<tam; i++){
    cout << cal[i] << " ";
  } // for
  cout << endl;
  return;
} // fnMuestra

// Programa principal
int main(void){
  
  // declaracion de variables
  int edad;
  float estatura;
  bool trabaja;
  char genero;
  char nombre[30];
  int numero;
  int calificaciones[MAX];
  float promedio;
  int medallero[PAIS][TIPO]; // 4 paises y 3 tipos de medallas
  int totMedallas;
  int i;

  cout << "Repaso de fundamentos de programacion" << endl;
  
  // lectura de datos
  cout << "Ingresa tus datos: ";
  cout << "Edad --> ";
  cin >> edad;
  // Condicional simple
  if(edad>=18)
    cout << "Eres mayor de edad. Ya tienes tu credencial de elector? " << endl;

  // Condicional doble
  cout << "Estatura (ej, 1.77) --> ";
  cin >> estatura;
  if(estatura>=1.90)
    cout << "Felicitaciones!! Estas admitido en la seleccion del CUCEA" << endl;
  else{
    cout << "Lo siento :c !!" << endl;
    cout << "No es posible ingresar en la seleccion del CUCEA" << endl;
  } // if-else

  // Condicional multiple
  cout << "Genero (F-Femenino M-Masculino O-Otro) --> ";
  cin >> genero;
  switch(genero){
    case 'F' : case 'f' :
      cout << "Tu genero es Femenino" << endl;
      break;
    case 'M' : case 'm' :
      cout << "Tu genero es Masculino" << endl;
      break;
    case 'O' : case 'o' : 
      cout << "Tu genero es otro" << endl;
      break;
    default:
      cout << "Dato no valido" << endl;
      break;
  } // switch

  // Ciclo do-while
  cout << "Serie del 2 desde el 1 hasta el 100 (do-while)" << endl;
  numero = 1;
  do{
    if(numero%2==0)
      cout << numero << "\t";
    numero++; // incremento
  } while(numero <= 100); // do-while
  cout << endl;

  // Ciclo while
  cout << "Serie del 2 desde el 1 hasta el 100 (while)" << endl;
  numero = 1;
  while(numero <= 100){
    if(numero%2==0)
      cout << numero << "\t";
    numero++; // incremento
  } // while
  cout << endl;

  // Ciclo for
  cout << "Serie del 2 desde el 1 hasta el 100 (for)" << endl;
  for(numero=1; numero <= 100; numero++){
    if(numero%2==0)
      cout << numero << "\t";
  }
  cout << endl;

  // Arreglos unidimensionales o vectores
  // Leer las calificaciones
  promedio = 0;
  for(int i=0; i<MAX; i++){
    cout << "Ingresa la calificacion " << i+1 << " --> ";
    cin >> calificaciones[i];
    promedio += calificaciones[i];
  } // for
  promedio /= MAX;
  cout << "El promedio de las calificaciones = " << promedio << endl;

  // Arreglos bidimensionales o matrices o tablas
  // Leer medallas por pais
  cout << "Ingresa las medallas de cada pais" << endl;
  for(int i=0; i<PAIS; i++){
    for(int j=0; j<TIPO; j++){
      if(j==0) // oro
        cout << "Ingresa total de medallas de ORO del pais " << i+1 << " --> ";
      if(j==0) // plata
        cout << "Ingresa total de medallas de PLATA del pais " << i+1 << " --> ";
      if(j==0) // bronce
        cout << "Ingresa total de medallas de BRONCE del pais " << i+1 << " --> ";
      cin >> medallero[i][j];
    } // j-TIPO
  } // i-PAIS

  // contabiliza todas las medallas por pais -- recorrido x filas
  for(int i=0; i<PAIS; i++){
    totMedallas = 0; // acumulador
    for(int j=0; j<TIPO; j++){
      totMedallas+=medallero[i][j];
    } // j-TIPO
    cout << "El pais " << i+1 << " obtuvo " << totMedallas << " madallas" << endl;
  } // i-PAIS

  // contabiliza todas las medallas por tipo -- recorrido x columnas
  for(int j=0; j<TIPO; j++){
    totMedallas = 0; // acumulador
    for(int i=0; i<PAIS; i++){
      totMedallas+=medallero[i][j];
    } // i-TIPO
    cout << "Total de medallas tipo " << j+1 << " fueron " << totMedallas << endl;
  } // j-PAIS

  // arreglos de caracteres o cadenas o strings
  cout << "Ingresa tu nombre --> ";
  cin.ignore();
  cin.getline(nombre,30,'\n');

  // calcular longitud de la cadena
  i=0;
  while(nombre[i] != '\0'){
    i++;
  } // while
  cout << nombre << " tiene " << i << " caracteres" << endl;


  // Funciones o programacion modular
  cout << "Trabajas? (1-si 0-no) --> ";
  cin >> trabaja;
  if(fnTurno(trabaja) == true){
    cout << "Tu turno para estudiar sera el matutino" << endl;
  } else {
    cout << "Tu turno para estudiar sera el vespertino" << endl;
  } 

  // llamada a funcion
  fnMuestra(calificaciones, MAX);
  
  return 0;
} // main

// ==============================
// Implementacion de funciones
bool fnTurno(bool work){
  if(work) // por default supone que es == true
    return true;
  else
    return false;
} // fnTurno()

// Fin de archivo