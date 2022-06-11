/*
 * FlyCode.c
 *
 *  Created on: 8 jun. 2022
 *      Author: juan
 */

#include <stdio.h>
#include <string.h>
#include "FlyCode.h"
#include "utn.h"

int FlyCode_init(FlyCode* arrayFlyCodes, int lenFlyCodes)
{
	int error;
	error = -1;
	FlyCode auxiliar[8] = {	{"MM0987B", "En horario"},{"BA2491A", "Aterrizado"},{"IB0800A", "Aterrizado"},
							{"BR3456J", "Demorado"},{"FR5678G", "En horario"},{"HY4567D", "Demorado"},
							{"GU2345F", "En vuelo"},{"TU6789B", "Aterrizado"}};

	if(arrayFlyCodes != NULL && lenFlyCodes > 0)
	{
		for(int i = 0; i < lenFlyCodes; i++)
		{
			arrayFlyCodes[i] = auxiliar[i];
		}
		error = 1;
	}
	return error;
}

void FlyCode_PrintOne(FlyCode flyCode)
{
	printf("%s\n", flyCode.descripconFlyCode);
}

int FlyCode_PrintLista(FlyCode arrayFlyCode[], int lenFlyCodes)
{
	int error;
	error = -1;

	if(arrayFlyCode != NULL && lenFlyCodes > 0)
	{
		printf("\nLista de codigos de vuelo:\n\n");
		for(int i = 0; i < lenFlyCodes; i++)
		{
			printf("%d. ", i+1);
			FlyCode_PrintOne(arrayFlyCode[i]);
		}
		error = 1;
	}
	return error;
}

int FlyCode_ReemplazarIntPorString(char* flyCodeStr, int flyCode)
{
	int error;
	error = -1;

	if(flyCodeStr != NULL && flyCode >= 0)
	{
		switch(flyCode)
		{
			case 1:
				strcpy(flyCodeStr, "MM0987B");
				break;
			case 2:
				strcpy(flyCodeStr, "BA2491A");
				break;
			case 3:
				strcpy(flyCodeStr, "IB0800A");
				break;
			case 4:
				strcpy(flyCodeStr, "BR3456J");
				break;
			case 5:
				strcpy(flyCodeStr, "FR5678G");
				break;
			case 6:
				strcpy(flyCodeStr, "HY4567D");
				break;
			case 7:
				strcpy(flyCodeStr, "GU2345F");
				break;
			case 8:
				strcpy(flyCodeStr, "TU6789B");
				break;
		}
	}
	return error;
}


