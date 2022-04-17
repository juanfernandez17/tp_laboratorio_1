/*
 * Input.h

 	 Fernàndez Juan Ignacio 1ºB
 	 Trabajo pràctico Nº1
 */
#include <stdio_ext.h>
#include <stdlib.h>

#ifndef INPUT_H_
#define INPUT_H_

/// @brief Pide al usuario ingresar un numero que debe estar entre el rango establecido
/// @param char[] Mensaje que se imprime para pedirle al usuario que ingrese el numero
/// @param char[] Mensaje de error que se imprime cuando el usuario ingresa un numero no valido
/// @param int Nùmero mìnimo que se puede ingresar
/// @param int Nùmero maximo que se puede ingresar
/// @return Numero ingresado y validado entre el rango establecido
float PedirNumero(char[], char[], int, int);

#endif /* INPUT_H_ */
