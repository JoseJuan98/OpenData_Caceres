/*
 * Farola.h
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#ifndef FAROLA_H_
#define FAROLA_H_
#include <string>
#include <iostream>
#include "../Utilidades/coords.h"


using namespace std;

/*
 * ---------------------------------------------------------------------------
 *                                  FAROLA
 * Autores: Jose Juan y Fran
 *
 * Esta clase es la encargada de contener y administrar la informacion de cada
 * farola por individual
 *
 * La via a la que pertenece la encuentra el gestor y lo inserta en ella
 *
 * Descripcion de los atributos:
 *
 * funcionamiento: booleano que si funciona esta a true
 * proteccion: string que indica la proteccion de la farola
 * tipoLuz: string que indica el tipo de luz que emite
 * materialS: string que indica el material del soporte
 * potencia: int que indica la potencia
 * tipoLampara: string con el tipo de lampara que tiene la farola
 * altura: float que indica la altura de la farola
 * tipoSoporte: string que indica el tipo de soporte de la farola
 * circuitos: int con la cantidad de circuitos
 * materialL: string con el tipo de material de la lampara
 * coordFarola: coordenada de la farola de la clase coordenada
 * ---------------------------------------------------------------------------
 */

class Farola {
private:


	bool funcionamiento;  //{ "N" , "S" } no o si funciona
	string proteccion;
	string tipoLuz;       //{ "AA" , "AC" , "E" , "ER" , "F" , "O" , "P" }
	string materialS;     //Tipo de material S. { "F" , "Fi" , "Fr" }
	int potencia;
	string tipoLampara;   //{ "F" , "FCBC" , "H" , "HM" , "I" , "LED'S" , "MC" , "PAR" , "VMCC" , "VSAP" , "VSBP" }
	float altura;         //Altura del ElementoMunicipal
	string tipoSoporte;   //{ "Ba" , "Br" , "C" , "O" }
	int circuitos;        //nº de cicuitos que tiene una farola
	string materialL;     //El tipo de material L de la farola. { "Al" , "F" , "O" , "P" }
	Coords *coordFarola;        //coordenada formada con ge_long y geo_lat
	public:

	/*	Desc: Inicializa los atributos con valores por defecto, incluyendo hacerle un new a la coordenada
	 * 	PRE:
	 * 	POST: La farola se crea y esta correctamente inicializada, ademas desucoordenada
	 * 	Params:
	 * 	Comp: O(1) */
	Farola();

	/*	Desc: Inicializa los atributos con los valores dados, incluyendo hacerle un new a la coordenada con la longitud y latitud introducida
	 * 	PRE:
	 * 	POST: La farola se crea y esta correctamente inicializada con los valores dados, ademas de su coordenada
	 * 	Params:
	 * 	Comp: O(1) */

	Farola(bool funcionamiento, string proteccion, string tipoLuz,string materialS,float geo_long,   int potencia,
				string tipoLampara, float geo_lat, float altura, string tipoSoporte, int circuitos, string materialL);

	//                     ~~~SETS~~~

	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El atributo tiene el valor nuevo
	 * 	Params: bool funciona
	 * 	Comp: O(1) */

	void setFuncionamiento(bool funciona);


	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El atributo tiene el valor nuevo
	 * 	Params: string proteccion
	 * 	Comp: O(1) */

	void setProteccion(string proteccion);

	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El atributo tiene el valor nuevo
	 * 	Params: string tipoLuz
	 * 	Comp: O(1) */

	void setTipoLuz(string tipoLuz);

	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El atributo tiene el valor nuevo
	 * 	Params: string materialS
	 * 	Comp: O(1) */
	void setMaterialS(string materialS);

	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El atributo tiene el valor nuevo
	 * 	Params: int potencia
	 * 	Comp: O(1) */
	void setPotencia(int potencia);

	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El atributo tiene el valor nuevo
	 * 	Params: string tipoLampara
	 * 	Comp: O(1) */
	void setTipoLampara(string tipoLampara);

	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El atributo tiene el valor nuevo
	 * 	Params: float altura
	 * 	Comp: O(1) */

