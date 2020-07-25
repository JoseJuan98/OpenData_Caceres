/*
 * PruebasGestorBarrios.cpp
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#include "Pruebas.h"
void pruebasInsertar_MostrarBarrio(){
	cout << "___________INICIO PRUEBA INSERTAR EN ORDEN Y MOSTRAR___________" << endl;
	distrito *d1 = new distrito("Centro");
	distrito *d2 = new distrito("Sur");
	distrito *d3 = new distrito("Oeste");

	Barrio *b1 = new Barrio("El Rodeo", d1);
	Barrio *b2 = new Barrio("Casa Plata", d2);
	Barrio *b3 = new Barrio("Macondo", d3);
	Barrios *B = new Barrios();

	B->insertarBarrioEnOrden(b1);
	B->insertarBarrioEnOrden(b2);
	B->insertarBarrioEnOrden(b3);

	cout << "Para comprobar que se inserta en orden y se muestre correctamente deberia mostrarse en este orden" << endl;
	cout << endl;
	cout <<	"Barrio:        Distrito:" << endl;
	cout <<	"Casa Plata     Sur" << endl;
	cout <<	"El Rodeo       Centro" << endl;
	cout <<	"Macondo        Oeste" << endl;
	cout << endl;
	cout << "A continuacion se ejecutara la prueba" << endl;
	cout << endl;
	B->mostrarBarrios();
	cout << endl;
	cout << "FIN PRUEBA INSERTAR EN ORDEN Y MOSTRAR." << endl;
	cout << endl;
}

void pruebasBuscarBarrio(){
	cout << "___________INICIO PRUEBA BUSCAR BARRIO___________" << endl;
	distrito *d1 = new distrito("Centro");
	distrito *d2 = new distrito("Sur");
	distrito *d3 = new distrito("Oeste");

	Barrio *b1 = new Barrio("El Rodeo", d1);
	Barrio *b2 = new Barrio("Casa Plata", d2);
	Barrio *b3 = new Barrio("Macondo", d3);
	Barrios *B = new Barrios();

	Barrio *b_aux;

	B->insertarBarrioEnOrden(b1);
	B->insertarBarrioEnOrden(b2);
	B->insertarBarrioEnOrden(b3);
	cout << endl;
	if(! B->buscarBarrio("El Rodeo", b_aux)){
		cout << "ERROR en buscar barrio El Rodeo" << endl;
	}else{
		cout << "Prueba 1 buscar barrio El Rodeo satisfactoria" << endl;
	}
	if(! B->buscarBarrio("Casa Plata", b_aux)){
		cout << "ERROR en buscar barrio Casa Plata" << endl;
	}else{
		cout << "Prueba 2 buscar barrio Casa Plata satisfactoria" << endl;
	}
	if(! B->buscarBarrio("Macondo", b_aux)){
		cout << "ERROR en buscar barrio Macondo" << endl;
	}else{
		cout << "Prueba 3 buscar barrio Macondo satisfactoria" << endl;
	}
	cout << endl;
	cout << "FIN PRUEBAS BUSCAR BARRIO" << endl;

}



//int main(){
//	cout << "INICIO PRUEBAS DEL GESTOR BARRIOS" << endl;
//
//	cout << endl;
//	pruebasInsertar_MostrarBarrio();
//	pruebasBuscarBarrio();
//
//	cout << endl;
//
//	cout << "FIN PRUEBAS DEL GESTOR BARRIOS" << endl;
//}

