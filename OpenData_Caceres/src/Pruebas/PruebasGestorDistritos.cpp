/*
 * Pruebas.cpp
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Peña Gomez y Francisco Nuñez Sierra
 */

#include "../Pruebas/Pruebas.h"

void pruebasInsertarDistrito(){
	cout << "INICIO PRUEBA INSERTAR EN ORDEN..." << endl;
	distrito *d1 = new distrito("Norte");
	distrito *d2 = new distrito("Sur");
	distrito *d3 = new distrito("Este");
	Distritos *D = new Distritos();

	D->insertarDistritoEnOrden(d1);
	D->insertarDistritoEnOrden(d2);
	D->insertarDistritoEnOrden(d3);

	cout << endl;
	cout << "Para comprobar que se inserta en orden correctamente deberia mostrarse en este orden" << endl;
	cout <<	"Distrito: Este, Norte y Sur" << endl;
	cout << endl;
	cout << "A continuacion se ejecutara la prueba" << endl;
	cout << endl;
	D->mostrarDistritos();
	cout << endl;
	cout << "FIN PRUEBA INSERTAR EN ORDEN." << endl;
	cout << endl;
}
void pruebasBuscarDistrito(){

	distrito *d1 = new distrito("Norte");
	distrito *d2 = new distrito("Sur");
	distrito *d3 = new distrito("Este");
	Distritos *D = new Distritos();

	distrito *d_aux;
	string norte = "Norte";
	string sur = "Sur";
	string este = "Este";

	D->insertarDistritoEnOrden(d1);
	D->insertarDistritoEnOrden(d2);
	D->insertarDistritoEnOrden(d3);

	cout << "INICIO PRUEBA BUSCAR DISTRITO..." << endl;
	cout << endl;
	if(!D->buscarDistrito(d_aux, norte)){
		cout << "Error en buscarDistrito" << endl;
	}else{
		cout << "Se ha buscado correctamente el distrito numero 1" << endl;
	}
	if(!D->buscarDistrito(d_aux, sur)){
		cout << "Error en buscarDistrito" << endl;
	}else{
		cout << "Se ha buscado correctamente el distrito numero 2" << endl;
	}
	if(!D->buscarDistrito(d_aux, este)){
		cout << "Error en buscarDistrito" << endl;
	}else{
		cout << "Se ha buscado correctamente el distrito numero 3" << endl;
	}
	cout << endl;
	cout << "FIN PRUEBA BUSCAR DISTRITO." << endl;
	cout << endl;
}

void pruebasMostrarDistrito(){
	cout << "INICIO PRUEBA MOSTRAR..." << endl;
	distrito *d1 = new distrito("Norte");
	distrito *d2 = new distrito("Sur");
	distrito *d3 = new distrito("Este");
	Distritos *D = new Distritos();

	D->insertarDistritoEnOrden(d1);
	D->insertarDistritoEnOrden(d2);
	D->insertarDistritoEnOrden(d3);

	cout << endl;
	cout << "Deberia mostrar  en este orden" << endl;
	cout << "   Distrito: Este             " << endl;
	cout << "   Distrito: Norte            " << endl;
	cout << "   Distrito: Sur.             " << endl;
	cout << endl;
	cout << "Ahora se ejecutara la Prueba y deberia mostrar lo anterior" << endl;
	cout << endl;
	D->mostrarDistritos();
	cout << endl;
	cout << "FIN PRUEBAS MOSTRAR DISTRITOS" << endl;
	cout << endl;
}


//int main(){
//	cout << "INICIO PRUEBAS GESTOR DISTRITOS" << endl;
//
//	cout << endl;
//    pruebasMostrarDistrito();
//    pruebasInsertarDistrito();
//	pruebasBuscarDistrito();
//	cout << endl;
//
//	cout << "FIN DE PRUEBAS DE GESTOR DISTRITOS" << endl;
//	return 0;
//}


