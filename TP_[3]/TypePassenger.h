/*
 * TypePassenger.h
 *
 *  Created on: 8 jun. 2022
 *      Author: juan
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

typedef struct
{
	int id;
	char descripcion[20];
} TypePassenger;

/// @brief Inicializa la lista de tipos de pasajero
///
/// @param arrayTypePassenger TypePassenger* lista de pasajeros que se cargara
/// @param lenTypePassenger int Longitud de la lista de pasajeros
/// @return int [-1] en caso de que arrayTypePassenger sea NULL o lenTypePassenger sea menor a 0
/// 		int [0] en caso de lograr cargar la lista correctamente
int TypePassenger_init(TypePassenger* arrayTypePassenger, int lenTypePassenger);

/// @brief Imprime los datos del tipoPasajero que recibe
///
/// @param tipoPasajero TypePassenger del cual se imprimiran los datos
void TypePassenger_printOne(TypePassenger tipoPasajero);

/// @brief Imprime la lista de tipos de pasajeros
///
/// @param arrayTypePassenger TypePassenger* lista de tipos de pasajeros
/// @param lenTypePassenger int Longitud de la lista de pasajeros
/// @return int [-1]  en caso de que arrayTypePassenger sea NULL o lenTypePassenger sea menor a 0
/// 		int [0] en caso de imprimir correctamente todos los datos
int TypePassenger_printLista(TypePassenger* arrayTypePassenger, int lenTypePassenger);

/// @brief Recibe una cadena y determinara el indice (int) del tipo de pasajero correspondiente
///
/// @param typePassenger char* cadena que sera analizada
/// @return [1] en caso de que la cadena recibida corresponda a el typePassenger EconomyClass
/// 		[2] en caso de que la cadena recibida corresponda a el typePassenger FirstClass
/// 		[3] en caso de que la cadena recibida corresponda a el typePassenger ExecutiveClass
int TypePassenger_ReturnTypePassenger(char* typePassenger);

/// @brief Recibe una cadena donde se guardara un valor y un entero que determina el tipo de pasajero
///
/// @param typePassengerStr char* Espacio donde se guardara el tipo de pasajero en string
/// @param typePassenger int Tipo de pasajero recibido el cual sera analizado
/// @return int [-1] en caso de que typePassengerStr sea NULL o typePassenger sea menor a 0
/// 		int [1] en caso de que se haya podido analizar y asignar a typePassengerStr la cadena correspondiente
int TypePassenger_ReemplazarIntPorString(char* typePassengerStr, int typePassenger);
#endif /* TYPEPASSENGER_H_ */
