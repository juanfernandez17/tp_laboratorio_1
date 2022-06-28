#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"

#define TAM_TYPEPASSENGER 3
#define TAM_FLYCODE 8


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int error;
	FILE* pArchivo;
	error = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "r");

		if(pArchivo != NULL)
		{
			parser_PassengerFromText(pArchivo, pArrayListPassenger);
			fclose(pArchivo);
			error = 1;
		}
	}
    return error;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return 	int [-1] en caso de que path o pArrayListPassenger sea igual a NULL
 *			int [1] en caso de cargar los datos del archivo binario de manera exitosa
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int error;
	FILE* pArchivo;
	error = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "rb");

		if(pArchivo != NULL)
		{
			parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
			fclose(pArchivo);
			error = 1;
		}
	}
    return error;
}

/** \brief Alta de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return 	int [-1] en caso de  que pArrayListPassenger sea NULL o que no se haya logrado crear un pasajero
 *			int [1] en caso de crear y agregar un pasajero a pArrayListPassenger de manera exitosa
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int error;
	int lenLista;
	char idStr[20];
	char nombreStr[20];
	char apellidoStr[20];
	char precioStr[20];
	char tipoPasajeroStr[20];
	char codigoVueloStr[20];
	Passenger* nuevoPasajero;
	TypePassenger listaTiposPasajeros[TAM_TYPEPASSENGER];
	FlyCode listaFlyCodes[TAM_FLYCODE];

	TypePassenger_init(listaTiposPasajeros, TAM_TYPEPASSENGER);
	FlyCode_init(listaFlyCodes, TAM_FLYCODE);
	error = -1;
	lenLista = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL)
	{
		Passenger_PedirDatos(idStr, nombreStr, apellidoStr, precioStr, tipoPasajeroStr, codigoVueloStr, listaTiposPasajeros, TAM_TYPEPASSENGER, listaFlyCodes, TAM_FLYCODE, lenLista);
		nuevoPasajero = Passenger_newParametros(idStr,nombreStr, apellidoStr, precioStr, tipoPasajeroStr, codigoVueloStr);

		if(nuevoPasajero != NULL)
		{
			ll_add(pArrayListPassenger, nuevoPasajero);
			error = 1;
		}
	}
	return error;
}

/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return 	int [-1] en caso de que pArrayListPassenger sea NULL
 * 			int [1] en caso de lograr listar todos los pasajeros
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int error;
	int lenLista;
	Passenger* unPasajero;
	TypePassenger listaTiposPasajeros[TAM_TYPEPASSENGER];
	FlyCode listaFlyCodes[TAM_FLYCODE];

	TypePassenger_init(listaTiposPasajeros, TAM_TYPEPASSENGER);
	FlyCode_init(listaFlyCodes, TAM_FLYCODE);
	error = -1;
	lenLista = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL)
	{
		printf("=================================================================================================================\n");
		printf("  ID  \tNAME\t\t     LAST NAME  \t      PRICE\t    TYPE PASSENGER\t FLY CODE   STATUS FLIGHT\n");
		printf("=================================================================================================================\n");
		for(int i = 0; i < lenLista; i++)
		{
			unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			if(unPasajero != NULL)
			{
				Passenger_PrintOne(unPasajero, listaTiposPasajeros, TAM_TYPEPASSENGER, listaFlyCodes, TAM_FLYCODE);
			}
		}
		error = 1;
	}
    return error;
}
/** \brief Modificar datos de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return 	int [-1] en caso de que pArrayListPassenger sea NULL
 * 			int [0] en caso de no encontrar un pasajero con el ID ingresado
 *			int [1] en caso de encontrar un pasajero con el ID ingresado
 */
/*
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int error;
	int idModify;
	int lenLista;
	int idMayor;
	int idPassenger;
	Passenger* passengerConIdMayor;
	Passenger* unPasajero;
	TypePassenger listaTiposPasajeros[TAM_TYPEPASSENGER];
	FlyCode listaFlyCodes[TAM_FLYCODE];

	TypePassenger_init(listaTiposPasajeros, TAM_TYPEPASSENGER);
	FlyCode_init(listaFlyCodes, TAM_FLYCODE);
	error = -1;
	lenLista = ll_len(pArrayListPassenger);
	passengerConIdMayor = (Passenger*) ll_get(pArrayListPassenger, lenLista - 1);
	Passenger_getId(passengerConIdMayor, &idMayor);

	if(pArrayListPassenger != NULL)
	{
		error = 0;
		controller_ListPassenger(pArrayListPassenger);
		utn_getNumeroConIntentos(&idModify, "\n\nID del pasajero a modificar: ", "Error, ID fuera de rango. Intentelo de nuevo: \n", 1, idMayor, 5);
		for(int i = 0; i < lenLista; i++)
		{
			unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_getId(unPasajero, &idPassenger);

			if(idPassenger == idModify)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
				if(unPasajero != NULL)
				{
					printf("\nPasajero a modificar: \n");
					Passenger_PrintOne(unPasajero, listaTiposPasajeros, TAM_TYPEPASSENGER, listaFlyCodes, TAM_FLYCODE);
					Passenger_Modificar(unPasajero, listaTiposPasajeros, TAM_TYPEPASSENGER, listaFlyCodes, TAM_FLYCODE);
					error = 1;
					break;
				}
			}
		}
	}
    return error;
}*/

