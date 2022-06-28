/*
 * ArrayPassenger.c
 *
 *  Created on: 25 jun. 2022
 *      Author: juan
 */

#include "ArrayPassenger.h"
#include "utn.h"
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define TAM_F 100
#define ASCENDENTE 1
#define DESCENDENTE 0
#define TOUPPER 1
#define TOLOWER 0

int initPassengers(Passenger* list, int len)
{
	int returnAux;
	returnAux = -1;

	if(list != NULL && len >= 0)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
		returnAux = 0;
	}
	return returnAux;
}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, int idFlyCode)
{
	int returnAux;
	int indiceLibre;
	returnAux = -1;

	if(list != NULL && len >= 0 && id > 0 && name != NULL && lastName != NULL && price > 0 && typePassenger > 0 && idFlyCode > 0)
	{
		indiceLibre = findIsEmpty(list, len);

		if(indiceLibre != -1)
		{
			list[indiceLibre].id = id;
			strcpy(list[indiceLibre].name, name);
			strcpy(list[indiceLibre].lastName, lastName);
			list[indiceLibre].price = price;
			list[indiceLibre].typePassenger = typePassenger;
			list[indiceLibre].idFlyCode = idFlyCode;
			list[indiceLibre].isEmpty = FALSE;
			returnAux = 0;
		}
	}
	return returnAux;
}

int findPassengerById(Passenger* list, int len, int id)
{
	int returnAux;
	returnAux = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}

int removePassenger(Passenger* list, int len, int id)
{
	int returnAux;
	int indiceRemover;
	returnAux = -1;

	if(list != NULL && len > 0)
	{
		indiceRemover = findPassengerById(list, len, id);

		if(indiceRemover != -1)
		{
			list[indiceRemover].isEmpty = TRUE;
			returnAux = 0;
		}
	}
	return returnAux;
}

int findIsEmpty(Passenger* list, int len)
{
	int returnAux;
	returnAux = -1;

	if(list != NULL && len >= 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				returnAux = i;
				break;
			}
		}
	}
	return returnAux;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int returnAux;
	int comparacionApellido;
	int comparacionTipoPasajero;
	Passenger auxiliar;
	returnAux = -1;

	if(list != NULL && len > 0 && (order == 1 || order == 0))
	{
		for(int i = 0; i < len - 1; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if(list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)
				{
					comparacionApellido = Passenger_CompareByLastName(list[i], list[j]);

					if((order == 1 && comparacionApellido == 1) || (order == 0 && comparacionApellido == -1))
					{
						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
					}
					else
					{
						if(comparacionApellido == 0)
						{
							comparacionTipoPasajero = Passenger_CompareByTypePassenger(list[i], list[j]);
							if((order == 1 && comparacionTipoPasajero == 1) || (order == 0 && comparacionTipoPasajero == -1))
							{
								auxiliar = list[i];
								list[i] = list[j];
								list[j] = auxiliar;
							}
						}
					}
				}
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

int Passenger_CompareByLastName(Passenger passengerUno, Passenger passengerDos)
{
	int comparacion;
	char nombreUno[50];
	char nombreDos[50];

	strcpy(nombreUno, passengerUno.lastName);
	strcpy(nombreDos, passengerDos.lastName);

	if(strcmp(nombreUno, nombreDos) > 0)
	{
		comparacion = 1;
	}
	else
	{
		if(strcmp(nombreUno, nombreDos) < 0)
		{
			comparacion = -1;
		}
		else
		{
			comparacion = 0;
		}
	}
	return comparacion;
}

int Passenger_CompareByTypePassenger(Passenger pasajeroUno, Passenger pasajeroDos)
{
	int comparacion;
	int tipoPasajeroUno;
	int tipoPasajeroDos;

	comparacion = 0;
	tipoPasajeroUno = pasajeroUno.typePassenger;
	tipoPasajeroDos = pasajeroDos.typePassenger;

	if(tipoPasajeroUno > tipoPasajeroDos)
	{
		comparacion = 1;
	}
	else
	{
		if(tipoPasajeroUno < tipoPasajeroDos)
		{
			comparacion = -1;
		}
	}
	return comparacion;
}

int printPassengers(Passenger* list, int len, FlyCode* listFlyCode)
{
	int returnAux;
	returnAux = -1;

	if(list != NULL && len > 0)
	{
		printf("\n==============================================================================================");
		printf("\n ID \tNAME\t   LASTNAME\t\tPRICE\t   TYPEPASSENGER      FLYCODE\tSTATUSFLIGHT ");
		printf("\n==============================================================================================\n");
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printOnePassenger(list[i], listFlyCode);
			}
		}
		printf("==============================================================================================\n");
		returnAux = 0;
	}
	return returnAux;
}

