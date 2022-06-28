/*
 	 utn.c

 	 Fernandez Juan Ignacio 1ºB
 	 Biblioteca utn
 */

#include "utn.h"

/// @brief Lee de stdin hasta encontrar un '\n' o hasta que haya copiado en cadena un maximo de 'longitud - 1' caracteres.
///
/// @param char* Puntero al espacio de memoria donde se guardara la cadena obtenida
/// @param int lenCadena Longitud de la cadena
/// @return Retorna [0] en caso de obtener un cadena - Retorna [-1] en caso de error (no obtener una cadena)
static int myGets(char* cadena, int longitud);

/// @brief Obtiene una cadena ingresada por el usuario y en caso de que todos sus caracteres sean numeros (se comprueba con otra funcion) transforma esa cadena
/// 		a un dato de tipo int el cual sera asignado a el puntero que recibe como parametro.
///
/// @param int pResultado Puntero al espacio de memoria donde se guardara el numero ingresado por el usuario si es que todos sus caracteres son numeros
/// @return int Retorna [0] en caso de obtener un numeo entero - Retorna [-1] en caso de error, no poder obtener un numero entero
static int getInt(int* pResultado);

/// @brief Verifica que la cadena ingresada es un flotante
///
/// @param int pResultado Punto al espacio de memoria donde se guardara el resultado de la funcion
/// @return int Retorna [0] en caso de obtener un numero flotante - Retorna [-1] en caso de error, no poder obtener un numero flotante
static int getFloat(float* pResultado);

static int myGets(char* cadena, int longitud)
{
	int retorno;
	char bufferString[500];

	retorno = -1;

	if(cadena != NULL && longitud > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

static int getInt(int* pResultado)
{
	int retorno;
	char bufferString[64];

	retorno = -1;

	if( pResultado != NULL && !myGets(bufferString, sizeof(bufferString)) && esNumerica(bufferString, sizeof(bufferString)) == 1)
	{
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}

int esNumerica(char* cadena, int limite)
{
	int retorno;
	int i;
	int lenCadena;

	lenCadena = strlen(cadena);
	retorno = -1;

	if(cadena != NULL && limite > 0 && lenCadena != 0) // lenCadena != 0 sirve por si presiona enter sin antes haber ingreado un numero, salta error
	{
		retorno = 1;
		for(i = 0; i < limite; i++)
		{
			if(cadena[i] != '\0')
			{
				if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
				{
					continue;
				}
				if(cadena[i] < '0' || cadena[i] > '9')
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int utn_getNumeroConIntentos(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	int bufferInt;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		} while(reintentos >= 0);
	}
	return retorno;
}

int utn_getNumero(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo)
{
	int retorno;
	int bufferInt;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		printf("%s", mensaje);
		while(getInt(&bufferInt) != 0 || bufferInt < minimo || bufferInt > maximo)
		{
			printf("%s", mensajeError);
		}
		*pResultado = bufferInt;
		retorno = 0;
	}
	return retorno;
}

int esFlotante(char* cadena, int limite)
{
	int retorno;
	int i;
	int lenCadena;
	int contadorPuntos;

	retorno = -1;
	lenCadena = strlen(cadena);
	contadorPuntos = 0;

	if(cadena != NULL && limite > 0 && lenCadena != 0)
	{
		retorno = 1;
		for(i = 0; i < limite; i++)
		{
			if(cadena[i] != '\0')
			{
				if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
				{
					continue;
				}
				if(cadena[i] < '0' || cadena[i] > '9')
				{
					if(cadena[i] == '.' && contadorPuntos == 0)
					{
						contadorPuntos++;
					}
					else
					{
						retorno = 0;
						break;
					}
				}
			}
		}
	}
	return retorno;
}

static int getFloat(float* pResultado)
{
	int retorno;
	char bufferString[64];

	retorno = -1;

	if(pResultado != NULL && !myGets(bufferString, sizeof(bufferString)) && esFlotante(bufferString, sizeof(bufferString)) == 1)
	{
		retorno = 0;
		*pResultado = atof(bufferString);
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
		while(getFloat(&bufferFloat) != 0 || bufferFloat < minimo || bufferFloat > maximo)
		{
			printf("%s", mensajeError);
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

int esCaracter(char caracter)
{
	int retorno;
	char caracteresNoValidos[7] = {'[','\\',']','`','^','_'};

	retorno = 1;

	if(caracter < 'A' || caracter > 'z')
	{
		retorno = 0;
		for(int i = 0; i < 6; i++)
		{
			if(caracter == caracteresNoValidos[i])
			{
				retorno = 0;
				break;
			}
		}
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
		myGets(&bufferChar, sizeof(bufferChar));
		while(!esCaracter(bufferChar) || bufferChar < minimo || bufferChar > maximo)
		{
			printf("%s", mensajeError);
			myGets(&bufferChar, sizeof(bufferChar));
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

int utn_getString(char *pResultado, char mensaje[], char mensajeError[], int TAM)
{
	int retorno;
	char bufferString[TAM];
	int lenBufferString;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL)
	{
		printf("%s", mensaje);
		myGets(bufferString, sizeof(bufferString));
		lenBufferString = strlen(bufferString);
		while(lenBufferString >= TAM || lenBufferString == 0)
		{
			printf("%s", mensajeError);
			myGets(bufferString, sizeof(bufferString));
			lenBufferString = strlen(bufferString);
		}
		strcpy(pResultado, bufferString);
		retorno = 0;
	}
	return retorno;
}


int utn_ConfirmarAccion(char mensaje[], char mensajeError[])
{
	int confirmar;
	char confirmarAccion[3];
	confirmar = 0;

	utn_getString(confirmarAccion, mensaje, mensajeError, 3);
	for(int i = 0; i < 2; i++)
	{
		confirmarAccion[i] = tolower(confirmarAccion[i]);
	}
	while(strcmp(confirmarAccion, "si") != 0 && strcmp(confirmarAccion, "no") != 0)
	{
		utn_getString(confirmarAccion, mensaje, mensajeError, 3);
	}
	if(strcmp(confirmarAccion, "si") == 0)
	{
		confirmar = 1;
	}
	return confirmar;
}


