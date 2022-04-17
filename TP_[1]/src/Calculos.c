/*
 * Calculos.c

 	 Fernàndez Juan Ignacio 1ºB
 	 Trabajo pràctico Nº1
 */

#include "Calculos.h"

float CalcularPrecioConDebito(float precioVuelo)
{
	float precioTotal;

	precioTotal = precioVuelo * 0.9;
	return precioTotal;
}

float CalcularPrecioConCredito(float precioVuelo)
{
	float precioTotal;

	precioTotal = precioVuelo * 1.25;
	return precioTotal;
}

float CalcularPrecioConBitcoin(float precioVuelo)
{
	float precioTotal;
	float precioBitcoin;

	precioBitcoin = 4606954.55;
	precioTotal = precioVuelo / precioBitcoin;
	return precioTotal;
}

float CalcularPrecioUnitario(float km, float precioVuelo)
{
	float precioUnitario;

	precioUnitario = precioVuelo / km;
	return precioUnitario;
}

float CalcularDiferencia(float precioAerolineas, float precioLatam)
{
	float diferenciaDePrecio;

	if(precioAerolineas > precioLatam)
	{
		diferenciaDePrecio = precioAerolineas - precioLatam;
	}
	else
	{
		diferenciaDePrecio = precioLatam - precioAerolineas;
	}
	return diferenciaDePrecio;
}
