#ifndef COMMON_DEFINITION_H
#define COMMON_DEFINITION_H

#include <string>

const int _MAX_LAYOUT_NUMB = 100;

const int cButtonLayoutId = 8;

namespace units {

	const std::string TEMPERATURE_UNIT = "Celsius";

	const std::string VOLTAGE_UNIT = "Volts";

	const std::string POWER_UNIT = "Watts";

	const std::string FREQUENCY_UNIT = "Hertz";

	const std::string CURRENT_UNIT = "Amps";
}

enum class SonnenSystemSetup {
	Basic,
	Standard,
	Pro
};

enum class SonnenStorageState {
	Charge,
	Discharge
};

const std::string TEMPERATURE_NAME = "Temperature";

const std::string VOLTAGE_NAME = "Voltage";

const std::string POWER_NAME = "Power";

const std::string FREQUENCY_NAME = "Frequency";

const std::string CURRENT_NAME = "Current";


#endif // COMMON_DEFINITION_H