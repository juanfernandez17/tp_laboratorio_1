/*
 	Input.c

	Fernandez Juan Ignacio 1ºB
	Trabajo practico Nº2
 */

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Input.h"

#define TOLOWER 0
#define TOUPPER 1

int utn_getNumero(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int retorno;
	int bufferInt;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		printf("%s", mensaje);
		__fpurge(stdin);
		scanf("%d", &bufferInt);
		while(bufferInt < minimo || bufferInt > maximo)
		{
			printf("%s", mensajeError);
			__fpurge(stdin);
			scanf("%d", &bufferInt);
		}
		*pResultado = bufferInt;
		retorno = 0;
	}
	else
	{
		printf("Error!!!");
	}
	return retorno;
}

int utn_getNumeroFloat(float *pResultado, char mensaje[], char mensajeError[], float minimo, float maximo)
{
	int retorno;
	float bufferFloat;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		printf("%s", mensaje);
		__fpurge(stdin);
		scanf("%f", &bufferFloat);
		while(bufferFloat < minimo || bufferFloat > maximo)
		{
			printf("%s", mensajeError);
			__fpurge(stdin);
			scanf("%f", &bufferFloat);
		}
		*pResultado = bufferFloat;
		retorno = 0;
	}
	else
	{
		printf("Error!!!");
	}
	return retorno;
}

int utn_getCaracter(char *pResultado, char mensaje[], char mensajeError[], char minimo, char maximo)
{
	int retorno;
	char bufferChar;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		printf("%s", mensaje);
		__fpurge(stdin);
		scanf("%c", &bufferChar);
		bufferChar = tolower(bufferChar);
		while(bufferChar < minimo || bufferChar > maximo)
		{
			printf("%s", mensajeError);
			__fpurge(stdin);
			scanf("%c", &bufferChar);
			bufferChar = tolower(bufferChar);
		}
		*pResultado = bufferChar;
		retorno = 0;
	}
	else
	{
		printf("Error!!!");
	}
	return retorno;
}

int utn_getString(char *pResultado, char mensaje[], char mensajeError[], int TAM, char minimo, char maximo)
{
	int retorno;
	char bufferString[TAM];
	int lenBufferString;
	int validarCadena;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		printf("%s", mensaje);
		__fpurge(stdin);
		scanf("%[^\n]", bufferString);
		lenBufferString = strlen(bufferString);
		validarCadena = utn_VerificarString(bufferString, lenBufferString, 'A', 'z');
		while(lenBufferString < 0 || lenBufferString >= TAM || validarCadena != 1)
		{
			printf("%s", mensajeError);
			__fpurge(stdin);
			scanf("%[^\n]", bufferString);
			lenBufferString = strlen(bufferString);
			validarCadena = utn_VerificarString(bufferString, lenBufferString, 'A', 'z');
		}
		strcpy(pResultado, bufferString);
		retorno = 0;
	}
	return retorno;
}

int utn_VerificarString(char cadena[], int lenCadena, char minimo, char maximo)
{
	int validez;
	int contadorEspacios;
	char charNoValidos[7] = {'[',']','\\','^','_','`'};

	validez = -1;
	contadorEspacios = 0;

	for(int i = 0; i < lenCadena; i++)
	{
		if(cadena[i] == ' ')
		{
			contadorEspacios++;
		}
		if(cadena[i] < minimo || cadena[i] > maximo || contadorEspacios > 1)
		{
			validez = -1;
		}
		else
		{
			for(int j = 0; j < 7; j++)
			{
				if(cadena[i] != charNoValidos[j])
				{
					validez = 1;
				}
			}
		}
	}
	return validez;
}

void utn_FormatearString(char cadena[], int lenCadena, int opcion)
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

void utn_DarFormatoCadena(char cadena[], int lenCadena)
{
	utn_FormatearString(cadena, lenCadena, TOLOWER);

	for(int i = 0; i < 102; i++)
	{
		if(i == 0)
		{
			cadena[i] = toupper(cadena[i]);
		;
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

int utn_ConfirmarAccion(char mensaje[], char mensajeError[])
{
	int confirmar;
	char confirmarAccion[3];
	confirmar = -1;

	utn_getString(confirmarAccion, mensaje, mensajeError, 3, 'A', 'z');
	utn_FormatearString(confirmarAccion, 3, TOLOWER);
	while(strcmp(confirmarAccion, "si") != 0 && strcmp(confirmarAccion, "no") != 0)
	{
		utn_getString(confirmarAccion, mensaje, mensajeError, 3, 'A', 'z');
		utn_FormatearString(confirmarAccion, 3, TOLOWER);
	}

	if(strcmp(confirmarAccion, "si") == 0)
	{
		confirmar = 1;
	}
	return confirmar;
}
