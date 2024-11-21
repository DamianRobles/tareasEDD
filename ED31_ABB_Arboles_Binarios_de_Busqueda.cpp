// --------------------------------------
// Fecha: Sesión 25
// Objetivo: Árboles Binarios de Búsqueda (ABB)
// Practica: No. 31
// --------------------------------------

// LIBRERIAS
// --------------------------------------
#include <iostream>
#include <cstdlib>
#include <locale.h>
using namespace std;

/* Estructura Autoreferenciada */
// --------------------------------------
struct NodoArbol {
    int numero;
    struct NodoArbol *Izq;
    struct NodoArbol *Der;
};

typedef NodoArbol *apNodo;

// ---------------------------------------------
// Prototipos de funciones (OPERACIONES TDA ABB)
// ---------------------------------------------

// 1) Buscar un elemento en el Arbol
void buscarArbol(apNodo ptrArbol, int valor);

// 2) Insertar un nuevo nodo al Arbol
void insertaNodo(apNodo *ptrArbol, int valor);

// 3) Imprimir contenido del Arbol Recorrido in-orden
void inOrden(apNodo ptrArbol);

// 4) Eliminar un nodo en el Arbol
void eliminar(apNodo *ptrArbol, int valor);

// 5) Evaluar si un nodo es hoja o no lo es
int EsHoja(apNodo);

// 6) Muestra el menu en pantalla
void menu(void);

// 7) Calcula la altura maxima del arbol
int altura(apNodo a, int nivel);

// 8) Recorre de abajo hacia arriba el TDA Arbol
void recorre_down_up(apNodo a);

// 9) Recorre de arriba hacia abajo el TDA Arbol
void recorre_up_down(apNodo a);

// 10) Recorre nivel del arbol
void recorrenivel(apNodo a, int nivel);

// 11) Cuenta los nodos actuales del arbol
int cnodos(apNodo);

// 12) Consultar contenido del Arbol Recorrido pre-orden
void preOrden(apNodo ptrArbol);

// 13) Consultar contenido del Arbol Recorrido post-orden
void postOrden(apNodo ptrArbol);

// --------------------------------------
// Programa principal
// --------------------------------------
int main(void) {
    int valor;
    int opcion;
    apNodo RAIZ = NULL;
    
    setlocale(LC_ALL,"");
    
    do{
        menu();
        cout << "Digita tu opción --> ";
        cin >> opcion;
        switch(opcion){
            case 1:
                cout << "Número que deseas insertar -->" << endl;
                cin >> valor;
                insertaNodo(&RAIZ, valor);
                break;
            case 2:
                cout << "Número que deseas eliminar -->" << endl;
                cin >> valor;
                eliminar(&RAIZ, valor);
                break;
            case 3:
                cout << "Número a buscar  -->" << endl;
                cin >> valor;
                buscarArbol(RAIZ,valor);
                break;
            case 4:
                cout << "Contenido del árbol (in-order)" << endl;
                inOrden(RAIZ);
                break;
            case 5:
                cout << "Altura del árbol: " << altura(RAIZ,0);
                cout << endl << endl;
                break;
            case 6:
                cout << "El árbol visualizado por niveles (abajo hacia arriba): ";
                recorre_down_up(RAIZ);
                break;
            case 7:
                cout << "El árbol visualizado por niveles (arriba hacia abajo): ";
                recorre_up_down(RAIZ);
                break;
            case 8:
                if (RAIZ == NULL)
                    cout << "Árbol ABB vacío" << endl;
                else
                    cout << "Total de nodos actuales:  " << cnodos(RAIZ) << endl;
                break;
            case 9:
                cout << "Contenido del árbol (pre-order)" << endl;
                preOrden(RAIZ);
                break;
            case 10:
                cout << "Contenido del árbol (post-order)" << endl;
                postOrden(RAIZ);
                break;
            case 0:
                cout << "Seleccionaste SALIR" << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        } // switch
        system("pause");
    } while(opcion!=0);
    return(0);
} // main()

