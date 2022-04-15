/*
 * Input.c

 	 Fernàndez Juan Ignacio 1ºB
 	 Trabajo pràctico Nº1
 */
#include "Input.h"

float PedirNumero(char mensaje[], char mensajeError[], int minimo, int maximo)
{
	float numeroIngresado;

	if (mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		printf("%s", mensaje);
		__fpurge(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < minimo || numeroIngresado > maximo)
		{
			printf("\n%s", mensajeError);
			__fpurge(stdin);
			scanf("%f", &numeroIngresado);
		}
	}
	return numeroIngresado;
}
