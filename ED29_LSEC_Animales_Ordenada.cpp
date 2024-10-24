// **********************************************************
// Fecha: Sesión 21
// Autor: Rebeca
// Practica: No. 29  
// Objetivo: TDA Lista Simplemente Enlazada Circular ORDENADA
// **********************************************************

// Librerias
#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

// TDA LSEC
struct animal {
  // datos      
  char especie[20];
  char genero;
  char nombre[20];
  int edad;
  float precio;
  float peso;
  // enlace
  struct animal *siguiente;      
};

// Apuntador a la lista LSEC
struct animal *LISTA=NULL;

// Operaciones del TDA
void agregar(void);
void consultar(void);
void borrar(void);
void buscar(void);
void consultarPrecio(void);
void ordenarLista(void);

// Programa principal
int main(void) {
  int opcion;
  
  do {
    system("cls");
    cout << "        Tienda de Mascotas Minino" << endl;
    cout << "=======================================" << endl;
    cout << "1. Agregar una nueva mascota" << endl;
    cout << "2. Consultar la lista de mascotas" << endl;
    cout << "3. Elimnar una mascota de la lista" << endl;
    cout << "4. Buscar por nombre de la mascota" << endl;
    cout << "5. Consultar mascotas en un rango de precio" << endl;
    cout << "6. Ordenar lista por precio" << endl;
    cout << "0. Salir" << endl;      
    cout << "=======================================" << endl;
    cout << "Digita tu opcion -->";
    cin >> opcion;
    switch(opcion) {
        case 1:
          agregar();
          break;
          
        case 2:
          consultar();
          break;
          
        case 3:
          borrar();
          break;
          
        case 4:
          buscar();
          break;
          
        case 5:
          consultarPrecio();
          break;
          
        case 6:
          ordenarLista();
          break;
          
        case 0:
          cout << "Seleccionaste salir." << endl;
          break;
          
        default:    
          cout << "Opcion no valida." <<endl;
          break;            
    } // switch
    system("pause");  
  } while (opcion != 0 );  
  return(0);  
} // main

//===================================
void ordenarLista(void){
	//declarar apuntadores 
	animal *i=NULL, *j=NULL;
	animal *paso;
	int vueltas=0;
	
	//Caso A - Lista vacia
	if ( LISTA == NULL ) {
		system("cls");
		cout << "No existen animales registrados en la lista. No se puede ordenar la lista." <<endl;
		return;
	} //termina if
	
	// solicito memoria de nuevo
	paso = (animal *) malloc( sizeof(animal) );

	// valido 
	if ( paso == NULL ) {
		cout << "No hay memoria suficiente para crear variable de paso." << endl;
		return;
	} // if

    // Calcular nœmero de vueltas a la lista
    i=LISTA;
    vueltas=0;
    while ( i->siguiente != LISTA ) {
        vueltas++;
        i = i->siguiente;
    } // while
   
	// Lista con dos o mas nodos. 
    while( vueltas > 0 ){
        i=LISTA;	
	    // Recorre todo el arreglo para colocar uno en su lugar
	    while( i->siguiente != LISTA){
    	    j = i->siguiente;
	   	    // Comparar los precios de los animales, si es necesario intercambia informacion de los nodos i y j
	   	    if ( i->precio > j->precio  ){
	            
	            // 1) Copiar i -> paso
            	strcpy(paso->especie, i->especie);
            	strcpy(paso->nombre, i->nombre);
            	paso->genero = i->genero;
            	paso->edad = i->edad;
            	paso->precio = i->precio;
                paso->peso = i->peso;
            	      	
            	// 2) Copiar j -> i
            	strcpy(i->especie, j->especie);
            	strcpy(i->nombre, j->nombre);
            	i->genero = j->genero;
            	i->edad = j->edad;
            	i->precio = j->precio;
                i->peso = j->peso;
          	
            	// 3) Copiar paso -> j
            	strcpy(j->especie, paso->especie);
            	strcpy(j->nombre, paso->nombre);
            	j->genero = paso->genero;
            	j->edad = paso->edad;
            	j->precio =paso->precio;
                j->peso = paso->peso;
             	
            }	// if - intercambia informacion nodos
	        i = i->siguiente;
	    } // while
	    vueltas--;
	} // while
	
	cout<< "Los datos han sido ordenados por precio " <<endl;
	cout<< "Ingresar a la OPCION 2 para consultarlo." <<endl << endl; 
    	
	return;
} // ordenarLista

