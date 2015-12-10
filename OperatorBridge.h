#ifndef OPERATOR_BRIDGE_H
#define OPERATOR_BRIDGE_H

#include <WProgram.h>
// I'm Zach!
class OperatorBridge {
public:
    OperatorBridge();
    ~OperatorBridge();

    // Reads a packet from the connection, null if nothing
    // has been received.
    OperatorBridgePacketIn read();
    // Sends a packet over the connection, returns
    // true iff success.
    bool send(OperatorBridgePacketOut packet);
};

class OperatorBridgePacketOut() {
public:
		float BatteryTemp;
		float BatteryCharge;
		float SolarPanelChargeRate;
}

class OperatorBridgePacketIn() {
public:
		// Empty for now.
}

#endif
