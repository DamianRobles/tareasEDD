/*
  ! Fecha: Martes 10 de septiembre de 2024
  ! Archivo biblioCad.h
*/

//! 1. longCad
//! ====================================================
int longCad(char *cadena){
  int contador=0;
  while(*cadena != '\0'){
    contador++; // calcula la long
    cadena++; // recorre el apuntador
  }
  return contador;
}//* longCad()

//! 2. conCad
//! ====================================================
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
  
}//* conCad()

//! 1. longCad
//! ====================================================
