#include "grid.h"

Grid::Grid(float power)
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
}
