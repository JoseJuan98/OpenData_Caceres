/*
 * Calles.cpp
 *
 *  Created on: 21-01-2018
 *      Authors: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */
#include <cmath>
#include "../Gestores/Calles.h"
#include "../Utilidades/arbol.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

using namespace std;
Calles::Calles() {
	lvias = new ListaPI <Via *>;
	lfarolas = new ListaPI <Farola *>;
	ArbVias =new Arbol <Via *, ComparacionVias>;
}
void Calles::enlazarFarola(Farola *f){
	Coords* coordF= f->getCoordF();
	Coords* coordVInicio;
	Coords* coordVMedio;
	Coords* coordVFinal;
	float min1;
	//El numero -47 solo estara mientras el min2 no haya sido usado
	float min2=-47;

	Via *viaResultado;
	Via *viaAux;
	lvias->moverInicio();
	while(!lvias->finLista()&&!lvias->estaVacia()){
	//Va consultando cada una de las vias en viaAux
	lvias->consultar(viaAux);
	//Separa sus coordenadas
	coordVInicio=viaAux->getCoordsInicioVia();
	coordVMedio=viaAux->getCoordsMedioVia();
	coordVFinal=viaAux->getCoordsFinalVia();
	//Saca la menor distancia de los tres puntos de la via a el punto de la farola
	min1=fmin(coordF->distanceTo(coordVInicio),coordF->distanceTo(coordVMedio));
	min1=fmin(min1,coordF->distanceTo(coordVFinal));

	//Comprueba si es la via mas cercana hasta ahora y si es se la queda y hace que apunte
	//Se debe hacer tambien si min2 es igual a -47 porque eso determina si esta vacio
	if(min2>min1 or min2 == -47){
		min2=min1;
		viaResultado=viaAux;
	}
	lvias->avanzar();
	}
	viaResultado->insertarFarolaVia(f);
}


void Calles::insertarEnOrdenVia(Via *v){ //se usa sobre una lista ordenada
	bool enc=false;
	Via *aux;

	lvias->moverInicio();
	while(!lvias->finLista() && !enc){
		lvias->consultar(aux);
		if(*aux > *v){
			enc = true;
		}else{
			lvias->avanzar();
		}
	}
	lvias->insertar(v);
}
void Calles::mostrarVias(){
	Via *aux;
	lvias->moverInicio();
	while(!lvias->finLista()){
		lvias->consultar(aux);
		aux->mostrar();
		lvias->avanzar();
	}
}
bool Calles::buscarVia(string nombreVia,Via *&v){
	bool enc=false;
		lvias->moverInicio();
		while(!lvias->finLista()&&!enc){
			lvias->consultar(v);
			if(v->getNombreVia()==nombreVia){
				lvias->borrar();
				enc=true;
			}else{
				lvias->avanzar();
			}
		}
	return enc;
}
void Calles::mostrarViasDeUnBarrio(Barrio *bar){
		Via *v;
		lvias->moverInicio();
		while(!lvias->finLista()){
		lvias->consultar(v);
		if(v->getBarrioPertenece() != NULL){
		  if(v->getBarrioPertenece()==bar){
			v->mostrar();
		  }
		}
		lvias->avanzar();
		}

}
void Calles::viasDeUnBarrio(ListaPI <Via *>*&viasBarrio,Barrio *bar){
	Via *v;
		lvias->moverInicio();
		viasBarrio->moverInicio();
		while(!lvias->finLista()){
		lvias->consultar(v);
		if(v->getBarrioPertenece() != NULL){
		  if(v->getNombreBarrioPertenece()==bar->getNombreBarrio()){
			 viasBarrio->insertar(v);
		  }
		}
		lvias->avanzar();
		}

}

//FAROLAS
void Calles::insertarFarola(Farola *f){
	enlazarFarola(f);
	lfarolas->moverFinal();
	lfarolas->avanzar();      //porque inserta delante
	lfarolas->insertar(f);
}
void Calles::mostrarFarolas(){
	Farola *aux;
	lfarolas->moverInicio();
	while(!lfarolas->finLista()){
		lfarolas->consultar(aux);
		aux->mostrar();
		lfarolas->avanzar();
	}
}


//Arbol
void Calles::insertarEnOrdenEnArbol(Via *v){
	this->ArbVias->insertar(v);
}

