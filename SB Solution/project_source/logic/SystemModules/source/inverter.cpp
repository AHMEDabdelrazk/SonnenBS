#include "inverter.h"

Inverter::Inverter(std::shared_ptr<Battery> battery, std::shared_ptr<Grid> grid)
{
	mBatteryVoltage = battery->mVoltage;

	mInverterPower = battery->mMaxPower;
	
	// total P = P * numB
	// I = P / V  
	mBatteryCurrent.measurement_name = CURRENT_NAME;
	mBatteryCurrent.measurement_unit = units::CURRENT_UNIT;
	mBatteryCurrent.measurement_value = 
		(battery->mMaxPower.measurement_value * battery->mNumberOfBatteries)/ battery->mVoltage.measurement_value;

	mGridFrequency = grid->mFrequency;

	mGridVoltage = grid->mVoltage;
}