//======================================
// 2) Insertar un nodo dentro del arbol
//======================================
void insertaNodo( apNodo *ptrArbol, int valor ) {
    //******** El valor no fue encontrado en el Ã¡rbol y es insertado
    if ( (*ptrArbol) == NULL) {
        *ptrArbol = (apNodo) malloc(sizeof(NodoArbol));
        if ( (*ptrArbol) != NULL) {
            (*ptrArbol)->numero = valor;
            (*ptrArbol)->Izq = NULL;
            (*ptrArbol)->Der = NULL;
            cout << valor << " insertado en el arbol !!!" << endl;
        } else {
            cout << "No hay memoria disponible." << endl;
        } // if-else
    } else {
        //*********** ContinÃºo buscando el valor en el Ã¡rbol
        if ( valor < (*ptrArbol)->numero ) {
            // el Dato a insertar es menor que el Dato en el nodo actual
            insertaNodo( &((*ptrArbol)->Izq) , valor );
        } else {
            if ( valor > (*ptrArbol)->numero) {
                // el Dato a insertar es mayor que el Dato en el nodo actual
                insertaNodo( &( (*ptrArbol)->Der ), valor );
            } else {
                // el Dato ya existe, no se puede insertar
                cout << valor << " duplicado. No puede ser insertado !!!" << endl;
            } // if-else
        } // if-else
    } // if-else
} // insertaNodo()

//====================================
// 1) Buscar un nodo dentro del arbol
//====================================
void buscarArbol(apNodo arbol, int valor) {
    if ( arbol == NULL ) {
        cout << valor << "  no localizado." << endl;
        return;
    } // if
    
    if ( valor == arbol->numero )
        cout << "Número " << valor << " fue localizado." << endl;
    else
        if ( valor < arbol->numero )
            buscarArbol(arbol->Izq, valor);
        else
            buscarArbol(arbol->Der, valor);
}  // buscarArbol()

//==========================================
// 3) ImpresiÃ³n del Ã¡rbol. Recorrido inorden
//==========================================
void inOrden(apNodo ptrArbol)
{
    if ( ptrArbol != NULL) {
        inOrden(ptrArbol->Izq);
        cout << ptrArbol->numero << " ";
        inOrden(ptrArbol->Der);
    } // if
} // inOrden

//====================================
// 4) Eliminar un nodo dentro del Ã¡rbol
//====================================
void eliminar(apNodo *a, int dat) {
    apNodo padre = NULL;
    apNodo actual;
    apNodo nodo;
    int aux;
    
    actual = *a;
    while ( actual != NULL ) {
        // Es el que busco?
        if ( dat == actual->numero ) {
            // Es nodo hoja?
            // =============
            if( EsHoja(actual) ) {
                if (padre) {
                    if (padre->Der == actual)
                        padre->Der = NULL;
                    else
                        if (padre->Izq == actual)
                            padre->Izq = NULL;
                } // if
                // ELIMINAR EL NODO
                free(actual);
                actual = NULL;
                cout << dat << " eliminado." << endl;
                return;
            } else {
                // Es nodo rama
                // =============
                padre = actual;
                // Si existe subarbol derecho
                if (actual->Der) {
                    nodo = actual->Der;
                    // Busco su subarbol mÃ¡s a la izquierda
                    while(nodo->Izq) {
                        padre = nodo;
                        nodo = nodo->Izq;
                    } // while
                } else {
                    // sino va al subarbol izquierdo
                    nodo = actual->Izq;
                    // busco su subarbol mÃ¡s a la derecha
                    while(nodo->Der) {
                        padre = nodo;
                        nodo = nodo->Der;
                    } // while
                } // if-else
                // Ya posicionado, realiza el intercambio
                aux = actual->numero;
                actual->numero = nodo->numero;
                nodo->numero = aux;
                // Muevo el apuntador
                actual = nodo;
            } // if-else
            //===================
        } else {
            // Si no es el que busco, continuo la bÃºsqueda
            padre = actual;
            if (dat > actual->numero)
                actual = actual->Der;
            else
                if(dat < actual->numero)
                    actual = actual->Izq;
        } // if-else
    } // while
    // Si sale del ciclo es porque el dato a borrar no fue encontrado
    cout << dat << " no localizado" << endl;
    return;
} // eliminar()

//====================================
// 5) Valida si el nodo es un hoja
//====================================
int EsHoja(apNodo r) {
    return ( ! r->Der &&  ! r->Izq );
} // EsHoja()

//====================================
// 6) menu de operaciones del TDA ABB
//====================================
void menu(void) {
    system("cls");
    cout << "     Árboles Binarios de Búsqueda (ABB)" << endl;
    cout << "===============================================" << endl;
    cout << " 1. Insertar un nuevo nodo al árbol" << endl;
    cout << " 2. Eliminar un nodo en el árbol" << endl;
    cout << " 3. Buscar un elemento en el árbol" << endl;
    cout << " 4. Contenido del árbol (in-order)" << endl;
    cout << " 5. Altura del árbol" << endl;
    cout << " 6. Contenido del árbol por niveles (arriba-abajo)" << endl;
    cout << " 7. Contenido del árbol por niveles (abajo-arriba)" << endl;
    cout << " 8. Cuenta los nodos actuales del arbol" << endl;
    cout << " 9. Contenido del arbol (pre-order)" << endl;
    cout << "10. Contenido del arbol (pos-order)" << endl;
    cout << "0. Salir" << endl;
    cout << "-------------------------------------" << endl;
} // menu()

