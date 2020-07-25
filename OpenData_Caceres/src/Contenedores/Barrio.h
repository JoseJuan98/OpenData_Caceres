/*
 * Barrio.h
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */
#include <string>
#include <iostream>
#include "../Contenedores/distrito.h"
using namespace std;

#ifndef BARRIO_H_
#define BARRIO_H_

/*
 * ---------------------------------------------------------------------------
 *                                  BARRIO
 * Autores: Fran y Jose Juan
 *
 * Esta clase es la encargada de contener y administrar la informacion de cada
 * barrio por individual, posee un puntero a su distrito
 *
 * Esta enlazada con un distrito al que pertenece a traves de un puntero
 * A su vez, las vias tienen un puntero a su barrio
 *
 * Descripcion de los atributos:
 *
 * nombreBarrio: string con el nombre del barrio
 * perteneceADistrito: puntero que apunta al distrito en el que se encuentra
 *
 * ---------------------------------------------------------------------------
 */

class Barrio {
private:
	string nombreBarrio;
	distrito *perteneceADistrito;

public:

	/*	Desc: Inicializa la clase con atributos por defecto
	 * 	PRE:
	 * 	POST: El ditrito se crea y esta correctamente inicializado
	 * 	Params:
	 * 	Comp: O(1) */

	Barrio();

	/*	Desc: Inicializa la clase con atributos por parametro
	 * 	PRE:
	 * 	POST: El ditrito se crea y esta correctamente inicializado con los valores dados
	 * 	Params: string nombreBarrio, distrito *perteneceADistrito
	 * 	Comp: O(1) */

	Barrio(string nombreBarrio, distrito *perteneceADistrito);


	//                   ~~~ METODOS SET ~~~

	/*	Desc: Da un valor al atributo
	 * 	PRE:
	 * 	POST: Coloca el nombre del barrio correctamente
	 * 	Params: string nombreBarrio
	 * 	Comp: O(1) */

	void setNombreBarrio (string nombreBarrio);

	/*	Desc: Da un valor al atributo
	 * 	PRE:
	 * 	POST: Le mete el puntero al distrito, enlazandolo así
	 * 	Params: distrito *d
	 * 	Comp: O(1) */
	void setDistritoAlQuePertenece (distrito *d);

	//                           ~~~METODOS GET~~~

	/*	Desc: Devuelve el valor del atributo
	 * 	PRE:
	 * 	POST: El valor del atributo sale como salida
	 * 	Params:
	 * 	Comp: O(1) */


	string getNombreBarrio();


	/*	Desc: Devuelve el atributo, que es un puntero
	 * 	PRE:
	 * 	POST: Sale el valor del atributo como salida
	 * 	Params:
	 * 	Comp: O(1) */

	distrito* getDistritoAlQuePertenece();

	/*	Desc: Devuelve el nombre de su distrito enlazado
	 * 	PRE:
	 * 	POST: El nombre del distrito sale como salida
	 * 	Params:
	 * 	Comp: O(1) */

	string getNombreDistritoAlQuePertenece();

	//                   ~~~OTROS METODOS Y OPERADORES~~~

	/*	Desc: Muestra todos los atributos del objeto
   	 * 	PRE:
	 * 	POST: Muestra por conslola los atributos
	 * 	Params:
	 * 	Comp: O(1) */

	void mostrar();

	/*	Desc: Compara el string de dos barrios y si el primero es mayor lo identifica
	 * 	PRE:
	 * 	POST: True si es mayor, false si no
	 * 	Params: barrio b de entrada salida, constante
	 * 	Comp: O(1) */

	bool operator >(const Barrio &b);

	/*	Desc: Compara el string de dos barrios y si son iguales lo identifica
		 * 	PRE:
		 * 	POST: True si es igual, false si no
		 * 	Params: distrito d de entrada salida, constante
		 * 	Comp: O(1) */
	bool operator==(Barrio &b);

	/*	Desc: Libera el espacio de la memoria
	 * 	PRE:
	 * 	POST:
	 * 	Params:
	 * 	Comp: O(1) */

	~Barrio();
};

#endif /* BARRIO_H_ */
