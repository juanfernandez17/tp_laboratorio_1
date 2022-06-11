/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "utn.h"

#define TOLOWER 0
#define TOUPPER 1

Passenger* Passenger_new()
{
	Passenger* unPasajero;
	unPasajero = (Passenger*) malloc(sizeof(Passenger)*1);

	if(unPasajero != NULL)
	{
		unPasajero->id = 0;
		strcpy(unPasajero->nombre, "\0");
		strcpy(unPasajero->apellido, "\0");
		unPasajero->precio = 0;
		unPasajero->tipoPasajero = 0;
		strcpy(unPasajero->idFlyCode, "\0");
	}
	return unPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr)
{
	Passenger* unPasajero;
	int id;
	char nombre[20];
	char apellido[20];
	float precio;
	int tipoPasajero;
	char codigoVuelo[20];

	unPasajero = Passenger_new();

	if(unPasajero != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL)
	{
		id = atoi(idStr);
		strcpy(nombre, nombreStr);
		strcpy(apellido, apellidoStr);
		precio = atof(precioStr);
		tipoPasajero = TypePassenger_ReturnTypePassenger(tipoPasajeroStr);
		strcpy(codigoVuelo, codigoVueloStr);


		if(!Passenger_SetterGeneral(unPasajero, id, nombre, apellido, precio, tipoPasajero, codigoVuelo))
		{
			Passenger_delete(unPasajero);
		}
	}
	return unPasajero;
}

int Passenger_delete(Passenger* this)
{
	int error;
	error = -1;

	if(this != NULL)
	{
		free(this);
		error = 1;
	}
	return error;
}

int Passenger_setId(Passenger* this,int id)
{
	int error;
	error = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		error = 1;
	}
	return error;
}

int Passenger_getId(Passenger* this,int* id)
{
	int error;
	error = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		error = 1;
	}
	return error;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int error;
	error = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		error = 1;
	}
	return error;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int error;
	error = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		error = 1;
	}
	return error;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int error;
	error = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		error = 1;
	}
	return error;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int error;
	error = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		error = 1;
	}
	return error;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int error;
	error = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->idFlyCode, codigoVuelo);
		error = 1;
	}
	return error;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int error;
	error = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->idFlyCode);
		error = 1;
	}
	return error;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int error;
	error = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		error = 1;
	}
	return error;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int error;
	error = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		error = 1;
	}
	return error;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int error;
	error = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		error = 1;
	}
	return error;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int error;
	error = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		error = 1;
	}
	return error;
}

int Passenger_SetterGeneral(Passenger* this, int id, char* nombre, char* apellido, float precio, int tipoPasajero, char* codigoVuelo)
{
	int error;
	error = -1;

	if(this != NULL && id > 0 && nombre != NULL && apellido != NULL && precio > 0 && tipoPasajero >= 0 && codigoVuelo != NULL)
	{
		if(	Passenger_setId(this, id) && Passenger_setNombre(this, nombre) &&
			Passenger_setApellido(this, apellido) && Passenger_setPrecio(this, precio) &&
			Passenger_setTipoPasajero(this, tipoPasajero) && Passenger_setCodigoVuelo(this, codigoVuelo))
		{
			error = 1;
		}
	}
	return error;
}

int Passenger_GetterGeneral(Passenger* this, int* id, char* nombre, char* apellido, float* precio, int* tipoPasajero, char* codigoVuelo)
{
	int error;
	error = -1;

	if(this != NULL && id != NULL && nombre != NULL && apellido != NULL && precio != NULL && tipoPasajero != NULL && codigoVuelo != NULL)
	{
		if(	Passenger_getId(this, id) && Passenger_getPrecio(this, precio) &&
			Passenger_getNombre(this, nombre) && Passenger_getApellido(this, apellido) &&
			Passenger_getCodigoVuelo(this, codigoVuelo) && Passenger_getTipoPasajero(this, tipoPasajero))
		{
			error = 1;
		}
	}
	return error;
}

