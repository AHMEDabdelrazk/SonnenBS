/*
* date: 11/2024
* auth: ahmed abelrazik
* obje: Battery
* docu: Battery module (BMS): each of the battery packs that can be connected into a sonnenBatterie
*       storage system.
*/
#ifndef BATTERY_H
#define BATTERY_H

#include "common_definition.h"
#include "measurement.h"


class Battery
{

public:

	/*
	* constructor 
	*/
	Battery(int numberOfBatteries);
	/*
	* Module temperature in Celsius degrees
	*/
	Measurement mTemperature;
	/*
	* Module voltage in Volts.
	*/
	Measurement mVoltage;
	/*
	* Maximum power that the battery module can charge or discharge in Watts.
	*/
	Measurement mMaxPower;
	/*
	* number of batteries
	*/
	int mNumberOfBatteries;
	/*
	* get total power = MAX * numOfBatteries
	*/
	float GetTotalPower()const;
	/*
	* destructor
	*/
	~Battery() = default;
private:
	/*
	* Assumed voltage value
	*/
	const float cVoltage = 110;
	/*
	* Assumed ampere value
	*/
	const float cMaxPower = 1000;
	/*
	* Assumed ampere value
	*/
	const float cTemperature = 40;

};
#endif //BATTERY_H