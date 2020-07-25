/*
 * Via.cpp
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#include "../Contenedores/Via.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

Via::Via() {
	nombreVia="";
	longitud=0.0;
	tipoVia="";
	codigoVia="";

	coordInicioVia = NULL;
	coordMedioVia = NULL;
	coordFinalVia = NULL;

	perteneceABarrio = NULL;

	lfarolas = new ListaPI <Farola *>;
	cantidadFarolas= 0;
}

Via::Via(string nombreVia, float longitudVia, string tipoVia, string tieneCodigoVia,
		float laI, float lonI, float laM, float lonM, float laF, float lonF, Barrio *perteneceABarrio){
	this->nombreVia = nombreVia;
	this->longitud = longitudVia;
	this->tipoVia = tipoVia;
	this->codigoVia = tieneCodigoVia;

	this->coordInicioVia = new Coords(laI, lonI);
	this->coordMedioVia = new Coords (laM, lonM);
	this->coordFinalVia = new Coords (laF, lonF);
	this->perteneceABarrio = perteneceABarrio;

	lfarolas = new ListaPI <Farola *>;
	cantidadFarolas=0;
}


void Via::setNombreVia(string nombreVia){
	this->nombreVia = nombreVia;
}

void Via::setLongitudVia(float longitud){
	this->longitud = longitud;
}

void Via::setTipoVia(string tipoVia){
	this->tipoVia = tipoVia;
}

void Via::setCodigoVia(string codigoVia){
	this->codigoVia = codigoVia;
}

void Via::setBarrioPertenece(Barrio *perteneceABarrio){
	this->perteneceABarrio=perteneceABarrio;
}

void Via::setInicioVia (float latitud,float longitud){
    if (coordInicioVia == NULL ){
    	coordInicioVia = new Coords (latitud, longitud);
    }else{
    	coordInicioVia->setLongitude(longitud);
    	coordInicioVia->setLatitude(latitud);
    }
}

void Via::setMedioVia (float latitud,float longitud){
    if (coordMedioVia == NULL ){
    	coordMedioVia = new Coords (latitud, longitud);
    }else{
    	coordMedioVia->setLongitude(longitud);
    	coordMedioVia->setLatitude(latitud);
    }
}

void Via::setFinalVia (float latitud,float longitud){
    if (coordFinalVia == NULL ){
    	coordFinalVia = new Coords (latitud, longitud);
    }else{
    	coordFinalVia->setLongitude(longitud);
    	coordFinalVia->setLatitude(latitud);
    }
}

string Via::getNombreVia() const{
	return this->nombreVia;
}

float Via::getLongitudVia(){
	return longitud;
}
string Via::getTipoVia(){
	return this->tipoVia;
}
string Via::getCodigoVia(){
	return this->codigoVia;
}

Barrio* Via::getBarrioPertenece(){
	return this->perteneceABarrio;
}

string Via::getNombreBarrioPertenece(){
	return this->perteneceABarrio->getNombreBarrio();
}

Coords* Via::getCoordsInicioVia(){
	return this->coordInicioVia;
}

Coords* Via::getCoordsMedioVia(){
	return this->coordMedioVia;
}

Coords* Via::getCoordsFinalVia(){
	return this->coordFinalVia;
}

int Via::getCantidadFarolas(){
	return this->cantidadFarolas;
}

ListaPI<Farola *> *Via::getListaFarolas(){
	return this->lfarolas;
}


float Via::distanciaMinAVia(Via *v){
	float distanciaMin;
	distanciaMin = v->coordInicioVia->distanceTo(this->coordInicioVia);
	distanciaMin = fmin(v->coordInicioVia->distanceTo(this->coordMedioVia), distanciaMin);
	distanciaMin = fmin(v->coordInicioVia->distanceTo(this->coordFinalVia), distanciaMin);

	distanciaMin = fmin(v->coordMedioVia->distanceTo(this->coordInicioVia), distanciaMin);
	distanciaMin = fmin(v->coordMedioVia->distanceTo(this->coordMedioVia), distanciaMin);
	distanciaMin = fmin(v->coordMedioVia->distanceTo(this->coordFinalVia), distanciaMin);

	distanciaMin = fmin(v->coordFinalVia->distanceTo(this->coordInicioVia), distanciaMin);
	distanciaMin = fmin(v->coordFinalVia->distanceTo(this->coordMedioVia), distanciaMin);
	distanciaMin = fmin(v->coordFinalVia->distanceTo(this->coordFinalVia), distanciaMin);
	return distanciaMin;
}

void Via::mostrar(){
	if(perteneceABarrio != NULL){
		cout << "Nombre: " << nombreVia << ". Longitud: " << longitud << ". Tipo de via: " << tipoVia << ". Codigo: ";
		cout <<	codigoVia << ". Barrio: " << perteneceABarrio -> getNombreBarrio() << endl;

	}else{
		cout << nombreVia << ". Longitud: " << longitud << ". Tipo de via: " << tipoVia << ". Codigo: ";
		cout << codigoVia << ". No tiene Barrio" <<endl;
	}

	cout << "Coordenada Inicial:";
	coordInicioVia->show();
	cout << "Coordenada Media:";
	coordMedioVia->show();
	cout << "Coordenada Final:";
	coordFinalVia->show();
	cout << endl;

}
bool Via::operator >(const Via &v){
	bool mayor = false;
	if(nombreVia > v.nombreVia)
		mayor=true;

	return mayor;
}
bool Via::operator==(Via &V){
	bool iguales=false;
	if(nombreVia == V.nombreVia){
		if(perteneceABarrio != NULL && V.perteneceABarrio != NULL){
			if(*perteneceABarrio == *V.perteneceABarrio){
				iguales = true;
			}
		}
	}
return iguales;
}

float Via::consumoEnLaVia(){
	float consumo=0;
	Farola *fAux;
	lfarolas->moverInicio();
	while(!lfarolas->finLista()){
		lfarolas->consultar(fAux);
		if(fAux!=NULL)
			consumo=consumo+fAux->consumoFarola();
		lfarolas->avanzar();

	}
	return consumo;
}

float Via::concentracionDeFarolas(){
	float concentracion=0;
	if (this->longitud!=0)
		concentracion=this->cantidadFarolas/this->longitud;
	return concentracion;
}
bool Via::farolasDeUnTipo(string tipo, int &cantidad){
	bool tiene=false;
	Farola *farAux;
	cantidad=0;
	lfarolas->moverInicio();
	while(!lfarolas->finLista()){
				lfarolas->consultar(farAux);
				if(farAux->getTipoLampara()==tipo){
					cantidad++;
				}
				lfarolas->avanzar();

			}
	if (cantidad!=0){
		tiene=true;
	}
	return tiene;
}
void Via::insertarFarolaVia(Farola *f){
	lfarolas->moverFinal();
	lfarolas->avanzar();      //porque inserta delante
	lfarolas->insertar(f);
	cantidadFarolas++;
}
void Via::mostrarFarolasVia(){
	Farola *aux;
	lfarolas->moverInicio();
	while(!lfarolas->finLista()){
		lfarolas->consultar(aux);
		aux->mostrar();
		lfarolas->avanzar();
	}
}



Via::~Via() {

	if (coordInicioVia!= NULL)
	     delete coordInicioVia;
	if (coordFinalVia !=NULL)
	     delete coordFinalVia;
	if (coordMedioVia!=NULL)
	      delete coordMedioVia;

	delete lfarolas;
}