int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int error;
	int idModify;
	int lenLista;
	int idMayor;
	int idPassenger;
	Passenger* passengerConIdMayor;
	Passenger* unPasajero;
	TypePassenger listaTiposPasajeros[TAM_TYPEPASSENGER];
	FlyCode listaFlyCodes[TAM_FLYCODE];

	TypePassenger_init(listaTiposPasajeros, TAM_TYPEPASSENGER);
	FlyCode_init(listaFlyCodes, TAM_FLYCODE);
	error = -1;
	lenLista = ll_len(pArrayListPassenger);
	passengerConIdMayor = (Passenger*) ll_get(pArrayListPassenger, lenLista - 1);
	Passenger_getId(passengerConIdMayor, &idMayor);

	if(pArrayListPassenger != NULL)
	{
		error = 0;
		controller_ListPassenger(pArrayListPassenger);
		utn_getNumeroConIntentos(&idModify, "\n\nID del pasajero a modificar: ", "Error, ID fuera de rango. Intentelo de nuevo: \n", 1, idMayor, 5);

		for(int i = 0; i < lenLista; i++)
		{
			unPasajero = (Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_getId(unPasajero, &idPassenger);

			if(idPassenger == idModify)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
				if(unPasajero != NULL)
				{
					printf("\nPasajero a modificar: \n");
					Passenger_PrintOne(unPasajero, listaTiposPasajeros, TAM_TYPEPASSENGER, listaFlyCodes, TAM_FLYCODE);
					Passenger_Modificar(unPasajero, listaTiposPasajeros, TAM_TYPEPASSENGER, listaFlyCodes, TAM_FLYCODE);
					error = 1;
					break;
				}
			}
		}
	}
    return error;
}
/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \return 	int [-1] en caso de que pArrayListPassenger sea NULL
 * 			int [0] en caso de que no exista un pasajero con el ID ingresado
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int error;
	int idRemove;
	int idPassenger;
	int idMayor;
	int lenLista;
	Passenger* passengerConIdMayor;
	Passenger* unPasajero;
	TypePassenger listaTiposPasajeros[TAM_TYPEPASSENGER];
	FlyCode listaFlyCodes[TAM_FLYCODE];

	TypePassenger_init(listaTiposPasajeros, TAM_TYPEPASSENGER);
	FlyCode_init(listaFlyCodes, TAM_FLYCODE);
	error = -1;
	lenLista = ll_len(pArrayListPassenger);
	passengerConIdMayor = (Passenger*) ll_get(pArrayListPassenger, lenLista - 1);
	Passenger_getId(passengerConIdMayor, &idMayor);

	if(pArrayListPassenger != NULL)
	{
		error = 0;
		controller_ListPassenger(pArrayListPassenger);
		utn_getNumeroConIntentos(&idRemove, "\n\nID del pasajero a dar de baja: ", "Error, ID fuera de rango. Intentelo de nuevo: \n", 1, idMayor, 5);
		for(int i = 0; i < lenLista; i++)
		{
			unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_getId(unPasajero, &idPassenger);

			if(idPassenger == idRemove)
			{

				Passenger_PrintOne(unPasajero, listaTiposPasajeros, TAM_TYPEPASSENGER, listaFlyCodes, TAM_FLYCODE);
				if(utn_ConfirmarAccion("¿Desea remover de la lista a este pasajero? (si/no): ", "Error, opcion no disponible. Intentelo de nuevo (si/no): "))
				{
					ll_remove(pArrayListPassenger, i);
					error = 1;
					break;
				}
			}
		}
	}
    return error;
}

