/*
* date: 11/2024
* auth: ahmed abelrazik
* obje: Grid
* docu: main connection from the house to the utility provider grid.
*/

#ifndef GRID_H
#define GRID_H

#include "common_definition.h"
#include "measurement.h"


class Grid
{

public:
	/*
	* constructor
	*/
	Grid(float power);
	/*
	* Amount of power that is sold and bought to/from the utility provider.
	*/
	Measurement mPower;
	/*
	* Grid voltage in Volts
	*/
	Measurement mVoltage;
	/*
	* Grid frequency in Hertz
	*/
	Measurement mFrequency;
private:
	/*
	* Assumed voltage value
	*/
	const float cVoltage = 110;
	/*
	* Assumed hertz value
	*/
	const float cFrequency = 50;
};
#endif //GRID_H