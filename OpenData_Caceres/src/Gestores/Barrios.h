/*
 * Barrios.h
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#ifndef BARRIOS_H_
#define BARRIOS_H_
#include <string>
#include "../Utilidades/listapi.h"
#include "../Contenedores/Barrio.h"

/*
 * ---------------------------------------------------------------------------
 *                                  Barrios
 * Autores: Fran y Jose Juan
 *
 * Se encarga de contener la lista de todos los distritos y realizar operaciones
 * sobre ellos
 *
 * Descripción de los atributos
 *
 * lbarrios: lista de punto de interes que contiene todos los barrios
 *
 * ---------------------------------------------------------------------------
 */

using namespace std;
class Barrios {
	ListaPI <Barrio *> *lbarrios;
public:
	/*	Desc: Inicializa la clase y reserva el espacio para la lista de barrios
	 * 	PRE:
	 * 	POST: La lista de barrios y ya se puede usar
	 * 	Params:
	 * 	Comp: O(1) */
	Barrios();
	/*	Desc: Inserta el barrio dado en su posicion de la lista
	 * 	PRE:
	 * 	POST: El barrio queda insertado
	 * 	Params: Barrio *b
	 * 	Comp: O(n), dependiendo de su posicion alfabetica */
	void insertarBarrioEnOrden(Barrio *b);
	/*	Desc: Busca el barrio en la lista, comparandolo con el string y si lo encuentra lo saca como puntero, si no devuelve false
	 * 	PRE:
	 * 	POST: Saca el puntero del barrio si esta
	 * 	Params: string nombreBarrio, Barrio *&b
	 * 	Comp: O(n), dependiendo de su posicion alfabetica */
	bool buscarBarrio(string nombreBarrio, Barrio *&b);
	/*	Desc: Saca todos barrios a traves de una listaPI de un barrio ya encontrado con el buscar
	 * 	PRE: La lista PI ya ha sido inicializada
	 * 	POST:
	 * 	Params: ListaPI <Barrio *>*&barsDistrito,distrito *Distrito
     *	Comp: O(n) */
	void barriosDeUnDistrito(ListaPI <Barrio *>*&barsDistrito,distrito *Distrito);
	/*	Desc: Va mostrando uno a uno todos los vbarrios de la lista
	 * 	PRE:
	 * 	POST: Muestra todos los barrios por consola
	 * 	Params:
	 * 	Comp: O(n)*/
	void mostrarBarrios();
	/*	Desc: Libera el espacio de la lista y de todos sus barrios ya que van por composicion
	 * 	PRE:
	 * 	POST: El espacio queda liberado
	 * 	Params:
	 * 	Comp: O(n) */

	~Barrios();
};

#endif /* BARRIOS_H_ */
