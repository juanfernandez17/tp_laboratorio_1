/*
	Fernandez Juan Ignacio 1ºB
	Trabajo practico Nº3
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout, NULL);

    int option;
    int loadTxt;
    int loadBin;
    int saveAsTxt;
    int saveAsBin;
    int returnModify;
    int returnRemove;
    int cantPasajeros;

    LinkedList* listaPasajeros = ll_newLinkedList();
    loadTxt = 0;
    loadBin = 0;
    cantPasajeros = 0;

    do{
    	utn_getNumero(&option, "\n********** MENU DE OPCIONES **********\n\n"
								"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n"
								"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
								"3. Alta de pasajero\n"
								"4. Modificar datos de pasajero\n"
								"5. Baja de pasajero\n"
								"6. Listar pasajeros\n"
								"7. Ordenar pasajeros\n"
								"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
								"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
								"10. Salir\n\n"
								"Seleccione una opcion: ", "Error, opcion invalida. Intentelo de nuevo: ", 1, 10);
        switch(option)
        {
            case 1:
            	if(loadBin != 1 && loadTxt != 1)
            	{
            		loadTxt = controller_loadFromText("data.csv",listaPasajeros);
            		if(loadTxt == 1)
            		{
            			printf("\nSe cargo el archivo de texto correctamente!");
            			cantPasajeros += 1000;
            		}
            	}
            	else
            	{
            		printf("No puede acceder a esta opcion ya que anteriormente se cargaron los datos desde el archivo de texto o binario!\n");
            	}
                break;
            case 2:
            	if(loadTxt != 1 && loadBin != 1)
            	{
            		loadBin = controller_loadFromBinary("dataBin.bin", listaPasajeros);
            		if(loadBin == 1)
					{
						printf("\nSe cargo el archivo binario correctamente!");
						cantPasajeros += 1000;
					}
            	}
            	else
            	{
            		printf("No puede acceder a esta opcion ya que anteriormente se cargaron los datos desde el archivo binario o de texto!\n");
            	}
            	break;
            case 3:
            		if(controller_addPassenger(listaPasajeros) == 1)
            		{
            			cantPasajeros++;
            		}
            	break;
            case 4:
            		if(cantPasajeros != 0)
            		{
            			returnModify = controller_editPassenger(listaPasajeros);
						switch(returnModify)
						{
						case 1:
							printf("\nSe completo la modificacion correctamente!");
							break;
						case 0:
							printf("\nNo existe un pasajero con el ID ingresado!");
							break;
						default:
							printf("\nError...");
							break;
						}
            		}
            		else
            		{
            			printf("\nNo se puede acceder al menu de modificaciones si no hay pasajeros cargados previamente!");
            		}
				break;
			case 5:
				if(cantPasajeros != 0)
				{
					returnRemove = controller_removePassenger(listaPasajeros);
					if(returnRemove == -1)
					{
						printf("\nError...");
					}
					else
					{
						if(returnRemove == 0)
						{
							printf("\nNo existe un pasajero con el ID ingresado!");
						}
						else
						{
							printf("\nSe dio de baja al pasajero!");
							cantPasajeros--;
						}
					}
				}
				else
				{
					printf("\nNo se puede dar de baja un pasajero si no hay pasajeros cargados previamente!");
				}
				break;
			case 6:
				if(cantPasajeros != 0)
				{
					controller_ListPassenger(listaPasajeros);
				}
				else
				{
					printf("\nNo se puede listar los pasajeros si no hay pasajeros cargados previamente!");
				}

				break;
			case 7:
				if(cantPasajeros != 0)
				{
					controller_sortPassenger(listaPasajeros);
				}
				else
				{
					printf("\nNo se puede acceder al submenu para ordernar los pasajeros si no hay pasajeros cargados previamente!");
				}
				break;
			case 8:
				if(loadBin != 1 && loadTxt != 1)
				{
					printf("No puede acceder a esta opcion sin antes haber cargado uno de los archivos (opcion 1 u opcion 2)!\n");
				}
				else
				{
					saveAsTxt = controller_saveAsText("data.csv", listaPasajeros);
					if(saveAsTxt == 1)
					{
						printf("\nSe ha guardado el archivo correctamente!");
					}
				}
				break;
			case 9:
				if(loadBin != 1 && loadTxt != 1)
				{
					printf("No puede acceder a esta opcion sin antes haber cargado uno de los archivos (opcion 1 u opcion 2)!\n");
				}
				else
				{
					saveAsBin = controller_saveAsBinary("dataBin.bin", listaPasajeros);
					if(saveAsBin == 1)
					{
						printf("\nSe ha guardado el archivo correctamente!");
					}
				}
				break;
			default:
				if(saveAsTxt != 1 && saveAsBin != 1)
				{
					printf("\nNo puede salir del programa sin antes realizar un guardado (opcion 8 u opcion 9)!");
					option = 0;
				}
				else
				{
					printf("\nPrograma cerrado. Saludos!");
				}
				break;
        }
    }while(option != 10);
    return 0;
}

