/*
  ! Fecha: Martes 10 de septiembre de 2024
  ! Archivo biblioCad.h
/*
  ? Leer y almacenar una cadena de caracteres en arreglo
  ? Implementa la función longitud de cadena usando apuntadores
  ? Implementa la función concatenar dos cadenas usando apuntadores
  ? Implementa la función convertir a minúsculas una cadena usando apuntadores
  ? Implementa la función copiar una cadena en otra usando apuntadores
  ? Implementa la función comparar dos cadenas
*/

//* 1. longCad
int longCad(char *cadena){
  int contador=0;
  while(*cadena != '\0'){
    contador++; // calcula la long
    cadena++; // recorre el apuntador
  }
  return contador;
}//* longCad()