void Calles::getArbol(Arbol<Via *,ComparacionVias>* &abb){
	abb = this->ArbVias;
}
bool Calles::buscarEnArbol(string nombre,Via* &v, Arbol<Via *,ComparacionVias> *SubArb){
	bool enc = false;

	if (SubArb->vacio()) {
		enc = false;
	}else{
		Arbol<Via *, ComparacionVias> *abb_aux;
		if (nombre < SubArb->raiz()->getNombreVia()) {
			abb_aux = SubArb->hijoIzq();
			if(abb_aux != NULL){
				enc = buscarEnArbol(nombre, v, abb_aux);
			}
		}else if (nombre > SubArb->raiz()->getNombreVia()){ // dato < datoRaiz
				abb_aux = SubArb->hijoDer();
				if(abb_aux != NULL){
					enc = buscarEnArbol(nombre, v, abb_aux);
				}
		}else{ // dato > datoRaiz
			if(nombre == SubArb->raiz()->getNombreVia()){
				enc = true;
				v = SubArb->raiz();
			}
		}
	}
return enc;
}


//Metodo para escritura del algoritmo 3
void Calles::escribirFicheroViasDeUnDistrito(ListaPI <Via *> *lviasbar, string distrito){
	Via *aux;
	ofstream fsal;
	string nombreFichero = "Distrito"+distrito+".csv";
	fsal.open(nombreFichero.c_str());
	fsal << "Vias del distrito "<< distrito <<":" << endl;
	lviasbar->moverInicio();

	while(!lviasbar->finLista()){
		lviasbar->consultar(aux);
		fsal << aux->getNombreVia()  << endl;
		lviasbar->avanzar();
	}
	fsal.close();
}
//Algoritmo 4
void Calles::BarriosAdyacentesDeVia(Barrio *bar){
	Via *v_aux, *vDebar;
	Barrio *b_aux;
	ListaPI <Via *> *lviasDeBar = new ListaPI<Via *>;
	ListaPI <Barrio *> *lBarriosSinRepetir = new ListaPI<Barrio *>;
	bool enc, salir;
	viasDeUnBarrio(lviasDeBar,bar);
	lvias->moverInicio();
	while(!lvias->finLista()){
		lvias->consultar(v_aux);

        if(v_aux->getBarrioPertenece() != NULL){
		  if(v_aux->getNombreBarrioPertenece() != bar->getNombreBarrio()){

			lviasDeBar->moverInicio();
			enc=false;
			while(!lviasDeBar->finLista() && !enc){
				lviasDeBar->consultar(vDebar);

				  lBarriosSinRepetir->moverInicio();
				  salir=false;

				  while(!lBarriosSinRepetir->finLista() && !salir){
					lBarriosSinRepetir->consultar(b_aux);

					if(b_aux->getNombreBarrio() == v_aux->getNombreBarrioPertenece()){
						salir=true;
					}
					lBarriosSinRepetir->avanzar();
				  }
				  if(v_aux->distanciaMinAVia(vDebar) < 75 && !salir){
					 lBarriosSinRepetir->insertar(v_aux->getBarrioPertenece());
					 enc=true;
				  }
				  lviasDeBar->avanzar();
			}
		   }
        }
		lvias->avanzar();
	}
	lBarriosSinRepetir->moverInicio();
	while(!lBarriosSinRepetir->finLista()){
		lBarriosSinRepetir->consultar(b_aux);
		cout << b_aux->getNombreBarrio() << endl;
		lBarriosSinRepetir->avanzar();
	}
	delete lBarriosSinRepetir;
	delete lviasDeBar;
}
//Algoritmo 5
float Calles::viaConMayorConcentracion(Via *&v){
	float concentracionMax;
	Via *viaMax;
	Via *v_Aux;
	lvias->moverInicio();
		while(!lvias->finLista()){
			lvias->consultar(v_Aux);

			if(v_Aux->concentracionDeFarolas()>concentracionMax){
			concentracionMax=v_Aux->concentracionDeFarolas();
			viaMax=v_Aux;
			}
			lvias->avanzar();
		}
	v=viaMax;
	return concentracionMax;
}
//Algoritmo 6
void Calles::ficheroViasTipoLampara(string tipo){
	Via *viAux;
	int nFarolas=0;
	ofstream fsalida;
	string nombreFichero = "FicheroLamparaTipo"+tipo+".csv";
	fsalida.open(nombreFichero.c_str(),ios::out|ios::trunc);

	if (fsalida.is_open()){

	fsalida << "TipoLampara: " << tipo <<endl;
	fsalida << "Via;Numero de farolas" << endl;
	lvias->moverInicio();
	while(!lvias->finLista()){
		lvias->consultar(viAux);

		if(viAux->farolasDeUnTipo(tipo,nFarolas))
			fsalida << viAux->getNombreVia()<< ";" << nFarolas << endl;

		lvias->avanzar();
		nFarolas=0;

	    }
	}

}

