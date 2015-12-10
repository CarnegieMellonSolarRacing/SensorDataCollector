#ifndef SOLAR_PANEL_H 
#define SOLAR_PANEL_H
# wat 
#include <WProgram.h>
 
class SolarPanel {
public:
		//constructor
        SolarPanel();
        ~SolarPanel();
        // Gets the current going through the solar panel,
        // out of 100.
        float getCurrent();
        // Gets the change in current from the previous time step 
        // (most recent reading),
        float getChangeInCurrent();
};
 
#endif
