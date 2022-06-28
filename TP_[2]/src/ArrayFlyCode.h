/*
 * ArrayFlyCode.h
 *
 *  Created on: 25 jun. 2022
 *      Author: juan
 */

#ifndef ARRAYFLYCODE_H_
#define ARRAYFLYCODE_H_

typedef struct
{
	int idFlyCode;
	char codigoVueloStr[20];
	char estadoVueloStr[20];
	int isEmpty;

} FlyCode;

/// @brief Inicializa la lista de codigos de vuelo en TRUE para que se puedan cargar datos en todas sus posiciones al iniciar el programa
///
/// @param eFlyCode Lista de codigos de vuelos, los cuales se inicializaran con su estado en TRUE
/// @param int Longitud de la lista de codigos de vuelo
/// @return int Retorna [-1] en caso de error (que la longitud sea 0 o que se apunte a NULL)
/// 			Retorna [0] en caso de que se hayan inicializado todas las posiciones del array en TRUE
int FlyCode_init(FlyCode* list, int len);

/// @brief Esta funcion permite cargar de manera forzada una determinada cantidad de codigos de vuelos junto con su estado
///
/// @param flyCode Array de flyCodes donde se guardaran los codigos de vuelo y estados de los mismos
/// @param int Longitud del array de flyCodes
/// @return Retorna [-1] en caso de que el array apunte a NULL o la longitud sea 0.
/// 		Retorna [0] en caso de que se haya hardcodeado correctamente el array
int FlyCode_CargaForzada(FlyCode* list, int len);

/// @brief Permite mostrarle al usuario un codigo de vuelo junto con su estado
///
/// @param eFlyCode Recibe el codigo de vuelo que se quiere mostrar al usuario
void FlyCode_printOne(FlyCode codigoVuelo);

/// @brief Permite mostrar toda la lista de codigos de vuelo junto a sus respectivos estados de vuelo
///
/// @param eFlyCode Lista de codigos de vuelo, los cuales se imprimiran en pantalla
/// @param int Longitud de la lista de codigos de vuelo
/// @return Retorna [-1] en caso de que el array apunte a NULL o la longitud sea 0.
/// 		Retorna [0] en caso de que se haya logrado imprimir en pantalla toda la lista de codigos de vue
int FlyCode_printFlyCodes(FlyCode* list, int len);

/// @brief Permite ingresar un nuevo codigo de vuelo al sistema (se validara si el mismo ya existe en el sistema y si lo ingresado
/// 		es valido para ser un codigo de vuelo)
///
/// @param eFlyCode Lista de codigos de vuelo donde se almacenara el nuevo codigo de vuelo
/// @param int Longitud de la lista de codigos de vuelo
/// @param int id del ultimo codigo de vuelo
/// @return Retorna [-1] en caso de error (que el array apunte a NULL, que la longitud sea menor a 0 o que el codigo de vuelo ya exista)
/// 		Retorna [0] en caso de que se haya ingresado el nuevo codigo de vuelo al sistema
int addFlyCode(FlyCode* list, int len, int* lastId);

/// @brief A partir del int recibido determina el correspondiente estado de vuelo pero en string
///
/// @param idEstadoVuelo int Id que determinara el estado de vuelo
/// @param estadoVueloStr char* Puntero a la direccion de memoria donde se guardara el estado de vuelo en string
/// @return retorna [-1] en caso de error
/// 		retorna [0] en caso de obtener el estado de vuelo correspondiente
int getStatusFlightStr(int idEstadoVuelo, char* estadoVueloStr);

/// @brief Le solicita al usuario ingresar un nuevo codigo de vuelo
///
/// @param newFlyCode Puntero a la direccion donde se guardara el nuevo codigo de vuelo si es valido
/// @param mensaje Mensaje que solicita al usuario ingresar el nuevo codigo de vuelo
/// @param mensajeError Mensaje de error en caso de que el codigo de vuelo no sea valido
/// @return retorna [-1] en caso de que el nuevo codigo de vuelo no sea valido
/// 		retorna [1] en caso de que se haya logrado obtener el nuevo codigo
int getNewFlyCode(char* newFlyCode, char mensaje[], char mensajeError[]);

/// @brief Verifica que el codigo de vuelo recibido por parametro sea valido (valido = alfanumerico)
///	Sera validado de la A hasta la z, teniendo en cuenta que tambien puede ingresar numeros del 0 al 9. Pero NO caracteres especiales.
/// @param char Codigo de vuelo que serà analizado
/// @param char Indica el comienzo de la lista de caracteres que pueden ser validos para el codigo alfanumerico
/// @param char Indica el final de la lista de caracteres que pueden ser validos para el codigo alfanumerco
/// @return Retorna [-1] en caso de que el codigo de vuelo no sea valido (cantidad de caracteres diferentes a 9 o que alguno/s de los
/// 		caracteres ingresados no sean validos - Retorna [0] en caso de que el codigo de vuelo sea valido
int VerificarFlyCode(char newFlyCode[], char minimo, char maximo);

/// @brief Permite encontrar la primer posicion libre (isEmpty = TRUE) del array que recibe como parametro
///
/// @param eFlyCode Recibe la lista de codigos de vuelo del la cual se buscara la primer posicion libre
/// @param int Longitud de la lista de codigos de vuelo
/// @return int Retorna [-1] en caso de que el array apunte a NULL o la longitud sea 0 o que no se haya encontrado
/// 			ninguna posicion libre el la lista de codigos - Retorna [i] que seria la primer posicion libre que se encuentra en la lista
int FlyCode_findIsEmpty(FlyCode* list, int len);


#endif /* ARRAYFLYCODE_H_ */
