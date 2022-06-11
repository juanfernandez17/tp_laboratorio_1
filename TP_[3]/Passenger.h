/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "TypePassenger.h"
#include "FlyCode.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char idFlyCode[50];

}Passenger;

/// @brief Constructor por defecto de un pasajero
///
/// @return Puede retornar NULL en caso de que malloc no haya sido capaz de asignar memoria para un nuevo pasajero
/// 		Passenger* retorna el puntero a el pasajero creado en caso de que malloc haya logrado reservar memoria para el mismo
Passenger* Passenger_new();

/// @brief Constructor parametrizado de un pasajero
///
/// @param idStr char* id que (en caso de no ser NULL) se convertira en int para a continuacion asigarselo al nuevo pasajero creado
/// @param nombreStr char* nombre que (en caso de no ser NULL) sera asignado al nuevo pasajero creado
/// @param apellido char* apellido que (en caso de no ser NULL) sera asignado al nuevo pasajero creado
/// @param precio char* precio que (en caso de no ser NULL) se convertira en float para a continuacion asigarselo al nuevo pasajero creado
/// @param tipoPasajeroStr char* tipo de pasajero que (en caso de no ser NULL) se convetira en int para a continuacion asignarselo al nuevo pasajero creado
/// @param codigoVuelo char* codigo de vuelo que (en caso de no ser NULL) sera asignado al nuevo pasajero creado
/// @return Puede retornar NULL en caso de que malloc no haya sido capaz de asignar memoria para un nuevo pasajero o en caso de que algun
/// 		parametro recibido sea NULL
/// 		Passenger* retorna el puntero a el pasajero creado en caso de que malloc haya logrado reservar memoria para el mismo
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellido,char* precio,char* tipoPasajeroStr,char* codigoVuelo);

/// @brief Libera el espacio de memoria asignado al pasajero que recibe como parametro
///
/// @param this Passenger*
/// @return	int [-1] en caso de que this sea NULL
/// 		int [1] en caso de liberar el espacio de memoria de forma exitosa
int Passenger_delete(Passenger* this);

/// @brief Settea el campo ID del pasajero al que apunta this con el int que recibe como parametro
///
/// @param this Passenger* puntero hacia el pasajero del cual se quiere settear el valor del ID
/// @param id int Valor que sera setteado en el campo id del pasajero
/// @return	int [-1] en caso de que this sea NULL o id sea menor a 0
/// 		int [1] en caso de settear el valor correctamente
int Passenger_setId(Passenger* this,int id);

/// @brief Permite obtener el valor del campo Id del pasajero al que apunta this
///
/// @param this Passenger* puntero hacia el pasajero del cual se quiere obtener el valor del ID
/// @param id int* espacio de memoria donde se guardara el valor del ID del pasajero
/// @return	int [-1] en caso de que this o id sean NULL
/// 		int [1] en caso de obtener correctamente el id
int Passenger_getId(Passenger* this,int* id);

/// @brief Settea el campo nombre del pasajero al que apunta this con la cadena que recibe como parametro
///
/// @param this Passenger* puntero hacia el pasajero del cual se quiere settear el valor del nombre
/// @param nombre char* Valor que sera setteado en el campo nombre del pasajero
/// @return	int [-1] en caso de que this sea NULL o nombre sean NULL
/// 		int [1] en caso de settear el valor correctamente
int Passenger_setNombre(Passenger* this,char* nombre);

/// @brief Permite obtener el valor del campo nombre del pasajero al que apunta this
///
/// @param this Passenger* puntero hacia el pasajero del cual se quiere obtener el valor del nombre
/// @param nombre char* espacio de memoria donde se guardara el valor del nombre del pasajero
/// @return	int [-1] en caso de que this o nombre sean NULL
/// 		int [1] en caso de obtener correctamente el nombre
int Passenger_getNombre(Passenger* this,char* nombre);

/// @brief Settea el campo apellido del pasajero al que apunta this con la cadena que recibe como parametro
///
/// @param this Passenger* puntero hacia el pasajero del cual se quiere settear el valor del apellido
/// @param apellido char* Valor que sera setteado en el campo apellido del pasajero
/// @return	int [-1] en caso de que this sea NULL o apellido sean NULL
/// 		int [1] en caso de settear el valor correctamente
int Passenger_setApellido(Passenger* this,char* apellido);

/// @brief Permite obtener el valor del campo apellido del pasajero al que apunta this
///
/// @param this Passenger* puntero hacia el pasajero del cual se quiere obtener el valor del apellido
/// @param apellido char* espacio de memoria donde se guardara el valor del apellido del pasajero
/// @return	int [-1] en caso de que this o apellido sean NULL
/// 		int [1] en caso de obtener correctamente el nombre
int Passenger_getApellido(Passenger* this,char* apellido);

/// @brief Settea el campo precio del pasajero al que apunta this con el float que recibe como parametro
///
/// @param this Passenger* puntero hacia el pasajero del cual se quiere settear el valor del precio
/// @param precio float Valor que sera setteado en el campo precio del pasajero
/// @return	int [-1] en caso de que this sea NULL o precio sea menor a 0
/// 		int [1] en caso de settear el valor correctamente
int Passenger_setPrecio(Passenger* this, float precio);

