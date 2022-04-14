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
