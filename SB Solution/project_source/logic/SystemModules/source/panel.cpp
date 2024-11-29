#include "panel.h"

Panel::Panel(float power)
{
	mPower.measurement_name = POWER_NAME;
	mPower.measurement_unit = units::POWER_UNIT;
	mPower.measurement_value = power;

	mVoltage.measurement_name = VOLTAGE_NAME;
	mVoltage.measurement_unit = units::VOLTAGE_UNIT;
	mVoltage.measurement_value = cVoltage;

	mCurrent.measurement_name = CURRENT_NAME;
	mCurrent.measurement_unit = units::CURRENT_UNIT;
	mCurrent.measurement_value = cCurrent;
}