/// @brief Permite obtener el valor del campo precio del pasajero al que apunta this
///
/// @param this Passenger* puntero hacia el pasajero del cual se quiere obtener el valor del precio
/// @param precio int* espacio de memoria donde se guardara el valor del precio del pasajero
/// @return	int [-1] en caso de que this o precio sean NULL
/// 		int [1] en caso de obtener correctamente el precio
int Passenger_getPrecio(Passenger* this, float* precio);

/// @brief Settea el campo tipoPasajero del pasajero al que apunta this con el int que recibe como parametro
///
/// @param this Passenger* puntero hacia el pasajero del cual se quiere settear el valor del tipoPasajero
/// @param tipoPasajero char* Valor que sera setteado en el campo tipoPasajero del pasajero
/// @return	int [-1] en caso de que this sea NULL o tipoPasajero sean NULL
/// 		int [1] en caso de settear el valor correctamente
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/// @brief Permite obtener el valor del campo tipoPasajero del pasajero al que apunta this
///
/// @param this Passenger* puntero hacia el pasajero del cual se quiere obtener el valor del tipoPasajero
/// @param tipoPasajero char* espacio de memoria donde se guardara el valor del tipoPasajero del pasajero
/// @return	int [-1] en caso de que this o apellido sean NULL
/// 		int [1] en caso de obtener correctamente el tipoPasajero
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/// @brief Settea el campo codigoVuelo del pasajero al que apunta this con la cadena que recibe como parametro
///
/// @param this Passenger* puntero hacia el pasajero del cual se quiere settear el valor del codigoVuelo
/// @param codigoVuelo char* Valor que sera setteado en el campo codigoVuelo del pasajero
/// @return	int [-1] en caso de que this sea NULL o codigoVuelo sean NULL
/// 		int [1] en caso de settear el valor correctamente
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief Permite obtener el valor del campo codigoVuelo del pasajero al que apunta this
///
/// @param this Passenger* puntero hacia el pasajero del cual se quiere obtener el valor del codigoVuelo
/// @param codigoVuelo char* espacio de memoria donde se guardara el valor del codigoVuelo del pasajero
/// @return	int [-1] en caso de que this o codigoVuelo sean NULL
/// 		int [1] en caso de obtener correctamente el codigoVuelo
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief  Llama a las funciones para Settear valores para asignarle los valores que recibe como parametro al pasajero que tambien recibe como parametro
/// @return [-1] en caso de que alguno de los parametros recibidos sea NULL
/// 		[1] en caso de poder settear todos los valores correctamente
int Passenger_SetterGeneral(Passenger* this, int id, char* nombre, char* apellido, float precio, int tipoPasajero, char* codigoVuelo);

/// @brief  Llama a las funciones para obtener los valores del pasjero que recibe como parametros
/// @return [-1]  en caso de que alguno de los parametros recibidos sea NULL
/// 		[1] en caso de obtener correctamente todos los valores de los campos del pasajero recibido como parametro
int Passenger_GetterGeneral(Passenger* this, int* id, char* nombre, char* apellido, float* precio, int* tipoPasajero, char* codigoVuelo);

/// @brief Imprime los datos de un pasajero
///
/// @param unPasajero Passenger* puntero hacia el pasajero del cual se quiere imprimir los datos
/// @param listaTiposPasajeros TypePassenger* lista de tipos de pasajeros
/// @param lenTiposPasajeros int Cantidad de tipos de elementos
/// @param listaFlyCodes FlyCode* lista de codigos de vuelo
/// @param lenFlyCodes int Cantidad de codigos de vuelo
/// @return int [-1] en caso de que unPasajero o listaTiposPasajeros o listaFlyCodes apunte a NULL o lenTiposPasajeros o lenFlyCodes sea menor a 0
/// 		int [1] en caso de imprimir todos los datos correctamente
int Passenger_PrintOne(Passenger* unPasajero, TypePassenger* listaTiposPasajeros, int lenTiposPasajeros, FlyCode* listaFlyCodes, int lenFlyCodes);

///  @brief Verifica que el valor recibido como cadena sea un precio valido
///
/// @param precio char* cadena que contiene el valor a analizar
/// @return int [-1] en caso de que no sea un precio valido
/// 		int [1] en caso de que si sea un precio valido
int Passenger_ValidarPrecio(char* precio);

/// @brief Le pide al usuario los datos correspondientes a la estructura Passenger los cuales seran validados y
/// 		asignados al parametro correspondiente al dato
/// @return int [-1] en caso de que alguno de los parametros de la funcion sea NULL o la longitud de las listas recibidas sea menor a 0
/// 		int [1] en caso de pedir y asignar correctamente todos los datos
int Passenger_PedirDatos(	char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, TypePassenger* listaTiposPasajeros,
							int lenTiposPasajeros,FlyCode* listaFlyCodes, int lenFlyCodes, int lenLista);

