//============================================================================
// Author      : Jose Juan Pena Gomez y Francisco Nunez Sierra
// Date        : 21-01-2018
//             Main de todo el proyecto
//============================================================================

#include "UI.h"

#include <fstream>
#include <iostream>
#include "Opendata.h"
#include "Utilidades/timer.h"


using namespace std;


UI::UI() {
	datosCc = new Opendata();

	ejecutar();      //el constructor ya ejecuta el interfaz
}

void UI::ejecutar() {

int opcion;

double tInicio, tTotal;
bool salir=false;
	do {
		opcion = menu();
		switch(opcion){
			case 1:

				cout <<"Cargando datos ... "<<endl;
				tInicio=Timer::getTime();
				datosCc->cargarDatos();
				tTotal=Timer::getTime()-tInicio;
				cout << "Tiempo de ejecucución: "<<  tTotal << endl;
				cout <<"Carga finalizada ... "<<endl;

				break;
			case 2:
				cout << "Vias de barrio... " <<endl;
				tInicio=Timer::getTime();
				datosCc->mostrarViasDeBarrio();
				tTotal=Timer::getTime()-tInicio;
				cout << "Tiempo de ejecucion: " << tTotal << endl;

				break;
			case 3:
				tInicio=Timer::getTime();
				datosCc->ficheroViasDeUnDistrito();
				tTotal=Timer::getTime()-tInicio;
				cout << "Tiempo de ejecucución: "<<  tTotal << endl;

				break;
			case 4:
				cout << "Barrios adyacentes de: " << endl;
				tInicio=Timer::getTime();
				datosCc->BarriosAdyacentes();
				tTotal=Timer::getTime()-tInicio;
				cout << "Tiempo de ejecucución: "<<  tTotal << endl;

				cout << "Fin de barrios adyacentes."  << endl;
				break;
			case 5:
				tInicio=Timer::getTime();
				datosCc->viaMayorConcentracion();
				tTotal=Timer::getTime()-tInicio;
				cout << endl;
				cout << "Tiempo de ejecucución: "<<  tTotal << endl;

				break;
			case 6:
				tInicio=Timer::getTime();
				datosCc->ficheroViasTipoLampara();
				tTotal=Timer::getTime()-tInicio;
				cout << "Tiempo de ejecucución: "<<  tTotal << endl;

				break;
			case 7:
				tInicio=Timer::getTime();
				datosCc->mostrarViasQueEmpiezanPorUnaCadena();
				tTotal=Timer::getTime()-tInicio;
				cout << "Tiempo de ejecucución: "<<  tTotal << endl;

				break;
			case 8:
				tInicio=Timer::getTime();
				datosCc->consumoPorDistrito();
				tTotal=Timer::getTime()-tInicio;
				cout << "Tiempo de ejecucución: "<<  tTotal << endl;

				break;
			case 9:
				tInicio=Timer::getTime();
				datosCc->informeDeAhorro();
				tTotal=Timer::getTime()-tInicio;
				cout << "Tiempo de ejecucución: "<<  tTotal << endl;

				break;
			case 10:
				tInicio=Timer::getTime();
				datosCc->cambiarNombreVia();
				tTotal=Timer::getTime()-tInicio;
				cout << "Tiempo de ejecución: "<<  tTotal << endl;

				break;

			case 0:
				// Finalizar

				salir=true;
				break;
			default:
				cout << "ERROR en la opcion de menu" << endl;
				break;
		}

	} while (!salir);
}


int UI::menu(){

	int opcion;

	do {
		cout << endl;
		cout << "__________________ MENU PRINCIPAL ________________" << endl << endl;

		cout << "   1. Carga de datos                          " << endl;
    	cout << "   2. Mostrar vías de un barrio               " << endl;
    	cout << "   3. Generar fichero vías de un distrito     " << endl;
    	cout << "   4. Barrios adyacentes                      " << endl;
    	cout << "   5. Vía con mayor concentración de farolas  " << endl;
    	cout << "   6. Generar fichero de farolas según lámpara" << endl;
    	cout << "   7. Buscar vías, empieza por...             " << endl;
		cout << "   8. Consumo eléctrico por distrito          " << endl;
		cout << "   9. Informe de ahorro                       " << endl;
		cout << "  10. Cambiar nombre a una vía                " << endl;
		cout << endl;
		cout << "   0. Finalizar.                              " << endl;
		cout << "Opcion:  ";
		cin>> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 11));

	return opcion;
}




UI::~UI() {
	delete datosCc;
}

int main () {
	UI UI;
	return 0;
}
