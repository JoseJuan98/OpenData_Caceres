/*
 * Distritos.cpp
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#include "../Gestores/Distritos.h"

Distritos::Distritos() {
	ldist = new ListaPI<distrito *>;
}
void Distritos::insertarDistritoEnOrden(distrito *d){
	bool enc=false;
	distrito *daux;

	ldist->moverInicio();
	if(ldist->estaVacia()){
		ldist->insertar(d);
	}else{
	while(!ldist->finLista() && !enc ){
		ldist->consultar(daux);
		if(*daux > *d){
			enc = true;
		}else{
			ldist->avanzar();
		}
	}
	ldist->insertar(d);
	}
}
bool Distritos::buscarDistrito(distrito *&d, string nombD){
	bool enc=false;
	string nombreAux;
	distrito *d_aux;
	ldist->moverInicio();
	while(!ldist->finLista() && !enc){

		ldist->consultar(d_aux);



		if(d_aux->getNombreDistrito() == nombD){
			d = d_aux;
			enc=true;
		}

		ldist->avanzar();

	}
	return enc;
}

void Distritos::mostrarDistritos(){
	distrito *aux;
	ldist->moverInicio();

	while(!ldist->finLista()){
		ldist->consultar(aux);
		aux->mostrar();
		ldist->avanzar();
	}
}
Distritos::~Distritos() {
	distrito *d_aux;
	ldist->moverInicio();

	while(!ldist->estaVacia()){
		ldist->consultar(d_aux);
		delete d_aux;
		ldist->borrar();

	}
	delete ldist;

}