	void setAltura(float altura);

	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El atributo tiene el valor nuevo
	 * 	Params: float geo_lat,float geo_long
	 * 	Comp: O(1) */

	void setCoordF (float geo_lat,float geo_long);

	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El atributo tiene el valor nuevo
	 * 	Params: string tipoSoporte
	 * 	Comp: O(1) */

	void setTipoSoporte(string tipoSoporte);

	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El atributo tiene el valor nuevo
	 * 	Params: int circuitos
	 * 	Comp: O(1) */

	void setCircuitos(int circuitos);

	/*	Desc: Le da un valor al atributo
	 * 	PRE:
	 * 	POST: El atributo tiene el valor nuevo
	 * 	Params: string MaterialL
	 * 	Comp: O(1) */

	void setMaterialL(string MaterialL);



	//  ~~~GETS~~~

	/*	Desc: Devuelve el valor del atributo
 * 	PRE:
 * 	POST: Devuelve el valor del atributo
 * 	Params:
 * 	Comp: O(1) */
	Coords* getCoordF();
	/*	Desc: Devuelve el valor del atributo
	* 	PRE:
	* 	POST: Devuelve el valor del atributo
	* 	Params:
	* 	Comp: O(1) */
	string getProteccion();
	/*	Desc: Devuelve el valor del atributo
	 * 	PRE:
	 * 	POST: Devuelve el valor del atributo
	 * 	Params:
	 * 	Comp: O(1) */

	bool getFuncionamiento();
	/*	Desc: Devuelve el valor del atributo
	 * 	PRE:
	 * 	POST: Devuelve el valor del atributo
	 * 	Params:
	 * 	Comp: O(1) */

	string getTipoLuz();
	/*	Desc: Devuelve el valor del atributo
	 * 	PRE:
	 * 	POST: Devuelve el valor del atributo
	 * 	Params:
	 * 	Comp: O(1) */

	string getMaterialS();

	/*	Desc: Devuelve el valor del atributo
	 * 	PRE:
	 * 	POST: Devuelve el valor del atributo
	 * 	Params:
	 * 	Comp: O(1) */
	int getPotencia();

	/*	Desc: Devuelve el valor del atributo
	 * 	PRE:
	 * 	POST: Devuelve el valor del atributo
	 * 	Params:
	 * 	Comp: O(1) */

	string getTipoLampara();

	/*	Desc: Devuelve el valor del atributo
	 * 	PRE:
	 * 	POST: Devuelve el valor del atributo
	 * 	Params:
	 * 	Comp: O(1) */

	float getAltura();

	/*	Desc: Devuelve el valor del atributo
	 * 	PRE:
	 * 	POST: Devuelve el valor del atributo
	 * 	Params:
	 * 	Comp: O(1) */
	string getTipoSoporte();

	/*	Desc: Devuelve el valor del atributo
	 * 	PRE:
	 * 	POST: Devuelve el valor del atributo
	 * 	Params:
	 * 	Comp: O(1) */
	int getCircuitos();

	/*	Desc: Devuelve el valor del atributo
	 * 	PRE:
	 * 	POST: Devuelve el valor del atributo
	 * 	Params:
	 * 	Comp: O(1) */
	string getMaterialL();

	/*	Desc: Muestra todos los atributos de la farola
	 * 	PRE:
	 * 	POST: Muestra por consola los atributos de la farola
	 * 	Params:
	 * 	Comp: O(1) */

	void mostrar();

	/*	Desc: Devuelve el consumo de la farola por dia
	 * 	PRE:
	 * 	POST: Devuelve el consumo que viene dado por: consumo= (potencia(watts)/1000)*8horas*0.12149kWattsporhora
	 * 	Params:
	 * 	Comp: O(1) */

	float consumoFarola();

	/*	Desc: Destruye la instancia de la farol, liberando su espacio y el de la coordenada que va por composicion
	 * 	PRE:
	 * 	POST:
	 * 	Params:
	 * 	Comp: O(1) */

	~Farola();

};

#endif /* FAROLA_H_ */
