// *******************************
// Fecha: Sesión 27
// Practica: No. 33
// Objetivo: Grafos en C++ (POO)
// Materia: Estructuras de datos
// *******************************

// Librerias
// =================================================
#include <windows.h>
#include <iostream>
#include <time.h>
using namespace std;

// Implementacion de grafos
// =================================================
class nodoa {
public:
    int ady;
    int peso;
    nodoa *siguiente;
	//constructor
    nodoa(int v,int p, nodoa *sig = NULL)
    {
        ady = v;
        peso=p;
        siguiente = sig;
    }
    
    class listaa;
};

typedef nodoa *pnodoa;

// =================================================
class listaa {
public:
    pnodoa primero;
    //constructor
	listaa() { primero =  NULL; }// crea la lista vacia
	//metodos
	void Insertara(int v); // insert
    // void Borrara(int v);// delete
    bool ListaaVacia();  //empty
    void Mostrara();// recorrer
    
};

// =================================================
class nodoc{
public:
	int valor;
	
	nodoc *siguiente;
	nodoc(int val,nodoc *sig=NULL){
        valor=val;
        
        siguiente=sig;
	}
	class cola;
};

typedef nodoc *pnodoc;

// =================================================
class cola{
public:
	pnodoc inicio;
	pnodoc fin;
	cola(){
        inicio=NULL;
        fin=NULL;
	}
	bool colavacia();
	void ingresar(int val);
	int leer();
};

bool cola::colavacia(){
    return inicio==NULL;
}

void cola::ingresar(int val){
    
	if(colavacia()){
		inicio=new nodoc(val);
		fin=inicio;
	}
	else{
		fin->siguiente=new nodoc(val);
		fin=fin->siguiente;
	}
}

int cola::leer(){
    nodoc *auxnodoc;
    auxnodoc=inicio;
    
    if (colavacia())
    {
        cout<<"cola vacia"<<endl;
        return(0);
    }
    else
    {
        inicio=auxnodoc->siguiente;
        return auxnodoc->valor;
        delete(auxnodoc);
        
        if(colavacia()){
            fin=NULL;
        }
    }
}

#define tam 100

// =================================================
class pila {
private:
	int pilita[tam];
	int cima;
public:
	pila(){
        cima=-1;
	}
    void push(int v);
    int pop();
    int ver(int i);
    bool pilavacia();
    bool pilallena();
};

bool pila::pilavacia(){
    return cima==-1;
}

bool pila::pilallena(){
    return cima==tam-1;
}

int pila::ver(int i){
    return pilita[i];
}

void pila::push(int v){
	if ( pilallena() ) {
        cout<<"la pila esta llena";
	}
	else{
        cima++;
        pilita[cima]=v;
        
	}
}

int pila::pop(){
    if ( pilavacia() ) {
		cout<<"la pila esta vacia";
        return 0;
    }
    else {
		cima--;
		return pilita[cima+1];
    }
}

// =================================================
#define Max 100
#define INF 999

// funcion gotoxy
void gotoxy(short x, short y);

//funcion para cambiar el color del texto
void text_color( int col );

//matriz de adyacencia
int MatrizAdyacente[Max][Max];

//matriz de caminos o valorada
int MatrizCaminos[Max][Max];

//matriz de floyd y de warshall
int mat_floyd_warshall[Max][Max];

int visitado[Max];

int marcado[Max];

// =================================================
class nodo {
public:
    int vertice;
	nodoa *puntero;
    nodo *siguiente;
	//constructor
    nodo(int v, nodo *sig = NULL,nodoa *punt=NULL)
    {
        vertice = v;
        siguiente = sig;
        puntero=punt;
    }
    // friend class listaa;
    class lista;
};

typedef nodo *pnodo;

// =================================================
class lista {
public:
    
    // listaa ad;
    pnodo primero;
    
    // Constructor
    // crea la lista vacia
	lista() { primero =  NULL; }
	
