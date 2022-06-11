/*
 * TypePassenger.c
 *
 *  Created on: 8 jun. 2022
 *      Author: juan
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "TypePassenger.h"
#include "utn.h"

int TypePassenger_init(TypePassenger* arrayTypePassenger, int lenTypePassenger)
{
	int error;
	error = -1;
	TypePassenger auxiliar[3] = {{1, "EconomyClass"},{2, "FirstClass"},{3, "ExecutiveClass"}};

	if(arrayTypePassenger != NULL && lenTypePassenger > 0)
	{
		for(int i = 0; i < lenTypePassenger; i++)
		{
			arrayTypePassenger[i] = auxiliar[i];
		}
		error = 1;
	}
	return error;
}

void TypePassenger_printOne(TypePassenger tipoPasajero)
{
	printf("%d. %s\n", tipoPasajero.id, tipoPasajero.descripcion);
}

int TypePassenger_printLista(TypePassenger* arrayTypePassenger, int lenTypePassenger)
{
	int error;
	error = -1;

	if(arrayTypePassenger != NULL && lenTypePassenger > 0)
	{
		printf("\nLista de tipos de pasajero:\n\n");
		for(int i = 0; i < lenTypePassenger; i++)
		{
			TypePassenger_printOne(*(arrayTypePassenger + i));
		}
		error = 1;
	}
	return error;
}

int TypePassenger_ReturnTypePassenger(char* typePassenger)
{
	int tipoPasajero;
	char tipoPasajeroCaracter[20];

	strcpy(tipoPasajeroCaracter, typePassenger);

	if(strcmp(tipoPasajeroCaracter, "EconomyClass") == 0)
	{
		tipoPasajero = 1;
	}
	else
	{
		if(strcmp(tipoPasajeroCaracter, "FirstClass") == 0)
		{
			tipoPasajero = 2;
		}
		else
		{
			if(strcmp(tipoPasajeroCaracter, "ExecutiveClass") == 0)
			{
				tipoPasajero = 3;
			}
		}
	}
	return tipoPasajero;
}

int TypePassenger_ReemplazarIntPorString(char* typePassengerStr, int typePassenger)
{
	int error;
	error = -1;

	if(typePassengerStr != NULL && typePassenger >= 0)
	{
		switch(typePassenger)
		{
			case 1:
				strcpy(typePassengerStr, "EconomyClass");
				break;
			case 2:
				strcpy(typePassengerStr, "FirstClass");
				break;
			case 3:
				strcpy(typePassengerStr, "ExecutiveClass");
				break;
		}
	}
	return error;
}
