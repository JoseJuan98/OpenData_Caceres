/*
 * ui.h
 *
 *  Created on: 21-01-2018
 *      Author: Jose Juan Pena Gomez y Francisco Nunez Sierra
 */

#ifndef UI_H_
#define UI_H_
#include "Opendata.h"

class UI {

private:
	Opendata *datosCc;

	int  menu     ();
	void ejecutar ();


public:

	 UI();
	~UI();
};

#endif /* UI_H_ */
