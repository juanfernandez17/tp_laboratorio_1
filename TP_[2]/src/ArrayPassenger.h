/*
 * ArrayPassenger.h
 *
 *  Created on: 25 jun. 2022
 *      Author: juan
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "ArrayFlyCode.h"

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	int idFlyCode;
	int typePassenger;
	int isEmpty;
} Passenger;


/// @brief Esta funcion se utiliza al comenzar el programa para poner todas las posiciones del array en libre (isEmpty = TRUE)
///
/// @param ePassenger Recibe como parametro la lista donde se agrupan a los pasajeros
/// @param int Recibe la longitud del array que contiene a los pasajeros
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) -
/// 					[0] en caso de que se haya logrado inicializar todas las posiciones en libre
int initPassengers(Passenger* list, int len);

/// @brief Es una funcion que agrega un pasajero en el array de pasajeros con los datos que recibe como parametro
///
/// @param ePassenger Recibe el array donde se almacenara el nuevo pasajero que se agrega
/// @param int Recibe la longitud del array donde se encuentran los pasajeros
/// @param int ID que se le asigna al pasajero de manera automatica
/// @param char[] Nombre del pasajero
/// @param char[] Apellido del pasajero
/// @param float Precio del vuelo
/// @param int Tipo de pasajero (TURISTA, PRIMERA_CLASE, EJECUTIVO, PREMIUM)
/// @param char[] Codigo de vuelo alfanumerico
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) o en caso de que no haya espacio libre
/// 		en el array para agregar un nuevo pasajero. Retorna [0] en caso de que se haya logrado agregar el pasajero
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, int flyCode);

/// @brief Permite encontrar a un pasajero a traves de su ID (el cual es asignado automaticamente con la funcion privada "ePassenger_ObtenerID"
///
/// @param ePassenger Recibe el array del cual realizara la busqueda para encontrar el usuario con el ID que se ingreso por parametro
/// @param int Longitud del array que contiene a los pasajeros
/// @param int ID del pasajero que el usuario desea encontrar
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) o en caso de que no se haya encontrado un pasajero con
///			el ID pasado por parametro - Retorna [i] que seria el indice o posicion del usuario que tiene el ID que se ingreso por parametro
int findPassengerById(Passenger* list, int len, int id);
/// @brief Le permite al usuario dar de baja a un pasajero (pone "isEmpty" en TRUE). Para esto le pide que ingrese el ID del usuario que quiere eliminar
/// 		luego se confirma que existe ese usuario y le pide confirmacion al usuario para eliminar al pasajero del sistema.
///
/// @param ePassenger Recibe el array de pasajeros donde se eliminara el que coincida con el ID que ingresa el usuario
/// @param int Longitud del array que contiene a los pasajeros
/// @param int ID del pasajero que se busca eliminar
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) o en caso de que no se haya encontrado a un pasajero con
/// 		el ID ingresado -Retorna [0] en caso de exito
int removePassenger(Passenger* list, int len, int id);

/// @brief Permite ordenar un array de manera ascendente o descendete segun lo que reciba por parametro
///
/// @param ePassenger Recibe el array que se ordenara
/// @param int Longitud del array
/// @param int Order indica si el array se ordenara de manera ascendente o descendente
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL)
/// 			Retorna [0] en caso de que que se haya logrado ordenar el array
int sortPassengers(Passenger* list, int len, int order);

/// @brief Imprime los datos de los pasajeros que se encuentran en el array que recibe como parametro
///
/// @param  ePassenger Array del cual se van a imprimir los datos
/// @param int Longitud del array que recibe como parametro
/// @param eFlyCode array de los codigos de vuelo
/// @return  Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL)
///			Retorna [0] en caso de que se hayan mostrado correctamente los datos del array
int printPassengers(Passenger* list, int len, FlyCode* listFlyCode);

/// @brief Permite mostrar en pantalla los datos del pasajero que recibe por parametro
///
/// @param ePassenger Recibe al pasajero del cual quiere mostrar la informacion
/// @param eFlyCode Codigo del cual se imprimira el estado de vuelo
void printOnePassenger(Passenger unPasajero, FlyCode* list);

/// @brief Ordena la lista de pasajeros segun el codigo de vuelo y luego por el estado de manera ascendente o descendente
///
/// @param ePassenger Lista de pasajeros la cual se ordenara segun el criterio recibido (ascendente o descendente)
/// @param int Longitud de la lista de pasajeros
/// @param int Order puede tomar dos valores: ASCENDENTE O DESCENDENTE lo cual determinara el ordenamiento de la lista de pasajeros
/// @param eFlyCodes Lista de codigos de vuelo
/// @param int Longitud de la lista de codigos de vuelo
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL)
/// 			Retorna [0] en caso de que se haya ordenado el array
int sortPassengersByCode(Passenger* list, int len, int order, FlyCode* listFlyCode);

/// @brief Le permite al usuario realizar modificaciones en en nombre, apellido, precio, tipo de pasajero o codigo de vuelo
///
/// @param ePassenger recibe el array donde se encuentran los pasajeros cargados
/// @param int Longitud del array que contiene a los pasajeros
/// @param eFlyCode recibe el array donde se encuentran los diferentes codigos de vuelos, los cuales pueden modificarse
/// @param int Longitud del array que contiene a los codigos de vuelo
/// @param int ID del pasajero del cual se quiere realizar una modificacion
/// @return int Retorna [-1] en caso de que el ID recibido por parametro no se haya encontrado en el array de pasajeros
/// 			Retorna [0] en caso de que haya exito
int Passenger_modify(Passenger* list, int len, FlyCode* listFlyCode, int lenFlyCode);
/// @brief Permite encontrar la primer posicion libre (isEmpty = TRUE) del array que recibe como parametro
///
/// @param ePassenger Recibe el array de pasajeros del cual se buscara la primer posicion libre
/// @param int Recibe la longitud del array que contiene a los pasajeros
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) o que no se haya encontrado
/// 		ninguna posicion libre en el array - Retorna [i] que seria la primer posicion que encuentra en el array
int findIsEmpty(Passenger* list, int len);

/// @brief Permite conocer cual de los nombres de los pasajeros que recibe es mayor
///
/// @param passengerUno pasajero uno del cual se obtendra el nombre para ser comparado
/// @param passengerDos pasajero dos del cual se obtendra el nombre para ser comparado
/// @return retorna [-1] si el nombre del segundo pasajero es mayor
/// 		retorna [0] si los nombres son iguales
/// 		retorna [1] si el nombre del primero es mayor
int Passenger_CompareByLastName(Passenger passengerUno, Passenger passengerDos);

/// @brief Permite conocer cual de los tipos de pasajeros que recibe es mayor
///
/// @param passengerUno pasajero uno del cual se obtendra el tipo de pasajero para ser comparado
/// @param passengerDos pasajero dos del cual se obtendra el tipo de pasajero para ser comparado
/// @return retorna [-1] si el tipo de pasajero  del segundo pasajero es mayor
/// 		retorna [0] si los tipo de pasajero son iguales
/// 		retorna [1] si el tipo de pasajero del primero es mayor
int Passenger_CompareByTypePassenger(Passenger pasajeroUno, Passenger pasajeroDos);

/// @brief Permite obtener el tipo de pasajero segun su el int recibido
///
/// @param typePassenger int Que determina el tipo de pasajero
/// @param typePassengerStr char tipo de pasajero pasado a string
/// @return retorna [-1] en caso de error
/// 		retorna [0] en caso de exito
int Passenger_getTyePassenger(int typePassenger, char* typePassengerStr);

/// @brief Permite obtener el codigo de vuelo y estado de vuelo a partir del id recibido
///
/// @param idFlyCode int Id que determina el codigo de vuelo junto a su estado de vuelo
/// @param list lista de codigos de vuelo
/// @param codigoVueloStr Puntero al espacio de memoria donde se guardara el codigo de vuelo correspondiente en caracteres
/// @param estadoVueloStr Puntero al espacio de memoria donde se guardara el estado de vuelo correspondiente en caracteres
/// @return etorna [-1] en caso de error
/// 		retorna [0] en caso de exito
int Passenger_getStatusAndFlightCode(int idFlyCode, FlyCode* list,char* codigoVueloStr, char* estadoVueloStr);

/// @brief Permite conocer cual es el codigo mayor recibido, cual es el menor y si son iguales
///
/// @param passengerUno pasajero uno del cual se obtendra el codigo de vuelo para ser comparado
/// @param passengerDos pasajero uno dos cual se obtendra el codigo de vuelo para ser comparado
/// @param list lista de codigos de vuelo
/// @return retorna [-1] en caso de que el segundo codigo de vuelo sea mayor
/// 		retorna [0] en caso de que los codigos de vuelo sean iguales
/// 		retorna [1] en caso de que el primer codigo sea mayor
int Passenger_CompareByCode(Passenger passengerUno, Passenger passengerDos, FlyCode* list);

/// @brief Despliega el menu de las opciones que se pueden modificar del pasajero
///
/// @param Recibe el pasajero del cual se va a realizar una modificacion
/// @param eFlyCode recibe el array donde se encuentran los diferentes codigos de vuelos, los cuales pueden modificarse
/// @param int Longitud del array que contiene a los codigos de vuelo
/// @return int Retorna [-1] en caso de que el ID recibido por parametro no se haya encontrado en el array de pasajeros
/// 			Retorna [0] en caso de que haya encontrado al usuario y se hayan realizado modificaciones en el mismo
int Passenger_MenuModificar(Passenger* list, FlyCode* listFlyCode, int lenFlyCode, int indice);

/// @brief Su funcion es pedirle al usuario que ingrese datos correspondientes a los campos de un ePassenger (excluyen el ID e isEmpty)
/// 		Estos datos son los que se pasaran como parametro a la funcion "addPassenger" (PedirDatos "llama" a addPassenger para pasarle los datos como parametro)
///
/// @param ePassenger Recibe el array donde estan los pasajeros
/// @param int Longitud del array de pasajeros
/// @param eFlyCode Recibe el array donde se encuentran los Codigos de vuelos con sus respectivos estados (ej: AB001, ACTIVO)
/// 		El codigo de vuelo que ingrese el usuario es verificado con otra funcion para saber si existe o no.
/// @param int Longitud de los codigos de vuelo existentes
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) o en caso de que no haya espacio libre
/// 		en el array para agregar un nuevo pasajero. Retorna [0] en caso de que se haya logrado agregar el pasajero
int Passenger_PedirDatos(Passenger* list, int len, FlyCode* listFlyCode, int lenFlyCode, int* lastId);

/// @brief Pide al usuario ingresar un codigo de vuelo para luego darlo de baja a traves de otra funcion
///
/// @param list Lista de pasajeros
/// @param len Longitud de la lista de pasajeros
/// @param listFlyCode Lista de codigos de vuelo
/// @param lenFlyCode Longitud de codigos de vuelo
/// @return retorna [-1] en caso de error (punteros a NULL o longitud de listas < 1)
/// 		retorna [0] en caso de exito y haber logrado dar de baja al pasajero
int Passenger_delete(Passenger* list, int len, FlyCode* listFlyCode, int lenFlyCode);

/// @brief Imprime la lista de pasajeros ordenara por codigo de vuelo y por estado de vuelo
///
/// @param ePassenger Lista de pasajeros que se imprimira
/// @param int Longitud de la lista de pasajeros
/// @param int order Determina si se ordenan de manera ascendente o descendente
/// @param eFlyCode Lista de codigos de vuelo (solo se imprimiran aquellos que esten ACTIVOS)
/// @param char* statusFlight estado de vuelo que indica cuales se imprimiran
int printPassengersFlyCode(Passenger* list, int len, int order, FlyCode* listFlyCode,char statusFlight[]);

/// @brief Despliega las opciones para los diferentes informes
///
/// @param optionSubMenu int Opcion ingresada por el usuario
/// @param list lista de pasajeros
/// @param len longitud de la lista de pasajeros
/// @param listFlyCode lista de codigos de vuelo
/// @return retorna [-1] en caso de error (listas apuntando a NULL o longitud < 1)
/// 		retorna [0] en caso de exito
int Passenger_subMenu(int optionSubMenu, Passenger* list, int len, FlyCode* listFlyCode);

/// @brief Permite sumar los precios de todos los pasajes ingresados y calcular el promedio de los mismos
///
/// @param ePassenger Lista de pasajeros de los cuales se calculara el total y promedio del precio de sus pasajes
/// @param int Longitud de la lista de pasajeros
/// @param float* total Puntero a la direccion de memoria donde se guardara el precio total
/// @param float* promedio Puntero a la direccion de memoria donde se guardara el promedio
/// @return retorna [-1] en caso de error (si alguno de los punteros que recibe apunta a NULL)
/// 		retorna [0] en caso de exito
int Passenger_getPromedioVuelos(Passenger* list, int len, float* total, float* promedio);

/// @brief Permite saber cuàntos pasajeros superan el precio promedio de pasajes
///
/// @param ePassenger Lista de pasajeros de los cuales se comprobara si superan o no el precio promedio de pasajes
/// @param int Longitud de la lista de pasajeros
/// @param float* El precio promedio de los pasajes
/// @param  eFlyCode Recibe el array donde se encuentran los Codigos de vuelos con sus respectivos estados
/// @return retorna [-1] en caso de error (si alguno de los punteros que recibe apunta a NULL)
/// 		retorna [0] en caso de exito
int Passenger_getSuperiorPromedio(Passenger* list, int len, float* promedio, FlyCode* listFlyCode);

/// @brief Esta funcion se puede o no ejecutar al comienzo del programa. Carga en el array que recibe 5 pasajeros con sus respectivos campos
///
/// @param ePassenger Recibe como parametro la lista donde se agrupan a los pasajeros
/// @param int Recibe la longitud del array que contiene a los pasajeros
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) -
/// 					[0] en caso de que se haya logrado cargar a los pasajeros en el array
int Passenger_CargaForzada(Passenger* list, int len);

/// @brief Permite formatear todos los caracteres de una cadena recibida a mayuscula o minuscula
///
/// @param cadena char* cadena que sera formateada
/// @param lenCadena int Longitud de la cadena
/// @param opcion int Opcion que determina si se pasara la cadena a minuscula [0] o mayuscula [1]
void Passenger_FormatearString(char cadena[], int lenCadena, int opcion);

/// @brief Da un formato correspondiente a la cadena que recibe como parametro para que tenga la primer letra en mayuscula y las demas en minuscula
///
/// @param cadena char* cadena que sera formateada
/// @param lenCadena int Longitud de la cadena
void Passenger_DarFormatoNombre(char cadena[], int lenCadena);

/// @brief Verifica que el formato de la cadena ingresada corresponda a un nombre o apellido
///
/// @param cadena Cadena que se analizara
/// @param len Longitud de la cadena
/// @return Retorna [0] en caso de no ser valida
/// 		Retorna [1] en caso de ser valida
int Passenger_ValidarNombre(char* cadena, int len);

#endif /* ARRAYPASSENGER_H_ */
