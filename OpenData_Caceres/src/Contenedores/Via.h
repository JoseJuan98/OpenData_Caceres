/*
 * Via.h
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#ifndef VIA_H_
#define VIA_H_
#include <string>
#include <iostream>
#include "../Utilidades/coords.h"
#include "Farola.h"
#include "Barrio.h"
#include "../Utilidades/listapi.h"
using namespace std;
/*
 * ---------------------------------------------------------------------------
 *                                  VIA
 * Autores: Fran y Jose Juan
 *
 * Esta clase es la encargada de contener y administrar la informacion de cada
 * via por individual, posee un puntero a su barrio y una lista con todas las
 * farolas de la via, que se enlazan cuando se llama al metodo insetar farola
 * cuandose enlaza desde fuera
 *
 * Esta enlazada con un distrito al que pertenece a traves de un puntero
 * A su vez, las vias tienen un puntero a su barrio
 *
 * Ademas de eso, contiene la listaPI de sus farolas
 *
 * Descripcion de los Atributos:
 *
 * nombreVia: string con el nombre de la via
 * longitud: float con la longitud de la via en metros
 * tipoVia: string con el tipo de la via
 * codigoVia: string con el codigo  de la via
 * cantidadFarolas: int con la cantidad de farolas que se encuentran en la via
 * coordInicioVia: coordenada de la clase coord que contiene la coordenada del inicio
 * coordMedioVia: coordenada de la clase coord que contiene la coordenada del medio
 * coordFinalVia: coordenada de la clase coord que contiene la coordenada del final
 * perteneceABarrio: puntero al barrio al que pertenece
 *
 * lfarolas: listaPI con todas las farolas que se encuentran en la via
 *           para esta hay distintos metodos que la manipulan
 * ---------------------------------------------------------------------------
 */

class Via {
private:
	string nombreVia;
	float longitud;
	string tipoVia;
	string codigoVia;
	int cantidadFarolas;
	Coords *coordInicioVia;
	Coords *coordMedioVia;
	Coords *coordFinalVia;

	Barrio *perteneceABarrio;

	ListaPI<Farola *> *lfarolas;


public:

	//CONST POR DEFECTO
	/*	Desc: Inicializa los atributos con valores por defecto, incluyendo hacerle un new a la lista de farolas y a las coordenadas
	 * 	PRE:
	 * 	POST: La via se crea y esta correctamente inicializada
	 * 	Params:
	 * 	Comp: O(1) */
	Via();

	//CONSTRUCTOR PARAMETRIZADO

	/*	Desc: Inicializa los atributos con valores por defecto, cogiendo cada longitud y latitud para las coordenadas y inicializando la lista de farolas vacia
	 * 	PRE: Los atributos introducidos son realistas en funcion de lo que pueden ser
	 * 	POST: La via se crea y esta correctamente inicializada
	 * 	Params: string nombreVia, float longitud, string tipoVia, string codigoVia,
			float laI, float lonI, float laM, float lonM, float laF, float lonF, Barrio *perteneceABarrio
	 * 	Comp: O(1) */

	Via(string nombreVia, float longitud, string tipoVia, string codigoVia,
			float laI, float lonI, float laM, float lonM, float laF, float lonF, Barrio *perteneceABarrio);


	// ~~~SETS~~~
	/*	Desc: Le da un valor al atributo
	* 	PRE:
	* 	POST: El atributo tiene el valor nuevo
	* 	Params: string nombreVia
	* 	Comp: O(1) */

	void setNombreVia(string nombreVia);

	/*	Desc: Le da un valor al atributo
	* 	PRE:
	* 	POST: El atributo tiene el valor nuevo
	* 	Params: float LongitudVia
	* 	Comp: O(1) */

	void setLongitudVia(float longitudVia);

	/*	Desc: Le da un valor al atributo
	* 	PRE:
	* 	POST: El atributo tiene el valor nuevo
	* 	Params: string tipoVia
	* 	Comp: O(1) */

	void setTipoVia(string tipoVia);

	/*	Desc: Le da un valor al atributo
	* 	PRE:
	* 	POST: El atributo tiene el valor nuevo
	* 	Params: string codigoVia
	* 	Comp: O(1) */

	void setCodigoVia(string codigoVia);

	/*	Desc: Le da un valor al atributo
	* 	PRE:
	* 	POST: El atributo tiene el valor nuevo
	* 	Params: float latitud, float longitud
	* 	Comp: O(1) */

	void setInicioVia(float latitud,float longitud);

	/*	Desc: Le da un valor al atributo
	* 	PRE:
	* 	POST: El atributo tiene el valor nuevo
	* 	Params: float latitud, float longitud
	* 	Comp: O(1) */

	void setMedioVia(float latitud,float longitud);

	/*	Desc: Le da un valor al atributo
	* 	PRE:
	* 	POST: El atributo tiene el valor nuevo
	* 	Params: float latitud, float longitud
	* 	Comp: O(1) */

	void setFinalVia(float latitud,float longitud);

	/*	Desc: Le da un valor al atributo
	* 	PRE:
	* 	POST: El atributo tiene el valor nuevo
	* 	Params: Barrio *perteneceABarrio
	* 	Comp: O(1) */

	void setBarrioPertenece(Barrio *perteneceABarrio);

	// ~~~GETS~~~

	/*	Desc: Devuelve el valor del atributo
	* 	PRE:
	* 	POST: Devuelve el valor del atributo
	* 	Params:
	* 	Comp: O(1) */

	string getNombreVia() const;

