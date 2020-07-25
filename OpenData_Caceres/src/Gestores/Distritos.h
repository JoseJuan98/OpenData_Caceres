/*
 * Distritos.h
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#ifndef DISTRITOS_H_
#define DISTRITOS_H_
#include <string>
#include "../Utilidades/listapi.h"
#include "../Contenedores/distrito.h"

using namespace std;

/*
 * ---------------------------------------------------------------------------
 *                                  Distritos
 * Autores: Fran y Jose Juan
 *
 * Se encarga de contener la lista de todos los distritos y realizar operaciones
 * sobre ellos
 *
 * Descripción de los atributos
 *
 * ldist: lista de punto de interes que contiene todas los distritos
 *
 * ---------------------------------------------------------------------------
 */

class Distritos {
	ListaPI<distrito *> *ldist;
public:
	/*	Desc: Inicializa la clase y reserva el espacio para la lista de distritos
	 * 	PRE:
	 * 	POST: La lista de distrito y ya se puede usar
	 * 	Params:
	 * 	Comp: O(1) */
	Distritos();
	/*	Desc: Inserta en la lista por orden alfabetico
	 * 	PRE:
	 * 	POST: El distrito esta insertado en su sitio
	 * 	Params: distrito *d
	 * 	Comp: O(n),según la posicion alfabetica, caso mejor primera */
	void insertarDistritoEnOrden(distrito *d);
	/*	Desc: Inicializa la clase atributos con valores por defecto
	 * 	PRE:
	 * 	POST: El ditrito se crea y esta correctamente inicializado
	 * 	Params: distrito *&d, string nombD
	 * 	Comp: O(n), segun la posicion a la que este, caso mejor primera */
	bool buscarDistrito(distrito *&d, string nombD);
	/*	Desc: Muestra todos los distritos uno por uno, que estan en orden alfabetico
	 * 	PRE:
	 * 	POST: Se muestran por consola todos los distritos
	 * 	Params:
	 * 	Comp: O(n) */

	void mostrarDistritos();
	/*	Desc: Destruye la instancia y todos sus distritos ya que van por composicion
	 * 	PRE:
	 * 	POST: El la lista se destruye y destruye todos sus distritos, liberando el espacio
	 * 	Params:
	 * 	Comp: O(n) */
	~Distritos();
};

#endif /* DISTRITOS_H_ */
