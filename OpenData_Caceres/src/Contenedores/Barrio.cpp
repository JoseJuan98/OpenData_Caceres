/*
 * Barrio.cpp
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#include "../Contenedores/Barrio.h"



Barrio::Barrio() {
	nombreBarrio="";
	perteneceADistrito = NULL;


}
//Por parametro
Barrio::Barrio(string nombreBarrio,  distrito *d){
	this->nombreBarrio = nombreBarrio;
	this->perteneceADistrito = d;
}




//clase::funcion
void Barrio::setNombreBarrio (string nombreBarrio){
	//this:puntero asociado a la instancia
	this->nombreBarrio = nombreBarrio;
}
void Barrio::setDistritoAlQuePertenece(distrito *d){
	this->perteneceADistrito=d;
}

string Barrio::getNombreBarrio(){
	return nombreBarrio;
}



distrito* Barrio::getDistritoAlQuePertenece(){
	return this->perteneceADistrito;
}
string Barrio::getNombreDistritoAlQuePertenece(){
	return this->perteneceADistrito->getNombreDistrito();
}

bool Barrio::operator >(const Barrio &b){
	bool mayor = false;
	if(nombreBarrio > b.nombreBarrio)
		mayor=true;

	return mayor;
}
bool Barrio::operator==(Barrio &b){
	bool iguales = false;
	if(nombreBarrio == b.nombreBarrio){
		if(*perteneceADistrito == *b.perteneceADistrito){
			iguales = true;
		}
	}
return iguales;
}
void Barrio::mostrar(){

	cout << "Barrio: " << nombreBarrio << " Nombre de Distrito: " << this->perteneceADistrito->getNombreDistrito() << endl;
}

Barrio::~Barrio() {

}