	/*	Desc: Devuelve el valor del atributo
	* 	PRE:
	* 	POST: Devuelve el valor del atributo
	* 	Params:
	* 	Comp: O(1) */

	float getLongitudVia();

	/*	Desc: Devuelve el valor del atributo
	* 	PRE:
	* 	POST: Devuelve el valor del atributo
	* 	Params:
	* 	Comp: O(1) */

	string getTipoVia();

	/*	Desc: Devuelve el valor del atributo
	* 	PRE:
	* 	POST: Devuelve el valor del atributo
	* 	Params:
	* 	Comp: O(1) */

	string getCodigoVia();

	/*	Desc: Devuelve el valor del atributo
	* 	PRE:
	* 	POST: Devuelve el valor del atributo
	* 	Params:
	* 	Comp: O(1) */

	Coords *getCoordsInicioVia();

	/*	Desc: Devuelve el valor del atributo
	* 	PRE:
	* 	POST: Devuelve el valor del atributo
	* 	Params:
	* 	Comp: O(1) */

	Coords *getCoordsMedioVia();

	/*	Desc: Devuelve el valor del atributo
	* 	PRE:
	* 	POST: Devuelve el valor del atributo
	* 	Params:
	* 	Comp: O(1) */

	Coords *getCoordsFinalVia();

	/*	Desc: Devuelve el valor del atributo
	* 	PRE:
	* 	POST: Devuelve el valor del atributo
	* 	Params:
	* 	Comp: O(1) */

	ListaPI<Farola *> *getListaFarolas();

	/*	Desc: Devuelve el valor del atributo
	* 	PRE:
	* 	POST: Devuelve el valor del atributo
	* 	Params:
	* 	Comp: O(1) */

	int getCantidadFarolas();

	/*	Desc: Devuelve el valor del atributo
	* 	PRE:
	* 	POST: Devuelve el valor del atributo
	* 	Params:
	* 	Comp: O(1) */

	Barrio* getBarrioPertenece();

	/*	Desc: Devuelve el valor del atributo
	 * 	PRE:
	 * 	POST: Devuelve el valor del atributo
	 * 	Params:
	 * 	Comp: O(1) */

	string getNombreBarrioPertenece();

	//~~~Gestiones de la lista de farolas~~~
	/*	Desc: Inserta una farola en la lista que contine cada via
	 * 	PRE:
	 * 	POST: La farola esta correctamente insertada al final
	 * 	Params: Farola * f
	 * 	Comp: O(n) */


	void insertarFarolaVia(Farola * f);

	/*	Desc: Muestra todas las farolas de la lista
	 * 	PRE:
	 * 	POST: Muestra las farolas
	 * 	Params:
	 * 	Comp: O(n) */

	void mostrarFarolasVia();

	//~~~OTROS METODOS~~~

	/*	Desc: Devuelve la cantidad de sus farolas partido por su longitud, solo dividiendo atributos
	 * 	PRE:
	 * 	POST: Sale la concentracion de farolas en la via
	 * 	Params:
	 * 	Comp: O(1) */

	float concentracionDeFarolas();

	/*	Desc: Cuenta todas las farolas que haya de u tipo concreto si hay, si no hay devuelve false
	 * 	PRE:
	 * 	POST: Si hay farolas del tipo dado y su cantidad
	 * 	Params: string tipo, int cantidad
	 * 	Comp: O(n) */

	bool farolasDeUnTipo(string tipo, int &cantidad);

	/*	Desc: Calcula la distancia as corta entre todos las coordenadas con otra via dada
	 *        Se usa para el algoritmo 4
	 * 	PRE:  La otra via esta correctamente inicializada con coordenadas
	 * 	POST: Devuelve la distancia mas corta
	 * 	Params: Via *v
	 * 	Comp: O(1) */

	float distanciaMinAVia(Via *v);

	/*	Desc: Llama a cada consumo de la lista de farolas y saca el consumo total en la via
	 * 	PRE:
	 * 	POST: Devuelve el consumo total en la via
	 * 	Params:
	 * 	Comp: O(n) */

	float consumoEnLaVia();

	/*	Desc: Muestra los atributos de la via
	 * 	PRE:
	 * 	POST: Muestra por consolala via
	 * 	Params:
	 * 	Comp: O(1) */

	void mostrar();

	/*	Desc: Compara el string de dos Vias y si la primera es mayor lo identifica
	 * 	PRE:
	 * 	POST: True si es mayor, false si no
	 * 	Params: Via v de entrada salida, constante
	 * 	Comp: O(1) */

	bool operator >(const Via &v);

	/*	Desc: Compara el string de dos Vias y si el primero es mayor lo identifica
	 * 	PRE:
	 * 	POST: True si es mayor, false si no
	 * 	Params: distrito d de entrada salida, constante
	 * 	Comp: O(1) */

	bool operator==(Via &V);

	/*	Desc: Destruye la instancia, ademas de las coordenadas, como van por composicion se eliminan, y las farolas por agregacion y solo se elimina la lista
	 * 	PRE:
	 * 	POST: La instancia es destruida y sus coordenadas y la lista pero sin eliminar las farolas
	 * 	Params:
	 * 	Comp: O(1) */

	~Via();
};

//Clase para comparar dos vias en los arboles, diseñada en las sesiones



class ComparacionVias{
public:
	int operator()(const  Via *v1,const Via *v2){
		int resultado=0;
		if(v1->getNombreVia() > v2->getNombreVia())
			resultado=1;
		if(v1->getNombreVia() < v2->getNombreVia())
			resultado=-1;
		return resultado;
	}
};

#endif /* VIA_H_ */