/// @brief Permite modificar los campos de un pasajero
///
/// @param unPasajero Passenger* puntero al pasajero del cual se quiere realizar una modificacion
/// @param listaTiposPasajeros TypePassenger* lista de tipos de pasajeros
/// @param lenTiposPasajeros int Cantidad de tipos de elementos
/// @param listaFlyCodes FlyCode* lista de codigos de vuelo
/// @param lenFlyCodes int Cantidad de codigos de vuelo
/// @return int [-1] en caso de que unPasajero o listaTiposPasajeros o listaFlyCodes sean NULL o que lenTiposPasajeros o lenFlyCodes sean menor a 0
/// 		int [1] en caso de que se pueda acceder a modificar un pasajero
int Passenger_Modificar(Passenger* unPasajero, TypePassenger* listaTiposPasajeros, int lenTiposPasajeros, FlyCode* listaFlyCodes, int lenFlyCodes);

/// @brief Compara los nombres de los pasajeros a los cuales apuntan thisUno y thisDos
///
/// @param thisUno void* Puntero a un pasajero
/// @param thisDos void* Puntero a un pasajero
/// @return int [-1] en caso de que el nombre del segundo sea mayor al del primero
/// 		int [0] en caso de que los nombres sean iguales
/// 		int [1] en caso de que el primer nombre sea mayor que el del segundo
int Passenger_CompareByName(void* thisUno, void* thisDos);

/// @brief Compara los apellidos de los pasajeros a los cuales apuntan thisUno y thisDos
///
/// @param thisUno void* Puntero a un pasajero
/// @param thisDos void* Puntero a un pasajero
/// @return int [-1] en caso de que el apellido del segundo sea mayor al del primero
/// 		int [0] en caso de que los apellidos sean iguales
/// 		int [1] en caso de que el primer apellido sea mayor que el del segundo
int Passenger_CompareByLastName(void* thisUno, void* thisDos);

/// @brief Compara los id de los pasajeros a los cuales apuntan thisUno y thisDos
///
/// @param thisUno void* Puntero a un pasajero
/// @param thisDos void* Puntero a un pasajero
/// @return int [-1] en caso de que el id del segundo sea mayor al del primero
/// 		int [0] en caso de que los id sean iguales
/// 		int [1] en caso de que el id sea mayor que el del segundo
int Passenger_CompareById(void* thisUno, void* thisDos);

/// @brief Compara los precios de los pasajeros a los cuales apuntan thisUno y thisDos
///
/// @param thisUno void* Puntero a un pasajero
/// @param thisDos void* Puntero a un pasajero
/// @return int [-1] en caso de que el precio del segundo sea mayor al del primero
/// 		int [0] en caso de que los precios sean iguales
/// 		int [1] en caso de que el precio  sea mayor que el del segundo
int Passenger_CompareByPrice(void* thisUno, void* thisDos);

/// @brief Compara los typePassenger de los pasajeros a los cuales apuntan thisUno y thisDos
///
/// @param thisUno void* Puntero a un pasajero
/// @param thisDos void* Puntero a un pasajero
/// @return int [-1] en caso de que el typePassenger del segundo sea mayor al del primero
/// 		int [0] en caso de que los typePassenger sean iguales
/// 		int [1] en caso de que el typePassenger sea mayor que el del segundo
int Passenger_CompareByTypePassenger(void* thisUno, void* thisDos);

/// @brief Compara los flyCode de los pasajeros a los cuales apuntan thisUno y thisDos
///
/// @param thisUno void* Puntero a un pasajero
/// @param thisDos void* Puntero a un pasajero
/// @return int [-1] en caso de que el flyCode del segundo sea mayor al del primero
/// 		int [0] en caso de que los flyCode sean iguales
/// 		int [1] en caso de que el flyCode sea mayor que el del segundo
int Passenger_CompareByFlyCode(void* thisUno, void* thisDos);

/// @brief Compara el typePassenger de un pasajero con la listaTiposPasajeros y devuelve el indice del tipo de pasajero que le corresponde
///
/// @param unPasajero Passenger* Puntero a un pasajero
/// @param listaTiposPasajeros TypePassenger* lista de tipos de pasajeros
/// @param lenTiposPasajeros int Cantidad de tipos de pasajeros
/// @return int [i] indice del tipo de pasajero que le corresponde al pasajero
int Passenger_MatchTypePassenger(Passenger* unPasajero, TypePassenger* listaTiposPasajeros, int lenTiposPasajeros);

/// @brief Compara el flyCode de un pasajero con la listaFlyCodes y devuelve el indice del flyCode que le corresponde
///
/// @param unPasajero Passenger* Puntero a un pasajero
/// @param listaFlyCodes FlyCode* lista de codigos de vuelo
/// @param lenFlyCodes int Cantidad de codigos de vuelo
/// @return int [i] indice del codigo de vuelo que le corresponde al pasajero
int Passenger_MatchFlyCode(Passenger* unPasajero, FlyCode* listaFlyCodes, int lenFlyCodes);

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

#endif /* PASSENGER_H_ */
