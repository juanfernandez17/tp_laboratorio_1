/*
	ArrayPassenger.c

	Fernàndez Juan Ignacio 1ºB
	Trabajo pràctico Nº2
*/

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayPassenger.h"
#include "ArrayFlyCode.h"
#include "Input.h"

#define TOLOWER 0
#define TOUPPER 1
#define TRUE 1
#define FALSE 2
#define TURISTA 1
#define PRIMERA_CLASE 2
#define EJECUTIVO 3
#define PREMUIM 4
#define ASCENDENTE 1
#define DESCENDENTE 0
#define TAM_F 50

static int idIncremental = 1;
static int ePassenger_ObtenerID(void);
static int ePassenger_ObtenerID()
{
	return idIncremental++;
}

int initPassengers(ePassenger arrayPassengers[], int lenPassengers)
{
	int retorno;
	retorno = -1;

	if(arrayPassengers != NULL && lenPassengers >= 0)
	{
		for(int i = 0; i < lenPassengers; i++)
		{
			arrayPassengers[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}


int AltaForzadaPasajeros(ePassenger arrayPassengers[], int lenPassengers)
{
	int retorno;
	retorno = -1;

	ePassenger auxiliarPassengers[5] = {{1100, "Joaquin", "Acosta", 500, "ABCD00100", EJECUTIVO, FALSE},
										{1101, "Lucas", "Perez", 650, "ABCD00101", EJECUTIVO, FALSE},
										{1102, "Florencia", "Lagos", 400, "ABCD00101", TURISTA, FALSE},
										{1103, "Aixa", "Medrano", 700, "ABCD00102", TURISTA, FALSE},
										{1104, "Marcos", "Gomez", 400, "ABCD00103", PRIMERA_CLASE, FALSE}};

	if(arrayPassengers != NULL && lenPassengers > 0)
	{
		for(int i = 0; i < 5; i++)
		{
			arrayPassengers[i] = auxiliarPassengers[i];
		}
		retorno = 0;
	}
	return retorno;
}

int findIsEmpty(ePassenger arrayPassengers[], int lenPassengers)
{
	int retorno;
	retorno = -1;

	if(arrayPassengers != NULL && lenPassengers > 0)
	{
		for(int i = 0; i < lenPassengers; i++)
		{
			if(arrayPassengers[i].isEmpty == TRUE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int addPassenger(ePassenger arrayPassengers[], int lenPassengers, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[])
{
	int retorno;
	int indexLibre;

	retorno = -1;
	indexLibre = findIsEmpty(arrayPassengers, lenPassengers);

	if(arrayPassengers != NULL && lenPassengers > 0)
	{
		if(indexLibre != -1)
		{
			arrayPassengers[indexLibre].id = id;
			strcpy(arrayPassengers[indexLibre].name, name);
			strcpy(arrayPassengers[indexLibre].lastName, lastName);
			arrayPassengers[indexLibre].price = price;
			arrayPassengers[indexLibre].typePassenger = typePassenger;
			strcpy(arrayPassengers[indexLibre].flycode, flyCode);
			arrayPassengers[indexLibre].isEmpty = FALSE;

			utn_DarFormatoCadena(arrayPassengers[indexLibre].name, 51);
			utn_DarFormatoCadena(arrayPassengers[indexLibre].lastName, 51);

			retorno = 0;
		}
	}
	return retorno;
}

int PedirDatos(ePassenger arrayPassengers[], int lenPassengers,eFlyCode arrayFlyCodes[], int lenFlyCodes)
{
	int retorno;
	int id;
	char name[51];
	char lastName[51];
	float price;
	int typePassenger;
	char flyCode[10];

	id = ePassenger_ObtenerID();
	utn_getString(name, "Nombre: ", "Error, nombre no valido. Intentelo de nuevo: ", 51, 'A', 'z');
	utn_getString(lastName, "Apellido: ", "Error, apellido no valido. Intentelo de nuevo: ", 51, 'A', 'z');
	utn_getNumeroFloat(&price, "Precio: ", "Error, precio fuera de rango. Intentelo de nuevo: ", 1, 10000);
	utn_getNumero(&typePassenger, "\n1. TURISTA\n2. PRIMERA CLASE\n3. EJECUTIVO\n4. PREMIUM\n\nTipo de pasajero: ",
									"Error, tipo de pasajero no valido. Intentelo de nuevo: ", 1, 4);
	printFlyCode(arrayFlyCodes, TAM_F);
	printf("\nTener en cuenta al ingresar el codigo de vuelo: el mismo es alfanumerico y debe contar con 9 caracteres.\n");
	PedirFlyCode(flyCode, "Ingresar codigo de vuelo: ", "Error, codigo de vuelo no valido. Intentelo de nuevo: ");
	retorno = findFlyCode(arrayFlyCodes, lenFlyCodes, flyCode);

	while(retorno != 0)
	{
		printf("\nCodigo de vuelo no encontrado. Intentelo de nuevo: ");
		PedirFlyCode(flyCode, "Ingresar codigo de vuelo: ", "Error, codigo de vuelo no valido. Intentelo de nuevo: ");
		retorno = findFlyCode(arrayFlyCodes, lenFlyCodes, flyCode);
	}

	retorno = addPassenger(arrayPassengers, lenPassengers, id, name, lastName, price, typePassenger, flyCode);

	return retorno;
}

int findPassengerById(ePassenger arrayPassengers[], int lenPassengers, int id)
{
	int find;
	find = -1;

	if(arrayPassengers != NULL && lenPassengers > 0)
	{
		for(int i = 0; i < lenPassengers; i++)
		{
			if(arrayPassengers[i].isEmpty == FALSE && arrayPassengers[i].id == id)
			{
				find = i;
			}
		}
	}
	return find;
}

int removePassengerById(ePassenger arrayPassengers[], int lenPassengers, int id)
{
	int remove;
	int find;
	int confirmarEliminacion;

	remove = -1;

	if(arrayPassengers != NULL && lenPassengers > 0)
	{
		find = findPassengerById(arrayPassengers, lenPassengers, id);
		if(find != -1)
		{
			for(int i = 0; i < lenPassengers; i++)
			{
				if(arrayPassengers[i].isEmpty == FALSE && arrayPassengers[i].id == id)
				{
					PrintOnePassenger(arrayPassengers[i]);
					confirmarEliminacion = utn_ConfirmarAccion("\n\n¿Quiere eliminar a este pasajero? (si/no)\n", "Error, opcion no valida. Intentelo de nuevo (si/no)\n");
					if(confirmarEliminacion == 1)
					{
						arrayPassengers[i].isEmpty = TRUE;
						remove = 0;
					}
					else
					{
						remove = 1;
					}
				}
			}
		}
	}
	return remove;
}

int modifyPassenger(ePassenger arrayPassengers[], int lenPassengers, eFlyCode arrayFlyCodes[], int lenFlyCodes,int id)
{
	int modify;
	int find;
	modify = -1;

	if(arrayPassengers != NULL && lenPassengers > 0)
	{
		find = findPassengerById(arrayPassengers, lenPassengers, id);
		if(find != -1)
		{
			for(int i = 0; i < lenPassengers; i++)
			{
				if(arrayPassengers[i].isEmpty == FALSE && arrayPassengers[i].id == id)
				{
					PrintOnePassenger(arrayPassengers[i]);
					modify = modifyMenu(arrayPassengers[i], arrayFlyCodes, lenFlyCodes);
				}
			}
		}
	}
	return modify;
}

int modifyMenu(ePassenger passenger, eFlyCode arrayFlyCodes[], int lenFlyCodes)
{
	int modify;
	char newName[51];
	char newLastName[51];
	float newPrice;
	int newTypePassenger;
	char newFlyCode[10];
	int confirmarModificacion;
	int opcion;

	modify = 1;

	do
	{
		printf("\n\nOpciones para modificar\n:\n1. Nombre\n2. Apellido\n3. Precio\n4. Tipo de pasajero\n5. Codigo de vuelo\n6. Salir");
		utn_getNumero(&opcion, "\nSeleccione que campo quiere modificar: ", "Error, opcion ingresada no valida. Intentelo de nuevo: ", 1, 6);

		switch(opcion)
		{
			case 1:
				utn_getString(newName, "Nuevo nombre: ", "Error, nombre no valido. Intentelo de nuevo: ", 51, 'A', 'z');
				confirmarModificacion = utn_ConfirmarAccion("¿Conservar cambios? si/no", "Error, opcion no valida. Intentelo de nuevo (si/no): ");
				if(confirmarModificacion == 1)
				{
					strcpy(passenger.name, newName);
					modify = 0;
				}
				break;
			case 2:
				utn_getString(newLastName, "Nuevo apellido: ", "Error, apellido no valido. Intentelo de nuevo: ", 51, 'A', 'z');
				confirmarModificacion = utn_ConfirmarAccion("¿Conservar cambios? si/no", "Error, opcion no valida. Intentelo de nuevo (si/no): ");
				if(confirmarModificacion == 1)
				{
					strcpy(passenger.lastName, newLastName);
					modify = 0;
				}
				break;
			case 3:
				utn_getNumeroFloat(&newPrice, "Nuevo precio: ", "Error, precio fuera de rango. Intentelo de nuevo: ", 1, 10000);
				confirmarModificacion = utn_ConfirmarAccion("¿Conservar cambios? si/no", "Error, opcion no valida. Intentelo de nuevo (si/no): ");
				if(confirmarModificacion == 1)
				{
					passenger.price = newPrice;
					modify = 0;
				}
				break;
			case 4:
				utn_getNumero(&newTypePassenger, "\n1. TURISTA\n2. PRIMERA CLASE\n3. EJECUTIVO\n4. PREMIUM\n\nTipo de pasajero: ",
																"Error, tipo de pasajero no valido. Intentelo de nuevo: ", 1, 4);
				confirmarModificacion = utn_ConfirmarAccion("¿Conservar cambios? si/no", "Error, opcion no valida. Intentelo de nuevo (si/no): ");
				if(confirmarModificacion == 1)
				{
					passenger.typePassenger = newTypePassenger;
					modify = 0;
				}
				break;
			case 5:
				PedirFlyCode(newFlyCode, "Ingresar codigo de vuelo: ", "Error, codigo de vuelo no valido. Intentelo de nuevo: ");
				confirmarModificacion = utn_ConfirmarAccion("¿Conservar cambios? si/no", "Error, opcion no valida. Intentelo de nuevo (si/no): ");
				if(confirmarModificacion == 1)
				{
					strcpy(passenger.flycode, newFlyCode);
					modify = 0;
				}
				break;
			default:
				printf("\nSalida del menu de modificaciones!");
				break;
		}
	} while(opcion != 6);
	return modify;
}


int sortPassengers(ePassenger arrayPassengers[], int lenPassengers, int order)
{
	int error;
	error = -1;
	if(arrayPassengers != NULL && lenPassengers > 0)
	{
		error = 0;
		for(int i = 0; i < lenPassengers; i++)
		{
			utn_DarFormatoCadena(arrayPassengers[i].name, 51);
			utn_DarFormatoCadena(arrayPassengers[i].lastName, 51);
		}

		if(order == ASCENDENTE)
		{
			ordenAscendente(arrayPassengers, lenPassengers);
		}
		else
		{
			if(order == DESCENDENTE)
			{
				ordenDescendente(arrayPassengers, lenPassengers);
			}
		}
	}
	return error;
}

void ordenAscendente(ePassenger arrayPassengers[], int lenPassengers)
{
	ePassenger auxiliar;

	for(int i = 0; i < lenPassengers - 1; i++)
	{
		if(arrayPassengers[i].isEmpty == FALSE)
		{
			for(int j = i + 1; j < lenPassengers; j++)
			{
				if(strcmp(arrayPassengers[i].lastName, arrayPassengers[j].lastName) > 0)
				{
					auxiliar = arrayPassengers[i];
					arrayPassengers[i] = arrayPassengers[j];
					arrayPassengers[j] = auxiliar;
				}
				else
				{
					if(strcmp(arrayPassengers[i].lastName, arrayPassengers[j].lastName) == 0)
					{
						if(arrayPassengers[i].typePassenger > arrayPassengers[j].typePassenger)
						{
							auxiliar = arrayPassengers[i];
							arrayPassengers[i] = arrayPassengers[j];
							arrayPassengers[j] = auxiliar;
						}
					}
				}
			}
		}
	}
}

void ordenDescendente(ePassenger arrayPassengers[], int lenPassengers)
{
	ePassenger auxiliar;

	for(int i = 0; i < lenPassengers - 1; i++)
	{
		if(arrayPassengers[i].isEmpty == FALSE)
		{
			for(int j = i + 1; j < lenPassengers; j++)
			{
				if(strcmp(arrayPassengers[i].lastName, arrayPassengers[j].lastName) < 0)
				{
					auxiliar = arrayPassengers[i];
					arrayPassengers[i] = arrayPassengers[j];
					arrayPassengers[j] = auxiliar;
				}
				else
				{
					if(strcmp(arrayPassengers[i].lastName, arrayPassengers[j].lastName) == 0)
					{
						if(arrayPassengers[i].typePassenger < arrayPassengers[j].typePassenger)
						{
							auxiliar = arrayPassengers[i];
							arrayPassengers[i] = arrayPassengers[j];
							arrayPassengers[j] = auxiliar;
						}
					}
				}
			}
		}
	}
}

void PrintOnePassenger(ePassenger Pasajero)
{
	printf("\nID: %d | %s, %s | Price: %.2f | Fly code: %s | Type passenger: %d", Pasajero.id, Pasajero.lastName, Pasajero.name,
	Pasajero.price, Pasajero.flycode, Pasajero.typePassenger);
}

int printPassengers(ePassenger arrayPassengers[], int lenPassengers, eFlyCode arrayFlyCodes[], int lenFlyCodes)
{
	int error;
	error = -1;

	if(arrayPassengers != NULL && lenPassengers > 0)
	{
		error = 0;
		for(int i = 0; i < lenFlyCodes; i++)
		{
			for(int j = 0; j < lenPassengers; j++)
			{
				if(arrayPassengers[j].isEmpty == FALSE && arrayFlyCodes[i].isEmpty == FALSE)
				{
					if(strcmp(arrayFlyCodes[i].flyCode, arrayPassengers[j].flycode) == 0)
					{
						printf("\nID: %d | %s, %s | Price: %.2f | Fly code: %s | Type passenger: %d | Status flight: %d",
						arrayPassengers[j].id, arrayPassengers[j].lastName, arrayPassengers[j].name, arrayPassengers[j].price, arrayPassengers[j].flycode ,arrayPassengers[j].typePassenger, arrayFlyCodes[i].statusFlight);
					}
				}
			}
		}
	}
	return error;
}



int sortPassengersByCode(ePassenger arrayPassengers[], int lenPassengers, int order, eFlyCode arrayFlyCodes[], int lenFlyCodes)
{
	int error;
	ePassenger auxiliar;
	error = -1;

	if(arrayPassengers != NULL && lenPassengers > 0 && arrayFlyCodes != NULL && lenFlyCodes > 0)
	{
		error = 0;

		for(int i = 0; i < lenPassengers - 1; i++)
		{
			if(arrayPassengers[i].isEmpty == FALSE)
			{
				for(int j = i + 1; j < lenPassengers; j++)
				{
					if(order == ASCENDENTE)
					{
						if(strcmp(arrayPassengers[i].flycode, arrayPassengers[j].flycode) > 0)
						{
							auxiliar = arrayPassengers[i];
							arrayPassengers[i] = arrayPassengers[j];
							arrayPassengers[j] = auxiliar;
						}
						else
						{
							if(strcmp(arrayPassengers[i].flycode, arrayPassengers[j].flycode) == 0)
							{
								if(arrayFlyCodes[i].statusFlight > arrayFlyCodes[j].statusFlight)
								{
									auxiliar = arrayPassengers[i];
									arrayPassengers[i] = arrayPassengers[j];
									arrayPassengers[j] = auxiliar;
								}

							}
						}
					}
					else
					{
						if(order == DESCENDENTE)
						{
							if(strcmp(arrayPassengers[i].flycode, arrayPassengers[j].flycode) < 0)
							{
								auxiliar = arrayPassengers[i];
								arrayPassengers[i] = arrayPassengers[j];
								arrayPassengers[j] = auxiliar;
							}
							else
							{
								if(strcmp(arrayPassengers[i].flycode, arrayPassengers[j].flycode) == 0)
								{
									if(arrayFlyCodes[i].statusFlight < arrayFlyCodes[j].statusFlight)
									{
										auxiliar = arrayPassengers[i];
										arrayPassengers[i] = arrayPassengers[j];
										arrayPassengers[j] = auxiliar;
									}

								}
							}
						}
					}
				}
			}
		}
	}
	return error;
}

float PromedioVuelos(ePassenger arrayPassengers[], int lenPassengers)
{
	float acumuladorPrecios;
	int contadorPasajeros;
	float promedio;

	contadorPasajeros = 0;

	for(int i = 0; i < lenPassengers; i++)
	{
		if(arrayPassengers[i].isEmpty == FALSE)
		{
			acumuladorPrecios += arrayPassengers[i].price;
			contadorPasajeros++;
		}
	}
	promedio = CalcularPromedio(acumuladorPrecios, contadorPasajeros);
	printf("\nSuma de todos los precios: %.2f\n", acumuladorPrecios);
	printf("\nPromedio de precios de los pasajes: %.2f", promedio);

	return promedio;
}

int SuperiorAlPromedio(ePassenger arrayPassengers[], int lenPassengers, float promedio)
{
	int contador;

	contador = 0;

	for(int i = 0; i < lenPassengers; i++)
	{
		if(arrayPassengers[i].price > promedio)
		{
			contador++;
		}
	}
	return contador;
}

float CalcularPromedio(float acumulador, int contador)
{
	float resultado;

	resultado = acumulador / contador;

	return resultado;
}