    //  Metodos
	void Insertarv(int v);
    void Borrarv(int v);
    bool ListavVacia();
    void Mostrarv();
    pnodo Buscarv( int v);
    void BorrarListav();
    bool listavexiste(int i,int f);
	void creararco(int i,int f,int peso);
	void CrearMatrizAdyacencia();
	int CantidadVertices();
	int ExisteArco(int i,int f);
	void mostrarmatriz();
	bool BuscarAdy(pnodo aux,int ad);
	void CrearMatrizCaminos();
	void MostrarMatrizCaminos();
	void RecorridoAnchura();
	int NodoVisitado(int v, int t);
	void RecorridoProfundidad();
	void Floyd();
	void Warshall();
	void copiarMatrizCaminos();
	void mostrar_mat_floyd_warshall();
	int Posicion(int v);
	bool marca(int ady ,int ident[Max],int i);
};

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::creararco(int i,int f,int peso){
	pnodo pos;
	pos=primero;
	
    if(listavexiste(i,f)){
        while(pos!=NULL){ // se recorre la lista  hasta encontrar el valor buscado
            if(i == pos->vertice ){
                
                if(pos->puntero==NULL){
                    pos->puntero=new nodoa(f,peso);
                }
                else {
                    nodoa *temp=pos->puntero;
					while(temp->siguiente!=NULL){
						temp=temp->siguiente;
					}
					temp->siguiente=new nodoa(f,peso);
					temp=NULL;
					delete temp;
				}
            }
			pos=pos->siguiente;
        }
	}
	else cout<<"no se puede crear arco"<<endl;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool lista::listavexiste(int i,int f)
{
	if (Buscarv(i)!=NULL && Buscarv(f)!=NULL)
        return true;
	else
        return false;
} //

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::Insertarv(int v)
{
    pnodo  anterior;
    
    if (ListavVacia()) // Si la lista est· vacÌa
    {
        primero = new nodo(v, primero);
    } else {
        if (v<=primero->vertice) {
            // si el valor a insertar es menor que el
            //se inserta el nodo antes del primer dato de la lista
            primero =new nodo(v, primero) ;
            
        } else  {
            //en caso contrario se busca el nodo que tenga un dato menor a valor
            // Avanzamos hasta que el siguiente tenga un valor mayor que valor
            anterior = primero;
            while((anterior->siguiente) && (anterior->siguiente->vertice<=v)) {
                anterior = anterior->siguiente;
            }
            // Creamos un nuevo nodo despuÈs del nodo anterior, y cuyo siguiente
            // es el siguiente del anterior
            anterior->siguiente = new nodo(v, anterior->siguiente);
        } // if-else
    }
} //

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::Borrarv(int v)
{
    pnodo anterior, nodo;
    nodo = primero;
    anterior = NULL;
    
    if (primero)
    {  // si la lista tiene  datos se busca el nodo a borrar
        
        while((nodo) && nodo->vertice !=v)
        { // busca el dato igual al valor
            anterior = nodo;
            nodo = nodo->siguiente;
	    }
        if (!nodo)
        {// en este caso el valor buscado no esta en la lista
            cout<<"\n NO existe en la lista";
        }
        else { // Borrar el nodo
            if (anterior==NULL) //* Primer elemento
				primero = primero->siguiente;
            else  //* un elemento cualquiera
				anterior->siguiente = nodo->siguiente;
            delete nodo; // se libera el nodo es decir se borra
        }
    } else
        cout<<"\n no hay elementos para borrar";
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::Mostrarv()
{
    pnodo nodo = primero;
    
    if (ListavVacia())
        cout<<"\nLista vacÌa"<<'\n'; // si hay datos para mostrar
    else
    {
        while(nodo)
        {  // mientras tenga datos la lista
            cout<<" vertice:\t";
            //text_color(8);
            cout<<nodo->vertice;
            //text_color(7);
            cout<<"\tadyacentes";
            nodoa *temp=nodo->puntero;
            while(temp){
                //text_color(11);
                cout<<"\t"<<temp->ady;   /*<<"peso: "<<temp->peso*/
                temp=temp->siguiente;
                
            }
            cout<<endl<<endl;
            nodo = nodo->siguiente;
            //text_color(7);
        }
        cout<<'\n';
    }
    //text_color(7);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
pnodo lista::Buscarv(int valor){
	pnodo indice,n=NULL;
	indice=primero;
	
    while (indice!=NULL)
    { // se recorre la lista  hasta encontrar el valor buscado
		if (valor == indice->vertice )
        {
			return indice; // al encontar el valor  lo retorna
        }
		indice=indice->siguiente;
	}
    cout<<"\n no esta en la lista";
    return n; // si el valor buscado no esta en la lista retorna nulo
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::BorrarListav(){
	pnodo nodo;
    
    while(primero)
    { //mientras la lista tenda datos los borra
        nodo = primero;
        primero = nodo->siguiente;
        delete nodo; // se libera la memoria de  cada nodo
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool lista::ListavVacia(){
	return primero == NULL;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int lista::CantidadVertices(){
    pnodo nodo=primero;
    int i=0;
    
    while(nodo!=NULL){
        i++;
        nodo=nodo->siguiente;
    }
    return i;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::CrearMatrizAdyacencia(){
    pnodo nodo=primero,nodotemp=nullptr;
    int i,j;
    
    int cant=CantidadVertices();
    
    for(i=0;i<cant;i++){
        nodotemp=primero;
        for(j=0;j<cant;j++){
            MatrizAdyacente[i][j]=ExisteArco(nodo->vertice,nodotemp->vertice);
            nodotemp=nodotemp->siguiente;
        }
        nodo=nodo->siguiente;
    }
    delete nodo;
    delete nodotemp;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int lista::ExisteArco(int i,int f)
{
    pnodo nodo;
    
    int a=1;
    nodo=Buscarv(i);
    
    if (nodo) {
        if ( BuscarAdy(nodo,f) )
            return a;
        else
            return a=0;
    }
    return a;   // AGREGADA
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool lista::BuscarAdy(pnodo aux,int ad){
    nodoa *temp=aux->puntero;
    bool a;
    
    while(temp){
        if (ad==temp->ady)
        {
            return a=true;
        }
        temp=temp->siguiente;
    }
    return a=false;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::mostrarmatriz(){
    int i,j,cant;
    pnodo nodo=primero;
    
    cant=CantidadVertices();
    cout<<"   ";
    
    for(i=0;i<cant;i++){
        //text_color(11);
        cout<<"\t"<<nodo->vertice<<" ";
        nodo=nodo->siguiente;
    }
    nodo=primero;cout<<"\n\n";
    for( i=0;i<cant;i++){
        //text_color(11);
        cout<<nodo->vertice;
        for(j=0;j<cant;j++){
            //text_color(7);
            cout<<"\t"<<MatrizAdyacente[i][j]<<" ";
        }
        nodo=nodo->siguiente;
        cout<<"\n";
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::CrearMatrizCaminos(){
    pnodo nodo=primero,nodotemp=NULL,nodoaux;
    nodoa *auxiliar;
    int i,j;
    
    int cant=CantidadVertices();
    
    for(i=0;i<cant;i++){
        nodotemp=primero;
        for(j=0;j<cant;j++){
            if(nodo->vertice==nodotemp->vertice){
                MatrizCaminos[i][j]=0;
            }else{
                if(ExisteArco(nodo->vertice,nodotemp->vertice)==1){
                    nodoaux=Buscarv(nodo->vertice);
                    auxiliar=nodoaux->puntero;
                    while(auxiliar){
                        if(nodotemp->vertice==auxiliar->ady){
                            MatrizCaminos[i][j]=auxiliar->peso;
                        }
                        auxiliar=auxiliar->siguiente;
                    }
                    
                }else{
                    MatrizCaminos[i][j]=INF;
                }
            }
            
            nodotemp=nodotemp->siguiente;
        }
        nodo=nodo->siguiente;
    }
    delete nodo;
    delete nodotemp;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::MostrarMatrizCaminos(){
    int i,j,cant;
    char x='-';
    pnodo nodo=primero;
    
    cant=CantidadVertices();
    cout<<" ";
    
    for(i=0;i<cant;i++){
        //text_color(11);
        cout<<"\t"<<nodo->vertice<<" ";
        nodo=nodo->siguiente;
    }
    nodo=primero;
    cout<<"\n\n";
    for( i=0;i<cant;i++){
        //text_color(11);
        cout<<nodo->vertice<<" ";
        for (j=0;j<cant;j++){
            if (MatrizCaminos[i][j]==INF){
                //text_color(7);
                cout<<"\t"<<x<<" ";
            }
            else {
                //text_color(7);
                cout<<"\t"<<MatrizCaminos[i][j]<<" ";
            }
        }
        nodo=nodo->siguiente;
        cout<<"\n";
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::RecorridoAnchura()
{
    pnodo v;
    v=primero;
    cola c;
    nodoa *ady;
    ady=v->puntero;
    int i=0,l;
    //int col=5,fil=5,col2=col;
    int marcado[100];
    
    c.ingresar(v->vertice);
    //Sleep(150);
    //text_color(11);gotoxy(fil,col++);
    cout<<v->vertice;
    marcado[i]=v->vertice;
    while(!c.colavacia()){l=c.leer();
        //Sleep(150);
        //text_color(7);
        //gotoxy(fil+10,col2);
        cout<<l<<"\t";
        //col2++;
        v=primero;
        while(v){
            if(l==v->vertice){
                ady=v->puntero;
                while(ady){
                    if(marca(ady->ady,marcado,i)){
                        c.ingresar(ady->ady);
                        //Sleep(400);
                        //text_color(11);
                        //gotoxy(fil,col++);
                        cout<<ady->ady << " ";
                        marcado[i++]=ady->ady;
                    }
                    ady=ady->siguiente;
                    
                }
            }
            v=v->siguiente;
        }
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int lista::NodoVisitado(int v, int t){
    int i;
    
    for(i=0;i<t;i++){
        if(v==marcado[i]||v==visitado[i]){
            return 0;
        }
    }
    return 1;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::RecorridoProfundidad(){
    pnodo v;
    v=primero;
    pila pil;
    nodoa *ady;
    ady=v->puntero;
    int i=0,l;
    //int col=5, fil=5, col2=col;
    int marcado[100];
    
    pil.push(v->vertice);
    //Sleep(150);
    //text_color(11);
    //gotoxy(fil,col++);
    cout<<v->vertice;
    marcado[i]=v->vertice;
    
    while(!pil.pilavacia())
    {
        l=pil.pop();
        //Sleep(150);
        //text_color(7);
        //gotoxy(fil+10,col2);
        cout<<l<<"\t";
        //col2++;
        v=primero;
        while(v){
            if (l==v->vertice)
            {
                ady=v->puntero;
                while(ady){
                    if(marca(ady->ady,marcado,i))
                    {
                        pil.push(ady->ady);
                        //Sleep(400);
                        //text_color(11);
                        //gotoxy(fil,col++);
                        cout<<ady->ady << " ";
                        marcado[i++]=ady->ady;
                    }
                    ady=ady->siguiente;
                }
            }
            v=v->siguiente;
        }
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::Floyd(){
    int k,i,j,cant=CantidadVertices();
    
    copiarMatrizCaminos();
    
	for(k=0;k<cant;k++){
		for(i=0;i<cant;i++){
			for(j=0;j<cant;j++){
				if(mat_floyd_warshall[i][j] > mat_floyd_warshall[i][k] + mat_floyd_warshall[k][j]){
					mat_floyd_warshall[i][j] = mat_floyd_warshall[i][k] + mat_floyd_warshall[k][j];
				}//fin si
			}//fin for j
		}//fin for i
	}//fin for k
	
    mostrar_mat_floyd_warshall();
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::Warshall(){
    int k,i,j,cant=CantidadVertices();
	
    copiarMatrizCaminos();
	for(k=0;k<cant;k++){
		for(i=0;i<cant;i++){
			for(j=0;j<cant;j++){
				if(!mat_floyd_warshall[i][j] && (mat_floyd_warshall[i][k] && mat_floyd_warshall[k][j])){
					mat_floyd_warshall[i][j] = mat_floyd_warshall[i][j] || (mat_floyd_warshall[i][k] && mat_floyd_warshall[k][j]);
			    }//fin si
			}//fin for j
		}//fin for i
	}//fin for k
	mostrar_mat_floyd_warshall();
    
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::copiarMatrizCaminos(){
	int i,j,cant=CantidadVertices();
    
	CrearMatrizCaminos();
	for( i=0;i<cant;i++){
        for(j=0;j<cant;j++){
			mat_floyd_warshall[i][j] =MatrizCaminos[i][j];
        }
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void lista::mostrar_mat_floyd_warshall(){
    int i,j,cant=CantidadVertices();
    pnodo nodo=primero;
    char x='-';   // x=236;
    
    for(i=0;i<cant;i++){
        // text_color(8);
        cout<<"\t"<<nodo->vertice<<" ";
        nodo=nodo->siguiente;
    }
    nodo=primero;
    cout<<"\n\n";
	for( i=0;i<cant;i++){
        //text_color(8);
        cout<<nodo->vertice;
        for(j=0;j<cant;j++){
            if(mat_floyd_warshall[i][j]==INF){
                //text_color(7);
                cout<<"\t"<<x;
            }
            else{
                //text_color(7);
                cout<<"\t"<<mat_floyd_warshall[i][j];
            }
        }
        cout<<"\n";
        nodo=nodo->siguiente;
    }
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// funcion gotoxy
void gotoxy(short x, short y) {
	/* HANDLE hConsoleOutput;
     COORD Cursor_Pos = {x, y};
     hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
     */
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void text_color( int col ){
    /* HANDLE hOutput = NULL;
     if( hOutput == NULL )
     hOutput = GetStdHandle( STD_OUTPUT_HANDLE );
     SetConsoleTextAttribute( hOutput, (WORD) col );
     */
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int lista::Posicion(int v)
{
	pnodo nodo=primero;
	int i=0;
    
	while(nodo)
    {
		if (nodo->vertice==v)
        {
			return i-1;
		}
		i++;
		nodo=nodo->siguiente;
	}
    return i;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool lista::marca(int ady ,int ident[Max],int i){
    bool s;
	
    for(int f=0;f<i;f++){
        if(ady==ident[f]){
            return s=false;
        }
    }
    return s=true;
}

// =================================================
int main(void) {
    
    lista l;
    int opc;
    
    do {
        system("cls");
        cout << "\nManipulacion de un Grafo\n";
        cout << "1- Crear Grafo pre-determinado \n";
        cout << "2- Crear Matriz de Adyacencia \n";
        cout << "3- Crear Matriz de Caminos \n";
        cout << "4- Mostar Lista de Nodos Adyacentes \n";
        cout << "5- Recorrido En Profundidad \n";
        cout << "6- Recorrido En Anchura \n";
        cout << "7- Mostar Matriz de Floyd \n";
        cout << "8- Mostar Matriz de Warshall \n";
        cout << "9- Salir\n\n";
        cout << "=========================\n";
        cout << "Ingrese la opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:
                //system("cls");
                l.BorrarListav();
                
                // vetices
                l.Insertarv(5);
                l.Insertarv(8);
                l.Insertarv(6);
                l.Insertarv(11);
                l.Insertarv(19);
                l.Insertarv(15);
                
                // arcos con:  vertice inicial, vertice final, peso
                l.creararco(5,6,4);
                l.creararco(5,15,13);
                l.creararco(5,19,2);
                l.creararco(15,8,5);
                l.creararco(15,6,13);
                l.creararco(8,19,21);
                l.creararco(8,11,4);
                l.creararco(19,11,4);
                l.creararco(6,11,5);
                l.creararco(11,8,15);
                break;
                
            case 2:
                //system("cls");
                if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
                    cout<<"\n\nMatriz de adyacencia"<<"\n\n";
                    l.CrearMatrizAdyacencia();
                    l.mostrarmatriz();}
                break;
                
            case 3:
                //system("cls");
                if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
                    cout<<"\n\nMatriz de caminos\n\n";
                    l.CrearMatrizCaminos();
                    l.MostrarMatrizCaminos();}
                break;
                
            case 4:
                //system("cls");
                if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
                    cout<<"\n\nVertices Adyacentes\n\n";
                    l.Mostrarv();}
                break;
                
            case 5:
                //system("cls");
                if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
                    cout<<"\n\nRecorrido Profundidad\n\n";
                    l.RecorridoProfundidad();}
                break;
                
            case 6:
                //system("cls");
                if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
                    cout<<"\n\nRecorrido Anchura\n\n";
                    l.RecorridoAnchura();}
                break;
                
            case 7:
                //system("cls");
                if(l.ListavVacia()){cout<<"\n\nGrafo Vacio\n\n";}else{
                    cout<<"\n\nFloyd\n\n";
                    l.Floyd();}
                break;
                
            case 8:
                //system("cls");
                if  (l.ListavVacia())
                {
                    cout<<"\n\nGrafo Vacio\n\n";
                }
                else
                {
                    cout<<"\n\nWarshall\n\n";
                    l.Warshall();
                }
                break;
                
            default:
                cout << "Opcion no valida" << endl;
                break;
        } // switch
        
        cout<<"\n\n";
        system("pause");
        
    } while( opc != 9);
    return 0;
} // main

// ****************   fin de archivo
