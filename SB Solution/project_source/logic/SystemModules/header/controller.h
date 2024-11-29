/*
* date: 11/2024
* auth: ahmed abelrazik
* obje: Controllrr
* docu: handles the energy logic and issues all necessary commands to each of the
*       devices.
*/

#include "common_definition.h"
#include "battary.h"
#include "inverter.h"
#include "panel.h"
#include "house.h"
#include "battary.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{

public:

	Controller(std::shared_ptr<Battery>& battery, std::shared_ptr<House>& house, 
		std::shared_ptr<Panel>& panel);
	/*
	* get grid power
	*/
	float GetGridPower()const;
	/*
	* PV power production
	*/
	float GetPVPowerProduction();
	/*
	* charge OR discharge
	*/
	SonnenStorageState GetStorageState() const;
	/*
	* basic or standard or pro
	*/
	SonnenSystemSetup GetSonnenSystemRecommendedType() const;
private:
	/*
	* system objects
	*/
	std::shared_ptr<Battery> mBattery;
	std::shared_ptr<Panel> mPanel;
	std::shared_ptr<House> mHouse;
	/*
	* pv production
	*/
	float mPVProduction = 0.0f;
};
#endif //CONTROLLER_H