/*
* date: 11/2024
* auth: ahmed abelrazik
* obje: Panel
* docu: produces energy from the sun radiation.
*/


#ifndef PANEL_H
#define PANEL_H

#include "common_definition.h"
#include "measurement.h"


class Panel
{

public:
	/*
	* constructor
	*/
	Panel(float power);
	/*
	* Amount of power the PV is producing in Watts
	*/
	Measurement mPower;
	/*
	* Voltage that the PV is producing in Volts
	*/
	Measurement mVoltage;
	/*
	* Current that the PV is producing in Amps
	*/
	Measurement mCurrent;
private:
	/*
	* Assumed voltage value
	*/
	const float cVoltage = 110;
	/*
	* Assumed ampere value
	*/
	const float cCurrent = 20;
};
#endif //PANEL_H