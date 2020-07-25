/*
 * distrito.h
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#ifndef DISTRITO_H_
#define DISTRITO_H_

#include <string>
#include <iostream>
using namespace std;

/*
 * ---------------------------------------------------------------------------
 *                                  Distrito
 * Autores: Fran y Jose Juan
 *
 * Esta clase es la encargada de contener y administrar la informacion de cada
 * distrito por individual
 *
 * Descripción de los atributos
 *
 * nombreDistrito: string con el nombre del distrito
 *
 * ---------------------------------------------------------------------------
 */

class distrito {
	string nombreDistrito;

public:
	//CONST POR DEFECTO
	/*	Desc: Inicializa la clase atributos con valores por defecto
	 * 	PRE:
	 * 	POST: El ditrito se crea y esta correctamente inicializado
	 * 	Params:
	 * 	Comp: O(1) */
	distrito();

	//CONST POR PARAMETROS

	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El ditrito se crea y se inicializa con los valores de los parametros
	 * 	Params: string nombreDistrito
	 * 	Comp: O(1) */
	distrito(string nombreDistrito);


	//         ~~~SETS~~~

	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El atributo tiene el valor nuevo
	 * 	Params: string nombreDistrito
	 * 	Comp: O(1) */
	void setNombreDistrito(string nombreDistrito);

	//         ~~~GETS~~~
	/*	Desc: Devuelve el valor del atributo
	 * 	PRE:
	 * 	POST: Devuelve el valor del atributo
	 * 	Params:
	 * 	Comp: O(1) */
	string getNombreDistrito();

	//          OTROS METODOS
	/*	Desc: Muestra todos los atributos
	 * 	PRE:
	 * 	POST: Se muestran por consola los atributos
	 * 	Params: string nombreDistrito
	 * 	Comp: O(1) */

	void mostrar();

	/*	Desc: Compara el string de dos distritos y si el primero es mayor lo identifica
	 * 	PRE:
	 * 	POST: True si es mayor, false si no
	 * 	Params: distrito d de entrada salida, constante
	 * 	Comp: O(1) */

	bool operator >(const distrito &d);
	/*	Desc: Compara el string de dos distritos y si son iguales lo identifica
	 * 	PRE:
	 * 	POST: True si son iguales, false si no
	 * 	Params: distrito d de entrada salida, constante
	 * 	Comp: O(1) */
	bool operator==(const distrito &d);
	/*	Desc: Destructor por defecto
	 * 	PRE:
	 * 	POST:Libera el espacio del objeto
	 * 	Params:
	 * 	Comp: O(1) */
	virtual ~distrito();

};

#endif /* DISTRITO_H_ */
