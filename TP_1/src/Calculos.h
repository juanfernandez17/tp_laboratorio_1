/*
 * MetodosDePago.h

 	 Fernàndez Juan Ignacio 1ºB
 	 Trabajo pràctico Nº1
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/// @brief Recibe el precio inicial del vuelo, calcula el precio final a pagar con tarjeta de dèbito (10% de descuento) y lo devuelve
///
/// @param float Precio inicial del vuelo
/// @return	float Precio final con el 10% de descuento aplicado
float PagarConTarjetaDebito(float);

/// @brief Recibe el precio inicial del vuelo, calcula el precio final a pagar con tarjeta de crèdito (25% de interès) y lo devuelve
///
/// @param float Precio inicial del vuelo
/// @return float Precio final con el 25% de interes aplicado
float PagarConTarjetaCredito(float);

/// @brief Recibe el precio inicial del vuelo, calcula el precio final a pagar con Bitcoins y lo devuelve
///
/// @param float Precio del vuelo
/// @return float Precio final a pagar con Bitcoins
float PagarConBitcoin(float);

/// @brief	Recibe el precio inicial de el vuelo de Latam y el vuelo de Aerolineas, calcula la diferencia de precios y lo devuelve
///
/// @param float KMs ingresados
/// @param float Precio inicial del vuelo
/// @return float Precio unitario
float CalcularPrecioUnitario(float, float);

/// @brief Recibe los precios de los vuelos (Aerolineas y Latam), verifica cual es el precio mayor y le resta el menor para calcular la diferencia
///
/// @param float Precio inicial del vuelo Aerolineas
/// @param float Precio inicial del vuelo Latam
/// @return float La diferencia de precio entre ambos vuelos
float CalcularDiferencia(float, float);

#endif /* CALCULOS_H_ */