int Passenger_PrintOne(Passenger* unPasajero, TypePassenger* listaTiposPasajeros, int lenTiposPasajeros, FlyCode* listaFlyCodes, int lenFlyCodes)
{
	int error;
	int id;
	char nombre[20];
	char apellido[20];
	float precio;
	int tipoPasajero;
	char codigoVuelo[20];
	int indiceFlyCode;
	int indiceTypePassenger;
	error = -1;

	if(unPasajero != NULL && Passenger_GetterGeneral(unPasajero, &id, nombre, apellido, &precio, &tipoPasajero, codigoVuelo))
	{
		error = 1;
		indiceFlyCode = Passenger_MatchFlyCode(unPasajero, listaFlyCodes, lenFlyCodes);
		indiceTypePassenger = Passenger_MatchTypePassenger(unPasajero, listaTiposPasajeros, lenTiposPasajeros);
		printf("|%5d| %-20s %-20s | %-10.2f | %-20s | %-10s | %-10s |\n", id, nombre,apellido, precio, listaTiposPasajeros[indiceTypePassenger].descripcion, codigoVuelo, listaFlyCodes[indiceFlyCode].statusFly);
		printf("-----------------------------------------------------------------------------------------------------------------\n");
	}
	return error;
}

int Passenger_ValidarPrecio(char* precio)
{
	int valido;
	int lenCadena;
	int numero;
	valido = 1;

	lenCadena = strlen(precio);
	if(esFlotante(precio, lenCadena) != 1)
	{
		valido = -1;
	}
	else
	{
		numero = atof(precio);
		if(numero < 1 || numero > 100000)
		{
			valido = -1;
		}
	}
	return valido;
}

static int idIncrementalInicial = 1; // Se usa en caso de que no se haya cargado un archivo
static int idIncremental = 1001; // Se usa en caso de que se haya cargado el archivo
static int Passenger_ObtenerID(int);
static int Passenger_ObtenerID(int lenLista)
{
	if(lenLista == 0)
	{
		return idIncrementalInicial++;
	}
	else
	{
		return idIncremental++;
	}
}

int Passenger_PedirDatos(	char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, TypePassenger* listaTiposPasajeros,
							int lenTiposPasajeros,FlyCode* listaFlyCodes, int lenFlyCodes, int lenLista)
{
	int error;
	int getId;
	int getTypePassenger;
	int getFlyCode;
	int lenNombre;
	int lenApellido;

	error = -1;

	if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL)
	{
		getId = Passenger_ObtenerID(lenLista);
		sprintf(idStr, "%d", getId);

		utn_getString(nombreStr, "Nombre: ", "Error, intentelo de nuevo: ", 20);
		lenNombre = strlen(nombreStr);
		Passenger_DarFormatoNombre(nombreStr, lenNombre);
		utn_getString(apellidoStr, "Apellido: ", "Error, intentelo de nuevo: ", 20);
		lenApellido = strlen(apellidoStr);
		Passenger_DarFormatoNombre(apellidoStr, lenApellido);
		utn_getString(precioStr, "Precio: ", "Error, precio fuera de rango. Intentelo de nuevo: ", 20);

		while(Passenger_ValidarPrecio(precioStr) != 1)
		{
			printf("\nError...");
			utn_getString(precioStr, "Intentelo de nuevo: ", "Error, precio fuera de rango. Intentelo de nuevo: ", 20);
		}

		TypePassenger_printLista(listaTiposPasajeros, lenTiposPasajeros);
		utn_getNumero(&getTypePassenger, "Tipo de pasajero (seleccione el numero correspondiente a su tipo de pasaje): ", "Error, tipo de pasajero fuera de rango. Intentelo de nuevo: ", 1, 3);
		TypePassenger_ReemplazarIntPorString(tipoPasajeroStr, getTypePassenger);

		FlyCode_PrintLista(listaFlyCodes, lenFlyCodes);
		utn_getNumero(&getFlyCode, "Codigo de vuelo (seleccione el numero correspondiente a su codigo de vuelo): ", "Error, codigo de vuelo fuera de rango. Intentelo de nuevo: ", 1, 8);
		FlyCode_ReemplazarIntPorString(codigoVueloStr, getFlyCode);

		error = 1;
	}
	return error;
}

