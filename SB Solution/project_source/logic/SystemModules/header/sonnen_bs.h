/*
* date: 11/2024
* auth: ahmed abelrazik
* obje: SonnenBS
* docu: sonnenBatterie storage system. It can release energy from the battery modules into
*       the house grid or store energy from the house grid into the battery modules.
*/

#ifndef SONNEN_BS_H
#define SONNEN_BS_H

#include "common_definition.h"
#include "battary.h"
#include "inverter.h"
#include "panel.h"
#include "house.h"
#include "controller.h"
#include <QString>


/*
*  Storage
*/
class SonnenBS
{

public:

	SonnenBS(float homePower, float panelPower, int numOfBatteries);

	/*
	* get grid power
	*/
	QString GetGridPower()const;
	/*
	* PV power production
	*/
	QString GetPVPowerProduction() const;

	/*
	* charge OR discharge
	*/
	QString GetStorageState() const;

	/*
	* basic or standard or pro
	*/
	QString GetSonnenSystemRecommendedType() const;

	/*
	* system objects
	*/
	std::shared_ptr<Battery> mBattery;
	std::shared_ptr<Controller> mController;
	std::shared_ptr<Inverter> mInverter;
	std::shared_ptr<Panel> mPanel;
	std::shared_ptr<Grid> mGrid;
	std::shared_ptr<House> mHouse;

};
#endif //SONNEN_BS_H