/** \brief Ordenar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return	int [-1] en caso de que pArrayListPassenger sea NULL
 *			int [1] en caso de ordenar exitosamente la lista
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int error;
	int criterioOrdenamiento;
	int orden;
	LinkedList* cloneList;
	error = -1;

	if(pArrayListPassenger != NULL)
	{
		cloneList = ll_clone(pArrayListPassenger);

		utn_getNumero(&criterioOrdenamiento, "******** CRITERIOS DE ORDENAMIENTO ********\n\n"
				"1. Nombre\n"
				"2. Apellido\n"
				"3. Id\n"
				"4. Precio\n"
				"5. Tipo de pasajero\n"
				"6. Codigo de vuelo\n\n"
				"Seleccione una opcion: ", "Error, opcion no valida. Intentelo de nuevo: ", 1, 6);

		utn_getNumero(&orden, "\n\nOrdenar de manera:\n\n"
				"1. Ascendente\n"
				"0. Descendente\n\n"
				"Seleccione una opcion: ", "Error, opcion no valida. Intentelo de nuevo: ", 0, 1);

		switch(orden)
		{
		case 1:
			switch(criterioOrdenamiento)
			{
				case 1:
					ll_sort(cloneList, Passenger_CompareByName, orden);
					break;
				case 2:
					ll_sort(cloneList, Passenger_CompareByLastName, orden);
					break;
				case 3:
					ll_sort(cloneList, Passenger_CompareById, orden);
					break;
				case 4:
					ll_sort(cloneList, Passenger_CompareByPrice, orden);
					break;
				case 5:
					ll_sort(cloneList, Passenger_CompareByTypePassenger, orden);
					break;
				default:
					ll_sort(cloneList, Passenger_CompareByFlyCode, orden);
					break;
			}
			break;
		default:
			switch(criterioOrdenamiento)
			{
				case 1:
					ll_sort(cloneList, Passenger_CompareByName, orden);
					break;
				case 2:
					ll_sort(cloneList, Passenger_CompareByLastName, orden);
					break;
				case 3:
					ll_sort(cloneList, Passenger_CompareById, orden);
					break;
				case 4:
					ll_sort(cloneList, Passenger_CompareByPrice, orden);
					break;
				case 5:
					ll_sort(cloneList, Passenger_CompareByTypePassenger, orden);
					break;
				default:
					ll_sort(cloneList, Passenger_CompareByFlyCode, orden);
					break;
			}
			break;
		}
		controller_ListPassenger(cloneList);
		error = 1;
	}
    return error;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return 	int [-1] en caso de que path o pArrayListPassenger sean NULL
 *			int [1] en caso de guardar exitosamente los datos en el archivo de texto
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int error;
	int lenLista;
	int indiceTypePassenger;
	int indiceFlyCode;
	int id;
	char nombre[20];
	char apellido[20];
	float precio;
	char codigoVuelo[20];
	int tipoPasajero;
	FILE* pArchivo;
	Passenger* unPasajero;
	TypePassenger listaTiposPasajeros[TAM_TYPEPASSENGER];
	FlyCode listaFlyCodes[TAM_FLYCODE];

	TypePassenger_init(listaTiposPasajeros, TAM_TYPEPASSENGER);
	FlyCode_init(listaFlyCodes, TAM_FLYCODE);
	lenLista = ll_len(pArrayListPassenger);
	error = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "w");

		if(pArchivo != NULL)
		{
			fprintf(pArchivo, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
			for(int i = 0; i < lenLista; i++)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
				if(unPasajero != NULL)
				{
					Passenger_GetterGeneral(unPasajero, &id, nombre, apellido, &precio, &tipoPasajero, codigoVuelo);
					indiceTypePassenger = Passenger_MatchTypePassenger(unPasajero, listaTiposPasajeros, TAM_TYPEPASSENGER);
					indiceFlyCode = Passenger_MatchTypePassenger(unPasajero, listaTiposPasajeros, TAM_FLYCODE);
					if(indiceTypePassenger != -1 && indiceFlyCode != -1)
					{
						fprintf(pArchivo, "%d,%s,%s,%.f,%s,%s,%s\n", id, nombre, apellido, precio, codigoVuelo,
																	listaTiposPasajeros[indiceTypePassenger].descripcion,
																	listaFlyCodes[indiceFlyCode].statusFly);
					}
				}
			}
			fclose(pArchivo);
			error = 1;
		}
	}
    return error;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return 	int [-1] en caso de que path o pArrayListPassenger sean NULL
 *			int [1] en caso de guardar exitosamente los datos en el archivo binario
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int error;
	int lenLista;
	FILE* pArchivo;
	Passenger* unPasajero;

	error = -1;
	lenLista = ll_len(pArrayListPassenger);

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path, "wb");

		if(pArchivo != NULL)
		{
			for(int i = 0; i < lenLista; i++)
			{
				unPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
				fwrite(unPasajero,sizeof(Passenger),1,pArchivo);
			}
			fclose(pArchivo);
			error = 1;
		}
	}
    return error;
}