int Passenger_Modificar(Passenger* unPasajero, TypePassenger* listaTiposPasajeros, int lenTiposPasajeros, FlyCode* listaFlyCodes, int lenFlyCodes)
{
	int error;
	int opcion;
	int getNuevoTypePassenger;
	int getNuevoFlyCode;
	char nuevoNombre[20];
	char nuevoApellido[20];
	char nuevoPrecio[20];
	char nuevoCodigoVuelo[20];
	error = -1;

	if(unPasajero != NULL && listaTiposPasajeros != NULL && lenTiposPasajeros > 0 && listaFlyCodes != NULL && lenFlyCodes > 0)
	{
		error = 1;
		do
		{
			utn_getNumero(&opcion, "\n******** MENU DE MODIFICACIONES ********\n\n"
					"1. Nombre\n"
					"2. Apellido\n"
					"3. Precio\n"
					"4. Tipo de pasajero\n"
					"5. Codigo de vuelo\n"
					"6. Regresar al menu principal\n"
					"Seleccione una opcion: ", "Error, opcion no disponible. Intentelo de nuevo: ", 1, 6);

			switch(opcion)
			{
				case 1:
					utn_getString(nuevoNombre, "Nombre nuevo: ", "Error, intentelo de nuevo: ", 20);
					Passenger_setNombre(unPasajero, nuevoNombre);
					break;
				case 2:
					utn_getString(nuevoApellido, "Apellido nuevo: ", "Error, intentelo de nuevo: ", 20);
					Passenger_setApellido(unPasajero, nuevoApellido);
					break;
				case 3:
					utn_getString(nuevoPrecio, "Precio nuevo: ", "Error, precio fuera de rango. Intentelo de nuevo: ", 20);

					while(Passenger_ValidarPrecio(nuevoPrecio) != 1)
					{
						printf("\nError...");
						utn_getString(nuevoPrecio, "Intentelo de nuevo: ", "Error, precio fuera de rango. Intentelo de nuevo: ", 20);
					}
					Passenger_setPrecio(unPasajero, atof(nuevoPrecio));
					break;
				case 4:
					TypePassenger_printLista(listaTiposPasajeros, lenTiposPasajeros);
					utn_getNumero(&getNuevoTypePassenger, "Nuevo tipo de pasajero (seleccione el numero correspondiente a su tipo de pasaje): ", "Error, tipo de pasajero fuera de rango. Intentelo de nuevo: ", 1, 3);
					Passenger_setTipoPasajero(unPasajero, getNuevoTypePassenger);
					break;
				case 5:
					FlyCode_PrintLista(listaFlyCodes, lenFlyCodes);
					utn_getNumero(&getNuevoFlyCode, "Nuevo codigo de vuelo (seleccione el numero correspondiente a su codigo de vuelo): ", "Error, codigo de vuelo fuera de rango. Intentelo de nuevo: ", 1, 8);
					FlyCode_ReemplazarIntPorString(nuevoCodigoVuelo, getNuevoFlyCode);
					Passenger_setCodigoVuelo(unPasajero, nuevoCodigoVuelo);
					break;
				default:
					printf("Salio del menu de modificaciones!\n");
					break;
			}
		} while(opcion != 6);
	}
	return error;
}

