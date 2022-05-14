/*
 	Input.h

	Fernandez Juan Ignacio 1ºB
	Trabajo practico Nº2
 */

#ifndef INPUT_H_
#define INPUT_H_

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
int utn_getString(char *pResultado, char mensaje[], char mensajeError[], int TAM, char minimo, char maximo);

/// @brief Recibe una cadena como parametro y se evaluara si es valida o no (para que sea valida solamente puede contener letras)
///			El rango valido sera de la 'A' a la 'z' excluyendo los caracteres especiales que se encuentran en ese rango segun el codigo ASCII
/// @param char Cadena que sera analizada
/// @param int Longitud de la cadena recibida
/// @param char Indica que los caracteres seran validos a partir de este minimo ("A")
/// @param char Indica que los caracteres seran validos hasta este maximo ("z")
/// @return Retorna [-1] en caso de que la cadena no sea valida - Retorna [0] en caso de que la cadena sea valida
int utn_VerificarString(char cadena[], int lenCadena, char minimo, char maximo);

/// @brief Recibe una cadena por parametro la cual sera modificada (se pondra la primer letra de cada palabra en mayuscula y las proximas en minuscula)
///
/// @param char Cadena que sea modificada
/// @param int Longitud de la cadena
void utn_DarFormatoCadena(char cadena[], int lenCadena);

/// @brief Le solicita al usuario que confirme una determinada accion (ej: antes de eliminar o modificar un pasajero le pregunta si quiere realmente hacerlo o no)
/// 	ya que podria haberse equivocado al momento de seleccionar la opcion o confundirse de pasajero
///
/// @param char Mensaje que le pide al usuario la confirmacion de la accion
/// @param char Mensaje de error en caso de que la opcion ingresada por el usuario no sea valida (opciones validas: si/no)
/// @return Retorna [-1] en caso de que se haya ingresado "no" por lo tanto no se realizaria la accion
/// 		Retorna [1] en caso de que se haya ingresado "si" por lo tanto se confirmaria la accion
int utn_ConfirmarAccion(char mensaje[], char mensajeError[]);

/// @brief Recibe una cadena como parametro la cual se pasaran todos sus caracteres a minuscula o mayuscula segun se le indica a la funcion
///
/// @param char Cadena que sera formateada a mayuscula o minuscula
/// @param int Longitud de la cadena
/// @param int Opcion que determina si se formateara la cadena a mayuscula o minuscula
void utn_FormatearString(char cadena[], int lenCadena, int opcion);

#endif /* INPUT_H_ */
