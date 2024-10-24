//==================================================
// Fecha: Sesión 21
// Practica No.: 30 
// Objetivo: ESTRUCTURAS DE DATOS DINAMICAS USANDO
//           VARIABLES LOCALES (EJEMPLO LDEC)
//           MANEJO DE VARIAS LISTAS SIMULTANEAMENTE
//           Material Adicional
//==================================================

// LIBRERIAS
//=======================================
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// DEFINICIONES DE TDA
//=======================================
// 1) DEFINO nodo COMO nuevo tipo de dato TDA
typedef struct nodo {
    // dato a guardar
    char nombre[15];
    // apuntadores
    struct nodo *siguiente;
    struct nodo *anterior;
};

//=======================================
// 2) DEFINO apNodo COMO nuevo TDA apuntador a TDA nodo
typedef nodo *apNodo;

// PROTOTIPOS
//=======================================
// paso x REFERENCIA
void Insertar(apNodo *lista, char *);   // lista es apuntador a un apuntador
void Eliminar(apNodo *lista, char *);   // lista es apuntador a un apuntador
// paso x VALOR
void MostrarLista(apNodo lista, char *);  // lista es apuntador a nodo
// void MostrarLista(nodo *lista, char *);

// FUNCIîN PRINCIPAL
//=======================================
int main(void) {
    // Definir listas como variable local
    struct nodo *FLORES = NULL;
    struct nodo *EMPRESA = NULL;
    struct nodo *PERSONAS = NULL;
    struct nodo *CIUDADES = NULL;
    struct nodo *UNIVERSIDADES = NULL;

    char nombreLista[20];
    int opc;
    
    do {
        system("cls");
        cout << "            LISTAS " << endl;
        cout << "==================================" << endl;
        cout << "1) Agregar nueva FLOR." << endl;
        cout << "2) Eliminar una FLOR." << endl;
        cout << "3) Mostrar la lista de FLORES." << endl;
        cout << "==================================" << endl;
        cout << "4) Agregar nueva EMPRESA." << endl;
        cout << "5) Eliminar una EMPRESA." << endl;
        cout << "6) Mostrar la lista de EMPRESAS." << endl;
        cout << "==================================" << endl;
        cout << "7) Agregar nueva PERSONA." << endl;
        cout << "8) Eliminar una PERSONA." << endl;
        cout << "9) Mostrar la lista de PERSONAS." << endl;
        cout << "==================================" << endl;
        cout << "10) Agregar nueva CIUDAD." << endl;
        cout << "11) Eliminar una CIUDAD." << endl;
        cout << "12) Mostrar la lista de CIUDADES." << endl;
        cout << "==================================" << endl;
        cout << "13) Agregar nueva UNIVERSIDAD." << endl;
        cout << "14) Eliminar una UNIVERSIDAD." << endl;
        cout << "15) Mostrar la lista de UNIVERSIDADES." << endl;
        cout << "==================================" << endl;
        cout << "0) Salir" << endl;
        cout << "==================================" << endl;
        cout << "Digita tu opcion ----> ";
        cin >> opc;
        cout << endl;
        
        switch (opc) {
                // ************************
            case 1:                        // Insertar elemento
                strcpy(nombreLista, "FLOR");
                Insertar(&FLORES,nombreLista);          // PASO X REFERENCIA
                break;
                
            case 2:                        // Eliminar elemento
                strcpy(nombreLista, "FLOR");
                Eliminar(&FLORES,nombreLista);          // PASO X REFERENCIA
                break;
                
            case 3:                        // Consultar lista adelante
                strcpy(nombreLista, "FLOR");
                MostrarLista(FLORES,nombreLista);       // PASO X VALOR
                break;
                
                // ************************
            case 4:                        // Insertar elemento
                strcpy(nombreLista, "EMPRESA");
                Insertar(&EMPRESA,nombreLista);          // PASO X REFERENCIA
                break;
                
            case 5:                        // Eliminar elemento
                strcpy(nombreLista, "EMPRESA");
                Eliminar(&EMPRESA,nombreLista);          // PASO X REFERENCIA
                break;
                
            case 6:                        // Consultar lista adelante
                strcpy(nombreLista, "EMPRESA");
                MostrarLista(EMPRESA,nombreLista);       // PASO X VALOR
                break;
                
                // ************************
            case 7:                        // Insertar elemento
                strcpy(nombreLista, "PERSONA");
                Insertar(&PERSONAS,nombreLista);          // PASO X REFERENCIA
                break;
                
            case 8:                        // Eliminar elemento
                strcpy(nombreLista, "PERSONA");
                Eliminar(&PERSONAS,nombreLista);          // PASO X REFERENCIA
                break;
                
            case 9:                        // Consultar lista adelante
                strcpy(nombreLista, "PERSONA");
                MostrarLista(PERSONAS, nombreLista);       // PASO X VALOR
                break;
                
                // ************************
            case 10:                        // Insertar elemento
                strcpy(nombreLista, "CIUDAD");
                Insertar(&CIUDADES,nombreLista);          // PASO X REFERENCIA
                break;
                
            case 11:                        // Eliminar elemento
                strcpy(nombreLista, "CIUDAD");
                Eliminar(&CIUDADES,nombreLista);          // PASO X REFERENCIA
                break;
                
            case 12:                        // Consultar lista adelante
                strcpy(nombreLista, "CIUDAD");
                MostrarLista(CIUDADES,nombreLista);       // PASO X VALOR
                break;
                
                // ************************
            case 13:                        // Insertar elemento
                strcpy(nombreLista, "UNIVERSIDAD");
                Insertar(&UNIVERSIDADES,nombreLista);          // PASO X REFERENCIA
                break;
                
            case 14:                        // Eliminar elemento
                strcpy(nombreLista, "UNIVERSIDAD");
                Eliminar(&UNIVERSIDADES,nombreLista);          // PASO X REFERENCIA
                break;
                
            case 15:                        // Consultar lista adelante
                strcpy(nombreLista, "UNIVERSIDAD");
                MostrarLista(UNIVERSIDADES,nombreLista);       // PASO X VALOR
                break;
                
                // ************************
            case 0:                        // Salir del programa
                cout << "Elegiste salir del programa" << endl;
                break;
                
            default:                       // Opcion No valida
                cout << "Opcion no valida" << endl;
                break;
        } // switch
        
        system("pause");
        
    } while ( opc != 0 );
    
    return(0);
    
} // main()


