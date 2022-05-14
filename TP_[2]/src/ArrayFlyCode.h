/*
	ArrayFlyCode.h

	Fernàndez Juan Ignacio 1ºB
	Trabajo pràctico Nº2
*/

#ifndef ARRAYFLYCODE_H_
#define ARRAYFLYCODE_H_

typedef struct
{
	char flyCode[10];
	int statusFlight;
	int isEmpty;

} eFlyCode;

/// @brief Inicializa la lista de codigos de vuelo en TRUE para que se puedan cargar datos en todas sus posiciones al iniciar el programa
///
/// @param eFlyCode Lista de codigos de vuelos, los cuales se inicializaran con su estado en TRUE
/// @param int Longitud de la lista de codigos de vuelo
/// @return int Retorna [-1] en caso de error (que la longitud sea 0 o que se apunte a NULL)
/// 			Retorna [0] en caso de que se hayan inicializado todas las posiciones del array en TRUE
int initFlyCode(eFlyCode arrayFlyCodes[], int lenFlyCodes);


/// @brief Esta funcion permite cargar de manera forzada una determinada cantidad de codigos de vuelos junto con su estado
///
/// @param int Array de flyCodes donde se guardaran los codigos de vuelo y estados de los mismos
/// @param int Longitud del array de flyCodes
/// @return Retorna [-1] en caso de que el array apunte a NULL o la longitud sea 0.
/// 		Retorna [0] en caso de que se haya hardcodeado correctamente el array
int AltaForzadaCodigos(eFlyCode arrayFlyCodes[], int lenFlyCodes);

/// @brief Determina si un codigo de vuelo se encuentra o no en el array de flyCodes
///
/// @param eFlyCode Array de los codigos de vuelo
/// @param int Longitud del array de los codigo de vuelo
/// @param char Recibe el codigo de vuelo del cual se buscara si se encuentra o no en el array de flyCode
/// @return int Retorna [-1] en caso de que no se haya encontrado el codigo de vuelo en el array de flyCode
/// 			Retorna [0] en caso de que si se haya encontrado el codigo de vuelo
int findFlyCode(eFlyCode arrayFlyCodes[], int lenFlyCodes, char flyCode[]);


/// @brief Permite mostrarle al usuario un codigo de vuelo junto con su estado
///
/// @param eFlyCode Recibe el codigo de vuelo que se quiere mostrar al usuario
void printOneFlyCode(eFlyCode flyCode);

/// @brief Permite mostrar toda la lista de codigos de vuelo junto a sus respectivos estados de vuelo
///
/// @param eFlyCode Lista de codigos de vuelo, los cuales se imprimiran en pantalla
/// @param int Longitud de la lista de codigos de vuelo
/// @return Retorna [-1] en caso de que el array apunte a NULL o la longitud sea 0.
/// 		Retorna [0] en caso de que se haya logrado imprimir en pantalla toda la lista de codigos de vuelo
int printFlyCode(eFlyCode arrayFlyCodes[], int lenFlyCodes);


/// @brief Permite encontrar la primer posicion libre (isEmpty = TRUE) del array que recibe como parametro
///
/// @param ePassenger Recibe el array de pasajeros del cual se buscara la primer posicion libre
/// @param int Recibe la longitud del array que contiene a los pasajeros
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) o que no se haya encontrado
/// 		ninguna posicion libre en el array - Retorna [i] que seria la primer posicion que encuentra en el array

/// @brief Permite encontrar la primer posicion libre (isEmpty = TRUE) del array que recibe como parametro
///
/// @param eFlyCode Recibe la lista de codigos de vuelo del la cual se buscara la primer posicion libre
/// @param int Longitud de la lista de codigos de vuelo
/// @return int Retorna [-1] en caso de que el array apunte a NULL o la longitud sea 0 o que no se haya encontrado
/// 			ninguna posicion libre el la lista de codigos - Retorna [i] que seria la primer posicion libre que se encuentra en la lista
int findIsEmptyFlyCode(eFlyCode arrayFlyCodes[], int lenFlyCodes);

/// @brief Le pide al usuario que ingrese un codigo de vuelo el cual sera analizado para saber si es valido o no
///
/// @param char Puntero donde se almacenara el codigo de vuelo ingresado por el usuario en caso de ser valido
/// @param char Mensaje que le indica al usuario que debe ingresar un codigo de vuelo
/// @param char Mensaje de error que indica al usuario que el codigo de vuelo ingresado no es valido
void PedirFlyCode(char newFlyCode[], char mensaje[], char mensajeError[]);

/// @brief Verifica que el codigo de vuelo recibido por parametro sea valido (valido = alfanumerico)
///	Sera validado de la A hasta la z, teniendo en cuenta que tambien puede ingresar numeros del 0 al 9. Pero NO caracteres especiales.
/// @param char Codigo de vuelo que serà analizado
/// @param char Indica el comienzo de la lista de caracteres que pueden ser validos para el codigo alfanumerico
/// @param char Indica el final de la lista de caracteres que pueden ser validos para el codigo alfanumerco
/// @return Retorna [-1] en caso de que el codigo de vuelo no sea valido (cantidad de caracteres diferentes a 9 o que alguno/s de los
/// 		caracteres ingresados no sean validos - Retorna [0] en caso de que el codigo de vuelo sea valido
int VerificarFlyCode(char newFlyCode[], char minimo, char maximo);

/// @brief Permite ingresar un nuevo codigo de vuelo al sistema (se validara si el mismo ya existe en el sistema y si lo ingresado
/// 		es valido para ser un codigo de vuelo)
///
/// @param eFlyCode Lista de codigos de vuelo donde se almacenara el nuevo codigo de vuelo
/// @param int Longitud de la lista de codigos de vuelo
/// @return Retorna [-1] en caso de error (que el array apunte a NULL, que la longitud sea menor a 0 o que el codigo de vuelo ya exista)
/// 		Retorna [0] en caso de que se haya ingresado el nuevo codigo de vuelo al sistema
int AltaFlyCode(eFlyCode arrayFlyCodes[], int lenFlyCodes);

#endif /* ARRAYFLYCODE_H_ */
