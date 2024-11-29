/*
* date: 11/2024
* auth: ahmed abelrazik
* obje: measurement
* docu: measurement name value and unit
*/


#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <iostream>
#include <string>
#include <stdexcept>


class Measurement
{

public:
	Measurement() : measurement_name(""), measurement_value(0), measurement_unit("") 
	{
		// Default constructor
	}
	Measurement(const std::string& name, float value, const std::string& unit)
		: measurement_name(name), measurement_value(value), measurement_unit(unit)
	{
		// Parameterized constructor
	}
	Measurement(const Measurement& nMeasurement)
		: measurement_name(nMeasurement.measurement_name), measurement_value(nMeasurement.measurement_value),
		measurement_unit(nMeasurement.measurement_unit) {
		// Copy constructor
	}
	/*
	* name of the measurement 
	* it code be voltage, frequency, power, current
	*/
	std::string measurement_name;
	/*
	* value of the measurement
	*/
	float measurement_value;
	/*
	* unit of the measurement
	* it code be volt, hertz, watts, amps
	*/
	std::string measurement_unit;
	/*
	* operator + overload
	*/
	Measurement operator+(const Measurement& nMeasurement) const {
		if (measurement_name != nMeasurement.measurement_name ||
			measurement_unit != nMeasurement.measurement_unit) {
			throw std::invalid_argument("measurements cannot be added.");
		}
		return Measurement(measurement_name, measurement_value+ 
			nMeasurement.measurement_value, measurement_unit);
	}
	// defaulted destructor
	~Measurement() = default;
};
#endif //MEASUREMENT_H