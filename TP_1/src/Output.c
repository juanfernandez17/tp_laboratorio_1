/*
 * Output.c

		Fernàndez Juan Ignacio 1ºB
 		Trabajo pràctico Nº1
 */

#include "Output.h"

void MostrarResultados(float precioConDebito, float precioConCredito, float precioConBitcoin, float precioUnitario)
{
	printf("\na) Precio con tarjeta de dèbito: $ %.2f"
			"\nb) Precio con tarjeta de crèdito: $ %.2f"
			"\nc) Precio pagando con bitcoin: $%.5f BTC"
			"\nd) Mostrar precio unitario: $ %.2f\n", precioConDebito, precioConCredito, precioConBitcoin, precioUnitario);
}

void MostrarMenu(float kmIngresados, float precioAerolineas, float precioLatam)
{
	printf("\n1. Ingresar Kilòmetros: (km = %.2f)", kmIngresados);
	printf("\n2. Ingresar Precio de Vuelos: (Aerolineas = %.2f, Latam = %.2f)", precioAerolineas, precioLatam);
	printf("\n3. Calcular todos los costos: "
			"\n   a) Tarjeta de dèbito (descuento 10%%)"
			"\n   b) Tarjeta de crèdito (interès 25%%)"
			"\n   c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)"
			"\n   d) Mostrar precio por km (precio unitario)"
			"\n   e) Mostrar diferencia de precio ingresada (Latam - Aerolìneas)");
	printf("\n4. Informar Resultados");
	printf("\n5. Carga forzada de datos");
	printf("\n6. Salir");
}