int Passenger_CompareByName(void* thisUno, void* thisDos)
{
	int comparacion;
	char nombreUno[50];
	char nombreDos[50];
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;

	pasajeroUno = (Passenger*) thisUno;
	pasajeroDos= (Passenger*) thisDos;

	Passenger_getNombre(pasajeroUno, nombreUno);
	Passenger_getNombre(pasajeroDos, nombreDos);

	comparacion = strcmp(nombreUno, nombreDos);

	if(comparacion > 0)
	{
		comparacion = 1;
	}
	else
	{
		if(comparacion < 0)
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

int Passenger_CompareById(void* thisUno, void* thisDos)
{
	int comparacion;
	int idUno;
	int idDos;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;

	comparacion = 0;
	pasajeroUno = (Passenger*) thisUno;
	pasajeroDos = (Passenger*) thisDos;

	Passenger_getId(pasajeroUno, &idUno);
	Passenger_getId(pasajeroDos, &idDos);

	if(idUno > idDos)
	{
		comparacion = 1;
	}
	else
	{
		if(idUno < idDos)
		{
			comparacion = -1;
		}
	}
	return comparacion;
}

int Passenger_CompareByLastName(void* thisUno, void* thisDos)
{
	int comparacion;
	char apellidoUno[50];
	char apellidoDos[50];
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;

	pasajeroUno = (Passenger*) thisUno;
	pasajeroDos= (Passenger*) thisDos;

	Passenger_getApellido(pasajeroUno, apellidoUno);
	Passenger_getApellido(pasajeroDos, apellidoDos);

	comparacion = strcmp(apellidoUno, apellidoDos);

	if(comparacion > 0)
	{
		comparacion = 1;
	}
	else
	{
		if(comparacion < 0)
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

int Passenger_CompareByPrice(void* thisUno, void* thisDos)
{
	int comparacion;
	float precioUno;
	float precioDos;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;

	comparacion = 0;
	pasajeroUno = (Passenger*) thisUno;
	pasajeroDos = (Passenger*) thisDos;

	Passenger_getPrecio(pasajeroUno, &precioUno);
	Passenger_getPrecio(pasajeroDos, &precioDos);

	if(precioUno > precioDos)
	{
		comparacion = 1;
	}
	else
	{
		if(precioUno < precioDos)
		{
			comparacion = -1;
		}
	}
	return comparacion;
}


int Passenger_CompareByTypePassenger(void* thisUno, void* thisDos)
{
	int comparacion;
	int tipoUno;
	int tipoDos;
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;

	comparacion = 0;
	pasajeroUno = (Passenger*) thisUno;
	pasajeroDos = (Passenger*) thisDos;

	Passenger_getTipoPasajero(pasajeroUno, &tipoUno);
	Passenger_getTipoPasajero(pasajeroDos, &tipoDos);

	if(tipoUno > tipoDos)
	{
		comparacion = 1;
	}
	else
	{
		if(tipoUno < tipoDos)
		{
			comparacion = -1;
		}
	}
	return comparacion;
}

int Passenger_CompareByFlyCode(void* thisUno, void* thisDos)
{
	int comparacion;
	char flyCodeUno[50];
	char flyCodeDos[50];
	Passenger* pasajeroUno;
	Passenger* pasajeroDos;

	pasajeroUno = (Passenger*) thisUno;
	pasajeroDos= (Passenger*) thisDos;

	Passenger_getCodigoVuelo(pasajeroUno, flyCodeUno);
	Passenger_getCodigoVuelo(pasajeroDos, flyCodeDos);

	comparacion = strcmp(flyCodeUno, flyCodeDos);

	if(comparacion > 0)
	{
		comparacion = 1;
	}
	else
	{
		if(comparacion < 0)
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


int Passenger_MatchTypePassenger(Passenger* unPasajero, TypePassenger* listaTiposPasajeros, int lenTiposPasajeros)
{
	int indice;
	int typePassenger;

	indice = -1;
	Passenger_getTipoPasajero(unPasajero, &typePassenger);

	for(int i = 0; i < lenTiposPasajeros; i++)
	{
		if(typePassenger == listaTiposPasajeros[i].id)
		{
			indice = i;
		}
	}
	return indice;
}

int Passenger_MatchFlyCode(Passenger* unPasajero, FlyCode* listaFlyCodes, int lenFlyCodes)
{
	int indice;
	char flyCode[20];

	indice = -1;
	Passenger_getCodigoVuelo(unPasajero, flyCode);

	for(int i = 0; i < lenFlyCodes; i++)
	{
		if(strcmp(flyCode, listaFlyCodes[i].descripconFlyCode) == 0 )
		{
			indice = i;
		}
	}
	return indice;
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

