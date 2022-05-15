/*
	Fernàndez Juan Ignacio 1ºB
	Trabajo pràctico Nº2
*/
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Input.h"
#include "ArrayPassenger.h"
#include "ArrayFlyCode.h"
#include "Menu.h"

#define TAM_P 2000
#define TAM_F 50
#define ASCENDENTE 1
#define DESCENDENTE 0
#define TRUE 1
#define FALSE 2

int main(void) {

	setbuf(stdout, NULL);

	ePassenger arrayPassengers[TAM_P];
	eFlyCode arrayFlyCodes[TAM_F];
	int retorno;
	int opcion;
	int opcionDos;
	int eliminarId;
	int modificarId;
	int flagPasajeros;
	int flagFlyCode;
	float promedioPasajes;
	int cantSuperiorPromedio;

	initPassengers(arrayPassengers, TAM_P);
	initFlyCode(arrayFlyCodes, TAM_F);

	flagPasajeros = 0;
	flagFlyCode = 0;

	do
	{
		MostrarMenu(&opcion);

		switch(opcion)
		{
			case 1:
				if(flagFlyCode == 0)
				{
					printf("\nNo se puede cargar usuarios ya que no se ha ingresado ningun codigo de vuelo.\n"
							"Ingrese un codigo con la opcion 6 primero"); // Si no hay ningun codigo de vuelo significa que no existen vuelos.
																		//Por lo tanto no pueden existir pasajeros hasta que no exista un vuelo antes.
				}
				else
				{
					retorno = PedirDatos(arrayPassengers, TAM_P, arrayFlyCodes, TAM_F);
					if(retorno == -1)
					{
						printf("\nError, no se ha logrado dar de alta al pasajero en el sistema.");
					}
					else
					{
						printf("\nSe ha dado de alta al pasajero!");
						flagPasajeros = flagPasajeros + 1;
					}
				}
				break;
			case 2:
				if(flagPasajeros == 0)
				{
					printf("\nNo se puede acceder a esta opcion sin antes haber ingresado un pasajero.\n");
				}
				else
				{
					printPassengers(arrayPassengers, TAM_P, arrayFlyCodes, TAM_F);
					utn_getNumero(&modificarId, "\nID del pasajero que quiere modificar: ", "Error, rango de ID no valido. Intentelo de nuevo: ", 1, 2000);
					retorno = modifyPassenger(arrayPassengers, TAM_P, arrayFlyCodes, TAM_F, modificarId);
					switch(retorno)
					{
					case 0:
						printf("\nSe han guardado las modificaciones!");
						break;
					case 1:
						printf("\nSe ha encontrado al usuario, pero no han realizado modificaciones.");
						break;
					default:
						printf("\nNo se ha encontrado el ID");
						break;
					}
				}
				break;
			case 3:
				if(flagPasajeros == 0)
				{
					printf("\nNo se puede acceder a esta opcion sin antes haber ingresado un pasajero.\n");
				}
				else
				{
					printPassengers(arrayPassengers, TAM_P, arrayFlyCodes, TAM_F);
					utn_getNumero(&eliminarId, "\nID del pasajero que quiere eliminar: ", "Error, rango de ID no valido. Intentelo de nuevo: ", 1, 2000);
					retorno = removePassengerById(arrayPassengers, TAM_P, eliminarId);

					switch(retorno)
					{
						case 1:
							printf("\nSe ha encontrado al usuario, pero no lo dio de baja.");
							break;
						case 0:
							printf("\nSe ha dado de baja al pasajero del sistema!");
							flagPasajeros = flagPasajeros - 1;
							break;
						default:
							printf("\nNo se ha encontrado el ID");
							break;
					}
				}
				break;
			case 4:
				if(flagPasajeros == 0)
				{
					printf("\nNo se puede acceder a esta opcion sin antes haber ingresado un pasajero.\n");
				}
				else
				{
					MostrarSubMenu(&opcionDos);
					switch(opcionDos)
					{
						case 1:
							sortPassengers(arrayPassengers, TAM_P, ASCENDENTE);
							printPassengers(arrayPassengers, TAM_P, arrayFlyCodes, TAM_F);
							break;
						case 2:
							promedioPasajes = PromedioVuelos(arrayPassengers, TAM_P);
							cantSuperiorPromedio = SuperiorAlPromedio(arrayPassengers, TAM_P, promedioPasajes);
							printf("\nCantidad de pasajeros que superan el promedio: %d", cantSuperiorPromedio);
							break;
						case 3:
							sortPassengersByCode(arrayPassengers, TAM_P, ASCENDENTE, arrayFlyCodes, TAM_F);
							printPassengers(arrayPassengers, TAM_P, arrayFlyCodes, TAM_F);
							break;
						default:
							printf("\nHa salido del menu de informes.\n");
							break;
					}
				}
				break;
			case 5:
				AltaForzadaCodigos(arrayFlyCodes, TAM_F);
				retorno = AltaForzadaPasajeros(arrayPassengers, TAM_P);
				flagFlyCode = flagFlyCode + 4;
				if(retorno == 0)
				{
					printf("\nSe han cargado correctamente los pasajeros y codigos de vuelo.");
					flagPasajeros = flagPasajeros + 5;
				}
				else
				{
					printf("\nError, no se ha logrado completar la carga forzada.");
				}
				break;
			case 6:
				retorno = AltaFlyCode(arrayFlyCodes, TAM_F);
				if(retorno == -1)
				{
					printf("\nNo se pueden cargar mas codigos de vuelo en el sistema.");
				}
				else
				{
					printf("\nSe ha cargado del codigo de vuelo en el sistema.");
					flagFlyCode = flagFlyCode + 1;
				}
				break;
			default:
				printf("\nSaliò del programa. Saludos!");
				break;
		}
	} while(opcion != 7);
	return 0;
}


