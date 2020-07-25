/*
 * Barrios.cpp
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#include "../Gestores/Barrios.h"

Barrios::Barrios() {
	lbarrios = new ListaPI <Barrio *>;
}
void Barrios::insertarBarrioEnOrden(Barrio *b){
	bool enc=false;
	Barrio *b_paux;

	lbarrios->moverInicio();
	while(!lbarrios->finLista() && !enc){
		lbarrios->consultar(b_paux);
		if(*b_paux > *b){                      //sobrecarga
			enc = true;
		}else{
			lbarrios->avanzar();
		}
	}
	lbarrios->insertar(b);
}
bool Barrios::buscarBarrio(string nombreBarrio, Barrio *&b){
	bool enc=false;
	Barrio *b_aux;
	lbarrios->moverInicio();
	while(!lbarrios->finLista() && !enc){

		lbarrios->consultar(b_aux);
		if(b_aux->getNombreBarrio() == nombreBarrio){
			b = b_aux;
			enc=true;
		}else{
			lbarrios->avanzar();
		}
	}
	return enc;
}
void Barrios::mostrarBarrios(){
	Barrio *aux=NULL;
	lbarrios->moverInicio();

	while(!lbarrios->finLista()){
		lbarrios->consultar(aux);
		aux->mostrar();
		lbarrios->avanzar();
	}
}
void Barrios::barriosDeUnDistrito(ListaPI <Barrio *>*&barsDistrito,distrito *Distrito){
	barsDistrito=new ListaPI< Barrio*>;
	Barrio *b;
	lbarrios->moverInicio();
	barsDistrito->moverInicio();
	while(!lbarrios->finLista()){
	lbarrios->consultar(b);
	if(b->getDistritoAlQuePertenece()==Distrito && b!=NULL){
		barsDistrito->avanzar();
		barsDistrito->insertar(b);
		}
	lbarrios->avanzar();
	}

}


Barrios::~Barrios() {
	Barrio *b_aux;
	lbarrios->moverInicio();

	while(!lbarrios->estaVacia()){
		lbarrios->consultar(b_aux);
		delete b_aux;
		lbarrios->borrar();

	}
	delete lbarrios;

}

