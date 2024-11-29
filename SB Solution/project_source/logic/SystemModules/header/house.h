/*
* date: 11/2024
* auth: ahmed abelrazik
* obje: House
* docu: measurement point of all house connected loads.
*/

#ifndef HOUSE_H
#define HOUSE_H

#include "common_definition.h"
#include "measurement.h"


class House
{

public:
	/*
	* constructor
	*/
	House(float power);
	/*
	* Amount of power that is going into the house in Watts
	*/
	Measurement mPower;
	/*
	* Voltage of the house grid
	*/
	Measurement mVoltage;
	/*
	* Frequency of the house grid
	*/
	Measurement mFrequency;
	/*
	* Current flowing into the house in Amps
	*/
	Measurement mCurrent;
private:
	/*
	* Assumed voltage value
	*/
	const float cVoltage = 110;
	/*
	* Assumed hertz value
	*/
	const float cFrequency = 50;
	/*
	* Assumed ampere value
	*/
	const float cCurrent = 20;
};
#endif //HOUSE_H