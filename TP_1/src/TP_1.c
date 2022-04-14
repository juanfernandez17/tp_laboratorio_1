/*
	Fernàndez Juan Ignacio 1ºB
	Trabajo pràctico Nº1
*/
#include <stdio_ext.h>
#include <stdlib.h>
#include "Calculos.h"
#include "Input.h"
#include "Output.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	float kmIngresados;
	float precioVueloAerolineas;
	float precioVueloLatam;
	// Creo los array para colocara en la posicion [0] el precio de Aerolineas y en la posicion [1] el precio de Latam
	float precioConDebito[2];
	float precioConCredito[2];
	float precioConBitcoin[2];
	float precioUnitario[2];
	float diferenciaDePrecio;
	float kmCargaForzada;
	float precioVueloAerolineasCargaForzada;
	float precioVueloLatamCargaForzada;
	int flagCalcularCostos;

	kmIngresados = 0;
	precioVueloAerolineas = 0;
	precioVueloLatam = 0;
	kmCargaForzada = 7090;
	precioVueloAerolineasCargaForzada = 162965;
	precioVueloLatamCargaForzada = 159339;
	flagCalcularCostos = 0; /* 0 = no se realizaron los calculos, por lo tanto NO se pueden mostrar los resultados
	 	 	 	 	 	 	   1 = se realizaron los calculos y ya se pueden mostrar los resultados */
	do
	{
		//Menù
		printf("\n1. Ingresar Kilòmetros: (km = %.2f)", kmIngresados);
		printf("\n2. Ingresar Precio de Vuelos: (Aerolineas = %.2f, Latam = %.2f)", precioVueloAerolineas, precioVueloLatam);
		printf("\n3. Calcular todos los costos: "
				"\n   a) Tarjeta de dèbito (descuento 10%%)"
				"\n   b) Tarjeta de crèdito (interès 25%%)"
				"\n   c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)"
				"\n   d) Mostrar precio por km (precio unitario)"
				"\n   e) Mostrar diferencia de precio ingresada (Latam - Aerolìneas)");
		printf("\n4. Informar Resultados");
		printf("\n5. Carga forzada de datos");
		printf("\n6. Salir");

		opcion = PedirNumero("\n\nSeleccione una opcion: ", "Error, seleccione una opcion disponible: ", 1, 6);

		switch(opcion)
		{
			case 1:
				kmIngresados = PedirNumero("Ingresar kilòmetros: ", "Error, los kilòmetros deben estar dentro del rango (1-15000)", 1, 15000);
				break;
			case 2:
				precioVueloAerolineas = PedirNumero("Ingresar precio del vuelo Aerolineas: ", "Error, el precio debe estar dentro del rango (1-999999)", 1, 999999);
				precioVueloLatam = PedirNumero("Ingresar precio del vuelo Latam: ", "Error, el precio debe estar dentro del rango (1-999999)", 1, 999999);
				break;
			case 3:
				//  Si falta ingresar los kilometros o el precio de alguna de las dos aerolineas NO se pueden realizar los calculos
				if (kmIngresados == 0 || precioVueloAerolineas == 0 || precioVueloLatam == 0)
				{
					printf("Debe ingresar todos los datos (kilometros y precios de ambas aerolineas) para poder realizar los calculos.");
				}
				else
				{
					// Calcular costos Aerolineas
					precioConDebito[0] = PagarConTarjetaDebito(precioVueloAerolineas);
					precioConCredito[0] = PagarConTarjetaCredito(precioVueloAerolineas);
					precioConBitcoin[0] = PagarConBitcoin(precioVueloAerolineas);
					precioUnitario[0] = CalcularPrecioUnitario(kmIngresados, precioVueloAerolineas);
					// Calcular costos Latam
					precioConDebito[1] = PagarConTarjetaDebito(precioVueloLatam);
					precioConCredito[1] = PagarConTarjetaCredito(precioVueloLatam);
					precioConBitcoin[1] = PagarConBitcoin(precioVueloLatam);
					precioUnitario[1] = CalcularPrecioUnitario(kmIngresados, precioVueloLatam);
					// Calcular diferencia de precio
					diferenciaDePrecio = CalcularDiferencia(precioVueloAerolineas, precioVueloLatam);

					printf("\nCalculos realizados!!!\n");
					flagCalcularCostos = 1;
				}
				break;
			case 4:
				if (flagCalcularCostos == 0)
				{
					printf("Antes de mostrar los resultados debe ingresar a la opcion 3 para calcular los costos.");
				}
				else
				{
					// Resultados Latam
					printf("KMs Ingresados: %.2f km", kmIngresados);
					printf("\n\nPrecio Latam: $%.2f", precioVueloLatam);
					MostrarResultados(precioConDebito[1], precioConCredito[1], precioConBitcoin[1], precioUnitario[1]);
					// Resultados Aerolineas
					printf("\nPrecio Aerolineas: $%.2f", precioVueloAerolineas);
					MostrarResultados(precioConDebito[0], precioConCredito[0], precioConBitcoin[0], precioUnitario[0]);
					// Diferencia de precios
					printf("\n\nLa diferencia de precio es: $ %.2f\n\n", diferenciaDePrecio);
				}
				break;
			case 5:
				// Calcular costos Aerolineas con carga forzada
				precioConDebito[0] = PagarConTarjetaDebito(precioVueloAerolineasCargaForzada);
				precioConCredito[0] = PagarConTarjetaCredito(precioVueloAerolineasCargaForzada);
				precioConBitcoin[0] = PagarConBitcoin(precioVueloAerolineasCargaForzada);
				precioUnitario[0] = CalcularPrecioUnitario(kmCargaForzada, precioVueloAerolineasCargaForzada);
				// Calcular costos Latam con carga forzada
				precioConDebito[1] = PagarConTarjetaDebito(precioVueloLatamCargaForzada);
				precioConCredito[1] = PagarConTarjetaCredito(precioVueloLatamCargaForzada);
				precioConBitcoin[1] = PagarConBitcoin(precioVueloLatamCargaForzada);
				precioUnitario[1] = CalcularPrecioUnitario(kmCargaForzada, precioVueloLatamCargaForzada);
				// Calcular diferencia de precio
				diferenciaDePrecio = CalcularDiferencia(precioVueloAerolineasCargaForzada, precioVueloLatamCargaForzada);
				// Resultados de Aerolineas con carga forzada
				printf("KMs Ingresados: %.2f km", kmCargaForzada);
				printf("\n\nPrecio Aerolineas: $%.2f", precioVueloAerolineasCargaForzada);
				MostrarResultados(precioConDebito[0], precioConCredito[0], precioConBitcoin[0], precioUnitario[0]);
				// Resultados de Latam con carga forzada
				printf("\nPrecio Latam: $%.2f", precioVueloLatamCargaForzada);
				MostrarResultados(precioConDebito[1],precioConCredito[1], precioConBitcoin[1], precioUnitario[1]);
				// Diferencia de precios
				printf("\nLa diferencia de precio es: $%.2f\n", diferenciaDePrecio);
				break;
			default: //Opcion 6 -> Salir
				printf("Gracias por usar la aplicaciòn!!! Saludos.");
				break;
		}
	} while(opcion != 6);
	return 0;
}
