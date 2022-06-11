#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return 	int [-1] en caso de que pFile o pArrayListPassenger sean NULL
 *			int [1] en caso de parsear todos los datos que se encuentran en el archivo de texto
 *			y agregarlos a pArrayListPassenger
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int error;
	int datosLeidos;
	char idStr[20];
	char nombreStr[20];
	char apellidoStr[20];
	char precioStr[20];
	char tipoPasajeroStr[20];
	char codigoVueloStr[20];
	char estadoVueloStr[20];
	Passenger* unPasajero;
	error = -1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		datosLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);

		while(!feof(pFile) && datosLeidos == 7)
		{
			datosLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
			unPasajero = Passenger_newParametros(idStr, nombreStr, apellidoStr, precioStr, tipoPasajeroStr, codigoVueloStr);

			if(unPasajero != NULL)
			{
				ll_add(pArrayListPassenger, unPasajero);
			}
		}
		error = 1;
	}
    return error;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return 	int [-1] en caso de que pFile o pArrayListPassenger sean NULL
 *			int [1] en caso de parsear todos los datos que se encuentran en el archivo binario
 *			y agregarlos a pArrayListPassenger
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int error;
	Passenger* unPasajero;
	error = -1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			unPasajero = Passenger_new();

			if(unPasajero != NULL)
			{
				fread(unPasajero,sizeof(Passenger), 1,pFile);
				ll_add(pArrayListPassenger, unPasajero);
			}
		}
		error = 1;
	}
    return error;
}
