/*
	ArrayPassenger.h

	Fernàndez Juan Ignacio 1ºB
	Trabajo pràctico Nº2
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
	char flycode[10];
	int typePassenger;
	int isEmpty;

} ePassenger;

/// @brief Esta funcion se utiliza al comenzar el programa para poner todas las posiciones del array en libre (isEmpty = TRUE)
///
/// @param ePassenger Recibe como parametro la lista donde se agrupan a los pasajeros
/// @param int Recibe la longitud del array que contiene a los pasajeros
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) -
/// 					[0] en caso de que se haya logrado inicializar todas las posiciones en libre
int initPassengers(ePassenger arrayPassengers[], int lenPassengers);

/// @brief Esta funcion se puede o no ejecutar al comienzo del programa. Carga en el array que recibe 5 pasajeros con sus respectivos campos
///
/// @param ePassenger Recibe como parametro la lista donde se agrupan a los pasajeros
/// @param int Recibe la longitud del array que contiene a los pasajeros
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) -
/// 					[0] en caso de que se haya logrado cargar a los pasajeros en el array
int AltaForzadaPasajeros(ePassenger arrayPassengers[], int lenPassengers);

/// @brief Permite encontrar la primer posicion libre (isEmpty = TRUE) del array que recibe como parametro
///
/// @param ePassenger Recibe el array de pasajeros del cual se buscara la primer posicion libre
/// @param int Recibe la longitud del array que contiene a los pasajeros
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) o que no se haya encontrado
/// 		ninguna posicion libre en el array - Retorna [i] que seria la primer posicion que encuentra en el array
int findIsEmpty(ePassenger arrayPassengers[], int lenPassengers);

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
int addPassenger(ePassenger arrayPassengers[], int lenPassengers, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[]);

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
int PedirDatos(ePassenger arrayPassengers[], int lenPassengers, eFlyCode arrayFlyCodes[], int lenFlyCodes);

/// @brief Permite encontrar a un pasajero a traves de su ID (el cual es asignado automaticamente con la funcion privada "ePassenger_ObtenerID"
///
/// @param ePassenger Recibe el array del cual realizara la busqueda para encontrar el usuario con el ID que se ingreso por parametro
/// @param int Longitud del array que contiene a los pasajeros
/// @param int ID del pasajero que el usuario desea encontrar
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) o en caso de que no se haya encontrado un pasajero con
///			el ID pasado por parametro - Retorna [i] que seria el indice o posicion del usuario que tiene el ID que se ingreso por parametro
int findPassengerById(ePassenger arrayPassengers[], int lenPassengers, int id);

/// @brief Le permite al usuario dar de baja a un pasajero (pone "isEmpty" en TRUE). Para esto le pide que ingrese el ID del usuario que quiere eliminar
/// 		luego se confirma que existe ese usuario y le pide confirmacion al usuario para eliminar al pasajero del sistema.
///
/// @param ePassenger Recibe el array de pasajeros donde se eliminara el que coincida con el ID que ingresa el usuario
/// @param int Longitud del array que contiene a los pasajeros
/// @param int ID del pasajero que se busca eliminar
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL) o en caso de que no se haya encontrado a un pasajero con
/// 		el ID ingresado - Retorna [1] en caso de que se haya encontrado al pasajero con el ID ingresado pero no se haya confirmado su eliminacion
/// 		Retorna [0] en caso de que se haya encontrado al pasajero con el ID ingresado y se haya confirmado su eliminacion
int removePassengerById(ePassenger arrayPassengers[], int lenPassengers, int id);

/// @brief Le permite al usuario realizar modificaciones en en nombre, apellido, precio, tipo de pasajero o codigo de vuelo
///
/// @param ePassenger recibe el array donde se encuentran los pasajeros cargados
/// @param int Longitud del array que contiene a los pasajeros
/// @param eFlyCode recibe el array donde se encuentran los diferentes codigos de vuelos, los cuales pueden modificarse
/// @param int Longitud del array que contiene a los codigos de vuelo
/// @param int ID del pasajero del cual se quiere realizar una modificacion
/// @return int Retorna [-1] en caso de que el ID recibido por parametro no se haya encontrado en el array de pasajeros
/// 			Retorna [1] en caso de que haya encontrado el ID del pasajero, pero no se hayan realizado modificaciones en el mismo
/// 			Retorna [0] en caso de que haya encontrado al usuario y se hayan realizado modificaciones en el mismo
int modifyPassenger(ePassenger arrayPassengers[], int lenPassengers, eFlyCode arrayFlyCodes[], int lenFlyCodes,int id);

/// @brief Despliega el menu de las opciones que se pueden modificar del pasajero
///
/// @param Recibe el pasajero del cual se va a realizar una modificacion
/// @param eFlyCode recibe el array donde se encuentran los diferentes codigos de vuelos, los cuales pueden modificarse
/// @param int Longitud del array que contiene a los codigos de vuelo
/// @return int Retorna [-1] en caso de que el ID recibido por parametro no se haya encontrado en el array de pasajeros
/// 			Retorna [1] en caso de que haya encontrado el ID del pasajero, pero no se hayan realizado modificaciones en el mismo
/// 			Retorna [0] en caso de que haya encontrado al usuario y se hayan realizado modificaciones en el mismo
int modifyMenu(ePassenger passenger, eFlyCode arrayFlyCodes[], int lenFlyCodes);

/// @brief Permite ordenar un array de manera ascendente o descendete segun lo que reciba por parametro
///
/// @param ePassenger Recibe el array que se ordenara
/// @param int Longitud del array
/// @param int Order indica si el array se ordenara de manera ascendente o descendente
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL)
/// 			Retorna [0] en caso de que que se haya logrado ordenar el array
int sortPassengers(ePassenger arrayPassengers[], int lenPassengers, int order);

/// @brief Permite mostrar en pantalla los datos del pasajero que recibe por parametro
///
/// @param ePassenger Recibe al pasajero del cual quiere mostrar la informacion
void PrintOnePassenger(ePassenger Pasajero);

/// @brief Imprime los datos de los pasajeros que se encuentran en el array que recibe como parametro
///
/// @param  ePassenger Array del cual se van a imprimir los datos
/// @param int Longitud del array que recibe como parametro
/// @param eFlyCode array de los codigos de vuelo
/// @param int Longitud del array de codigos de vuelo
/// @return  Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL)
///			Retorna [0] en caso de que se hayan mostrado correctamente los datos del array
int printPassengers(ePassenger arrayPassengers[], int lenPassengers, eFlyCode arrayFlyCodes[], int lenFlyCodes);

/// @brief Ordena la lista de pasajeros segun el codigo de vuelo y luego por el estado de manera ascendente o descendente
///
/// @param ePassenger Lista de pasajeros la cual se ordenara segun el criterio recibido (ascendente o descendente)
/// @param int Longitud de la lista de pasajeros
/// @param int Order puede tomar dos valores: ASCENDENTE O DESCENDENTE lo cual determinara el ordenamiento de la lista de pasajeros
/// @param eFlyCodes Lista de codigos de vuelo
/// @param int Longitud de la lista de codigos de vuelo
/// @return int Retorna [-1] en caso de error (longitud menor a 0 o que se apunte a NULL)
/// 			Retorna [0] en caso de que se haya ordenado el array
int sortPassengersByCode(ePassenger arrayPassengers[], int lenPassengers, int order, eFlyCode arrayFlyCodes[], int lenFlyCodes);

/// @brief Permite ordenar el array que recibe como parametro de manera descendente
///
/// @param ePassenger Recibe el array de que se ordenara de manera descendente
/// @param int Longitud del array que se ordenara
void ordenDescendente(ePassenger arrayPassengers[], int lenPassengers);

/// @brief Permite ordenar el array que recibe como parametro de manera ascendente
///
/// @param ePassenger Recibe el array de que se ordenara de manera ascendente
/// @param int Longitud del array que se ordenara
void ordenAscendente(ePassenger arrayPassengers[], int lenPassengers);

/// @brief Permite sumar los precios de todos los pasajes ingresados y calcular el promedio de los mismos
///
/// @param ePassenger Lista de pasajeros de los cuales se calculara el total y promedio del precio de sus pasajes
/// @param int Longitud de la lista de pasajeros
/// @return float Retorna el precio promedio de pasajes
float PromedioVuelos(ePassenger arrayPassengers[], int lenPassengers);

/// @brief Permite saber cuàntos pasajeros superan el precio promedio de pasajes
///
/// @param ePassenger Lista de pasajeros de los cuales se comprobara si superan o no el precio promedio de pasajes
/// @param int Longitud de la lista de pasajeros
/// @param float El precio promedio de los pasajes
/// @return Retorna la cantidad de pasajeros de la lista recibida que superan el precio promedio de los pasajes
int SuperiorAlPromedio(ePassenger arrayPassengers[], int lenPassengers, float promedio);

/// @brief Permite calcular un promedio
///
/// @param float Recibe un total el cual se va a dividir por el contador
/// @param int Contador que se utilizara para dividir al acumulador
/// @return Retorna el promedio
float CalcularPromedio(float acumulador, int contador);

#endif /* ARRAYPASSENGER_H_ */