//===================================
void consultarPrecio(void) {
   float costo;
   struct animal *buscar=LISTA;  
   bool encontrado=false;
     
   // a) Lista vacía
   if ( LISTA == NULL ) {
      cout << "No se tiene registro de mascotas aun!!!"
           << endl;  
      return;  
   } //if      

   cout << "Precio maximo de la mascota que deseas mostrar --> ";
   cin >> costo;

   do {
       if ( buscar->precio <= costo ) { 
        cout << "Registro localizado:" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Especie --> " << buscar->especie << endl;
        cout << "Nombre --> " << buscar->nombre << endl;
        cout << "Genero (H-hembra / M-macho) --> " << buscar->genero << endl;
        cout << "Edad (meses) --> " << buscar->edad << endl;
        cout << "Precio --> " << buscar->precio << endl;
        cout << "Peso --> " << buscar->peso << endl;
        cout << "--------------------------------------" << endl;
        encontrado=true;  
       } // if 
       buscar=buscar->siguiente;         
   } while ( buscar != LISTA );  
   
   if ( ! encontrado )  //  encontrado == false
     cout << "No estan registradas mascotas con precio <= " << costo << endl;
   return;
} // consultarPrecio

//===================================
void buscar(void) {
   struct animal *buscar=LISTA;
   char nomb[20];
     
   // a) Lista vacía
   if ( LISTA == NULL ) {
      cout << "No se tiene registro de mascotas aun!!!"
           << endl;  
      return;  
   } //if      
   
   cout << "Nombre de la mascota a buscar --> ";
   cin >> nomb;
   
   do {
      if ( strcmp(nomb,buscar->nombre) == 0 ) { 
        cout << "Registro localizado:" << endl;
        cout << "--------------------------------------" << endl;
        cout << "Especie --> " << buscar->especie << endl;
        cout << "Nombre --> " << buscar->nombre << endl;
        cout << "Genero (H-hembra / M-macho) --> " << buscar->genero << endl;
        cout << "Edad (meses) --> " << buscar->edad << endl;
        cout << "Precio --> " << buscar->precio << endl;
        cout << "Peso --> " << buscar->peso << endl;
        cout << "--------------------------------------" << endl;
        return;   
      } // if 
      buscar=buscar->siguiente;         
   } while ( buscar != LISTA );
   
   cout << nomb << " no esta registrado como nombre de mascota!!!" << endl;
   return;
} // buscar

