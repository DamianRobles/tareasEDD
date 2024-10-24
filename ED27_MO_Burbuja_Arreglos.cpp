// ****************************************************
// Fecha: Sesión 21
// Autor: Rebeca
// Practica: No. 27
// Objetivo: Ordenamiento de un arreglo
//           Método de la BURBUJA o por Hundimiento
// ****************************************************

/* Algoritmo a desarrollar:
   - Leer la edad de 10 personas en un arreglo
   - Leer 10 caracteres en un arreglo
   - Ordenarlos por el algoritmo de la burbuja
   - Imprimirlos ya ordenados
*/

#include <iostream>
#include <string.h>
using namespace std;

const int TOTAL = 10;

int main(void) {
  // Declaracion de variables
  int aEdad[TOTAL], iPaso;
  char aLetras[TOTAL], cPaso;
  int i, j;

  // ARREGLO DE ENTEROS
  //===============================
  // Leer datos
  //===============================
    for ( i=0; i<TOTAL; i++) {
    	cout << "Edad "<<i+1 <<"--> ";
    	cin >> aEdad[i];
  	} // for i

  //===============================
  // ORDENAMIENTO X ALGORITMO BURBUJA
  //===============================
  for ( i=0; i <TOTAL-1;  i++) {
	for ( j=0; j<TOTAL-1; j++) {
	  if ( aEdad[j] > aEdad[j+1] ) {
              iPaso = aEdad[j];
	      aEdad[j] = aEdad[j+1];
	      aEdad[j+1] = iPaso;
	  } //if
    } // for j
  } // for i

  //===============================
  // Escribir datos ordenados
  //===============================
  cout << "Arreglo de numeros enteros ORDENADOS (Edades)" << endl;
  for ( i=0; i<TOTAL; i++)
     cout << aEdad[i] << '\t';
  cout << endl;

  // ARREGLO DE CARACTERES 
  //===============================
  // Leer datos
  //===============================
  for ( i=0; i<TOTAL; i++) {
    cout << "Letra "<<i+1 <<"--> ";
    cin >> aLetras[i];
  } // for i

  //===============================
  // ORDENAMIENTO X ALGORITMO BURBUJA
  //===============================
  for ( i=0; i < TOTAL-1;  i++) {
	for ( j=0; j<TOTAL-1; j++) {
		if ( aLetras[j] > aLetras[j+1] ) {
          cPaso = aLetras[j];
	      aLetras[j] = aLetras[j+1];
		  aLetras[j+1] = cPaso;
		} //if
    } // for j
  } // for i

  //===============================
  // Escribir datos ordenados
  //===============================
  cout << "Arreglo de letras CARACTERES ordenados" << endl;
  for ( i=0; i<TOTAL; i++)
    cout << aLetras[i] << "\t";
  cout << endl;
 
  return(0);
    
} //fin main


// ----- Fin de archivo