//Algortmo 7
void Calles::mostrarViasQueEmpiezenPor(string cad){
	Via *viAux;
	lvias->moverInicio();
	while(!lvias->finLista()){
		lvias->consultar(viAux);
		if(viAux->getNombreVia().find(cad)==0){
			viAux->mostrar();
		}
		lvias->avanzar();
	}
}
void Calles::mostrarViasQueEmpiezenPorArbol(string cad){
	Arbol<Via *, ComparacionVias> *izq;
	Arbol<Via *, ComparacionVias> *der;
	Via * raiz;

	if (!ArbVias->vacio()) {
		izq = ArbVias->hijoIzq();
		der = ArbVias->hijoDer();
		raiz = ArbVias->raiz();
		if(raiz->getNombreVia().find(cad)==0){
					raiz->mostrar();
				}

		if (izq != NULL&&cad<raiz->getNombreVia()){
											mostrarViasQueEmpiezenPorArbolRecur(izq,cad);
										}else{
				if(der !=NULL)
					mostrarViasQueEmpiezenPorArbolRecur(der,cad);
				}

	}

}
void Calles::mostrarViasQueEmpiezenPorArbolRecur(Arbol<Via *,ComparacionVias> *SubArb,string cad ){
	Arbol<Via *, ComparacionVias> *izq;
	Arbol<Via *, ComparacionVias> *der;
	Via * raiz;

	if (!SubArb->vacio()) {
		izq = SubArb->hijoIzq();
		der = SubArb->hijoDer();
		raiz = SubArb->raiz();

		if(raiz!=NULL&&raiz->getNombreVia().find(cad)==0){
					raiz->mostrar();
				}
		if (izq != NULL&&cad<raiz->getNombreVia()){
													mostrarViasQueEmpiezenPorArbolRecur(izq,cad);
												}else{
						if(der !=NULL)
							mostrarViasQueEmpiezenPorArbolRecur(der,cad);
						}


	}

}

//Algoritmo 8

float Calles::consumoEnBarrio(Barrio* bar){
	float consumoAcumulado=0.0;
	Via *viaux;
	lvias->moverInicio();
	while(!lvias->finLista()){

		lvias->consultar(viaux);
		if(viaux->getBarrioPertenece()==bar)
			consumoAcumulado=consumoAcumulado+viaux->consumoEnLaVia();

		lvias->avanzar();

	}
	return consumoAcumulado;
}
//Algoritmo 9
float Calles::ahorroCambioFarola(string tipoLamparaVieja,int potenciaVieja, int potenciaNueva){
	Farola*fAux;
	int ahorroPotencia;
	int cantidadAhorroPotencia=0;
	float ahorroConsumo;
	//Esto te da el ahorro de potencia por cada farola
	ahorroPotencia=potenciaVieja-potenciaNueva;
	lfarolas->moverInicio();
	while(!lfarolas->finLista()){
		lfarolas->consultar(fAux);
		//Todas las farolas que cumplan el los parametros dados se sumara su ahorro
		if(fAux->getTipoLampara()==tipoLamparaVieja&&fAux->getPotencia()==potenciaVieja&&fAux!=NULL){
			cantidadAhorroPotencia= cantidadAhorroPotencia+ahorroPotencia;

		}
		lfarolas->avanzar();
	}
	//Una vez que tienes el ahorro en potencia en todas las farolas, se calcula el consumo que se ahorraria
	ahorroConsumo=cantidadAhorroPotencia*8*0.12149/1000;
	return ahorroConsumo;
}
//Algoritmo 10
bool Calles::cambiarNombreVia(string nomVie, string nomNue){
	Via *v;
	bool enc=false;
	lvias->moverInicio();
	while(!lvias->finLista()&&!enc){
		lvias->consultar(v);
		if(v->getNombreVia()==nomVie){
			lvias->borrar();
			enc=true;
		}else{
			lvias->avanzar();
		}
	}
	if(enc){
		v->setNombreVia(nomNue);
		this->insertarEnOrdenVia(v);
	}
	return enc;
}
bool Calles::cambiarNombreViaArbol(string nomVie, string nomNue){
	Via *v;
	bool enc=false;
	enc = this->buscarEnArbol(nomVie, v, ArbVias);

	if(enc){
		ArbVias->borrar(v);
		v->setNombreVia(nomNue);
		this->insertarEnOrdenEnArbol(v);
	}
	return enc;
}
Calles::~Calles() {

	Via *viAux;
	Farola *fAux;
	lvias->moverInicio();

	while(!lvias->estaVacia()){
		lvias->consultar(viAux);
		delete viAux;
		lvias->borrar();

	}
	lfarolas->moverInicio();
	while(!lfarolas->estaVacia()){
		lfarolas->consultar(fAux);
		delete fAux;
		lfarolas->borrar();
	}
	delete lfarolas;
	delete lvias;
	delete ArbVias;



}

