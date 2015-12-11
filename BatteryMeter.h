#ifndef BATTERY_METER_H
#define BATTERY_METER_H
 
#include <WProgram.h>
 
class BatteryMeter {
public:
	BatteryMeter();
	~BatteryMeter();
	// Gets the current charge of the battery,
	// out of 100.
    float getPercentCharge();
	// Gets the current temperature on the battery,
    // in celcius.
    float getTemperature();
};
 
#endif