void printOnePassenger(Passenger unPasajero, FlyCode* list)
{
	char tipoPasajeroStr[50];
	char flyCodeStr[50];
	char estadoVuelo[50];

	Passenger_getTyePassenger(unPasajero.typePassenger, tipoPasajeroStr);
	Passenger_getStatusAndFlightCode(unPasajero.idFlyCode, list, flyCodeStr, estadoVuelo);

	printf("| %-4d | %-10s %-15s | %-10.2f | %-15s | %-10s | %-10s |\n", unPasajero.id, unPasajero.name,
	unPasajero.lastName, unPasajero.price, tipoPasajeroStr, flyCodeStr, estadoVuelo);
}

int Passenger_getTyePassenger(int typePassenger, char* typePassengerStr)
{
	int returnAux;
	returnAux = -1;

	if(typePassenger > 0 && typePassengerStr != NULL)
	{
		switch(typePassenger)
		{
		case 1:
			strcpy(typePassengerStr, "Turista");
			break;
		case 2:
			strcpy(typePassengerStr, "Primera clase");
			break;
		case 3:
			strcpy(typePassengerStr, "Ejecutivo");
			break;
		default:
			strcpy(typePassengerStr, "Premium");
			break;
		}
		returnAux = 0;
	}
	return returnAux;
}

