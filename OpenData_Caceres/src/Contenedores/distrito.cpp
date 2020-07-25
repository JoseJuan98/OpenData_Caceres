/*
 * distrito.cpp
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#include "../Contenedores/distrito.h"
 distrito::distrito(){
	 this->nombreDistrito = "";


 }
void distrito::setNombreDistrito(string nDto){
	this->nombreDistrito=nDto;
}
string distrito::getNombreDistrito(){
	return this->nombreDistrito;
}

void distrito::mostrar(){
	cout <<" Distrito: " <<nombreDistrito <<endl;
}

distrito::distrito(string nombreDistrito){
	this->nombreDistrito = nombreDistrito;


}


bool distrito::operator >(const distrito &d){
	bool mayor = false;
	if(nombreDistrito > d.nombreDistrito)
		mayor=true;

	return mayor;
}
bool distrito::operator==(const distrito &d){
	return (nombreDistrito == d.nombreDistrito);
}

distrito::~distrito() {

}

