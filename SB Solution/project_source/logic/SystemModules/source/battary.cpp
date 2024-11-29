#include "battary.h"

Battery::Battery(int numberOfBatteries)
{
	/*
	* temperature in Celsius degrees
	*/
	mTemperature.measurement_name = TEMPERATURE_NAME;
	mTemperature.measurement_unit = units::TEMPERATURE_UNIT;
	mTemperature.measurement_value = cTemperature;

	/*
	* voltage in Volts.
	*/
	mVoltage.measurement_name = VOLTAGE_NAME;
	mVoltage.measurement_unit = units::VOLTAGE_UNIT;
	mVoltage.measurement_value = cVoltage;

	/*
	* power in Watts.
	*/
	mMaxPower.measurement_name = POWER_NAME;
	mMaxPower.measurement_unit = units::POWER_UNIT;
	mMaxPower.measurement_value = cMaxPower;

	/*
	* numberOfBatteries
	*/
	mNumberOfBatteries = numberOfBatteries;
}

float Battery::GetTotalPower() const
{
	float total = (mNumberOfBatteries * mMaxPower.measurement_value);
	return total;
}
