/*
 * Opendata.h
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#ifndef OPENDATA_H_
#define OPENDATA_H_
#include "Gestores/Calles.h"
#include "Gestores/Distritos.h"
#include "Gestores/Barrios.h"
#include "Utilidades/timer.h"
/*
 * ---------------------------------------------------------------------------
 *                                  Opendata
 * Autores: Jose Juan y Fran
 *
 * Se encarga de manejar todas las clases para realizar los algoritmos que
 * permiten la gestion
 *
 * Descripción de los atributos
 *
 * d: gestor de los distritos
 * b: gestor de los barrios
 * c: gestor de vias y farolas
 *
 * ---------------------------------------------------------------------------
 */
class Opendata {
private:

	// ~~Gestores de las listas~~
			Distritos *d;
			Barrios *b;
			Calles *c;

	// ~~Cargadores individuales~~
	void cargarVia();
	void cargarDistrito();
	void cargarBarrios();
	void cargarFarolas();




public:

	Opendata();

	//Algoritmo 1
	/*	Desc: Llama a todos los cargadores que leen los csv y los inserta
	 * 	PRE:
	 * 	POST: carga los datos del proyecto
	 * 	Params:
 	 * 	Comp: O(4n) */
	void cargarDatos();
	//Algoritmo 2
	/*	Desc: Llama al metodo de calles y muestra todas las vias de un barrio dado por consola
	 * 	PRE:
	 * 	POST: carga los datos del proyecto a traves de un barrio ya encontrado
	 * 	Params:
	 * 	Comp: O(n*n) */

	void mostrarViasDeBarrio();
	//Algoritmo 3
	/*	Desc: Crea un fichero con todas las vias de un distrito dado por consola
	 * 	PRE:
	 * 	POST: El fichero esta creado en la raiz del proyecto
	 * 	Params:
	 * 	Comp: O(n^3) */
	void ficheroViasDeUnDistrito();
	//Algoritmo 4
	/*	Desc: Indica los barrios adyacentes a uno dado por consola
	 * 	PRE:
	 * 	POST: Muestra los adyacentes por consola
	 * 	Params:
	 * 	Comp: O(n+n^3) */
	void BarriosAdyacentes();
	//Algoritmo 5
	/*	Desc: Saca por pantalla la via con mas concentracion
	 * 	PRE:
	 * 	POST: Saca por pantalla la via con mas concentracion
	 * 	Params:
	 * 	Comp: O(n*cantiidad de farolas por via) */
	void viaMayorConcentracion();
	//Algoritmo 6

	/*	Desc: Saca por pantalla la via con mas concentracion
	 * 	PRE:
	 * 	POST: Saca por pantalla la via con mas concentracion
	 * 	Params:
	 * 	Comp: O(n*cantiidad de farolas por via) */
	void ficheroViasTipoLampara();
	//Algoritmo 7 Listas y Arboles

	/*	Desc: Saca por pantalla la via con mas concentracion
	 * 	PRE:
	 * 	POST: Saca por pantalla la via con mas concentracion
	 * 	Params:
	 * 	Comp: O(n) */
	void mostrarViasQueEmpiezanPorUnaCadena();
	//Algoritmo 8
	/*	Desc: Muestra el consumo de un distrito concreto por consola
	 * 	PRE:
	 * 	POST: Muestra el consumo del distrito
	 * 	Params:
	 * 	Comp: O(n) */
	void consumoPorDistrito();
	//Algoritmo 9
	/*	Desc: Muestra el ahorro de cambiar farolas de un tipo por otro enconsola
	 * 	PRE:
	 * 	POST: Muestra el ahorro por consola
	 * 	Params:
	 * 	Comp: O(n) */
	void informeDeAhorro();
	//Algoritmo 10
	/*	Desc: Cambia el nombre deuna via por otro
	 * 	PRE:
	 * 	POST: Cambia el nombre de una via por otro ambos pedidos
	 * 	Params:
	 * 	Comp: O(n*log(n)) */
	void cambiarNombreVia();


	~Opendata();
};

#endif /* OPENDATA_H_ */
