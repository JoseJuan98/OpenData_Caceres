/*
 * PruebasGestorCalles.cpp
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#include "Pruebas.h"


void pruebasInsertar_MostrarVias(){
	/*(string nombreVia, float longitud, string tipoVia, string codigoVia,
				float laI, float lonI, float laM, float lonM, float laF, float lonF, Barrio *perteneceABarrio);*/
	//Villuercas;68.09;Calle;534;-6.377342;39.478283;39.477783;-6.378042;39.47801;-6.377677;Peña Redonda
	distrito *d1 = new distrito("Centro");
	Barrio *b1 = new Barrio("Peña Redonda",d1);
	Via *v1 = new Via("Villuercas", 68.09, "Calle", "534" , -6.377342, 39.478283, 39.477783, -6.378042,
			39.47801, -6.377677, b1);
	//Isla De La Palma;402.82;Calle;3586;-6.387242;39.475783;39.472983;-6.390042;39.474542;-6.388083;R-66-B
	distrito *d2 = new distrito("Oeste");
	Barrio *b2 = new Barrio("R-66-B",d2);
	Via *v2 = new Via("Isla De La Palma", 402.82, "Calle", "3586" , -6.387242,39.475783,39.472983,-6.390042,
			39.474542,-6.388083, b2);
	//Alfonso Albala;255.41;Calle;3148;-6.398142;39.472483;39.470783;-6.399542;39.471987;-6.398268;Los Castellanos
	distrito *d3 = new distrito("Centro");
	Barrio *b3 = new Barrio("Los Castellanos",d3);
	Via *v3 = new Via("Alfonso Albala", 255.41 , "Calle", "3148" ,-6.398142,39.472483,39.470783,-6.399542,
			39.471987,-6.398268, b3);

	Calles *c = new Calles();

	c->insertarEnOrdenEnArbol(v1);
	c->insertarEnOrdenVia(v1);
	c->insertarEnOrdenEnArbol(v2);
	c->insertarEnOrdenVia(v2);
	c->insertarEnOrdenEnArbol(v3);
	c->insertarEnOrdenVia(v3);

	cout << "___________INICIO PRUEBAS INSERTAR EN ORDEN(Arbol y Lista) Y MOSTRAR DE VIAS___________" << endl;
	cout << endl;
	cout << "Para que la prueba sea satisfactoria debera mostrar:" << endl;
	cout << "Nombre: Alfonso Albala. Longitud: 255.41. Tipo de via: Calle. Codigo: 3148. Barrio: Los Castellanos" << endl;
    cout << "      Coordenada Inicial:	Latitud: -6.39814 Longitud: 39.4725 " << endl;
    cout << "      Coordenada Media:		Latitud: 39.4708  Longitud: -6.39954 " << endl;
    cout << "      Coordenada Final:		Latitud: 39.472   Longitud: -6.39827  " << endl;

    cout << "Nombre: Isla De La Palma. Longitud: 402.82. Tipo de via: Calle. Codigo: 3586. Barrio: R-66-B" << endl;
    cout << "      Coordenada Inicial:	Latitud: -6.38724 Longitud: 39.4758 " << endl;
    cout << "      Coordenada Media:		Latitud: 39.473   Longitud: -6.39004" << endl;
    cout << "      Coordenada Final:		Latitud: 39.4745  Longitud: -6.38808" << endl;

    cout << "Nombre: Villuercas. Longitud: 68.09. Tipo de via: Calle. Codigo: 534. Barrio: Peña Redonda" << endl;
    cout << "      Coordenada Inicial:	Latitud: -6.37734 Longitud: 39.4783" << endl;
    cout << "      Coordenada Media:		Latitud: 39.4778  Longitud: -6.37804" << endl;
    cout << "      Coordenada Final:		Latitud: 39.478   Longitud: -6.37768" << endl;
	cout << endl;
	cout << "Se procedera a ejecutar la prueba " << endl;
	cout << endl;
	c->mostrarVias();
	cout << endl;
	cout << "FIN PRUEBAS INSERTAR Y MOSTRAR DE VIAS" << endl;
}
void pruebasInsertar_Mostrar_EnlazaFarolas(){
	distrito *d1 = new distrito("Centro");
	Barrio *b1 = new Barrio("Peña Redonda",d1);
	Via *v1 = new Via("Villuercas", 68.09, "Calle", "534" , -60.377342, 390.478283, 390.477783, -60.378042,
			390.47801, -60.377677, b1);
	distrito *d2 = new distrito("Oeste");
	Barrio *b2 = new Barrio("R-66-B",d2);
	Via *v2 = new Via("Isla De La Palma", 402.82, "Calle", "3586" , -15.387242,52.475783,52.472983,-15.390042,
			52.474542,-15.388083, b2);
	distrito *d3 = new distrito("Centro");
	Barrio *b3 = new Barrio("Los Castellanos",d3);
	Via *v3 = new Via("Alfonso Albala", 255.41 , "Calle", "3148" ,-6.398142,39.472483,39.470783,-6.399542,
			39.471987,-6.398268, b3);

	/* Farola(bool funcionamiento, string proteccion, string tipoLuz,string materialS,float geo_long,   int potencia,
     *string tipoLampara, float geo_lat, float altura, string tipoSoporte, int circuitos, string materialL)
	 */
	Farola *f1 = new Farola(true,"F","AC","F", -6.37181,  250, "VSAP", 39.461, 8.0 , "Ba", 2, "P");
	Farola *f2 = new Farola(false,"F","E","F", -6.37180,  150, "HM", 50.678, 7.0 , "C", 1, "P");
	Farola *f3 = new Farola(true,"F","E","F", -3.3742,  250, "VSAP", 23.456, 6.0 , "Br", 5, "Al");
	Calles *c = new Calles();
	cout << endl;
	cout << "___________INICIO PRUEBA INSERTAR Y MOSTRAR FAROLAS___________" << endl;

	c->insertarEnOrdenVia(v1); //aunque no pertenezcan a estas vias pero es para probar que se enlazan correctamente
	c->insertarEnOrdenVia(v2);
	c->insertarEnOrdenVia(v3);

	c->insertarFarola(f1);
	c->insertarFarola(f2);
	c->insertarFarola(f3);

	cout << endl;
	cout << "Para comprobar que se inserta en orden correctamente, teniendo en cuenta que por cercania";
	cout <<	"una farola pueda pertenecer a dos vias proximas" << endl;
	cout << "por el diseño de las pruebas al inventarme las coordenadas";
	cout << " deberian mostrarse y seguramente repetidas:" << endl;
	cout << endl;
	cout << "Sí funciona Proteccion: F Tipoluz:AC Material soporte:F Potencia:250 Tipo lampara:VSAP Altura:8 ";
	cout << "Tipo de Soporte:Ba Circuitos:2 Material de la lampara:P" << endl;
    cout << "	Latitud: 39.461 Longitud: -6.37181" << endl;
	cout << "No funciona Proteccion: F Tipoluz:E Material soporte:F Potencia:150 Tipo lampara:HM Altura:7 ";
    cout << "Tipo de Soporte:C Circuitos:1 Material de la lampara:P" << endl;
	cout << "       Latitud: 50.678 Longitud: -6.3718" << endl;
	cout << "Sí funciona Proteccion: F Tipoluz:E Material soporte:F Potencia:250 Tipo lampara:VSAP Altura:6 ";
    cout << "Tipo de Soporte:Br Circuitos:5 Material de la lampara:Al" << endl;
	cout << "       Latitud: 23.456 Longitud: -3.3742" << endl;
	cout << endl;
	cout << endl;
	cout << "Acontinuacion se ejecutara la prueba " << endl;
	cout << endl;
	c->mostrarFarolas();
	cout << endl;
	cout << "FIN DE PRUEBA INSERTAR Y MOSTRAR FAROLAS" << endl;
	cout << endl;
	cout << endl;
	cout << "___________INICIO PRUEBA ENLAZAR FAROLAS Y MOSTRAR FAROLAS DE UNA VIA___________" << endl;
	cout << endl;
	cout << "Deberan mostrarse las farolas anteriores las cuales pertenecen todas a v3 por cercania, entonces";
	cout << "v1 y v2 deberian estar vacias "<< endl;
	cout << endl;
	cout << "      Farolas de v1" << endl;
	v1->mostrarFarolasVia();
	cout << endl;
	cout << "      Farolas de v2" << endl;
	v2->mostrarFarolasVia();
	cout << endl;
	cout << "      Farolas de v3" << endl;
	v3->mostrarFarolasVia();
	cout << endl;
	cout << "FIN PRUEBA ENLAZAR FAROLAS..." << endl;
}
void pruebasBuscarUnaVia(){
    cout << endl;
	cout <<"___________INICIO PRUEBAS BUSCAR VIA___________" << endl;
	cout << endl;
	distrito *d1 = new distrito("Centro");
	Barrio *b1 = new Barrio("Peña Redonda",d1);
	Via *v1 = new Via("Villuercas", 68.09, "Calle", "534" , -6.377342, 39.478283, 39.477783, -6.378042,
			39.47801, -6.377677, b1);
	distrito *d2 = new distrito("Oeste");
	Barrio *b2 = new Barrio("R-66-B",d2);
	Via *v2 = new Via("Isla De La Palma", 402.82, "Calle", "3586" , -6.387242,39.475783,39.472983,-6.390042,
				39.474542,-6.388083, b2);
	distrito *d3 = new distrito("Centro");
	Barrio *b3 = new Barrio("Los Castellanos",d3);
	Via *v3 = new Via("Alfonso Albala", 255.41 , "Calle", "3148" ,-6.398142,39.472483,39.470783,-6.399542,
				39.471987,-6.398268, b3);
	Calles *c = new Calles();
	Via *v = new Via();

	Arbol<Via *,ComparacionVias> *abb_aux;
	c->insertarEnOrdenEnArbol(v1);
	c->insertarEnOrdenVia(v1);
	c->insertarEnOrdenEnArbol(v2);
	c->insertarEnOrdenVia(v2);
	c->insertarEnOrdenEnArbol(v3);
	c->insertarEnOrdenVia(v3);
	cout << "___________Pruebas buscar con lista___________" << endl;
	cout << endl;
	if(c->buscarVia("Villuercas", v)){
		cout << "Prueba buscar v1 satisfactoria" << endl;
	}else{
		cout << "Error en buscar v1" << endl;
	}
	cout << endl;
	if(c->buscarVia("Isla De La Palma", v)){
		cout << "Prueba buscar v2 satisfactoria" << endl;
	}else{
		cout << "Error en buscar v2" << endl;
	}
	cout << endl;
	if(c->buscarVia("Alfonso Albala", v)){
		cout << "Prueba buscar v3 satisfactoria" << endl;
	}else{
		cout << "Error en buscar v3" << endl;
	}
	cout << endl;
	cout << "___________Pruebas buscar con arbol___________" << endl;
	cout << endl;
	c->getArbol(abb_aux);
	if(c->buscarEnArbol("Villuercas", v, abb_aux)){
		cout << "Prueba buscar v1 satisfactoria" << endl;
	}else{
		cout << "Error en buscar v1" << endl;
	}
	cout << endl;
	if(c->buscarEnArbol("Isla De La Palma", v,abb_aux)){
		cout << "Prueba buscar v2 satisfactoria" << endl;
	}else{
		cout << "Error en buscar v2" << endl;
	}
	cout << endl;
	if(c->buscarEnArbol("Alfonso Albala", v,abb_aux)){
		cout << "Prueba buscar v3 satisfactoria" << endl;
	}else{
		cout << "Error en buscar v3" << endl;
	}
	cout << endl;

}
void pruebasViasDeUnBarrio(){
	cout << endl;
	cout <<"___________INICIO PRUEBAS VIAS DE UN BARRIO___________" << endl;
	cout << endl;
	distrito *d1 = new distrito("Centro");
	Barrio *b1 = new Barrio("Peña Redonda",d1);
	Via *v1 = new Via("Villuercas", 68.09, "Calle", "534" , -6.377342, 39.478283, 39.477783, -6.378042,
			39.47801, -6.377677, b1);
	Via *v2 = new Via("Isla De La Palma", 402.82, "Calle", "3586" , -6.387242,39.475783,39.472983,-6.390042,
				39.474542,-6.388083, b1);
	Via *v3 = new Via("Alfonso Albala", 255.41 , "Calle", "3148" ,-6.398142,39.472483,39.470783,-6.399542,
				39.471987,-6.398268, b1);
	Calles *c = new Calles();
	ListaPI<Via *>*l = new ListaPI<Via *>;
	Via *v;
	int i=1;


	c->insertarEnOrdenVia(v1);
	c->insertarEnOrdenVia(v2);
	c->insertarEnOrdenVia(v3);

	c->viasDeUnBarrio(l, b1);

	l->moverInicio();
	while(!l->finLista()){
		l->consultar(v);
		cout << "Vias del Barrio b" << i << ":" << v->getNombreVia() <<endl;
		i++;
		l->avanzar();
	}



}
//int main(){
//	cout << "INICIO PRUEBAS DE GESTORCALLES..." << endl;
//	cout << endl;
//
//	pruebasInsertar_MostrarVias();
//	pruebasInsertar_Mostrar_EnlazaFarolas();
//	pruebasBuscarUnaVia();
//	pruebasViasDeUnBarrio();
//
//	cout << endl;
//	cout << "FIN DE PRUEBAS DE GESTORCALLES." << endl;
//}
