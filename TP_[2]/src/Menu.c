/*
	Menu.c

	Fernàndez Juan Ignacio 1ºB
	Trabajo pràctico Nº2
*/

#include "Menu.h"
#include "Input.h"
#include <stdio.h>

void MostrarMenu(int *opcion)
{
	printf("\n--------------- MENU DE OPCIONES ---------------\n");
	printf("\n1. Alta\n2. Modificar\n3. Baja\n4. Informar\n5. Carga forzada (5 pasajeros y 4 codigos de vuelo)\n6. Alta de codigo de vuelo\n7. Salir");

	utn_getNumero(opcion, "\n\nSeleccione una opcion: ", "Error, opcion no valida. Intentelo de nuevo: ", 1, 10);
}

void MostrarSubMenu(int *opcionDos)
{
	printf("\nOpciones para informar\n");
	printf("\n1. Listar pasajeros por apellido y tipo de pasajero\n2. Total y promedio de precios de los pasajes y\n"
			" cantidad de pasajeros que superan el precio promedio\n3. Listar pasajeros por codigo de vuelo y estados de vuelos ACTIVO\n4. Salir");

	utn_getNumero(opcionDos, "\n\nSeleccione una opcion: ", "Error, opcion no valida. Intentelo de nuevo: ", 1, 4);
}
