/*
  ! Fecha: Martes 10 de septiembre de 2024
  ! Archivo biblioCad.h
*/

//! 1. longCad
//! ==============================================================
int longCad(char *cadena){
  int contador=0;
  while(*cadena != '\0'){
    contador++; // calcula la long
    cadena++; // recorre el apuntador
  }

  return contador;
}//* longCad()


//! 2. conCad
//! ==============================================================
void conCad(char *peli, char *pers){
  // 1. ir al final de peli
  while(*peli != '\0'){
    peli++;
  }// while

  // 2. copiar pers en peli
  while(*pers != '\0'){
    *peli = *pers;
    peli++;
    pers++;
  } // while

  // 3. fin de cadena a peli
  *peli = '\0';

  return;
}//* conCad()


//! 3. minusCad
//! ==============================================================
void minusCad(char *cadena){
  while(*cadena != '\0'){
    if(*cadena >= 65 && *cadena <= 90){
      *cadena += 32;
    } // if
    cadena++;
  } // while

  return;
}//* minusCad()


//! 4. copCad
//! ==============================================================
void copCad(char *peli, char *pers){
  // 1. copiar pers en peli
  while(*pers != '\0'){
    *peli = *pers;
    peli++;
    pers++;
  } // while

  // 2. fin de cadena a peli
  *peli = '\0';

  return;
}//* conCad()


//! 5. cmpCad
//! ==============================================================
bool cmpCad(char *peli, char *pers){
  // declaracion de var locales
  int largo1, largo2;
  // calcular long de ambas cadenas
  largo1 = longCad(peli);
  largo2 = longCad(pers);
  
  // caso 1. las cadenas tienen diferente long
  if(largo1 != largo2){
    return false;
  } // if

  // caso 2. las cadenas tienen misma longitud
  while(*peli != '\0'){
    if(*peli != *pers){
      return false;
    }
    peli++;
    pers++;
  } // while

  return true;
}//* cmpCad()


//! 6. revCad (TAREA 1)
//! ==============================================================
void revCad(char *cadena){
  // declaracion de var locales
  int largo;
  char aux;
  // calcular long de la cadena
  largo = longCad(cadena);
  // acomodar la cadena al reves
  for(int i=0; i<largo/2; i++){
    aux = cadena[i];
    cadena[i] = cadena[largo-1-i];
    cadena[largo-1-i] = aux;
  }
  
}//* revCad()

//! 7. mayusCad (TAREA 2)
//! ==============================================================
void mayusCad(char *cadena){
  while(*cadena != '\0'){
    if(*cadena >= 97 && *cadena <= 122){
      *cadena -= 32;
    } // if
    cadena++;
  } // while

  return;
}//* mayusCad()