int Passenger_getStatusAndFlightCode(int idFlyCode, FlyCode* list,char* codigoVueloStr, char* estadoVueloStr)
{
	int returnAux;
	returnAux = -1;

	if(idFlyCode > 0 && codigoVueloStr != NULL && estadoVueloStr != NULL)
	{
		for(int i = 0; i < TAM_F; i++)
		{
			if(list[i].idFlyCode == idFlyCode)
			{
				strcpy(codigoVueloStr, list[i].codigoVueloStr);
				strcpy(estadoVueloStr, list[i].estadoVueloStr);
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

int sortPassengersByCode(Passenger* list, int len, int order, FlyCode* listFlyCode)
{
	int returnAux;
	int retornoComparacion;
	Passenger auxiliar;
	returnAux = -1;

	if(list != NULL && (order == 0 || order == 1))
	{
		for(int i = 0; i < len - 1; i++)
		{
			for(int j = i + 1; j < len; j++)
			{
				if(list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)
				{
					retornoComparacion = Passenger_CompareByCode(list[i], list[j], listFlyCode);

					if((order == 1 && retornoComparacion == 1) || (order == 0 && retornoComparacion == -1))
					{
						auxiliar = list[i];
						list[i] = list[j];
						list[j] = auxiliar;
					}
				}
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

int printPassengersFlyCode(Passenger* list, int len, int order, FlyCode* listFlyCode,char statusFlight[])
{
	int returnAux;
	char estadoVuelo[50];
	char codigoVuelo[50];
	returnAux = -1;

	if(list != NULL && len > 0 && listFlyCode != NULL && statusFlight != NULL && (order == 0 || order == 1))
	{
		sortPassengersByCode(list, len, order, listFlyCode);

		for(int i = 0; i < len; i++)
		{
			Passenger_getStatusAndFlightCode(list[i].idFlyCode, listFlyCode, codigoVuelo, estadoVuelo);

			if(strcmp(estadoVuelo, statusFlight) == 0 && list[i].isEmpty == FALSE)
			{
				printOnePassenger(list[i], listFlyCode);
			}
		}
		returnAux = 1;
	}

	return returnAux;
}

int Passenger_CompareByCode(Passenger passengerUno, Passenger passengerDos, FlyCode* list)
{
	int comparacion;
	char codigoVueloUno[20];
	char codigoVueloDos[20];
	char estadoVueloUno[20];
	char estadoVueloDos[20];

	Passenger_getStatusAndFlightCode(passengerUno.idFlyCode, list, codigoVueloUno, estadoVueloUno);
	Passenger_getStatusAndFlightCode(passengerDos.idFlyCode, list, codigoVueloDos, estadoVueloDos);

	if(strcmp(codigoVueloUno, codigoVueloDos) > 0)
	{
		comparacion = 1;
	}
	else
	{
		if(strcmp(codigoVueloUno, codigoVueloDos) < 0)
		{
			comparacion = -1;
		}
		else
		{
			comparacion = 0;
		}
	}
	return comparacion;
}

int Passenger_modify(Passenger* list, int len, FlyCode* listFlyCode, int lenFlyCode)
{
	int returnAux;
	int indice;
	int idModificar;
	returnAux = -1;

	if(list != NULL && len > 0 && listFlyCode != NULL && lenFlyCode > 0)
	{
		printPassengers(list, len, listFlyCode);
		utn_getNumero(&idModificar, "Ingresar ID del pasajero: ", "Error, intentelo de nuevo: ", 1, len);
		indice = findPassengerById(list, len, idModificar);

		if(indice != -1 && list[indice].isEmpty == FALSE)
		{
			printOnePassenger(list[indice], listFlyCode);
			Passenger_MenuModificar(list, listFlyCode, lenFlyCode, indice);
		}
	}
	return returnAux;
}

int Passenger_MenuModificar(Passenger* list, FlyCode* listFlyCode, int lenFlyCode, int indice)
{
	int returnAux;
	int option;
	char newName[51];
	char newLastName[51];
	float newPrice;
	int newTypePassenger;
	int newFlyCode;
	int modificaciones;
	returnAux = -1;

	if(listFlyCode != NULL && lenFlyCode > 0 && list != NULL)
	{
		do
		{
			utn_getNumero(&option, "\n**** Menu para modificaciones ****\n"
							"1. Nombre\n"
							"2. Apellido\n"
							"3. Precio\n"
							"4. Tipo de pasajero\n"
							"5. Codigo de vuelo\n"
							"6. Regresar al menu principal\n\n"
							"Seleccione una opcion: ", "Error, intentelo de nuevo: ", 1, 6);

			switch(option)
			{
				case 1:
					utn_getString(newName, "Ingresar nombre: ", "Error, intentelo de nuevo: ", 51);
					modificaciones = utn_ConfirmarAccion("¿Confirmar cambio? si/no: ", "Error, intentelo de nuevo (opciones: si/no): ");

					if(modificaciones == 1)
					{
						Passenger_DarFormatoNombre(newName, strlen(newName));
						strcpy(list[indice].name, newName);
					}
					break;
				case 2:
					utn_getString(newLastName, "Ingresar apellido: ", "Error, intentelo de nuevo: ", 51);
					modificaciones = utn_ConfirmarAccion("¿Confirmar cambio? si/no: ", "Error, intentelo de nuevo (opciones: si/no): ");

					if(modificaciones == 1)
					{
						Passenger_DarFormatoNombre(newLastName, strlen(newLastName));
						strcpy(list[indice].lastName, newLastName);
					}
					break;
				case 3:
					utn_getNumeroFloat(&newPrice, "Ingresar precio: ", "Error, intentelo de nuevo: ", 1, 1000000);
					modificaciones = utn_ConfirmarAccion("¿Confirmar cambio? si/no: ", "Error, intentelo de nuevo (opciones: si/no): ");

					if(modificaciones == 1)
					{
						list[indice].price = newPrice;
					}
					break;
				case 4:
					utn_getNumero(&newTypePassenger, "\nTipos de pasajeros\n\n1. Turista\n"
							"2. Primer clase\n3. Ejecutivo\n4. Premium\n\nIngresar tipo de pasajero (numero): ", "Error, intentelo de nuevo: ", 1, 4);
					modificaciones = utn_ConfirmarAccion("¿Confirmar cambio? si/no: ", "Error, intentelo de nuevo (opciones: si/no): ");

					if(modificaciones == 1)
					{
						list[indice].typePassenger = newTypePassenger;
					}
					break;
				case 5:
					FlyCode_printFlyCodes(listFlyCode, lenFlyCode);
					utn_getNumero(&newFlyCode, "Ingresar codigo de vuelo (numero): ", "Error, intentelo de nuevo: ", 1, lenFlyCode);
					modificaciones = utn_ConfirmarAccion("¿Confirmar cambio? si/no: ", "Error, intentelo de nuevo (opciones: si/no): ");

					if(modificaciones == 1)
					{
						list[indice].idFlyCode = newFlyCode;
					}
					break;
				default:
					printf("\nRegreso al menu principal!");
					break;
			}
		} while(option != 6);

		returnAux = 0;
	}
	return returnAux;
}

int Passenger_PedirDatos(Passenger* list, int len, FlyCode* listFlyCode, int lenFlyCode, int* lastId)
{
	int returnAux;
	char nombre[51];
	char apellido[51];
	float precio;
	int tipoPasajero;
	int codigoVuelo;
	int lenNombre;
	int lenApellido;

	returnAux = -1;

	if(list != NULL && listFlyCode != NULL && lastId != NULL)
	{
		*lastId = *lastId + 1;

		utn_getString(nombre, "Ingresar nombre: ", "Error, intentelo de nuevo: ", 51);
		while(Passenger_ValidarNombre(nombre, strlen(nombre)) == 0)
		{
			printf("\nNombre no valido. Intentelo de nuevo.\n");
			utn_getString(nombre, "Ingresar nombre: ", "Error, intentelo de nuevo: ", 51);
		}
		utn_getString(apellido, "Ingresar apellido: ", "Error, intentelo de nuevo: ", 51);
		while(Passenger_ValidarNombre(apellido, strlen(apellido)) == 0)
		{
			printf("\nApellido no valido. Intentelo de nuevo.\n");
			utn_getString(apellido, "Ingresar apellido: ", "Error, intentelo de nuevo: ", 51);
		}
		utn_getNumeroFloat(&precio, "Ingresar precio: ", "Error, intentelo de nuevo: ", 1, 1000000);
		utn_getNumero(&tipoPasajero, "\nTipos de pasajeros\n\n1. Turista\n"
						"2. Primer clase\n3. Ejecutivo\n4. Premium\n\nIngresar tipo de pasajero (numero): ", "Error, intentelo de nuevo: ", 1, 4);
		FlyCode_printFlyCodes(listFlyCode, lenFlyCode);
		utn_getNumero(&codigoVuelo, "\nIngresar codigo de vuelo (numero): ", "Error, intentelo de nuevo: ", 1, lenFlyCode);

		lenNombre = strlen(nombre);
		lenApellido = strlen(apellido);
		Passenger_DarFormatoNombre(nombre, lenNombre);
		Passenger_DarFormatoNombre(apellido, lenApellido);

		returnAux = addPassenger(list, len, *lastId, nombre, apellido, precio, tipoPasajero, codigoVuelo);
	}
	return returnAux;
}

int Passenger_delete(Passenger* list, int len, FlyCode* listFlyCode, int lenFlyCode)
{
	int returnAux;
	int idRemover;
	int indice;
	int confirmacion;
	returnAux = -1;

	if(list != NULL && len > 0 && listFlyCode != NULL && lenFlyCode > 0)
	{
		printPassengers(list, lenFlyCode, listFlyCode);
		utn_getNumero(&idRemover, "Ingresar ID del pasajero: ", "Error, intentelo de nuevo: ", 1, len);
		indice = findPassengerById(list, lenFlyCode, idRemover);

		if(indice != -1)
		{
			printOnePassenger(list[indice], listFlyCode);
			confirmacion = utn_ConfirmarAccion("¿Confirmar eliminacion? si/no: ", "Error, intentelo de nuevo (opciones: si/no): ");

			if(confirmacion == 1)
			{
				removePassenger(list, lenFlyCode, idRemover);
				returnAux = 0;
			}
		}
	}
	return returnAux;
}

int Passenger_subMenu(int optionSubMenu, Passenger* list, int len, FlyCode* listFlyCode)
{
	int returnAux;
	float promedio;
	float total;
	int order;
	returnAux = -1;

	if(list != NULL && len > 0 && optionSubMenu > 0 && listFlyCode != NULL)
	{
		switch(optionSubMenu)
		{
			case 1:
				utn_getNumero(&order, "Orden:\n1. Ascendente\n2. Descendente\nSeleccione una opcion: ", "Error, intentelo de nuevo: ", 1, 2);
				if(order == 1)
				{
					sortPassengers(list, len, ASCENDENTE);
				}
				else
				{
					sortPassengers(list, len, DESCENDENTE);
				}
				printPassengers(list, len, listFlyCode);
				break;
			case 2:
				Passenger_getPromedioVuelos(list, len, &total, &promedio);
				printf("\nPrecio total de pasajes: %.2f", total);
				printf("\nPromedio: %.2f\n", promedio);
				Passenger_getSuperiorPromedio(list, len, &promedio, listFlyCode);
				break;
			case 3:
				utn_getNumero(&order, "Orden:\n1. Ascendente\n2. Descendente\nSeleccione una opcion: ", "Error, intentelo de nuevo: ", 1, 2);
				if(order == 1)
				{
					printPassengersFlyCode(list, len, ASCENDENTE, listFlyCode, "Activo");
				}
				else
				{
					printPassengersFlyCode(list, len, DESCENDENTE, listFlyCode, "Activo");
				}
				break;
			default:
				printf("\nRegreso al menu principal!");
				break;
		}
		returnAux = 0;
	}
	return returnAux;
}

int Passenger_getPromedioVuelos(Passenger* list, int len, float* total, float* promedio)
{
	int returnAux;
	int cantPasajeros;
	returnAux = -1;
	cantPasajeros = 0;

	if(list != NULL && len > 0 && promedio != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				*total += list[i].price;
				cantPasajeros++;
			}
		}
		*promedio = *total / cantPasajeros;
		returnAux = 0;
	}
	return returnAux;
}

int Passenger_getSuperiorPromedio(Passenger* list, int len, float* promedio, FlyCode* listFlyCode)
{
	int returnAux;
	int contador;

	returnAux = -1;
	contador = 0;

	if(list != NULL && len > 0 && promedio != NULL && listFlyCode != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].price > *promedio)
			{
				contador++;
				printOnePassenger(list[i], listFlyCode);
			}
		}
		printf("\nCantidad de pasajeros que superan el promedio: %d", contador);
		returnAux = 0;
	}
	return returnAux;
}

int Passenger_CargaForzada(Passenger* list, int len)
{
	int returnAux;
	returnAux = -1;

	Passenger auxiliar[5] = {{1, "Joaquin", "Acosta", 500, 1, 1,FALSE},
							{2, "Lucas", "Perez", 1000, 1, 2,FALSE},
							{3, "Florencia", "Lagos", 750, 2, 3,FALSE},
							{4, "Aixa", "Gomez", 1500, 4, 1,FALSE},
							{5, "Marcos", "Gomez", 5000, 3, 1,FALSE}};

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < 5; i++)
		{
			list[i] = auxiliar[i];
		}
		returnAux = 0;
	}

	return returnAux;
}

void Passenger_FormatearString(char cadena[], int lenCadena, int opcion)
{
	for(int i = 0; i < lenCadena; i++)
	{
		if(opcion == TOUPPER)
		{
			cadena[i] = toupper(cadena[i]);
		}
		else
		{
			if(opcion == TOLOWER)
			{
				cadena[i] = tolower(cadena[i]);
			}
		}
	}
}

void Passenger_DarFormatoNombre(char cadena[], int lenCadena)
{
	Passenger_FormatearString(cadena, lenCadena, TOLOWER);

	for(int i = 0; i < lenCadena; i++)
	{
		if(i == 0)
		{
			cadena[i] = toupper(cadena[i]);
		}
		else
		{
			if(cadena[i] == ' ')
			{
				cadena[i + 1] = toupper(cadena[i + 1]);
			}
		}
	}
}

int Passenger_ValidarNombre(char* cadena, int len)
{
	int validacion;
	validacion = 1;

	for(int i = 0; i < len; i++)
	{
		if(esCaracter(cadena[i]) == 0)
		{
			validacion = 0;
			break;
		}
	}
	return validacion;
}
