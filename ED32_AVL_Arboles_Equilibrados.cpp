//==================================================================
// Objetivo: Arbol AVL
//    (C) Mayo 2002, Salvador Pozo
//    C con Clase:
// Fecha: Sesion 26 
// Practica No.: 32
//==================================================================

//============= PREPROCESADOR ======================================
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

//============= DATOS ESTRUCTURADOS ================================
/* IZQUIERDO=0,  DERECHO=1 */
enum {IZQUIERDO, DERECHO};

typedef struct _nodo {
    int dato;
    int FE;                     // Factor de Equilibrio
    struct _nodo *derecho;
    struct _nodo *izquierdo;
    struct _nodo *padre;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;

//============== PROTOTIPOS DE FUNCIONES  ==========================
/* Insertar en arbol ordenado: */
void Insertar(Arbol *a, int dat);

/* Borrar un elemento: */
void Borrar(Arbol *a, int dat);

/* Funcion de busqueda: */
int Buscar(Arbol a, int dat);

/* Comprobar si el arbol esta vacio: */
int Vacio(Arbol r);

/* Comprobar si es un nodo hoja: */
int EsHoja(pNodo r);

/* Contar numero de nodos: */
int NumeroNodos(Arbol a, int* c);

/* Calcular la altura de un arbol: */
int AlturaArbol(Arbol a, int* altura);

/* Calcular altura de un dato: */
int Altura(Arbol a, int dat);

// Aplicar una funcion a cada elemento del arbol
void InOrden(Arbol, void (*func)(int*));
void PreOrden(Arbol, void (*func)(int*));
void PostOrden(Arbol, void (*func)(int*));

// Funciones de equilibrado:
void Equilibrar(Arbol *raiz, pNodo nodo, int, int);
void RSI(Arbol *raiz, pNodo nodo);
void RSD(Arbol *raiz, pNodo nodo);
void RDID(Arbol *raiz, pNodo nodo);
void RDDI(Arbol *raiz, pNodo nodo);

// Funciones auxiliares:
void Podar(Arbol *a);
void auxContador(Arbol a, int*);
void auxAltura(Arbol a, int, int*);
void Mostrar(int *d);

//============== PROGRAMA PRINCIPAL ==========================
int main(void) {
    /* Declaracion de variables */
    Arbol ArbolInt=NULL;
    int altura;
    int nnodos;
    
    /* Insercion de nodos en arbol: */
    cout << "ARBOL AVL. Se insertan los siguiente elementos."  << endl;
    cout << "10 5  12  4  7  3  6  9  8  11  14  13 2  1  15  10  17 18 16 " << endl;
    
    Insertar(&ArbolInt, 10);
    Insertar(&ArbolInt, 5);
    Insertar(&ArbolInt, 12);
    Insertar(&ArbolInt, 4);
    Insertar(&ArbolInt, 7);
    Insertar(&ArbolInt, 3);
    Insertar(&ArbolInt, 6);
    Insertar(&ArbolInt, 9);
    Insertar(&ArbolInt, 8);
    Insertar(&ArbolInt, 11);
    Insertar(&ArbolInt, 14);
    Insertar(&ArbolInt, 13);
    Insertar(&ArbolInt, 2);
    Insertar(&ArbolInt, 1);
    Insertar(&ArbolInt, 15);
    Insertar(&ArbolInt, 10);
    Insertar(&ArbolInt, 17);
    Insertar(&ArbolInt, 18);
    Insertar(&ArbolInt, 16);
    
    // Altura del arbol
    cout << "Altura de arbol "  << AlturaArbol(ArbolInt, &altura) << endl;
    
    /* Mostrar el Arbol en tres ordenes distintos: */
    cout << "Recorrido InOrden: " ;
    InOrden(ArbolInt, Mostrar);
    cout << endl;
    
    cout << "Recorrido PreOrden: ";
    PreOrden(ArbolInt, Mostrar);
    cout << endl;
    
    cout << "Recorrido PostOrden: ";
    PostOrden(ArbolInt, Mostrar);
    cout << endl;
    
    // Total de nodos
    cout << "Numero de nodos: " <<  NumeroNodos(ArbolInt, &nnodos) << endl;
    
    /* Borraremos algunos elementos: */
    cout << "Borraremos algunos elementos " << endl;
    
    cout << "Borrar 5: " << endl;
    Borrar(&ArbolInt, 5);
    InOrden(ArbolInt, Mostrar);
    cout << endl;
    
    cout << "Borrar 8: " << endl;
    Borrar(&ArbolInt, 8);
    InOrden(ArbolInt, Mostrar);
    cout << endl;
    
    cout << "Borrar 15: " << endl;
    Borrar(&ArbolInt, 15);
    InOrden(ArbolInt, Mostrar);
    cout << endl;
    
    cout << "Borrar 245: " << endl;
    Borrar(&ArbolInt, 245);
    InOrden(ArbolInt, Mostrar);
    cout << endl;
    
    cout <<  "Borrar 4: " << endl;
    Borrar(&ArbolInt, 4);
    InOrden(ArbolInt, Mostrar);
    cout << endl;
    
    cout << "Borrar 17: " << endl;
    Borrar(&ArbolInt, 17);
    InOrden(ArbolInt, Mostrar);
    cout << endl;
    
    /* Visualizar informacion del arbol */
    cout << "Numero de nodos: " << NumeroNodos(ArbolInt, &nnodos) << endl;
    cout << "Altura de 1 --> " << Altura(ArbolInt, 1) << endl;
    cout << "Altura de 10 --> " << Altura(ArbolInt, 10) << endl;
    cout << "Altura de arbol --> " << AlturaArbol(ArbolInt, &altura) << endl;
    
    /* Liberar memoria asociada al arbol: */
    Podar(&ArbolInt);
    
    return(0);
} // main()

/* Poda: borrar todos los nodos a partir de uno, incluido */
// ===========================================================
void Podar(Arbol *a) {
    /* Algoritmo recursivo, recorrido en postorden */
    if (*a) {
        Podar(&(*a)->izquierdo); /* Podar izquierdo */
        Podar(&(*a)->derecho);   /* Podar derecho */
        free(*a);                /* Eliminar nodo */
        *a = NULL;
    } // if
} // Podar()

/* Insertar un dato en el arbol ABB */
// ===========================================================
void Insertar(Arbol *a, int dat)
{
    pNodo padre = NULL;
    pNodo actual = *a;
    
    /* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
    while (!Vacio(actual) && dat != actual->dato) {
        padre = actual;
        if (dat < actual->dato)
            actual = actual->izquierdo;
        else
            if(dat > actual->dato)
                actual = actual->derecho;
    } // while
    
    /* Si se ha encontrado el elemento, regresar sin insertar */
    if ( ! Vacio(actual) )
        return;
    
    /* Si padre es NULL, entonces el arbol estaba vacio, el nuevo nodo ser el nodo raiz */
    if ( Vacio(padre) ) {
        *a = (Arbol)malloc(sizeof(tipoNodo));
        (*a)->dato = dat;
        (*a)->izquierdo = (*a)->derecho = NULL;
        (*a)->padre = NULL;
        (*a)->FE = 0;
    } else
        if (dat < padre->dato)
        {
            /* Si el dato es menor que el que contiene el nodo padre, lo insertamos en la rama izquierda */
            actual = (Arbol)malloc(sizeof(tipoNodo));
            padre->izquierdo = actual;
            actual->dato = dat;
            actual->izquierdo = actual->derecho = NULL;
            actual->padre = padre;
            actual->FE = 0;
            Equilibrar(a, padre, IZQUIERDO, TRUE);
        } else
            if (dat > padre->dato)
            {
                /* Si el dato es mayor que el que contiene el nodo padre, lo insertamos en la rama derecha */
                actual = (Arbol)malloc(sizeof(tipoNodo));
                padre->derecho = actual;
                actual->dato = dat;
                actual->izquierdo = actual->derecho = NULL;
                actual->padre = padre;
                actual->FE = 0;
                Equilibrar(a, padre, DERECHO, TRUE);
            } // if
} // Insertar()

/* Equilibrar Arbol AVL partiendo del nodo nuevo */
// ===========================================================
void Equilibrar(Arbol *a, pNodo nodo, int rama, int nuevo)
{
    int salir = FALSE;
    
    /* Recorrer camino inverso actualizando valores de FE: */
    while (nodo && !salir) {
        if (nuevo)
            if (rama == IZQUIERDO)
                nodo->FE--; /* Depende de si insertamos ... */
            else
                nodo->FE++;
        else
            if(rama == IZQUIERDO)
                nodo->FE++;  /* ... o si borramos */
            else
                nodo->FE--;
        
        /* Si la altura de las ramas que empieza en nodo no ha variado, salir de Equilibrar */
        if (nodo->FE == 0)
            salir = TRUE;
        else
            if (nodo->FE == -2)
            {
                /* ROTAR DERECHA y salir */
                if (nodo->izquierdo->FE == 1)
                    RDDI(a, nodo); /* Rotacion doble Derecha-Izquierda. Diferente signo -2 y +1 */
                else
                    RSD(a, nodo); /* Rotacion simple Derecha. Mismo signo -2 y -1, 0 */
                salir = TRUE;
            } else
                if (nodo->FE == 2)
                {
                    /* ROTAR IZQUIERDA y salir */
                    if (nodo->derecho->FE == -1)
                        RDID(a, nodo);     /* Rotacion doble Izquierda-Derecha. Diferente signo +2 y -1 */
                    else
                        RSI(a, nodo);     /* Rotacion simple Izquierda. Mismo signo +2 y +1 y 0 */
                    salir = TRUE;
                } // if
        
        if (nodo->padre) {
            if (nodo->padre->derecho == nodo)
                rama = DERECHO;
            else
                rama = IZQUIERDO;
        } // if
        nodo = nodo->padre; /* Calcular FE, siguiente nodo del camino. */
    } // while
 } // Equilibrar()

/* Rotacion doble Derecha-Izquierda */
// ===========================================================
void RDDI(Arbol *raiz, Arbol nodo)
{
    pNodo Padre = nodo->padre;
    pNodo P = nodo;
    pNodo Q = P->izquierdo;
    pNodo R = Q->derecho;
    pNodo B = R->izquierdo;
    pNodo C = R->derecho;
    
    if (Padre)
        if (Padre->derecho == nodo)
            Padre->derecho = R;
        else
            Padre->izquierdo = R;
    else
        *raiz = R;
    
    /* Reconstruir Arbol: */
    Q->derecho = B;
    P->izquierdo = C;
    R->izquierdo = Q;
    R->derecho = P;
    
    /* Reasignar padres: */
    R->padre = Padre;
    P->padre = Q->padre = R;
    if (B)
        B->padre = Q;
    if (C)
        C->padre = P;
    
    /* Ajustar valores de FE: */
    switch(R->FE) {
        case -1:
            Q->FE = 0;
            P->FE = 1;
            break;
        case 0:
            Q->FE = 0;
            P->FE = 0;
            break;
        case 1:
            Q->FE = -1;
            P->FE = 0;
            break;
    }
    R->FE = 0;
}

/* Rotacion doble Izquierda-Derecha */
// ===========================================================
void RDID(Arbol *a, pNodo nodo)
{
    pNodo Padre = nodo->padre;
    pNodo P = nodo;
    pNodo Q = P->derecho;
    pNodo R = Q->izquierdo;
    pNodo B = R->izquierdo;
    pNodo C = R->derecho;
    
    if (Padre)
        if (Padre->derecho == nodo)
            Padre->derecho = R;
        else
            Padre->izquierdo = R;
    else
        *a = R;
    
    /* Re-organizar Arbol: */
    P->derecho = B;
    Q->izquierdo = C;
    R->izquierdo = P;
    R->derecho = Q;
    
    /* Reasignar padres: */
    R->padre = Padre;
    P->padre = Q->padre = R;
    if (B)
        B->padre = P;
    if (C)
        C->padre = Q;
    
    /* Ajustar valores de FE: */
    switch(R->FE) {
        case -1:
            P->FE = 0;
            Q->FE = 1;
            break;
        case 0:
            P->FE = 0;
            Q->FE = 0;
            break;
        case 1:
            P->FE = -1;
            Q->FE = 0;
            break;
    } // switch
    R->FE = 0;
} // RDID

/* Rotacion simple a derecha */
// ===========================================================
void RSD(Arbol *a, pNodo nodo)
{
    pNodo Padre = nodo->padre;
    pNodo P = nodo;
    pNodo Q = P->izquierdo;
    pNodo B = Q->derecho;
    
    if (Padre)
        if (Padre->derecho == P)
            Padre->derecho = Q;
        else
            Padre->izquierdo = Q;
    else
        *a = Q;
    
    /* Reconstruir árbol: */
    P->izquierdo = B;
    Q->derecho = P;
    
    /* Reasignar padres: */
    P->padre = Q;
    if (B)
        B->padre = P;
    Q->padre = Padre;
    
    /* Ajustar valores de FE: */
    P->FE = 0;
    Q->FE = 0;
} // RSD

/* Rotacion simple a izquierda */
// ===========================================================
void RSI(Arbol *a, pNodo nodo)
{
    pNodo Padre = nodo->padre;
    pNodo P = nodo;
    pNodo Q = P->derecho;
    pNodo B = Q->izquierdo;
    
    if (Padre)
        if (Padre->derecho == P)
            Padre->derecho = Q;
        else
            Padre->izquierdo = Q;
    else
        *a = Q;
    
    /* Re-organizar Arbol: */
    P->derecho = B;
    Q->izquierdo = P;
    
    /* Reasignar padres: */
    P->padre = Q;
    if (B)        // Si existe
        B->padre = P;
    Q->padre = Padre;
    
    /* Ajustar valores de FE: */
    P->FE = 0;
    Q->FE = 0;
} // RSI

/* Eliminar un elemento de un arbol */
// ===========================================================
void Borrar(Arbol *a, int dat)
{
    pNodo padre = NULL;
    pNodo actual;
    pNodo nodo;
    int aux;
    
    actual = *a;
    
    /* Mientras sea posible que el valor este en el arbol */
    while (! Vacio(actual) ) {
        if ( dat == actual->dato ) { /* Si el valor esta en el nodo actual */
            if ( EsHoja(actual) ) {  /* Y si ademas es un nodo hoja: lo borramos */
                if (padre) {
                    /* Si tiene padre (no es el nodo raiz) */
                    /* Anulamos el puntero que le hace referencia */
                    if (padre->derecho == actual)
                        padre->derecho = NULL;
                    else
                        if(padre->izquierdo == actual)
                            padre->izquierdo = NULL;
                } // if
                /* Borrar el nodo */
                free(actual);
                actual = NULL;
                /* El nodo padre del actual puede ser ahora un nodo hoja, por lo
                 tanto su FE es cero, pero debemos seguir el camino a partir de
                 su padre, si existe. */
                if ( (padre->derecho == actual && padre->FE == 1) ||
                    (padre->izquierdo == actual && padre->FE == -1) )
                {
                    padre->FE = 0;
                    actual = padre;
                    padre = actual->padre;
                } // if
                
                if (padre)
                {
                    if (padre->derecho == actual)
                        Equilibrar(a, padre, DERECHO, FALSE);
                    else
                        Equilibrar(a, padre, IZQUIERDO, FALSE);
                } // if
                return;
            } else { /* Si el valor esta en el nodo actual, pero no es hoja */
                padre = actual;
                /* Buscar nodo mas a la izquierdo de rama derecha */
                if (actual->derecho) {
                    nodo = actual->derecho;
                    while(nodo->izquierdo) {
                        padre = nodo;
                        nodo = nodo->izquierdo;
                    } // while
                } else {
                    /* O buscar nodo mas a la derecha de rama izquierda */
                    nodo = actual->izquierdo;
                    while(nodo->derecho) {
                        padre = nodo;
                        nodo = nodo->derecho;
                    } // while
                } // if-else
                /* Intercambiar valores de no a borrar u nodo encontrado
                 y continuar, cerrando el bucle. El nodo encontrado no tiene
                 por que ser un nodo hoja, cerrando el bucle nos aseguramos
                 de que solo se eliminan nodos hoja. */
                aux = actual->dato;
                actual->dato = nodo->dato;
                nodo->dato = aux;
                actual = nodo;
              } // if-else
        }
        else { /* Todavia no hemos encontrado el valor, seguir buscandolo */
            padre = actual;
            if (dat > actual->dato)
                actual = actual->derecho;
            else
                if (dat < actual->dato)
                    actual = actual->izquierdo;
        } // if-else
    } // while
} // Borrar()

/* Recorrido de arbol en inorden, aplicamos la funcion func, que tiene  el prototipo: void func(int*); */
// ===========================================================
void InOrden(Arbol a, void (*func)(int*))
{
    if (a->izquierdo)
        InOrden(a->izquierdo, func);
    func(&(a->dato));
    if (a->derecho)
        InOrden(a->derecho, func);
}  // InOrden()

/* Recorrido de arbol en preorden, aplicamos la funcion func, que tiene el prototipo: void func(int*); */
// ===========================================================
void PreOrden(Arbol a, void (*func)(int*))
{
    func(&a->dato);
    if (a->izquierdo)
        PreOrden(a->izquierdo, func);
    if (a->derecho)
        PreOrden(a->derecho, func);
} // PreOrden()

/* Recorrido de arbol en postorden, aplicamos la funcion func, que tiene el prototipo: void func(int*); */
// ===========================================================
void PostOrden(Arbol a, void (*func)(int*))
{
    if (a->izquierdo)
        PostOrden(a->izquierdo, func);
    if (a->derecho)
        PostOrden(a->derecho, func);
    func(&a->dato);
} // PostOrden()

/* Buscar un valor en el arbol */
// ===========================================================
int Buscar(Arbol a, int dat)
{
    pNodo actual = a;
    
    /* Todavia puede aparecer, ya que quedan nodos por visitar */
    while(!Vacio(actual)) {
        if(dat == actual->dato)
            return(TRUE); /* dato encontrado */
        else
            if(dat < actual->dato)
                actual = actual->izquierdo; /* Seguir */
            else
                if(dat > actual->dato)
                    actual = actual->derecho;
    }
    return(FALSE); /* No esta en arbol */
} // Buscar()

/* Calcular la altura del nodo que contiene el dato dat */
// ===========================================================
int Altura(Arbol a, int dat)
{
    int altura = 0;
    pNodo actual = a;
    
    /* Todavía puede aparecer, ya que quedan nodos por mirar */
    while(!Vacio(actual)) {
        if(dat == actual->dato)
            return(altura); /* encontrado: devolver altura */
        else {
            altura++; /* Incrementamos la altura, seguimos buscando */
            if(dat < actual->dato)
                actual = actual->izquierdo;
            else
                if(dat > actual->dato)
                    actual = actual->derecho;
        }
    }
    return(-1); /* No esta en el arbol, devolver -1 */
} // Altura()

/* Contar el numero de nodos */
// ===========================================================
int NumeroNodos(Arbol a, int *contador)
{
    *contador = 0;
    
    auxContador(a, contador); /* Función auxiliar */
    return *contador;
} // NumeroNodos()

/* Funcion auxiliar para contar nodos. Funcion recursiva de recorrido en preorden, el proceso es aumentar el contador */
// ===========================================================
void auxContador(Arbol nodo, int *c)
{
    (*c)++; /* Otro nodo */
    /* Continuar recorrido */
    if(nodo->izquierdo)
        auxContador(nodo->izquierdo, c);
    if(nodo->derecho)
        auxContador(nodo->derecho, c);
} // auxContador()

/* Calcular la altura del arbol, que es la altura del nodo de mayor altura. */
// ===========================================================
int AlturaArbol(Arbol a, int *altura)
{
    *altura = 0;
    
    auxAltura(a, 0, altura);
    return *altura;
} // AlturaArbol()

/* Funcion auxiliar para calcular altura. Funcion recursiva de recorrido en postorden, el proceso es actualizar la altura solo en nodos hojas de mayor altura de la maxima actual */
// ===========================================================
void auxAltura(pNodo nodo, int a, int *altura)
{
    /* Recorrido postorden */
    if (nodo->izquierdo)
        auxAltura(nodo->izquierdo, a+1, altura);
    
    if (nodo->derecho)
        auxAltura(nodo->derecho, a+1, altura);
    
    /* Proceso, si es un nodo hoja, y su altura es mayor que la actual del arbol, actualizamos la altura actual del arbol */
    if ( EsHoja(nodo) && a > *altura )
        *altura = a;
} // auxAltura()

/* Comprobar si un arbol es vacio */
// ===========================================================
int Vacio(Arbol r)
{
    return r==NULL;
} // Vacio()

/* Comprobar si un nodo es hoja */
// ===========================================================
int EsHoja(pNodo r)
{
    return( ! r->derecho && ! r->izquierdo );
} // EsHoja()

/* Funcion de prueba para recorridos del arbol */
// ===========================================================
void Mostrar(int *d)
{
    cout <<  *d  << "-";
} // Mostrar()

// ============= eof
