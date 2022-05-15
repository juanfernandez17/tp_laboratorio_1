/*
	Menu.h

	Fernàndez Juan Ignacio 1ºB
	Trabajo pràctico Nº2
*/

#ifndef MENU_H_
#define MENU_H_

/// @brief Despliega el menu principal donde se encuentran las opciones y le permite al usuario seleccionar la opcion que quiera
///
/// @param int Puntero donde se almacenara la opcion ingresada por el usuario
void MostrarMenu(int *opcion);

/// @brief Despliega un menu de informes donde se encuentran las opciones de lo que se quiere informar
///  y le permite al usuario seleccionar la opcion que quiera
///
/// @param int Puntero dodne se almacenara la opcion que ingresa el usuario
void MostrarSubMenu(int *opcionDos);

#endif /* MENU_H_ */
