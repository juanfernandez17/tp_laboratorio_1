/*
 * FlyCode.h
 *
 *  Created on: 8 jun. 2022
 *      Author: juan
 */

#ifndef FLYCODE_H_
#define FLYCODE_H_

typedef struct
{
	char descripconFlyCode[50];
	char statusFly[50];
} FlyCode;

/// @brief Inicializa la lista de codigos de vuelo
///
/// @param arrayFlyCodes FlyCode* lista donde se guardaron los codigos de vuelo
/// @param lenFlyCodes int Cantidad de codigos de vuelo
/// @return int [-1] en caso de que arrayFlyCodes sea NULL o lenFlyCodes sea menor a 0
/// 		int [1] en caso de cargar la lista de forma correcta
int FlyCode_init(FlyCode* arrayFlyCodes, int lenFlyCodes);

///  @brief Imprime los datos del flyCode recibido como parametro
///
/// @param flyCode FlyCode codigo de vuelo del cual se quiere impmir los datos
void FlyCode_PrintOne(FlyCode flyCode);

/// @brief Imprime todos los codigos de vuelo
///
/// @param arrayFlyCode FlyCode[] lista con todos los codigos de vuelo
/// @param lenFlyCodes int Cantidad de codigos de vuelo
///
/// @return int [-1] en caso de que arrayFlyCodes sea NULL o lenFlyCodes sea menor a 0
/// 		int [1] en caso de imprimir correctamente toda la lista de codigos de vuelo
int FlyCode_PrintLista(FlyCode arrayFlyCode[], int lenFlyCodes);

/// @brief Analiza el int que recibe y asigna a char* flyCodeStr el codigo de vuelo correspondiente
///
/// @param flyCodeStr char* Espacio donde se guardara el codigo de vuelo correspondiente a su indice
/// @param flyCode int Indice ingresado por el usuario
/// @return int [-1] en caso de que flyCodeStr sea NULL o flyCode sea menor a 0
/// 		int [1] en caso de lograr asignar a flyCodeStr el codigo de vuelo correspondiente
int FlyCode_ReemplazarIntPorString(char* flyCodeStr, int flyCode);
#endif /* FLYCODE_H_ */
