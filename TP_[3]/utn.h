/*
 	 utn.h

 	 Fernandez Juan Ignacio 1ºB
 	 Biblioteca utn
 */


#ifndef UTN_H_
#define UTN_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/// @brief Le pide al usuario ingresar un numero entero que sera validado dentro de un rango determinado y lo asigna al puntero que se le pasa por parametro
///
/// @param pResultado int Puntero donde se almacenara el numero ingresado por el ususario si es valido
/// @param mensaje char Mensaje para solicitar al usuario que ingrese un numero
/// @param mensajeError char Mensaje para informar al usuario que el numero que ingresò no es valido
/// @param minimo int Numero minimo que puede ingresar el usuario
/// @param maximo int Numero maximo que puede ingresar el usuario
/// @param intenteos int Cantidad de intentos para que el usuario pueda ingresar el numero
/// @return int [0] en caso de que se hayan pasado parametros correctos  [-1] en caso de que se hayan pasado parametros incorrectos
int utn_getNumeroConIntentos(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int intenteos);

/// @brief Le pide al usuario ingresar un numero entero que sera validado dentro de un rango determinado y lo asigna al puntero que se le pasa por parametro
///
/// @param pResultado int Puntero donde se almacenara el numero ingresado por el ususario si es valido
/// @param mensaje char Mensaje para solicitar al usuario que ingrese un numero
/// @param mensajeError char Mensaje para informar al usuario que el numero que ingresò no es valido
/// @param minimo int Numero minimo que puede ingresar el usuario
/// @param maximo int Numero maximo que puede ingresar el usuario
/// @return int [0] en caso de que se hayan pasado parametros correctos  [-1] en caso de que se hayan pasado parametros incorrectos
int utn_getNumero(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo);

/// @brief Le pide al usuario ingresar un numero flotante que sera validado dentro de un rango determinado y lo asigna al puntero que se le pasa por parametro
///
/// @param pResultado float Puntero donde se almacenara el numero ingresado por el ususario si es valido
/// @param mensaje char Mensaje para solicitar al usuario que ingrese un numero
/// @param mensajeError char Mensaje para informar al usuario que el numero que ingresò no es valido
/// @param minimo float Numero minimo que puede ingresar el usuario
/// @param maximo float Numero maximo que puede ingresar el usuario
/// @return int [0] en caso de que se hayan pasado parametros correctos  [-1] en caso de que se hayan pasado parametros incorrectos
int utn_getNumeroFloat(float *pResultado, char mensaje[], char mensajeError[], float minimo, float maximo);

/// @brief Le pide al usuario ingresar un caracter que sera validado dentro de un rango determinado y lo asigna al puntero que se le pasa por parametro
///
/// @param pResultado char Puntero donde se almacenara el caracter ingresado por el usuario si es valido
/// @param mensaje char Mensaje para solicitar al usuario que ingrese un caracter
/// @param mensajeError char Mensaje para informar al usuario que el caracter que ingresò no es valido
/// @param minimo char Letra minima que se puede ingresar
/// @param maximo char Letra maxima que se puede ingresar (ejemplo: de la 'a' hasta la 'j')
/// @return int [0] en caso de que se hayan pasado parametros correctos  [-1] en caso de que se hayan pasado parametros incorrectos
int utn_getCaracter(char *pResultado, char mensaje[], char mensajeError[], char minimo, char maximo);

/// @brief Le pide al usuario ingresar una cadena de caracteres que sera validado (sera valido si la cantidad de caracteres es menor al tamaño del array) y lo asigna al puntero que se le pasa por parametro
///
/// @param pResultado char Puntero donde se almacenara la cadena de caracteres ingresada por el usuario si es valida
/// @param mensaje char Mensaje para informar al usuario que debe ingresar una cadena de caracteres
/// @param mensajeError char Mensaje de error en caso de que el usuario ingrese una cantidad de caracteres superiores al tamaño del array
/// @param TAM int Tamaño que se le asigna al array
/// @return int [0] en caso de que se hayan pasado parametros correctos  [-1] en caso de que se hayan pasado parametros incorrectos
int utn_getString(char *pResultado, char mensaje[], char mensajeError[], int TAM);

/// @brief Le pide al usuario ingresar una respuesta que confirme o no una accion determinada (la que se lleva a cabo cuando se llama a la funcion)
/// 		Las respuestas posibles son: si o no
///
/// @param char Mensaje que comunica al usuario que debe ingresar un si o un no
/// @param char Mensaje de error que se da en caso de que el usuario ingrese algo que no sea un si o un no
/// @return int Retorna [0] en caso de que la respuesta sea NO - Retorna [1] en caso de que la respuesta sea si
int utn_ConfirmarAccion(char mensaje[], char mensajeError[]);

/// @brief Verifica que la cadena ingresada contenga numeros en todas sus posiciones (se acepta el + o el - en la primer posicion unicamente)
///
/// @param char* cadena de caracteres que serà analizada
/// @return int Retorna [0] en caso de que no sean todos sus caracteres numeros - Retorna [1] en caso de que la cadena sea numerica
int esNumerica(char* cadena, int limite);

/// @brief Verifica que la cadena ingresada sea un numero flotante
///
/// @param char* cadena de caracteres que serà analizada
/// @param limite
/// @return int Retorna [0] en caso de que no sea un numero flotante - Retorna [1] en caso de que si sea un numero flotante
int esFlotante(char* cadena, int limite);

/// @brief Verificar que el caracter recibido sea una letra de la A a la z
///
/// @param caracter Caracter a analizar
/// @return retorna 0 en caso de que el caracter sea invalido (algun caracter especial o numero)
/// 		retorna 1 en caso de que el caracter sea una letra
int esCaracter(char caracter);

#endif /* UTN_H_ */
