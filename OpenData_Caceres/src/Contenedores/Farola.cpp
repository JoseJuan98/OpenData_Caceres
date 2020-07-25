/*
ZSA  * Farola.cpp
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#include "../Contenedores/Farola.h"

Farola::Farola() {
	coordFarola = NULL;
	funcionamiento = false;
	proteccion = "";
	tipoLuz = "";
	materialS = "";
    potencia = 0;
    tipoLampara = "";
    altura = 0.0;
    tipoSoporte = "";
    circuitos = 0;

}



void Farola::setCoordF (float geo_lat,float geo_long){
    if (coordFarola == NULL ){
    	coordFarola = new Coords (geo_lat, geo_long);
    }else{
    	coordFarola->setLongitude(geo_long);
    	coordFarola->setLatitude(geo_lat);
    }
}


void Farola::setAltura(float altura){
	this->altura=altura;
}

void Farola::setFuncionamiento(bool funciona){
	this->funcionamiento=funciona;
}
void Farola::setProteccion(string proteccion){
	this->proteccion=proteccion;
}

void Farola::setTipoLuz(string tipoLuz){
	this->tipoLuz=tipoLuz;
}

void Farola::setMaterialS(string materialS){
	this->materialS=materialS;
}

void Farola::setPotencia(int potencia){
	this->potencia=potencia;
}

void Farola::setTipoLampara(string tipoLampara){
	this->tipoLampara=tipoLampara;
}

void Farola::setTipoSoporte(string tipoSoporte){
	this->tipoSoporte=tipoSoporte;
}

void Farola::setCircuitos(int circuitos){
	this->circuitos=circuitos;
}

void Farola::setMaterialL(string MaterialL){
	this->materialL=MaterialL;
}


bool Farola::getFuncionamiento(){
	return funcionamiento;
}
string Farola::getProteccion(){
	return this-> proteccion;
}
Coords* Farola::getCoordF(){
	return this->coordFarola;
}
string Farola::getTipoLuz(){
	return this->tipoLuz;
}
string Farola::getMaterialS(){
	return this->materialS;
}
int Farola::getPotencia(){
	return potencia;
}
string Farola::getTipoLampara(){
	return this->tipoLampara ;
}
float Farola::getAltura(){
	return altura;
}
string Farola::getTipoSoporte(){
	return this->tipoSoporte;
}
int Farola::getCircuitos(){
	return circuitos;
}
string Farola::getMaterialL(){
	return this->materialL;
}


float Farola::consumoFarola(){
	float consumo=0;
	//la potencia esta en watts y debe ser pasada a kilowatts
	//consumo= (potencia(watts)/1000)*8horas*0.12149kWattsporhora
	if(this->potencia>0){
		consumo=this->potencia*8*0.12149/1000;
	}


		return consumo;

}

void Farola::mostrar(){
	if(funcionamiento){
		cout << "Sí funciona " <<  "Proteccion: "<< proteccion <<" Tipoluz:"<< tipoLuz<< " Material soporte:"<<materialS<<" Potencia:"<< potencia<< " Tipo lampara:"<<tipoLampara<< " Altura:"<<altura<<" Tipo de Soporte:"<< tipoSoporte<<" Circuitos:"<<circuitos<<" Material de la lampara:"<<materialL<< endl;
		coordFarola->show();
	}else{
		cout << "No funciona " <<  "Proteccion: "<< proteccion <<" Tipoluz:"<< tipoLuz<< " Material soporte:"<<materialS<<" Potencia:"<< potencia<< " Tipo lampara:"<<tipoLampara<< " Altura:"<<altura<<" Tipo de Soporte:"<< tipoSoporte<<" Circuitos:"<<circuitos<<" Material de la lampara:"<<materialL<< endl;
		coordFarola->show();
	}

}



Farola::Farola(bool funcionamiento, string proteccion, string tipoLuz,string materialS,float geo_long,   int potencia,
		string tipoLampara, float geo_lat, float altura, string tipoSoporte, int circuitos, string materialL){

	coordFarola = new Coords(geo_lat, geo_long);
	this->funcionamiento = funcionamiento;
	this->proteccion = proteccion;
	this->tipoLuz = tipoLuz;
	this->materialS = materialS;
	this->potencia = potencia;
	this->tipoLampara = tipoLampara;
	this->altura = altura;
	this->tipoSoporte = tipoSoporte;
	this->circuitos = circuitos;
	this->materialL = materialL;

}
Farola::~Farola() {
	if (coordFarola!= NULL)
		     delete coordFarola;
}
