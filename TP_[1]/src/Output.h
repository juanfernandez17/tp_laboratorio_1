/*
 * Output.h

 	 Fernàndez Juan Ignacio 1ºB
 	 Trabajo pràctico Nº1
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include <stdio_ext.h>
#include <stdlib.h>

/// @brief Imprime en pantalla la informacion sobre pagar con tarjeta de debito, con tarjeta de credito, con bitcoins y el precio unitario
///
/// @param float Precio a pagar con tarjeta de debito
/// @param float Precio a pagar con tarjeta de credito
/// @param float Precio a pagar con bitcoins
/// @param float Precio unitario
void MostrarResultados(float, float, float, float);

/// @brief Imprime el menu de opciones para el usuario
///
/// @param float Kilometros ingresados por el usuario
/// @param float Precio del vuelo de Aerolineas ingresado por el usuario
/// @param float Precio del vuelo de Latam ingresado por el usuario
void MostrarMenu(float, float, float);
#endif /* OUTPUT_H_ */
