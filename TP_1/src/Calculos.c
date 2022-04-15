/*
 * Calculos.c

 	 Fernàndez Juan Ignacio 1ºB
 	 Trabajo pràctico Nº1
 */

#include "Calculos.h"

float CalcularPrecioConDebito(float precio)
{
	float precioTotal;

	precioTotal = precio * 0.9;
	return precioTotal;
}

float CalcularPrecioConCredito(float precio)
{
	float precioTotal;

	precioTotal = precio * 1.25;
	return precioTotal;
}

float CalcularPrecioConBitcoin(float precio)
{
	float precioTotal;
	float precioBitcoin;

	precioBitcoin = 4606954.55;
	precioTotal = precio / precioBitcoin;
	return precioTotal;
}

float CalcularPrecioUnitario(float km, float precio)
{
	float precioUnitario;

	precioUnitario = precio / km;
	return precioUnitario;
}

float CalcularDiferencia(float precioVueloAerolineas, float precioVueloLatam)
{
	float diferencia;

	if(precioVueloAerolineas > precioVueloLatam)
	{
		diferencia = precioVueloAerolineas - precioVueloLatam;
	}
	else
	{
		diferencia = precioVueloLatam - precioVueloAerolineas;
	}
	return diferencia;
}
