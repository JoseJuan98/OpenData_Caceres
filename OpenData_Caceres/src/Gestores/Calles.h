/*
 * Calles.h
 *
 *  Created on: 21-01-2018
 *      Author:  Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#ifndef CALLES_H_
#define CALLES_H_
#include "../Utilidades/listapi.h"
#include "../Utilidades/arbol.h"
#include "../Contenedores/Via.h"
#include "../Contenedores/Farola.h"
/*
 * ---------------------------------------------------------------------------
 *                                  Calles
 * Autores: Fran y Jose Juan
 *
 * Se encarga de contener la lista de todas las Vias y las Farolas y realizar operaciones
 * sobre ellas, muchas de ellas para ejecutar las operaciones de los algoritmos
 * Ademas de eso tiene un arbol binario de busqueda de las vias que ayuda a reducir
 * el tiempo de operaciones que requieran la busqueda
 *
 * Descripción de los atributos
 *
 * lvias: lista de punto de interes que contiene todas las vias
 * ArbVias: arbol binario con punteros a todas las vias
 * lfarolas: lvias: lista de punto de interes que contiene todos las farolas
 *
 * ---------------------------------------------------------------------------
 */
class Calles {
	ListaPI<Via *> *lvias;
	ListaPI<Farola *> *lfarolas;
	Arbol<Via *,ComparacionVias> *ArbVias;
private:
	/*	Desc: Recorre la lista de vias y encuentra la mas cercana a la farola dada y la inserta en ella
	 * 	PRE:
	 * 	POST: Inicializa las listas y el arbol de manera que ya se puedan usar
	 * 	Params:
	 * 	Comp: O(1) */
	void enlazarFarola(Farola *f);
public:
	/*	Desc: Inicializa la clase y reserva el espacio para las listas y el arbol
	 * 	PRE:
	 * 	POST: Inicializa las listas y el arbol de manera que ya se puedan usar
	 * 	Params:
	 * 	Comp: O(1) */

	Calles();

	//Lista De Vias
	/*	Desc: Inserta la via dado en su posicion de la lista
	 * 	PRE:
	 * 	POST: La via queda insertada
	 * 	Params: Via *v
	 * 	Comp: O(n), dependiendo de su posicion alfabetica */

	void insertarEnOrdenVia(Via *v);
	/*	Desc: Muestra todas las vias de la lista
	 * 	PRE:
	 * 	POST: Las vias se muestran por consola
	 * 	Params: Via*v
	 * 	Comp: O(n), dependiendo de su posicion alfabetica */
	void mostrarVias();

	/*	Desc: Busca la via en la lista, comparandolo con el string y si lo encuentra lo saca como puntero, si no devuelve false
	 * 	PRE:
	 * 	POST: Saca el puntero de la via si esta
	 * 	Params: string nombreVia, Via *&v
	 * 	Comp: O(n), dependiendo de su posicion alfabetica */

	bool buscarVia(string nombreVia, Via *&v);

	/*	Desc: Saca todas las vias a traves de una listaPI de una via ya encontrado con el buscar
	 * 	PRE: La lista PI ya ha sido inicializada
	 * 	POST: Saca una lista de las vias de un barrio
	 * 	Params: ListaPI <Barrio *>*&barsDistrito,distrito *Distrito
     *	Comp: O(n) */

	void viasDeUnBarrio(ListaPI <Via *>*&viasBarrio,Barrio *bar);

	/*	Desc: Inserta la via dado en su posicion del arbol
	 * 	PRE:
	 * 	POST: La via queda insertada
	 * 	Params: Via *v
	 * 	Comp: O(log(n)), dependiendo de su posicion alfabetica */
	void insertarEnOrdenEnArbol(Via *v);

	/*	Desc: get del arbol de vias
	 *	POST: devuelve por parametro de salida el arbol de vias para no romper la encapsulacion
	 *	Params: *&abb
	 *	Comp: O(1)
	 */
	void getArbol(Arbol<Via *,ComparacionVias> *&abb);
	/*	Desc: Busca la via en el arbol, comparandolo con el string y si lo encuentra lo saca como puntero, si no devuelve false
	 * 	PRE:
	 * 	POST: Saca el puntero de la via si esta
	 * 	Params: string nombreVia, Via *&v
	 *  Comp: O(log(n)), dependiendo de su posicion alfabetica */
	bool buscarEnArbol (string nombre, Via* &v, Arbol<Via *,ComparacionVias> *SubArb);

	//Lista De Farolas

	/*	Desc: Inserta la farola dado en su posicion de la lista
	 * 	PRE:
	 * 	POST: La farola queda insertada
	 * 	Params: Farola *f
	 * 	Comp: O(n) */

	void insertarFarola(Farola *f);
	/*	Desc: Muestra todas las farolas de la lista
	 * 	PRE:
	 * 	POST: Las farolas se muestran por consola
	 * 	Params:
	 * 	Comp: O(n) */
	void mostrarFarolas();

