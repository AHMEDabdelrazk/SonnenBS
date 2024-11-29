#include "sonnen_bs.h"

SonnenBS::SonnenBS(float homePower, float panelPower, int numOfBatteries)
{
	mBattery = std::make_shared<Battery>(numOfBatteries);
	mHouse = std::make_shared<House>(homePower);
	mPanel = std::make_shared<Panel>(panelPower);

	mController = std::make_shared<Controller>(mBattery, mHouse, mPanel);

	mGrid = std::make_unique<Grid>(mController->GetGridPower());
}

QString SonnenBS::GetGridPower() const
{
	QString gridPower = QString::number(mController->GetGridPower());
	return gridPower;
}

QString SonnenBS::GetPVPowerProduction() const
{
	QString pvPower = QString::number(mController->GetPVPowerProduction());
	return pvPower;
}

QString SonnenBS::GetStorageState() const
{
	QString status = "";
	SonnenStorageState storageState = mController->GetStorageState();
	if (storageState == SonnenStorageState::Charge)
		status = "Charge";
	else if(storageState == SonnenStorageState::Discharge)
		status = "Discharge";
	return status;
}

QString SonnenBS::GetSonnenSystemRecommendedType() const
{
	QString systemRecommended = "";
	SonnenSystemSetup system = mController->GetSonnenSystemRecommendedType();
	if (system == SonnenSystemSetup::Basic)
		systemRecommended = "Basic";
	else if (system == SonnenSystemSetup::Standard)
		systemRecommended = "Standard";
	else if (system == SonnenSystemSetup::Pro)
		systemRecommended = "Pro";
	return systemRecommended;
}
