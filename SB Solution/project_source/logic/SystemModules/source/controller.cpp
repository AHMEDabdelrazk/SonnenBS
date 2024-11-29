#include "controller.h"
#include <iostream>

Controller::Controller(std::shared_ptr<Battery>& battery, std::shared_ptr<House>& house,
	std::shared_ptr<Panel>& panel)
	: mBattery(battery), mHouse(house), mPanel(panel)
{

}

float Controller::GetGridPower() const
{
	float P_grid;
	float direction = 1;
	if (mPVProduction < 0.0f)
		direction = -1;

	P_grid = (mPVProduction * direction) - mBattery->GetTotalPower();

	return (P_grid * direction);
}

float Controller::GetPVPowerProduction() 
{

	float P_panle = mPanel->mPower.measurement_value;
	float P_house = mHouse->mPower.measurement_value;
	std::cout << P_panle << std::endl;
	std::cout << P_house << std::endl;
	mPVProduction = P_panle - P_house;

	return mPVProduction;
}

SonnenStorageState Controller::GetStorageState() const
{
	/*
	* if pv pane power > house power means system charging else
	* the battery is feeding the house
	*/
	if (mPVProduction > 0.0)
		return SonnenStorageState::Charge;
	return SonnenStorageState::Discharge;
}

SonnenSystemSetup Controller::GetSonnenSystemRecommendedType() const
{
	if (mPVProduction > 3000)
		return SonnenSystemSetup::Pro;
	if (mPVProduction > 2000)
		return SonnenSystemSetup::Standard;
	return SonnenSystemSetup::Basic;
}