	//Algoritmo 2

	/*	Desc: Muestra todas las vias que pertenezcan a un barrio ya sacado conbuscar de la lista
	 * 	PRE:
	 * 	POST: Las farolas se muestran por consola
	 * 	Params: Barrio *bar
	 * 	Comp: O(n)*/
	void mostrarViasDeUnBarrio(Barrio *bar);
	//Algoritmo 3
	/*	Desc: Escribe un fichero con todas las vias de un distrito
	 * 	PRE: Una lista de vias de las vias de un distrito que se saca en el opendata
	 * 	POST: Las vias se meten en el fichero
	 * 	Params: ListaPI <Via *> *lviasdist, string distrito
	 * 	Comp: O(n)*/
	void escribirFicheroViasDeUnDistrito(ListaPI <Via *> *lviasdist, string distrito);
	//Algoritmo 4
	/*	Desc: Muestra por consola todos los nombres de los barrios adyacentes
	 * 	PRE: El puntero al barrio ya sacado con el buscar
	 * 	POST: Las vias se meten en el fichero
	 * 	Params: Barrio *bar
	 * 	Comp: O(n*cantidadDeBarriosAdyacentes)*/
    void BarriosAdyacentesDeVia(Barrio *bar);
	//Algoritmo 5

    /*	Desc: Devuelve un puntero con mayor densidad de farolas y su valor
   	 * 	PRE:
   	 * 	POST: Saca la via con mayor concentracion
   	 * 	Params: Via *&v
   	 * 	Comp: O(n*cantidadDeFarolasDeCadaVia)*/

	float viaConMayorConcentracion(Via *&v);

	//Algoritmo 6

	 /*	Desc: Saca un fichero con las vias que tengan farolas con un tipo de lampara y su cantidad
   	 * 	PRE:
   	 * 	POST: El fichero con las farolas se crea
   	 * 	Params: string tipo
   	 * 	Comp: O(n)*/
	void ficheroViasTipoLampara(string tipo);

	//Algoritmo 7
	/*	Desc: Muestra todas las vias que empiezen por una cadena usando la lista
   	 * 	PRE:
   	 * 	POST: Las vias se muestran por consola
   	 * 	Params: string cad
	 * 	Comp: O(n)*/
	void mostrarViasQueEmpiezenPor(string cad);

	/*	Desc: Muestra todas las vias que empiezen por una cadena usando el arbol, tambien tiene su metodo respectivo
   	 * 	PRE:
   	 * 	POST: Las vias se muestran por consola
   	 * 	Params: string cad
	 * 	Comp: O(log(n))*/

	void mostrarViasQueEmpiezenPorArbol(string cad);
	void mostrarViasQueEmpiezenPorArbolRecur(Arbol<Via *,ComparacionVias> *SubArb,string cad );


	//Algoritmo 8
	/*	Desc: Devuelve el consumo de un barrio usando la lista, ya que por arboles tardaria mas al recorrerlo entero
   	 * 	PRE:
   	 * 	POST: Devuelve en un float el consumo de un barrio
   	 * 	Params: Barrio *b
	 * 	Comp: O(n)*/
	float consumoEnBarrio(Barrio*b);

	//Algoritmo 9

	/*	Desc: Devuelve el consumo de la ciudad si se cambiaran todas las farolas vsap de cierta potencia por otra
	 *        Usa la lista de farolas y la recorre
   	 * 	PRE:
   	 * 	POST: Devuelve en un float el ahorro por el cambio
   	 * 	Params: string tipoLamparaVieja,int potenciaVieja, int potenciaNueva
	 * 	Comp: O(n)*/

	float ahorroCambioFarola(string tipoLamparaVieja,int potenciaVieja, int potenciaNueva);

	//Algoritmo 10

	/*	Desc: Cambia el nombre de una via en la lista
   	 * 	PRE:
   	 * 	POST: Devuelve en un bool si se ha cambiado el nombre con exito o no
   	 * 	Params: string nombreViejo, string nombreNuevo
	 * 	Comp: O(n*n) segun lo que tarde en encontrar la via en la lista
	 * 	*/

	bool cambiarNombreVia(string nombreViejo, string nombreNuevo);

	/*	Desc: Cambia el nombre de una via en el arbol
	 * 	PRE:
	 * 	POST: Devuelve en un bool si se ha cambiado el nombre con exito o no
	 * 	Params: string nombreViejo, string nombreNuevo
	 * 	Comp: O(n*log(n))
	 */
	bool cambiarNombreViaArbol(string nomVie, string nomNue);

	/*	Desc: Destruye la clase destruyendo tambien cada isntancia de sus listas ademas de el espacio del arbol
	 * 	PRE:
	 * 	POST: destruye la lista de farolas y la de vias liberando su espacio
	 * 	Params:
	 * 	Comp: O(2n)
	 * 	*/
	~Calles();
};

#endif /* CALLES_H_ */
