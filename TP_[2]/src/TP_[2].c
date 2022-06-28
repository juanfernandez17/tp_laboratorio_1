
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayPassenger.h"
#include "ArrayFlyCode.h"

#define TAM_P 2000
#define TAM_F 100

int main(void) {

	setbuf(stdout, NULL);

	Passenger listPassengers[TAM_P];
	FlyCode listFlyCodes[TAM_F];
	int option;
	int optionSubMenu;
	int lastIdPassenger;
	int lastIdFlyCode;
	int flagCargaForzada;
	int retornoDelete;
	int cantPasajeros;
	int retornoAddFlyCode;
	int retornoAdd;

	initPassengers(listPassengers, TAM_P);
	FlyCode_init(listFlyCodes, TAM_F);
	lastIdPassenger = 0;
	lastIdFlyCode = 0;
	flagCargaForzada = 0;
	cantPasajeros = 0;

	do
	{
		utn_getNumero(&option, "\n******* MENU PRINCIPAL *******\n"
				"1. Alta pasajero\n2. Modificar pasajero\n3. Baja pasajero\n4. Informar\n"
				"5. Carga forzada (5 pasajeros y 4 codigos de vuelo)\n6. Alta codigo vuelo\n7. Salir\n\n"
				"Seleccione una opcion: ", "Error, intentelo de nuevo: ", 1, 7);

		switch(option)
		{
			case 1:
				if(cantPasajeros < 1)
				{
					printf("\nNo puede ingresar un nuevo pasajero sin antes haber ingresado un codigo de vuelo!");
				}
				else
				{
					retornoAdd = Passenger_PedirDatos(listPassengers, TAM_P, listFlyCodes, TAM_F, &lastIdPassenger);

					if(retornoAdd != 0)
					{
						printf("\nError al ingresar el nuevo pasajero a la lista!");
					}
					else
					{
						printf("\nSe ingreso el nuevo pasajero a la lista!");
					}
				}
				break;
			case 2:
				if(cantPasajeros < 1)
				{
					printf("\nNo puede modificar un pasajero sin antes haber cargado, al menos, un pasajero a la lista!");
				}
				else
				{
					Passenger_modify(listPassengers, TAM_P, listFlyCodes, TAM_F);
				}
				break;
			case 3:
				if(cantPasajeros < 1)
				{
					printf("\nNo puede eliminar un pasajero sin antes haber cargado, al menos, un pasajero a la lista!");
				}
				else
				{
					retornoDelete = Passenger_delete(listPassengers, TAM_P, listFlyCodes, TAM_F);
					if(retornoDelete == 0)
					{
						printf("\nSe dio de baja el pasajero!");
						cantPasajeros--;
					}
				}
				break;
			case 4:
				if(cantPasajeros < 1)
				{
					printf("\nNo puede acceder al submenu de informes sin antes haber ingresado, al menos, un pasajero a la lista!");
				}
				else
				{
					utn_getNumero(&optionSubMenu, "\n******* MENU DE INFORMES *******\n"
							"1. Listar pasajeros por apellido y tipo de pasajero\n"
							"2. Total y promedio de precios de los pasajes y cantidad de pasajeros que superan el precio promedio\n"
							"3. Listar pasajeros por codigo de vuelo y estado de vuelos Activo\n"
							"4. Regresar al menu principal\n\n"
							"Seleccione una opcion: ", "Error, intentelo de nuevo: ", 1, 4);
					Passenger_subMenu(optionSubMenu, listPassengers, TAM_P, listFlyCodes);
				}
				break;
			case 5:
				if(flagCargaForzada == 0)
				{
					Passenger_CargaForzada(listPassengers, TAM_P);
					FlyCode_CargaForzada(listFlyCodes, TAM_F);
					lastIdPassenger += 5;
					lastIdFlyCode += 4;
					cantPasajeros += 5;
					flagCargaForzada = 1;
					printf("\nSe han cargado 5 pasajeros y 4 codigos de vuelo!");
				}
				else
				{
					printf("\nYa ha realizado la carga forzada previamente!");
				}
				break;
			case 6:
				retornoAddFlyCode = addFlyCode(listFlyCodes, TAM_F, &lastIdFlyCode);

				if(retornoAddFlyCode == 0)
				{
					printf("\nSe dio de alta el nuevo codigo!");
					lastIdFlyCode += 1;
				}
				else
				{
					printf("\nNo se logro dar de alta el nuevo codigo!");
				}
				break;
			default:
				printf("\nPrograma cerrado. Saludos!");
				break;
		}
	} while(option != 7);
	return 0;
}