//===================================
void borrar(void) {
   struct animal *borrar=LISTA;  
   char resp;
    
   // a) Lista vacía
   if ( LISTA == NULL ) {
      cout << "No se tiene registro de mascotas aun. No es posible eliminar!"
           << endl;  
      return;  
   } //if  
     
   // b) Lista único nodo
   if ( LISTA->siguiente == LISTA ) {
    cout << "Especie --> " << borrar->especie << endl;
    cout << "Nombre --> " << borrar->nombre << endl;
    cout << "Genero (H-hembra / M-macho) --> " << borrar->genero << endl;
    cout << "Edad (meses) --> " << borrar->edad << endl;
    cout << "Precio --> " << borrar->precio << endl;
    cout << "Peso --> " << borrar->peso << endl;
    cout << "--------------------------------------" << endl;
    cout << "Estas seguro de eliminarlo (S/s)? ";    
    cin >> resp;
    if ( resp == 'S' || resp == 's' ) {
       LISTA = NULL;
       free(borrar);
       cout << "Registro elimnado!!!" << endl;
       return;  
    } else
        cout << "No se elimino el registro!!!" << endl;   
    return;   
   } // if
     
   // c) Lista tiene 2 o más nodos
   do {
    cout << "Especie --> " << borrar->especie << endl;
    cout << "Nombre --> " << borrar->nombre << endl;
    cout << "Genero (H-hembra / M-macho) --> " << borrar->genero << endl;
    cout << "Edad (meses) --> " << borrar->edad << endl;
    cout << "Precio --> " << borrar->precio << endl;
    cout << "Peso --> " << borrar->peso << endl;
    cout << "--------------------------------------" << endl;
    cout << "Estas seguro de eliminarlo (S/s)? ";    
    cin >> resp;
    if ( resp == 'S' || resp == 's' ) {       
        // 1) Posicionar lista uno antes del que quiero borrar
        while ( LISTA->siguiente != borrar ) {
           LISTA = LISTA->siguiente;
        } // while
        // 2) Brincar el nodo
        LISTA->siguiente = borrar->siguiente;
        // 3) Liberar memoria
        free(borrar);
        cout << "Registro eliminado exitosamente!!" << endl;
        return;
    } // if
    borrar = borrar->siguiente;   
   } while ( borrar != LISTA);
   cout << "No se elimino registro alguno!!" << endl;
   return;   
} // borrar

//===================================
void consultar(void) {
  struct animal *inicio=LISTA;
  
  // a) LISTA vacía
  if ( LISTA == NULL ) {
     cout << "No se tienen mascotas registradas." << endl;  
     return;
  } // if   
     
  // b) Consultar la lista
  system("cls");
  cout << "Mascotas en existencia" << endl;
  cout << "--------------------------------------" << endl;  
  do {
    cout << "Especie --> " << inicio->especie << endl;
    cout << "Nombre --> " << inicio->nombre << endl;
    cout << "Genero (H-hembra / M-macho) --> " << inicio->genero << endl;
    cout << "Edad (meses) --> " << inicio->edad << endl;
    cout << "Precio --> " << inicio->precio << endl;
    cout << "Peso --> " << inicio->peso << endl;
    cout << "--------------------------------------" << endl;
    inicio = inicio->siguiente; 
  } while ( inicio != LISTA);
  return;
} // consultar

//===================================
void agregar(void) {
   // 1) Declarar variable
   struct animal *nuevo;
   
   // 2) Solicitar memoria
   nuevo = (animal *) malloc( sizeof(animal) );  
     
   // 3) Validar el apuntador
   if ( nuevo == NULL ) {
      cout << "No hay memoria suficiente." << endl;
      return;   
   } //if
     
   // 4) Solicitar datos (información que se guarda en el nodo)
   cout << "Ingresa los datos de la mascota a registrar" << endl;   
   cout << "Especie --> ";
   cin >> nuevo->especie;
   cout << "Nombre --> ";
   cin >> nuevo->nombre;
   cout << "Genero (H-hembra / M-macho) --> ";
   cin >> nuevo->genero;
   cout << "Edad (meses) --> ";
   cin >> nuevo->edad;
   cout << "Precio --> ";
   cin >> nuevo->precio;
   cout << "Peso --> ";
   cin >> nuevo->peso;
   
   // 5) Actualizar el apuntador del nuevo nodo
   if ( LISTA == NULL )
      nuevo->siguiente = nuevo;
   else
      nuevo->siguiente = LISTA->siguiente;
      
   // 6) Agregar el nuevo nodo a la LISTA LSEC
   if ( LISTA == NULL )
      LISTA = nuevo;
   else
      LISTA->siguiente = nuevo;
      
   cout << "Datos de la mascota registrados exitosamente!!!" << endl;
   return;
} // agregar

// Fin de archivo
