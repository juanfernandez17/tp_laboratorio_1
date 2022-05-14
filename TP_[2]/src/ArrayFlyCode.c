/*
	ArrayFlyCode.c

	Fernàndez Juan Ignacio 1ºB
	Trabajo pràctico Nº2
*/

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayFlyCode.h"
#include "Input.h"

#define TRUE 1
#define FALSE 2
#define PEPE 3
#define ACTIVO 1
#define CANCELADO 2
#define DEMORADO 3
#define TOLOWER 0
#define TOUPPER 1
#define ASCENDENTE 1
#define DESCENDENTE 0


int initFlyCode(eFlyCode arrayFlyCodes[], int lenFlyCodes)
{
	int error;

	error = -1;

	if(arrayFlyCodes != NULL && lenFlyCodes >= 0)
	{
		error = 0;

		for(int i = 0; i < lenFlyCodes; i ++)
		{
			arrayFlyCodes[i].isEmpty = TRUE;
		}
	}
	return error;
}

int AltaForzadaCodigos(eFlyCode arrayFlyCodes[], int lenFlyCodes)
{
	int retorno;
	retorno = -1;

	eFlyCode auxiliarFlyCodes[4] = {{"ABCD00100", ACTIVO, FALSE},{"ABCD00101", CANCELADO, FALSE},{"ABCD00103", DEMORADO, FALSE}, {"ABCD00104", ACTIVO, FALSE}};

	if(arrayFlyCodes != NULL && lenFlyCodes >= 0)
	{
		for(int i = 0; i < 4; i++)
		{
			arrayFlyCodes[i] = auxiliarFlyCodes[i];
		}
		retorno = 0;
	}
	return retorno;
}

int findFlyCode(eFlyCode arrayFlyCodes[], int lenFlyCodes, char flyCode[])
{
	int retorno;
	retorno = -1;

	for(int i = 0; i < lenFlyCodes; i++)
	{
		if(strcmp(arrayFlyCodes[i].flyCode, flyCode) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}

void printOneFlyCode(eFlyCode flyCode)
{
	printf("\nCodigo: %s | Estado: %d\n", flyCode.flyCode, flyCode.statusFlight);
}

int printFlyCode(eFlyCode arrayFlyCodes[], int lenFlyCodes)
{
	int error;

	error = -1;
	if(arrayFlyCodes != NULL && lenFlyCodes >= 0)
	{
		error = 0;
		for(int i = 0; i < lenFlyCodes; i++)
		{
			if(arrayFlyCodes[i].isEmpty == FALSE)
			{
				printOneFlyCode(arrayFlyCodes[i]);
			}
		}
	}
	return error;
}

int findIsEmptyFlyCode(eFlyCode arrayFlyCodes[], int lenFlyCodes)
{
	int retorno;
	retorno = -1;
	if(arrayFlyCodes != NULL && lenFlyCodes > 0)
	{
		for(int i = 0; i < lenFlyCodes; i++)
		{
			if(arrayFlyCodes[i].isEmpty == TRUE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int AltaFlyCode(eFlyCode arrayFlyCodes[], int lenFlyCodes)
{
	int error;
	int indexLibre;
	int existe;
	eFlyCode auxiliar;

	existe = -1;
	error = -1;

	if(arrayFlyCodes != NULL && lenFlyCodes > 0)
	{
		error = 0;
		indexLibre = findIsEmptyFlyCode(arrayFlyCodes, lenFlyCodes);
		if(indexLibre != -1)
		{
			PedirFlyCode(auxiliar.flyCode, "\nIngrese el nuevo codigo de vuelo: ", "Error, codigo de vuelo no valido. Intentelo de nuevo: ");
			existe = findFlyCode(arrayFlyCodes, lenFlyCodes, auxiliar.flyCode);

			if(existe == 0)
			{
				printf("\nEl codigo ingresado ya existe en el sistema.");
				error = -1;
				return error;
			}
			else
			{
				arrayFlyCodes[indexLibre] = auxiliar;
				printf("\nEstados:\n1. ACTIVO\n2. CANCELADO\n3. DEMORADO\n");
				utn_getNumero(&arrayFlyCodes[indexLibre].statusFlight, "Ingrese el estado de vuelo: ", "Error, opcion no valida. Intentelo de nuevo: ", 1, 3);
				arrayFlyCodes[indexLibre].isEmpty = FALSE;
			}
		}
		else
		{
			printf("\nNo hay mas espacio para ingresar nuevos vuelos.");
		}
	}
	return error;
}

void PedirFlyCode(char newFlyCode[], char mensaje[], char mensajeError[])
{
	int error;

	printf("%s", mensaje);
	__fpurge(stdin);
	scanf("%s", newFlyCode);

	error = VerificarFlyCode(newFlyCode, 'a', 'z');

	while(error != 0)
	{
		printf("%s", mensajeError);
		__fpurge(stdin);
		scanf("%s", newFlyCode);
		error = VerificarFlyCode(newFlyCode, 'a', 'z');
	}

}

int VerificarFlyCode(char newFlyCode[], char minimo , char maximo)
{
	int error;
	int lenFlyCode;

	char arrayNumeros[10] = {'0','1','2','3','4','5','6','7','8','9'};

	error = 0;
	lenFlyCode = strlen(newFlyCode);

	if(lenFlyCode != 9)
	{
		error = -1;
	}
	else
	{
		for(int i = 0; i < lenFlyCode; i++)
		{
			if(newFlyCode[i] < minimo || newFlyCode[i] > maximo)
			{
				error = -1;
			}
			for(int j = 0; j < 10; j++)
			{
				if(newFlyCode[i] == arrayNumeros[j])
				{
					error = 0;
				}
			}
		}
	}
	return error;
}
