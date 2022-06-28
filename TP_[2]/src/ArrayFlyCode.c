/*
 * ArrayFlyCode.c
 *
 *  Created on: 25 jun. 2022
 *      Author: juan
 */

#include "ArrayFlyCode.h"
#include "utn.h"
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int FlyCode_init(FlyCode* list, int len)
{
	int returnAux;
	returnAux = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].isEmpty = TRUE;
		}
		returnAux = 0;
	}
	return returnAux;
}

int FlyCode_CargaForzada(FlyCode* list, int len)
{
	int returnAux;
	FlyCode auxiliarList[4] = {	{1,"ABCD00101", "Activo", FALSE},{2,"ABCD00102", "Demorado", FALSE},
								{3,"ABCD00103", "Aterrizado", FALSE},{4,"ABCD00104", "Cancelado", FALSE}};;
	if(list != NULL && len > 0)
	{
		for(int i = 0; i < 4; i++)
		{
			list[i] = auxiliarList[i];
		}
		returnAux = -1;
	}
	return returnAux;
}

void FlyCode_printOne(FlyCode codigoVuelo)
{
	printf("\n%d. %s | %s", codigoVuelo.idFlyCode, codigoVuelo.codigoVueloStr, codigoVuelo.estadoVueloStr);
}

int FlyCode_printFlyCodes(FlyCode* list, int len)
{
	int returnAux;
	returnAux = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				FlyCode_printOne(list[i]);
			}
		}
		returnAux = 0;
	}
	return returnAux;
}

int FlyCode_findIsEmpty(FlyCode* list, int len)
{
	int returnAux;
	returnAux = -1;

	if(list != NULL && len > 0)
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

int addFlyCode(FlyCode* list, int len, int* lastId)
{
	int returnAux;
	int indice;
	char newFlyCode[50];
	int estadoVuelo;
	char estadoVueloStr[50];
	returnAux = -1;

	if(list != NULL && len > 0 && lastId != NULL)
	{
		indice = FlyCode_findIsEmpty(list, len);

		if(indice != -1)
		{
			*lastId = *lastId + 1;
			getNewFlyCode(newFlyCode, "Ingresar nuevo codigo de vuelo (Tener en cuenta: debe ser un codigo de 9 caracteres): ", "Error, codigo invalido. Intentelo de nuevo: ");
			strcpy(list[indice].codigoVueloStr, newFlyCode);
			list[indice].idFlyCode = *lastId;
			utn_getNumero(&estadoVuelo, "**** Estados de vuelo ****\n"
					"1. Activo\n2. Demorado\n3. Aterrizado\n4. Cancelado\n\n"
					"Seleccione el estado de vuelo: ", "Error, intentelo de nuevo: ", 1, 4);
			getStatusFlightStr(estadoVuelo, estadoVueloStr);
			strcpy(list[indice].estadoVueloStr, estadoVueloStr);
			list[indice].isEmpty = FALSE;
			returnAux = 0;
		}
	}
	return returnAux;
}

int getStatusFlightStr(int idEstadoVuelo, char* estadoVueloStr)
{
	int returnAux;
	returnAux = -1;

	if(idEstadoVuelo > 0 && estadoVueloStr != NULL)
	{
		switch(idEstadoVuelo)
		{
			case 1:
				strcpy(estadoVueloStr, "Activo");
				break;
			case 2:
				strcpy(estadoVueloStr, "Demorado");
				break;
			case 3:
				strcpy(estadoVueloStr, "Aterrizado");
				break;
			default:
				strcpy(estadoVueloStr, "Cancelado");
				break;
		}
		returnAux = 0;
	}
	return returnAux;
}

int getNewFlyCode(char* newFlyCode, char mensaje[], char mensajeError[])
{
	int validacion;
	validacion = -1;

	printf("\n%s", mensaje);
	__fpurge(stdin);
	scanf("%s", newFlyCode);

	validacion = VerificarFlyCode(newFlyCode, 'a', 'z');

	while(validacion != 1)
	{
		printf("\n%s", mensajeError);
		__fpurge(stdin);
		scanf("%s", newFlyCode);
		validacion = VerificarFlyCode(newFlyCode, 'a', 'z');
	}
	return validacion;
}

int VerificarFlyCode(char newFlyCode[], char minimo, char maximo)
{
	int validacion;
	int lenFlyCode;
	char arrayNumeros[10] = {'0', '1','2', '3', '4', '5', '6', '7', '8', '9'};

	validacion = 1;
	lenFlyCode = strlen(newFlyCode);

	if(lenFlyCode != 9)
	{
		validacion = -1;
	}
	else
	{
		for(int i = 0; i < lenFlyCode; i++)
		{
			if(esCaracter(newFlyCode[i]) == 0)
			{
				validacion = -1;
			}
			for(int j = 0; j < 10; j++)
			{
				if(newFlyCode[i] == arrayNumeros[j])

				{
					validacion = 1;
				}
			}
		}
	}
	return validacion;
}

