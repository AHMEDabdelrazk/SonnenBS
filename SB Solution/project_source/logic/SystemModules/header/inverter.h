/*
* date: 11/2024
* auth: ahmed abelrazik
* obje: Inverter
* docu: device inside the sonnenBattery in charge of controlling the power flow to the
*       batteries.
*/


#ifndef INVERTER_H
#define INVERTER_H

#include "common_definition.h"
#include "measurement.h"
#include "battary.h"
#include "grid.h"


class Inverter
{

public:
	/*
	* constructor
	*/
	Inverter(std::shared_ptr<Battery> battery, std::shared_ptr<Grid> grid);
	/*
	*/
	Inverter() = delete;
	/*
	* Battery voltage in Volts
	*/
	Measurement mBatteryVoltage;
	/*
	* Battery current that is flowing to/from inverter in Amps
	*/
	Measurement mBatteryCurrent;
	/*
	* Power inverter is releasing/storing in the batteries in Watts
	*		* positive value notates inverter power is flowing into the batteries (charging)
	*		* negative value notates battery power is flowing into the inverter (discharging)
	*/
	Measurement mInverterPower;
	/*
	* Inverter sensed grid frequency in Hertz
	*/
	Measurement mGridFrequency;
	/*
	* Inverter sensed grid Voltage in Volts
	*/
	Measurement mGridVoltage;

private:
	/*
	* Assumed ampere value
	*/
	const float cPower = 16;
};
#endif //INVERTER_H