// DEFINICIîN DE FUNCIONES (OPERACIONES)
//////////////////////////////////////

//====================================
// 1) INSERTAR      (PASO X REFERENCIA)
//====================================
void Insertar(apNodo *lista, char *nomb) {
    // 1) Definir apuntador
    struct nodo *nuevo;
    
    // 2) Crear nodo (solicitar memoria)
    nuevo = new(nodo);
    
    // 3) Validar apuntador
    if ( nuevo == NULL ) {
        cout << "NO HAY MEMORIA SUFICIENTE." << endl;
        return;
    } // if
    
    // 4) Asignar datos
    cout << "Nombre de la " << nomb << " --> ";
    cin >> nuevo->nombre;
    
    // 5) Insertarlo en la lista
    if ( (*lista) == NULL ) {
        (*lista) = nuevo;
        (*lista)->anterior = nuevo;
    }
    else {
        nuevo->siguiente = (*lista)->siguiente;
        nuevo->anterior = (*lista);
        (*lista)->siguiente->anterior = nuevo;
    } // if-else
    
    // Cerrar lista Circular
    (*lista)->siguiente = nuevo;
    
    cout << "Registro " << nuevo->nombre << " agregado..." << endl;
    return;
    
} // Insertar()

//====================================
// 2) ELIMINAR      (PASO X REFERENCIA)
//====================================
void Eliminar(apNodo *lista, char *nomb) {
    // 1) Declarar variable
    apNodo copia = *lista;
    char v[15];
    
    // 2) Validar lista no vac’a
    if ( copia == NULL ) {
        cout << "LISTA " << nomb << " VACIA." << endl;
    } else {
        cout << "Nombre a eliminar ";
        cin >> v;
        // Hacer que nodo apunte al valor v
        do {
            if( strcmp( copia->nombre,v ) != 0 )
                copia = copia->siguiente;
        } while( strcmp(copia->nombre,v) != 0  && (*lista) != copia);
        
        // Si existe un nodo con el valor v
        if ( strcmp ( copia->nombre, v) == 0 ) {
            // a) Un solo nodo
            if ( (*lista) == (*lista)->siguiente )
                (*lista) = NULL;
            else {
                // b) dos o mas nodos
                if ( copia == (*lista) )   // Apuntan al mismo nodo
                    (*lista) = (*lista)->anterior;
                copia->siguiente->anterior = copia->anterior;
                copia->anterior->siguiente = copia->siguiente;
            } // if-else
            // eliminar nodo
            delete(copia);
            cout << "Nombre " << v << " eliminado." << endl;
        } else
            cout << "Nombre NO localizado." << endl;
    } // if-else
    return;
} // Eliminar()

//====================================
// 3) MostrarLista (PASO X VALOR)
//====================================
void MostrarLista(struct nodo *lista, char *nomb) {
    // Declarar variable
    struct nodo *copia = lista;
    
    // Validar la lista no estŽ vac’a
    if ( copia == NULL ) {
        cout << "LISTA " << nomb << " VACIA." << endl;
    } else {
        cout << "Contenido de la LISTA " << nomb << endl;
        cout << "-------------------" << endl;
        do {
            cout << copia->nombre << endl;
            copia = copia->siguiente;
        } while(copia != lista);
        cout << "-------------------" << endl;
    } // if-else
    
    return;
} // MostrarLista()

///////////////////////// FIN DE ARCHIVO