//===============================
// 7) Calcula la altura del arbol
//===============================
int altura(apNodo a, int nivel) {
    int p_hi, p_hd;
    
    // a) Es hoja?
    if (a==NULL)
        return(nivel-1);
    
    // b) En otro caso se llama recursivamente a la funcion altura,
    // tanto por el hijo derecho como por el izquierdo
    p_hi = altura(a->Izq,nivel+1);
    p_hd = altura(a->Der,nivel+1);
    
    // c) comparacion de alturas izquierda y derecha
    // se regresa la de mayor longitud
    if (p_hi > p_hd)
        return p_hi;
    else
        return p_hd;
} // altura()

//==========================================
// 8) Recorre de arriba hacia abajo el arbol
//==========================================
void recorre_up_down(apNodo a) {
    int i;
    
    if (a == NULL)
        cout << "Árbol vacío." << endl;
    else {
        // desde la maxima altura hasta 0, se recorre el arbol usando a la
        // funcion recorre_nivel
        cout << "Visualizar árbol de arriba hacia abajo." << endl;
        i=altura(a,0);     // altura del arbol, total de niveles
        for ( int j=0; j<=i; j++ ) {
            cout << "Nivel " << j << " : ";
            recorrenivel(a,j);
            cout << endl;
        } // for
    } // else
    
}  // recorre_up_down()

//==========================================
// 9) Recorre de abajo hacia arriba el arbol
//==========================================
void recorre_down_up(apNodo a) {
    int i;
    // desde la maxima altura hasta 0, se recorre el arbol usando a la
    // funcion recorre_nivel
    
    if (a == NULL)
        cout << "Árbol vacío." << endl;
    else {
        cout << "Visualizar árbol de abajo hacia arriba." << endl;
        // altura del arbol, total de niveles
        i=altura(a,0);
        for ( ; i>=0; i-- ) {
            cout << "Nivel " << i << " : ";
            recorrenivel(a,i);
            cout << endl;
        } // for
    } // else
    
} // recorre_down_up()

//===============================
// 10) Recorre un nivel del arbol
//===============================
void recorrenivel(apNodo a, int nivel) {
    // si es null no hay nada que recorrer
    if (a==NULL)
        return;
    
    // en todo caso se recorre el hijo izquierdo y el hijo derecho
    recorrenivel(a->Izq,nivel-1);
    recorrenivel(a->Der,nivel-1);
    
    // hasta que nivel=0, entonces se imprime  en pantalla
    if (nivel == 0) {
        cout << a->numero << "  ";
        return;
    } // if
} // recorrenivel()

//===============================
// 11) Contar el numero de nodos del arbol
//===============================
int cnodos(apNodo raiz){
    // se cuenta el mismo nodo
    int c=1;
    // Si es hijo de hoja, no se cuenta
    if (raiz == NULL) {
        return(0);
    } // if
    // Si es hoja regresa el 1
    if ( EsHoja(raiz) ) {
        return(c);
    } // if
    // Le suma los nodos del sub-Arbol izquierdo
    c = c + ( cnodos(raiz->Izq) );
    // Le suma los nodos del sub-Arbol derecho
    c = c + ( cnodos(raiz->Der) );
    // Regresa el total de nodos del Arbol en cuestion
    return(c);
} // cnodos()

//==========================================
// 12) Impresion del Arbol. Recorrido pre-orden
//==========================================
void preOrden(apNodo ptrArbol)
{
    if ( ptrArbol != NULL ) {
        cout << ptrArbol->numero << " ";
        preOrden(ptrArbol->Izq);
        preOrden(ptrArbol->Der);
    } // if
} // preOrden

//==========================================
// 13) Impresión del Árbol. Recorrido post-orden
//==========================================
void postOrden(apNodo ptrArbol)
{
    if ( ptrArbol != NULL) {
        postOrden(ptrArbol->Izq);
        postOrden(ptrArbol->Der);
        cout << ptrArbol->numero << " ";
    } // if
} // postOrden

/////////////////// Fin de archivo
