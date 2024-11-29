#include "house.h"

House::House(float power)
{
	mPower.measurement_name = POWER_NAME;
	mPower.measurement_unit = units::POWER_UNIT;
	mPower.measurement_value = power;

	mVoltage.measurement_name = VOLTAGE_NAME;
	mVoltage.measurement_unit = units::VOLTAGE_UNIT;
	mVoltage.measurement_value = cVoltage;

	mFrequency.measurement_name = FREQUENCY_NAME;
	mFrequency.measurement_unit = units::FREQUENCY_UNIT;
	mFrequency.measurement_value = cFrequency;

	mCurrent.measurement_name = CURRENT_NAME;
	mCurrent.measurement_unit = units::CURRENT_UNIT;
	mCurrent.measurement_value = cCurrent;
}