// Fecha: jueves 20 agosto de 2024
// Autor: Dali
// Practica No.: 2
// Objetivo: Estructuras o registros

// Librerias
#include <iostream>
using namespace std;

// definicion TDA's (TDA = Tipo de Datos Abstracto)
struct cancion{
  // miembros o elementos
  char titulo[40];
  char interprete[40];
  float duracion;
  int ano;
  char genero[40];
};

int main(void){
  // declaracion de variables
  cancion cancion1, cancion2={"Cuando calienta el sol","Luis miguel",3.39,2008,"balada"}, cancion3;

  // 1) Solicitar los datos al usuario
  cout << "Ingresa los datos de tu cancion favorita: " << endl;
  cout << "Titulo: ";
  cin.getline(cancion1.titulo, 40, '\n');
  cout << "Interprete: ";
  cin.getline(cancion1.interprete, 40, '\n');
  cout << "Genero: ";
  cin.getline(cancion1.genero, 40, '\n');
  cout << "Ano: ";
  cin >> cancion1.ano;
  cout << "Duracion: ";
  cin >> cancion1.duracion;

  // 2) Mostrar los datos leidos
  cout << endl << "Informacion de tu cancion 1" << endl;
  cout << "------------------------------------" << endl;
  cout << "Titulo: " << cancion1.titulo << endl;
  cout << "Interprete: " << cancion1.interprete << endl;
  cout << "Genero: " << cancion1.genero << endl;
  cout << "Ano: " << cancion1.ano << endl;
  cout << "Duracion: " << cancion1.duracion << endl;
  cout << "------------------------------------" << endl;

  cout << endl << "Informacion de tu cancion 2" << endl;
  cout << "------------------------------------" << endl;
  cout << "Titulo: " << cancion2.titulo << endl;
  cout << "Interprete: " << cancion2.interprete << endl;
  cout << "Genero: " << cancion2.genero << endl;
  cout << "Ano: " << cancion2.ano << endl;
  cout << "Duracion: " << cancion2.duracion << endl;
  cout << "------------------------------------" << endl;

  cancion3 = cancion1;
  cout << endl << "Informacion de tu cancion 3" << endl;
  cout << "------------------------------------" << endl;
  cout << "Titulo: " << cancion3.titulo << endl;
  cout << "Interprete: " << cancion3.interprete << endl;
  cout << "Genero: " << cancion3.genero << endl;
  cout << "Ano: " << cancion3.ano << endl;
  cout << "Duracion: " << cancion3.duracion << endl;
  cout << "------------------------------------" << endl;

  return 0;
} // main