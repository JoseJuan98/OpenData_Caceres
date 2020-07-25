/*
 * Pruebas.h
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#ifndef PRUEBAS_H_
#define PRUEBAS_H_

#include <iostream>
#include "../Gestores/Barrios.h"
#include "../Gestores/Calles.h"
#include "../Gestores/Distritos.h"

#include "../Utilidades/listapi.h"
#include "../Contenedores/Via.h"
#include "../Contenedores/Farola.h"
#include "../Contenedores/distrito.h"
#include "../Contenedores/Barrio.h"

using namespace std;
/**************************ACLARACIONES*****************************
 *1.TODOS LOS .CPPs DE LAS PRUEBAS TIENEN UN MAIN COMENTADO PARA PROBARLAS, LO UNICO QUE HAY QUE HACER PARA PROBARLAS ES
 *COMENTAR EL DEL UI Y DESCOMENTAR EL ELEGIDO A PROBAR.
 *

 *3.EL OPENDATA NO TIENE PRUEBAS YA QUE SE REALIZAN AL EJECUTAR LOS ALGORITMOS.
 *
 *4.NO TENGAIS EN CUENTA LA COHERENCIA DE SI UN BARRIO PERTENECE AL DISTRITO INCORRECTO O LA VIA AL BARRIO, ETC;
 *HEMOS COGIDO BARRIOS VIAS Y DISTRITOS ALEATORIAMENTE.
 */

//PRUEBAS DE CLASES CONTENEDORAS

void pruebasClasesContenedoras();

void pruebasFarolasYVias();
//PRUEBAS DEL GESTORDISTRITOS
void pruebasInsertar_MostrarDistrito();

void pruebasBuscarDistrito();



//PRUEBAS GESTORBARRIOS
void pruebasInsertar_MostrarBarrio();

void pruebasBuscarBarrio();

void pruebasMostrarBarrio();

//PRUENAS GESTORCALLES
void pruebasInsertar_MostrarVias();

void pruebasInsertar_Mostrar_EnlazarFarolas(); //y tmb el enlazar farolas

void pruebasBuscarUnaVia();

void pruebasViasDeUnBarrio();

#endif /* PRUEBAS_H_ */
