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
	float precioAerolineas;
	float precioLatam;
	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;
	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float diferenciaDePrecio;
	int flagCalcularCostos;

	kmIngresados = 0; // Inicializo KMs, precioAerolineas y precioLatam para que antes de que el usuario ingrese uno de estos valores aparezcan en 0
	precioAerolineas = 0;
	precioLatam = 0;
	flagCalcularCostos = 0; /* 0 = no se realizaron los calculos, por lo tanto NO se pueden mostrar los resultados
	 	 	 	 	 	 	   1 = se realizaron los calculos y ya se pueden mostrar los resultados */
	do
	{
		MostrarMenu(kmIngresados, precioAerolineas, precioLatam);
		opcion = PedirNumero("\n\nSeleccione una opcion: ", "Error, seleccione una opcion disponible: ", 1, 6);

		switch(opcion)
		{
			case 1:
				kmIngresados = PedirNumero("Ingresar kilòmetros: ", "Error, intentelo nuevamente (rango vàlido de KMs 1-15000):", 1, 15000);
				break;
			case 2:
				precioAerolineas = PedirNumero("Ingresar precio del vuelo Aerolineas: ", "Error, intentelo nuevamente (rango vàlido de precio 1-999999): ", 1, 999999);
				precioLatam = PedirNumero("Ingresar precio del vuelo Latam: ", "Error, intentelo nuevamente (rango vàlido de precio 1-999999): ", 1, 999999);
				break;
			case 3:
				if (kmIngresados == 0 || precioAerolineas == 0 || precioLatam == 0)//  Si falta ingresar los kilometros o el precio de alguna de las dos aerolineas NO se pueden realizar los calculos
				{
					printf("Debe ingresar todos los datos (kilometros y precios de ambas aerolineas) para poder realizar los calculos.");
				}
				else
				{
					precioDebitoAerolineas = CalcularPrecioConDebito(precioAerolineas);
					precioCreditoAerolineas = CalcularPrecioConCredito(precioAerolineas);
					precioBitcoinAerolineas = CalcularPrecioConBitcoin(precioAerolineas);
					precioUnitarioAerolineas = CalcularPrecioUnitario(kmIngresados, precioAerolineas);
					precioDebitoLatam = CalcularPrecioConDebito(precioLatam);
					precioCreditoLatam = CalcularPrecioConCredito(precioLatam);
					precioBitcoinLatam = CalcularPrecioConBitcoin(precioLatam);
					precioUnitarioLatam = CalcularPrecioUnitario(kmIngresados, precioLatam);
					diferenciaDePrecio = CalcularDiferencia(precioAerolineas, precioLatam);
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
					printf("KMs Ingresados: %.2f km", kmIngresados);
					printf("\n\nPrecio Latam: $%.2f", precioLatam);
					MostrarResultados(precioDebitoLatam, precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam);
					printf("\nPrecio Aerolineas: $%.2f", precioAerolineas);
					MostrarResultados(precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas);
					printf("\nLa diferencia de precio es: $ %.2f\n", diferenciaDePrecio);
				}
				break;
			case 5:
				kmIngresados = 7090;
				precioAerolineas = 162965;
				precioLatam = 159339;
				precioDebitoAerolineas = CalcularPrecioConDebito(precioAerolineas);
				precioCreditoAerolineas = CalcularPrecioConCredito(precioAerolineas);
				precioBitcoinAerolineas = CalcularPrecioConBitcoin(precioAerolineas);
				precioUnitarioAerolineas = CalcularPrecioUnitario(kmIngresados, precioAerolineas);
				precioDebitoLatam = CalcularPrecioConDebito(precioLatam);
				precioCreditoLatam = CalcularPrecioConCredito(precioLatam);
				precioBitcoinLatam = CalcularPrecioConBitcoin(precioLatam);
				precioUnitarioLatam = CalcularPrecioUnitario(kmIngresados, precioLatam);
				diferenciaDePrecio = CalcularDiferencia(precioAerolineas, precioLatam);
				printf("KMs Ingresados: %.2f km", kmIngresados);
				printf("\n\nPrecio Aerolineas: $%.2f", precioAerolineas);
				MostrarResultados(precioDebitoAerolineas, precioCreditoAerolineas, precioBitcoinAerolineas, precioUnitarioAerolineas);
				printf("\nPrecio Latam: $%.2f", precioLatam);
				MostrarResultados(precioDebitoLatam,precioCreditoLatam, precioBitcoinLatam, precioUnitarioLatam);
				printf("\nLa diferencia de precio es: $%.2f\n", diferenciaDePrecio);
				break;
			default:
				printf("Gracias por usar la aplicaciòn!!! Saludos.");
				break;
		}
	} while(opcion != 6);
	return 0;
}
