// ======================================
// Fecha: martes 27 de agosto de 2024
// Autor: Rebeca
// Práctica No.: 6
// Objetivo: Tipos de Datos enumerados
// ======================================

// Librerías
#include <iostream>
using namespace std;

// Definir nuevos TDA's
enum TipoFigura {Cuadro, Triangulo, Circulo};
enum DiaSemana {Lunes=1, Martes, Miercoles, Jueves, Viernes, Sabado, Domingo};
enum TipoEleccion {Piedra, Papel=4, Tijeras};
enum Modo {Apagado, Encendido};

// Función principal
int main(void) {
    // Declaración de variables
    TipoFigura figura; 
    DiaSemana dia=Sabado;
    Modo lampara=Encendido;
 
    figura = Circulo;
 
   // Revisamos el valor predeterminado que asigna el compilador a los enumeradores
    cout << "Valor de Cuadro: " << Cuadro << endl;
    cout << "Valor de Triangulo: " << Triangulo << endl;
    cout << "Valor de Circulo: " << Circulo << endl;
    
    cout << "Valor de Lunes: " << Lunes << endl;
    cout << "Valor de Martes: " << Martes << endl;
    cout << "Valor de Domingo: " << Domingo << endl;
    cout << "dia:  " << dia << endl;
    
    cout << "Valor de Apagado " << Apagado << endl;
    cout << "Valor de Encendido " << Encendido << endl;
    if ( lampara == Encendido) 
        lampara = Apagado;
    else 
        lampara = Encendido;
    cout << "lampara " << lampara << endl;
 
    cout << "Valor de Piedra: " << Piedra << endl;
    cout << "Valor de Papel: " << Papel << endl;
    cout << "Valor de Tijeras: " << Tijeras << endl;
    
    switch (figura) {
        case Cuadro: 
            cout << "Actividades para Cuadros " << figura << endl; 
            break;
        case Triangulo: 
            cout << "Actividades para Triángulo " << figura << endl; 
            break;
        case Circulo: 
            cout << "Actividades para Círculo " << figura << endl; 
            break;
        default: 
            cout << "Función no implementada"; 
            break;
    } // switch
  
    return 0;
} // main
