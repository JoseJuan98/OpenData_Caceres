/*
 * Opendata.cpp
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#include "Opendata.h"
#include <fstream>
using namespace std;
Opendata::Opendata() {
	c = new Calles();
	b = new Barrios();
	d = new Distritos();

}
//Pruebas

//Metodos Privados
void Opendata::cargarDistrito(){
	distrito *dist;
	ifstream fEnt;
	fEnt.open("Distrito.csv");
	string linea;
	string nombred;
	char saltolinea;


	if(fEnt.is_open()){

		getline(fEnt,linea,';');

		while(!fEnt.eof()){
			fEnt.get(saltolinea);
			fEnt.get(saltolinea);
			getline(fEnt, nombred, ';');

			if(nombred!=""){
				dist = new distrito(nombred);
				d->insertarDistritoEnOrden(dist);
			}
		}
		fEnt.close();

	}
}
void Opendata::cargarBarrios(){

	Barrio *barrio;
	ifstream fEnt;
	fEnt.open("Barrio.csv");
	string linea;
	string nombre[2];
	distrito *dis;

	if(fEnt.is_open()){
		getline(fEnt, linea);
		while(!fEnt.eof()){
				getline(fEnt, nombre[0], ';');

			if(!fEnt.eof()){
			    getline(fEnt, nombre[1]);

			    if(! d->buscarDistrito(dis,nombre[1])){
			    	dis = NULL;
			    }
			    barrio = new Barrio(nombre[0], dis);
			    b->insertarBarrioEnOrden(barrio);
			}
		}
		fEnt.close();

	}
}
void Opendata::cargarVia(){

	int i;
		Via *v;
		Barrio *bar;
		float laI, lonI, laM, lonM, laF, lonF;

		ifstream fEnt;
		fEnt.open("Via.csv");
		string linea;
		string campo[11];

		if(fEnt.is_open()){

			getline(fEnt, linea);
			while(!fEnt.eof()){
				for(i=0; i < 10; i++){
					getline(fEnt, campo[i], ';');

				}


				   getline(fEnt, campo[10]);

			       //usar como constructor parametrizado en el orden de nuestros campos
				   laI = atof(campo[6].c_str());
				   lonI = atof(campo[7].c_str());
				   laF = atof(campo[5].c_str());
				   lonF = atof(campo[4].c_str());
				   laM = atof(campo[8].c_str());
				   lonM = atof(campo[9].c_str());

				  if(! b->buscarBarrio(campo[10], bar)){
					  bar=NULL;
				  }
				   v = new Via(campo[0], atof(campo[1].c_str()), campo[2], campo[3], laI, lonI, laM, lonM, laF, lonF, bar);
				   c->insertarEnOrdenVia(v);
				   c->insertarEnOrdenEnArbol(v);
			}
			fEnt.close();
	}

}

void Opendata::cargarFarolas(){

	int i;
	Farola *f;
	bool funciona;
	float lat;
	float lon;
	string campo[15];
	string linea;
	ifstream fEnt;
	fEnt.open("Farola.csv");

	if(fEnt.is_open()){

		getline(fEnt, linea);
		while(!fEnt.eof()){
			for(i=0; i < 11; i++){
				getline(fEnt, campo[i], ';');

			}
			getline(fEnt, campo[11]);
			//bool funcionamiento, string proteccion, string tipoLuz,string materialS,float geo_long,   int potencia,
			//string tipoLampara, float geo_lat, float altura, string tipoSoporte, int circuitos, string materialL

			lon= atof(campo[4].c_str());
			lat= atof(campo[7].c_str());
			if(campo[0]=="S"){
				funciona=true;
			}
			else{
				funciona=false;
			}
			f = new Farola(funciona,campo[1],campo[2],campo[3],lon,atoi(campo[5].c_str()),campo[6],
					lat,atof(campo[8].c_str()),campo[9],atoi(campo[10].c_str()),campo[11]);
			c->insertarFarola(f);
		}
		fEnt.close();
    }
}
//Algoritmo 1
void Opendata::cargarDatos(){
	cargarDistrito();
	cargarBarrios();
	cargarVia();
	cargarFarolas();

}
//Algoritmo 2
void Opendata::mostrarViasDeBarrio(){

	string nombreBarrio;
	Barrio *barAux;
	cout << "Nombre del Barrio: ";
	getline(cin,nombreBarrio);
	if(b->buscarBarrio(nombreBarrio,barAux)){
	c->mostrarViasDeUnBarrio(barAux);
	}else{
		cout << "Barrio no encontrado"<< endl;
	}

}
//Algoritmo 3
void Opendata::ficheroViasDeUnDistrito(){

	distrito *dist=NULL;
	Barrio *bar=NULL;
	Via *v_aux, *v;
	string nombreDistrito;
	ListaPI<Barrio*> *lbarriosDist= new ListaPI<Barrio*>;
	ListaPI<Via*> *lv_aux;
	ListaPI<Via*> *lv_Completa= new ListaPI<Via*>;
	cout << "Nombre de Distrito: " << endl;
	getline(cin, nombreDistrito);
	if(d->buscarDistrito(dist, nombreDistrito)){
		b->barriosDeUnDistrito(lbarriosDist,dist);

	    lbarriosDist->moverInicio();
	    while(!lbarriosDist->finLista()){
	    	lv_aux= new ListaPI<Via*>;
	    	lbarriosDist->consultar(bar);
	    	c->viasDeUnBarrio(lv_aux, bar);

	    	lv_aux->moverInicio();

	    	while(!lv_aux->finLista()){
	    		lv_aux->consultar(v_aux);
	    		//Insertar en orden
	    		lv_Completa->moverInicio();
	    		bool enc=false;
	    		while(!lv_Completa->finLista() && !enc){
	    			lv_Completa->consultar(v);
	    			if(*v > *v_aux){
	    				enc = true;
	    			}else{
	    			  lv_Completa->avanzar();
	    			}
	    		}
	    		lv_Completa->insertar(v_aux);

	    		//Fin insertar en orden
	    		lv_aux->avanzar();
	    	}

	    	delete lv_aux;
	    	lbarriosDist->avanzar();
	    }
	    c->escribirFicheroViasDeUnDistrito(lv_Completa, nombreDistrito);
	    delete lv_Completa;
	    delete lbarriosDist;
	}else{
		cout << "Este distrito no existe" << endl;
	}

}
//Algoritmo 4
void Opendata::BarriosAdyacentes(){

	string barrio;
	Barrio *bar=NULL;
	getline(cin, barrio);
	if(b->buscarBarrio(barrio, bar)){
		c->BarriosAdyacentesDeVia(bar);
	}

}
//Algoritmo 5
void Opendata::viaMayorConcentracion(){

	Via *viAux=NULL;
	float concentracion;
	string nombreVia;
	concentracion=c->viaConMayorConcentracion(viAux);
	nombreVia=viAux->getNombreVia();
	cout << "Via con mayor concentracion: " << nombreVia << ": " << concentracion;

}

//Algoritmo 6
void Opendata::ficheroViasTipoLampara(){

	string tipo;
	cout << "Selecciona el tipo de lampara de la farola:";
	cin >> tipo;
	c->ficheroViasTipoLampara(tipo);



}
//Algoritmo 7
void Opendata::mostrarViasQueEmpiezanPorUnaCadena(){
	double t0,t1,t2,t3;
	bool refinar=true;
	string siOno;
	string cadena;
	string cadenaCompleta="";
	while(refinar){
		cout << "Introduce cadena por la que empiezan las vias: " << cadenaCompleta;
		getline(cin,cadena);
		cadenaCompleta=cadenaCompleta+cadena;
		t0=Timer::getTime();
		c->mostrarViasQueEmpiezenPor(cadenaCompleta);
		t1=Timer::getTime()-t0;
		cout << "Tiempo con listas: " << t1 << endl;
		t2=Timer::getTime();
		c->mostrarViasQueEmpiezenPorArbol(cadenaCompleta);
		t3=Timer::getTime()-t2;
		cout << "Tiempo con arbol: " << t3 <<endl;
		cout << "Escriba S para refinar la busqueda, cualquier otra tecla para volver al menu" << endl;
		getline(cin,siOno);
		if(siOno!="S"){
			refinar=false;
		}

	}
}

//Algoritmo 8

void Opendata::consumoPorDistrito(){
	distrito *dis;
	string nombre;
	Barrio *bAux;
	ListaPI<Barrio*>* laux=new ListaPI<Barrio*>;
	float consumo=0;
	cout << "Introduzca el distrito al que calcular el consumo: ";
	getline(cin,nombre);
	d->buscarDistrito(dis,nombre);
	b->barriosDeUnDistrito(laux,dis);
	laux->moverInicio();
	while(!laux->finLista()){
		laux->consultar(bAux);
		consumo=consumo+c->consumoEnBarrio(bAux);
		laux->avanzar();
	}
	delete laux;
	cout << "El consumo en " << nombre << " es: " << consumo << endl;



}

//Algoritmo 9
void Opendata::informeDeAhorro(){
	string tipoViejo;
	string tipoNuevo;
	int potVieja;
	int potNueva;
	cout << "Introduzca el tipo de la farola vieja a cambiar: " << endl;
	cin >> tipoViejo;
	cout << "Y su potencia: " << endl;
	cin >> potVieja;
	cout << "Introduzca el tipo nuevo de la farola nueva a cambiar: " << endl;
	cin >> tipoNuevo;
	cout << "Y su potencia: " << endl;
	cin >> potNueva;
	cout << "El ahorro total en Caceres de cambiar " << tipoViejo << " de " << potVieja << " por " << tipoNuevo << " de " << potNueva << " seria:" << endl;
	cout << c->ahorroCambioFarola(tipoViejo,potVieja,potNueva) << "€/dia" << endl;
}
//Algoritmo 10
void Opendata::cambiarNombreVia(){
	string nomViejo, nomNuevo;
	double t0, t1, t2 ,t3;
	cout << "Nombre de la via a cambiar: " << endl;
	getline(cin,nomViejo);
	cout << "Nombre nuevo: " << endl;
	getline(cin,nomNuevo);
	//Para probar este Algortimo con listas descomentar esto
//	t0 = Timer::getTime();
//	if(c->cambiarNombreVia(nomViejo,nomNuevo))
//		cout << "Nombre Cambiado Correctamente En Lista" << endl;
//	else
//		cout << "Lo siento, la via no se ha encontrado en la lista." << endl;
//
//	t1 = Timer::getTime() - t0;
//	cout <<"Tiempo en Lista: " << t1 << endl;
	t2 = Timer::getTime();
	if(c->cambiarNombreViaArbol(nomViejo,nomNuevo))
		cout << "Nombre Cambiado Correctamente En Arbol" << endl;
	else
		cout << "Lo siento, la via no se ha encontrado en el Arbol." << endl;

	t3 = Timer::getTime() - t2;
	cout <<"Tiempo en Arbol: " << t3 << endl;
}



Opendata::~Opendata() {
	delete c;
	delete b;
	delete d;
}

