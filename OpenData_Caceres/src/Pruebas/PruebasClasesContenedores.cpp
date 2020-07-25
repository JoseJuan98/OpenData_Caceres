/*
 * PruebasContenedores.cpp
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#include "Pruebas.h"

void pruebasClasesContenedoras(){
	distrito *d1 = new distrito("Centro");
	distrito *d2 = new distrito("Oeste");
	distrito *d3 = new distrito("Sur");

	Barrio *b1 = new Barrio("Peña Redonda",d1);
	Barrio *b2 = new Barrio("R-66-B",d2);
	Barrio *b3 = new Barrio("Los Castellanos",d3);

	Via *v1 = new Via("Villuercas", 68.09, "Calle", "534" , -6.377342, 39.478283, 39.477783, -6.378042,
				39.47801, -6.377677, b1);
	Via *v2 = new Via("Isla De La Palma", 402.82, "Calle", "3586" , -6.387242,39.475783,39.472983,-6.390042,
				39.474542,-6.388083, b2);
	Via *v3 = new Via("Alfonso Albala", 255.41 , "Calle", "3148" ,-6.398142,39.472483,39.470783,-6.399542,
				39.471987,-6.398268, b3);

	cout << "___________INICIO PRUEBA DE CLASE DISTRITO___________" << endl;
	cout << endl;
	cout << "-Mostrando distritos" << endl;
	cout << endl;
	d1->mostrar();
	d2->mostrar();
	d3->mostrar();
	cout << endl;
	cout << "-Prueba setNombreDistrito, cambiando atributo nombreDistrio d1 por Norte" << endl;
	cout << endl;
	d1->setNombreDistrito("Norte");
	d1->mostrar();
	cout << endl;
	cout << "-Prueba operador comparacion de distritos" << endl;
	cout << endl;
	if(d2<d3){
		cout << "Prueba satisfactoria" << endl;
	}else{
		cout << "Error en prueba del operador comparacion" << endl;
	}
	cout << endl;
	cout << "-Prueba operador asignacion de distritos" << endl;
	cout << endl;
	if(d2==d3){
		cout << "Error en prueba del operador asignacion" << endl;
	}else{
		cout << "Prueba satisfactoria" << endl;
	}
	cout << endl;
	cout << "FIN DE LAS PRUEBAS DE LA CLASE DISTRITO" << endl;
	cout << endl;
	cout << "___________INICIO PRUEBAS DE LA CLASE BARRIO___________"<< endl;
	cout << endl;
	cout << "-Mostrando barrios" << endl;
	cout << endl;
	b1->mostrar();
	b2->mostrar();
	b3->mostrar();
	cout << endl;
	cout << "-Prueba getNombreDistritoAlQuePertence" << endl;
	cout << endl;
	cout << "   Distrito de b1: "<< b1->getNombreDistritoAlQuePertenece() << endl;
	cout  << endl;
	cout << "   Distrito de b2: "<< b2->getNombreDistritoAlQuePertenece() << endl;
	cout  << endl;
	cout << "   Distrito de b3: " << b3->getNombreDistritoAlQuePertenece() << endl;
	cout  << endl;
	cout << "-Prueba operador comparacion de barrios" << endl;
	cout << endl;
	if(b2<b3){
		cout << "Prueba satisfactoria" << endl;
	}else{
		cout << "Error en prueba del operador comparacion" << endl;
	}
	cout << endl;
	cout << "-Prueba operador asignacion de barrios" << endl;
	cout << endl;
	if(b2==b3){
		cout << "Error en prueba del operador asignacion" << endl;
	}else{
		cout << "Prueba satisfactoria" << endl;
	}
	cout << endl;
	cout << "___________INICIO PRUEBAS DE LA CLASE VIA___________"<< endl;
	cout << endl;
	cout << "-Mostrando vias" << endl;
	v1->mostrar();
	v2->mostrar();
	v3->mostrar();
	cout << endl;
	cout << "-Prueba operador comparacion de vias" << endl;
	cout << endl;
	if(v1<v2){
		cout << "Prueba satisfactoria" << endl;
	}else{
		cout << "Error en prueba del operador comparacion" << endl;
	}
	cout << endl;
	cout << "-Prueba operador asignacion de vias" << endl;
	cout << endl;
	if(v2==v3){
		cout << "Error en prueba del operador asignacion" << endl;
	}else{
		cout << "Prueba satisfactoria" << endl;
	}
}
void pruebasFarolasYVias(){
	distrito *d3 = new distrito("Centro");
	Barrio *b3 = new Barrio("Los Castellanos",d3);
	Via *v3 = new Via("Alfonso Albala", 255.41 , "Calle", "3148" ,-6.398142,39.472483,39.470783,-6.399542,
			39.471987,-6.398268, b3);

	Farola *f1 = new Farola(true,"F","AC","F", -6.37181,  250, "VSAP", 39.461, 8.0 , "Ba", 2, "P");
	Farola *f2 = new Farola(false,"F","E","F", -6.37180,  150, "HM", 50.678, 7.0 , "C", 1, "P");
	Farola *f3 = new Farola(true,"F","E","F", -3.3742,  250, "VSAP", 23.456, 6.0 , "Br", 5, "Al");
	Calles *c = new Calles();
	cout << endl;
	cout << "___________INICIO PRUEBA CANTIDAD DE FAROLAS DE UNA VIA___________" << endl;
	cout << endl;

	c->insertarEnOrdenVia(v3);

	c->insertarFarola(f1);
	c->insertarFarola(f2);
	c->insertarFarola(f3);

	if(v3->getCantidadFarolas() == 3){
		cout << "-Prueba cantidad de farolas satisfactoria" << endl;
	}else{
		cout << "ERROR" << endl;
	}
	cout << endl;
	cout << "FIN PRUEBAS DE CANTIDAD DE FAROLAS DE UNA VIA" << endl;
}
//int main(){
//	cout << "INICIO PRUEBAS DE CLASES CONTENEDORAS..." << endl;
//	cout << endl;
//	pruebasClasesContenedoras();
//	pruebasFarolasYVias();
//	cout << endl;
//	cout << "FIN PRUEBAS CLASES CONTENEDORAS" << endl;
//	return 0;
//
//}
